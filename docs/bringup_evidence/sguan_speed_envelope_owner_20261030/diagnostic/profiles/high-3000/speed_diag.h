/* Temporary isolated bench instrumentation. Not a public status ABI. */
static volatile uint32_t sd_adc,sd_overflow,sd_last,sd_max,sd_control_last,sd_control_max;
static volatile uint32_t sd_reason,sd_pwm_clips,sd_saturated;
static volatile float sd_peak,sd_bus_min,sd_bus_max;
static struct { uint32_t seq,word[32]; } sd_channel;

static void sd_reset(void)
{
    sd_last=sd_max=sd_control_last=sd_control_max=0;
    sd_reason=sd_pwm_clips=sd_saturated=0;
    sd_peak=0;sd_bus_min=1000;sd_bus_max=0;
}
static void sd_stop(unsigned reason)
{
    sd_reason=reason;
    pwm_safe_off(reason==2?FOC_ERROR_ADC:FOC_ERROR_OBSERVER);
}
static int sd_guard(void)
{
    for(unsigned i=0;i<3;i++) {
        if(!isfinite(current[i])) {sd_stop(7);return 0;}
        float mag=fabsf(current[i]);if(mag>sd_peak) sd_peak=mag;
    }
    if(vbus<sd_bus_min) sd_bus_min=vbus;
    if(vbus>sd_bus_max) sd_bus_max=vbus;
    if(sd_peak>=3) {sd_stop(1);return 0;}
    if(!isfinite(vbus)||vbus<22||vbus>27) {sd_stop(5);return 0;}
    if(!isfinite(Sguan.encoder.Real_Speed)||fabsf(Sguan.encoder.Real_Speed)>3300*Value_2PI/60) {
        sd_stop(6);return 0;
    }
    if(high_count>=1200000U) {sd_stop(4);return 0;}
    return 1;
}
static void sd_publish(const struct ns800_foc_status *s)
{
    float ud=Sguan.foc.Ud_in,uq=Sguan.foc.Uq_in;
    float emf=sqrtf(Sguan.transfer.SMO.alpha.Output_Ex*Sguan.transfer.SMO.alpha.Output_Ex+
        Sguan.transfer.SMO.beta.Output_Ex*Sguan.transfer.SMO.beta.Output_Ex);
    float dc=vbus>1 ? 1.5f*(Sguan.foc.Ualpha*Sguan.current.Real_Ialpha+
        Sguan.foc.Ubeta*Sguan.current.Real_Ibeta)/vbus : 0;
    uint32_t w[32]={sd_adc,sd_overflow,sd_last,sd_max,sd_control_last,sd_control_max,
        (uint32_t)(sd_peak*1000),(uint32_t)(vbus*1000),
        (uint32_t)(int32_t)(current[0]*1000),(uint32_t)(int32_t)(current[1]*1000),
        (uint32_t)(int32_t)(current[2]*1000),s->state,s->error,high_count,sd_reason,
        (uint32_t)(int32_t)(Sguan.foc.Target_Speed*60/Value_2PI),
        (uint32_t)(int32_t)(s->speed*60/Value_2PI),400000000U,offset_count,
        (uint32_t)(sd_bus_min*1000),(uint32_t)(sd_bus_max*1000),sd_pwm_clips,sd_saturated,
        (uint32_t)(int32_t)(ud*1000),(uint32_t)(int32_t)(uq*1000),
        (uint32_t)(int32_t)(Sguan.current.Real_Id*1000),(uint32_t)(int32_t)(Sguan.current.Real_Iq*1000),
        (uint32_t)(int32_t)(Sguan.foc.Target_Iq*1000),(uint32_t)(emf*1000),
        (uint32_t)(int32_t)(dc*1000),s->command_seq,s->stop_seq};
    uint32_t seq=__atomic_load_n(&sd_channel.seq,__ATOMIC_RELAXED);
    __atomic_store_n(&sd_channel.seq,seq+1,__ATOMIC_RELAXED);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    for(unsigned i=0;i<32;i++) __atomic_store_n(&sd_channel.word[i],w[i],__ATOMIC_RELAXED);
    __atomic_store_n(&sd_channel.seq,seq+2,__ATOMIC_RELEASE);
}
static int speed_diag(int argc,char **argv)
{
    RT_UNUSED(argc);RT_UNUSED(argv);uint32_t w[32];int valid=0;
    for(unsigned n=0;n<3;n++) {
        uint32_t seq=__atomic_load_n(&sd_channel.seq,__ATOMIC_ACQUIRE);if(seq&1)continue;
        for(unsigned i=0;i<32;i++) w[i]=__atomic_load_n(&sd_channel.word[i],__ATOMIC_RELAXED);
        __atomic_thread_fence(__ATOMIC_SEQ_CST);
        if(seq==__atomic_load_n(&sd_channel.seq,__ATOMIC_ACQUIRE)) {valid=1;break;}
    }
    if(!valid) {rt_kprintf("diag busy\n");return -RT_EBUSY;}
    rt_kprintf("diag adc=%u overflow=%u isr=%u/%u control=%u/%u peak_mA=%u bus_mV=%u I_mA=%d,%d,%d\n",
        w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],(int32_t)w[8],(int32_t)w[9],(int32_t)w[10]);
    rt_kprintf("diag state=%u error=%08x ticks=%u reason=%u target_rpm=%d est_rpm=%d cpu_hz=%u offsets=%u\n",
        w[11],w[12],w[13],w[14],(int32_t)w[15],(int32_t)w[16],w[17],w[18]);
    rt_kprintf("diag bus_min_mV=%u bus_max_mV=%u clips=%u saturated=%u\n",w[19],w[20],w[21],w[22]);
    rt_kprintf("diag Udq_mV=%d,%d Idq_mA=%d,%d iqref_mA=%d emf_mV=%u estimated_dc_mA=%d command_seq=%u stop_seq=%u\n",
        (int32_t)w[23],(int32_t)w[24],(int32_t)w[25],(int32_t)w[26],(int32_t)w[27],w[28],(int32_t)w[29],w[30],w[31]);
    return 0;
}
MSH_CMD_EXPORT_ALIAS(speed_diag,diag,Isolated bounded speed-envelope bench);
