/* Temporary instrumentation, isolated tree only; compact public status unchanged. */
#define TRACE_N 1024U
#ifndef FOC_DIAG_MAX_TICKS
#define FOC_DIAG_MAX_TICKS 240000U
#endif
struct trace_sample {
    uint32_t adc, dwt;
    float ia, ib, ihat_a, ihat_b, za, zb, ea, eb, ua, ub;
    float error, we, angle, speed, control_angle, id, iq, iqref;
    float phase_u, phase_v, phase_w, peak, bus, previous_angle, previous_we;
    uint32_t flags;
};
struct trace_buffer {
    uint32_t magic, version, variant, kind, count, capacity, sample_bytes;
    uint32_t cpu_hz, fs, start_adc, end_adc, overflow_start, overflow_end;
    uint32_t abort, max_isr, completed;
    struct trace_sample sample[TRACE_N];
};
_Static_assert(sizeof(struct trace_sample)==112, "Trace layout");
struct trace_buffer foc_trace __attribute__((section(".sram2"),aligned(32)));
static volatile uint32_t diag_adc, diag_overflows, diag_isr_last, diag_isr_max;
static volatile uint32_t diag_control_last, diag_control_max;
static volatile float diag_peak;
struct diag_channel { uint32_t seq, words[22]; };
static struct diag_channel diag_status;

static void diag_reset(void)
{
    memset(&foc_trace,0,sizeof(foc_trace));
    foc_trace.magic=0x504C4C54; foc_trace.version=1;
    foc_trace.variant=FOC_DIAG_VARIANT; foc_trace.kind=1;
    foc_trace.capacity=TRACE_N; foc_trace.sample_bytes=sizeof(struct trace_sample);
    foc_trace.cpu_hz=RCC_getCpuclkFrequency(); foc_trace.fs=PWM_HZ;
    foc_trace.overflow_start=diag_overflows;
    diag_peak=0; diag_isr_last=diag_isr_max=0;
    diag_control_last=diag_control_max=0;
}

static void diag_save(uint32_t entered,float previous_angle,float previous_we)
{
    if(foc_trace.count>=TRACE_N) return;
    SMO_STRUCT *smo=&Sguan.transfer.SMO;
    struct trace_sample *s=&foc_trace.sample[foc_trace.count];
    s->adc=diag_adc; s->dwt=entered;
    s->ia=smo->alpha.Input_Ix; s->ib=smo->beta.Input_Ix;
    s->ihat_a=smo->alpha.Output_Ix; s->ihat_b=smo->beta.Output_Ix;
    s->za=smo->alpha.F_i; s->zb=smo->beta.F_i;
    s->ea=smo->alpha.Output_Ex; s->eb=smo->beta.Output_Ex;
    s->ua=smo->alpha.Input_Ux; s->ub=smo->beta.Input_Ux;
    s->error=Sguan.transfer.PLL_encoder.go.Error;
    s->we=Sguan.transfer.PLL_encoder.go.OutWe;
    s->angle=Sguan.transfer.PLL_encoder.go.OutRe;
    s->speed=Sguan.encoder.Real_Speed; s->control_angle=Sguan.encoder.Real_Re;
    s->id=Sguan.current.Real_Id; s->iq=Sguan.current.Real_Iq; s->iqref=Sguan.foc.Target_Iq;
    s->phase_u=current[0]; s->phase_v=current[1]; s->phase_w=current[2];
    s->peak=diag_peak; s->bus=vbus;
    s->previous_angle=previous_angle; s->previous_we=previous_we;
    s->flags=(running?1U:0U)|(sensorless.closed?2U:0U)|
        (smo->alpha.IntegralFrozen_flag?4U:0U)|(smo->beta.IntegralFrozen_flag?8U:0U)|((uint32_t)fault<<8);
    if(!foc_trace.count) foc_trace.start_adc=diag_adc;
    foc_trace.end_adc=diag_adc; foc_trace.overflow_end=diag_overflows;
    foc_trace.count++;
    if(foc_trace.count==TRACE_N) foc_trace.completed=1;
}

static void diag_publish(const struct ns800_foc_status *status)
{
    uint32_t words[22]={FOC_DIAG_VARIANT,diag_adc,diag_overflows,diag_isr_last,diag_isr_max,
        diag_control_last,diag_control_max,(uint32_t)(diag_peak*1000),
        (uint32_t)(vbus*1000),(uint32_t)(int32_t)(current[0]*1000),
        (uint32_t)(int32_t)(current[1]*1000),(uint32_t)(int32_t)(current[2]*1000),
        status->state,status->error,high_count,foc_trace.count,foc_trace.completed,foc_trace.abort,
        (uint32_t)(int32_t)(Sguan.foc.Target_Speed*60/Value_2PI),
        (uint32_t)(int32_t)(status->speed*60/Value_2PI),foc_trace.cpu_hz,offset_count};
    uint32_t seq=__atomic_load_n(&diag_status.seq,__ATOMIC_RELAXED);
    __atomic_store_n(&diag_status.seq,seq+1U,__ATOMIC_RELAXED);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    for(unsigned i=0;i<22;i++) __atomic_store_n(&diag_status.words[i],words[i],__ATOMIC_RELAXED);
    __atomic_store_n(&diag_status.seq,seq+2U,__ATOMIC_RELEASE);
}

static int diag_cmd(int argc,char **argv)
{
    RT_UNUSED(argc);RT_UNUSED(argv);
    uint32_t w[22]; int valid=0;
    for(unsigned retry=0;retry<3;retry++) {
        uint32_t seq=__atomic_load_n(&diag_status.seq,__ATOMIC_ACQUIRE);
        if(seq&1U) continue;
        for(unsigned i=0;i<22;i++) w[i]=__atomic_load_n(&diag_status.words[i],__ATOMIC_RELAXED);
        __atomic_thread_fence(__ATOMIC_SEQ_CST);
        if(seq==__atomic_load_n(&diag_status.seq,__ATOMIC_ACQUIRE)) {valid=1;break;}
    }
    if(!valid) {rt_kprintf("diag busy\n");return -RT_EBUSY;}
    rt_kprintf("diag variant=%u adc=%u overflow=%u isr=%u/%u control=%u/%u peak_mA=%u bus_mV=%u I_mA=%d,%d,%d\n",
        w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8],(int32_t)w[9],(int32_t)w[10],(int32_t)w[11]);
    rt_kprintf("diag state=%u error=%08x ticks=%u count=%u complete=%u abort=%u target_rpm=%d est_rpm=%d cpu_hz=%u offsets=%u\n",
        w[12],w[13],w[14],w[15],w[16],w[17],(int32_t)w[18],(int32_t)w[19],w[20],w[21]);
    return 0;
}
MSH_CMD_EXPORT_ALIAS(diag_cmd, diag, Temporary isolated feedback diagnostics);
