#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "protocol.h"
#include "OD.h"
#include "cia402.h"

static co_frame sent[4096];
static unsigned count;
static unsigned bus_off, snapshot_busy, delay_request, delay_stop, gate_release=1, reset_allowed=1;
static unsigned start_requests, speed_requests, stop_requests, reset_requests;
static unsigned offered, stop_sequence, normal_pending, stop_pending, reject_request;
static struct foc_request request;
static struct ns800_foc_status feedback={.state=FOC_STATE_IDLE};
static float reference;
static enum ns800_foc_owner test_owner=FOC_OWNER_CAN;
enum ns800_foc_owner ns800_foc_owner_get(void) {return test_owner;}

/* Deterministic CPU0 model. It never follows target speed: tests provide the
 * feedback independently, and can delay/reject each actual acknowledgement. */
int ns800_foc_submit(enum foc_operation op,float rpm,float current,uint32_t *seq)
{
    if(op==FOC_STOP) {
        stop_requests++; stop_pending=1; *seq=++stop_sequence; return 0;
    }
    if(normal_pending || stop_pending) return -16;
    request=(struct foc_request){op,rpm,current};
    normal_pending=1; *seq=++offered;
    if(op==FOC_START) start_requests++;
    if(op==FOC_SPEED) speed_requests++;
    if(op==FOC_RESET_FAULT) reset_requests++;
    return 0;
}
int ns800_foc_status_read(struct ns800_foc_status *s)
{ if(snapshot_busy) return -16; *s=feedback; return 0; }
static void core_step(void)
{
    if(stop_pending && !delay_stop) {
        if(normal_pending) {feedback.command_seq=offered;feedback.command_result=-4;normal_pending=0;}
        if(feedback.error) feedback.state=FOC_STATE_FAULT;
        else if(feedback.state!=FOC_STATE_NOT_READY && feedback.state!=FOC_STATE_CALIBRATING)
            feedback.state=FOC_STATE_IDLE;
        feedback.stop_seq=stop_sequence;stop_pending=0;
    }
    if(normal_pending && !delay_request && !stop_pending) {
        feedback.command_seq=offered;feedback.command_result=0;
        if(reject_request) feedback.command_result=-22;
        else if(request.operation==FOC_START) {feedback.state=FOC_STATE_ARMING;reference=request.rpm;}
        else if(request.operation==FOC_SPEED) {
            if(feedback.state!=FOC_STATE_CLOSED || reference*request.rpm<=0) feedback.command_result=-16;
            else reference=request.rpm;
        }
        else if(request.operation==FOC_RESET_FAULT) {
            if(!reset_allowed) feedback.command_result=-16;
            else {feedback.error=0;feedback.state=FOC_STATE_IDLE;}
        }
        normal_pending=0;
    }
    if(feedback.state==FOC_STATE_ARMING && gate_release && !stop_pending)
        feedback.state=FOC_STATE_STARTING;
}
int co_bus_send(const co_frame *f) { assert(count < 4096); sent[count++] = *f; return 1; }
int co_bus_open(void) { return 0; }
int co_bus_receive(co_frame *f) { (void)f; return 0; }
void co_bus_errors(unsigned *r, unsigned *t, unsigned *b) { *r = *t = 0; *b=bus_off; }
static void tick(unsigned n) { while (n--) {core_step();assert(co_protocol_process(1000)==0);} }
static void receive(uint16_t id, const uint8_t *data, uint8_t len)
{
    co_frame f = {.ident = id, .DLC = len};
    memcpy(f.data, data, len); co_protocol_receive(&f); tick(3);
}
static const co_frame *find(unsigned from, uint16_t id)
{
    for (unsigned i = from; i < count; ++i) if (sent[i].ident == id) return &sent[i];
    assert(!"Expected frame not transmitted"); return NULL;
}
static uint32_t le32(const uint8_t *p)
{ return p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }
static const co_frame *sdo(uint8_t command, uint16_t index, uint8_t sub, uint32_t value)
{
    uint8_t data[] = {command, index, index >> 8, sub, value, value >> 8, value >> 16, value >> 24};
    unsigned from = count; receive(0x601, data, 8);
    return find(from, 0x581);
}
static void queue_rpdo(uint16_t cw,int32_t rpm)
{
    uint32_t value=(uint32_t)rpm;
    co_frame frame={.ident=0x201,.DLC=6,.data={cw,cw>>8,value,value>>8,value>>16,value>>24}};
    co_protocol_receive(&frame);
}
static void rpdo(uint16_t cw,int32_t rpm) {queue_rpdo(cw,rpm);tick(3);}
static unsigned state(void) {return od_statusword & 0x6F;}
static void enable(int32_t rpm)
{
    rpdo(6,rpm);assert(state()==0x21);
    rpdo(7,rpm);assert(state()==0x23);
    rpdo(15,rpm);assert(state()==0x27 && (od_statusword & 0x10));
}
static void clear_fault(void)
{
    assert(sdo(0x2B,0x6040,0,0)->data[0]==0x60);
    assert(sdo(0x2B,0x6040,0,0x80)->data[0]==0x60);
    tick(3);assert(state()==0x40 && od_error_code==0);
}
int main(void)
{
    assert(cia402_velocity_valid(2500) && cia402_velocity_valid(-2500));
    assert(!cia402_velocity_valid(2501) && !cia402_velocity_valid(-2501));
    feedback.state=FOC_STATE_CALIBRATING;
    assert(co_protocol_reset() == 0);
    tick(1);
    assert(find(0, 0x701)->data[0] == 0);
    assert(state()==0 && start_requests==0);
    unsigned from = count; tick(600);
    assert(find(from, 0x701)->data[0] == 127);
    feedback.state=FOC_STATE_IDLE;tick(2);assert(state()==0x40);
    assert(le32(sdo(0x40, 0x1000, 0, 0)->data + 4) == 0x20192);
    assert(le32(sdo(0x40, 0x1018, 3, 0)->data + 4) == 0x20000);
    assert(sdo(0x40, 0x2000, 0, 0)->data[4] == 1); /* real command backend */
    assert(sdo(0x40, 0x2003, 0, 0)->data[4] == 0);
    assert(sdo(0x2F, 0x6060, 0, 3)->data[0] == 0x60);
    assert(le32(sdo(0x2F, 0x6060, 0, 4)->data + 4) == 0x06090030);
    assert(le32(sdo(0x23, 0x606C, 0, 1)->data + 4) == 0x06010002);
    assert(le32(sdo(0x40, 0x7777, 0, 0)->data + 4) == 0x06020000);
    assert(le32(sdo(0x23,0x60FF,0,100)->data+4)==0x06090030);
    assert(le32(sdo(0x40,0x6083,0,0)->data+4)==0x06020000); /* no fake profile acceleration */
    assert(le32(sdo(0x40,0x6084,0,0)->data+4)==0x06020000);
    assert(le32(sdo(0x2B,0x2004,0,0x2310)->data+4)==0x06090030); /* old fault-injection command is not accepted */
    assert(sdo(0x2B,0x2004,0,800)->data[0]==0x60);
    /* Segmented SDO upload, including toggle handling. */
    const co_frame *reply = sdo(0x40, 0x1008, 0, 0);
    assert(reply->data[0] == 0x41);
    unsigned length = le32(reply->data + 4), copied = 0;
    char name[64] = {0};
    for (unsigned toggle = 0; copied < length; toggle ^= 0x10)
    {
        uint8_t request[8] = {0x60 | toggle};
        from = count; receive(0x601, request, 8); reply = find(from, 0x581);
        assert((reply->data[0] & 0x10) == toggle);
        unsigned n = 7 - ((reply->data[0] >> 1) & 7);
        memcpy(name + copied, reply->data + 1, n); copied += n;
    }
    assert(!strcmp(name, "NS800 FOC velocity bridge"));
    uint8_t start[] = {1, 1}; receive(0, start, 2);
    assert(co_protocol_nmt() == 5);
    sdo(0x23,0x60FF,0,500);sdo(0x2B,0x6040,0,6);sdo(0x2B,0x6040,0,7);sdo(0x2B,0x6040,0,15);
    assert(start_requests==0); /* SDO/raw traffic does not establish a control lease */
    rpdo(6,500);assert(state()==0x21);
    rpdo(7,500);assert(state()==0x23);
    delay_request=1;rpdo(15,500);tick(10);
    assert(start_requests==1 && state()==0x23 && !(od_statusword&0x10));
    assert(request.operation==FOC_START && request.rpm==500 && fabsf(request.current-.8f)<1e-6f);
    delay_request=0;gate_release=0;tick(3);
    assert(feedback.state==FOC_STATE_ARMING && state()==0x23 && !(od_statusword&0x10));
    feedback.speed=52.3598776f;gate_release=1;tick(3);
    assert(state()==0x27 && (od_statusword&0x10) && od_actual_velocity==500);
    assert(le32(sdo(0x2B,0x2004,0,1000)->data+4)==0x08000022); /* startup current immutable while active */
    from = count; tick(20); reply = find(from, 0x181);
    assert(reply->DLC==6 && (reply->data[0]&0x6F)==0x27 && le32(reply->data+2)==500);
    delay_request=1;rpdo(15,600);assert(speed_requests==0); /* do not send SPEED during acquisition */
    feedback.state=FOC_STATE_CLOSED;tick(1);assert(speed_requests==1 && request.rpm==600);
    rpdo(15,650);assert(speed_requests==1);
    delay_request=0;tick(4);assert(speed_requests==2 && reference==650 && od_actual_velocity==500);
    rpdo(15,0);assert(state()==0x40 && feedback.state==FOC_STATE_IDLE && od_actual_velocity==500);
    unsigned starts=start_requests;
    rpdo(15,500);assert(start_requests==starts); /* zero stop requires a new 6/7/F sequence */
    enable(500);
    rpdo(15,-500);assert(state()==0x40);
    starts=start_requests;rpdo(15,-500);assert(start_requests==starts);
    enable(-500);assert(request.rpm==-500);
    feedback.speed=-52.3598776f;tick(1);assert(od_actual_velocity==-500);
    delay_stop=1;rpdo(2,-500);assert(state()==7 && (od_statusword&0x10));
    delay_stop=0;tick(3);assert(state()==0x40 && !(od_statusword&0x10));
    enable(500);rpdo(7,500);assert(state()==0x23 && feedback.state==FOC_STATE_IDLE);
    rpdo(15,500);assert(state()==0x27);
    rpdo(6,500);assert(state()==0x21 && feedback.state==FOC_STATE_IDLE);
    rpdo(7,500);starts=start_requests;rpdo(0x10F,500);
    assert(state()==0x40 && start_requests==starts); /* HALT must never arm */
    enable(500);unsigned stops_before_batch=stop_requests;starts=start_requests;
    queue_rpdo(0,0);queue_rpdo(15,500);tick(4);
    assert(stop_requests==stops_before_batch+1 && feedback.state==FOC_STATE_IDLE && state()==0x40);
    rpdo(15,500);assert(start_requests==starts); /* PDO coalescing cannot erase STOP */
    enable(500);stops_before_batch=stop_requests;
    co_frame sdo_stop={.ident=0x601,.DLC=8,.data={0x2B,0x40,0x60,0,0,0,0,0}};
    co_protocol_receive(&sdo_stop);queue_rpdo(15,500);tick(4);
    assert(stop_requests==stops_before_batch+1 && feedback.state==FOC_STATE_IDLE && state()==0x40);
    enable(500);stops_before_batch=stop_requests;
    queue_rpdo(6,500); /* this unprocessed PDO must not re-arm after NMT STOP/START */
    co_frame nmt_stop={.ident=0,.DLC=2,.data={2,1}}, nmt_start={.ident=0,.DLC=2,.data={1,1}};
    co_protocol_receive(&nmt_stop);co_protocol_receive(&nmt_start);tick(4);
    assert(stop_requests==stops_before_batch+1 && feedback.state==FOC_STATE_IDLE && state()==0x40);
    starts=start_requests;rpdo(15,500);assert(start_requests==starts);

    enable(500);from=count;
    feedback.error=(FOC_ERROR_LIBRARY<<16)|0x12;feedback.state=FOC_STATE_FAULT;tick(4);
    assert(state()==8 && od_error_code==0xFF12 && od_foc_error==feedback.error);
    reply=find(from,0x81);assert(reply->data[0]==0x12 && reply->data[1]==0xFF);
    assert(le32(reply->data+4)==feedback.error && feedback.state==FOC_STATE_FAULT);
    reset_allowed=0;sdo(0x2B,0x6040,0,0x80);tick(3);assert(state()==8 && feedback.error);
    unsigned resets=reset_requests;reset_allowed=1;tick(20);assert(reset_requests==resets);
    sdo(0x2B,0x6040,0,0);delay_request=1;sdo(0x2B,0x6040,0,0x80);
    assert(state()==8 && feedback.error && normal_pending); /* SDO success is not a reset ACK */
    delay_request=0;tick(3);
    assert(state()==0x40 && !od_error_code && feedback.error==0 && feedback.state==FOC_STATE_IDLE);

    enable(500);rpdo(15,100);assert(state()==8 && od_error_code==CIA402_ERROR_REFERENCE);
    clear_fault();
    enable(500);
    unsigned stops=stop_requests;
    for(unsigned i=0;i<90;++i) {
        uint8_t raw[]={1};receive(0x123,raw,1);sdo(0x40,0x6041,0,0);
    }
    assert(state()==8 && od_error_code==CIA402_ERROR_LINK && stop_requests==stops+1);
    starts=start_requests;rpdo(15,500);assert(start_requests==starts); /* reconnect is not re-enable */
    clear_fault();
    rpdo(6,500);rpdo(7,500);delay_request=1;rpdo(15,500);
    assert(normal_pending);rpdo(15,0);delay_request=0;tick(3);
    assert(!normal_pending && feedback.state==FOC_STATE_IDLE && state()==0x40);
    starts=start_requests;rpdo(15,500);assert(start_requests==starts); /* cancelled initialization cannot arm late */
    enable(500);feedback.state=FOC_STATE_IDLE;tick(4);
    assert(state()==8 && od_error_code==CIA402_ERROR_LOCAL); /* manual STOP cannot cause automatic restart */
    clear_fault();
    enable(500);delay_request=1;feedback.state=FOC_STATE_CLOSED;rpdo(15,600);
    assert(normal_pending);reject_request=1;delay_request=0;tick(4);
    assert(state()==8 && od_error_code==CIA402_ERROR_REQUEST && feedback.state==FOC_STATE_IDLE);
    reject_request=0;clear_fault();
    enable(500);bus_off=1;tick(4);
    assert(state()==8 && od_error_code==CIA402_ERROR_LINK && feedback.state==FOC_STATE_IDLE);
    bus_off=0;rpdo(15,500);assert(state()==8);clear_fault();
    enable(500);snapshot_busy=1;bus_off=1;stops=stop_requests;tick(4);
    assert(stop_requests==stops+1 && feedback.state==FOC_STATE_IDLE);
    snapshot_busy=0;tick(2);assert(state()==8 && !(od_statusword&0x10));
    bus_off=0;clear_fault();
    enable(500);stop_sequence=feedback.stop_seq=UINT32_MAX-1;delay_stop=1;rpdo(6,500);
    assert(state()==0x27 && feedback.stop_seq==UINT32_MAX-1); /* old ACK is not sufficient */
    uint32_t local_stop;
    assert(ns800_foc_submit(FOC_STOP,0,0,&local_stop)==0); /* emergency STOP supersedes our serial */
    assert(local_stop==0); /* ordered STOP acknowledgement also survives serial wrap */
    delay_stop=0;tick(3);
    assert(feedback.stop_seq==local_stop && state()==8 && od_error_code==CIA402_ERROR_LOCAL);
    starts=start_requests;rpdo(15,500);assert(start_requests==starts);
    clear_fault();
    for (unsigned len = 0; len <= 8; ++len)
    {
        uint8_t payload[] = {0, 1, 2, 3, 4, 5, 6, 7};
        from = count; receive(0x123, payload, len); reply = find(from, 0x321);
        assert(reply->DLC == len && !memcmp(reply->data, payload, len));
    }
    uint8_t stop[] = {2, 1}; receive(0, stop, 2); assert(co_protocol_nmt() == 4);
    rpdo(15,500);assert(od_controlword == 0);
    uint8_t operational[]={1,1};receive(0,operational,2);
    enable(500);receive(0,stop,2);assert(feedback.state==FOC_STATE_IDLE && !(od_statusword&0x10));
    receive(0,operational,2);starts=start_requests;tick(3);assert(start_requests==starts);
    rpdo(6,500);rpdo(7,500);delay_request=1;rpdo(15,500);
    assert(normal_pending);stops=stop_requests;
    uint8_t reset[] = {0x82, 1}; co_frame f = {.ident = 0, .DLC = 2};
    memcpy(f.data, reset, 2); co_protocol_receive(&f);
    assert(co_protocol_process(1000) == 1);
    assert(stop_requests==stops+1 && stop_pending);
    assert(co_protocol_reset() == 0); from = count; tick(1);
    assert(find(from, 0x701)->data[0] == 0 && od_controlword == 0 && od_target_velocity == 0);
    assert(stop_requests==stops+1 && !normal_pending && feedback.state==FOC_STATE_IDLE);
    delay_request=0;starts=start_requests;tick(10);assert(start_requests==starts);
    receive(0,operational,2);enable(500);
    feedback.error=FOC_ERROR_ADC<<16;feedback.state=FOC_STATE_FAULT;tick(4);
    assert(od_error_code==0xFF11);
    co_protocol_receive(&f);assert(co_protocol_process(1000)==1);
    assert(co_protocol_reset()==0);tick(3);
    assert(state()==8 && od_error_code==0xFF11 && od_foc_error==(FOC_ERROR_ADC<<16));
    clear_fault(); /* NMT reset cannot erase a latched drive fault */
    receive(0,operational,2);enable(500);feedback.state=FOC_STATE_CLOSED;
    unsigned speeds=speed_requests;rpdo(15,2500);
    assert(speed_requests==speeds+1 && reference==2500);
    test_owner=FOC_OWNER_SWITCHING;
    uint32_t handover_stop;
    assert(ns800_foc_submit(FOC_STOP,0,0,&handover_stop)==0);tick(3);
    test_owner=FOC_OWNER_UART;feedback.state=FOC_STATE_CLOSED;feedback.speed=52.36f;
    starts=start_requests;stops=stop_requests;speeds=speed_requests;
    rpdo(15,500);rpdo(0,0);
    assert(start_requests==starts && stop_requests==stops && speed_requests==speeds);
    assert(feedback.state==FOC_STATE_CLOSED && state()==0x40);
    co_protocol_receive(&f);assert(co_protocol_process(1000)==1);
    assert(co_protocol_reset()==0);tick(3);
    assert(stop_requests==stops && feedback.state==FOC_STATE_CLOSED); /* NMT reset does not seize UART. */
    receive(0,operational,2);rpdo(15,500);
    feedback.state=FOC_STATE_IDLE;test_owner=FOC_OWNER_CAN;tick(3);
    assert(start_requests==starts && state()==0x40); /* stale enable cannot restart after handover */
    enable(500);
    puts("CAN owner: read-only under UART/switching, NMT isolation, fresh enable after return and 2500 rpm SPEED passed");
    puts("CANopen/FOC bridge: real command submission, delayed ACK/arming, published feedback, fault reset, lease/bus-off/NMT stops and no automatic restart passed (fake CPU0; no hardware)");
}
