#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>
#include "zcan.h"

/* Uses the user's ZLG SDK, not a second copy of the proprietary library.
 * Only for NS800_PROTOCOL_BENCH. Verify 0x2000/0x2003 before exercising 402. */
static FILE *logfile;
static jmp_buf failed;
static unsigned opened, initialized, frames;
static unsigned last_emcy;
static double started;
static double now(void) { struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t); return t.tv_sec + t.tv_nsec * 1e-9; }
static void check(int ok, const char *what)
{ if (!ok) { fprintf(stderr, "FAIL: %s\n", what); longjmp(failed, 1); } }
static void log_frame(const char *direction, const ZCAN_20_MSG *f)
{
    fprintf(logfile, "%.6f,%s,0x%03x,%u,", now()-started, direction, f->hdr.id, f->hdr.len);
    for (unsigned i=0; i<f->hdr.len && i<8; ++i) fprintf(logfile, "%02x", f->dat[i]);
    fputc('\n', logfile); fflush(logfile);
}
static void send_frame(unsigned id, const U8 *data, unsigned len)
{
    ZCAN_20_MSG f={0}; f.hdr.id=id; f.hdr.len=len; f.hdr.inf.txm=ZCAN_TX_NORM;
    memcpy(f.dat, data, len); log_frame("tx", &f);
    check(VCI_Transmit(33,0,0,&f,1)==1, "ZLG transmit");
}
static ZCAN_20_MSG wait_frame(unsigned id, int first_byte, double timeout)
{
    double until=now()+timeout;
    ZCAN_20_MSG match={0};
    while (now()<until)
    {
        ZCAN_20_MSG batch[64];
        int n=(int)VCI_Receive(33,0,0,batch,64,2), found=0;
        check(n>=0 && n<=64, "ZLG receive");
        for (int i=0; i<n; ++i)
        {
            ZCAN_20_MSG *f=&batch[i]; log_frame("rx", f);
            if (f->hdr.inf.tx || f->hdr.inf.err || f->hdr.inf.sef || f->hdr.inf.sdf || f->hdr.inf.fmt) continue;
            frames++;
            if (f->hdr.id==0x81 && f->hdr.len==8) last_emcy=f->dat[0] | f->dat[1]<<8;
            if (!found && f->hdr.id==id && (first_byte<0 || f->dat[0]==first_byte))
            { match=*f; found=1; }
        }
        if (found) return match;
    }
    fprintf(stderr,"timeout waiting id=0x%x first=%d\n",id,first_byte);
    check(0,"expected CAN response"); return match;
}
static unsigned le32(const U8 *p) { return p[0] | (unsigned)p[1]<<8 | (unsigned)p[2]<<16 | (unsigned)p[3]<<24; }
static ZCAN_20_MSG sdo(unsigned command, unsigned index, unsigned sub, unsigned value)
{
    U8 data[]={command,index,index>>8,sub,value,value>>8,value>>16,value>>24};
    send_frame(0x601,data,8);
    ZCAN_20_MSG r=wait_frame(0x581,-1,1);
    check(r.hdr.len==8 && r.dat[1]==(index&255) && r.dat[2]==(index>>8) && r.dat[3]==sub,"SDO index/subindex");
    return r;
}
static unsigned read_object(unsigned index)
{
    ZCAN_20_MSG r=sdo(0x40,index,0,0);
    check(r.dat[0]==0x43 || r.dat[0]==0x4B || r.dat[0]==0x4F,"SDO expedited upload");
    return le32(r.dat+4);
}
static void write_object(unsigned command, unsigned index, unsigned value)
{ ZCAN_20_MSG r=sdo(command,index,0,value); check(r.dat[0]==0x60,"SDO download acknowledgement"); }
static void state(unsigned cw, unsigned expected)
{
    U8 data[]={cw,0,0xF4,1,0,0}; send_frame(0x201,data,6);
    ZCAN_20_MSG r=wait_frame(0x181,expected,1);
    check(r.hdr.len==6 && le32(r.dat+2)==0,"TPDO status and disconnected actual velocity");
    unsigned sw=read_object(0x6041);
    check((sw&0x6F)==expected && !(sw&0x10),"402 state; no voltage-enabled flag");
    check(read_object(0x606C)==0,"actual velocity remains disconnected zero");
}
int main(int argc, char **argv)
{
    if (argc!=2) { fprintf(stderr,"usage: %s new-log.csv (protocol bench ONLY, no motor backend)\n",argv[0]); return 2; }
    logfile=fopen(argv[1],"wx"); if (!logfile) { perror("log"); return 1; }
    started=now(); fputs("host_s,direction,id,size,payload_hex\n",logfile);
    int result=1;
    if (setjmp(failed)) goto done;
    check(VCI_OpenDevice(33,0,0),"ZLG open"); opened=1;
    ZCAN_INIT config={.clk=80000000,.aset={.tseg1=28,.tseg2=9,.sjw=4,.brp=1},
                     .dset={.tseg1=13,.tseg2=4,.sjw=4,.brp=0}};
    check(VCI_InitCAN(33,0,0,&config),"ZLG init"); initialized=1;
    U32 termination=1,timeout=50;
    check(VCI_SetReference(33,0,0,CMD_CAN_TRES,&termination),"ZLG termination");
    (void)VCI_SetReference(33,0,0,CMD_CAN_TX_TIMEOUT,&timeout);
    check(VCI_StartCAN(33,0,0),"ZLG start");
    check(read_object(0x2000)==0 && read_object(0x2003)==1,
          "bench-only test refuses the real FOC bridge; no NMT/reset/enable will be sent");
    U8 reset[]={0x82,1}; send_frame(0,reset,2);
    wait_frame(0x701,0,2); wait_frame(0x701,127,2);
    check(read_object(0x1000)==0x20192,"402 device type");
    check(read_object(0x2000)==0 && read_object(0x2003)==1,"must be unconnected protocol bench");
    puts("PASS boot-up, pre-operational heartbeat, device identity and disconnected marker");
    ZCAN_20_MSG r=sdo(0x40,0x1008,0,0);
    check(r.dat[0]==0x41,"segmented upload initiate");
    unsigned length=le32(r.dat+4), copied=0; char name[64]={0};
    check(length<sizeof(name),"device name length");
    for (unsigned toggle=0; copied<length; toggle^=0x10)
    {
        U8 request[8]={0x60|toggle}; send_frame(0x601,request,8); r=wait_frame(0x581,-1,1);
        check((r.dat[0]&0xF0)==toggle,"SDO segment/toggle");
        unsigned n=7-((r.dat[0]>>1)&7); check(copied+n<=length,"SDO segment length");
        memcpy(name+copied,r.dat+1,n); copied+=n;
    }
    check(!strcmp(name,"NS800 CANopen protocol bench"),"segmented device name");
    write_object(0x2F,0x6060,3);
    r=sdo(0x2F,0x6060,0,4); check(r.dat[0]==0x80 && le32(r.dat+4)==0x06090030,"unsupported mode abort");
    r=sdo(0x23,0x606C,0,1); check(r.dat[0]==0x80 && le32(r.dat+4)==0x06010002,"read-only abort");
    r=sdo(0x40,0x7777,0,0); check(r.dat[0]==0x80 && le32(r.dat+4)==0x06020000,"missing object abort");
    puts("PASS expedited/segmented SDO, mode selection and abort responses");
    U8 start[]={1,1}; send_frame(0,start,2);
    state(6,0x21); state(7,0x23); state(15,0x27);
    check(read_object(0x60FF)==500,"RPDO target velocity stored only");
    state(2,0x40);
    puts("PASS RPDO/TPDO and 402 shutdown/switch-on/enable/quick-stop state model");
    last_emcy=0; write_object(0x2B,0x2004,0x2310);
    check((read_object(0x6041)&0x6F)==8 && read_object(0x603F)==0x2310,"injected fault state");
    check(last_emcy==0x2310,"EMCY fault code received");
    write_object(0x2B,0x6040,0x80); check((read_object(0x6041)&0x6F)==8,"active fault not reset");
    write_object(0x2B,0x2004,0); check((read_object(0x6041)&0x6F)==8,"fault reset needs new edge");
    write_object(0x2B,0x6040,0); write_object(0x2B,0x6040,0x80);
    check((read_object(0x6041)&0x6F)==0x40,"fault reset edge");
    puts("PASS protocol fault injection, EMCY and fault-reset edge");
    for (unsigned n=0; n<=8; ++n)
    {
        U8 payload[8]; for (unsigned i=0;i<8;++i) payload[i]=n+i*17;
        send_frame(0x123,payload,n); r=wait_frame(0x321,-1,1);
        check(r.hdr.len==n && !memcmp(r.dat,payload,n),"classic 0..8 byte raw echo");
    }
    U8 stop[]={2,1}; send_frame(0,stop,2); wait_frame(0x701,4,2);
    U8 preop[]={0x80,1}; send_frame(0,preop,2); wait_frame(0x701,127,2);
    reset[0]=0x81; send_frame(0,reset,2); wait_frame(0x701,0,2);
    check(read_object(0x6040)==0 && read_object(0x60FF)==0,"reset clears protocol commands");
    check(read_object(0x2000)==0 && read_object(0x606C)==0,"still no motor backend");
    ZCAN_STAT status={0}; check(VCI_ReadCANStatus(33,0,0,&status),"ZLG status");
    check(status.RXE==0 && status.TXE==0,"CAN error counters zero");
    printf("PASS CANopen/402 protocol bench: frames=%u RXE=%u TXE=%u; motor disconnected\n",frames,status.RXE,status.TXE);
    result=0;
done:
    if(initialized) VCI_ResetCAN(33,0,0);
    if(opened) VCI_CloseDevice(33,0);
    fclose(logfile); return result;
}
