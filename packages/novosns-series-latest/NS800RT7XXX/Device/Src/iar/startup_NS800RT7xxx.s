/*
 * Copyright (c) 2006-2026, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-05-10     rcitach      the first version
 */

        MODULE  ?cstartup

        SECTION CSTACK:DATA:NOROOT(3)
        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table
        PUBLIC  __Vectors
        PUBLIC  __Vectors_End
        PUBLIC  __Vectors_Size

        DATA

__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler
        DCD     NMI_Handler
        DCD     HardFault_Handler
        DCD     MemManage_Handler
        DCD     BusFault_Handler
        DCD     UsageFault_Handler
        DCD     0
        DCD     0
        DCD     0
        DCD     0
        DCD     SVC_Handler
        DCD     DebugMon_Handler
        DCD     0
        DCD     PendSV_Handler
        DCD     SysTick_Handler
        DCD     WWDG_IRQHandler
        DCD     IWDG1_IRQHandler
        DCD     IWDG2_IRQHandler
        DCD     LVD_IRQHandler
        DCD     FLASH_IRQHandler
        DCD     FLASH_ECCERR_IRQHandler
        DCD     RAM_ECCERR_IRQHandler
        DCD     RCC_IRQHandler
        DCD     EXTI3_0_IRQHandler
        DCD     EXTI7_4_IRQHandler
        DCD     EXTI11_8_IRQHandler
        DCD     EXTI15_12_IRQHandler
        DCD     EXTI_CMP_IRQHandler
        DCD     EXTI_XINT2_1_IRQHandler
        DCD     EXTI_XINT5_3_IRQHandler
        DCD     EDMA1_CH0_IRQHandler
        DCD     EDMA1_CH1_IRQHandler
        DCD     EDMA1_CH2_IRQHandler
        DCD     EDMA1_CH3_IRQHandler
        DCD     EDMA1_CH4_IRQHandler
        DCD     EDMA1_CH5_IRQHandler
        DCD     EDMA1_CH6_IRQHandler
        DCD     EDMA1_CH7_IRQHandler
        DCD     EDMA1_CH8_IRQHandler
        DCD     EDMA1_CH9_IRQHandler
        DCD     EDMA1_CH10_IRQHandler
        DCD     EDMA1_CH11_IRQHandler
        DCD     EDMA1_CH12_IRQHandler
        DCD     EDMA1_CH13_IRQHandler
        DCD     EDMA1_CH14_IRQHandler
        DCD     EDMA1_CH15_IRQHandler
        DCD     EDMA1_CH16_IRQHandler
        DCD     EDMA1_CH17_IRQHandler
        DCD     EDMA1_CH18_IRQHandler
        DCD     EDMA1_CH19_IRQHandler
        DCD     EDMA1_CH20_IRQHandler
        DCD     EDMA1_CH21_IRQHandler
        DCD     EDMA1_CH22_IRQHandler
        DCD     EDMA1_CH23_IRQHandler
        DCD     EDMA1_CH24_IRQHandler
        DCD     EDMA1_CH25_IRQHandler
        DCD     EDMA1_CH26_IRQHandler
        DCD     EDMA1_CH27_IRQHandler
        DCD     EDMA1_CH28_IRQHandler
        DCD     EDMA1_CH29_IRQHandler
        DCD     EDMA1_CH30_IRQHandler
        DCD     EDMA1_CH31_IRQHandler
        DCD     EDMA1_ERR_IRQHandler
        DCD     EDMA2_CH0_IRQHandler
        DCD     EDMA2_CH1_IRQHandler
        DCD     EDMA2_CH2_IRQHandler
        DCD     EDMA2_CH3_IRQHandler
        DCD     EDMA2_CH4_IRQHandler
        DCD     EDMA2_CH5_IRQHandler
        DCD     EDMA2_CH6_IRQHandler
        DCD     EDMA2_CH7_IRQHandler
        DCD     EDMA2_CH8_IRQHandler
        DCD     EDMA2_CH9_IRQHandler
        DCD     EDMA2_CH10_IRQHandler
        DCD     EDMA2_CH11_IRQHandler
        DCD     EDMA2_CH12_IRQHandler
        DCD     EDMA2_CH13_IRQHandler
        DCD     EDMA2_CH14_IRQHandler
        DCD     EDMA2_CH15_IRQHandler
        DCD     EDMA2_CH16_IRQHandler
        DCD     EDMA2_CH17_IRQHandler
        DCD     EDMA2_CH18_IRQHandler
        DCD     EDMA2_CH19_IRQHandler
        DCD     EDMA2_CH20_IRQHandler
        DCD     EDMA2_CH21_IRQHandler
        DCD     EDMA2_CH22_IRQHandler
        DCD     EDMA2_CH23_IRQHandler
        DCD     EDMA2_CH24_IRQHandler
        DCD     EDMA2_CH25_IRQHandler
        DCD     EDMA2_CH26_IRQHandler
        DCD     EDMA2_CH27_IRQHandler
        DCD     EDMA2_CH28_IRQHandler
        DCD     EDMA2_CH29_IRQHandler
        DCD     EDMA2_CH30_IRQHandler
        DCD     EDMA2_CH31_IRQHandler
        DCD     EDMA2_ERR_IRQHandler
        DCD     ADCA_CONV_IRQHandler
        DCD     ADCA_EVENT_IRQHandler
        DCD     ADCB_CONV_IRQHandler
        DCD     ADCB_EVENT_IRQHandler
        DCD     ADCC_CONV_IRQHandler
        DCD     ADCC_EVENT_IRQHandler
        DCD     0
        DCD     0
        DCD     ADC_SAFE_CHK_IRQHandler
        DCD     EPWM1_TZINT_IRQHandler
        DCD     EPWM2_TZINT_IRQHandler
        DCD     EPWM3_TZINT_IRQHandler
        DCD     EPWM4_TZINT_IRQHandler
        DCD     EPWM5_TZINT_IRQHandler
        DCD     EPWM6_TZINT_IRQHandler
        DCD     EPWM7_TZINT_IRQHandler
        DCD     EPWM8_TZINT_IRQHandler
        DCD     EPWM9_TZINT_IRQHandler
        DCD     EPWM10_TZINT_IRQHandler
        DCD     EPWM11_TZINT_IRQHandler
        DCD     EPWM12_TZINT_IRQHandler
        DCD     EPWM13_TZINT_IRQHandler
        DCD     EPWM14_TZINT_IRQHandler
        DCD     EPWM15_TZINT_IRQHandler
        DCD     EPWM16_TZINT_IRQHandler
        DCD     EPWM17_TZINT_IRQHandler
        DCD     EPWM18_TZINT_IRQHandler
        DCD     EPWM1_INT_IRQHandler
        DCD     EPWM2_INT_IRQHandler
        DCD     EPWM3_INT_IRQHandler
        DCD     EPWM4_INT_IRQHandler
        DCD     EPWM5_INT_IRQHandler
        DCD     EPWM6_INT_IRQHandler
        DCD     EPWM7_INT_IRQHandler
        DCD     EPWM8_INT_IRQHandler
        DCD     EPWM9_INT_IRQHandler
        DCD     EPWM10_INT_IRQHandler
        DCD     EPWM11_INT_IRQHandler
        DCD     EPWM12_INT_IRQHandler
        DCD     EPWM13_INT_IRQHandler
        DCD     EPWM14_INT_IRQHandler
        DCD     EPWM15_INT_IRQHandler
        DCD     EPWM16_INT_IRQHandler
        DCD     EPWM17_INT_IRQHandler
        DCD     EPWM18_INT_IRQHandler
        DCD     ECAP1_IRQHandler
        DCD     ECAP2_IRQHandler
        DCD     ECAP3_IRQHandler
        DCD     ECAP4_IRQHandler
        DCD     ECAP5_IRQHandler
        DCD     ECAP6_IRQHandler
        DCD     ECAP7_IRQHandler
        DCD     EQEP1_IRQHandler
        DCD     EQEP2_IRQHandler
        DCD     EQEP3_IRQHandler
        DCD     EQEP4_IRQHandler
        DCD     EQEP5_IRQHandler
        DCD     EQEP6_IRQHandler
        DCD     EPG_IRQHandler
        DCD     SDFM1_DR_1_IRQHandler
        DCD     SDFM1_DR_2_IRQHandler
        DCD     SDFM1_DR_3_IRQHandler
        DCD     SDFM1_DR_4_IRQHandler
        DCD     SDFM1_ERR_IRQHandler
        DCD     SDFM2_DR_1_IRQHandler
        DCD     SDFM2_DR_2_IRQHandler
        DCD     SDFM2_DR_3_IRQHandler
        DCD     SDFM2_DR_4_IRQHandler
        DCD     SDFM2_ERR_IRQHandler
        DCD     SDFM3_DR_1_IRQHandler
        DCD     SDFM3_DR_2_IRQHandler
        DCD     SDFM3_DR_3_IRQHandler
        DCD     SDFM3_DR_4_IRQHandler
        DCD     SDFM3_ERR_IRQHandler
        DCD     SDFM4_DR_1_IRQHandler
        DCD     SDFM4_DR_2_IRQHandler
        DCD     SDFM4_DR_3_IRQHandler
        DCD     SDFM4_DR_4_IRQHandler
        DCD     SDFM4_ERR_IRQHandler
        DCD     LPTIM_IRQHandler
        DCD     CAN1_1_IRQHandler
        DCD     CAN1_2_IRQHandler
        DCD     CAN1_ECC_IRQHandler
        DCD     CAN1_WKUP_IRQHandler
        DCD     CANFD1_1_IRQHandler
        DCD     CANFD1_2_IRQHandler
        DCD     CANFD1_ECC_IRQHandler
        DCD     CANFD1_WKUP_TS_IRQHandler
        DCD     CANFD2_1_IRQHandler
        DCD     CANFD2_2_IRQHandler
        DCD     CANFD2_ECC_IRQHandler
        DCD     CANFD2_WKUP_TS_IRQHandler
        DCD     BTIM1_IRQHandler
        DCD     BTIM2_IRQHandler
        DCD     STIM1_IRQHandler
        DCD     STIM2_IRQHandler
        DCD     STIM3_IRQHandler
        DCD     TIM1_IRQHandler
        DCD     TIM2_IRQHandler
        DCD     AWK_IRQHandler
        DCD     LIN1_IRQHandler
        DCD     LIN2_IRQHandler
        DCD     I2C1_MST_IRQHandler
        DCD     I2C1_SLV_IRQHandler
        DCD     I2C2_MST_IRQHandler
        DCD     I2C2_SLV_IRQHandler
        DCD     0
        DCD     PMBUS_IRQHandler
        DCD     SPI1_RX_IRQHandler
        DCD     SPI1_TX_IRQHandler
        DCD     SPI2_RX_IRQHandler
        DCD     SPI2_TX_IRQHandler
        DCD     SPI3_RX_IRQHandler
        DCD     SPI3_TX_IRQHandler
        DCD     SPI4_RX_IRQHandler
        DCD     SPI4_TX_IRQHandler
        DCD     UART1_TX_IRQHandler
        DCD     UART1_RX_IRQHandler
        DCD     UART2_TX_IRQHandler
        DCD     UART2_RX_IRQHandler
        DCD     UART3_TX_IRQHandler
        DCD     UART3_RX_IRQHandler
        DCD     UART4_TX_IRQHandler
        DCD     UART4_RX_IRQHandler
        DCD     AESHASH_IRQHandler
        DCD     TRNG_IRQHandler
        DCD     QSPI_IRQHandler
        DCD     EMATH_IRQHandler
        DCD     DCC1_IRQHandler
        DCD     DCC2_IRQHandler
        DCD     DCC3_IRQHandler
        DCD     MCM_IRQHandler
        DCD     VDDRDY_IRQHandler
        DCD     FMU_CFG_IRQHandler
        DCD     FMU_EVT_IRQHandler
        DCD     CLB1_IRQHandler
        DCD     CLB2_IRQHandler
        DCD     CLB3_IRQHandler
        DCD     CLB4_IRQHandler
        DCD     CLB5_IRQHandler
        DCD     CLB6_IRQHandler
        DCD     EMIF_IRQHandler
        DCD     UPP_IRQHandler
        DCD     MU_IRQHandler
        DCD     MMATH_IRQHandler
        DCD     EXTI_TXEV_IRQHandler

__Vectors       EQU     __vector_table
__Vectors_End
__Vectors_Size  EQU     __Vectors_End - __Vectors

        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK Default_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
Default_Handler
        B       Default_Handler

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B       Default_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B       Default_Handler

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B       Default_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B       Default_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B       Default_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B       Default_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B       Default_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B       Default_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B       Default_Handler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WWDG_IRQHandler
        B       Default_Handler

        PUBWEAK IWDG1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
IWDG1_IRQHandler
        B       Default_Handler

        PUBWEAK IWDG2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
IWDG2_IRQHandler
        B       Default_Handler

        PUBWEAK LVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LVD_IRQHandler
        B       Default_Handler

        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_IRQHandler
        B       Default_Handler

        PUBWEAK FLASH_ECCERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_ECCERR_IRQHandler
        B       Default_Handler

        PUBWEAK RAM_ECCERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RAM_ECCERR_IRQHandler
        B       Default_Handler

        PUBWEAK RCC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RCC_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI3_0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_0_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI7_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI7_4_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI11_8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI11_8_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI15_12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI15_12_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI_CMP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI_CMP_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI_XINT2_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI_XINT2_1_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI_XINT5_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI_XINT5_3_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH0_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH1_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH2_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH3_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH4_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH5_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH6_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH7_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH8_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH9_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH10_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH11_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH12_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH13_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH14_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH14_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH15_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH16_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH16_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH17_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH17_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH18_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH18_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH19_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH19_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH20_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH20_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH21_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH21_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH22_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH22_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH23_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH23_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH24_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH24_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH25_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH25_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH26_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH26_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH27_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH27_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH28_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH28_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH29_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH29_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH30_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH30_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_CH31_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_CH31_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA1_ERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA1_ERR_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH0_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH1_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH2_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH3_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH4_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH5_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH6_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH7_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH8_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH9_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH10_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH11_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH12_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH13_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH14_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH14_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH15_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH16_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH16_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH17_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH17_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH18_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH18_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH19_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH19_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH20_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH20_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH21_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH21_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH22_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH22_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH23_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH23_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH24_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH24_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH25_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH25_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH26_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH26_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH27_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH27_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH28_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH28_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH29_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH29_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH30_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH30_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_CH31_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_CH31_IRQHandler
        B       Default_Handler

        PUBWEAK EDMA2_ERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EDMA2_ERR_IRQHandler
        B       Default_Handler

        PUBWEAK ADCA_CONV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADCA_CONV_IRQHandler
        B       Default_Handler

        PUBWEAK ADCA_EVENT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADCA_EVENT_IRQHandler
        B       Default_Handler

        PUBWEAK ADCB_CONV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADCB_CONV_IRQHandler
        B       Default_Handler

        PUBWEAK ADCB_EVENT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADCB_EVENT_IRQHandler
        B       Default_Handler

        PUBWEAK ADCC_CONV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADCC_CONV_IRQHandler
        B       Default_Handler

        PUBWEAK ADCC_EVENT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADCC_EVENT_IRQHandler
        B       Default_Handler

        PUBWEAK ADC_SAFE_CHK_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC_SAFE_CHK_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM1_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM1_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM2_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM2_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM3_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM3_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM4_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM4_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM5_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM5_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM6_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM6_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM7_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM7_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM8_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM8_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM9_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM9_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM10_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM10_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM11_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM11_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM12_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM12_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM13_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM13_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM14_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM14_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM15_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM15_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM16_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM16_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM17_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM17_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM18_TZINT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM18_TZINT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM1_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM1_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM2_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM2_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM3_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM3_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM4_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM4_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM5_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM5_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM6_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM6_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM7_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM7_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM8_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM8_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM9_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM9_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM10_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM10_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM11_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM11_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM12_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM12_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM13_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM13_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM14_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM14_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM15_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM15_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM16_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM16_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM17_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM17_INT_IRQHandler
        B       Default_Handler

        PUBWEAK EPWM18_INT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPWM18_INT_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP1_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP2_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP3_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP4_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP5_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP6_IRQHandler
        B       Default_Handler

        PUBWEAK ECAP7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECAP7_IRQHandler
        B       Default_Handler

        PUBWEAK EQEP1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EQEP1_IRQHandler
        B       Default_Handler

        PUBWEAK EQEP2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EQEP2_IRQHandler
        B       Default_Handler

        PUBWEAK EQEP3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EQEP3_IRQHandler
        B       Default_Handler

        PUBWEAK EQEP4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EQEP4_IRQHandler
        B       Default_Handler

        PUBWEAK EQEP5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EQEP5_IRQHandler
        B       Default_Handler

        PUBWEAK EQEP6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EQEP6_IRQHandler
        B       Default_Handler

        PUBWEAK EPG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EPG_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM1_DR_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM1_DR_1_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM1_DR_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM1_DR_2_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM1_DR_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM1_DR_3_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM1_DR_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM1_DR_4_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM1_ERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM1_ERR_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM2_DR_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM2_DR_1_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM2_DR_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM2_DR_2_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM2_DR_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM2_DR_3_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM2_DR_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM2_DR_4_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM2_ERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM2_ERR_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM3_DR_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM3_DR_1_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM3_DR_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM3_DR_2_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM3_DR_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM3_DR_3_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM3_DR_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM3_DR_4_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM3_ERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM3_ERR_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM4_DR_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM4_DR_1_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM4_DR_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM4_DR_2_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM4_DR_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM4_DR_3_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM4_DR_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM4_DR_4_IRQHandler
        B       Default_Handler

        PUBWEAK SDFM4_ERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SDFM4_ERR_IRQHandler
        B       Default_Handler

        PUBWEAK LPTIM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LPTIM_IRQHandler
        B       Default_Handler

        PUBWEAK CAN1_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_1_IRQHandler
        B       Default_Handler

        PUBWEAK CAN1_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_2_IRQHandler
        B       Default_Handler

        PUBWEAK CAN1_ECC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_ECC_IRQHandler
        B       Default_Handler

        PUBWEAK CAN1_WKUP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_WKUP_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD1_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD1_1_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD1_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD1_2_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD1_ECC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD1_ECC_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD1_WKUP_TS_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD1_WKUP_TS_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD2_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD2_1_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD2_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD2_2_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD2_ECC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD2_ECC_IRQHandler
        B       Default_Handler

        PUBWEAK CANFD2_WKUP_TS_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CANFD2_WKUP_TS_IRQHandler
        B       Default_Handler

        PUBWEAK BTIM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
BTIM1_IRQHandler
        B       Default_Handler

        PUBWEAK BTIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
BTIM2_IRQHandler
        B       Default_Handler

        PUBWEAK STIM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
STIM1_IRQHandler
        B       Default_Handler

        PUBWEAK STIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
STIM2_IRQHandler
        B       Default_Handler

        PUBWEAK STIM3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
STIM3_IRQHandler
        B       Default_Handler

        PUBWEAK TIM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_IRQHandler
        B       Default_Handler

        PUBWEAK TIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM2_IRQHandler
        B       Default_Handler

        PUBWEAK AWK_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
AWK_IRQHandler
        B       Default_Handler

        PUBWEAK LIN1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LIN1_IRQHandler
        B       Default_Handler

        PUBWEAK LIN2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LIN2_IRQHandler
        B       Default_Handler

        PUBWEAK I2C1_MST_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_MST_IRQHandler
        B       Default_Handler

        PUBWEAK I2C1_SLV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_SLV_IRQHandler
        B       Default_Handler

        PUBWEAK I2C2_MST_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_MST_IRQHandler
        B       Default_Handler

        PUBWEAK I2C2_SLV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_SLV_IRQHandler
        B       Default_Handler

        PUBWEAK PMBUS_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PMBUS_IRQHandler
        B       Default_Handler

        PUBWEAK SPI1_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_RX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI1_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_TX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI2_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_RX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI2_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_TX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI3_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI3_RX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI3_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI3_TX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI4_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI4_RX_IRQHandler
        B       Default_Handler

        PUBWEAK SPI4_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI4_TX_IRQHandler
        B       Default_Handler

        PUBWEAK UART1_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_TX_IRQHandler
        B       Default_Handler

        PUBWEAK UART1_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_RX_IRQHandler
        B       Default_Handler

        PUBWEAK UART2_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_TX_IRQHandler
        B       Default_Handler

        PUBWEAK UART2_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_RX_IRQHandler
        B       Default_Handler

        PUBWEAK UART3_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_TX_IRQHandler
        B       Default_Handler

        PUBWEAK UART3_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_RX_IRQHandler
        B       Default_Handler

        PUBWEAK UART4_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART4_TX_IRQHandler
        B       Default_Handler

        PUBWEAK UART4_RX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART4_RX_IRQHandler
        B       Default_Handler

        PUBWEAK AESHASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
AESHASH_IRQHandler
        B       Default_Handler

        PUBWEAK TRNG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TRNG_IRQHandler
        B       Default_Handler

        PUBWEAK QSPI_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
QSPI_IRQHandler
        B       Default_Handler

        PUBWEAK EMATH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EMATH_IRQHandler
        B       Default_Handler

        PUBWEAK DCC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DCC1_IRQHandler
        B       Default_Handler

        PUBWEAK DCC2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DCC2_IRQHandler
        B       Default_Handler

        PUBWEAK DCC3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DCC3_IRQHandler
        B       Default_Handler

        PUBWEAK MCM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MCM_IRQHandler
        B       Default_Handler

        PUBWEAK VDDRDY_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
VDDRDY_IRQHandler
        B       Default_Handler

        PUBWEAK FMU_CFG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FMU_CFG_IRQHandler
        B       Default_Handler

        PUBWEAK FMU_EVT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FMU_EVT_IRQHandler
        B       Default_Handler

        PUBWEAK CLB1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CLB1_IRQHandler
        B       Default_Handler

        PUBWEAK CLB2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CLB2_IRQHandler
        B       Default_Handler

        PUBWEAK CLB3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CLB3_IRQHandler
        B       Default_Handler

        PUBWEAK CLB4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CLB4_IRQHandler
        B       Default_Handler

        PUBWEAK CLB5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CLB5_IRQHandler
        B       Default_Handler

        PUBWEAK CLB6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CLB6_IRQHandler
        B       Default_Handler

        PUBWEAK EMIF_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EMIF_IRQHandler
        B       Default_Handler

        PUBWEAK UPP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UPP_IRQHandler
        B       Default_Handler

        PUBWEAK MU_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MU_IRQHandler
        B       Default_Handler

        PUBWEAK MMATH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MMATH_IRQHandler
        B       Default_Handler

        PUBWEAK EXTI_TXEV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI_TXEV_IRQHandler
        B       Default_Handler

        END
