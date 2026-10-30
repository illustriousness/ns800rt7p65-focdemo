/* Temporary bounded board experiment. Removed after A/B/A validation. */
#define TRACE_N 1024U
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
_Static_assert(sizeof(struct trace_sample) == 112, "Trace decoder layout");
struct trace_buffer foc_trace __attribute__((section(".sram2"), aligned(32)));
static SMO_STRUCT zero_observer;
static volatile uint32_t trace_zero_request, trace_zero_active;
static uint32_t zero_count;

static void trace_reset(unsigned kind)
{
    memset(&foc_trace, 0, sizeof(foc_trace));
    foc_trace.magic = 0x504C4C54; foc_trace.version = 1;
    foc_trace.variant = FOC_DIAG_VARIANT; foc_trace.kind = kind;
    foc_trace.capacity = TRACE_N; foc_trace.sample_bytes = sizeof(struct trace_sample);
    foc_trace.cpu_hz = RCC_getCpuclkFrequency(); foc_trace.fs = PWM_HZ;
    foc_trace.overflow_start = adc_overflows;
}

static void trace_sample_save(SMO_STRUCT *smo, uint32_t entered, float previous_angle,
                              float previous_we, int zero)
{
    if (foc_trace.count >= TRACE_N) return;
    struct trace_sample *s = &foc_trace.sample[foc_trace.count];
    s->adc = adc_count; s->dwt = entered;
    s->ia = smo->alpha.Input_Ix; s->ib = smo->beta.Input_Ix;
    s->ihat_a = smo->alpha.Output_Ix; s->ihat_b = smo->beta.Output_Ix;
    s->za = smo->alpha.F_i; s->zb = smo->beta.F_i;
    s->ea = smo->alpha.Output_Ex; s->eb = smo->beta.Output_Ex;
    s->ua = smo->alpha.Input_Ux; s->ub = smo->beta.Input_Ux;
    s->error = zero ? 0 : Sguan.transfer.PLL_encoder.go.Error;
    s->we = zero ? 0 : Sguan.transfer.PLL_encoder.go.OutWe;
    s->angle = zero ? 0 : Sguan.transfer.PLL_encoder.go.OutRe;
    s->speed = zero ? 0 : Sguan.encoder.Real_Speed;
    s->control_angle = zero ? 0 : Sguan.encoder.Real_Re;
    s->id = zero ? 0 : Sguan.current.Real_Id;
    s->iq = zero ? 0 : Sguan.current.Real_Iq;
    s->iqref = zero ? 0 : Sguan.foc.Target_Iq;
    s->phase_u = current[0]; s->phase_v = current[1]; s->phase_w = current[2];
    s->peak = peak_current; s->bus = vbus;
    s->previous_angle = previous_angle; s->previous_we = previous_we;
    s->flags = (running ? 1U : 0U) | (sensorless.closed ? 2U : 0U) |
        (smo->alpha.IntegralFrozen_flag ? 4U : 0U) |
        (smo->beta.IntegralFrozen_flag ? 8U : 0U) | ((uint32_t)fault << 8);
    if (!foc_trace.count) foc_trace.start_adc = adc_count;
    foc_trace.end_adc = adc_count; foc_trace.overflow_end = adc_overflows;
    foc_trace.count++;
    if (foc_trace.count == TRACE_N) foc_trace.completed = 1;
}

/* Runs only with the power stage off. No synthetic input reaches motor control. */
static void trace_zero_poll(void)
{
    if (!__atomic_exchange_n(&trace_zero_request, 0, __ATOMIC_ACQUIRE)) return;
    if (running) return;
    memset(&zero_observer, 0, sizeof(zero_observer));
    zero_observer.T = .00005f; zero_observer.Rs = .2f;
    zero_observer.Ld = zero_observer.Lq = .0004f;
    zero_observer.h = 6; zero_observer.Wc = 800;
    zero_observer.IntMax = 10; zero_observer.IntMin = -10;
    SMO_Init(&zero_observer);
    trace_reset(2); zero_count = 0;
    __atomic_store_n(&trace_zero_active, 1, __ATOMIC_RELEASE);
}

static int trace_cmd(int argc, char **argv)
{
    struct ns800_foc_status s;
    if (argc == 2 && !rt_strcmp(argv[1], "zero")) {
        if (ns800_foc_status_read(&s) != RT_EOK || s.running || trace_zero_active)
            return -RT_EBUSY;
        __atomic_store_n(&trace_zero_request, 1, __ATOMIC_RELEASE);
    }
    rt_kprintf("trace variant=%u kind=%u count=%u complete=%u abort=%u bytes=%u\n",
        FOC_DIAG_VARIANT, foc_trace.kind, foc_trace.count, foc_trace.completed,
        foc_trace.abort, (unsigned)sizeof(foc_trace));
    return 0;
}
MSH_CMD_EXPORT_ALIAS(trace_cmd, trace, Temporary bounded PLL trace);
