/**
  * @file       NS800RT7xxx_TI_epwm.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx epwm module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_EPWM_H__
#define __NS800RT7XXX_TI_EPWM_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EPWM_EXPORTED_TI_TYPES EPWM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'EPWM' module.
  */
  
/** @defgroup EPWM_TBCTLCONF EPWM Time Base Control Register Configuration
  * @{
  * @brief  Macro definitions abou PWM time base control for the bit fields in the TBCTL register.
  */
#define EPWM_TBCTL_SWFSYNC         (0x00000040UL)    /*!< Software Force Sync Pulse */
#define EPWM_TBCTL_PRDLD           (0x00000008UL)    /*!< Active Period Load */
#define EPWM_TBCTL_PHSEN           (0x00000004UL)    /*!< Phase Load Enable */
#define EPWM_TBCTL_PHSDIR          (0x00002000UL)    /*!< Phase Direction */
#define EPWM_TBCTL_FREE_SOFT_S     (14UL)            /*!< Emulation Mode Bits shift */
#define EPWM_TBCTL_FREE_SOFT_M     (0x0000C000UL)    /*!< Emulation Mode Bits mask */
#define EPWM_TBCTL_CMP_REPAIR_S    (16UL)            /*!< Sync Load Repair Enable shift */
#define EPWM_TBCTL_CMP_REPAIR_M    (0x00010000UL)    /*!< Sync Load Repair Enable mask */
#define EPWM_TBCTL_SYNCO_SEL_S     (17UL)            /*!< EPWMSYNCOUT Register Select shift */
#define EPWM_TBCTL_SYNCO_SEL_M     (0x00020000UL)    /*!< EPWMSYNCOUT Register Select mask */
#define EPWM_TBCTL_SYNCEN_SEL_S    (18UL)            /*!< Sync Load Select shfit */
#define EPWM_TBCTL_SYNCEN_SEL_M    (0x00040000UL)    /*!< Sync Load Select mask */

/**
  * @}
  */

/** @defgroup EPWM_SYNCINSELCONF EPWM Sync In Source Select Register Configuration
  * @{
  * @brief  Macro definitions abou PWM sync in source select for the bit fields in the EPWMSYNCINSEL register.
  */
#define EPWM_SYNCINSEL_SEL_S    (0UL)             /*!< EPWMxSYNCI source select shift */
#define EPWM_SYNCINSEL_SEL_M    (0x0000001FUL)    /*!< EPWMxSYNCI source select */
#define EPWM_SYNCINSEL_SYNCSELF_M    (0x0000001FUL)    /*!< EPWMxSYNCI source select */

/**
  * @}
  */

/** @defgroup EPWM_TBCTL3CONF EPWM Time Base Control Register3 Configuration
  * @{
  * @brief  Macro definitions abou EPWM one shot sync force enable for the bit fields in the TBCTL3 register.
  */
#define EPWM_TBCTL3_OSSFRCEN    (0x00000001UL)    /*!< One Shot Sync Force Enable */

/**
  * @}
  */

/** @defgroup EPWM_TBCTL2CONF EPWM Time Base Control Register2  Configuration
  * @{
  * @brief  Macro definitions abou PWM time base control register2 configuration for the bit fields in the TBCTL2 register.
  */
#define EPWM_TBCTL2_OSHTSYNCMODE    (0x00000040UL)    /*!< One shot sync mode */
#define EPWM_TBCTL2_OSHTSYNC        (0x00000080UL)    /*!< One shot sync */
#define EPWM_TBCTL2_PRD_SHDWFULL_M    (0x00010000UL)    /*!< TBPRD Shadow Register Full */

/**
  * @}
  */

/** @defgroup EPWM_TBSTSCONF EPWM Time Base Status Register Configuration
  * @{
  * @brief  Macro definitions about PWM time base status register configuration for the bit fields in the TBSTS register.
  */
#define EPWM_TBSTS_CTRDIR    (0x00000001UL)    /*!< Counter Direction Status */
#define EPWM_TBSTS_SYNCI     (0x00000002UL)    /*!< External Input Sync Status */
#define EPWM_TBSTS_CTRMAX    (0x00000004UL)    /*!< Counter Max Latched Status */

/**
  * @}
  */

/** @defgroup EPWM_XLINKCONF EPWM Related Register Link
  * @{
  * @brief  Macro definitions about PWM related register link for the bit fields in the EPWMXLINK register.
  */
#define EPWM_XLINK_TBPRDLINK_S      (0UL)             /*!< TBPRD Link shift */
#define EPWM_XLINK_TBPRDLINK_M      (0x0000001FUL)    /*!< TBPRD Link */
#define EPWM_XLINK_CMPALINK_S       (5UL)             /*!< CMPA Link shift */
#define EPWM_XLINK_CMPALINK_M       (0x000003E0UL)    /*!< CMPA Link */
#define EPWM_XLINK_CMPBLINK_S       (10UL)             /*!< CMPB Link shift */
#define EPWM_XLINK_CMPBLINK_M       (0x00007C00UL)    /*!< CMPB Link */
#define EPWM_XLINK_CMPCLINK_S       (16UL)            /*!< CMPC Link shift */
#define EPWM_XLINK_CMPCLINK_M       (0x001F0000UL)    /*!< CMPC Link */
#define EPWM_XLINK_CMPDLINK_S       (21UL)            /*!< CMPD Link shift */
#define EPWM_XLINK_CMPDLINK_M       (0x03E00000UL)    /*!< CMPD Link */
#define EPWM_XLINK_GLDCTL2LINK_S    (26UL)            /*!< GLDCTL2 Link shift */
#define EPWM_XLINK_GLDCTL2LINK_M    (0x7C000000UL)    /*!< GLDCTL2 Link */

/**
  * @}
  */

/** @defgroup EPWM_XLINK2CONF EPWM Related Register Link
  * @{
  * @brief  Macro definitions about PWM related register link for the bit fields in the EPWMXLINK2 register.
  */
 #define EPWM_XLINK2_DBREDLINK_S      (0UL)             /*!< DBRED Link shift */
 #define EPWM_XLINK2_DBREDLINK_M      (0x0000001FUL)    /*!< DBRED Link */
 #define EPWM_XLINK2_DBFEDLINK_S      (5UL)             /*!< DBRFD Link shift */
 #define EPWM_XLINK2_DBFEDLINK_M      (0x000003E0UL)    /*!< DBRFD Link */
 #define EPWM_XLINK2_TBPRDHRLINK_S    (10UL)            /*!< TBPRDHR Link shift */
 #define EPWM_XLINK2_TBPRDHRLINK_M    (0x00007C00UL)    /*!< TBPRDHR Link */

 
 /**
   * @}
   */

/** @defgroup EPWM_AQSFRCCONF EPWM Action Qualifier Software Force Register Configuration
  * @{
  * @brief  Macro definitions about PWM  qualifier software force for the bit fields in the AQSFRC register.
  */
#define EPWM_AQSFRC_ACTSFX    (0x00000003UL)    /*!< Action when One-time SW Force X Invoked */
#define EPWM_AQSFRC_OTSFX     (0x00000001UL)    /*!< One-time SW Force X Output */

/**
  * @}
  */

/** @defgroup EPWM_AQCSFRCCONF EPWM Action Qualifier Continuous Software Force Register Configuration
  * @{
  * @brief   Macro definitions about PWM action qualifier continuous software force for the bit fields in the AQCSFRC register.
  */
#define EPWM_AQCSFRC_CSFX    (0x00000003UL)    /*!< Continuous Software Force on output A */

/**
  * @}
  */

/** @defgroup EPWM_DBCTLCONF EPWM Dead Band Control Register Configuration
  * @{
  * @brief  Macro definitions about PWM dead band control for the bit fields in the DBCTL register.
  */
#define EPWM_DBCTL_OUT_MODE_S       (0UL)             /*!< Dead Band Output Mode Control shift */
#define EPWM_DBCTL_OUT_MODE_M       (0x00000003UL)    /*!< Dead Band Output Mode Control */
#define EPWM_DBCTL_IN_MODE_S        (4UL)             /*!< Dead Band Input Select Mode Control shift */
#define EPWM_DBCTL_IN_MODE_M        (0x00000030UL)    /*!< Dead Band Input Select Mode Control */
#define EPWM_DBCTL_SHDWDBREDMODE    (0x00000400UL)    /*!< DBRED Block Operating Mode */
#define EPWM_DBCTL_SHDWDBFEDMODE    (0x00000800UL)    /*!< DBFED Block Operating Mode */
#define EPWM_DBCTL_DEDB_MODE        (0x00004000UL)    /*!< Dead Band Dual-Edge B Mode Control */
#define EPWM_DBCTL_HALFCYCLE        (0x00008000UL)    /*!< Half Cycle Clocking Enable */

/**
  * @}
  */

/** @defgroup EPWM_DBCTL2CONF EPWM Dead Band Control Register 2 Configuration
  * @{
  * @brief  Macro definitions about EPWM Dead Band Control Register 2 for the bit fields in the DBCTL2 register.
  */
#define EPWM_DBCTL2_SHDWDBCTLMODE    (0x00000004UL)    /*!< DBCTL Load mode Select */

/**
  * @}
  */

/** @defgroup EPWM_PCCTLCONF EPWM PWM Chopping Control Register Configuration
  * @{
  * @brief  Macro definitions about PWM chopping control for the bit fields in the PCCTL register.
  */
#define EPWM_PCCTL_CHPEN    (0x00000001UL)    /*!< PWM chopping enable */

/**
  * @}
  */

/** @defgroup EPWM_CMPCTLCONF EPWM Compare Control Register Configuration
  * @{
  * @brief  Macro definitions about PWM compare controlfor for the bit fields in the CMPCTL register.
  */
#define EPWM_REGS_CMPCTL_LOADAMODE_S       (0UL)             /*!< Loading mode of CMPA shift */
#define EPWM_REGS_CMPCTL_LOADAMODE_M       (0x00000003UL)    /*!< Loading mode of CMPA mask */
#define EPWM_REGS_CMPCTL_LOADBMODE_S       (2UL)             /*!< Loading mode of CMPB shift */
#define EPWM_REGS_CMPCTL_LOADBMODE_M       (0x0000000CUL)    /*!< Loading mode of CMPB mask */
#define EPWM_REGS_CMPCTL_SHDWAMODE_S       (4UL)             /*!< Shadow mode of CMPA shift */
#define EPWM_REGS_CMPCTL_SHDWAMODE_M       (0x00000010UL)    /*!< Shadow mode of CMPA mask */
#define EPWM_REGS_CMPCTL_SHDWBMODE_S       (6UL)             /*!< Shadow mode of CMPB shift */
#define EPWM_REGS_CMPCTL_SHDWBMODE_M       (0x00000040UL)    /*!< Shadow mode of CMPB mask */
#define EPWM_REGS_CMPCTL_SHDWAORCFULL_S    (8UL)             /*!< CMPA shadow register full flag bit shift */
#define EPWM_REGS_CMPCTL_SHDWAORCFULL_M    (0x00000100UL)    /*!< CMPA shadow register full flag bit mask */
#define EPWM_REGS_CMPCTL_SHDWBORDFULL_S    (9UL)             /*!< CMPB shadow register full flag bit shift */
#define EPWM_REGS_CMPCTL_SHDWBORDFULL_M    (0x00000200UL)    /*!< CMPB shadow register full flag bit mask */
#define EPWM_REGS_CMPCTL_LOADASYNC_S       (10UL)            /*!< Synchronous loading opportunity of CMPA shift */
#define EPWM_REGS_CMPCTL_LOADASYNC_M       (0x00000C00UL)    /*!< Synchronous loading opportunity of CMPA mask */
#define EPWM_REGS_CMPCTL_LOADBSYNC_S       (12UL)            /*!< Synchronous loading opportunity of CMPB shift */
#define EPWM_REGS_CMPCTL_LOADBSYNC_M       (0x00003000UL)    /*!< Synchronous loading opportunity of CMPB mask */
#define EPWM_REGS_CMPCTL_LINKDUTYHR        (0x00008000UL)    /*!< Enable same values on CMPAHR/CMPBHR */

/**
  * @}
  */

/** @defgroup EPWM_CMPCTL2CONF EPWM Compare Control Register 2 Configuration
  * @{
  * @brief  Macro definitions about PWM compare control register 2 for the bit fields in the CMPCTL2 register.
  */
#define EPWM_REGS_CMPCTL2_LOADCMODE_S      (0UL)             /*!< Loading mode of CMPC shift */
#define EPWM_REGS_CMPCTL2_LOADCMODE_M      (0x00000003UL)    /*!< Loading mode of CMPC mask */
#define EPWM_REGS_CMPCTL2_LOADDMODE_S      (2UL)             /*!< Loading mode of CMPD shift */
#define EPWM_REGS_CMPCTL2_LOADDMODE_M      (0x0000000CUL)    /*!< Loading mode of CMPD mask */
#define EPWM_REGS_CMPCTL2_SHDWCMODE_S      (4UL)             /*!< Shadow mode of CMPC shift */
#define EPWM_REGS_CMPCTL2_SHDWCMODE_M      (0x00000010UL)    /*!< Shadow mode of CMPC mask */
#define EPWM_REGS_CMPCTL2_SHDWDMODE_S      (6UL)             /*!< Shadow mode of CMPD shift */
#define EPWM_REGS_CMPCTL2_SHDWDMODE_M      (0x00000040UL)    /*!< Shadow mode of CMPD mask */
#define EPWM_REGS_CMPCTL_SHDWAORCFULL_S    (8UL)             /*!< CMPC shadow register full flag bit shift */
#define EPWM_REGS_CMPCTL_SHDWAORCFULL_M    (0x00000100UL)    /*!< CMPC shadow register full flag bit mask */
#define EPWM_REGS_CMPCTL_SHDWBORDFULL_S    (9UL)             /*!< CMPD shadow register full flag bit shift */
#define EPWM_REGS_CMPCTL_SHDWBORDFULL_M    (0x00000200UL)    /*!< CMPD shadow register full flag bit mask */
#define EPWM_REGS_CMPCTL2_LOADCSYNC_S      (10UL)            /*!< Synchronous loading opportunity of CMPC shift */
#define EPWM_REGS_CMPCTL2_LOADCSYNC_M      (0x00000C00UL)    /*!< Synchronous loading opportunity of CMPC mask */
#define EPWM_REGS_CMPCTL2_LOADDSYNC_S      (12UL)            /*!< Synchronous loading opportunity of CMPD shift */
#define EPWM_REGS_CMPCTL2_LOADDSYNC_M      (0x00003000UL)    /*!< Synchronous loading opportunity of CMPD mask */

/**
  * @}
  */

/** @defgroup EPWM_CMPACONF EPWM Compare X Register Configuration
  * @{
  * @brief  Macro definitions about PWM compare X for the bit fields in the CMPA register.
  */
#define EPWM_REGS_CMPA_CMPA_S    (16UL)            /*!< Compare A register shift */
#define EPWM_REGS_CMPA_CMPA_M    (0xFFFF0000UL)    /*!< Compare A register mask */
#define EPWM_REGS_CMPB_CMPB_S    (16UL)            /*!< Compare B register shift */
#define EPWM_REGS_CMPB_CMPB_M    (0xFFFF0000UL)    /*!< Compare B register mask */
#define EPWM_REGS_CMPC_CMPC_S    (0UL)             /*!< Compare C register shift */
#define EPWM_REGS_CMPC_CMPC_M    (0x0000FFFFUL)    /*!< Compare C register mask */
#define EPWM_REGS_CMPD_CMPD_S    (0UL)             /*!< Compare D register shift */
#define EPWM_REGS_CMPD_CMPD_M    (0x0000FFFFUL)    /*!< Compare D register mask */

/**
  * @}
  */

/** @defgroup EPWM_TZCTL2CONF EPWM Trip Zone Control 2 Register Configuration
  * @{
  * @brief  Macro definitions about EPWM trip zone control 2 for the bit fields in the TZCTL2 register.
  */
#define EPWM_TZCTL2_ETZE    (0x00008000UL)       /*!< TZCTL2 enable */

/**
  * @}
  */

/** @defgroup EPWM_TZSELCONF EPWM Trip Zone Select Register Configuration
  * @{
  * @brief  Macro definitions about EPWM trip zone select for the bit fields in the TZSEL register.
  */
#define EPWM_TZ_SIGNAL_CBC1       (0x00000001UL)    /*!< TZ1 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC2       (0x00000002UL)    /*!< TZ2 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC3       (0x00000004UL)    /*!< TZ3 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC4       (0x00000008UL)    /*!< TZ4 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC5       (0x00000010UL)    /*!< TZ5 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC6       (0x00000020UL)    /*!< TZ6 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_DCAEVT2    (0x00000040UL)    /*!< DCAEVT2 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_DCBEVT2    (0x00000080UL)    /*!< DCBEVT2 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_OSHT1      (0x00000100UL)    /*!< One-shot TZ1 */
#define EPWM_TZ_SIGNAL_OSHT2      (0x00000200UL)    /*!< One-shot TZ2 */
#define EPWM_TZ_SIGNAL_OSHT3      (0x00000400UL)    /*!< One-shot TZ3 */
#define EPWM_TZ_SIGNAL_OSHT4      (0x00000800UL)    /*!< One-shot TZ4 */
#define EPWM_TZ_SIGNAL_OSHT5      (0x00001000UL)    /*!< One-shot TZ5 */
#define EPWM_TZ_SIGNAL_OSHT6      (0x00002000UL)    /*!< One-shot TZ6 */
#define EPWM_TZ_SIGNAL_DCAEVT1    (0x00004000UL)    /*!< One-shot DCAEVT1 */
#define EPWM_TZ_SIGNAL_DCBEVT1    (0x00008000UL)    /*!< One-shot DCBEVT1 */

/**
  * @}
  */

/** @defgroup EPWM_TZSEL2CONF EPWM Trip Zone Select Register Configuration
  * @{
  * @brief  Macro definitions about EPWM trip zone select for the bit fields in the TZSEL2 register.
  */
#define EPWM_TZSEL2_CAPEVTOST    (0x100UL)    /*!< One-shot CAPEVT */
#define EPWM_TZSEL2_CAPEVTCBC    (0x1UL)      /*!< CAPEVT Cycle By Cycle */

/**
  * @}
  */

/** @defgroup EPWM_ETSELCONF EPWM Event Trigger Select Register Configuration
  * @{
  * @brief  Macro definitions about EPWM event trigger select for the bit fields in the ETSEL register.
  */
#define EPWM_ETSEL_INTEN         (0x00000008UL)    /*!< EPWMxINTn Enable */
#define EPWM_ETSEL_SOCASELCMP    (0x00000010UL)    /*!< EPWMxSOCA Compare Select */
#define EPWM_ETSEL_SOCBSELCMP    (0x00000020UL)    /*!< EPWMxSOCB Compare Select */
#define EPWM_ETSEL_INTSELCMP     (0x00000040UL)    /*!< EPWMxINT Compare Select */
#define EPWM_ETSEL_SOCAEN        (0x00000800UL)    /*!< Start of Conversion A Enable */
#define EPWM_ETSEL_SOCBEN        (0x00008000UL)    /*!< Start of Conversion B Enable */

/**
  * @}
  */

/** @defgroup EPWM_INTSELCONF EPWM Interrupt Source Select
  * @{
  * @brief  Macro definitions about EPWM interrupt Source select for the bit fields in the ETSEL register.
  */
#define EPWM_INT_TBCTR_DISABLED    (0x00000000UL)    /*!< Time-base counter is disabled */
#define EPWM_INT_TBCTR_ZERO        (0x00000001UL)    /*!< Time-base counter equal to zero */
#define EPWM_INT_TBCTR_PERIOD      (0x00000002UL)    /*!< Time-base counter equal to period */
#define EPWM_INT_TBCTR_ETINTMIX    (0x00000003UL)    /*!< time-base counter based on mixed events */
#define EPWM_INT_TBCTR_U_CMPA      (0x00000004UL)    /*!< time-base counter equal to CMPA when the timer is incrementing */
#define EPWM_INT_TBCTR_U_CMPC      (0x00000008UL)    /*!< time-base counter equal to CMPC when the timer is incrementing */
#define EPWM_INT_TBCTR_D_CMPA      (0x00000005UL)    /*!< time-base counter equal to CMPA when the timer is decrementing */
#define EPWM_INT_TBCTR_D_CMPC      (0x0000000AUL)    /*!< time-base counter equal to CMPC when the timer is decrementing */
#define EPWM_INT_TBCTR_U_CMPB      (0x00000006UL)    /*!< time-base counter equal to CMPB when the timer is incrementing */
#define EPWM_INT_TBCTR_U_CMPD      (0x0000000CUL)    /*!< time-base counter equal to CMPD when the timer is incrementing */
#define EPWM_INT_TBCTR_D_CMPB      (0x00000007UL)    /*!< time-base counter equal to CMPB when the timer is decrementing */
#define EPWM_INT_TBCTR_D_CMPD      (0x0000000EUL)    /*!< time-base counter equal to CMPD when the timer is decrementing */

/**
  * @}
  */

/** @defgroup EPWM_ETPSCONF EPWM Event Trigger Frequency Division Register
  * @{
  * @brief  Macro definitions about EPWM event trigger frequency division for the bit fields in the ETPS register.
  */
#define EPWM_ETPS_INTPSSEL    (0x00000010UL)    /*!< EPWMxINTn Pre-Scale Selection Bits */
#define EPWM_ETPS_SOCPSSEL    (0x00000020UL)    /*!< EPWMxSOC A/B  Pre-Scale Selection Bits */

/**
  * @}
  */

/** @defgroup EPWM_ETCLRCONF EPWM Event Trigger Flag Clear Register
  * @{
  * @brief  Macro definitions about EPWM event trigger flag clear for the bit fields in the ETCLR register.
  */
#define EPWM_ETCLR_INT     (0x00000001UL)    /*!< EPWMxINTn Clear */
#define EPWM_ETCLR_SOCA    (0x00000004UL)    /*!< EPWMxSOCA Clear */
#define EPWM_ETCLR_SOCB    (0x00000008UL)    /*!< EPWMxSOCB Clear */

/**
  * @}
  */

/** @defgroup EPWM_ETCNTINITCTLCONF EPWM Event Trigger Counter Initialization Control Register
  * @{
  * @brief  Macro definitions about EPWM counter initialization for the bit fields in the ETCNTINITCTL register.
  */
#define EPWM_ETCNTINITCTL_INTINITFRC     (0x00000400UL)    /*!< EPWMxINT Counter Initialization Force */
#define EPWM_ETCNTINITCTL_SOCAINITFRC    (0x00000800UL)    /*!< EPWMxSOCA Counter Initialization Force */
#define EPWM_ETCNTINITCTL_SOCBINITFRC    (0x00001000UL)    /*!< EPWMxSOCB Counter Initialization Force */
#define EPWM_ETCNTINITCTL_INTINITEN      (0x00002000UL)    /*!< EPWMxINT Counter Initialization Enable */
#define EPWM_ETCNTINITCTL_SOCAINITEN     (0x00004000UL)    /*!< EPWMxSOCA Counter Initialization Enable */
#define EPWM_ETCNTINITCTL_SOCBINITEN     (0x00008000UL)    /*!< EPWMxSOCB Counter Initialization Enable */

/**
  * @}
  */

/** @defgroup EPWM_ETFRCONF EPWM Event Trigger Software Mandatory Register Configuration
  * @{
  * @brief  Macro definitions about EPWM event trigger software mandatory for the bit fields in the ETFRC register.
  */
#define EPWM_ETFRC_INT     (0x00000001UL)    /*!< EPWMxINTn Force */
#define EPWM_ETFRC_SOCA    (0x00000004UL)    /*!< EPWMxSOCA Force */
#define EPWM_ETFRC_SOCB    (0x00000008UL)    /*!< EPWMxSOCB Force */

/**
  * @}
  */

/** @defgroup EPWM_DCACTLCONF EPWM Digital Comparison A Control Register Configuration
  * @{
  * @brief  Macro definitions about EPWM digital comparison A control for the bit fields in the DCACTL register.
  */
#define EPWM_DCACTL_EVT1SRCSEL        (0x00000001UL)    /*!< DCAEVT1 Source Signal */
#define EPWM_DCACTL_EVT1FRCSYNCSEL    (0x00000002UL)    /*!< DCAEVT1 Force Sync Signal */
#define EPWM_DCACTL_EVT1SOCE          (0x00000004UL)    /*!< DCAEVT1 SOC Enable */
#define EPWM_DCACTL_EVT1SYNCE         (0x00000008UL)    /*!< DCAEVT1 SYNC Enable */
#define EPWM_DCACTL_EVT1LATSEL        (0x00000010UL)    /*!< DCAEVT1 Latched signal select */
#define EPWM_DCACTL_EVT1LAT           (0x00000080UL)    /*!< Indicates the status of DCAEVT1LAT signal */
#define EPWM_DCACTL_EVT2SRCSEL        (0x00000100UL)    /*!< DCAEVT2 Source Signal */
#define EPWM_DCACTL_EVT2FRCSYNCSEL    (0x00000200UL)    /*!< DCAEVT2 Force Sync Signal */
#define EPWM_DCACTL_EVT2LATSEL        (0x00001000UL)    /*!< DCAEVT2 Latched signal select */
#define EPWM_DCACTL_EVT2LAT           (0x00008000UL)    /*!< Indicates the status of DCAEVT2LAT signal */

/**
  * @}
  */

/** @defgroup EPWM_DCFCTLCONF EPWM Digital Compare Filter Control Configuration
  * @{
  * @brief  Macro definitions about EPWM digital compare filter for the bit fields in the DCFCTL register.
  */
#define EPWM_DCFCTL_BLANKE         (0x00000004UL)    /*!< Blanking Enable/Disable */
#define EPWM_DCFCTL_BLANKINV       (0x00000008UL)    /*!< Blanking Window Inversion */
#define EPWM_DCFCTL_EDGEFILTSEL    (0x00000040UL)    /*!< Edge Filter Select */

/**
  * @}
  */

/** @defgroup EPWM_DCCAPCTLCONF EPWM Digital Compare Capture Control Configuration
  * @{
  * @brief  Macro definitions about EPWM digital compare capture for the bit fields in the DCCAPCTL register.
  */
#define EPWM_DCCAPCTL_CAPE        (0x00000001UL)    /*!< Counter Capture Enable */
#define EPWM_DCCAPCTL_SHDWMODE    (0x00000002UL)    /*!< Counter Capture Mode */
#define EPWM_DCCAPCTL_CAPSTS      (0x00002000UL)    /*!< Latched Status Flag for Capture Event */
#define EPWM_DCCAPCTL_CAPCLR      (0x00004000UL)    /*!< DC Capture Latched Status Clear Flag */
#define EPWM_DCCAPCTL_CAPMODE     (0x00008000UL)    /*!< Counter Capture Mode */

/**
  * @}
  */

/** @defgroup EPWM_VCAPCTLCONF EPWM Valley Capture Control Configuration
  * @{
  * @brief  Macro definitions about EPWM valley capture for the bit fields in the VCAPCTL register.
  */
#define EPWM_VCAPCTL_VCAPE             (0x00000001UL)    /*!< Valley  Capture mode */
#define EPWM_VCAPCTL_VCAPSTART         (0x00000002UL)    /*!< Valley  Capture Start */
#define EPWM_VCAPCTL_EDGEFILTDLYSEL    (0x00000400UL)    /*!< Valley Switching Mode Delay Select */

/**
  * @}
  */

/** @defgroup EPWM_VCNTCFGCONF EPWM Valley Counter Configuration Register configuration
  * @{
  * @brief  Macro definitions about EPWM valley Counter Configuration for the bit fields in the VCNTCFG register.
  */
#define EPWM_VCNTCFG_STARTEDGESTS    (0x00000080UL)    /*!< Start Edge Status Bit */
#define EPWM_VCNTCFG_STOPEDGESTS     (0x00008000UL)    /*!< Stop Edge Status Bit */

/**
  * @}
  */

/** @defgroup EPWM_GLDCTLCONF EPWM Global Load Control Register Configuration
  * @{
  * @brief  Macro definitions about EPWM global load control for the bit fields in the GLDCTL register.
  */
#define EPWM_GLDCTL_GLD         (0x00000001UL)    /*!< Global Shadow to Active load event control */
#define EPWM_GLDCTL_OSHTMODE    (0x00000020UL)    /*!< One Shot Load mode control bit */

/**
  * @}
  */

/** @defgroup EPWM_GL_LOADCONF2CONF EPWM Global Load Control Register 2 Configuration
  * @{
  * @brief  Macro definitions about EPWM global load control register 2 for the bit fields in the GLDCTL2 register.
  */
#define EPWM_GLDCTL2_OSHTLD    (0x00000001UL)    /*!< Enable reload event in one shot mode */
#define EPWM_GLDCTL2_GFRCLD    (0x00000002UL)    /*!< Force reload event in one shot mode */

/**
  * @}
  */

/** @defgroup EPWM_TZDCSELCONF EPWM Trip Zone Digital Comparator Selection
  * @{
  * @brief  Macro definitions about EPWM Trip zone digital comparator selection for the bit fields in the TZDCSEL register.
  */
#define EPWM_TZDCSEL_DCXEVTX    (0x00000007UL)    /*!< Select an event source */

/**
  * @}
  */

/** @defgroup EPWM_AQCTLCONF EPWM Action Qualifier Control Register Configuration
  * @{
  * @brief  Macro definitions about EPWM action qualifier control for the bit fields in the AQCTL register.
  */
#define EPWM_AQCTL_SHDWAQAMODE      (0x00000100UL)    /*!< Set AQCTLA shadow loading mode bit mask */
#define EPWM_AQCTL_SHDWAQBMODE      (0x00000200UL)    /*!< Set AQCTLB shadow loading mode bit mask */

/**
  * @}
  */

/** @defgroup EPWM_CAPCTLCONF EPWM Event Capture Control Register Configuration
  * @{
  */
#define EPWM_CAPCTL_SRCSEL      (0x1UL)           /*!< Capture Logic Input Selection */
#define EPWM_CAPCTL_PULSECTL    (0x00000010UL)    /*!< Polarity selection for Capture input */
#define EPWM_CAPCTL_FRCLOAD     (0x00000100UL)    /*!< Capture event force load */

/**
  * @}
  */

/** @defgroup EPWM_TZEINTCONF EPWM Triple Zone Area Interrupt Configuration
  * @{
  * @brief  Macro definitions about EPWM triple zone area interrupt for the bit fields in the TZEINT register.
  */
#define EPWM_TZ_INTERRUPT_CBC        (0x00000002UL)    /*!< Trip Zones Cycle By Cycle interrupt */
#define EPWM_TZ_INTERRUPT_OST        (0x00000004UL)    /*!< Trip Zones One Shot interrupt */
#define EPWM_TZ_INTERRUPT_DCAEVT1    (0x00000008UL)    /*!< Digital Compare A Event 1 interrupt */
#define EPWM_TZ_INTERRUPT_DCAEVT2    (0x00000010UL)    /*!< Digital Compare A Event 2 interrupt */
#define EPWM_TZ_INTERRUPT_DCBEVT1    (0x00000020UL)    /*!< Digital Compare B Event 1 interrupt */
#define EPWM_TZ_INTERRUPT_DCBEVT2    (0x00000040UL)    /*!< Digital Compare B Event 2 interrupt */
#define EPWM_TZ_INTERRUPT_CAPEVT     (0x00000080UL)    /*!< Capture Event interrupt */

/**
  * @}
  */

/** @defgroup EPWM_TZFLGCONF EPWM Triple Zone Flag Configuration
  * @{
  * @brief  Macro definitions about EPWM triple zone Flag for the bit fields in the TZFLG register.
  */
#define EPWM_TZ_INTERRUPT       (0x00000001UL)    /*!< Trip Zone interrupt was generated */
#define EPWM_TZ_FLAG_CBC        (0x00000002UL)    /*!< Trip Zones Cycle By Cycle flag */
#define EPWM_TZ_FLAG_OST        (0x00000004UL)    /*!< Trip Zones One Shot flag */
#define EPWM_TZ_FLAG_DCAEVT1    (0x00000008UL)    /*!< Digital Compare A Event 1 flag */
#define EPWM_TZ_FLAG_DCAEVT2    (0x00000010UL)    /*!< Digital Compare A Event 2 flag */
#define EPWM_TZ_FLAG_DCBEVT1    (0x00000020UL)    /*!< Digital Compare B Event 1 flag */
#define EPWM_TZ_FLAG_DCBEVT2    (0x00000040UL)    /*!< Digital Compare B Event 2 flag */
#define EPWM_TZ_FLAG_CAPEVT     (0x00000080UL)    /*!< Capture Event flag */

/**
  * @}
  */

/** @defgroup EPWM_TZCBCFLGCONF EPWM Triple Zone CBC Flag Configuration
  * @{
  * @brief  Macro definitions about EPWM triple zone CBC Flag for the bit fields in the TZCBCFLG register.
  */
#define EPWM_TZ_CBC_FLAG_1          (0x00000001UL)    /*!< CBC flag 1 */
#define EPWM_TZ_CBC_FLAG_2          (0x00000002UL)    /*!< CBC flag 2 */
#define EPWM_TZ_CBC_FLAG_3          (0x00000004UL)    /*!< CBC flag 3 */
#define EPWM_TZ_CBC_FLAG_4          (0x00000008UL)    /*!< CBC flag 4 */
#define EPWM_TZ_CBC_FLAG_5          (0x00000010UL)    /*!< CBC flag 5 */
#define EPWM_TZ_CBC_FLAG_6          (0x00000020UL)    /*!< CBC flag 6 */
#define EPWM_TZ_CBC_FLAG_DCAEVT2    (0x00000040UL)    /*!< CBC flag Digital compare event A2 */
#define EPWM_TZ_CBC_FLAG_DCBEVT2    (0x00000080UL)    /*!< CBC flag Digital compare event B2 */
#define EPWM_TZ_CBC_FLAG_CAPEVT     (0x00000100UL)    /*!< Capture Event */

/**
  * @}
  */

/** @defgroup EPWM_TZOSTFLGCONF EPWM Triple Zone OST Flag Configuration
  * @{
  * @brief  Macro definitions about EPWM triple zone OST Flag for the bit fields in the TZOSTFLG register.
  */
#define EPWM_TZ_OST_FLAG_OST1       (0x00000001UL)    /*!< OST flag OST1 */
#define EPWM_TZ_OST_FLAG_OST2       (0x00000002UL)    /*!< OST flag OST2 */
#define EPWM_TZ_OST_FLAG_OST3       (0x00000004UL)    /*!< OST flag OST3 */
#define EPWM_TZ_OST_FLAG_OST4       (0x00000008UL)    /*!< OST flag OST4 */
#define EPWM_TZ_OST_FLAG_OST5       (0x00000010UL)    /*!< OST flag OST5 */
#define EPWM_TZ_OST_FLAG_OST6       (0x00000020UL)    /*!< OST flag OST6 */
#define EPWM_TZ_OST_FLAG_DCAEVT1    (0x00000040UL)    /*!< OST flag Digital compare event A1 */
#define EPWM_TZ_OST_FLAG_DCBEVT1    (0x00000080UL)    /*!< OST flag Digital compare event B1 */
#define EPWM_TZ_OST_FLAG_CAPEVT     (0x00000100UL)    /*!< Capture Event */

/**
  * @}
  */

/** @defgroup EPWM_TZFRCCONF EPWM Triple Zone Software Force Configuration
  * @{
  * @brief  Macro definitions about EPWM triple zone software force for the bit fields in the TZFRC register.
  */
#define EPWM_TZ_FORCE_EVENT_CBC        (0x00000002UL)    /*!< Force Cycle By Cycle trip event */
#define EPWM_TZ_FORCE_EVENT_OST        (0x00000004UL)    /*!< Force a One-Shot Trip Event */
#define EPWM_TZ_FORCE_EVENT_DCAEVT1    (0x00000008UL)    /*!< Force Digital Compare Output A Event 1 */
#define EPWM_TZ_FORCE_EVENT_DCAEVT2    (0x00000010UL)    /*!< Force Digital Compare Output A Event 2 */
#define EPWM_TZ_FORCE_EVENT_DCBEVT1    (0x00000020UL)    /*!< Force Digital Compare Output B Event 1 */
#define EPWM_TZ_FORCE_EVENT_DCBEVT2    (0x00000040UL)    /*!< Force Digital Compare Output B Event 2 */
#define EPWM_TZ_FORCE_EVENT_CAPEVT     (0x00000080UL)    /*!< Force Flag for Capture Event Output */

/**
  * @}
  */

/** @defgroup EPWM_GLDCFGCONF EPWM Global Load Register Configuration
  * @{
  * @brief  Macro definitions about EPWM global load for the bit fields in the GLDCFG register
  */
#define EPWM_GL_REGISTER_TBPRD_TBPRD        (0x00000001UL)    /*!< Global load TBPRD:TBPRD */
#define EPWM_GL_REGISTER_CMPA_CMPAHR        (0x00000002UL)    /*!< Global load CMPA:CMPAHR */
#define EPWM_GL_REGISTER_CMPB_CMPBHR        (0x00000004UL)    /*!< Global load CMPB:CMPBHR */
#define EPWM_GL_REGISTER_CMPC               (0x00000008UL)    /*!< Global load CMPC */
#define EPWM_GL_REGISTER_CMPD               (0x00000010UL)    /*!< Global load CMPD */
#define EPWM_GL_REGISTER_DBRED_DBREDHR      (0x00000020UL)    /*!< Global load DBRED:DBREDHR */
#define EPWM_GL_REGISTER_DBFED_DBFEDHR      (0x00000040UL)    /*!< Global load DBFED:DBFEDHR */
#define EPWM_GL_REGISTER_DBCTL              (0x00000100UL)    /*!< Global load DBCTL */
#define EPWM_GL_REGISTER_AQCTLA_AQCTLA2     (0x00000200UL)    /*!< Global load AQCTLA/A2 */
#define EPWM_GL_REGISTER_AQCTLB_AQCTLB2     (0x00000400UL)    /*!< Global load AQCTLB/B2 */
#define EPWM_GL_REGISTER_AQCSFRC            (0x00002000UL)    /*!< Global load AQCSFRC */
#define EPWM_GL_REGISTER_TBPRD_TBPRDHRHR    (0x00004000UL)    /*!< Global load TBPRD:TBPRDHR */

/**
  * @}
  */

/** @defgroup EPWM_EPWMSYNCOUTENCONF EPWM Synchronous Output Enable Register Configuration
  * @{
  * @brief  Macro definitions about EPWM synchronous output enable for the bit fields in the EPWMSYNCOUTEN register.
  */
#define EPWM_SYNC_OUT_PULSE_ON_SOFTWARE          (0x00000001UL)    /*!< Software force generated EPWM sync-out pulse */
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO         (0x00000002UL)    /*!< Counter zero event generates EPWM sync-out pulse */
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B    (0x00000004UL)    /*!< Counter equal to CMPB event generates EPWM sync-out */
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C    (0x00000008UL)    /*!< Counter equal to CMPC event generates EPWM sync-out */
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D    (0x00000010UL)    /*!< Counter equal to CMPD event generates EPWM sync-out */
#define EPWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC     (0x00000020UL)    /*!< DCA Event 1 Sync signal generates EPWM sync-out pulse */
#define EPWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC     (0x00000040UL)    /*!< DCB Event 1 Sync signal generates EPWM sync-out pulse */
#define EPWM_SYNC_OUT_PULSE_ON_ALL               (0x0000007FUL)    /*!< Enable all the above sources */

/**
  * @}
  */

/** @defgroup EPWM_DCMIXSELCONF EPWM DC Mix Selection Configuration
  * @{
  */
#define EPWM_DC_MIX_TBCTR_ZERO      (0x00000001UL)    /*!< Mix Time-base Counter Equal to Zero  */
#define EPWM_DC_MIX_TBCTR_PERIOD    (0x00000002UL)    /*!< Mix Time-base Counter Equal to Period */
#define EPWM_DC_MIX_TBCTR_U_CMPA    (0x00000004UL)    /*!< Mix Time-base Counter Up Equal to CMPA */
#define EPWM_DC_MIX_TBCTR_D_CMPA    (0x00000008UL)    /*!< Mix Time-base Counter Down Equal to CMPA */
#define EPWM_DC_MIX_TBCTR_U_CMPB    (0x00000010UL)    /*!< Mix Time-base Counter Up Equal to CMPB */
#define EPWM_DC_MIX_TBCTR_D_CMPB    (0x00000020UL)    /*!< Mix Time-base Counter Down Equal to CMPB */
#define EPWM_DC_MIX_TBCTR_U_CMPC    (0x00000040UL)    /*!< Mix Time-base Counter Up Equal to CMPC */
#define EPWM_DC_MIX_TBCTR_D_CMPC    (0x00000080UL)    /*!< Mix Time-base Counter Down Equal to CMPC */
#define EPWM_DC_MIX_TBCTR_U_CMPD    (0x00000100UL)    /*!< Mix Time-base Counter Up Equal to CMPD */
#define EPWM_DC_MIX_TBCTR_D_CMPD    (0x00000200UL)    /*!< Mix Time-base Counter Down Equal to CMPD */

/**
  * @}
  */

/** @defgroup EPWM_DCAHTRIPSELCONF EPWM Digital Comparison AH/AL/BH/BL Trip Selection
  * @{
  * @brief  Macro definitions about EPWM digital comparison X trip selection for the bit fields in the DCAHTRIPSEL register.
  */
#define EPWM_DC_COMBINATIONAL_TRIPIN1     (0x00000001UL)    /*!< Combinational Trip 1 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN2     (0x00000002UL)    /*!< Combinational Trip 2 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN3     (0x00000004UL)    /*!< Combinational Trip 3 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN4     (0x00000008UL)    /*!< Combinational Trip 4 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN5     (0x00000010UL)    /*!< Combinational Trip 5 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN6     (0x00000020UL)    /*!< Combinational Trip 6 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN7     (0x00000040UL)    /*!< Combinational Trip 7 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN8     (0x00000080UL)    /*!< Combinational Trip 8 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN9     (0x00000100UL)    /*!< Combinational Trip 9 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN10    (0x00000200UL)    /*!< Combinational Trip 10 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN11    (0x00000400UL)    /*!< Combinational Trip 11 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN12    (0x00000800UL)    /*!< Combinational Trip 12 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN14    (0x00002000UL)    /*!< Combinational Trip 14 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN15    (0x00004000UL)    /*!< Combinational Trip 15 input */

/**
  * @}
  */

/** @defgroup EPWM_CAPTRIPSEL EPWM Digital Comparison AH/AL/BH/BL Trip Selection
  * @{
  * @brief  Macro definitions about EPWM digital comparison X trip selection for the bit fields in the DCAHTRIPSEL register.
  */
#define EPWM_CAPGATECOMPSEL_M    (0xF0UL)    /*!< CAPGATE Select Bits */
#define EPWM_CAPINCOMPSEL_M      (0xFUL)     /*!< CAPIN Select Bits */

/**
  * @}
  */

/** @defgroup EPWM_DECTL diode emulation mode control register Selection
  * @{
  * @brief  Macro definitions about DECTL Register.
  */
#define EPWM_DECTL_ENABLE    (0x1UL)       /*!< DE function enable */

/**
  * @}
  */

/** @defgroup EPWM_DECHANNEL defines epwm output channel
  * @{
  * @brief  Macro definitions about epwm output channel.
  */
#define EPWM_DE_CHANNEL_A    (0x0UL)    /*!< Diode emulation channel A */
#define EPWM_DE_CHANNEL_B    (0x1UL)    /*!< Diode emulation channel B */

/**
  * @}
  */

/** @defgroup EPWM_DEACTCTL configure the PWM controls when in DE mode
  * @{
  * @brief  Macro definitions about PWM control register.
  */
#define EPWM_DEACTCTL_TRIPSELA      (0x4UL)       /*!< Trip source select on PWMA output */
#define EPWM_DEACTCTL_TRIPSELB      (0x40UL)      /*!< Trip source select on PWMB output */
#define EPWM_DEACTCTL_TRIPENABLE    (0x10000UL)   /*!< Enables PWMTRIP condition to bypassDiode emulation logic */

/**
  * @}
  */

/** @defgroup EPWM_DEFRCDEACTIVE defines for the bit fields in the DEFRC register
  * @{
  * @brief  Macro definitions about the bit fields in the DEFRC register.
  */
#define EPWM_DEFRC_DEACTIVE    (0x1UL)    /*!< Diode Emulation mode active flag force. */

/**
  * @}
  */

/** @defgroup EPWM_DECLRDEACTIVE defines for the bit fields in the DECLR register
  * @{
  * @brief  Macro definitions about the bit fields in the DECLR register.
  */
#define EPWM_DECLR_DEACTIVE    (0x1UL)    /*!< Diode Emulation mode active flag clear */

/**
  * @}
  */

/** @defgroup EPWM_DEMONCTLENABLE defines for the bit fields in the DEMONCTL register
  * @{
  * @brief  Macro definitions about the bit fields in the DEMONCTL register.
  */
#define EPWM_DEMONCTL_ENABLE   (0x1UL)    /*!< DEACTIVE monitor counter enable */

/**
  * @}
  */

/** @defgroup EPWM_DEMONSTEP defines for the bit fields in the DEMONSTEP register
  * @{
  * @brief  Macro definitions about the bit fields in the DEMONSTEP register.
  */
#define EPWM_DE_COUNT_UP      (0x0UL)    /*!< Diode emulation count up mode */
#define EPWM_DE_COUNT_DOWN    (0x1UL)    /*!< Diode emulation count down mode */

/**
  * @}
  */

/** @defgroup EPWM_DEMONTRIPSEL select trip source
  * @{
  * @brief  Macro definitions about the trip source selection register.
  */
 #define EPWM_DE_SRC_TRIPL    (1UL)    /*!< Diode emulation Trip L */
 #define EPWM_DE_SRC_TRIPH    (0UL)    /*!< Diode emulation Trip H */

/**
  * @}
  */

/** @defgroup EPWM_MINDBCFG defines for minimum dead band configuration register.
  * @{
  * @brief  Macro definitions minimum dead band configuration register.
  */
#define EPWM_MINDB_BLOCK_A                      (0UL)          /*!< Minimum Dead Band Block A */
#define EPWM_MINDB_BLOCK_B                      (1UL)          /*!< Minimum Dead Band Block B */
#define EPWM_MINDBCFG_ENABLEA                   (0x1UL)        /*!< Minimum dead band logic enable on PWMA shift */
#define EPWM_MINDBCFG_ENABLEB                   (0x10000UL)    /*!< Minimum dead band logic enable on PWMA */
#define EPWM_MINDB_REF_SIG                      (0x0UL)        /*!< Minimum Dead Band don't invert reference signal */
#define EPWM_MINDB_REF_SIG_INVERT               (0x1UL)        /*!< Minimum Dead invert reference signal */
#define EPWM_MINDB_BLOCKING_SIGNAL_BYPASS       (0x0UL)        /*!< Select BLOCKA as the blocking signal on PWMA. */
#define EPWM_MINDB_BLOCKING_SIGNAL_SWAPBLOCK    (0x1UL)        /*!< Select BLOCKB as the blocking signal on PWMB */
#define EPWM_MINDB_POLSEL_INVERT_LOGICAL_AND    (0x0UL)        /*!< Minimum Dead Band Invert and perform logical AND */
#define EPWM_MINDB_POLSEL_LOGICAL_OR            (0x1UL)        /*!< Minimum Dead Band Block perform logical OR */

/**
  * @}
  */

/** @defgroup EPWM_MINDBCFGSELA defines for minimum dead band reference.
  * @{
  * @brief  Macro definitions for minimum dead band reference.
  */
#define EPWM_MINDB_SEL_DEPWM            (0x0UL)    /*!< Minimum Dead Band Reference signal */
#define EPWM_MINDB_SEL_OUTXBAR_OUT1     (0x1UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 1 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT2     (0x2UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 2 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT3     (0x3UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 3 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT4     (0x4UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 4 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT5     (0x5UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 5 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT6     (0x6UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 6 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT7     (0x7UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 7 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT8     (0x8UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 8 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT9     (0x9UL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 9 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT10    (0xAUL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 10 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT11    (0xBUL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 11 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT12    (0xCUL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 12 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT13    (0xDUL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 13 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT14    (0xEUL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 14 */
#define EPWM_MINDB_SEL_OUTXBAR_OUT15    (0xFUL)    /*!< Minimum Dead Band Reference Signal PWM Output Xbar 15 */

/**
  * @}
  */

/** @defgroup EPWM_LUTCTLA defines LUT control register on PWMA.
  * @{
  * @brief  Macro definitions for LUT control register on PWMA.
  */
#define EPWM_LUTCTLA_BYPASS     (0x1UL)         /*!< Bypass LUTA */
#define EPWM_LUTCTLA_LUTDEC0    (0x10000UL)     /*!< LUT output PWMA value on decoding 0 */
#define EPWM_LUTCTLA_LUTDEC1    (0x20000UL)     /*!< LUT output PWMA value on decoding 1 */
#define EPWM_LUTCTLA_LUTDEC2    (0x40000UL)     /*!< LUT output PWMA value on decoding 2 */
#define EPWM_LUTCTLA_LUTDEC3    (0x80000UL)     /*!< LUT output PWMA value on decoding 3 */
#define EPWM_LUTCTLA_LUTDEC4    (0x100000UL)    /*!< LUT output PWMA value on decoding 4 */
#define EPWM_LUTCTLA_LUTDEC5    (0x200000UL)    /*!< LUT output PWMA value on decoding 5 */
#define EPWM_LUTCTLA_LUTDEC6    (0x400000UL)    /*!< LUT output PWMA value on decoding 6 */
#define EPWM_LUTCTLA_LUTDEC7    (0x800000UL)    /*!< LUT output PWMA value on decoding 7 */

/**
  * @}
  */

/** @defgroup EPWM_MINDBICLXBAR Selects one of the 16 outputs of ICL XBAR to feed into IN3 of LUTA.
  * @{
  * @brief  Macro definitions for ICL XBAR selection.
  */
#define EPWM_MINDB_ICL_XBAR_OUT1     (0x0UL)    /*!< ICL Xbar Out 1 */
#define EPWM_MINDB_ICL_XBAR_OUT2     (0x1UL)    /*!< ICL Xbar Out 2 */
#define EPWM_MINDB_ICL_XBAR_OUT3     (0x2UL)    /*!< ICL Xbar Out 3 */
#define EPWM_MINDB_ICL_XBAR_OUT4     (0x3UL)    /*!< ICL Xbar Out 4 */
#define EPWM_MINDB_ICL_XBAR_OUT5     (0x4UL)    /*!< ICL Xbar Out 5 */
#define EPWM_MINDB_ICL_XBAR_OUT6     (0x5UL)    /*!< ICL Xbar Out 6 */
#define EPWM_MINDB_ICL_XBAR_OUT7     (0x6UL)    /*!< ICL Xbar Out 7 */
#define EPWM_MINDB_ICL_XBAR_OUT8     (0x7UL)    /*!< ICL Xbar Out 8 */
#define EPWM_MINDB_ICL_XBAR_OUT9     (0x8UL)    /*!< ICL Xbar Out 9 */
#define EPWM_MINDB_ICL_XBAR_OUT10    (0x9UL)    /*!< ICL Xbar Out 10 */
#define EPWM_MINDB_ICL_XBAR_OUT11    (0xAUL)    /*!< ICL Xbar Out 11 */
#define EPWM_MINDB_ICL_XBAR_OUT12    (0xBUL)    /*!< ICL Xbar Out 12 */
#define EPWM_MINDB_ICL_XBAR_OUT13    (0xCUL)    /*!< ICL Xbar Out 13 */
#define EPWM_MINDB_ICL_XBAR_OUT14    (0xDUL)    /*!< ICL Xbar Out 14 */
#define EPWM_MINDB_ICL_XBAR_OUT15    (0xEUL)    /*!< ICL Xbar Out 15 */
#define EPWM_MINDB_ICL_XBAR_OUT16    (0xFUL)    /*!< ICL Xbar Out 16 */
/**
  * @}
  */

/** @defgroup EPWM_MINDBICLLUTDEC Selects one of the 8 LUT DEC.
  * @{
  * @brief  Macro definitions for LUT DEC.
  */
#define EPWM_MINDB_ICL_LUT_DEC0    (0UL)    /*!< LUT output PWMA/B value on decoding 0 */
#define EPWM_MINDB_ICL_LUT_DEC1    (1UL)    /*!< LUT output PWMA/B value on decoding 1 */
#define EPWM_MINDB_ICL_LUT_DEC2    (2UL)    /*!< LUT output PWMA/B value on decoding 2 */
#define EPWM_MINDB_ICL_LUT_DEC3    (3UL)    /*!< LUT output PWMA/B value on decoding 3 */
#define EPWM_MINDB_ICL_LUT_DEC4    (4UL)    /*!< LUT output PWMA/B value on decoding 4 */
#define EPWM_MINDB_ICL_LUT_DEC5    (5UL)    /*!< LUT output PWMA/B value on decoding 5 */
#define EPWM_MINDB_ICL_LUT_DEC6    (6UL)    /*!< LUT output PWMA/B value on decoding 6 */
#define EPWM_MINDB_ICL_LUT_DEC7    (7UL)    /*!< LUT output PWMA/B value on decoding 7 */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup EPWM_XCMPUniversal universal macro definition in XCMP API
  * @{
  * @brief  Universal macro definition in XCMP API.
  */
#define ADDRESS_OFFSET_BETWEEN_XAQCTLA    (0x20UL)
#define LOW_16BIT_M                       (0xFFFFUL)
#define HIGH_16BIT_M                      (0xFFFF0000UL)

/**
  * @}
  */

/** @defgroup EPWM_XCMPCTL1 Complex Waveform Generator Mode Control Register Selection
  * @{
  * @brief  Macro definitions about Mode Control Register XCMPCTL1.
  */
#define EPWM_XCMPCTL1_XCMPEN           (0x1UL)     /*!< XCMP Compare Register Operation Enable */
#define EPWM_XCMPCTL1_XCMPSPLIT        (0x2UL)     /*!< XCMP Register Allocation Options */
#define EPWM_XCMPCTL1_XCMPA_ALLOC_S    (4UL)       /*!< XCMPn register allocation shift for CMPA */
#define EPWM_XCMPCTL1_XCMPA_ALLOC_M    (0xF0UL)    /*!< XCMPn register allocation for CMPA */
#define EPWM_XCMPCTL1_XCMPB_ALLOC_S    (8UL)       /*!< XCMPn register allocation shift for CMPB */
#define EPWM_XCMPCTL1_XCMPB_ALLOC_M    (0xF00UL)   /*!< XCMPn register allocation for CMPB */

/**
  * @}
  */

/** @defgroup EPWM_XLOADCTL Complex Waveform Generator Mode Load Control Register Selection
  * @{
  * @brief  Macro definitions about Mode Control Register XLOADCTL.
  */
#define EPWM_XLOADCTL_LOADMODE                     (0x4UL)           /*!< Load mode selection for Shadow registers */
#define EPWM_XLOADCTL_SHDWBUFPTR_LOADONCE_S        (8UL)             /*!< Register Load event count shift */
#define EPWM_XLOADCTL_SHDWBUFPTR_LOADONCE_M        (0x300UL)         /*!< Register Load event count */
#define EPWM_XLOADCTL_SHDWBUFPTR_LOADMULTIPLE_S    (10UL)            /*!< Register Load event count shift */
#define EPWM_XLOADCTL_SHDWBUFPTR_LOADMULTIPLE_M    (0xC00UL)         /*!< Register Load event count */

/**
  * @}
  */

/** @defgroup EPWM_XLOADCTLLOADMULTIPLE indicate the current shadow buffer.
  * @{
  * @brief  Macro definitions about the current shadow buffer.
  */
#define EPWM_XCMP_ACTIVE     (0x0UL)    /*!< XCMP set = Active */
#define EPWM_XCMP_SHADOW1    (0x1UL)    /*!< XCMP set = Shadow 1 */
#define EPWM_XCMP_SHADOW2    (0x2UL)    /*!< XCMP set = Shadow 2 */
#define EPWM_XCMP_SHADOW3    (0x3UL)    /*!< XCMP set = Shadow 3 */

/**
  * @}
  */

/** @defgroup EPWM_XLOAD indicate the mode load enable register.
  * @{
  * @brief  Macro definitions about the bit fields in the XLOAD register.
  */
#define EPWM_XLOAD_STARTLD    (0x1UL)    /*!< Enable register loading of shadow buffers */
#define EPWM_XLOAD_FRCLD      (0x2UL)    /*!< Force register loading of shadow buffers */

/**
  * @}
  */

/** @defgroup EPWM_XLOADLINK indicate the bit fields in the EPWMXLINKXLOAD register.
  * @{
  * @brief  Macro definitions about the bit fields in the EPWMXLINKXLOAD register.
  */
#define EPWM_XLINKXLOAD_XLOADLINK_S    (0UL)       /*!< XLOAD Link Register shift */
#define EPWM_XLINKXLOAD_XLOADLINK_M    (0x1FUL)    /*!< XLOAD Link Register */

/**
  * @}
  */

/** @defgroup EPWM_XLOADLINK indicate the bit fields in the XREGSHDW1STS register.
  * @{
  * @brief  Macro definitions about the bit fields in the XREGSHDW1STS register.
  */
#define EPWM_XREGSHDW1STS_XCMP1_SHDW1FULL      (0x1UL)       /*!< XCMP1_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP2_SHDW1FULL      (0x2UL)       /*!< XCMP2_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP3_SHDW1FULL      (0x4UL)       /*!< XCMP3_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP4_SHDW1FULL      (0x8UL)       /*!< XCMP4_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP5_SHDW1FULL      (0x10UL)      /*!< XCMP5_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP6_SHDW1FULL      (0x20UL)      /*!< XCMP6_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP7_SHDW1FULL      (0x40UL)      /*!< XCMP7_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XCMP8_SHDW1FULL      (0x80UL)      /*!< XCMP8_SHDW1 register full Status flag */
#define EPWM_XREGSHDW1STS_XTBPRD_SHDW1FULL     (0x100UL)     /*!< XTBPRD_SHDW1 register full Status flag: XTBPRD */
#define EPWM_XREGSHDW1STS_CMPC_SHDW1FULL       (0x200UL)     /*!< CMPC_SHDW1 register full Status flag: CMPC */
#define EPWM_XREGSHDW1STS_CMPD_SHDW1FULL       (0x400UL)     /*!< CMPD_SHDW1 register full Status flag: CMPD */
#define EPWM_XREGSHDW1STS_XAQCTLA_SHDW1FULL    (0x800UL)     /*!< XAQCTLA_SHDW1 register full Status flag: XAQCTLA */
#define EPWM_XREGSHDW1STS_XAQCTLB_SHDW1FULL    (0x1000UL)    /*!< XAQCTLB_SHDW1 register full Status flag: XAQCTLB */
#define EPWM_XREGSHDW1STS_XMAX_SHDW1FULL       (0x2000UL)    /*!< XMINMAX_SHDW1 register full Status flag: MAX field update */
#define EPWM_XREGSHDW1STS_XMIN_SHDW1FULL       (0x4000UL)    /*!< XMINMAX_SHDW1 register full Status flag: MIN field update */

/**
  * @}
  */

/** @defgroup EPWM_XLOADLINK indicate the bit fields in the XREGSHDW2STS register.
  * @{
  * @brief  Macro definitions about the bit fields in the XREGSHDW2STS register.
  */
#define EPWM_XREGSHDW2STS_XCMP1_SHDW2FULL      (0x1UL)       /*!< XCMP1_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP2_SHDW2FULL      (0x2UL)       /*!< XCMP2_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP3_SHDW2FULL      (0x4UL)       /*!< XCMP3_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP4_SHDW2FULL      (0x8UL)       /*!< XCMP4_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP5_SHDW2FULL      (0x10UL)      /*!< XCMP5_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP6_SHDW2FULL      (0x20UL)      /*!< XCMP6_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP7_SHDW2FULL      (0x40UL)      /*!< XCMP7_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XCMP8_SHDW2FULL      (0x80UL)      /*!< XCMP8_SHDW2 register full Status flag */
#define EPWM_XREGSHDW2STS_XTBPRD_SHDW2FULL     (0x100UL)     /*!< XTBPRD_SHDW2 register full Status flag: XTBPRD */
#define EPWM_XREGSHDW2STS_CMPC_SHDW2FULL       (0x200UL)     /*!< CMPC_SHDW2 register full Status flag: CMPC */
#define EPWM_XREGSHDW2STS_CMPD_SHDW2FULL       (0x400UL)     /*!< CMPD_SHDW2 register full Status flag: CMPD */
#define EPWM_XREGSHDW2STS_XAQCTLA_SHDW2FULL    (0x800UL)     /*!< XAQCTLA_SHDW2 register full Status flag: XAQCTLA */
#define EPWM_XREGSHDW2STS_XAQCTLB_SHDW2FULL    (0x1000UL)    /*!< XAQCTLB_SHDW2 register full Status flag: XAQCTLB */
#define EPWM_XREGSHDW2STS_XMAX_SHDW2FULL       (0x2000UL)    /*!< XMINMAX_SHDW2 register full Status flag: MAX field update */
#define EPWM_XREGSHDW2STS_XMIN_SHDW2FULL       (0x4000UL)    /*!< XMINMAX_SHDW2 register full Status flag: MIN field update */

/**
  * @}
  */

/** @defgroup EPWM_XLOADLINK indicate the bit fields in the XREGSHDW2STS register.
  * @{
  * @brief  Macro definitions about the bit fields in the XREGSHDW2STS register.
  */
#define EPWM_XREGSHDW3STS_XCMP1_SHDW3FULL      (0x1UL)       /*!< XCMP1_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP2_SHDW3FULL      (0x2UL)       /*!< XCMP2_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP3_SHDW3FULL      (0x4UL)       /*!< XCMP3_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP4_SHDW3FULL      (0x8UL)       /*!< XCMP4_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP5_SHDW3FULL      (0x10UL)      /*!< XCMP5_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP6_SHDW3FULL      (0x20UL)      /*!< XCMP6_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP7_SHDW3FULL      (0x40UL)      /*!< XCMP7_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XCMP8_SHDW3FULL      (0x80UL)      /*!< XCMP8_SHDW3 register full Status flag */
#define EPWM_XREGSHDW3STS_XTBPRD_SHDW3FULL     (0x100UL)     /*!< XTBPRD_SHDW3 register full Status flag: XTBPRD */
#define EPWM_XREGSHDW3STS_CMPC_SHDW3FULL       (0x200UL)     /*!< CMPC_SHDW3 register full Status flag: CMPC */
#define EPWM_XREGSHDW3STS_CMPD_SHDW3FULL       (0x400UL)     /*!< CMPD_SHDW3 register full Status flag: CMPD */
#define EPWM_XREGSHDW3STS_XAQCTLA_SHDW3FULL    (0x800UL)     /*!< XAQCTLA_SHDW3 register full Status flag: XAQCTLA */
#define EPWM_XREGSHDW3STS_XAQCTLB_SHDW3FULL    (0x1000UL)    /*!< XAQCTLB_SHDW3 register full Status flag: XAQCTLB */
#define EPWM_XREGSHDW3STS_XMAX_SHDW3FULL       (0x2000UL)    /*!< XMINMAX_SHDW3 register full Status flag: MAX field update */
#define EPWM_XREGSHDW3STS_XMIN_SHDW3FULL       (0x4000UL)    /*!< XMINMAX_SHDW3 register full Status flag: MIN field update */

/**
  * @}
  */

/** @defgroup EPWM_XAQCTLAACTIVE defines for the bit fields in the XAQCTLA_ACTIVE register.
  * @{
  * @brief  Macro definitions for the bit fields in the XAQCTLA_ACTIVE register.
  */
#define EPWM_XAQCTLA_ACTIVE_XCMP1_S    (0UL)         /*!< XCMP1 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP1_M    (0x3UL)       /*!< XCMP1 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP2_S    (2UL)         /*!< XCMP2 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP2_M    (0xCUL)       /*!< XCMP2 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP3_S    (4UL)         /*!< XCMP3 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP3_M    (0x30UL)      /*!< XCMP3 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP4_S    (6UL)         /*!< XCMP4 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP4_M    (0xC0UL)      /*!< XCMP4 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP5_S    (8UL)         /*!< XCMP5 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP5_M    (0x300UL)     /*!< XCMP5 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP6_S    (10UL)        /*!< XCMP6 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP6_M    (0xC00UL)     /*!< XCMP6 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP7_S    (12UL)        /*!< XCMP7 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP7_M    (0x3000UL)    /*!< XCMP7 Action */
#define EPWM_XAQCTLA_ACTIVE_XCMP8_S    (14UL)        /*!< XCMP8 Action shift */
#define EPWM_XAQCTLA_ACTIVE_XCMP8_M    (0xC000UL)    /*!< XCMP8 Action */

/**
  * @}
  */

/** @defgroup EPWM_DEADBANDINPUT EPWM Dead Band Input
  * @{
  * @brief  Macro definitions abou PWM dead band input for the bit fields in the DBCTL register.
  */
#define EPWM_DB_INPUT_EPWMA     (0x00000000UL)    /*!< Input signal is ePWMA */
#define EPWM_DB_INPUT_EPWMB     (0x00000001UL)    /*!< Input signal is ePWMB */
#define EPWM_DB_INPUT_DB_RED    (0x00000002UL)    /*!< Input signal is the output of Rising Edge delay */

/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_EPWM_H__ */
