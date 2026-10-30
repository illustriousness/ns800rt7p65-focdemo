/*
 * Copyright (c) 2006-2026, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-05-10     rcitach      the first version
 */

.syntax unified
.cpu cortex-m7
.fpu fpv5-d16
.thumb

.global  g_pfnVectors
.global  __Vectors
.global  __Vectors_End
.global  __Vectors_Size

.word _sidata
.word _sdata
.word _edata
.word _sbss
.word _ebss

.section .text.Reset_Handler
.weak Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_sdata
  ldr   r1, =_edata
  ldr   r2, =_sidata
  movs  r3, #0
  b     2f

1:
  ldr   r4, [r2, r3]
  str   r4, [r0, r3]
  adds  r3, r3, #4

2:
  adds  r4, r0, r3
  cmp   r4, r1
  bcc   1b

  ldr   r2, =_sbss
  ldr   r4, =_ebss
  movs  r3, #0
  b     4f

3:
  str   r3, [r2]
  adds  r2, r2, #4

4:
  cmp   r2, r4
  bcc   3b

  bl    SystemInit
  bl    __libc_init_array
  bl    entry
  bx    lr
.size Reset_Handler, .-Reset_Handler

.section .text.Default_Handler,"ax",%progbits
.type Default_Handler, %function
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
.size Default_Handler, .-Default_Handler

.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object
__Vectors:
g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word MemManage_Handler
  .word BusFault_Handler
  .word UsageFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word DebugMon_Handler
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler
  .word WWDG_IRQHandler
  .word IWDG1_IRQHandler
  .word IWDG2_IRQHandler
  .word LVD_IRQHandler
  .word FLASH_IRQHandler
  .word FLASH_ECCERR_IRQHandler
  .word RAM_ECCERR_IRQHandler
  .word RCC_IRQHandler
  .word EXTI3_0_IRQHandler
  .word EXTI7_4_IRQHandler
  .word EXTI11_8_IRQHandler
  .word EXTI15_12_IRQHandler
  .word EXTI_CMP_IRQHandler
  .word EXTI_XINT2_1_IRQHandler
  .word EXTI_XINT5_3_IRQHandler
  .word EDMA1_CH0_IRQHandler
  .word EDMA1_CH1_IRQHandler
  .word EDMA1_CH2_IRQHandler
  .word EDMA1_CH3_IRQHandler
  .word EDMA1_CH4_IRQHandler
  .word EDMA1_CH5_IRQHandler
  .word EDMA1_CH6_IRQHandler
  .word EDMA1_CH7_IRQHandler
  .word EDMA1_CH8_IRQHandler
  .word EDMA1_CH9_IRQHandler
  .word EDMA1_CH10_IRQHandler
  .word EDMA1_CH11_IRQHandler
  .word EDMA1_CH12_IRQHandler
  .word EDMA1_CH13_IRQHandler
  .word EDMA1_CH14_IRQHandler
  .word EDMA1_CH15_IRQHandler
  .word EDMA1_CH16_IRQHandler
  .word EDMA1_CH17_IRQHandler
  .word EDMA1_CH18_IRQHandler
  .word EDMA1_CH19_IRQHandler
  .word EDMA1_CH20_IRQHandler
  .word EDMA1_CH21_IRQHandler
  .word EDMA1_CH22_IRQHandler
  .word EDMA1_CH23_IRQHandler
  .word EDMA1_CH24_IRQHandler
  .word EDMA1_CH25_IRQHandler
  .word EDMA1_CH26_IRQHandler
  .word EDMA1_CH27_IRQHandler
  .word EDMA1_CH28_IRQHandler
  .word EDMA1_CH29_IRQHandler
  .word EDMA1_CH30_IRQHandler
  .word EDMA1_CH31_IRQHandler
  .word EDMA1_ERR_IRQHandler
  .word EDMA2_CH0_IRQHandler
  .word EDMA2_CH1_IRQHandler
  .word EDMA2_CH2_IRQHandler
  .word EDMA2_CH3_IRQHandler
  .word EDMA2_CH4_IRQHandler
  .word EDMA2_CH5_IRQHandler
  .word EDMA2_CH6_IRQHandler
  .word EDMA2_CH7_IRQHandler
  .word EDMA2_CH8_IRQHandler
  .word EDMA2_CH9_IRQHandler
  .word EDMA2_CH10_IRQHandler
  .word EDMA2_CH11_IRQHandler
  .word EDMA2_CH12_IRQHandler
  .word EDMA2_CH13_IRQHandler
  .word EDMA2_CH14_IRQHandler
  .word EDMA2_CH15_IRQHandler
  .word EDMA2_CH16_IRQHandler
  .word EDMA2_CH17_IRQHandler
  .word EDMA2_CH18_IRQHandler
  .word EDMA2_CH19_IRQHandler
  .word EDMA2_CH20_IRQHandler
  .word EDMA2_CH21_IRQHandler
  .word EDMA2_CH22_IRQHandler
  .word EDMA2_CH23_IRQHandler
  .word EDMA2_CH24_IRQHandler
  .word EDMA2_CH25_IRQHandler
  .word EDMA2_CH26_IRQHandler
  .word EDMA2_CH27_IRQHandler
  .word EDMA2_CH28_IRQHandler
  .word EDMA2_CH29_IRQHandler
  .word EDMA2_CH30_IRQHandler
  .word EDMA2_CH31_IRQHandler
  .word EDMA2_ERR_IRQHandler
  .word ADCA_CONV_IRQHandler
  .word ADCA_EVENT_IRQHandler
  .word ADCB_CONV_IRQHandler
  .word ADCB_EVENT_IRQHandler
  .word ADCC_CONV_IRQHandler
  .word ADCC_EVENT_IRQHandler
  .word 0
  .word 0
  .word ADC_SAFE_CHK_IRQHandler
  .word EPWM1_TZINT_IRQHandler
  .word EPWM2_TZINT_IRQHandler
  .word EPWM3_TZINT_IRQHandler
  .word EPWM4_TZINT_IRQHandler
  .word EPWM5_TZINT_IRQHandler
  .word EPWM6_TZINT_IRQHandler
  .word EPWM7_TZINT_IRQHandler
  .word EPWM8_TZINT_IRQHandler
  .word EPWM9_TZINT_IRQHandler
  .word EPWM10_TZINT_IRQHandler
  .word EPWM11_TZINT_IRQHandler
  .word EPWM12_TZINT_IRQHandler
  .word EPWM13_TZINT_IRQHandler
  .word EPWM14_TZINT_IRQHandler
  .word EPWM15_TZINT_IRQHandler
  .word EPWM16_TZINT_IRQHandler
  .word EPWM17_TZINT_IRQHandler
  .word EPWM18_TZINT_IRQHandler
  .word EPWM1_INT_IRQHandler
  .word EPWM2_INT_IRQHandler
  .word EPWM3_INT_IRQHandler
  .word EPWM4_INT_IRQHandler
  .word EPWM5_INT_IRQHandler
  .word EPWM6_INT_IRQHandler
  .word EPWM7_INT_IRQHandler
  .word EPWM8_INT_IRQHandler
  .word EPWM9_INT_IRQHandler
  .word EPWM10_INT_IRQHandler
  .word EPWM11_INT_IRQHandler
  .word EPWM12_INT_IRQHandler
  .word EPWM13_INT_IRQHandler
  .word EPWM14_INT_IRQHandler
  .word EPWM15_INT_IRQHandler
  .word EPWM16_INT_IRQHandler
  .word EPWM17_INT_IRQHandler
  .word EPWM18_INT_IRQHandler
  .word ECAP1_IRQHandler
  .word ECAP2_IRQHandler
  .word ECAP3_IRQHandler
  .word ECAP4_IRQHandler
  .word ECAP5_IRQHandler
  .word ECAP6_IRQHandler
  .word ECAP7_IRQHandler
  .word EQEP1_IRQHandler
  .word EQEP2_IRQHandler
  .word EQEP3_IRQHandler
  .word EQEP4_IRQHandler
  .word EQEP5_IRQHandler
  .word EQEP6_IRQHandler
  .word EPG_IRQHandler
  .word SDFM1_DR_1_IRQHandler
  .word SDFM1_DR_2_IRQHandler
  .word SDFM1_DR_3_IRQHandler
  .word SDFM1_DR_4_IRQHandler
  .word SDFM1_ERR_IRQHandler
  .word SDFM2_DR_1_IRQHandler
  .word SDFM2_DR_2_IRQHandler
  .word SDFM2_DR_3_IRQHandler
  .word SDFM2_DR_4_IRQHandler
  .word SDFM2_ERR_IRQHandler
  .word SDFM3_DR_1_IRQHandler
  .word SDFM3_DR_2_IRQHandler
  .word SDFM3_DR_3_IRQHandler
  .word SDFM3_DR_4_IRQHandler
  .word SDFM3_ERR_IRQHandler
  .word SDFM4_DR_1_IRQHandler
  .word SDFM4_DR_2_IRQHandler
  .word SDFM4_DR_3_IRQHandler
  .word SDFM4_DR_4_IRQHandler
  .word SDFM4_ERR_IRQHandler
  .word LPTIM_IRQHandler
  .word CAN1_1_IRQHandler
  .word CAN1_2_IRQHandler
  .word CAN1_ECC_IRQHandler
  .word CAN1_WKUP_IRQHandler
  .word CANFD1_1_IRQHandler
  .word CANFD1_2_IRQHandler
  .word CANFD1_ECC_IRQHandler
  .word CANFD1_WKUP_TS_IRQHandler
  .word CANFD2_1_IRQHandler
  .word CANFD2_2_IRQHandler
  .word CANFD2_ECC_IRQHandler
  .word CANFD2_WKUP_TS_IRQHandler
  .word BTIM1_IRQHandler
  .word BTIM2_IRQHandler
  .word STIM1_IRQHandler
  .word STIM2_IRQHandler
  .word STIM3_IRQHandler
  .word TIM1_IRQHandler
  .word TIM2_IRQHandler
  .word AWK_IRQHandler
  .word LIN1_IRQHandler
  .word LIN2_IRQHandler
  .word I2C1_MST_IRQHandler
  .word I2C1_SLV_IRQHandler
  .word I2C2_MST_IRQHandler
  .word I2C2_SLV_IRQHandler
  .word 0
  .word PMBUS_IRQHandler
  .word SPI1_RX_IRQHandler
  .word SPI1_TX_IRQHandler
  .word SPI2_RX_IRQHandler
  .word SPI2_TX_IRQHandler
  .word SPI3_RX_IRQHandler
  .word SPI3_TX_IRQHandler
  .word SPI4_RX_IRQHandler
  .word SPI4_TX_IRQHandler
  .word UART1_TX_IRQHandler
  .word UART1_RX_IRQHandler
  .word UART2_TX_IRQHandler
  .word UART2_RX_IRQHandler
  .word UART3_TX_IRQHandler
  .word UART3_RX_IRQHandler
  .word UART4_TX_IRQHandler
  .word UART4_RX_IRQHandler
  .word AESHASH_IRQHandler
  .word TRNG_IRQHandler
  .word QSPI_IRQHandler
  .word EMATH_IRQHandler
  .word DCC1_IRQHandler
  .word DCC2_IRQHandler
  .word DCC3_IRQHandler
  .word MCM_IRQHandler
  .word VDDRDY_IRQHandler
  .word FMU_CFG_IRQHandler
  .word FMU_EVT_IRQHandler
  .word CLB1_IRQHandler
  .word CLB2_IRQHandler
  .word CLB3_IRQHandler
  .word CLB4_IRQHandler
  .word CLB5_IRQHandler
  .word CLB6_IRQHandler
  .word EMIF_IRQHandler
  .word UPP_IRQHandler
  .word MU_IRQHandler
  .word MMATH_IRQHandler
  .word EXTI_TXEV_IRQHandler
__Vectors_End:
.equ __Vectors_Size, __Vectors_End - __Vectors

.weak NMI_Handler
.thumb_set NMI_Handler,Default_Handler

.weak HardFault_Handler
.thumb_set HardFault_Handler,Default_Handler

.weak MemManage_Handler
.thumb_set MemManage_Handler,Default_Handler

.weak BusFault_Handler
.thumb_set BusFault_Handler,Default_Handler

.weak UsageFault_Handler
.thumb_set UsageFault_Handler,Default_Handler

.weak SVC_Handler
.thumb_set SVC_Handler,Default_Handler

.weak DebugMon_Handler
.thumb_set DebugMon_Handler,Default_Handler

.weak PendSV_Handler
.thumb_set PendSV_Handler,Default_Handler

.weak SysTick_Handler
.thumb_set SysTick_Handler,Default_Handler

.weak WWDG_IRQHandler
.thumb_set WWDG_IRQHandler,Default_Handler

.weak IWDG1_IRQHandler
.thumb_set IWDG1_IRQHandler,Default_Handler

.weak IWDG2_IRQHandler
.thumb_set IWDG2_IRQHandler,Default_Handler

.weak LVD_IRQHandler
.thumb_set LVD_IRQHandler,Default_Handler

.weak FLASH_IRQHandler
.thumb_set FLASH_IRQHandler,Default_Handler

.weak FLASH_ECCERR_IRQHandler
.thumb_set FLASH_ECCERR_IRQHandler,Default_Handler

.weak RAM_ECCERR_IRQHandler
.thumb_set RAM_ECCERR_IRQHandler,Default_Handler

.weak RCC_IRQHandler
.thumb_set RCC_IRQHandler,Default_Handler

.weak EXTI3_0_IRQHandler
.thumb_set EXTI3_0_IRQHandler,Default_Handler

.weak EXTI7_4_IRQHandler
.thumb_set EXTI7_4_IRQHandler,Default_Handler

.weak EXTI11_8_IRQHandler
.thumb_set EXTI11_8_IRQHandler,Default_Handler

.weak EXTI15_12_IRQHandler
.thumb_set EXTI15_12_IRQHandler,Default_Handler

.weak EXTI_CMP_IRQHandler
.thumb_set EXTI_CMP_IRQHandler,Default_Handler

.weak EXTI_XINT2_1_IRQHandler
.thumb_set EXTI_XINT2_1_IRQHandler,Default_Handler

.weak EXTI_XINT5_3_IRQHandler
.thumb_set EXTI_XINT5_3_IRQHandler,Default_Handler

.weak EDMA1_CH0_IRQHandler
.thumb_set EDMA1_CH0_IRQHandler,Default_Handler

.weak EDMA1_CH1_IRQHandler
.thumb_set EDMA1_CH1_IRQHandler,Default_Handler

.weak EDMA1_CH2_IRQHandler
.thumb_set EDMA1_CH2_IRQHandler,Default_Handler

.weak EDMA1_CH3_IRQHandler
.thumb_set EDMA1_CH3_IRQHandler,Default_Handler

.weak EDMA1_CH4_IRQHandler
.thumb_set EDMA1_CH4_IRQHandler,Default_Handler

.weak EDMA1_CH5_IRQHandler
.thumb_set EDMA1_CH5_IRQHandler,Default_Handler

.weak EDMA1_CH6_IRQHandler
.thumb_set EDMA1_CH6_IRQHandler,Default_Handler

.weak EDMA1_CH7_IRQHandler
.thumb_set EDMA1_CH7_IRQHandler,Default_Handler

.weak EDMA1_CH8_IRQHandler
.thumb_set EDMA1_CH8_IRQHandler,Default_Handler

.weak EDMA1_CH9_IRQHandler
.thumb_set EDMA1_CH9_IRQHandler,Default_Handler

.weak EDMA1_CH10_IRQHandler
.thumb_set EDMA1_CH10_IRQHandler,Default_Handler

.weak EDMA1_CH11_IRQHandler
.thumb_set EDMA1_CH11_IRQHandler,Default_Handler

.weak EDMA1_CH12_IRQHandler
.thumb_set EDMA1_CH12_IRQHandler,Default_Handler

.weak EDMA1_CH13_IRQHandler
.thumb_set EDMA1_CH13_IRQHandler,Default_Handler

.weak EDMA1_CH14_IRQHandler
.thumb_set EDMA1_CH14_IRQHandler,Default_Handler

.weak EDMA1_CH15_IRQHandler
.thumb_set EDMA1_CH15_IRQHandler,Default_Handler

.weak EDMA1_CH16_IRQHandler
.thumb_set EDMA1_CH16_IRQHandler,Default_Handler

.weak EDMA1_CH17_IRQHandler
.thumb_set EDMA1_CH17_IRQHandler,Default_Handler

.weak EDMA1_CH18_IRQHandler
.thumb_set EDMA1_CH18_IRQHandler,Default_Handler

.weak EDMA1_CH19_IRQHandler
.thumb_set EDMA1_CH19_IRQHandler,Default_Handler

.weak EDMA1_CH20_IRQHandler
.thumb_set EDMA1_CH20_IRQHandler,Default_Handler

.weak EDMA1_CH21_IRQHandler
.thumb_set EDMA1_CH21_IRQHandler,Default_Handler

.weak EDMA1_CH22_IRQHandler
.thumb_set EDMA1_CH22_IRQHandler,Default_Handler

.weak EDMA1_CH23_IRQHandler
.thumb_set EDMA1_CH23_IRQHandler,Default_Handler

.weak EDMA1_CH24_IRQHandler
.thumb_set EDMA1_CH24_IRQHandler,Default_Handler

.weak EDMA1_CH25_IRQHandler
.thumb_set EDMA1_CH25_IRQHandler,Default_Handler

.weak EDMA1_CH26_IRQHandler
.thumb_set EDMA1_CH26_IRQHandler,Default_Handler

.weak EDMA1_CH27_IRQHandler
.thumb_set EDMA1_CH27_IRQHandler,Default_Handler

.weak EDMA1_CH28_IRQHandler
.thumb_set EDMA1_CH28_IRQHandler,Default_Handler

.weak EDMA1_CH29_IRQHandler
.thumb_set EDMA1_CH29_IRQHandler,Default_Handler

.weak EDMA1_CH30_IRQHandler
.thumb_set EDMA1_CH30_IRQHandler,Default_Handler

.weak EDMA1_CH31_IRQHandler
.thumb_set EDMA1_CH31_IRQHandler,Default_Handler

.weak EDMA1_ERR_IRQHandler
.thumb_set EDMA1_ERR_IRQHandler,Default_Handler

.weak EDMA2_CH0_IRQHandler
.thumb_set EDMA2_CH0_IRQHandler,Default_Handler

.weak EDMA2_CH1_IRQHandler
.thumb_set EDMA2_CH1_IRQHandler,Default_Handler

.weak EDMA2_CH2_IRQHandler
.thumb_set EDMA2_CH2_IRQHandler,Default_Handler

.weak EDMA2_CH3_IRQHandler
.thumb_set EDMA2_CH3_IRQHandler,Default_Handler

.weak EDMA2_CH4_IRQHandler
.thumb_set EDMA2_CH4_IRQHandler,Default_Handler

.weak EDMA2_CH5_IRQHandler
.thumb_set EDMA2_CH5_IRQHandler,Default_Handler

.weak EDMA2_CH6_IRQHandler
.thumb_set EDMA2_CH6_IRQHandler,Default_Handler

.weak EDMA2_CH7_IRQHandler
.thumb_set EDMA2_CH7_IRQHandler,Default_Handler

.weak EDMA2_CH8_IRQHandler
.thumb_set EDMA2_CH8_IRQHandler,Default_Handler

.weak EDMA2_CH9_IRQHandler
.thumb_set EDMA2_CH9_IRQHandler,Default_Handler

.weak EDMA2_CH10_IRQHandler
.thumb_set EDMA2_CH10_IRQHandler,Default_Handler

.weak EDMA2_CH11_IRQHandler
.thumb_set EDMA2_CH11_IRQHandler,Default_Handler

.weak EDMA2_CH12_IRQHandler
.thumb_set EDMA2_CH12_IRQHandler,Default_Handler

.weak EDMA2_CH13_IRQHandler
.thumb_set EDMA2_CH13_IRQHandler,Default_Handler

.weak EDMA2_CH14_IRQHandler
.thumb_set EDMA2_CH14_IRQHandler,Default_Handler

.weak EDMA2_CH15_IRQHandler
.thumb_set EDMA2_CH15_IRQHandler,Default_Handler

.weak EDMA2_CH16_IRQHandler
.thumb_set EDMA2_CH16_IRQHandler,Default_Handler

.weak EDMA2_CH17_IRQHandler
.thumb_set EDMA2_CH17_IRQHandler,Default_Handler

.weak EDMA2_CH18_IRQHandler
.thumb_set EDMA2_CH18_IRQHandler,Default_Handler

.weak EDMA2_CH19_IRQHandler
.thumb_set EDMA2_CH19_IRQHandler,Default_Handler

.weak EDMA2_CH20_IRQHandler
.thumb_set EDMA2_CH20_IRQHandler,Default_Handler

.weak EDMA2_CH21_IRQHandler
.thumb_set EDMA2_CH21_IRQHandler,Default_Handler

.weak EDMA2_CH22_IRQHandler
.thumb_set EDMA2_CH22_IRQHandler,Default_Handler

.weak EDMA2_CH23_IRQHandler
.thumb_set EDMA2_CH23_IRQHandler,Default_Handler

.weak EDMA2_CH24_IRQHandler
.thumb_set EDMA2_CH24_IRQHandler,Default_Handler

.weak EDMA2_CH25_IRQHandler
.thumb_set EDMA2_CH25_IRQHandler,Default_Handler

.weak EDMA2_CH26_IRQHandler
.thumb_set EDMA2_CH26_IRQHandler,Default_Handler

.weak EDMA2_CH27_IRQHandler
.thumb_set EDMA2_CH27_IRQHandler,Default_Handler

.weak EDMA2_CH28_IRQHandler
.thumb_set EDMA2_CH28_IRQHandler,Default_Handler

.weak EDMA2_CH29_IRQHandler
.thumb_set EDMA2_CH29_IRQHandler,Default_Handler

.weak EDMA2_CH30_IRQHandler
.thumb_set EDMA2_CH30_IRQHandler,Default_Handler

.weak EDMA2_CH31_IRQHandler
.thumb_set EDMA2_CH31_IRQHandler,Default_Handler

.weak EDMA2_ERR_IRQHandler
.thumb_set EDMA2_ERR_IRQHandler,Default_Handler

.weak ADCA_CONV_IRQHandler
.thumb_set ADCA_CONV_IRQHandler,Default_Handler

.weak ADCA_EVENT_IRQHandler
.thumb_set ADCA_EVENT_IRQHandler,Default_Handler

.weak ADCB_CONV_IRQHandler
.thumb_set ADCB_CONV_IRQHandler,Default_Handler

.weak ADCB_EVENT_IRQHandler
.thumb_set ADCB_EVENT_IRQHandler,Default_Handler

.weak ADCC_CONV_IRQHandler
.thumb_set ADCC_CONV_IRQHandler,Default_Handler

.weak ADCC_EVENT_IRQHandler
.thumb_set ADCC_EVENT_IRQHandler,Default_Handler

.weak ADC_SAFE_CHK_IRQHandler
.thumb_set ADC_SAFE_CHK_IRQHandler,Default_Handler

.weak EPWM1_TZINT_IRQHandler
.thumb_set EPWM1_TZINT_IRQHandler,Default_Handler

.weak EPWM2_TZINT_IRQHandler
.thumb_set EPWM2_TZINT_IRQHandler,Default_Handler

.weak EPWM3_TZINT_IRQHandler
.thumb_set EPWM3_TZINT_IRQHandler,Default_Handler

.weak EPWM4_TZINT_IRQHandler
.thumb_set EPWM4_TZINT_IRQHandler,Default_Handler

.weak EPWM5_TZINT_IRQHandler
.thumb_set EPWM5_TZINT_IRQHandler,Default_Handler

.weak EPWM6_TZINT_IRQHandler
.thumb_set EPWM6_TZINT_IRQHandler,Default_Handler

.weak EPWM7_TZINT_IRQHandler
.thumb_set EPWM7_TZINT_IRQHandler,Default_Handler

.weak EPWM8_TZINT_IRQHandler
.thumb_set EPWM8_TZINT_IRQHandler,Default_Handler

.weak EPWM9_TZINT_IRQHandler
.thumb_set EPWM9_TZINT_IRQHandler,Default_Handler

.weak EPWM10_TZINT_IRQHandler
.thumb_set EPWM10_TZINT_IRQHandler,Default_Handler

.weak EPWM11_TZINT_IRQHandler
.thumb_set EPWM11_TZINT_IRQHandler,Default_Handler

.weak EPWM12_TZINT_IRQHandler
.thumb_set EPWM12_TZINT_IRQHandler,Default_Handler

.weak EPWM13_TZINT_IRQHandler
.thumb_set EPWM13_TZINT_IRQHandler,Default_Handler

.weak EPWM14_TZINT_IRQHandler
.thumb_set EPWM14_TZINT_IRQHandler,Default_Handler

.weak EPWM15_TZINT_IRQHandler
.thumb_set EPWM15_TZINT_IRQHandler,Default_Handler

.weak EPWM16_TZINT_IRQHandler
.thumb_set EPWM16_TZINT_IRQHandler,Default_Handler

.weak EPWM17_TZINT_IRQHandler
.thumb_set EPWM17_TZINT_IRQHandler,Default_Handler

.weak EPWM18_TZINT_IRQHandler
.thumb_set EPWM18_TZINT_IRQHandler,Default_Handler

.weak EPWM1_INT_IRQHandler
.thumb_set EPWM1_INT_IRQHandler,Default_Handler

.weak EPWM2_INT_IRQHandler
.thumb_set EPWM2_INT_IRQHandler,Default_Handler

.weak EPWM3_INT_IRQHandler
.thumb_set EPWM3_INT_IRQHandler,Default_Handler

.weak EPWM4_INT_IRQHandler
.thumb_set EPWM4_INT_IRQHandler,Default_Handler

.weak EPWM5_INT_IRQHandler
.thumb_set EPWM5_INT_IRQHandler,Default_Handler

.weak EPWM6_INT_IRQHandler
.thumb_set EPWM6_INT_IRQHandler,Default_Handler

.weak EPWM7_INT_IRQHandler
.thumb_set EPWM7_INT_IRQHandler,Default_Handler

.weak EPWM8_INT_IRQHandler
.thumb_set EPWM8_INT_IRQHandler,Default_Handler

.weak EPWM9_INT_IRQHandler
.thumb_set EPWM9_INT_IRQHandler,Default_Handler

.weak EPWM10_INT_IRQHandler
.thumb_set EPWM10_INT_IRQHandler,Default_Handler

.weak EPWM11_INT_IRQHandler
.thumb_set EPWM11_INT_IRQHandler,Default_Handler

.weak EPWM12_INT_IRQHandler
.thumb_set EPWM12_INT_IRQHandler,Default_Handler

.weak EPWM13_INT_IRQHandler
.thumb_set EPWM13_INT_IRQHandler,Default_Handler

.weak EPWM14_INT_IRQHandler
.thumb_set EPWM14_INT_IRQHandler,Default_Handler

.weak EPWM15_INT_IRQHandler
.thumb_set EPWM15_INT_IRQHandler,Default_Handler

.weak EPWM16_INT_IRQHandler
.thumb_set EPWM16_INT_IRQHandler,Default_Handler

.weak EPWM17_INT_IRQHandler
.thumb_set EPWM17_INT_IRQHandler,Default_Handler

.weak EPWM18_INT_IRQHandler
.thumb_set EPWM18_INT_IRQHandler,Default_Handler

.weak ECAP1_IRQHandler
.thumb_set ECAP1_IRQHandler,Default_Handler

.weak ECAP2_IRQHandler
.thumb_set ECAP2_IRQHandler,Default_Handler

.weak ECAP3_IRQHandler
.thumb_set ECAP3_IRQHandler,Default_Handler

.weak ECAP4_IRQHandler
.thumb_set ECAP4_IRQHandler,Default_Handler

.weak ECAP5_IRQHandler
.thumb_set ECAP5_IRQHandler,Default_Handler

.weak ECAP6_IRQHandler
.thumb_set ECAP6_IRQHandler,Default_Handler

.weak ECAP7_IRQHandler
.thumb_set ECAP7_IRQHandler,Default_Handler

.weak EQEP1_IRQHandler
.thumb_set EQEP1_IRQHandler,Default_Handler

.weak EQEP2_IRQHandler
.thumb_set EQEP2_IRQHandler,Default_Handler

.weak EQEP3_IRQHandler
.thumb_set EQEP3_IRQHandler,Default_Handler

.weak EQEP4_IRQHandler
.thumb_set EQEP4_IRQHandler,Default_Handler

.weak EQEP5_IRQHandler
.thumb_set EQEP5_IRQHandler,Default_Handler

.weak EQEP6_IRQHandler
.thumb_set EQEP6_IRQHandler,Default_Handler

.weak EPG_IRQHandler
.thumb_set EPG_IRQHandler,Default_Handler

.weak SDFM1_DR_1_IRQHandler
.thumb_set SDFM1_DR_1_IRQHandler,Default_Handler

.weak SDFM1_DR_2_IRQHandler
.thumb_set SDFM1_DR_2_IRQHandler,Default_Handler

.weak SDFM1_DR_3_IRQHandler
.thumb_set SDFM1_DR_3_IRQHandler,Default_Handler

.weak SDFM1_DR_4_IRQHandler
.thumb_set SDFM1_DR_4_IRQHandler,Default_Handler

.weak SDFM1_ERR_IRQHandler
.thumb_set SDFM1_ERR_IRQHandler,Default_Handler

.weak SDFM2_DR_1_IRQHandler
.thumb_set SDFM2_DR_1_IRQHandler,Default_Handler

.weak SDFM2_DR_2_IRQHandler
.thumb_set SDFM2_DR_2_IRQHandler,Default_Handler

.weak SDFM2_DR_3_IRQHandler
.thumb_set SDFM2_DR_3_IRQHandler,Default_Handler

.weak SDFM2_DR_4_IRQHandler
.thumb_set SDFM2_DR_4_IRQHandler,Default_Handler

.weak SDFM2_ERR_IRQHandler
.thumb_set SDFM2_ERR_IRQHandler,Default_Handler

.weak SDFM3_DR_1_IRQHandler
.thumb_set SDFM3_DR_1_IRQHandler,Default_Handler

.weak SDFM3_DR_2_IRQHandler
.thumb_set SDFM3_DR_2_IRQHandler,Default_Handler

.weak SDFM3_DR_3_IRQHandler
.thumb_set SDFM3_DR_3_IRQHandler,Default_Handler

.weak SDFM3_DR_4_IRQHandler
.thumb_set SDFM3_DR_4_IRQHandler,Default_Handler

.weak SDFM3_ERR_IRQHandler
.thumb_set SDFM3_ERR_IRQHandler,Default_Handler

.weak SDFM4_DR_1_IRQHandler
.thumb_set SDFM4_DR_1_IRQHandler,Default_Handler

.weak SDFM4_DR_2_IRQHandler
.thumb_set SDFM4_DR_2_IRQHandler,Default_Handler

.weak SDFM4_DR_3_IRQHandler
.thumb_set SDFM4_DR_3_IRQHandler,Default_Handler

.weak SDFM4_DR_4_IRQHandler
.thumb_set SDFM4_DR_4_IRQHandler,Default_Handler

.weak SDFM4_ERR_IRQHandler
.thumb_set SDFM4_ERR_IRQHandler,Default_Handler

.weak LPTIM_IRQHandler
.thumb_set LPTIM_IRQHandler,Default_Handler

.weak CAN1_1_IRQHandler
.thumb_set CAN1_1_IRQHandler,Default_Handler

.weak CAN1_2_IRQHandler
.thumb_set CAN1_2_IRQHandler,Default_Handler

.weak CAN1_ECC_IRQHandler
.thumb_set CAN1_ECC_IRQHandler,Default_Handler

.weak CAN1_WKUP_IRQHandler
.thumb_set CAN1_WKUP_IRQHandler,Default_Handler

.weak CANFD1_1_IRQHandler
.thumb_set CANFD1_1_IRQHandler,Default_Handler

.weak CANFD1_2_IRQHandler
.thumb_set CANFD1_2_IRQHandler,Default_Handler

.weak CANFD1_ECC_IRQHandler
.thumb_set CANFD1_ECC_IRQHandler,Default_Handler

.weak CANFD1_WKUP_TS_IRQHandler
.thumb_set CANFD1_WKUP_TS_IRQHandler,Default_Handler

.weak CANFD2_1_IRQHandler
.thumb_set CANFD2_1_IRQHandler,Default_Handler

.weak CANFD2_2_IRQHandler
.thumb_set CANFD2_2_IRQHandler,Default_Handler

.weak CANFD2_ECC_IRQHandler
.thumb_set CANFD2_ECC_IRQHandler,Default_Handler

.weak CANFD2_WKUP_TS_IRQHandler
.thumb_set CANFD2_WKUP_TS_IRQHandler,Default_Handler

.weak BTIM1_IRQHandler
.thumb_set BTIM1_IRQHandler,Default_Handler

.weak BTIM2_IRQHandler
.thumb_set BTIM2_IRQHandler,Default_Handler

.weak STIM1_IRQHandler
.thumb_set STIM1_IRQHandler,Default_Handler

.weak STIM2_IRQHandler
.thumb_set STIM2_IRQHandler,Default_Handler

.weak STIM3_IRQHandler
.thumb_set STIM3_IRQHandler,Default_Handler

.weak TIM1_IRQHandler
.thumb_set TIM1_IRQHandler,Default_Handler

.weak TIM2_IRQHandler
.thumb_set TIM2_IRQHandler,Default_Handler

.weak AWK_IRQHandler
.thumb_set AWK_IRQHandler,Default_Handler

.weak LIN1_IRQHandler
.thumb_set LIN1_IRQHandler,Default_Handler

.weak LIN2_IRQHandler
.thumb_set LIN2_IRQHandler,Default_Handler

.weak I2C1_MST_IRQHandler
.thumb_set I2C1_MST_IRQHandler,Default_Handler

.weak I2C1_SLV_IRQHandler
.thumb_set I2C1_SLV_IRQHandler,Default_Handler

.weak I2C2_MST_IRQHandler
.thumb_set I2C2_MST_IRQHandler,Default_Handler

.weak I2C2_SLV_IRQHandler
.thumb_set I2C2_SLV_IRQHandler,Default_Handler

.weak PMBUS_IRQHandler
.thumb_set PMBUS_IRQHandler,Default_Handler

.weak SPI1_RX_IRQHandler
.thumb_set SPI1_RX_IRQHandler,Default_Handler

.weak SPI1_TX_IRQHandler
.thumb_set SPI1_TX_IRQHandler,Default_Handler

.weak SPI2_RX_IRQHandler
.thumb_set SPI2_RX_IRQHandler,Default_Handler

.weak SPI2_TX_IRQHandler
.thumb_set SPI2_TX_IRQHandler,Default_Handler

.weak SPI3_RX_IRQHandler
.thumb_set SPI3_RX_IRQHandler,Default_Handler

.weak SPI3_TX_IRQHandler
.thumb_set SPI3_TX_IRQHandler,Default_Handler

.weak SPI4_RX_IRQHandler
.thumb_set SPI4_RX_IRQHandler,Default_Handler

.weak SPI4_TX_IRQHandler
.thumb_set SPI4_TX_IRQHandler,Default_Handler

.weak UART1_TX_IRQHandler
.thumb_set UART1_TX_IRQHandler,Default_Handler

.weak UART1_RX_IRQHandler
.thumb_set UART1_RX_IRQHandler,Default_Handler

.weak UART2_TX_IRQHandler
.thumb_set UART2_TX_IRQHandler,Default_Handler

.weak UART2_RX_IRQHandler
.thumb_set UART2_RX_IRQHandler,Default_Handler

.weak UART3_TX_IRQHandler
.thumb_set UART3_TX_IRQHandler,Default_Handler

.weak UART3_RX_IRQHandler
.thumb_set UART3_RX_IRQHandler,Default_Handler

.weak UART4_TX_IRQHandler
.thumb_set UART4_TX_IRQHandler,Default_Handler

.weak UART4_RX_IRQHandler
.thumb_set UART4_RX_IRQHandler,Default_Handler

.weak AESHASH_IRQHandler
.thumb_set AESHASH_IRQHandler,Default_Handler

.weak TRNG_IRQHandler
.thumb_set TRNG_IRQHandler,Default_Handler

.weak QSPI_IRQHandler
.thumb_set QSPI_IRQHandler,Default_Handler

.weak EMATH_IRQHandler
.thumb_set EMATH_IRQHandler,Default_Handler

.weak DCC1_IRQHandler
.thumb_set DCC1_IRQHandler,Default_Handler

.weak DCC2_IRQHandler
.thumb_set DCC2_IRQHandler,Default_Handler

.weak DCC3_IRQHandler
.thumb_set DCC3_IRQHandler,Default_Handler

.weak MCM_IRQHandler
.thumb_set MCM_IRQHandler,Default_Handler

.weak VDDRDY_IRQHandler
.thumb_set VDDRDY_IRQHandler,Default_Handler

.weak FMU_CFG_IRQHandler
.thumb_set FMU_CFG_IRQHandler,Default_Handler

.weak FMU_EVT_IRQHandler
.thumb_set FMU_EVT_IRQHandler,Default_Handler

.weak CLB1_IRQHandler
.thumb_set CLB1_IRQHandler,Default_Handler

.weak CLB2_IRQHandler
.thumb_set CLB2_IRQHandler,Default_Handler

.weak CLB3_IRQHandler
.thumb_set CLB3_IRQHandler,Default_Handler

.weak CLB4_IRQHandler
.thumb_set CLB4_IRQHandler,Default_Handler

.weak CLB5_IRQHandler
.thumb_set CLB5_IRQHandler,Default_Handler

.weak CLB6_IRQHandler
.thumb_set CLB6_IRQHandler,Default_Handler

.weak EMIF_IRQHandler
.thumb_set EMIF_IRQHandler,Default_Handler

.weak UPP_IRQHandler
.thumb_set UPP_IRQHandler,Default_Handler

.weak MU_IRQHandler
.thumb_set MU_IRQHandler,Default_Handler

.weak MMATH_IRQHandler
.thumb_set MMATH_IRQHandler,Default_Handler

.weak EXTI_TXEV_IRQHandler
.thumb_set EXTI_TXEV_IRQHandler,Default_Handler
