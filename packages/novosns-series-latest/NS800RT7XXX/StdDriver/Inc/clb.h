/**
  * @file       clb.h
  * @author     Favian
  * @brief      Header file for NS800RT7xxx clb module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __CLB_H__
#define __CLB_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_clb.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup CLB_EXPORTED_TYPES CLB Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'CLB' module.
  */

/** @defgroup CLB_ADDR Address offsets for CLB-internal memory space
  * @{
  * @brief  Macro definitions about Address offsets for CLB-internal memory space
  */
#define CLB_ADDR_COUNTER_0_LOAD      (0x0UL)     /*!< Counter0 Load Value Register */
#define CLB_ADDR_COUNTER_1_LOAD      (0x1UL)     /*!< Counter1 Load Value Register */
#define CLB_ADDR_COUNTER_2_LOAD      (0x2UL)     /*!< Counter2 Load Value Register */
#define CLB_ADDR_COUNTER_0_MATCH1    (0x4UL)     /*!< Counter0 Match1 Reference Register */
#define CLB_ADDR_COUNTER_1_MATCH1    (0x5UL)     /*!< Counter1 Match1 Reference Register */
#define CLB_ADDR_COUNTER_2_MATCH1    (0x6UL)     /*!< Counter2 Match1 Reference Register */
#define CLB_ADDR_COUNTER_0_MATCH2    (0x8UL)     /*!< Counter0 Match2 Reference Register */
#define CLB_ADDR_COUNTER_1_MATCH2    (0x9UL)     /*!< Counter1 Match2 Reference Register */
#define CLB_ADDR_COUNTER_2_MATCH2    (0xAUL)     /*!< Counter2 Match2 Reference Register */
#define CLB_ADDR_HLC_R0              (0xCUL)     /*!< HLC R0 Register */
#define CLB_ADDR_HLC_R1              (0xDUL)     /*!< HLC R1 Register */
#define CLB_ADDR_HLC_R2              (0xEUL)     /*!< HLC R2 Register */
#define CLB_ADDR_HLC_R3              (0xFUL)     /*!< HLC R3 Register */
#define CLB_ADDR_HLC_BASE            (0x20UL)    /*!< HLC EVENT1 Address */

/**
  * @}
  */

/**
  * @brief  CLB HLC Instruction Number
  */
#define CLB_NUM_HLC_INSTR    (31UL)

/**
  * @brief  CLB PUSHPULL FIFO size(32-bit registers)
  */
#define CLB_FIFO_SIZE    (4UL)    /* CLB PUSH/PULL FIFO size */

/**
  * @brief  CLB Lock Register's Key Code
  */
#define CLB_LOCK_KEY    (0x5A5AUL)    /* CLB Lock Register's Key Code */

/** @defgroup CLB_LOCALINPUTMUX_SELECTION Shift and masks needed by the API for Input selection
  * @{
  * @brief  Macro definitions about shift and masks for Input selection API
  */
#define CLB_LOCALINPUTMUX_MISCINPUTSEL_M    (0x20UL)
#define CLB_LOCALINPUTMUX_MISCINPUTSEL_S    (0x5UL)
#define CLB_LCLMUXSEL_MISCINPUTSEL_S        CLB_LCLMUXSEL1_MISCIN0SEL_S

/**
  * @}
  */

/** @defgroup CLB_OUTPUT_MASK CLB Output Enable Signal Mask
  * @{
  * @brief  CLB output enable signal mask, It can be passed to
  *         @ref CLB_setOutputMask() as the \e outputMask parameter.
  */
#define CLB_OUTPUT_00    (0x00000001UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 0 */
#define CLB_OUTPUT_01    (0x00000002UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 1 */
#define CLB_OUTPUT_02    (0x00000004UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 2 */
#define CLB_OUTPUT_03    (0x00000008UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 3 */
#define CLB_OUTPUT_04    (0x00000010UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 4 */
#define CLB_OUTPUT_05    (0x00000020UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 5 */
#define CLB_OUTPUT_06    (0x00000040UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 6 */
#define CLB_OUTPUT_07    (0x00000080UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 7 */
#define CLB_OUTPUT_08    (0x00000100UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 8 */
#define CLB_OUTPUT_09    (0x00000200UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 9 */
#define CLB_OUTPUT_10    (0x00000400UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 10 */
#define CLB_OUTPUT_11    (0x00000800UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 11 */
#define CLB_OUTPUT_12    (0x00001000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 12 */
#define CLB_OUTPUT_13    (0x00002000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 13 */
#define CLB_OUTPUT_14    (0x00004000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 14 */
#define CLB_OUTPUT_15    (0x00008000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 15 */
#define CLB_OUTPUT_16    (0x00010000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 16 */
#define CLB_OUTPUT_17    (0x00020000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 17 */
#define CLB_OUTPUT_18    (0x00040000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 18 */
#define CLB_OUTPUT_19    (0x00080000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 19 */
#define CLB_OUTPUT_20    (0x00100000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 20 */
#define CLB_OUTPUT_21    (0x00200000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 21 */
#define CLB_OUTPUT_22    (0x00400000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 22 */
#define CLB_OUTPUT_23    (0x00800000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 23 */
#define CLB_OUTPUT_24    (0x01000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 24 */
#define CLB_OUTPUT_25    (0x02000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 25 */
#define CLB_OUTPUT_26    (0x04000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 26 */
#define CLB_OUTPUT_27    (0x08000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 27 */
#define CLB_OUTPUT_28    (0x10000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 28 */
#define CLB_OUTPUT_29    (0x20000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 29 */
#define CLB_OUTPUT_30    (0x40000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 30 */
#define CLB_OUTPUT_31    (0x80000000UL)    /*!< Mask for CLB OUTPUT ENABLE/DISABLE 31 */

/**
  * @}
  */

/** \defgroup CLB_OFFSET_DEBUG CLB Register Offset Address
  * @{
  * @brief Macro definitions about Offset Address of CLB's DEBUG registers
  */
#define CLB_OFFSET_DEBUG_OUT2    (0x144UL)
#define CLB_OFFSET_DEBUG_R0      (0x148UL)
#define CLB_OFFSET_DEBUG_R1      (0x14CUL)
#define CLB_OFFSET_DEBUG_R2      (0x150UL)
#define CLB_OFFSET_DEBUG_R3      (0x154UL)
#define CLB_OFFSET_DEBUG_C0      (0x158UL)
#define CLB_OFFSET_DEBUG_C1      (0x15CUL)
#define CLB_OFFSET_DEBUG_C2      (0x160UL)
#define CLB_OFFSET_DEBUG_OUT     (0x164UL)

/**
  * @}
  */

/** \defgroup CLB_INTERRUPTS CLB Interrupt Source
  * @{
  * @brief Macro definitions about CLB Interrupt Source
  */
#define CLB_INT_FLAG0       CLB_SRCTRL_IFLAG0IE_M
#define CLB_INT_FLAG1       CLB_SRCTRL_IFLAG1IE_M
#define CLB_INT_FLAG2       CLB_SRCTRL_IFLAG2IE_M
#define CLB_INT_FLAG3       CLB_SRCTRL_IFLAG3IE_M
#define CLB_INT_NMIFLAG0    CLB_SRCTRL_IF0NMIEN_M
#define CLB_INT_NMIFLAG1    CLB_SRCTRL_IF1NMIEN_M
#define CLB_INT_NMIFLAG2    CLB_SRCTRL_IF2NMIEN_M
#define CLB_INT_NMIFLAG3    CLB_SRCTRL_IF3NMIEN_M
#define CLB_INT_DATAFULL    CLB_SRCTRL_DRDYIE_M
#define CLB_INT_DATARDY     CLB_SRCTRL_DRDYIE_M

/**
  * @}
  */

/** \defgroup CLB_FLAGS_CLEAR CLB Clear Interrupt Flags
  * @{
  * @brief Macro definitions about CLB Clear Interrupt Flags
  */
#define CLB_CLR_FLAG0       CLB_SRCLR_IFLAG0_M
#define CLB_CLR_FLAG1       CLB_SRCLR_IFLAG1_M
#define CLB_CLR_FLAG2       CLB_SRCLR_IFLAG2_M
#define CLB_CLR_FLAG3       CLB_SRCLR_IFLAG3_M
#define CLB_CLR_DATAFULL    CLB_SRCLR_FULLIF_M
#define CLB_CLR_DATARDY     CLB_SRCLR_DRDYIF_M

/**
  * @}
  */

/** @defgroup CLB_INPUTS CLB Inputs Selection
  * @{
  * @brief Values that can be passed to select CLB input signal
  */
typedef enum {
    CLB_IN0 = 0,    /*!< Input 0 */
    CLB_IN1,        /*!< Input 1 */
    CLB_IN2,        /*!< Input 2 */
    CLB_IN3,        /*!< Input 3 */
    CLB_IN4,        /*!< Input 4 */
    CLB_IN5,        /*!< Input 5 */
    CLB_IN6,        /*!< Input 6 */
    CLB_IN7         /*!< Input 7 */
} CLB_Inputs;

/**
  * @}
  */

/** @defgroup CLB_ONTPUTS CLB Ontputs Selection
  * @{
  * @brief  Values that can be passed to select CLB output signal.
  *         It can be passed to CLB_configOutputLUT() as the \e outID parameter.
  */
typedef enum {
    CLB_OUT0 = 0,    /*!< Output 0 */
    CLB_OUT1,        /*!< Output 1 */
    CLB_OUT2,        /*!< Output 2 */
    CLB_OUT3,        /*!< Output 3 */
    CLB_OUT4,        /*!< Output 4 */
    CLB_OUT5,        /*!< Output 5 */
    CLB_OUT6,        /*!< Output 6 */
    CLB_OUT7         /*!< Output 7 */
} CLB_Outputs;

/**
  * @}
  */

/** @defgroup CLB_AOCS CLB AOC Selection
  * @{
  * @brief  Values that can be passed to select CLB AOC signal.
  *         It can be passed to CLB_configAOC() as the \e aocID parameter.
  *         AOC is the Asynchronous Output Conditioning block.
  */
typedef enum {
    CLB_AOC0 = 0,    /*!< AOC 0 */
    CLB_AOC1,        /*!< AOC 1 */
    CLB_AOC2,        /*!< AOC 2 */
    CLB_AOC3,        /*!< AOC 3 */
    CLB_AOC4,        /*!< AOC 4 */
    CLB_AOC5,        /*!< AOC 5 */
    CLB_AOC6,        /*!< AOC 6 */
    CLB_AOC7         /*!< AOC 7 */
} CLB_AOCs;

/**
  * @}
  */

/** @defgroup CLB_SWRELEASECTRL CLB Software Release Control
  * @{
  * @brief  Values that can be passed to set/clear CLB SW release signals.
  *         It can be passed to CLB_writeSWReleaseControl() as the
  *         \e inID parameter.
  */
typedef enum {
    CLB_SW_RLS_CTRL0 = 0,    /*!< SW RLS CTRL 0 */
    CLB_SW_RLS_CTRL1,        /*!< SW RLS CTRL 1 */
    CLB_SW_RLS_CTRL2,        /*!< SW RLS CTRL 2 */
    CLB_SW_RLS_CTRL3,        /*!< SW RLS CTRL 3 */
    CLB_SW_RLS_CTRL4,        /*!< SW RLS CTRL 4 */
    CLB_SW_RLS_CTRL5,        /*!< SW RLS CTRL 5 */
    CLB_SW_RLS_CTRL6,        /*!< SW RLS CTRL 6 */
    CLB_SW_RLS_CTRL7         /*!< SW RLS CTRL 7 */
} CLB_SWReleaseCtrl;

/**
  * @}
  */

/** @defgroup CLB_SWGATECTRL CLB Software Gate Control
  * @{
  * @brief  Values that can be passed to set/clear CLB SW release signals.
  *         It can be passed to CLB_writeSWGateControl() as the \e inID parameter.
  */
typedef enum {
    CLB_SW_GATE_CTRL0 = 0U,    /*!< SW GATE CTRL 0 */
    CLB_SW_GATE_CTRL1,         /*!< SW GATE CTRL 1 */
    CLB_SW_GATE_CTRL2,         /*!< SW GATE CTRL 2 */
    CLB_SW_GATE_CTRL3,         /*!< SW GATE CTRL 3 */
    CLB_SW_GATE_CTRL4,         /*!< SW GATE CTRL 4 */
    CLB_SW_GATE_CTRL5,         /*!< SW GATE CTRL 5 */
    CLB_SW_GATE_CTRL6,         /*!< SW GATE CTRL 6 */
    CLB_SW_GATE_CTRL7          /*!< SW GATE CTRL 7 */
} CLB_SWGateCtrl;

/**
  * @}
  */

/** @defgroup CLB_COUNTERS CLB Counters
  * @{
  * @brief  Values that can be passed to select CLB counter. It can be passed to
  *         CLB_configCounterLoadMatch() as the \e counterID parameter.
  */
typedef enum {
    CLB_CTR0 = 0,    /*!< Counter 0 */
    CLB_CTR1,        /*!< Counter 1 */
    CLB_CTR2         /*!< Counter 2 */
} CLB_Counters;

/**
  * @}
  */

/** @defgroup CLB_REGISTERS CLB Registers
  * @{
  * @brief  Values that can be passed to CLB_getRegister() as the \e registerID
  *         parameter.
  */
typedef enum {
    CLB_REG_HLC_R0 = CLB_OFFSET_DEBUG_R0,    /*!< HLC R0 register */
    CLB_REG_HLC_R1 = CLB_OFFSET_DEBUG_R1,    /*!< HLC R1 register */
    CLB_REG_HLC_R2 = CLB_OFFSET_DEBUG_R2,    /*!< HLC R2 register */
    CLB_REG_HLC_R3 = CLB_OFFSET_DEBUG_R3,    /*!< HLC R3 register */
    CLB_REG_CTR_C0 = CLB_OFFSET_DEBUG_C0,    /*!< Counter 0 register */
    CLB_REG_CTR_C1 = CLB_OFFSET_DEBUG_C1,    /*!< Counter 1 register */
    CLB_REG_CTR_C2 = CLB_OFFSET_DEBUG_C2     /*!< Counter 2 register */
} CLB_Register;

/**
  * @}
  */

/** @defgroup CLB_FILTERTYPE CLB Filter Types
  * @{
  * @brief  Values that can be passed to CLB_selectInputFilter() as the \e filterType
  *         parameter.
  */
typedef enum {
    CLB_FILTER_NONE = 0U,       /*!< No filtering */
    CLB_FILTER_RISING_EDGE,     /*!< Rising edge detect */
    CLB_FILTER_FALLING_EDGE,    /*!< Falling edge detect */
    CLB_FILTER_ANY_EDGE         /*!< Any edge detect */
} CLB_FilterType;

/**
  * @}
  */

/** @defgroup CLB_GPINPUTMUX CLB General Purpose Input Mux
  * @{
  * @brief  Values that can be passed to CLB_configGPInputMux() as the \e gpMuxCfg
  * parameter.
  */
typedef enum {
    CLB_GP_IN_MUX_EXTERNAL = 0U,    /*!< Use external input path */
    CLB_GP_IN_MUX_GP_REG            /*!< Use CLB_GP_REG bit value as input */
} CLB_GPInputMux;

/**
  * @}
  */

/** @defgroup CLB_LOCALINPUTMUX CLB Local Input Mux
  * @{
  * @brief  Values that can be passed to CLB_configLocalInputMux() as the
  *         \e localMuxCfg parameter.
  */
typedef enum {
    CLB_LOCAL_IN_MUX_GLOBAL_IN = 0,    /*!< Global input mux selection */

    CLB_LOCAL_IN_MUX_EPWM_DCAEVT1 = 1U,    /*!< EPWMx DCAEVT1 */
    CLB_LOCAL_IN_MUX_EPWM_DCAEVT2,         /*!< EPWMx DCAEVT2 */
    CLB_LOCAL_IN_MUX_EPWM_DCBEVT1,         /*!< EPWMx DCBEVT1 */
    CLB_LOCAL_IN_MUX_EPWM_DCBEVT2,         /*!< EPWMx DCBEVT2 */
    CLB_LOCAL_IN_MUX_EPWM_DCAH,            /*!< EPWMx DCAH */
    CLB_LOCAL_IN_MUX_EPWM_DCAL,            /*!< EPWMx DCAL */
    CLB_LOCAL_IN_MUX_EPWM_DCBH,            /*!< EPWMx DCBH */
    CLB_LOCAL_IN_MUX_EPWM_DCBL,            /*!< EPWMx DCBL */
    CLB_LOCAL_IN_MUX_EPWM_OST,             /*!< EPWMx OST */
    CLB_LOCAL_IN_MUX_EPWM_CBC,             /*!< EPWMx CBC */

    CLB_LOCAL_IN_MUX_ECAP_ECAPIN = 11U,    /*!< ECAPx ECAPIN */
    CLB_LOCAL_IN_MUX_ECAP_ECAP_OUT,        /*!< ECAPx ECAP_OUT */
    CLB_LOCAL_IN_MUX_ECAP_ECAP_OUT_EN,     /*!< ECAPx ECAP_OUT_EN */
    CLB_LOCAL_IN_MUX_ECAP_CEVT1,           /*!< ECAPx CEVT1 */
    CLB_LOCAL_IN_MUX_ECAP_CEVT2,           /*!< ECAPx CEVT2 */
    CLB_LOCAL_IN_MUX_ECAP_CEVT3,           /*!< ECAPx CEVT3 */
    CLB_LOCAL_IN_MUX_ECAP_CEVT4,           /*!< ECAPx CEVT4 */

    CLB_LOCAL_IN_MUX_EQEP_EQEPA = 18U,    /*!< EQEPx EQEPA (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP_EQEPB,          /*!< EQEPx EQEPB (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP_EQEPI,          /*!< EQEPx EQEPI (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP_EQEPS = 21U,    /*!< EQEPx EQEPS (CLB 1-4) */
    CLB_LOCAL_IN_MUX_CPU2_HALT  = 21U,    /*!< CPU2.HALT (CLB 5-6) */

    CLB_LOCAL_IN_MUX_CPU1_TBCLKSYNC = 22U,    /*!< CPU1.TBCLKSYNC */
    CLB_LOCAL_IN_MUX_CPU2_TBCLKSYNC,          /*!< CPU2.TBCLKSYNC */
    CLB_LOCAL_IN_MUX_CPU1_HALT,               /*!< CPU1.HALT */

    CLB_LOCAL_IN_MUX_SPIPICO_CONTROLLER = 25U,    /*!< SPIxPICO Controller Output */
    CLB_LOCAL_IN_MUX_SPICLK,                      /*!< SPIx Clock */
    CLB_LOCAL_IN_MUX_SPIPICO_PERIPHERAL,          /*!< SPIxPICO Peripheral Input */
    CLB_LOCAL_IN_MUX_SPIPTE,                      /*!< SPIx PTE */
    CLB_LOCAL_IN_MUX_SCI_TX,                      /*!< SCIx TX */
    CLB_LOCAL_IN_MUX_SPIPOCI_OUT,                 /*!< SPIxPOCI(OUT) */

    CLB_LOCAL_IN_MUX_CLB_PSCLK = 31U,    /*!< CLBx prescaled clock */

    CLB_LOCAL_IN_MUX_EPWM9A            = 32U,    /*!< EPWM9A (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_ECAPIN      = 32U,    /*!< ECAP5 ECAPIN (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM9A_OE         = 33U,    /*!< EPWM9A trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_ECAP_OUT    = 33U,    /*!< ECAP5 ECAP_OUT(CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM9B            = 34U,    /*!< EPWM9B (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_ECAP_OUT_EN = 34U,    /*!< ECAP5 ECAP_OUT_EN (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM9B_OE         = 35U,    /*!< EPWM9B trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_CEVT1       = 35U,    /*!< ECAP5 CEVT1 (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM10A           = 36U,    /*!< EPWM10A (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_CEVT2       = 36U,    /*!< ECAP5 CEVT2 (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM10A_OE        = 37U,    /*!< EPWM10A trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_CEVT3       = 37U,    /*!< ECAP5 CEVT3 (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM10B           = 38U,    /*!< EPWM10B (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_CEVT4       = 38U,    /*!< ECAP5 CEVT4 (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM10B_OE        = 39U,    /*!< EPWM10B trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_ECAP5_ECAPIN0     = 39U,    /*!< ECAP5 ECAPIN0 (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM11A           = 40U,    /*!< EPWM11A (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP5_EQEPA       = 40U,    /*!< EQEP5 EQEPA (CLB 5) */
    CLB_LOCAL_IN_MUX_EQEP6_EQEPA       = 40U,    /*!< EQEP6 EQEPA (CLB 6) */
    CLB_LOCAL_IN_MUX_EPWM11A_OE        = 41U,    /*!< EPWM11A trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP5_EQEPB       = 41U,    /*!< EQEP5 EQEPB (CLB 5) */
    CLB_LOCAL_IN_MUX_EQEP6_EQEPB       = 41U,    /*!< EQEP6 EQEPB (CLB 6) */
    CLB_LOCAL_IN_MUX_EPWM11B           = 42U,    /*!< EPWM11B (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP5_EQEPI       = 42U,    /*!< EQEP5 EQEPI (CLB 5) */
    CLB_LOCAL_IN_MUX_EQEP6_EQEPI       = 42U,    /*!< EQEP6 EQEPI (CLB 6) */
    CLB_LOCAL_IN_MUX_EPWM11B_OE        = 43U,    /*!< EPWM11B trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EQEP5_EQEPS       = 43U,    /*!< EQEP5 EQEPS (CLB 5) */
    CLB_LOCAL_IN_MUX_EQEP6_EQEPS       = 43U,    /*!< EQEP6 EQEPS (CLB 6) */
    CLB_LOCAL_IN_MUX_EPWM12A           = 44U,    /*!< EPWM12A (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EPWM16A           = 44U,    /*!< EPWM16A (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM12A_OE        = 45U,    /*!< EPWM12A trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EPWM16A_OE        = 45U,    /*!< EPWM16A trip output (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM12B           = 46U,    /*!< EPWM12B (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EPWM16B           = 46U,    /*!< EPWM16B (CLB 5-6) */
    CLB_LOCAL_IN_MUX_EPWM12B_OE        = 47U,    /*!< EPWM12B trip output (CLB 1-4) */
    CLB_LOCAL_IN_MUX_EPWM16B_OE        = 47U,    /*!< EPWM16B trip output (CLB 5-6) */

    CLB_LOCAL_IN_MUX_INPUT1 = 48U,    /*!< CLBINPUTXBAR INPUT1 */
    CLB_LOCAL_IN_MUX_INPUT2,          /*!< CLBINPUTXBAR INPUT2 */
    CLB_LOCAL_IN_MUX_INPUT3,          /*!< CLBINPUTXBAR INPUT3 */
    CLB_LOCAL_IN_MUX_INPUT4,          /*!< CLBINPUTXBAR INPUT4 */
    CLB_LOCAL_IN_MUX_INPUT5,          /*!< CLBINPUTXBAR INPUT5 */
    CLB_LOCAL_IN_MUX_INPUT6,          /*!< CLBINPUTXBAR INPUT6 */
    CLB_LOCAL_IN_MUX_INPUT7,          /*!< CLBINPUTXBAR INPUT7 */
    CLB_LOCAL_IN_MUX_INPUT8,          /*!< CLBINPUTXBAR INPUT8 */
    CLB_LOCAL_IN_MUX_INPUT9,          /*!< CLBINPUTXBAR INPUT9 */
    CLB_LOCAL_IN_MUX_INPUT10,         /*!< CLBINPUTXBAR INPUT10 */
    CLB_LOCAL_IN_MUX_INPUT11,         /*!< CLBINPUTXBAR INPUT11 */
    CLB_LOCAL_IN_MUX_INPUT12,         /*!< CLBINPUTXBAR INPUT12 */
    CLB_LOCAL_IN_MUX_INPUT13,         /*!< CLBINPUTXBAR INPUT13 */
    CLB_LOCAL_IN_MUX_INPUT14,         /*!< CLBINPUTXBAR INPUT14 */
    CLB_LOCAL_IN_MUX_INPUT15,         /*!< CLBINPUTXBAR INPUT15 */
    CLB_LOCAL_IN_MUX_INPUT16          /*!< CLBINPUTXBAR INPUT16 */
} CLB_LocalInputMux;

/**
  * @}
  */

/** @defgroup CLB_GLOBAL_INPUT_MUX CLB Global Input Mux
  * @{
  * @brief  Values that can be passed to CLB_configGlobalInputMux() as the
  *         \e globalMuxCfg parameter.
  */
typedef enum {
    CLB_GLOBAL_IN_MUX_EPWM1A         = 0U,     /*!< EPWM1A (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5A         = 0U,     /*!< EPWM5A (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1A_OE      = 1U,     /*!< EPWM1A trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5A_OE      = 1U,     /*!< EPWM5A trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1B         = 2U,     /*!< EPWM1B (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5B         = 2U,     /*!< EPWM5B (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1B_OE      = 3U,     /*!< EPWM1B trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5B_OE      = 3U,     /*!< EPWM5B trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTR_ZERO = 4U,     /*!< EPWM1 TBCTR = Zero (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTR_ZERO = 4U,     /*!< EPWM5 TBCTR = Zero (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTR_PRD  = 5U,     /*!< EPWM1 TBCTR = TBPRD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTR_PRD  = 5U,     /*!< EPWM5 TBCTR = TBPRD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTRDIR   = 6U,     /*!< EPWM1 CTRDIR (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTRDIR   = 6U,     /*!< EPWM5 CTRDIR (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_TBCLK    = 7U,     /*!< EPWM1 TBCLK (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_TBCLK    = 7U,     /*!< EPWM5 TBCLK (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPA = 8U,     /*!< EPWM1 TBCTR = CMPA (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTR_CMPA = 8U,     /*!< EPWM5 TBCTR = CMPA (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPB = 9U,     /*!< EPWM1 TBCTR = CMPB (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTR_CMPB = 9U,     /*!< EPWM5 TBCTR = CMPB (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPC = 10U,    /*!< EPWM1 TBCTR = CMPC (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTR_CMPC = 10U,    /*!< EPWM5 TBCTR = CMPC (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPD = 11U,    /*!< EPWM1 TBCTR = CMPD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5_CTR_CMPD = 11U,    /*!< EPWM5 TBCTR = CMPD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1A_AQ      = 12U,    /*!< EPWM1A AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5A_AQ      = 12U,    /*!< EPWM5A AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1B_AQ      = 13U,    /*!< EPWM1B AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5B_AQ      = 13U,    /*!< EPWM5B AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1A_DB      = 14U,    /*!< EPWM1A DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5A_DB      = 14U,    /*!< EPWM5A DB submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM1B_DB      = 15U,    /*!< EPWM1B DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM5B_DB      = 15U,    /*!< EPWM5B DB submodule output (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_EPWM2A         = 16U,    /*!< EPWM2A (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6A         = 16U,    /*!< EPWM6A (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2A_OE      = 17U,    /*!< EPWM2A trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6A_OE      = 17U,    /*!< EPWM6A trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2B         = 18U,    /*!< EPWM2B (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6B         = 18U,    /*!< EPWM6B (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2B_OE      = 19U,    /*!< EPWM2B trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6B_OE      = 19U,    /*!< EPWM6B trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTR_ZERO = 20U,    /*!< EPWM2 TBCTR = Zero (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTR_ZERO = 20U,    /*!< EPWM6 TBCTR = Zero (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTR_PRD  = 21U,    /*!< EPWM2 TBCTR = TBPRD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTR_PRD  = 21U,    /*!< EPWM6 TBCTR = TBPRD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTRDIR   = 22U,    /*!< EPWM2 CTRDIR (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTRDIR   = 22U,    /*!< EPWM6 CTRDIR (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_TBCLK    = 23U,    /*!< EPWM2 TBCLK (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_TBCLK    = 23U,    /*!< EPWM6 TBCLK (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPA = 24U,    /*!< EPWM2 TBCTR = CMPA (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTR_CMPA = 24U,    /*!< EPWM6 TBCTR = CMPA (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPB = 25U,    /*!< EPWM2 TBCTR = CMPB (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTR_CMPB = 25U,    /*!< EPWM6 TBCTR = CMPB (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPC = 26U,    /*!< EPWM2 TBCTR = CMPC (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTR_CMPC = 26U,    /*!< EPWM6 TBCTR = CMPC (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPD = 27U,    /*!< EPWM2 TBCTR = CMPD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6_CTR_CMPD = 27U,    /*!< EPWM6 TBCTR = CMPD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2A_AQ      = 28U,    /*!< EPWM2A AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6A_AQ      = 28U,    /*!< EPWM6A AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2B_AQ      = 29U,    /*!< EPWM2B AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6B_AQ      = 29U,    /*!< EPWM6B AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2A_DB      = 30U,    /*!< EPWM2A DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6A_DB      = 30U,    /*!< EPWM6A DB submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM2B_DB      = 31U,    /*!< EPWM2B DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM6B_DB      = 31U,    /*!< EPWM6B DB submodule output (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_EPWM3A         = 32U,    /*!< EPWM3A (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7A         = 32U,    /*!< EPWM7A (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3A_OE      = 33U,    /*!< EPWM3A trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7A_OE      = 33U,    /*!< EPWM7A trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3B         = 34U,    /*!< EPWM3B (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7B         = 34U,    /*!< EPWM7B (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3B_OE      = 35U,    /*!< EPWM3B trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7B_OE      = 35U,    /*!< EPWM7B trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTR_ZERO = 36U,    /*!< EPWM3 TBCTR = Zero (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTR_ZERO = 36U,    /*!< EPWM7 TBCTR = Zero (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTR_PRD  = 37U,    /*!< EPWM3 TBCTR = TBPRD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTR_PRD  = 37U,    /*!< EPWM7 TBCTR = TBPRD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTRDIR   = 38U,    /*!< EPWM3 CTRDIR (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTRDIR   = 38U,    /*!< EPWM7 CTRDIR (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_TBCLK    = 39U,    /*!< EPWM3 TBCLK (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_TBCLK    = 39U,    /*!< EPWM7 TBCLK (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPA = 40U,    /*!< EPWM3 TBCTR = CMPA (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTR_CMPA = 40U,    /*!< EPWM7 TBCTR = CMPA (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPB = 41U,    /*!< EPWM3 TBCTR = CMPB (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTR_CMPB = 41U,    /*!< EPWM7 TBCTR = CMPB (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPC = 42U,    /*!< EPWM3 TBCTR = CMPC (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTR_CMPC = 42U,    /*!< EPWM7 TBCTR = CMPC (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPD = 43U,    /*!< EPWM3 TBCTR = CMPD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7_CTR_CMPD = 43U,    /*!< EPWM7 TBCTR = CMPD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3A_AQ      = 44U,    /*!< EPWM3A AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7A_AQ      = 44U,    /*!< EPWM7A AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3B_AQ      = 45U,    /*!< EPWM3B AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7B_AQ      = 45U,    /*!< EPWM7B AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3A_DB      = 46U,    /*!< EPWM3A DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7A_DB      = 46U,    /*!< EPWM7A DB submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM3B_DB      = 47U,    /*!< EPWM3B DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM7B_DB      = 47U,    /*!< EPWM7B DB submodule output (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_EPWM4A         = 48,    /*!< EPWM4A (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8A         = 48,    /*!< EPWM8A (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4A_OE      = 49,    /*!< EPWM4A trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8A_OE      = 49,    /*!< EPWM8A trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4B         = 50,    /*!< EPWM4B (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8B         = 50,    /*!< EPWM8B (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4B_OE      = 51,    /*!< EPWM4B trip output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8B_OE      = 51,    /*!< EPWM8B trip output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTR_ZERO = 52,    /*!< EPWM4 TBCTR = Zero (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTR_ZERO = 52,    /*!< EPWM8 TBCTR = Zero (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTR_PRD  = 53,    /*!< EPWM4 TBCTR = TBPRD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTR_PRD  = 53,    /*!< EPWM8 TBCTR = TBPRD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR   = 54,    /*!< EPWM4 CTRDIR (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTRDIR   = 54,    /*!< EPWM8 CTRDIR (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_TBCLK    = 55,    /*!< EPWM4 TBCLK (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_TBCLK    = 55,    /*!< EPWM8 TBCLK (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPA = 56,    /*!< EPWM4 TBCTR = CMPA (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTR_CMPA = 56,    /*!< EPWM8 TBCTR = CMPA (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPB = 57,    /*!< EPWM4 TBCTR = CMPB (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTR_CMPB = 57,    /*!< EPWM8 TBCTR = CMPB (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPC = 58,    /*!< EPWM4 TBCTR = CMPC (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTR_CMPC = 58,    /*!< EPWM8 TBCTR = CMPC (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPD = 59,    /*!< EPWM4 TBCTR = CMPD (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8_CTR_CMPD = 59,    /*!< EPWM8 TBCTR = CMPD (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4A_AQ      = 60,    /*!< EPWM4A AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8A_AQ      = 60,    /*!< EPWM8A AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4B_AQ      = 61,    /*!< EPWM4B AQ submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8B_AQ      = 61,    /*!< EPWM8B AQ submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4A_DB      = 62,    /*!< EPWM4A DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8A_DB      = 62,    /*!< EPWM8A DB submodule output (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_EPWM4B_DB      = 63,    /*!< EPWM4B DB submodule output (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_EPWM8B_DB      = 63,    /*!< EPWM8B DB submodule output (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_CLB_AUXSIG0 = 64,    /*!< CLB X-BAR AUXSIG0 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG1 = 65,    /*!< CLB X-BAR AUXSIG1 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG2 = 66,    /*!< CLB X-BAR AUXSIG2 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG3 = 67,    /*!< CLB X-BAR AUXSIG3 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG4 = 68,    /*!< CLB X-BAR AUXSIG4 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG5 = 69,    /*!< CLB X-BAR AUXSIG5 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG6 = 70,    /*!< CLB X-BAR AUXSIG6 */
    CLB_GLOBAL_IN_MUX_CLB_AUXSIG7 = 71,    /*!< CLB X-BAR AUXSIG7 */

    CLB_GLOBAL_IN_MUX_CLB1_OUT16 = 72,    /*!< CLB1 OUT16 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT16 = 72,    /*!< CLB5 OUT16 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT17 = 73,    /*!< CLB1 OUT17 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT17 = 73,    /*!< CLB5 OUT17 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT18 = 74,    /*!< CLB1 OUT18 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT18 = 74,    /*!< CLB5 OUT18 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT19 = 75,    /*!< CLB1 OUT19 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT19 = 75,    /*!< CLB5 OUT19 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT20 = 76,    /*!< CLB1 OUT20 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT20 = 76,    /*!< CLB5 OUT20 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT21 = 77,    /*!< CLB1 OUT21 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT21 = 77,    /*!< CLB5 OUT21 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT22 = 78,    /*!< CLB1 OUT22 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT22 = 78,    /*!< CLB5 OUT22 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB1_OUT23 = 79,    /*!< CLB1 OUT23 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB5_OUT23 = 79,    /*!< CLB5 OUT23 (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_CLB2_OUT16 = 80,    /*!< CLB2 OUT16 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT16 = 80,    /*!< CLB6 OUT16 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT17 = 81,    /*!< CLB2 OUT17 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT17 = 81,    /*!< CLB6 OUT17 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT18 = 82,    /*!< CLB2 OUT18 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT18 = 82,    /*!< CLB6 OUT18 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT19 = 83,    /*!< CLB2 OUT19 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT19 = 83,    /*!< CLB6 OUT19 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT20 = 84,    /*!< CLB2 OUT20 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT20 = 84,    /*!< CLB6 OUT20 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT21 = 85,    /*!< CLB2 OUT21 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT21 = 85,    /*!< CLB6 OUT21 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT22 = 86,    /*!< CLB2 OUT22 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT22 = 86,    /*!< CLB6 OUT22 (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_CLB2_OUT23 = 87,    /*!< CLB2 OUT23 (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_CLB6_OUT23 = 87,    /*!< CLB6 OUT23 (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_CLB3_OUT16 = 88,    /*!< CLB3 OUT16 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT17 = 89,    /*!< CLB3 OUT17 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT18 = 90,    /*!< CLB3 OUT18 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT19 = 91,    /*!< CLB3 OUT19 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT20 = 92,    /*!< CLB3 OUT20 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT21 = 93,    /*!< CLB3 OUT21 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT22 = 94,    /*!< CLB3 OUT22 */
    CLB_GLOBAL_IN_MUX_CLB3_OUT23 = 95,    /*!< CLB3 OUT23 */

    CLB_GLOBAL_IN_MUX_CLB4_OUT16 = 96,     /*!< CLB4 OUT16 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT17 = 97,     /*!< CLB4 OUT17 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT18 = 98,     /*!< CLB4 OUT18 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT19 = 99,     /*!< CLB4 OUT19 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT20 = 100,    /*!< CLB4 OUT20 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT21 = 101,    /*!< CLB4 OUT21 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT22 = 102,    /*!< CLB4 OUT22 */
    CLB_GLOBAL_IN_MUX_CLB4_OUT23 = 103,    /*!< CLB4 OUT23 */

    CLB_GLOBAL_IN_MUX_SPI1_SPICLK             = 120,    /*!< SPI1 SPICLK OUT (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_SPI3_SPICLK             = 120,    /*!< SPI3 SPICLK OUT (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_SPI1_SPIPOCI_CONTROLLER = 121,    /*!< SPI1 SPIPOCI Controller IN (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_SPI3_SPIPOCI_CONTROLLER = 121,    /*!< SPI3 SPIPOCI Controller IN (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_SPI1_SPIPTE             = 122,    /*!< SPI1 SPIPTE OUT (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_SPI3_SPIPTE             = 122,    /*!< SPI3 SPIPTE OUT (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_SPI2_SPICLK             = 123,    /*!< SPI2 SPICLK OUT (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_SPI4_SPICLK             = 123,    /*!< SPI4 SPICLK OUT (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_SPI2_SPIPOCI_CONTROLLER = 124,    /*!< SPI2 SPIPOCI Controller IN (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_SPI4_SPIPOCI_CONTROLLER = 124,    /*!< SPI4 SPIPOCI Controller IN (CLB 5-6) */
    CLB_GLOBAL_IN_MUX_SPI2_SPIPTE             = 125,    /*!< SPI2 SPIPTE OUT (CLB 1-4) */
    CLB_GLOBAL_IN_MUX_SPI4_SPIPTE             = 125,    /*!< SPI4 SPIPTE OUT (CLB 5-6) */

    CLB_GLOBAL_IN_MUX_CPU2_HALT = 126,    /*!< CPU2 HALT (CLB 1-4) */
} CLB_GlobalInputMux;

/**
  * @}
  */

/** @defgroup CLB_TAGS CLB Interrupt Tags
  * @{
  * @brief  Values that can be passed to CLB_clearInterruptTag() as the
  *         \e interruptTagID parameter.
  */
typedef enum {
    CLB_INT_TAG_0 = 0U,    /*!< CLB Interrupt Tag 0 */
    CLB_INT_TAG_1,         /*!< CLB Interrupt Tag 1 */
    CLB_INT_TAG_2,         /*!< CLB Interrupt Tag 2 */
    CLB_INT_TAG_3,         /*!< CLB Interrupt Tag 3 */
} CLB_InterruptTags;

/**
  * @}
  */


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Set global enable.
  *         This function enables the CLB via global enable register.
  * \param  clb The base address of a CLB tile's logic config register.
  *              - CLB1: CLB1 base address index
  *              - CLB2: CLB2 base address index
  *              - CLB3: CLB3 base address index
  *              - CLB4: CLB4 base address index
  *              - CLB5: CLB5 base address index
  *              - CLB6: CLB6 base address index
  */
static inline void CLB_enableCLB (CLB_TypeDef *clb)
{
    MODIFY_REG(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M, CLB_LOADEN_GBLEN_M);
}

/**
  * \brief  Clear global enable.
  *         This function disables the CLB via global enable register.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableCLB (CLB_TypeDef *clb)
{
    CLEAR_BIT(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M | CLB_LOADEN_GBLEN_M);
}

/**
  * \brief  Enable HLC NMI.
  *         This function enables the CLB HLC NMI.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableNMI (CLB_TypeDef *clb)
{
    MODIFY_REG(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M, CLB_LOADEN_NMIEN_M);
}

/**
  * \brief  Disable HLC NMI.
  *         This function disables the CLB HLC NMI.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableNMI (CLB_TypeDef *clb)
{
    CLEAR_BIT(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M | CLB_LOADEN_NMIEN_M);
}

/**
  * \brief  Configure Clock Prescalar.
  *         This function enables and configures the CLB Clock Precalar.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  */
static inline void CLB_configureClockPrescalar (CLB_TypeDef *clb, uint16_t prescl)
{
    WRITE_REG(clb->PRESCALECTRL.BIT.PRESCALE, (uint32_t)prescl);
    WRITE_REG(clb->PRESCALECTRL.BIT.CLKEN, ENABLE);
}

/**
  * \brief  Configures Clock Precalar Strobe Mode.
  *         This function enables and configures the CLB Clock Precalar Strobe Mode.
  * \param  clb     The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  * \param  strb    The value of TAP, which select one of the 16 register bit position of
  *                 the counter as the output.
  */
static inline void CLB_configureStrobeMode (CLB_TypeDef *clb, uint16_t strb)
{
    WRITE_REG(clb->PRESCALECTRL.BIT.TAP, strb);
    WRITE_REG(clb->PRESCALECTRL.BIT.STRB, ENABLE);
}

/**
  * \brief  Configures the general purpose SW release control value.
  *         This function configures the general purpose SW release control value.
  * \param  clb     The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  * \param  inID    The specified CLB SW Release input signal.
  *                 This parameter can have one enumeration value from
  *                 @ref CLB_SWReleaseCtrl.
  * \param  val     The value of the SW RLS control.
  */
static inline void CLB_writeSWReleaseControl (CLB_TypeDef *clb,
                                              CLB_SWReleaseCtrl inID, bool val)
{
    MODIFY_REG( clb->GPREG.WORDVAL,
                CLB_GPREG_SWRC0_M << (uint32_t)inID,
                val << (CLB_GPREG_SWRC0_S + (uint32_t)inID));
}

/**
  * \brief  Configures the general purpose SW gate control value.
  *         This function configures the general purpose SW gate control value.
  * \param  clb     The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  * \param  inID    The specified CLB SW Release input signal.
  *                 This parameter can have one enumeration value from @ref CLB_SWGateCtrl.
  * \param  val     The value of the SW GATE control.
  */
static inline void CLB_writeSWGateControl (CLB_TypeDef *clb,
                                           CLB_SWGateCtrl inID, bool val)
{
    MODIFY_REG(clb->GPREG.WORDVAL,
               CLB_GPREG_SWGC0_M << (uint32_t)inID,
               val << (CLB_GPREG_SWGC0_S + (uint32_t)inID));
}

/**
  * \brief  Configures Counter TAP Selects.
  *         This function configures the counter tap selects.
  * \param  clb       The base address of a CLB tile's logic config register.
  *                    - CLB1: CLB1 base address index
  *                    - CLB2: CLB2 base address index
  *                    - CLB3: CLB3 base address index
  *                    - CLB4: CLB4 base address index
  *                    - CLB5: CLB5 base address index
  *                    - CLB6: CLB6 base address index
  * \param  tapSel    The value to represent counter tap selects.
  */
static inline void CLB_configCounterTapSelects (CLB_TypeDef *clb, uint32_t tapSel)
{
    WRITE_REG(clb->COUNT01MATCHTAPSEL.WORDVAL, tapSel);
}

/**
  * \brief  Configures AOC (Asynchronous Output Conditioning) functions.
  *         This function configures the input signals and equations of the aoc LUT
  *         corresponding to the \e aocID parameter.
  * \param  clb       The base address of a CLB tile's logic config register.
  *                    - CLB1: CLB1 base address index
  *                    - CLB2: CLB2 base address index
  *                    - CLB3: CLB3 base address index
  *                    - CLB4: CLB4 base address index
  *                    - CLB5: CLB5 base address index
  *                    - CLB6: CLB6 base address index
  * \param  aocID     The specified CLB tile AOC signal.
  *                   This parameter can have one enumeration value from @ref CLB_AOCs
  * \param  aocCfg    The value for the AOC signal function and input signal selections.
  */
static inline void CLB_configAOC (CLB_TypeDef *clb, CLB_AOCs aocID,
                                     uint32_t aocCfg)
{
    WRITE_REG(clb->OUTPUTCONDCTRLX[(uint32_t)aocID].WORDVAL, aocCfg);
}

/**
  * \brief  Enable CLB lock.
  *         This function enables the lock bit of the lock register. The lock can only
  *         be set once and can only be cleared by a device reset.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableLock (CLB_TypeDef *clb)
{
    /* Setting the lock bit requires key 0x5A5A to be written at the same time */
    WRITE_REG(clb->LOCK.WORDVAL, ((uint32_t)CLB_LOCK_KEY << CLB_LOCK_KEY_S) | CLB_LOCK_LOCK_M);
}

/**
  * \brief  Write value to address.
  *         This function writes the specified value to CLB internal memory.
  * \param  clb        The base address of a CLB tile's logic config register.
  *                     - CLB1: CLB1 base address index
  *                     - CLB2: CLB2 base address index
  *                     - CLB3: CLB3 base address index
  *                     - CLB4: CLB4 base address index
  *                     - CLB5: CLB5 base address index
  *                     - CLB6: CLB6 base address index
  * \param  address    The address of CLB internal memory.
  * \param  value      The value to write to specified address.
  */
static inline void CLB_writeInterface (CLB_TypeDef *clb, uint32_t address,
                                      uint32_t value)
{
    WRITE_REG(clb->LOADADDR.WORDVAL, address);
    WRITE_REG(clb->LOADDATA.WORDVAL, value);
    MODIFY_REG(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M, CLB_LOADEN_LOADEN_M);
}

/**
  * \brief  Select input filter type.
  *         This function configures the filter selection for the specified input.
  * \param  clb           The base address of a CLB tile's logic config register.
  *                        - CLB1: CLB1 base address index
  *                        - CLB2: CLB2 base address index
  *                        - CLB3: CLB3 base address index
  *                        - CLB4: CLB4 base address index
  *                        - CLB5: CLB5 base address index
  *                        - CLB6: CLB6 base address index
  * \param  inID          The specified CLB tile input signal.
  *                       This parameter can have one enumeration value from @ref CLB_Inputs.
  * \param  filterType    The selected type of filter applied to the input.
  *                       This parameter can have one enumeration value from @ref CLB_FilterType.
  */
static inline void CLB_selectInputFilter (CLB_TypeDef *clb, CLB_Inputs inID,
                                          CLB_FilterType filterType)
{
    uint16_t shiftVal;

    /* Each input has a 2-bit field in this register so need to calculate
    shift amount accordingly. */
    shiftVal = (uint16_t)inID << 1;
    MODIFY_REG(clb->INPUTFILTER.WORDVAL,
               CLB_INPUTFILTER_FIN0_M << shiftVal,
               (uint16_t)filterType << shiftVal);
}

/**
  * \brief  Enables synchronization of an input signal.
  *         This function enables synchronization on the specified input signal.
  * \param  clb     The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  * \param  inID    The specified CLB tile input signal.
  *                 This parameter can have one enumeration value from @ref CLB_Inputs.
  */
static inline void CLB_enableSynchronization (CLB_TypeDef *clb, CLB_Inputs inID)
{
    SET_BIT(clb->INPUTFILTER.WORDVAL, CLB_INPUTFILTER_SYNC0_M << (uint16_t)inID);
}

/**
  * \brief  Disables synchronization of an input signal.
  *         This function disables synchronization on the specified input signal.
  * \param  clb     The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  * \param  inID    The specified CLB tile input signal.
  *                 This parameter can have one enumeration value from CLB_Inputs.
  */
static inline void CLB_disableSynchronization (CLB_TypeDef *clb, CLB_Inputs inID)
{
    CLEAR_BIT(clb->INPUTFILTER.WORDVAL, CLB_INPUTFILTER_SYNC0_M << (uint16_t)inID);
}

/**
  * \brief  Configures the general purpose input mux.
  *         This function configures the general purpose input mux. The \e gpMuxCfg
  *         parameter can select either the use of an external input signal
  *         or the use of the corresponding CLB_GP_REG bit as an input.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB1 base address index
  *                      - CLB3: CLB1 base address index
  *                      - CLB4: CLB1 base address index
  *                      - CLB5: CLB1 base address index
  *                      - CLB6: CLB1 base address index
  * \param  inID        The specified CLB tile input signal.
  *                     This parameter can have one enumeration value from @ref CLB_Inputs.
  * \param  gpMuxCfg    The mux selection for the general purpose input mux.
  *                     This parameter can have one enumeration value from @ref CLB_GPInputMux
  * 
  * \sa CLB_setGPREG() to write to the CLB_GP_REG.
  */
static inline void CLB_configGPInputMux (CLB_TypeDef *clb, CLB_Inputs inID,
                                         CLB_GPInputMux gpMuxCfg)
{
    MODIFY_REG(clb->INMUXSEL0.WORDVAL,
               CLB_INMUXSEL0_SELGPIN0_M << (uint16_t)inID,
               (uint16_t)gpMuxCfg << (uint16_t)inID);
}

/**
  * \brief  Sets the CLB_GP_REG register value.
  *         This function writes to the CLB_GP_REG register. When the general purpose
  *         input mux is configured to use CLB_GP_REG, each bit in \e gpRegVal
  *         corresponds to an input signal (bit 0 to Input 0, bit 1 to Input 1, and
  *         so on).
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  gpRegVal    The value to be written to CLB_GP_REG.
  * 
  * \sa     CLB_configGPInputMux() to select the CLB_GP_REG as the source for
  *         an input signal.
  */
static inline void CLB_setGPREG (CLB_TypeDef *clb, uint32_t gpRegVal)
{
    WRITE_REG(clb->GPREG.WORDVAL, gpRegVal);
}

/**
  * \brief  Gets the CLB_GP_REG register value.
  *         This function writes to the CLB_GP_REG register. When the general purpose
  *         input mux is configured to use CLB_GP_REG, each bit in \e gpRegVal
  *         corresponds to an input signal (bit 0 to Input 0, bit 1 to Input 1, and
  *         so on).
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB1 base address index
  *                      - CLB3: CLB1 base address index
  *                      - CLB4: CLB1 base address index
  *                      - CLB5: CLB1 base address index
  *                      - CLB6: CLB1 base address index
  * \return CLB_GP_REG value.
  * 
  * \sa CLB_configGPInputMux() to select the CLB_GP_REG as the source for
  * an input signal.
  */
static inline uint32_t CLB_getGPREG (CLB_TypeDef *clb)
{
    return(clb->GPREG.WORDVAL);
}

/**
  * \brief  Configures the local input mux.
  *         This function configures the local input mux for the specified input
  *         signal.
  * \note   The local input mux options' peripheral sources depend on which
  *         instance of the \e clb you are using. For example, for CLB1 the
  *         EPWM signal selections come from EPWM1 but for CLB2 they come from EPWM2.
  *         See your technical reference manual for details.
  * \param  clb            The base address of a CLB tile's logic config register.
  *                         - CLB1: CLB1 base address index
  *                         - CLB2: CLB1 base address index
  *                         - CLB3: CLB1 base address index
  *                         - CLB4: CLB1 base address index
  *                         - CLB5: CLB1 base address index
  *                         - CLB6: CLB1 base address index
  * \param  inID           The specified CLB tile input signal.
  *                        This parameter can have one enumeration value from @ref CLB_Inputs.
  * \param  localMuxCfg    The mux selection for the local input mux.
  *                        This parameter can have one enumeration value from @ref CLB_LocalInputMux.
  */
static inline void CLB_configLocalInputMux (CLB_TypeDef *clb, CLB_Inputs inID,
                                            CLB_LocalInputMux localMuxCfg)
{
    uint8_t offset_mul;
    uint16_t shiftVal;
    uint32_t miscShiftVal, inputMuxSel;
    __IO uint32_t *reg;

    if (inID < CLB_IN4)
    {
        offset_mul = inID;
        reg = &clb->LCLMUXSEL1.WORDVAL;
    }
    else
    {
        offset_mul = inID - 4;
        reg = &clb->LCLMUXSEL2.WORDVAL;
    }
    
    /* Each local input has a 5-bit field in this register so need to calculate
    shift amount accordingly. */

    shiftVal = offset_mul * CLB_LCLMUXSEL1_LCLMUXSELIN1_S;


    /* If the local inputs are selected then only 5-bits are used in this
    register but if miscellaneous inputs are selected then another 1-bit is
    used along with the above 5. So we need to calculate this accordingly. */

    /* Each miscellaneous input has a 1-bit field in this register so
    need to calculate shift amount accordingly. */

    miscShiftVal = offset_mul + CLB_LCLMUXSEL_MISCINPUTSEL_S;


    /* Each miscellaneous input has an extra 1-bit to be set
    apart from the local input bits */
    
    inputMuxSel =
        ((((uint32_t)localMuxCfg & CLB_LCLMUXSEL1_LCLMUXSELIN0_M) << shiftVal) |
        ((((uint32_t)localMuxCfg & CLB_LOCALINPUTMUX_MISCINPUTSEL_M)
            >> CLB_LOCALINPUTMUX_MISCINPUTSEL_S)
            << miscShiftVal));

        /* Update the local / misc input mux selections */
        MODIFY_REG(
            *reg,
            ((uint32_t)CLB_LCLMUXSEL1_LCLMUXSELIN0_M << shiftVal) | 
            ((CLB_LOCALINPUTMUX_MISCINPUTSEL_M >> CLB_LOCALINPUTMUX_MISCINPUTSEL_S) << miscShiftVal),
            inputMuxSel
        );
}

/**
  * \brief  Configures the global input mux.
  *         This function configures the global input mux for the specified input
  *         signal.
  * \note   The global input mux options' peripheral sources depend on which
  *         instance of the \e clb you are using. For example, for CLB1 the
  *         EPWM signal selections come from EPWM1 but for CLB2 they come from EPWM2.
  *         See your technical reference manual for details.
  * \param  clb     The base address of a CLB tile's logic config register.
  *                  - CLB1: CLB1 base address index
  *                  - CLB2: CLB2 base address index
  *                  - CLB3: CLB3 base address index
  *                  - CLB4: CLB4 base address index
  *                  - CLB5: CLB5 base address index
  *                  - CLB6: CLB6 base address index
  * \param  inID    The specified CLB tile input signal.
  *                 This parameter can have one enumeration value from @ref CLB_Inputs.
  * \param  globalMuxCfg 
  *                 The mux selection for the global input mux.
  *                 This parameter can have one enumeration value from @ref CLB_GlobalInputMux.
  */
static inline void CLB_configGlobalInputMux (CLB_TypeDef *clb, CLB_Inputs inID,
                                             CLB_GlobalInputMux globalMuxCfg)
{
    uint8_t offset_mul;
    uint16_t shiftVal;
    __IO uint32_t *reg;

    /* Each input has a 5-bit field in this register so need to calculate
    shift amount accordingly. */
    if (inID < CLB_IN4)
    {
        offset_mul = (uint8_t)inID;
        reg = &clb->GLBLMUXSEL1.WORDVAL;
    }
    else
    {
        offset_mul = (uint8_t)inID - 4;
        reg = &clb->GLBLMUXSEL2.WORDVAL;
    }
    
    shiftVal = offset_mul * CLB_GLBLMUXSEL1_GLBLMUXSELIN1_S;

    MODIFY_REG(
        *reg,
        (uint32_t)CLB_GLBLMUXSEL1_GLBLMUXSELIN0_M << shiftVal,
        (uint32_t)globalMuxCfg << shiftVal
    );

}

/**
  * \brief  Controls the output enable.
  *         This function is used to enable and disable CLB outputs by writing a mask
  *         to CLB_OUT_EN. Each bit corresponds to a CLB output. When a bit is 1, the
  *         corresponding output is enabled; when a bit is 0, the output is disabled.
  * 
  * \note   Note that the 8 CLB outputs are replicated to create more output
  *         paths. See your technical reference manual for more details.
  *         If no further modifications are expected, then it is advised to set the
  *         block writes bit of the MISC_ACCESS_CTRL Register. This will prevent
  *         accidental writes.
  * \param  clb           The base address of a CLB tile's logic config register.
  *                        - CLB1: CLB1 base address index
  *                        - CLB2: CLB2 base address index
  *                        - CLB3: CLB3 base address index
  *                        - CLB4: CLB4 base address index
  *                        - CLB5: CLB5 base address index
  *                        - CLB6: CLB6 base address index
  * \param  outputMask    The mask of the outputs to be enabled.
  *                       This parameter takes a logical OR of any of the @ref CLB_OUTPUT_MASK
  *                       values that correspond to the CLB OUTPUT ENABLE for the respective outputs.
  * \param  enable        A switch to decide if the CLB outputs need to be enabled or not.
  *                       This parameter can have one of the values from:
  *                        - false: Disable the respective CLB outputs
  *                        - true: Enable the respective CLB outputs
  */
static inline void CLB_setOutputMask (CLB_TypeDef *clb, uint32_t outputMask ,
                                      bool enable)
{
    if(enable == true)
    {
        SET_BIT(clb->OUTEN.WORDVAL, outputMask);
    }
    else
    {
        CLEAR_BIT(clb->OUTEN.WORDVAL, outputMask);
    }
}

/**
  * \brief  Enable the interrupts.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \param  interruptSource
  *                This parameter takes a logical OR of any of the @ref CLB_INTERRUPTS
  *                values that correspond to the CLB Interrupts.
  */
static inline void CLB_enableInterrupt (CLB_TypeDef *clb, uint32_t interruptSource)
{
    SET_BIT(clb->SRCTRL.WORDVAL, interruptSource);
}

/**
  * \brief  Disable the interrupts.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \param  interruptSource
  *                This parameter takes a logical OR of any of the @ref CLB_INTERRUPTS
  *                values that correspond to the CLB Interrupts.
  */
static inline void CLB_disableInterrupt (CLB_TypeDef *clb, uint32_t interruptSource)
{
    CLEAR_BIT(clb->SRCTRL.WORDVAL, interruptSource);
}

/**
  * \brief  Reads the interrupt tag register.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \return Returns the value in the interrupt tag register which is a 6-bit
  *         constant set by the HLC.
  */
static inline uint16_t CLB_getInterruptTag (CLB_TypeDef *clb)
{
    return READ_REG(clb->INTRTAGREG.WORDVAL);
}

/**
  * \brief  Clears the interrupt tag register.
  *         This function clears the interrupt tag register, setting it to 0.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_clearInterruptTag (CLB_TypeDef *clb, CLB_InterruptTags interruptTagID)
{
    CLEAR_BIT(clb->INTRTAGREG.WORDVAL, 0x3FU << interruptTagID);
    WRITE_REG(clb->SRCLR.WORDVAL, 1U << (4U + (uint32_t) interruptTagID));
}

/**
  * \brief  Selects LUT4 inputs.
  *         This function configures the LUT4 block's input signals.
  * \param  clb        The base address of a CLB tile's logic config register.
  *                     - CLB1: CLB1 base address index
  *                     - CLB2: CLB2 base address index
  *                     - CLB3: CLB3 base address index
  *                     - CLB4: CLB4 base address index
  *                     - CLB5: CLB5 base address index
  *                     - CLB6: CLB6 base address index
  * \param  lut4In0    The value for LUT4 input signal 0.
  * \param  lut4In1    The value for LUT4 input signal 1.
  * \param  lut4In2    The value for LUT4 input signal 2.
  * \param  lut4In3    The value for LUT4 input signal 3.
  */
static inline void CLB_selectLUT4Inputs (CLB_TypeDef *clb, uint32_t lut4In0,
                                         uint32_t lut4In1, uint32_t lut4In2,
                                         uint32_t lut4In3)
{
    WRITE_REG(clb->LUT4INX[0].WORDVAL, lut4In0);
    WRITE_REG(clb->LUT4INX[1].WORDVAL, lut4In1);
    WRITE_REG(clb->LUT4INX[2].WORDVAL, lut4In2);
    WRITE_REG(clb->LUT4INX[3].WORDVAL, lut4In3);
}

/**
  * \brief  Configures LUT4 functions.
  *         This function configures the LUT4 block's equations.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  lut4Fn10    The equation value for LUT4 blocks 0 and 1.
  * \param  lut4Fn2     The equation value for LUT4 block2.
  */
static inline void CLB_configLUT4Function (CLB_TypeDef *clb, uint32_t lut4Fn10,
                                           uint32_t lut4Fn2)
{
    WRITE_REG(clb->LUT4FN.WORDVAL, lut4Fn10);
    WRITE_REG(clb->LUT4FN2.WORDVAL, lut4Fn2);
}

/**
  * \brief  Selects FSM inputs.
  *         This function configures the FSM block's external inputs and extra external
  *         inputs.
  * \param  clb          The base address of a CLB tile's logic config register.
  *                       - CLB1: CLB1 base address index
  *                       - CLB2: CLB2 base address index
  *                       - CLB3: CLB3 base address index
  *                       - CLB4: CLB4 base address index
  *                       - CLB5: CLB5 base address index
  *                       - CLB6: CLB6 base address index
  * \param  external0    The value for FSM external 0 input.
  * \param  external1    The value for FSM external 1 input.
  * \param  extra0       The value for FSM extra 0 input.
  * \param  extra1       The value for FSM extra 1 input.
  */
static inline void CLB_selectFSMInputs (CLB_TypeDef *clb, uint32_t external0,
                                        uint32_t external1, uint32_t extra0,
                                        uint32_t extra1)
{
    WRITE_REG(clb->FSMEXTERNALINX[0].WORDVAL, external0);
    WRITE_REG(clb->FSMEXTERNALINX[1].WORDVAL, external1);
    WRITE_REG(clb->FSMEXTRAIN0.WORDVAL, extra0);
    WRITE_REG(clb->FSMEXTRAIN1.WORDVAL, extra1);
}

/**
  * \brief  Configures FSM LUT function.
  *         This function configures the FSM block's LUT equations.
  * \param  clb           The base address of a CLB tile's logic config register.
  *                        - CLB1: CLB1 base address index
  *                        - CLB2: CLB2 base address index
  *                        - CLB3: CLB3 base address index
  *                        - CLB4: CLB4 base address index
  *                        - CLB5: CLB5 base address index
  *                        - CLB6: CLB6 base address index
  * \param  fsmLutFn10    The value for FSM 0 & FSM 1 LUT function.
  * \param  fsmLutFn2     The value for FSM 2 LUT function.
  */
static inline void CLB_configFSMLUTFunction (CLB_TypeDef *clb, uint32_t fsmLutFn10,
                                             uint32_t fsmLutFn2)
{
    WRITE_REG(clb->FSMLUTFN.WORDVAL, fsmLutFn10);
    WRITE_REG(clb->FSMLUTFN2.WORDVAL, fsmLutFn2);
}

/**
  * \brief  Configures FSM next state.
  *         This function configures the FSM's next state equation.
  * \param  clb           The base address of a CLB tile's logic config register.
  *                        - CLB1: CLB1 base address index
  *                        - CLB2: CLB2 base address index
  *                        - CLB3: CLB3 base address index
  *                        - CLB4: CLB4 base address index
  *                        - CLB5: CLB5 base address index
  *                        - CLB6: CLB6 base address index
  * \param  nextState0    The value for FSM 0's next state.
  * \param  nextState1    The value for FSM 1's next state. 
  * \param  nextState2    The value for FSM 2's next state.
  */
static inline void CLB_configFSMNextState (CLB_TypeDef *clb, uint32_t nextState0,
                                           uint32_t nextState1,
                                           uint32_t nextState2)
{
    WRITE_REG(clb->FSMNEXTSTATEX[0].WORDVAL, nextState0);
    WRITE_REG(clb->FSMNEXTSTATEX[1].WORDVAL, nextState1);
    WRITE_REG(clb->FSMNEXTSTATEX[2].WORDVAL, nextState2);
}

/**
  * \brief  Selects Counter inputs.
  *         This function selects the input signals to the counter block.
  * \param  clb      The base address of a CLB tile's logic config register.
  *                   - CLB1: CLB1 base address index
  *                   - CLB2: CLB2 base address index
  *                   - CLB3: CLB3 base address index
  *                   - CLB4: CLB4 base address index
  *                   - CLB5: CLB5 base address index
  *                   - CLB6: CLB6 base address index
  * \param  reset    The value for counter's reset inputs.
  * \param  event    The value for counter's event inputs.
  * \param  mode0    The value for counter's mode 0 inputs.
  * \param  mode1    The value for counter's mode 1 inputs.
  */
static inline void CLB_selectCounterInputs (CLB_TypeDef *clb, uint32_t reset,
                                            uint32_t event, uint32_t mode0,
                                            uint32_t mode1)
{
    WRITE_REG(clb->CNTRST.WORDVAL, reset);
    WRITE_REG(clb->CNTENT.WORDVAL, event);
    WRITE_REG(clb->CNTMDX[0].WORDVAL, mode1);
    WRITE_REG(clb->CNTMDX[1].WORDVAL, mode0);
}

/**
  * \brief  Configures Counter and FSM modes.
  * \note   This function configures the counter mode, particularly add/shift, load
  *         modes. The function also configures whether the FSM should use state inputs
  *         or an extra external input.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  miscCtrl    The value to represent counter and FSM modes.
  */
static inline void CLB_configMiscCtrlModes (CLB_TypeDef *clb, uint32_t miscCtrl)
{
    WRITE_REG(clb->MISCCONTROL.WORDVAL, miscCtrl);
}

/**
  * \brief  Configures Output LUT functions.
  *         This function configures the input signals and equations of the output LUT
  *         corresponding to the \e outID parameter.
  * \param  clb          The base address of a CLB tile's logic config register.
  *                       - CLB1: CLB1 base address index
  *                       - CLB2: CLB2 base address index
  *                       - CLB3: CLB3 base address index
  *                       - CLB4: CLB4 base address index
  *                       - CLB5: CLB5 base address index
  *                       - CLB6: CLB6 base address index
  * \param  outID        The specified CLB tile output signal.
  * \param  outputCfg    The value for the output LUT signal function and input signal selections.
  */
static inline void CLB_configOutputLUT (CLB_TypeDef *clb, CLB_Outputs outID,
                                       uint32_t outputCfg)
{
    WRITE_REG(clb->OUTPUTLUTX[outID].WORDVAL, outputCfg);
}

/**
  * \brief  Configures HLC event selection.
  *         This function configures the event selection for the High Level Controller.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  eventSel    The value for HLC event selection.
  */
static inline void CLB_configHLCEventSelect (CLB_TypeDef *clb, uint32_t eventSel)
{
    WRITE_REG(clb->HLCEVENTSEL.WORDVAL, eventSel);
}

/**
  * \brief  Program HLC instruction.
  *         This function configures the CLB internal memory corresponding to the
  *         specified HLC instruction number with the given instruction.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \param  instructionNum
  *                The index into the HLC instruction memory. For example, a value of
  *                0 corresponds to instruction 0 of event 0, a value of 1 corresponds
  *                to instruction 1 of event 0, and so on up to a value of 31 which
  *                corresponds to instruction 7 of event 3.
  * \param  instruction
  *                The instruction to be programmed.
  */
static inline void CLB_programHLCInstruction (CLB_TypeDef *clb,
                                              uint32_t instructionNum,
                                              uint32_t instruction)
{
    CLB_writeInterface(clb, CLB_ADDR_HLC_BASE + instructionNum, instruction);
}

/**
  * \brief  Set HLC registers.
  *         This function configures the CLB internal memory corresponding to the HLC
  *         registers R0-R3 with the specified values.
  * \param  clb       The base address of a CLB tile's logic config register.
  *                    - CLB1: CLB1 base address index
  *                    - CLB2: CLB2 base address index
  *                    - CLB3: CLB3 base address index
  *                    - CLB4: CLB4 base address index
  *                    - CLB5: CLB5 base address index
  *                    - CLB6: CLB6 base address index
  * \param  r0Init    The value to write to HLC register R0.
  * \param  r1Init    The value to write to HLC register R1.
  * \param  r2Init    The value to write to HLC register R2.
  * \param  r3Init    The value to write to HLC register R3.
  */
static inline void CLB_setHLCRegisters (CLB_TypeDef *clb, uint32_t r0Init,
                                        uint32_t r1Init, uint32_t r2Init,
                                        uint32_t r3Init)
{
    CLB_writeInterface(clb, CLB_ADDR_HLC_R0, r0Init);
    CLB_writeInterface(clb, CLB_ADDR_HLC_R1, r1Init);
    CLB_writeInterface(clb, CLB_ADDR_HLC_R2, r2Init);
    CLB_writeInterface(clb, CLB_ADDR_HLC_R3, r3Init);
}

/**
  * \brief  Get HLC or counter register values.
  * \param  clb           The base address of a CLB tile's logic config register.
  *                        - CLB1: CLB1 base address index
  *                        - CLB2: CLB2 base address index
  *                        - CLB3: CLB3 base address index
  *                        - CLB4: CLB4 base address index
  *                        - CLB5: CLB5 base address index
  *                        - CLB6: CLB6 base address index
  * \param  registerID    The internal register from which to read. Can be
  *                       either an HLC register ( \b CLB_REG_HLC_Rn ) or a counter value
  *                       ( \b CLB_REG_CTR_Cn ). This parameter can have one enumeration 
  *                       value from @ref CLB_Register.
  * \return Returns the value in the specified HLC register or counter.
  */
static inline uint32_t CLB_getRegister (CLB_TypeDef *clb, CLB_Register registerID)
{
    return(READ_REG(*(uint32_t*)((uint32_t)clb + (uint32_t)registerID)));
}

/**
  * \brief  Get output status.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \return Returns the output status of various components within the CLB tile
  *         such as a counter match or LUT output. Use the \b CLB_DBGOUT_*_M
  *         masks from <tt>NS800RT7xxx.h</tt> to decode the bits.
  */
static inline uint32_t CLB_getOutputStatus (CLB_TypeDef *clb)
{
    return(READ_REG(*(uint32_t*)((uint32_t)clb + CLB_OFFSET_DEBUG_OUT)));
}

/**
  * \brief  Enable CLB Pipeline Mode.
  * \note   This function enables the CLB Pipeline Mode
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enablePipelineMode (CLB_TypeDef *clb)
{
    MODIFY_REG(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M, CLB_LOADEN_PLEN_M);
}

/**
  * \brief  Disable CLB Pipeline Mode.
  *         This function disables the CLB Pipeline Mode.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disablePipelineMode (CLB_TypeDef *clb)
{
    CLEAR_BIT(clb->LOADEN.WORDVAL, CLB_LOADEN_INTR0TRIG_M | CLB_LOADEN_PLEN_M);
}

/**
  * \brief  Disable CLB Output Mask Updates.
  * \note   This function disables the CLB Output Mask updates
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableOutputMaskUpdates (CLB_TypeDef *clb)
{
    SET_BIT(clb->MISCACCESSCTRL.WORDVAL, CLB_MISCACCESSCTRL_BLKEN_M);
}

/**
  * \brief  Enable CLB Output Mask Updates.
  * \note   This function enables the CLB Output Mask updates
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableOutputMaskUpdates (CLB_TypeDef *clb)
{
    CLEAR_BIT(clb->MISCACCESSCTRL.WORDVAL, CLB_MISCACCESSCTRL_BLKEN_M);
}

/**
  * \brief  Enable Input Pipeline Mode.
  * \note   This function enables the CLB Input Pipeline mode
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableInputPipelineMode (CLB_TypeDef *clb, CLB_Inputs inID)
{
    SET_BIT(clb->INPUTFILTER.WORDVAL, CLB_INPUTFILTER_PIPE0_M << (uint32_t)inID);
}

/**
  * \brief  Disable Input Pipeline Mode.
  * \note   This function disables the CLB Input Pipeline mode
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableInputPipelineMode (CLB_TypeDef *clb, CLB_Inputs inID)
{
    CLEAR_BIT(clb->INPUTFILTER.WORDVAL, CLB_INPUTFILTER_PIPE0_M << (uint32_t)inID);
}


/**
  * \brief  Disable DataFIFO Access.
  * \note   This function disables the CLB DataFIFO access.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableDataFIFOAccess (CLB_TypeDef *clb)
{
    WRITE_REG(clb->MISCACCESSCTRL.BIT.RXFIFOEN, DISABLE);
}


/**
  * \brief  Enable DataFIFO Access.
  * \note   This function enables the CLB DataFIFO access.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableDataFIFOAccess (CLB_TypeDef *clb)
{
    WRITE_REG(clb->MISCACCESSCTRL.BIT.RXFIFOEN, ENABLE);
}

/**
  * \brief  Configures SPI RX Buffer Load Signal event selection.
  * \note   This function configures the event selection for the SPI RX Buffer.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  eventSel    The value for HLC event selection.
  */
static inline void CLB_configDataFIFOLoadSignal (CLB_TypeDef *clb, uint16_t eventSel)
{
    WRITE_REG(clb->SPIDATACTRLHI.BIT.STRB, eventSel);
}

/**
  * \brief  Configures SPI Export HLC R0 Shift value.
  * \note   This function configures the SPI Export HLC R0 Shift value.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  shiftVal    The value for SPI export HLC R0 bit range selection.
  */
static inline void CLB_configDataFIFOLoadShift (CLB_TypeDef *clb, uint16_t shiftVal)
{
    WRITE_REG(clb->SPIDATACTRLHI.BIT.SHIFT, shiftVal);
}

/**
  * \brief  CPU interface pull a Data from DataFIFO.
  *         This function reads a word from the DataFIFO.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \return Return a value pulled from CLB DataFIFO
  */
static inline uint32_t CLB_readDataFIFO (CLB_TypeDef *clb)
{
    return READ_REG(clb->DATAFIFO.WORDVAL);
}

/**
  * \brief  Write a word into PULL FIFO.
  *         This function writes the PULL FIFO.
  * \param  clb       The base address of a CLB tile's logic config register.
  *                    - CLB1: CLB1 base address index
  *                    - CLB2: CLB2 base address index
  *                    - CLB3: CLB3 base address index
  *                    - CLB4: CLB4 base address index
  *                    - CLB5: CLB5 base address index
  *                    - CLB6: CLB6 base address index
  * \param  dataVal   The value to write.
  */
static inline void CLB_writeFIFO (CLB_TypeDef *clb, uint32_t dataVal)
{
    WRITE_REG(clb->PULL.WORDVAL, dataVal);
}

/**
  * \brief  Read a word from PUSH FIFO.
  *         This function reads the PUSH FIFO.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * \return Return a value read from PUSH FIFO
  */
static inline uint32_t CLB_readFIFO (CLB_TypeDef *clb)
{
    return READ_REG(clb->PUSH.WORDVAL);
}

/**
  * \brief  Disable Overflow and Underflow detection for PUSH/PULL FIFO
  *         This function disables PUSH/PULL FIFO Overflow and Underflow detection.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableFIFOsOverFlowDetection (CLB_TypeDef *clb)
{
    MODIFY_REG(clb->LOADEN.WORDVAL,
        CLB_LOADEN_INTR0TRIG_M,
        CLB_LOADEN_PUSHOUDIS_M | CLB_LOADEN_PULLOUDIS_M);
}

/**
  * \brief  Enable Overflow and Underflow detection for PUSH/PULL FIFO
  *         This function enables PUSH/PULL FIFO Overflow and Underflow detection.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableFIFOsOverFlowDetection (CLB_TypeDef *clb)
{
    CLEAR_BIT(clb->LOADEN.WORDVAL,
        CLB_LOADEN_INTR0TRIG_M | CLB_LOADEN_PUSHOUDIS_M | CLB_LOADEN_PULLOUDIS_M);
}

/**
  * \brief  Enable MultiTAG Function.
  *         This function enables MultiTAG Function, Which means Each HLC Event corresponds to a TAG.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_enableMultiTAG (CLB_TypeDef *clb)
{
    WRITE_REG(clb->NEWCFG.BIT.HLCTAGOPT, ENABLE);
}

/**
  * \brief  Disable MultiTAG Function.
  *         This function Disable MultiTAG Function, Which means All HLC Events corresponds to One TAG.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  */
static inline void CLB_disableMultiTAG (CLB_TypeDef *clb)
{
    WRITE_REG(clb->NEWCFG.BIT.HLCTAGOPT, DISABLE);
}

/**
  * \brief  Configures Counter load and match.
  *         This function configures the CLB internal memory corresponding to the
  *         counter block's load and match values.
  * \param  clb          The base address of a CLB tile's logic config register.
  *                       - CLB1: CLB1 base address index
  *                       - CLB2: CLB2 base address index
  *                       - CLB3: CLB3 base address index
  *                       - CLB4: CLB4 base address index
  *                       - CLB5: CLB5 base address index
  *                       - CLB6: CLB6 base address index
  * \param  counterID    The specified counter unit.
  * \param  load         The value for counter's load mode.
  * \param  match1       The value for counter's match 1.
  * \param  match2       The value for counter's match 2.
  */
extern void CLB_configCounterLoadMatch (CLB_TypeDef *clb, CLB_Counters counterID,
                                        uint32_t load, uint32_t match1, uint32_t match2);

/**
  * \brief  Clear FIFO registers.
  *         This function clears the PUSH/PULL FIFOs as well as its pointers.
  * \param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * 
  * \attention      Accessing PUSH/PULL FIFO by PUSHX/PULLX register MUST
  *                 disable \e Overflow-and-Underflow-detection ,
  *                 @ref CLB_disableFIFOsOverFlowDetection()
  */
extern void CLB_clearFIFOs (CLB_TypeDef *clb);

/**
  * \brief  Configure the FIFO registers.
  *         This function writes to the PULL FIFO. This also clears the FIFOs and
  *         its pointer using the CLB_clearFIFOs() API prior to writing to
  *         the FIFO.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * \param  pullData    Pointer to an array of bytes which needs to be
  *                     written into the FIFO. The 0th FIFO data is in the 0th index.
  * 
  * \attention      Accessing PUSH/PULL FIFO by PUSHX/PULLX register MUST
  *                 disable \e Overflow-and-Underflow-detection ,
  *                 @ref CLB_disableFIFOsOverFlowDetection()
  */
extern void CLB_writeFIFOs (CLB_TypeDef *clb, const uint32_t pullData[]);

/**
  * \brief  Read FIFO registers.
  *         This function reads from the PUSH FIFO. The 0th FIFO data would be in
  *         the 0th index.
  * \param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB1 base address index
  *                      - CLB3: CLB1 base address index
  *                      - CLB4: CLB1 base address index
  *                      - CLB5: CLB1 base address index
  *                      - CLB6: CLB1 base address index
  * \param  pushData    Pointer to an array of bytes which needs to be
  *                     read from the FIFO.
  * 
  * \attention      Accessing PUSH/PULL FIFO by PUSHX/PULLX register MUST
  *                 disable \e Overflow-and-Underflow-detection ,
  *                 @ref CLB_disableFIFOsOverFlowDetection()
  */
extern void CLB_readFIFOs (CLB_TypeDef *clb, uint32_t pushData[]);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __CLB_H__ */
