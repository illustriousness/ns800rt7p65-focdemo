;********************************************************************************
;* @File Name          : startup_NS800RT7xxx.s
;* @author             : MCD Application Team
;* @Description        : NS800RT7xxx devices vector table for MDK toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the Cortex-M processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>
;******************************************************************************
;* @attention
;*
;* Copyright (c) 2025 Novosense Limited.
;* All rights reserved.
;*
;* This software is licensed under terms that can be found in the LICENSE file
;* in the root directory of this software component.
;* If no LICENSE file comes with this software, it is provided AS-IS.
;*
;*******************************************************************************

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
Stack_Size      EQU     0x00001000

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00001000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size


__Vectors       DCD     __initial_sp
                DCD     Reset_Handler                  ;< -15 Reset Handler
                DCD     NMI_Handler                    ;< -14 NMI Handler
                DCD     HardFault_Handler              ;< -13 Hard Fault Handler
                DCD     MemManage_Handler              ;< -12 MPU Fault Handler
                DCD     BusFault_Handler               ;< -11 Bus Fault Handler
                DCD     UsageFault_Handler             ;< -10 Usage Fault Handler
                DCD     0                              ;< -9 Reserved
                DCD     0                              ;< -8 Reserved
                DCD     0                              ;< -7 Reserved
                DCD     0                              ;< -6 Reserved
                DCD     SVC_Handler                    ;< -5 SVCall Handler
                DCD     DebugMon_Handler               ;< -4 Debug Monitor Handler
                DCD     0                              ;< -3 Reserved
                DCD     PendSV_Handler                 ;< -2 PendSV Handler
                DCD     SysTick_Handler                ;< -1 SysTick Handler


                ; External Interrupts
                DCD    WWDG_IRQHandler                 ;< 0   WWDG_IRQn
                DCD    IWDG1_IRQHandler                ;< 1   IWDG1_IRQn
                DCD    IWDG2_IRQHandler                ;< 2   IWDG2_IRQn
                DCD    LVD_IRQHandler                  ;< 3   LVD_IRQn
                DCD    FLASH_IRQHandler                ;< 4   FLASH_IRQn
                DCD    FLASH_ECCERR_IRQHandler         ;< 5   FLASH_ECCERR_IRQn
                DCD    RAM_ECCERR_IRQHandler           ;< 6   RAM_ECCERR_IRQn
                DCD    RCC_IRQHandler                  ;< 7   RCC_IRQn
                DCD    EXTI3_0_IRQHandler              ;< 8   EXTI3_0_IRQn
                DCD    EXTI7_4_IRQHandler              ;< 9   EXTI7_4_IRQn
                DCD    EXTI11_8_IRQHandler             ;< 10  EXTI11_8_IRQn
                DCD    EXTI15_12_IRQHandler            ;< 11  EXTI15_12_IRQn
                DCD    EXTI_CMP_IRQHandler             ;< 12  EXTI_CMP_IRQn
                DCD    EXTI_XINT2_1_IRQHandler         ;< 13  EXTI_XINT2_1_IRQn
                DCD    EXTI_XINT5_3_IRQHandler         ;< 14  EXTI_XINT5_3_IRQn
                DCD    EDMA1_CH0_IRQHandler            ;< 15  EDMA1_CH0_IRQn
                DCD    EDMA1_CH1_IRQHandler            ;< 16  EDMA1_CH1_IRQn
                DCD    EDMA1_CH2_IRQHandler            ;< 17  EDMA1_CH2_IRQn
                DCD    EDMA1_CH3_IRQHandler            ;< 18  EDMA1_CH3_IRQn
                DCD    EDMA1_CH4_IRQHandler            ;< 19  EDMA1_CH4_IRQn
                DCD    EDMA1_CH5_IRQHandler            ;< 20  EDMA1_CH5_IRQn
                DCD    EDMA1_CH6_IRQHandler            ;< 21  EDMA1_CH6_IRQn
                DCD    EDMA1_CH7_IRQHandler            ;< 22  EDMA1_CH7_IRQn
                DCD    EDMA1_CH8_IRQHandler            ;< 23  EDMA1_CH8_IRQn
                DCD    EDMA1_CH9_IRQHandler            ;< 24  EDMA1_CH9_IRQn
                DCD    EDMA1_CH10_IRQHandler           ;< 25  EDMA1_CH10_IRQn
                DCD    EDMA1_CH11_IRQHandler           ;< 26  EDMA1_CH11_IRQn
                DCD    EDMA1_CH12_IRQHandler           ;< 27  EDMA1_CH12_IRQn
                DCD    EDMA1_CH13_IRQHandler           ;< 28  EDMA1_CH13_IRQn
                DCD    EDMA1_CH14_IRQHandler           ;< 29  EDMA1_CH14_IRQn
                DCD    EDMA1_CH15_IRQHandler           ;< 30  EDMA1_CH15_IRQn
                DCD    EDMA1_CH16_IRQHandler           ;< 31  EDMA1_CH16_IRQn
                DCD    EDMA1_CH17_IRQHandler           ;< 32  EDMA1_CH17_IRQn
                DCD    EDMA1_CH18_IRQHandler           ;< 33  EDMA1_CH18_IRQn
                DCD    EDMA1_CH19_IRQHandler           ;< 34  EDMA1_CH19_IRQn
                DCD    EDMA1_CH20_IRQHandler           ;< 35  EDMA1_CH20_IRQn
                DCD    EDMA1_CH21_IRQHandler           ;< 36  EDMA1_CH21_IRQn
                DCD    EDMA1_CH22_IRQHandler           ;< 37  EDMA1_CH22_IRQn
                DCD    EDMA1_CH23_IRQHandler           ;< 38  EDMA1_CH23_IRQn
                DCD    EDMA1_CH24_IRQHandler           ;< 39  EDMA1_CH24_IRQn
                DCD    EDMA1_CH25_IRQHandler           ;< 40  EDMA1_CH25_IRQn
                DCD    EDMA1_CH26_IRQHandler           ;< 41  EDMA1_CH26_IRQn
                DCD    EDMA1_CH27_IRQHandler           ;< 42  EDMA1_CH27_IRQn
                DCD    EDMA1_CH28_IRQHandler           ;< 43  EDMA1_CH28_IRQn
                DCD    EDMA1_CH29_IRQHandler           ;< 44  EDMA1_CH29_IRQn
                DCD    EDMA1_CH30_IRQHandler           ;< 45  EDMA1_CH30_IRQn
                DCD    EDMA1_CH31_IRQHandler           ;< 46  EDMA1_CH31_IRQn
                DCD    EDMA1_ERR_IRQHandler            ;< 47  EDMA1_ERR_IRQn
                DCD    EDMA2_CH0_IRQHandler            ;< 48  EDMA2_CH0_IRQn
                DCD    EDMA2_CH1_IRQHandler            ;< 49  EDMA2_CH1_IRQn
                DCD    EDMA2_CH2_IRQHandler            ;< 50  EDMA2_CH2_IRQn
                DCD    EDMA2_CH3_IRQHandler            ;< 51  EDMA2_CH3_IRQn
                DCD    EDMA2_CH4_IRQHandler            ;< 52  EDMA2_CH4_IRQn
                DCD    EDMA2_CH5_IRQHandler            ;< 53  EDMA2_CH5_IRQn
                DCD    EDMA2_CH6_IRQHandler            ;< 54  EDMA2_CH6_IRQn
                DCD    EDMA2_CH7_IRQHandler            ;< 55  EDMA2_CH7_IRQn
                DCD    EDMA2_CH8_IRQHandler            ;< 56  EDMA2_CH8_IRQn
                DCD    EDMA2_CH9_IRQHandler            ;< 57  EDMA2_CH9_IRQn
                DCD    EDMA2_CH10_IRQHandler           ;< 58  EDMA2_CH10_IRQn
                DCD    EDMA2_CH11_IRQHandler           ;< 59  EDMA2_CH11_IRQn
                DCD    EDMA2_CH12_IRQHandler           ;< 60  EDMA2_CH12_IRQn
                DCD    EDMA2_CH13_IRQHandler           ;< 61  EDMA2_CH13_IRQn
                DCD    EDMA2_CH14_IRQHandler           ;< 62  EDMA2_CH14_IRQn
                DCD    EDMA2_CH15_IRQHandler           ;< 63  EDMA2_CH15_IRQn
                DCD    EDMA2_CH16_IRQHandler           ;< 64  EDMA2_CH16_IRQn
                DCD    EDMA2_CH17_IRQHandler           ;< 65  EDMA2_CH17_IRQn
                DCD    EDMA2_CH18_IRQHandler           ;< 66  EDMA2_CH18_IRQn
                DCD    EDMA2_CH19_IRQHandler           ;< 67  EDMA2_CH19_IRQn
                DCD    EDMA2_CH20_IRQHandler           ;< 68  EDMA2_CH20_IRQn
                DCD    EDMA2_CH21_IRQHandler           ;< 69  EDMA2_CH21_IRQn
                DCD    EDMA2_CH22_IRQHandler           ;< 70  EDMA2_CH22_IRQn
                DCD    EDMA2_CH23_IRQHandler           ;< 71  EDMA2_CH23_IRQn
                DCD    EDMA2_CH24_IRQHandler           ;< 72  EDMA2_CH24_IRQn
                DCD    EDMA2_CH25_IRQHandler           ;< 73  EDMA2_CH25_IRQn
                DCD    EDMA2_CH26_IRQHandler           ;< 74  EDMA2_CH26_IRQn
                DCD    EDMA2_CH27_IRQHandler           ;< 75  EDMA2_CH27_IRQn
                DCD    EDMA2_CH28_IRQHandler           ;< 76  EDMA2_CH28_IRQn
                DCD    EDMA2_CH29_IRQHandler           ;< 77  EDMA2_CH29_IRQn
                DCD    EDMA2_CH30_IRQHandler           ;< 78  EDMA2_CH30_IRQn
                DCD    EDMA2_CH31_IRQHandler           ;< 79  EDMA2_CH31_IRQn
                DCD    EDMA2_ERR_IRQHandler            ;< 80  EDMA2_ERR_IRQn
                DCD    ADCA_CONV_IRQHandler            ;< 81  ADCA_CONV_IRQn
                DCD    ADCA_EVENT_IRQHandler           ;< 82  ADCA_EVENT_IRQn
                DCD    ADCB_CONV_IRQHandler            ;< 83  ADCB_CONV_IRQn
                DCD    ADCB_EVENT_IRQHandler           ;< 84  ADCB_EVENT_IRQn
                DCD    ADCC_CONV_IRQHandler            ;< 85  ADCC_CONV_IRQn
                DCD    ADCC_EVENT_IRQHandler           ;< 86  ADCC_EVENT_IRQn
                DCD    0                               ;< 87  Reserved
                DCD    0                               ;< 88  Reserved
                DCD    ADC_SAFE_CHK_IRQHandler         ;< 89  ADC_SAFE_CHK_IRQn
                DCD    EPWM1_TZINT_IRQHandler          ;< 90  EPWM1_TZINT_IRQn
                DCD    EPWM2_TZINT_IRQHandler          ;< 91  EPWM2_TZINT_IRQn
                DCD    EPWM3_TZINT_IRQHandler          ;< 92  EPWM3_TZINT_IRQn
                DCD    EPWM4_TZINT_IRQHandler          ;< 93  EPWM4_TZINT_IRQn
                DCD    EPWM5_TZINT_IRQHandler          ;< 94  EPWM5_TZINT_IRQn
                DCD    EPWM6_TZINT_IRQHandler          ;< 95  EPWM6_TZINT_IRQn
                DCD    EPWM7_TZINT_IRQHandler          ;< 96  EPWM7_TZINT_IRQn
                DCD    EPWM8_TZINT_IRQHandler          ;< 97  EPWM8_TZINT_IRQn
                DCD    EPWM9_TZINT_IRQHandler          ;< 98  EPWM9_TZINT_IRQn
                DCD    EPWM10_TZINT_IRQHandler         ;< 99  EPWM10_TZINT_IRQn
                DCD    EPWM11_TZINT_IRQHandler         ;< 100 EPWM11_TZINT_IRQn
                DCD    EPWM12_TZINT_IRQHandler         ;< 101 EPWM12_TZINT_IRQn
                DCD    EPWM13_TZINT_IRQHandler         ;< 102 EPWM13_TZINT_IRQn
                DCD    EPWM14_TZINT_IRQHandler         ;< 103 EPWM14_TZINT_IRQn
                DCD    EPWM15_TZINT_IRQHandler         ;< 104 EPWM15_TZINT_IRQn
                DCD    EPWM16_TZINT_IRQHandler         ;< 105 EPWM16_TZINT_IRQn
                DCD    EPWM17_TZINT_IRQHandler         ;< 106 EPWM17_TZINT_IRQn
                DCD    EPWM18_TZINT_IRQHandler         ;< 107 EPWM18_TZINT_IRQn
                DCD    EPWM1_INT_IRQHandler            ;< 108 EPWM1_INT_IRQn
                DCD    EPWM2_INT_IRQHandler            ;< 109 EPWM2_INT_IRQn
                DCD    EPWM3_INT_IRQHandler            ;< 110 EPWM3_INT_IRQn
                DCD    EPWM4_INT_IRQHandler            ;< 111 EPWM4_INT_IRQn
                DCD    EPWM5_INT_IRQHandler            ;< 112 EPWM5_INT_IRQn
                DCD    EPWM6_INT_IRQHandler            ;< 113 EPWM6_INT_IRQn
                DCD    EPWM7_INT_IRQHandler            ;< 114 EPWM7_INT_IRQn
                DCD    EPWM8_INT_IRQHandler            ;< 115 EPWM8_INT_IRQn
                DCD    EPWM9_INT_IRQHandler            ;< 116 EPWM9_INT_IRQn
                DCD    EPWM10_INT_IRQHandler           ;< 117 EPWM10_INT_IRQn
                DCD    EPWM11_INT_IRQHandler           ;< 118 EPWM11_INT_IRQn
                DCD    EPWM12_INT_IRQHandler           ;< 119 EPWM12_INT_IRQn
                DCD    EPWM13_INT_IRQHandler           ;< 120 EPWM13_INT_IRQn
                DCD    EPWM14_INT_IRQHandler           ;< 121 EPWM14_INT_IRQn
                DCD    EPWM15_INT_IRQHandler           ;< 122 EPWM15_INT_IRQn
                DCD    EPWM16_INT_IRQHandler           ;< 123 EPWM16_INT_IRQn
                DCD    EPWM17_INT_IRQHandler           ;< 124 EPWM17_INT_IRQn
                DCD    EPWM18_INT_IRQHandler           ;< 125 EPWM18_INT_IRQn
                DCD    ECAP1_IRQHandler                ;< 126 ECAP1_IRQn
                DCD    ECAP2_IRQHandler                ;< 127 ECAP2_IRQn
                DCD    ECAP3_IRQHandler                ;< 128 ECAP3_IRQn
                DCD    ECAP4_IRQHandler                ;< 129 ECAP4_IRQn
                DCD    ECAP5_IRQHandler                ;< 130 ECAP5_IRQn
                DCD    ECAP6_IRQHandler                ;< 131 ECAP6_IRQn
                DCD    ECAP7_IRQHandler                ;< 132 ECAP7_IRQn
                DCD    EQEP1_IRQHandler                ;< 133 EQEP1_IRQn
                DCD    EQEP2_IRQHandler                ;< 134 EQEP2_IRQn
                DCD    EQEP3_IRQHandler                ;< 135 EQEP3_IRQn
                DCD    EQEP4_IRQHandler                ;< 136 EQEP4_IRQn
                DCD    EQEP5_IRQHandler                ;< 137 EQEP5_IRQn
                DCD    EQEP6_IRQHandler                ;< 138 EQEP6_IRQn
                DCD    EPG_IRQHandler                  ;< 139 EPG_IRQn
                DCD    SDFM1_DR_1_IRQHandler           ;< 140 SDFM1_DR_1_IRQn
                DCD    SDFM1_DR_2_IRQHandler           ;< 141 SDFM1_DR_2_IRQn
                DCD    SDFM1_DR_3_IRQHandler           ;< 142 SDFM1_DR_3_IRQn
                DCD    SDFM1_DR_4_IRQHandler           ;< 143 SDFM1_DR_4_IRQn
                DCD    SDFM1_ERR_IRQHandler            ;< 144 SDFM1_ERR_IRQn
                DCD    SDFM2_DR_1_IRQHandler           ;< 145 SDFM2_DR_1_IRQn
                DCD    SDFM2_DR_2_IRQHandler           ;< 146 SDFM2_DR_2_IRQn
                DCD    SDFM2_DR_3_IRQHandler           ;< 147 SDFM2_DR_3_IRQn
                DCD    SDFM2_DR_4_IRQHandler           ;< 148 SDFM2_DR_4_IRQn
                DCD    SDFM2_ERR_IRQHandler            ;< 149 SDFM2_ERR_IRQn
                DCD    SDFM3_DR_1_IRQHandler           ;< 150 SDFM3_DR_1_IRQn
                DCD    SDFM3_DR_2_IRQHandler           ;< 151 SDFM3_DR_2_IRQn
                DCD    SDFM3_DR_3_IRQHandler           ;< 152 SDFM3_DR_3_IRQn
                DCD    SDFM3_DR_4_IRQHandler           ;< 153 SDFM3_DR_4_IRQn
                DCD    SDFM3_ERR_IRQHandler            ;< 154 SDFM3_ERR_IRQn
                DCD    SDFM4_DR_1_IRQHandler           ;< 155 SDFM4_DR_1_IRQn
                DCD    SDFM4_DR_2_IRQHandler           ;< 156 SDFM4_DR_2_IRQn
                DCD    SDFM4_DR_3_IRQHandler           ;< 157 SDFM4_DR_3_IRQn
                DCD    SDFM4_DR_4_IRQHandler           ;< 158 SDFM4_DR_4_IRQn
                DCD    SDFM4_ERR_IRQHandler            ;< 159 SDFM4_ERR_IRQn
                DCD    LPTIM_IRQHandler                ;< 160 LPTIM_IRQn
                DCD    CAN1_1_IRQHandler               ;< 161 CAN1_1_IRQn
                DCD    CAN1_2_IRQHandler               ;< 162 CAN1_2_IRQn
                DCD    CAN1_ECC_IRQHandler             ;< 163 CAN1_ECC_IRQn
                DCD    CAN1_WKUP_IRQHandler            ;< 164 CAN1_WKUP_IRQn
                DCD    CANFD1_1_IRQHandler             ;< 165 CANFD1_1_IRQn
                DCD    CANFD1_2_IRQHandler             ;< 166 CANFD1_2_IRQn
                DCD    CANFD1_ECC_IRQHandler           ;< 167 CANFD1_ECC_IRQn
                DCD    CANFD1_WKUP_TS_IRQHandler       ;< 168 CANFD1_WKUP_TS_IRQn
                DCD    CANFD2_1_IRQHandler             ;< 169 CANFD2_1_IRQn
                DCD    CANFD2_2_IRQHandler             ;< 170 CANFD2_2_IRQn
                DCD    CANFD2_ECC_IRQHandler           ;< 171 CANFD2_ECC_IRQn
                DCD    CANFD2_WKUP_TS_IRQHandler       ;< 172 CANFD2_WKUP_TS_IRQn
                DCD    BTIM1_IRQHandler                ;< 173 BTIM1_IRQn
                DCD    BTIM2_IRQHandler                ;< 174 BTIM2_IRQn
                DCD    STIM1_IRQHandler                ;< 175 STIM1_IRQn
                DCD    STIM2_IRQHandler                ;< 176 STIM2_IRQn
                DCD    STIM3_IRQHandler                ;< 177 STIM3_IRQn
                DCD    TIM1_IRQHandler                 ;< 178 TIM1_IRQn
                DCD    TIM2_IRQHandler                 ;< 179 TIM2_IRQn
                DCD    AWK_IRQHandler                  ;< 180 AWK_IRQn
                DCD    LIN1_IRQHandler                 ;< 181 LIN1_IRQn
                DCD    LIN2_IRQHandler                 ;< 182 LIN2_IRQn
                DCD    I2C1_MST_IRQHandler             ;< 183 I2C1_MST_IRQn
                DCD    I2C1_SLV_IRQHandler             ;< 184 I2C1_SLV_IRQn
                DCD    I2C2_MST_IRQHandler             ;< 185 I2C2_MST_IRQn
                DCD    I2C2_SLV_IRQHandler             ;< 186 I2C2_SLV_IRQn
                DCD    0                               ;< 187 Reserved
                DCD    PMBUS_IRQHandler                ;< 188 PMBUS_IRQn
                DCD    SPI1_RX_IRQHandler              ;< 189 SPI1_RX_IRQn
                DCD    SPI1_TX_IRQHandler              ;< 190 SPI1_TX_IRQn
                DCD    SPI2_RX_IRQHandler              ;< 191 SPI2_RX_IRQn
                DCD    SPI2_TX_IRQHandler              ;< 192 SPI2_TX_IRQn
                DCD    SPI3_RX_IRQHandler              ;< 193 SPI3_RX_IRQn
                DCD    SPI3_TX_IRQHandler              ;< 194 SPI3_TX_IRQn
                DCD    SPI4_RX_IRQHandler              ;< 195 SPI4_RX_IRQn
                DCD    SPI4_TX_IRQHandler              ;< 196 SPI4_TX_IRQn
                DCD    UART1_TX_IRQHandler             ;< 197 UART1_TX_IRQn
                DCD    UART1_RX_IRQHandler             ;< 198 UART1_RX_IRQn
                DCD    UART2_TX_IRQHandler             ;< 199 UART2_TX_IRQn
                DCD    UART2_RX_IRQHandler             ;< 200 UART2_RX_IRQn
                DCD    UART3_TX_IRQHandler             ;< 201 UART3_TX_IRQn
                DCD    UART3_RX_IRQHandler             ;< 202 UART3_RX_IRQn
                DCD    UART4_TX_IRQHandler             ;< 203 UART4_TX_IRQn
                DCD    UART4_RX_IRQHandler             ;< 204 UART4_RX_IRQn
                DCD    AESHASH_IRQHandler              ;< 205 AES_HASH_IRQn
                DCD    TRNG_IRQHandler                 ;< 206 TRNG_IRQn
                DCD    QSPI_IRQHandler                 ;< 207 QSPI_IRQn
                DCD    EMATH_IRQHandler                ;< 208 EMATH_IRQn
                DCD    DCC1_IRQHandler                 ;< 209 DCC1_IRQn
                DCD    DCC2_IRQHandler                 ;< 210 DCC2_IRQn
                DCD    DCC3_IRQHandler                 ;< 211 DCC3_IRQn
                DCD    MCM_IRQHandler                  ;< 212 MCM_IRQn
                DCD    VDDRDY_IRQHandler               ;< 213 VDDRDY_IRQn
                DCD    FMU_CFG_IRQHandler              ;< 214 FMU_CFG_IRQn
                DCD    FMU_EVT_IRQHandler              ;< 215 FMU_EVT_IRQn
                DCD    CLB1_IRQHandler                 ;< 216 CLB1_CFG_IRQn
                DCD    CLB2_IRQHandler                 ;< 217 CLB2_CFG_IRQn
                DCD    CLB3_IRQHandler                 ;< 218 CLB3_CFG_IRQn
                DCD    CLB4_IRQHandler                 ;< 219 CLB4_CFG_IRQn
                DCD    CLB5_IRQHandler                 ;< 220 CLB5_CFG_IRQn
                DCD    CLB6_IRQHandler                 ;< 221 CLB6_CFG_IRQn
                DCD    EMIF_IRQHandler                 ;< 222 EMIF_IRQn
                DCD    UPP_IRQHandler                  ;< 223 UPP_IRQn
                DCD    MU_IRQHandler                   ;< 224 MU_IRQn
                DCD    MMATH_IRQHandler                ;< 225 MMATH_IRQn
                DCD    EXTI_TXEV_IRQHandler            ;< 226 EXTI_TXEV_IRQn

__Vectors_End

__Vectors_Size      EQU     __Vectors_End - __Vectors

                    AREA    |.text|, CODE, READONLY

;Reset Handler routine

; Reset Handler routine

Reset_Handler       PROC
                    EXPORT  Reset_Handler                    [WEAK]
                    IMPORT  __main
                    IMPORT  SystemInit

                    LDR     R0, =SystemInit
                    BLX     R0
                    LDR     R0, =__main
                    BX      R0
                    ENDP

NMI_Handler         PROC
                    EXPORT  NMI_Handler                      [WEAK]
                    B       .
                    ENDP

HardFault_Handler   PROC
                    EXPORT  HardFault_Handler                [WEAK]
                    B       .
                    ENDP

MemManage_Handler   PROC
                    EXPORT  MemManage_Handler                [WEAK]
                    B       .
                    ENDP

BusFault_Handler    PROC
                    EXPORT  BusFault_Handler                 [WEAK]
                    B       .
                    ENDP

UsageFault_Handler  PROC
                    EXPORT  UsageFault_Handler               [WEAK]
                    B       .
                    ENDP

DebugMon_Handler    PROC
                    EXPORT  DebugMon_Handler                 [WEAK]
                    B       .
                    ENDP

SVC_Handler         PROC
                    EXPORT  SVC_Handler                      [WEAK]
                    B       .
                    ENDP

PendSV_Handler      PROC
                    EXPORT  PendSV_Handler                   [WEAK]
                    B       .
                    ENDP

SysTick_Handler     PROC
                    EXPORT  SysTick_Handler                  [WEAK]
                    B       .
                    ENDP

Default_Handler     PROC
                    EXPORT    WWDG_IRQHandler                [weak]    ; WWDG_IRQn
                    EXPORT    IWDG1_IRQHandler               [weak]    ; IWDG1_IRQn
                    EXPORT    IWDG2_IRQHandler               [weak]    ; IWDG2_IRQn
                    EXPORT    LVD_IRQHandler                 [weak]    ; LVD_IRQn
                    EXPORT    FLASH_IRQHandler               [weak]    ; FLASH_IRQn
                    EXPORT    FLASH_ECCERR_IRQHandler        [weak]    ; FLASH_ECCERR_IRQn
                    EXPORT    RAM_ECCERR_IRQHandler          [weak]    ; RAM_ECCERR_IRQn
                    EXPORT    RCC_IRQHandler                 [weak]    ; RCC_IRQn
                    EXPORT    EXTI3_0_IRQHandler             [weak]    ; EXTI3_0_IRQn
                    EXPORT    EXTI7_4_IRQHandler             [weak]    ; EXTI7_4_IRQn
                    EXPORT    EXTI11_8_IRQHandler            [weak]    ; EXTI11_8_IRQn
                    EXPORT    EXTI15_12_IRQHandler           [weak]    ; EXTI15_12_IRQn
                    EXPORT    EXTI_CMP_IRQHandler            [weak]    ; EXTI_CMP_IRQn
                    EXPORT    EXTI_XINT2_1_IRQHandler        [weak]    ; EXTI_XINT2_1_IRQn
                    EXPORT    EXTI_XINT5_3_IRQHandler        [weak]    ; EXTI_XINT5_3_IRQn
                    EXPORT    EDMA1_CH0_IRQHandler           [weak]    ; EDMA1_CH0_IRQn
                    EXPORT    EDMA1_CH1_IRQHandler           [weak]    ; EDMA1_CH1_IRQn
                    EXPORT    EDMA1_CH2_IRQHandler           [weak]    ; EDMA1_CH2_IRQn
                    EXPORT    EDMA1_CH3_IRQHandler           [weak]    ; EDMA1_CH3_IRQn
                    EXPORT    EDMA1_CH4_IRQHandler           [weak]    ; EDMA1_CH4_IRQn
                    EXPORT    EDMA1_CH5_IRQHandler           [weak]    ; EDMA1_CH5_IRQn
                    EXPORT    EDMA1_CH6_IRQHandler           [weak]    ; EDMA1_CH6_IRQn
                    EXPORT    EDMA1_CH7_IRQHandler           [weak]    ; EDMA1_CH7_IRQn
                    EXPORT    EDMA1_CH8_IRQHandler           [weak]    ; EDMA1_CH8_IRQn
                    EXPORT    EDMA1_CH9_IRQHandler           [weak]    ; EDMA1_CH9_IRQn
                    EXPORT    EDMA1_CH10_IRQHandler          [weak]    ; EDMA1_CH10_IRQn
                    EXPORT    EDMA1_CH11_IRQHandler          [weak]    ; EDMA1_CH11_IRQn
                    EXPORT    EDMA1_CH12_IRQHandler          [weak]    ; EDMA1_CH12_IRQn
                    EXPORT    EDMA1_CH13_IRQHandler          [weak]    ; EDMA1_CH13_IRQn
                    EXPORT    EDMA1_CH14_IRQHandler          [weak]    ; EDMA1_CH14_IRQn
                    EXPORT    EDMA1_CH15_IRQHandler          [weak]    ; EDMA1_CH15_IRQn
                    EXPORT    EDMA1_CH16_IRQHandler          [weak]    ; EDMA1_CH16_IRQn
                    EXPORT    EDMA1_CH17_IRQHandler          [weak]    ; EDMA1_CH17_IRQn
                    EXPORT    EDMA1_CH18_IRQHandler          [weak]    ; EDMA1_CH18_IRQn
                    EXPORT    EDMA1_CH19_IRQHandler          [weak]    ; EDMA1_CH19_IRQn
                    EXPORT    EDMA1_CH20_IRQHandler          [weak]    ; EDMA1_CH20_IRQn
                    EXPORT    EDMA1_CH21_IRQHandler          [weak]    ; EDMA1_CH21_IRQn
                    EXPORT    EDMA1_CH22_IRQHandler          [weak]    ; EDMA1_CH22_IRQn
                    EXPORT    EDMA1_CH23_IRQHandler          [weak]    ; EDMA1_CH23_IRQn
                    EXPORT    EDMA1_CH24_IRQHandler          [weak]    ; EDMA1_CH24_IRQn
                    EXPORT    EDMA1_CH25_IRQHandler          [weak]    ; EDMA1_CH25_IRQn
                    EXPORT    EDMA1_CH26_IRQHandler          [weak]    ; EDMA1_CH26_IRQn
                    EXPORT    EDMA1_CH27_IRQHandler          [weak]    ; EDMA1_CH27_IRQn
                    EXPORT    EDMA1_CH28_IRQHandler          [weak]    ; EDMA1_CH28_IRQn
                    EXPORT    EDMA1_CH29_IRQHandler          [weak]    ; EDMA1_CH29_IRQn
                    EXPORT    EDMA1_CH30_IRQHandler          [weak]    ; EDMA1_CH30_IRQn
                    EXPORT    EDMA1_CH31_IRQHandler          [weak]    ; EDMA1_CH31_IRQn
                    EXPORT    EDMA1_ERR_IRQHandler           [weak]    ; EDMA1_ERR_IRQn
                    EXPORT    EDMA2_CH0_IRQHandler           [weak]    ; EDMA2_CH0_IRQn
                    EXPORT    EDMA2_CH1_IRQHandler           [weak]    ; EDMA2_CH1_IRQn
                    EXPORT    EDMA2_CH2_IRQHandler           [weak]    ; EDMA2_CH2_IRQn
                    EXPORT    EDMA2_CH3_IRQHandler           [weak]    ; EDMA2_CH3_IRQn
                    EXPORT    EDMA2_CH4_IRQHandler           [weak]    ; EDMA2_CH4_IRQn
                    EXPORT    EDMA2_CH5_IRQHandler           [weak]    ; EDMA2_CH5_IRQn
                    EXPORT    EDMA2_CH6_IRQHandler           [weak]    ; EDMA2_CH6_IRQn
                    EXPORT    EDMA2_CH7_IRQHandler           [weak]    ; EDMA2_CH7_IRQn
                    EXPORT    EDMA2_CH8_IRQHandler           [weak]    ; EDMA2_CH8_IRQn
                    EXPORT    EDMA2_CH9_IRQHandler           [weak]    ; EDMA2_CH9_IRQn
                    EXPORT    EDMA2_CH10_IRQHandler          [weak]    ; EDMA2_CH10_IRQn
                    EXPORT    EDMA2_CH11_IRQHandler          [weak]    ; EDMA2_CH11_IRQn
                    EXPORT    EDMA2_CH12_IRQHandler          [weak]    ; EDMA2_CH12_IRQn
                    EXPORT    EDMA2_CH13_IRQHandler          [weak]    ; EDMA2_CH13_IRQn
                    EXPORT    EDMA2_CH14_IRQHandler          [weak]    ; EDMA2_CH14_IRQn
                    EXPORT    EDMA2_CH15_IRQHandler          [weak]    ; EDMA2_CH15_IRQn
                    EXPORT    EDMA2_CH16_IRQHandler          [weak]    ; EDMA2_CH16_IRQn
                    EXPORT    EDMA2_CH17_IRQHandler          [weak]    ; EDMA2_CH17_IRQn
                    EXPORT    EDMA2_CH18_IRQHandler          [weak]    ; EDMA2_CH18_IRQn
                    EXPORT    EDMA2_CH19_IRQHandler          [weak]    ; EDMA2_CH19_IRQn
                    EXPORT    EDMA2_CH20_IRQHandler          [weak]    ; EDMA2_CH20_IRQn
                    EXPORT    EDMA2_CH21_IRQHandler          [weak]    ; EDMA2_CH21_IRQn
                    EXPORT    EDMA2_CH22_IRQHandler          [weak]    ; EDMA2_CH22_IRQn
                    EXPORT    EDMA2_CH23_IRQHandler          [weak]    ; EDMA2_CH23_IRQn
                    EXPORT    EDMA2_CH24_IRQHandler          [weak]    ; EDMA2_CH24_IRQn
                    EXPORT    EDMA2_CH25_IRQHandler          [weak]    ; EDMA2_CH25_IRQn
                    EXPORT    EDMA2_CH26_IRQHandler          [weak]    ; EDMA2_CH26_IRQn
                    EXPORT    EDMA2_CH27_IRQHandler          [weak]    ; EDMA2_CH27_IRQn
                    EXPORT    EDMA2_CH28_IRQHandler          [weak]    ; EDMA2_CH28_IRQn
                    EXPORT    EDMA2_CH29_IRQHandler          [weak]    ; EDMA2_CH29_IRQn
                    EXPORT    EDMA2_CH30_IRQHandler          [weak]    ; EDMA2_CH30_IRQn
                    EXPORT    EDMA2_CH31_IRQHandler          [weak]    ; EDMA2_CH31_IRQn
                    EXPORT    EDMA2_ERR_IRQHandler           [weak]    ; EDMA2_ERR_IRQn
                    EXPORT    ADCA_CONV_IRQHandler           [weak]    ; ADCA_CONV_IRQn
                    EXPORT    ADCA_EVENT_IRQHandler          [weak]    ; ADCA_EVENT_IRQn
                    EXPORT    ADCB_CONV_IRQHandler           [weak]    ; ADCB_CONV_IRQn
                    EXPORT    ADCB_EVENT_IRQHandler          [weak]    ; ADCB_EVENT_IRQn
                    EXPORT    ADCC_CONV_IRQHandler           [weak]    ; ADCC_CONV_IRQn
                    EXPORT    ADCC_EVENT_IRQHandler          [weak]    ; ADCC_EVENT_IRQn
                    EXPORT    ADC_SAFE_CHK_IRQHandler        [weak]    ; ADC_SAFE_CHK_IRQn
                    EXPORT    EPWM1_TZINT_IRQHandler         [weak]    ; EPWM1_TZINT_IRQn
                    EXPORT    EPWM2_TZINT_IRQHandler         [weak]    ; EPWM2_TZINT_IRQn
                    EXPORT    EPWM3_TZINT_IRQHandler         [weak]    ; EPWM3_TZINT_IRQn
                    EXPORT    EPWM4_TZINT_IRQHandler         [weak]    ; EPWM4_TZINT_IRQn
                    EXPORT    EPWM5_TZINT_IRQHandler         [weak]    ; EPWM5_TZINT_IRQn
                    EXPORT    EPWM6_TZINT_IRQHandler         [weak]    ; EPWM6_TZINT_IRQn
                    EXPORT    EPWM7_TZINT_IRQHandler         [weak]    ; EPWM7_TZINT_IRQn
                    EXPORT    EPWM8_TZINT_IRQHandler         [weak]    ; EPWM8_TZINT_IRQn
                    EXPORT    EPWM9_TZINT_IRQHandler         [weak]    ; EPWM9_TZINT_IRQn
                    EXPORT    EPWM10_TZINT_IRQHandler        [weak]    ; EPWM10_TZINT_IRQn
                    EXPORT    EPWM11_TZINT_IRQHandler        [weak]    ; EPWM11_TZINT_IRQn
                    EXPORT    EPWM12_TZINT_IRQHandler        [weak]    ; EPWM12_TZINT_IRQn
                    EXPORT    EPWM13_TZINT_IRQHandler        [weak]    ; EPWM13_TZINT_IRQn
                    EXPORT    EPWM14_TZINT_IRQHandler        [weak]    ; EPWM14_TZINT_IRQn
                    EXPORT    EPWM15_TZINT_IRQHandler        [weak]    ; EPWM15_TZINT_IRQn
                    EXPORT    EPWM16_TZINT_IRQHandler        [weak]    ; EPWM16_TZINT_IRQn
                    EXPORT    EPWM17_TZINT_IRQHandler        [weak]    ; EPWM17_TZINT_IRQn
                    EXPORT    EPWM18_TZINT_IRQHandler        [weak]    ; EPWM18_TZINT_IRQn
                    EXPORT    EPWM1_INT_IRQHandler           [weak]    ; EPWM1_INT_IRQn
                    EXPORT    EPWM2_INT_IRQHandler           [weak]    ; EPWM2_INT_IRQn
                    EXPORT    EPWM3_INT_IRQHandler           [weak]    ; EPWM3_INT_IRQn
                    EXPORT    EPWM4_INT_IRQHandler           [weak]    ; EPWM4_INT_IRQn
                    EXPORT    EPWM5_INT_IRQHandler           [weak]    ; EPWM5_INT_IRQn
                    EXPORT    EPWM6_INT_IRQHandler           [weak]    ; EPWM6_INT_IRQn
                    EXPORT    EPWM7_INT_IRQHandler           [weak]    ; EPWM7_INT_IRQn
                    EXPORT    EPWM8_INT_IRQHandler           [weak]    ; EPWM8_INT_IRQn
                    EXPORT    EPWM9_INT_IRQHandler           [weak]    ; EPWM9_INT_IRQn
                    EXPORT    EPWM10_INT_IRQHandler          [weak]    ; EPWM10_INT_IRQn
                    EXPORT    EPWM11_INT_IRQHandler          [weak]    ; EPWM11_INT_IRQn
                    EXPORT    EPWM12_INT_IRQHandler          [weak]    ; EPWM12_INT_IRQn
                    EXPORT    EPWM13_INT_IRQHandler          [weak]    ; EPWM13_INT_IRQn
                    EXPORT    EPWM14_INT_IRQHandler          [weak]    ; EPWM14_INT_IRQn
                    EXPORT    EPWM15_INT_IRQHandler          [weak]    ; EPWM15_INT_IRQn
                    EXPORT    EPWM16_INT_IRQHandler          [weak]    ; EPWM16_INT_IRQn
                    EXPORT    EPWM17_INT_IRQHandler          [weak]    ; EPWM17_INT_IRQn
                    EXPORT    EPWM18_INT_IRQHandler          [weak]    ; EPWM18_INT_IRQn
                    EXPORT    ECAP1_IRQHandler               [weak]    ; ECAP1_IRQn
                    EXPORT    ECAP2_IRQHandler               [weak]    ; ECAP2_IRQn
                    EXPORT    ECAP3_IRQHandler               [weak]    ; ECAP3_IRQn
                    EXPORT    ECAP4_IRQHandler               [weak]    ; ECAP4_IRQn
                    EXPORT    ECAP5_IRQHandler               [weak]    ; ECAP5_IRQn
                    EXPORT    ECAP6_IRQHandler               [weak]    ; ECAP6_IRQn
                    EXPORT    ECAP7_IRQHandler               [weak]    ; ECAP7_IRQn
                    EXPORT    EQEP1_IRQHandler               [weak]    ; EQEP1_IRQn
                    EXPORT    EQEP2_IRQHandler               [weak]    ; EQEP2_IRQn
                    EXPORT    EQEP3_IRQHandler               [weak]    ; EQEP3_IRQn
                    EXPORT    EQEP4_IRQHandler               [weak]    ; EQEP4_IRQn
                    EXPORT    EQEP5_IRQHandler               [weak]    ; EQEP5_IRQn
                    EXPORT    EQEP6_IRQHandler               [weak]    ; EQEP6_IRQn
                    EXPORT    EPG_IRQHandler                 [weak]    ; EPG_IRQn
                    EXPORT    SDFM1_DR_1_IRQHandler          [weak]    ; SDFM1_DR_1_IRQn
                    EXPORT    SDFM1_DR_2_IRQHandler          [weak]    ; SDFM1_DR_2_IRQn
                    EXPORT    SDFM1_DR_3_IRQHandler          [weak]    ; SDFM1_DR_3_IRQn
                    EXPORT    SDFM1_DR_4_IRQHandler          [weak]    ; SDFM1_DR_4_IRQn
                    EXPORT    SDFM1_ERR_IRQHandler           [weak]    ; SDFM1_ERR_IRQn
                    EXPORT    SDFM2_DR_1_IRQHandler          [weak]    ; SDFM2_DR_1_IRQn
                    EXPORT    SDFM2_DR_2_IRQHandler          [weak]    ; SDFM2_DR_2_IRQn
                    EXPORT    SDFM2_DR_3_IRQHandler          [weak]    ; SDFM2_DR_3_IRQn
                    EXPORT    SDFM2_DR_4_IRQHandler          [weak]    ; SDFM2_DR_4_IRQn
                    EXPORT    SDFM2_ERR_IRQHandler           [weak]    ; SDFM2_ERR_IRQn
                    EXPORT    SDFM3_DR_1_IRQHandler          [weak]    ; SDFM3_DR_1_IRQn
                    EXPORT    SDFM3_DR_2_IRQHandler          [weak]    ; SDFM3_DR_2_IRQn
                    EXPORT    SDFM3_DR_3_IRQHandler          [weak]    ; SDFM3_DR_3_IRQn
                    EXPORT    SDFM3_DR_4_IRQHandler          [weak]    ; SDFM3_DR_4_IRQn
                    EXPORT    SDFM3_ERR_IRQHandler           [weak]    ; SDFM3_ERR_IRQn
                    EXPORT    SDFM4_DR_1_IRQHandler          [weak]    ; SDFM4_DR_1_IRQn
                    EXPORT    SDFM4_DR_2_IRQHandler          [weak]    ; SDFM4_DR_2_IRQn
                    EXPORT    SDFM4_DR_3_IRQHandler          [weak]    ; SDFM4_DR_3_IRQn
                    EXPORT    SDFM4_DR_4_IRQHandler          [weak]    ; SDFM4_DR_4_IRQn
                    EXPORT    SDFM4_ERR_IRQHandler           [weak]    ; SDFM4_ERR_IRQn
                    EXPORT    LPTIM_IRQHandler               [weak]    ; LPTIM_IRQn
                    EXPORT    CAN1_1_IRQHandler              [weak]    ; CAN1_1_IRQn
                    EXPORT    CAN1_2_IRQHandler              [weak]    ; CAN1_2_IRQ
                    EXPORT    CAN1_ECC_IRQHandler            [weak]    ; CAN1_ECC_IRQn
                    EXPORT    CAN1_WKUP_IRQHandler           [weak]    ; CAN1_WKUP_IRQn
                    EXPORT    CANFD1_1_IRQHandler            [weak]    ; CANFD1_1_IRQn
                    EXPORT    CANFD1_2_IRQHandler            [weak]    ; CANFD1_2_IRQn
                    EXPORT    CANFD1_ECC_IRQHandler          [weak]    ; CANFD1_ECC_IRQn
                    EXPORT    CANFD1_WKUP_TS_IRQHandler      [weak]    ; CANFD1_WKUP_TS_IRQn
                    EXPORT    CANFD2_1_IRQHandler            [weak]    ; CANFD2_1_IRQn
                    EXPORT    CANFD2_2_IRQHandler            [weak]    ; CANFD2_2_IRQn
                    EXPORT    CANFD2_ECC_IRQHandler          [weak]    ; CANFD2_ECC_IRQn
                    EXPORT    CANFD2_WKUP_TS_IRQHandler      [weak]    ; CANFD2_WKUP_TS_IRQn
                    EXPORT    BTIM1_IRQHandler               [weak]    ; BTIM1_IRQn
                    EXPORT    BTIM2_IRQHandler               [weak]    ; BTIM2_IRQn
                    EXPORT    STIM1_IRQHandler               [weak]    ; STIM1_IRQn
                    EXPORT    STIM2_IRQHandler               [weak]    ; STIM2_IRQn
                    EXPORT    STIM3_IRQHandler               [weak]    ; STIM3_IRQn
                    EXPORT    TIM1_IRQHandler                [weak]    ; TIM1_IRQn
                    EXPORT    TIM2_IRQHandler                [weak]    ; TIM2_IRQn
                    EXPORT    AWK_IRQHandler                 [weak]    ; AWK_IRQn
                    EXPORT    LIN1_IRQHandler                [weak]    ; LIN1_IRQn
                    EXPORT    LIN2_IRQHandler                [weak]    ; LIN2_IRQn
                    EXPORT    I2C1_MST_IRQHandler            [weak]    ; I2C1_MST_IRQn
                    EXPORT    I2C1_SLV_IRQHandler            [weak]    ; I2C1_SLV_IRQn
                    EXPORT    I2C2_MST_IRQHandler            [weak]    ; I2C2_MST_IRQn
                    EXPORT    I2C2_SLV_IRQHandler            [weak]    ; I2C2_SLV_IRQn
                    EXPORT    PMBUS_IRQHandler               [weak]    ; PMBUS_IRQn
                    EXPORT    SPI1_RX_IRQHandler             [weak]    ; SPI1_RX_IRQn
                    EXPORT    SPI1_TX_IRQHandler             [weak]    ; SPI1_TX_IRQn
                    EXPORT    SPI2_RX_IRQHandler             [weak]    ; SPI2_RX_IRQn
                    EXPORT    SPI2_TX_IRQHandler             [weak]    ; SPI2_TX_IRQn
                    EXPORT    SPI3_RX_IRQHandler             [weak]    ; SPI3_RX_IRQn
                    EXPORT    SPI3_TX_IRQHandler             [weak]    ; SPI3_TX_IRQn
                    EXPORT    SPI4_RX_IRQHandler             [weak]    ; SPI4_RX_IRQn
                    EXPORT    SPI4_TX_IRQHandler             [weak]    ; SPI4_TX_IRQn
                    EXPORT    UART1_TX_IRQHandler            [weak]    ; UART1_TX_IRQn
                    EXPORT    UART1_RX_IRQHandler            [weak]    ; UART1_RX_IRQn
                    EXPORT    UART2_TX_IRQHandler            [weak]    ; UART2_TX_IRQn
                    EXPORT    UART2_RX_IRQHandler            [weak]    ; UART2_RX_IRQn
                    EXPORT    UART3_TX_IRQHandler            [weak]    ; UART3_TX_IRQn
                    EXPORT    UART3_RX_IRQHandler            [weak]    ; UART3_RX_IRQn
                    EXPORT    UART4_TX_IRQHandler            [weak]    ; UART4_TX_IRQn
                    EXPORT    UART4_RX_IRQHandler            [weak]    ; UART4_RX_IRQn
                    EXPORT    AESHASH_IRQHandler             [weak]    ; AESHASH_IRQn
                    EXPORT    TRNG_IRQHandler                [weak]    ; TRNG_IRQn
                    EXPORT    QSPI_IRQHandler                [weak]    ; QSPI_IRQn
                    EXPORT    EMATH_IRQHandler               [weak]    ; EMATH_IRQn
                    EXPORT    DCC1_IRQHandler                [weak]    ; DCC1_IRQn
                    EXPORT    DCC2_IRQHandler                [weak]    ; DCC2_IRQn
                    EXPORT    DCC3_IRQHandler                [weak]    ; DCC3_IRQn
                    EXPORT    MCM_IRQHandler                 [weak]    ; MCM_IRQn
                    EXPORT    VDDRDY_IRQHandler              [weak]    ; VDDRDY_IRQn
                    EXPORT    FMU_CFG_IRQHandler             [weak]    ; FMU_CFG_IRQn
                    EXPORT    FMU_EVT_IRQHandler             [weak]    ; FMU_EVT_IRQn
                    EXPORT    CLB1_IRQHandler                [weak]    ; CLB1_CFG_IRQn
                    EXPORT    CLB2_IRQHandler                [weak]    ; CLB2_CFG_IRQn
                    EXPORT    CLB3_IRQHandler                [weak]    ; CLB3_CFG_IRQn
                    EXPORT    CLB4_IRQHandler                [weak]    ; CLB4_CFG_IRQn
                    EXPORT    CLB5_IRQHandler                [weak]    ; CLB5_CFG_IRQn
                    EXPORT    CLB6_IRQHandler                [weak]    ; CLB6_CFG_IRQn
                    EXPORT    EMIF_IRQHandler                [weak]    ; CLB6_CFG_IRQn
                    EXPORT    UPP_IRQHandler                 [weak]    ; CLB6_CFG_IRQn
                    EXPORT    MU_IRQHandler                  [weak]    ; MU_IRQn
                    EXPORT    MMATH_IRQHandler               [weak]    ; MMATH_IRQn
                    EXPORT    EXTI_TXEV_IRQHandler           [weak]    ; EXTI_TXEV_IRQn


WWDG_IRQHandler                ; WWDG_IRQn
IWDG1_IRQHandler               ; IWDG1_IRQn
IWDG2_IRQHandler               ; IWDG2_IRQn
LVD_IRQHandler                 ; LVD_IRQn
FLASH_IRQHandler               ; FLASH_IRQn
FLASH_ECCERR_IRQHandler        ; FLASH_ECCERR_IRQn
RAM_ECCERR_IRQHandler          ; RAM_ECCERR_IRQn
RCC_IRQHandler                 ; RCC_IRQn
EXTI3_0_IRQHandler             ; EXTI3_0_IRQn
EXTI7_4_IRQHandler             ; EXTI7_4_IRQn
EXTI11_8_IRQHandler            ; EXTI11_8_IRQn
EXTI15_12_IRQHandler           ; EXTI15_12_IRQn
EXTI_CMP_IRQHandler            ; EXTI_CMP_IRQn
EXTI_XINT2_1_IRQHandler        ; EXTI_XINT2_1_IRQn
EXTI_XINT5_3_IRQHandler        ; EXTI_XINT5_3_IRQn
EDMA1_CH0_IRQHandler           ; EDMA1_CH0_IRQn
EDMA1_CH1_IRQHandler           ; EDMA1_CH1_IRQn
EDMA1_CH2_IRQHandler           ; EDMA1_CH2_IRQn
EDMA1_CH3_IRQHandler           ; EDMA1_CH3_IRQn
EDMA1_CH4_IRQHandler           ; EDMA1_CH4_IRQn
EDMA1_CH5_IRQHandler           ; EDMA1_CH5_IRQn
EDMA1_CH6_IRQHandler           ; EDMA1_CH6_IRQn
EDMA1_CH7_IRQHandler           ; EDMA1_CH7_IRQn
EDMA1_CH8_IRQHandler           ; EDMA1_CH8_IRQn
EDMA1_CH9_IRQHandler           ; EDMA1_CH9_IRQn
EDMA1_CH10_IRQHandler          ; EDMA1_CH10_IRQn
EDMA1_CH11_IRQHandler          ; EDMA1_CH11_IRQn
EDMA1_CH12_IRQHandler          ; EDMA1_CH12_IRQn
EDMA1_CH13_IRQHandler          ; EDMA1_CH13_IRQn
EDMA1_CH14_IRQHandler          ; EDMA1_CH14_IRQn
EDMA1_CH15_IRQHandler          ; EDMA1_CH15_IRQn
EDMA1_CH16_IRQHandler          ; EDMA1_CH16_IRQn
EDMA1_CH17_IRQHandler          ; EDMA1_CH17_IRQn
EDMA1_CH18_IRQHandler          ; EDMA1_CH18_IRQn
EDMA1_CH19_IRQHandler          ; EDMA1_CH19_IRQn
EDMA1_CH20_IRQHandler          ; EDMA1_CH20_IRQn
EDMA1_CH21_IRQHandler          ; EDMA1_CH21_IRQn
EDMA1_CH22_IRQHandler          ; EDMA1_CH22_IRQn
EDMA1_CH23_IRQHandler          ; EDMA1_CH23_IRQn
EDMA1_CH24_IRQHandler          ; EDMA1_CH24_IRQn
EDMA1_CH25_IRQHandler          ; EDMA1_CH25_IRQn
EDMA1_CH26_IRQHandler          ; EDMA1_CH26_IRQn
EDMA1_CH27_IRQHandler          ; EDMA1_CH27_IRQn
EDMA1_CH28_IRQHandler          ; EDMA1_CH28_IRQn
EDMA1_CH29_IRQHandler          ; EDMA1_CH29_IRQn
EDMA1_CH30_IRQHandler          ; EDMA1_CH30_IRQn
EDMA1_CH31_IRQHandler          ; EDMA1_CH31_IRQn
EDMA1_ERR_IRQHandler           ; EDMA1_ERR_IRQn
EDMA2_CH0_IRQHandler           ; EDMA2_CH0_IRQn
EDMA2_CH1_IRQHandler           ; EDMA2_CH1_IRQn
EDMA2_CH2_IRQHandler           ; EDMA2_CH2_IRQn
EDMA2_CH3_IRQHandler           ; EDMA2_CH3_IRQn
EDMA2_CH4_IRQHandler           ; EDMA2_CH4_IRQn
EDMA2_CH5_IRQHandler           ; EDMA2_CH5_IRQn
EDMA2_CH6_IRQHandler           ; EDMA2_CH6_IRQn
EDMA2_CH7_IRQHandler           ; EDMA2_CH7_IRQn
EDMA2_CH8_IRQHandler           ; EDMA2_CH8_IRQn
EDMA2_CH9_IRQHandler           ; EDMA2_CH9_IRQn
EDMA2_CH10_IRQHandler          ; EDMA2_CH10_IRQn
EDMA2_CH11_IRQHandler          ; EDMA2_CH11_IRQn
EDMA2_CH12_IRQHandler          ; EDMA2_CH12_IRQn
EDMA2_CH13_IRQHandler          ; EDMA2_CH13_IRQn
EDMA2_CH14_IRQHandler          ; EDMA2_CH14_IRQn
EDMA2_CH15_IRQHandler          ; EDMA2_CH15_IRQn
EDMA2_CH16_IRQHandler          ; EDMA2_CH16_IRQn
EDMA2_CH17_IRQHandler          ; EDMA2_CH17_IRQn
EDMA2_CH18_IRQHandler          ; EDMA2_CH18_IRQn
EDMA2_CH19_IRQHandler          ; EDMA2_CH19_IRQn
EDMA2_CH20_IRQHandler          ; EDMA2_CH20_IRQn
EDMA2_CH21_IRQHandler          ; EDMA2_CH21_IRQn
EDMA2_CH22_IRQHandler          ; EDMA2_CH22_IRQn
EDMA2_CH23_IRQHandler          ; EDMA2_CH23_IRQn
EDMA2_CH24_IRQHandler          ; EDMA2_CH24_IRQn
EDMA2_CH25_IRQHandler          ; EDMA2_CH25_IRQn
EDMA2_CH26_IRQHandler          ; EDMA2_CH26_IRQn
EDMA2_CH27_IRQHandler          ; EDMA2_CH27_IRQn
EDMA2_CH28_IRQHandler          ; EDMA2_CH28_IRQn
EDMA2_CH29_IRQHandler          ; EDMA2_CH29_IRQn
EDMA2_CH30_IRQHandler          ; EDMA2_CH30_IRQn
EDMA2_CH31_IRQHandler          ; EDMA2_CH31_IRQn
EDMA2_ERR_IRQHandler           ; EDMA2_ERR_IRQn
ADCA_CONV_IRQHandler           ; ADCA_CONV_IRQn
ADCA_EVENT_IRQHandler          ; ADCA_EVENT_IRQn
ADCB_CONV_IRQHandler           ; ADCB_CONV_IRQn
ADCB_EVENT_IRQHandler          ; ADCB_EVENT_IRQn
ADCC_CONV_IRQHandler           ; ADCC_CONV_IRQn
ADCC_EVENT_IRQHandler          ; ADCC_EVENT_IRQn
ADC_SAFE_CHK_IRQHandler        ; ADC_SAFE_CHK_IRQn
EPWM1_TZINT_IRQHandler         ; EPWM1_TZINT_IRQn
EPWM2_TZINT_IRQHandler         ; EPWM2_TZINT_IRQn
EPWM3_TZINT_IRQHandler         ; EPWM3_TZINT_IRQn
EPWM4_TZINT_IRQHandler         ; EPWM4_TZINT_IRQn
EPWM5_TZINT_IRQHandler         ; EPWM5_TZINT_IRQn
EPWM6_TZINT_IRQHandler         ; EPWM6_TZINT_IRQn
EPWM7_TZINT_IRQHandler         ; EPWM7_TZINT_IRQn
EPWM8_TZINT_IRQHandler         ; EPWM8_TZINT_IRQn
EPWM9_TZINT_IRQHandler         ; EPWM9_TZINT_IRQn
EPWM10_TZINT_IRQHandler        ; EPWM10_TZINT_IRQn
EPWM11_TZINT_IRQHandler        ; EPWM11_TZINT_IRQn
EPWM12_TZINT_IRQHandler        ; EPWM12_TZINT_IRQn
EPWM13_TZINT_IRQHandler        ; EPWM13_TZINT_IRQn
EPWM14_TZINT_IRQHandler        ; EPWM14_TZINT_IRQn
EPWM15_TZINT_IRQHandler        ; EPWM15_TZINT_IRQn
EPWM16_TZINT_IRQHandler        ; EPWM16_TZINT_IRQn
EPWM17_TZINT_IRQHandler        ; EPWM17_TZINT_IRQn
EPWM18_TZINT_IRQHandler        ; EPWM18_TZINT_IRQn
EPWM1_INT_IRQHandler           ; EPWM1_INT_IRQn
EPWM2_INT_IRQHandler           ; EPWM2_INT_IRQn
EPWM3_INT_IRQHandler           ; EPWM3_INT_IRQn
EPWM4_INT_IRQHandler           ; EPWM4_INT_IRQn
EPWM5_INT_IRQHandler           ; EPWM5_INT_IRQn
EPWM6_INT_IRQHandler           ; EPWM6_INT_IRQn
EPWM7_INT_IRQHandler           ; EPWM7_INT_IRQn
EPWM8_INT_IRQHandler           ; EPWM8_INT_IRQn
EPWM9_INT_IRQHandler           ; EPWM8_INT_IRQn
EPWM10_INT_IRQHandler          ; EPWM8_INT_IRQn
EPWM11_INT_IRQHandler          ; EPWM1_INT_IRQn
EPWM12_INT_IRQHandler          ; EPWM2_INT_IRQn
EPWM13_INT_IRQHandler          ; EPWM3_INT_IRQn
EPWM14_INT_IRQHandler          ; EPWM4_INT_IRQn
EPWM15_INT_IRQHandler          ; EPWM5_INT_IRQn
EPWM16_INT_IRQHandler          ; EPWM6_INT_IRQn
EPWM17_INT_IRQHandler          ; EPWM7_INT_IRQn
EPWM18_INT_IRQHandler          ; EPWM8_INT_IRQn
ECAP1_IRQHandler               ; ECAP1_IRQn
ECAP2_IRQHandler               ; ECAP2_IRQn
ECAP3_IRQHandler               ; ECAP3_IRQn
ECAP4_IRQHandler               ; ECAP4_IRQn
ECAP5_IRQHandler               ; ECAP5_IRQn
ECAP6_IRQHandler               ; ECAP6_IRQn
ECAP7_IRQHandler               ; ECAP7_IRQn
EQEP1_IRQHandler               ; EQEP1_IRQn
EQEP2_IRQHandler               ; EQEP2_IRQn
EQEP3_IRQHandler               ; EQEP3_IRQn
EQEP4_IRQHandler               ; EQEP4_IRQn
EQEP5_IRQHandler               ; EQEP5_IRQn
EQEP6_IRQHandler               ; EQEP6_IRQn
EPG_IRQHandler                 ; EPG_IRQn
SDFM1_DR_1_IRQHandler          ; SDFM1_DR_1_IRQn
SDFM1_DR_2_IRQHandler          ; SDFM1_DR_2_IRQn
SDFM1_DR_3_IRQHandler          ; SDFM1_DR_3_IRQn
SDFM1_DR_4_IRQHandler          ; SDFM1_DR_4_IRQn
SDFM1_ERR_IRQHandler           ; SDFM1_ERR_IRQn
SDFM2_DR_1_IRQHandler          ; SDFM2_DR_1_IRQn
SDFM2_DR_2_IRQHandler          ; SDFM2_DR_2_IRQn
SDFM2_DR_3_IRQHandler          ; SDFM2_DR_3_IRQn
SDFM2_DR_4_IRQHandler          ; SDFM2_DR_4_IRQn
SDFM2_ERR_IRQHandler           ; SDFM2_ERR_IRQn
SDFM3_DR_1_IRQHandler          ; SDFM3_DR_1_IRQn
SDFM3_DR_2_IRQHandler          ; SDFM3_DR_2_IRQn
SDFM3_DR_3_IRQHandler          ; SDFM3_DR_3_IRQn
SDFM3_DR_4_IRQHandler          ; SDFM3_DR_4_IRQn
SDFM3_ERR_IRQHandler           ; SDFM3_ERR_IRQn
SDFM4_DR_1_IRQHandler          ; SDFM4_DR_1_IRQn
SDFM4_DR_2_IRQHandler          ; SDFM4_DR_2_IRQn
SDFM4_DR_3_IRQHandler          ; SDFM4_DR_3_IRQn
SDFM4_DR_4_IRQHandler          ; SDFM4_DR_4_IRQn
SDFM4_ERR_IRQHandler           ; SDFM4_ERR_IRQn
LPTIM_IRQHandler               ; LPTIM_IRQn
CAN1_1_IRQHandler              ; CAN1_1_IRQn
CAN1_2_IRQHandler              ; CAN1_2_IRQn
CAN1_ECC_IRQHandler            ; CAN1_ECC_IRQn
CAN1_WKUP_IRQHandler           ; CAN1_WKUP_IRQn
CANFD1_1_IRQHandler            ; CANFD1_1_IRQn
CANFD1_2_IRQHandler            ; CANFD1_2_IRQn
CANFD1_ECC_IRQHandler          ; CANFD1_ECC_IRQn
CANFD1_WKUP_TS_IRQHandler      ; CANFD1_WKUP_TS_IRQn
CANFD2_1_IRQHandler            ; CANFD2_1_IRQn
CANFD2_2_IRQHandler            ; CANFD2_2_IRQn
CANFD2_ECC_IRQHandler          ; CANFD2_ECC_IRQn
CANFD2_WKUP_TS_IRQHandler      ; CANFD2_WKUP_TS_IRQn
BTIM1_IRQHandler               ; BTIM1_IRQn
BTIM2_IRQHandler               ; BTIM2_IRQn
STIM1_IRQHandler               ; STIM1_IRQn
STIM2_IRQHandler               ; STIM2_IRQn
STIM3_IRQHandler               ; STIM3_IRQn
TIM1_IRQHandler                ; TIM1_IRQn
TIM2_IRQHandler                ; TIM2_IRQn
AWK_IRQHandler                 ; AWK_IRQn
LIN1_IRQHandler                ; LIN1_IRQn
LIN2_IRQHandler                ; LIN2_IRQn
I2C1_MST_IRQHandler            ; I2C1_MST_IRQn
I2C1_SLV_IRQHandler            ; I2C1_SLV_IRQn
I2C2_MST_IRQHandler            ; I2C2_MST_IRQn
I2C2_SLV_IRQHandler            ; I2C2_SLV_IRQn
PMBUS_IRQHandler               ; PMBUS_IRQn
SPI1_RX_IRQHandler             ; SPI1_RX_IRQn
SPI1_TX_IRQHandler             ; SPI1_TX_IRQn
SPI2_RX_IRQHandler             ; SPI2_RX_IRQn
SPI2_TX_IRQHandler             ; SPI2_TX_IRQn
SPI3_RX_IRQHandler             ; SPI3_RX_IRQn
SPI3_TX_IRQHandler             ; SPI3_TX_IRQn
SPI4_RX_IRQHandler             ; SPI4_RX_IRQn
SPI4_TX_IRQHandler             ; SPI4_TX_IRQn
UART1_TX_IRQHandler            ; UART1_TX_IRQn
UART1_RX_IRQHandler            ; UART1_RX_IRQn
UART2_TX_IRQHandler            ; UART2_TX_IRQn
UART2_RX_IRQHandler            ; UART2_RX_IRQn
UART3_TX_IRQHandler            ; UART3_TX_IRQn
UART3_RX_IRQHandler            ; UART3_RX_IRQn
UART4_TX_IRQHandler            ; UART4_TX_IRQn
UART4_RX_IRQHandler            ; UART4_RX_IRQn
AESHASH_IRQHandler             ; AESHASH_IRQn
TRNG_IRQHandler                ; TRNG_IRQn
QSPI_IRQHandler                ; QSPI_IRQn
EMATH_IRQHandler               ; EMATH_IRQn
DCC1_IRQHandler                ; DCC1_IRQn
DCC2_IRQHandler                ; DCC2_IRQn
DCC3_IRQHandler                ; DCC3_IRQn
MCM_IRQHandler                 ; MCM_IRQn
VDDRDY_IRQHandler              ; VDDRDY_IRQn
FMU_CFG_IRQHandler             ; FMU_CFG_IRQn
FMU_EVT_IRQHandler             ; FMU_EVT_IRQn
CLB1_IRQHandler                ; CLB1_CFG_IRQn
CLB2_IRQHandler                ; CLB2_CFG_IRQn
CLB3_IRQHandler                ; CLB3_CFG_IRQn
CLB4_IRQHandler                ; CLB4_CFG_IRQn
CLB5_IRQHandler                ; CLB5_CFG_IRQn
CLB6_IRQHandler                ; CLB6_CFG_IRQn
EMIF_IRQHandler                ; CLB6_CFG_IRQn
UPP_IRQHandler                 ; CLB6_CFG_IRQn
MU_IRQHandler                  ; MU_IRQn
MMATH_IRQHandler               ; MMATH_IRQn
EXTI_TXEV_IRQHandler           ; EXTI_TXEV_IRQn

                B       .
                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END


;************************ (C) COPYRIGHT Novosns *****END OF FILE*****
