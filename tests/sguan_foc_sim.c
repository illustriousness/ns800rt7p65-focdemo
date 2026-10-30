/* Independent PMSM plant exercises the actual SguanFOC entry points.
 * Both host and board now use the exact upstream software math implementation. */
#include "SguanFOC.h"
#include "foc_sensorless.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
volatile uint8_t ns800_foc_start_requested;
static float ia, ib, theta, omega, va, vb;
static int blocked;
static struct foc_sensorless_monitor sensorless;
void ns800_foc_delay(uint32_t ms) { (void)ms; }
void ns800_foc_user_initial(void) { }
void ns800_foc_user_start(void) { }
float ns800_foc_vbus(void) { return 24; }
int32_t ns800_foc_adc_raw(int32_t ch) {
    float cur = ch == 0 ? ia : (-ia + sqrtf(3)*ib)/2;
    return 1558 + (int32_t)lroundf(cur/(-3.3f/(4096*6*.02f)));
}
void ns800_foc_pwm_set(uint32_t u, uint32_t v, uint32_t w) {
    float a=((float)u/1000-.5f)*24,b=((float)v/1000-.5f)*24,c=((float)w/1000-.5f)*24;
    va=(2*a-b-c)/3; vb=(b-c)/sqrtf(3);
    Sguan.foc.Ualpha=va; Sguan.foc.Ubeta=vb;
}
int main(int argc, char **argv) {
    float target=argc>1?atof(argv[1]):500;
    blocked=argc>2 && strcmp(argv[2],"0")!=0;
    theta=argc>3?atof(argv[3]):0.0f;
    SguanFOC_main_Loop();
    memset(&Sguan.value,0,sizeof(Sguan.value));
    memset(&Sguan.encoder,0,sizeof(Sguan.encoder));
    foc_sensorless_reset(&sensorless);
    Sguan.Func_Start(); SguanFOC_main_Loop();
    Sguan.foc.Real_VBUS=24; Sguan.foc.Target_IF_Iq=target>0?.8f:-.8f;
    Sguan.Func_Set_Velocity(target*Value_2PI/60);
    float max_est_error=0, sum_est_error=0, max_plant_error=0;
    unsigned steady_samples=0;
    for (int n=0;n<260000;n++) {
        SguanFOC_High_Loop();
        if((n+1)%20==0) {
            SguanFOC_Low_Loop();
            if(!foc_sensorless_tick(&sensorless,&Sguan)) {
                if(blocked && !sensorless.closed && sensorless.elapsed_ms>=10000) {
                    puts("blocked rotor rejected within startup deadline"); return 0;
                }
                fprintf(stderr,"board supervisor fault at %.3fs\n",n*.00005f); return 1;
            }
        }
        float sn=sinf(theta),cs=cosf(theta),iq=-ia*sn+ib*cs;
        const float dt=.00005f,R=.2f,L=.0004f,flux=.021f;
        ia+=dt/L*(va-R*ia+2*omega*flux*sn); ib+=dt/L*(vb-R*ib-2*omega*flux*cs);
        if (!blocked) {
            omega+=dt*(3*flux*iq-.0001f*omega)/.0000173f;
            theta=Value_normalize(theta+dt*2*omega);
        }
        if(n%20000==0) printf("t=%.1f actual=%.1f est=%.1f high=%.1f I=%.2f phase=%.2f observer=%u closed=%u status=%u\n",
            n*dt,omega*60/Value_2PI,Sguan.encoder.Real_Speed*60/Value_2PI,Sguan.value.High_Wm*60/Value_2PI,
            hypotf(ia,ib),Sguan.encoder.Real_Re-theta,
            (unsigned)(Sguan.value.Speed_abs>Sguan.value.Sensorless_AbsMin),sensorless.closed,Sguan.status);
        if (!isfinite(ia)||hypotf(ia,ib)>3.5f) { fprintf(stderr,"current/nonfinite at %.3fs\n",n*dt); return 1; }
        if(Sguan.status>=MOTOR_STATUS_OVERVOLTAGE) {
            fprintf(stderr,"library fault at %.3fs status=%u\n",n*dt,Sguan.status); return 1;
        }
        if(n>=200000) {
            float error=fabsf(Sguan.encoder.Real_Speed*60/Value_2PI-target);
            sum_est_error+=error; steady_samples++;
            if(error>max_est_error) max_est_error=error;
            error=fabsf(omega*60/Value_2PI-target);
            if(error>max_plant_error) max_plant_error=error;
        }
    }
    printf("steady errors: estimate max=%.2f mean=%.2f plant max=%.2f rpm\n",
           max_est_error,sum_est_error/steady_samples,max_plant_error);
    if(blocked || !sensorless.closed || max_est_error>50 ||
       sum_est_error/steady_samples>25 || max_plant_error>25) return 1;
    puts("independent plant closed-loop pass");
    return 0;
}
