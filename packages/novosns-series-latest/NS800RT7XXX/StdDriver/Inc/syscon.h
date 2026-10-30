/**
  * @file       syscon.h
  * @author     wangxin & mengyutai
  * @brief      Header file for NS800RT7xxx SYSCON module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SYSCON_H__
#define __SYSCON_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_syscon.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SYSCON_EXPORTED_TYPES SYSCON Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'SYSCON' module.
  */

/** @defgroup SYSCON_SPI1NCSSEL SYSCON SPI1 NCS Pin Select
  * @{
  * @brief  Macro definitions about SYSCON SPI1 NCS pin select.
  *         Values that can be passed to SYSCON_setSpi1Ncs() as the \e spi1Ncs parameter.
  */
typedef enum {
    SYSCON_SPI1NCS_SEL_HIGH = 0U,    /*!< fixed high level */
    SYSCON_SPI1NCS_SEL_PA19,         /*!< PA19 */
    SYSCON_SPI1NCS_SEL_PB3,          /*!< PB3 */
    SYSCON_SPI1NCS_SEL_PB25,         /*!< PB25 */
    SYSCON_SPI1NCS_SEL_PB29,         /*!< PB29 */
    SYSCON_SPI1NCS_SEL_PG13          /*!< PG13 */
} SYSCON_Spi1NcsSel;

/**
  * @}
  */

/** @defgroup SYSCON_SPI2NCSSEL SYSCON SPI2 NCS Pin Select
  * @{
  * @brief  Macro definitions about SYSCON NCS2 ssn pin select.
  *         Values that can be passed to SYSCON_setSpi2Ncs() as the \e spi2Ncs parameter.
  */
typedef enum {
    SYSCON_SPI2NCS_SEL_HIGH = 0U,    /*!< fixed high level */
    SYSCON_SPI2NCS_SEL_PA23,         /*!< PA23 */
    SYSCON_SPI2NCS_SEL_PA27,         /*!< PA27 */
    SYSCON_SPI2NCS_SEL_PB27,         /*!< PB27 */
    SYSCON_SPI2NCS_SEL_PC2,          /*!< PC2 */
    SYSCON_SPI2NCS_SEL_PF17,         /*!< PF17  */
    SYSCON_SPI2NCS_SEL_PG8,          /*!< PG8 */
    SYSCON_SPI2NCS_SEL_PG12          /*!< PG12 */
} SYSCON_Spi2NcsSel;

/**
  * @}
  */

/** @defgroup SYSCON_SPI3NCSSEL SYSCON SPI3 NCS Pin Select
  * @{
  * @brief  Macro definitions about SYSCON SPI3 NCS pin select.
  *         Values that can be passed to SYSCON_setSpi3Ncs() as the \e spi3Ncs parameter.
  */
typedef enum {
    SYSCON_SPI3NCS_SEL_HIGH = 0U,    /*!< fixed high level */
    SYSCON_SPI3NCS_SEL_PA23,         /*!< PA23 */
    SYSCON_SPI3NCS_SEL_PB21,         /*!< PB21 */
    SYSCON_SPI3NCS_SEL_PC8,          /*!< PC8 */
    SYSCON_SPI3NCS_SEL_PD7,          /*!< PD7 */
    SYSCON_SPI3NCS_SEL_PG8,          /*!< PG8 */
    SYSCON_SPI3NCS_SEL_PG31          /*!< PG31 */
} SYSCON_Spi3NcsSel;

/**
  * @}
  */
  
/** @defgroup SYSCON_SPI4NCSSEL SYSCON Spi4 NCS Pin Select
  * @{
  * @brief  Macro definitions about SYSCON SPI4 NCS pin select.
  *         Values that can be passed to SYSCON_setSpi4Ncs() as the \e spi4Ncs parameter.
  */
typedef enum {
    SYSCON_SPI4NCS_SEL_HIGH = 0U,    /*!< fixed high level */
    SYSCON_SPI4NCS_SEL_PA31,         /*!< PA31 */
    SYSCON_SPI4NCS_SEL_PB1,          /*!< PB1 */
    SYSCON_SPI4NCS_SEL_PB13,         /*!< PB13 */
    SYSCON_SPI4NCS_SEL_PC25,         /*!< PC25 */
    SYSCON_SPI4NCS_SEL_PC30          /*!< PC30 */
} SYSCON_Spi4NcsSel;

/**
  * @}
  */

/** @defgroup SYSCON_EXTIPINSEL SYSCON EXTI Pin Select
  * @{
  * @brief  Macro definitions about SYSCON EXTI pin select.
  *         Values that can be passed to SYSCON_setExtiSel() as the \e pinSel parameter.
  */
typedef enum {
    SYSCON_EXTI_PINSEL_0 = 0U,    /*!< pin select 0 */
    SYSCON_EXTI_PINSEL_1,         /*!< pin select 1 */
    SYSCON_EXTI_PINSEL_2,         /*!< pin select 2 */
    SYSCON_EXTI_PINSEL_3,         /*!< pin select 3 */
    SYSCON_EXTI_PINSEL_4,         /*!< pin select 4 */
    SYSCON_EXTI_PINSEL_5,         /*!< pin select 5 */
    SYSCON_EXTI_PINSEL_6,         /*!< pin select 6 */
    SYSCON_EXTI_PINSEL_7,         /*!< pin select 7 */
    SYSCON_EXTI_PINSEL_8,         /*!< pin select 8 */
    SYSCON_EXTI_PINSEL_9,         /*!< pin select 9 */
    SYSCON_EXTI_PINSEL_10,        /*!< pin select 10 */
    SYSCON_EXTI_PINSEL_11,        /*!< pin select 11 */
    SYSCON_EXTI_PINSEL_12,        /*!< pin select 12 */
    SYSCON_EXTI_PINSEL_13,        /*!< pin select 13 */
    SYSCON_EXTI_PINSEL_14,        /*!< pin select 14 */
    SYSCON_EXTI_PINSEL_15         /*!< pin select 15 */
} SYSCON_ExtiPinSel;

/**
  * @}
  */

/** @defgroup SYSCON_EXTISEL SYSCON EXTI Select
  * @{
  * @brief  Macro definitions about SYSCON EXTI select.
  *         Values that can be passed to SYSCON_setExtiSel() as the \e sel parameter.
  */
typedef enum {
    SYSCON_EXTISEL_0 = 0U,    /*!< exti select 0 */
    SYSCON_EXTISEL_1,         /*!< exti select 1 */
    SYSCON_EXTISEL_2,         /*!< exti select 2 */
    SYSCON_EXTISEL_3,         /*!< exti select 3 */
    SYSCON_EXTISEL_4,         /*!< exti select 4 */
    SYSCON_EXTISEL_5,         /*!< exti select 5 */
    SYSCON_EXTISEL_6,         /*!< exti select 6 */
    SYSCON_EXTISEL_7,         /*!< exti select 7 */
    SYSCON_EXTISEL_8,         /*!< exti select 8 */
    SYSCON_EXTISEL_9,         /*!< exti select 9 */
    SYSCON_EXTISEL_10,        /*!< exti select 10 */
    SYSCON_EXTISEL_11,        /*!< exti select 11 */
    SYSCON_EXTISEL_12,        /*!< exti select 12 */
    SYSCON_EXTISEL_13,        /*!< exti select 13 */
    SYSCON_EXTISEL_14,        /*!< exti select 14 */
    SYSCON_EXTISEL_15         /*!< exti select 15 */
} SYSCON_ExtiSel;

/**
  * @}
  */

/** @defgroup SYSCON_SYNCOUTCRSEL SYSCON SYNCOUT Select
  * @{
  * @brief  Macro definitions about SYSCON SYNCOUT select.
  *         Values that can be passed to SYSCON_setSyncOutSel() as the \e sel parameter.
  */
typedef enum {
    SYSCON_SYNCOUTSEL_EPWM1 = 0U,       /*!< EPWM1 */
    SYSCON_SYNCOUTSEL_EPWM2,            /*!< EPWM2 */
    SYSCON_SYNCOUTSEL_EPWM3,            /*!< EPWM3 */
    SYSCON_SYNCOUTSEL_EPWM4,            /*!< EPWM4 */
    SYSCON_SYNCOUTSEL_EPWM5,            /*!< EPWM5 */
    SYSCON_SYNCOUTSEL_EPWM6,            /*!< EPWM6 */
    SYSCON_SYNCOUTSEL_EPWM7,            /*!< EPWM7 */
    SYSCON_SYNCOUTSEL_EPWM8,            /*!< EPWM8 */
    SYSCON_SYNCOUTSEL_EPWM9,            /*!< EPWM9 */
    SYSCON_SYNCOUTSEL_EPWM10,           /*!< EPWM10 */
    SYSCON_SYNCOUTSEL_EPWM11,           /*!< EPWM11 */
    SYSCON_SYNCOUTSEL_EPWM12,           /*!< EPWM12 */
    SYSCON_SYNCOUTSEL_EPWM13,           /*!< EPWM13 */
    SYSCON_SYNCOUTSEL_EPWM14,           /*!< EPWM14 */
    SYSCON_SYNCOUTSEL_EPWM15,           /*!< EPWM15 */
    SYSCON_SYNCOUTSEL_EPWM16,           /*!< EPWM16 */
    SYSCON_SYNCOUTSEL_EPWM17,           /*!< EPWM17 */
    SYSCON_SYNCOUTSEL_EPWM18,           /*!< EPWM18 */
    SYSCON_SYNCOUTSEL_ECAP1 = 0x18U,    /*!< ECAP1 */
    SYSCON_SYNCOUTSEL_ECAP2,            /*!< ECAP2 */
    SYSCON_SYNCOUTSEL_ECAP3,            /*!< ECAP3 */
    SYSCON_SYNCOUTSEL_ECAP4,            /*!< ECAP4 */
    SYSCON_SYNCOUTSEL_ECAP5,            /*!< ECAP5 */
    SYSCON_SYNCOUTSEL_ECAP6,            /*!< ECAP6 */
    SYSCON_SYNCOUTSEL_ECAP7             /*!< ECAP7 */
} SYSCON_SyncoutCrSel;

/**
  * @}
  */

/** @defgroup SYSCON_EPWMSOCAEN SYSCON EPWMSOCA Enable
  * @{
  * @brief  Macro definitions about SYSCON EPWMSOCA enable.
  *         Values that can be passed to SYSCON_enableEpwmSocA() as the \e epwmNum parameter.
  */
typedef enum {
    SYSCON_EPWM1SOCAEN = 0U,    /*!< EPWM1SOCAEN */
    SYSCON_EPWM2SOCAEN,         /*!< EPWM2SOCAEN */
    SYSCON_EPWM3SOCAEN,         /*!< EPWM3SOCAEN */
    SYSCON_EPWM4SOCAEN,         /*!< EPWM4SOCAEN */
    SYSCON_EPWM5SOCAEN,         /*!< EPWM5SOCAEN */
    SYSCON_EPWM6SOCAEN,         /*!< EPWM6SOCAEN */
    SYSCON_EPWM7SOCAEN,         /*!< EPWM7SOCAEN */
    SYSCON_EPWM8SOCAEN,         /*!< EPWM8SOCAEN */
    SYSCON_EPWM9SOCAEN,         /*!< EPWM9SOCAEN */
    SYSCON_EPWM10SOCAEN,        /*!< EPWM10SOCAEN */
    SYSCON_EPWM11SOCAEN,        /*!< EPWM11SOCAEN */
    SYSCON_EPWM12SOCAEN,        /*!< EPWM12SOCAEN */
    SYSCON_EPWM13SOCAEN,        /*!< EPWM13SOCAEN */
    SYSCON_EPWM14SOCAEN,        /*!< EPWM14SOCAEN */
    SYSCON_EPWM15SOCAEN,        /*!< EPWM15SOCAEN */
    SYSCON_EPWM16SOCAEN,        /*!< EPWM16SOCAEN */
    SYSCON_EPWM17SOCAEN,        /*!< EPWM17SOCAEN */
    SYSCON_EPWM18SOCAEN         /*!< EPWM18SOCAEN */
} SYSCON_EpwmSocAEn;

/**
  * @}
  */

/** @defgroup SYSCON_EPWMSOCBEN SYSCON EPWMSOCB Enable
  * @{
  * @brief  Macro definitions about SYSCON EPWMSOCB enable.
  *         Values that can be passed to SYSCON_enableEpwmSocB() as the \e epwmNum parameter.
  */
typedef enum {
    SYSCON_EPWM1SOCBEN = 0U,    /*!< EPWM1SOCBEN */
    SYSCON_EPWM2SOCBEN,         /*!< EPWM2SOCBEN */
    SYSCON_EPWM3SOCBEN,         /*!< EPWM3SOCBEN */
    SYSCON_EPWM4SOCBEN,         /*!< EPWM4SOCBEN */
    SYSCON_EPWM5SOCBEN,         /*!< EPWM5SOCBEN */
    SYSCON_EPWM6SOCBEN,         /*!< EPWM6SOCBEN */
    SYSCON_EPWM7SOCBEN,         /*!< EPWM7SOCBEN */
    SYSCON_EPWM8SOCBEN,         /*!< EPWM8SOCBEN */
    SYSCON_EPWM9SOCBEN,         /*!< EPWM9SOCBEN */
    SYSCON_EPWM10SOCBEN,        /*!< EPWM10SOCBEN */
    SYSCON_EPWM11SOCBEN,        /*!< EPWM11SOCBEN */
    SYSCON_EPWM12SOCBEN,        /*!< EPWM12SOCBEN */
    SYSCON_EPWM13SOCBEN,        /*!< EPWM13SOCBEN */
    SYSCON_EPWM14SOCBEN,        /*!< EPWM14SOCBEN */
    SYSCON_EPWM15SOCBEN,        /*!< EPWM15SOCBEN */
    SYSCON_EPWM16SOCBEN,        /*!< EPWM16SOCBEN */
    SYSCON_EPWM17SOCBEN,        /*!< EPWM17SOCBEN */
    SYSCON_EPWM18SOCBEN         /*!< EPWM18SOCBEN */
} SYSCON_EpwmSocBEn;

/**
  * @}
  */

/** @defgroup SYSCON_DOZEMODULEID SYSCON Peripheral DOZE Request
  * @{
  * @brief  Macro definitions about SYSCON Peripheral doze Request.
  *         Values that can be passed to SYSCON_setPDozeReq() as the \e id parameter.
  */
typedef enum {
    MODULE_DOZE_CAN1 = 0U,    /*!< CAN1 */
    MODULE_DOZE_CANFD1,       /*!< CANFD1 */
    MODULE_DOZE_CANFD2        /*!< CANFD2 */
} SYSCON_DozeModuleId;

/**
  * @}
  */

/** @defgroup SYSCON_STOPMODULEID SYSCON Peripheral STOP Request
  * @{
  * @brief  Macro definitions about SYSCON Peripheral stop Request.
  *         Values that can be passed to SYSCON_setPStopReq() as the \e id parameter.
  */
typedef enum {
    MODULE_STOP_CAN1 = 0U,    /*!< CAN1 */
    MODULE_STOP_CANFD1,       /*!< CANFD1 */
    MODULE_STOP_CANFD2,       /*!< CANFD2 */
    MODULE_STOP_EMIF,         /*!< EMIF */
    MODULE_STOP_EDMA1,        /*!< EDMA1 */
    MODULE_STOP_EDMA2,        /*!< EDMA2 */
    MODULE_STOP_TRNG = 15U    /*!< TRNG */
} SYSCON_StopModuleId;

/**
  * @}
  */

/** @defgroup SYSCON_COMMON_MACRO SYSCON Common Macro
  * @{
  * @brief  Macro definitions about SYSCON unlcok/lock definition.
  */
#define SYSCON_DEFAULT_KEY         (0x5A690000UL)    /*!< Default key */
#define SYSCON_DEFAULT_KEY_MASK    (0xFFFF0000UL)    /*!< Default key Mask */

/**
  * @}
  */

/** @defgroup SYSCON_NMIFLG SYSCON NMI Flag Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI flag register definition.
  */
#define SYSCON_NMIFLG_NMIINT               (SYSCON_NMIFLG_NMIINT_M)            /*!< NMI interrupt flag bit */
#define SYSCON_NMIFLG_HXTLSTOP             (SYSCON_NMIFLG_HXTLSTOP_M)          /*!< HXTL STOP flag */
#define SYSCON_NMIFLG_FLASH_ECCERR         (SYSCON_NMIFLG_FLASH_ECCERR_M)      /*!< FLASH_ECCERR flag */
#define SYSCON_NMIFLG_SRAM1_ECCERR         (SYSCON_NMIFLG_SRAM1_ECCERR_M)      /*!< SRAM1_ECCERR flag */
#define SYSCON_NMIFLG_SRAM2_ECCERR         (SYSCON_NMIFLG_SRAM2_ECCERR_M)      /*!< SRAM2_ECCERR flag */
#define SYSCON_NMIFLG_DTCM_ECCERR          (SYSCON_NMIFLG_DTCM_ECCERR_M)       /*!< DTCM _ECCERR flag */
#define SYSCON_NMIFLG_ITCM_ECCERR          (SYSCON_NMIFLG_ITCM_ECCERR_M)       /*!< ITCM_ECCERR flag */
#define SYSCON_NMIFLG_BKSRAM_PARERR        (SYSCON_NMIFLG_BKSRAM_PARERR_M)     /*!< BKSRAM_PARERR flag */
#define SYSCON_NMIFLG_MCD_NMI              (SYSCON_NMIFLG_MCD_NMI_M)           /*!< MCD_NMI flag */
#define SYSCON_NMIFLG_SMPU_ERR             (SYSCON_NMIFLG_SMPU_ERR_M)          /*!< SMPU_ERR flag */
#define SYSCON_NMIFLG_LVD_NMI              (SYSCON_NMIFLG_LVD_NMI_M)           /*!< LVD_NMI flag */
#define SYSCON_NMIFLG_OSCCLKSTOP           (SYSCON_NMIFLG_OSCCLKSTOP_M)        /*!< OSCCLKSTOP flag */
#define SYSCON_NMIFLG_CAN1NCE              (SYSCON_NMIFLG_CAN1NCE_M)           /*!< CAN1 NCE flag */
#define SYSCON_NMIFLG_CANFD1NCE            (SYSCON_NMIFLG_CANFD1NCE_M)         /*!< CANFD1 NCE flag */
#define SYSCON_NMIFLG_CANFD2NCE            (SYSCON_NMIFLG_CANFD2NCE_M)         /*!< CANFD2 NCE flag */
#define SYSCON_NMIFLG_SW_ERR               (SYSCON_NMIFLG_SW_ERR_M)            /*!< SW_ERR flag */
#define SYSCON_NMIFLG_CLB1_NMI             (SYSCON_NMIFLG_CLB1_NMI_M)          /*!< CLB1_NMI flag */
#define SYSCON_NMIFLG_CLB2_NMI             (SYSCON_NMIFLG_CLB2_NMI_M)          /*!< CLB2_NMI flag */
#define SYSCON_NMIFLG_CLB3_NMI             (SYSCON_NMIFLG_CLB3_NMI_M)          /*!< CLB3_NMI flag */
#define SYSCON_NMIFLG_CLB4_NMI             (SYSCON_NMIFLG_CLB4_NMI_M)          /*!< CLB4_NMI flag */
#define SYSCON_NMIFLG_CLB5_NMI             (SYSCON_NMIFLG_CLB5_NMI_M)          /*!< CLB5_NMI flag */
#define SYSCON_NMIFLG_CLB6_NMI             (SYSCON_NMIFLG_CLB6_NMI_M)          /*!< CLB6_NMI flag */
#define SYSCON_NMIFLG_CPU2_NMIWDTRST       (SYSCON_NMIFLG_CPU2_NMIWDTRST_M)    /*!< CPU2_NMIWDT flag */
#define SYSCON_NMIFLG_CPU2_WWDGRST         (SYSCON_NMIFLG_CPU2_WWDGRST_M)      /*!< CPU2_WWDGRST flag */
#define SYSCON_NMIFLG_CPU2_IWDG1RST        (SYSCON_NMIFLG_CPU2_IWDG1RST_M)     /*!< CPU2_IWDG1RST flag */
#define SYSCON_NMIFLG_CPU2_LOCKUPRST       (SYSCON_NMIFLG_CPU2_LOCKUPRST_M)    /*!< CPU2_LOCKUPRST flag */
#define SYSCON_NMIFLG_CPU2_SOFTRST         (SYSCON_NMIFLG_CPU2_SOFTRST_M)      /*!< CPU2_SOFTRST flag */

/**
  * @}
  */

/** @defgroup SYSCON_NMIFLGCLR SYSCON NMI Flag Clear Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI flag clear register definition.
  */
#define SYSCON_NMIFLGCLR_NMIINT            (SYSCON_NMIFLGCLR_NMIINT_M)            /*!< NMI interrupt flag clear bit */
#define SYSCON_NMIFLGCLR_HXTLSTOP          (SYSCON_NMIFLGCLR_HXTLSTOP_M)          /*!< HXTL STOP flag clear bit */
#define SYSCON_NMIFLGCLR_FLASH_ECCERR      (SYSCON_NMIFLGCLR_FLASH_ECCERR_M)      /*!< FLASH_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_SRAM1_ECCERR      (SYSCON_NMIFLGCLR_SRAM1_ECCERR_M)      /*!< SRAM1_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_SRAM2_ECCERR      (SYSCON_NMIFLGCLR_SRAM2_ECCERR_M)      /*!< SRAM2_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_DTCM_ECCERR       (SYSCON_NMIFLGCLR_DTCM_ECCERR_M)       /*!< DTCM_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_ITCM_ECCERR       (SYSCON_NMIFLGCLR_ITCM_ECCERR_M)       /*!< ITCM_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_BKSRAM_PARERR     (SYSCON_NMIFLGCLR_BKSRAM_PARERR_M)     /*!< BKSRAM_PARERR flag clear bit */
#define SYSCON_NMIFLGCLR_MCD_NMI           (SYSCON_NMIFLGCLR_MCD_NMI_M)           /*!< MCD_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_SMPU_ERR          (SYSCON_NMIFLGCLR_SMPU_ERR_M)          /*!< SMPU_ERR flag clear bit */
#define SYSCON_NMIFLGCLR_LVD_NMI           (SYSCON_NMIFLGCLR_LVD_NMI_M)           /*!< LVD_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_OSCCLKSTOP        (SYSCON_NMIFLGCLR_OSCCLKSTOP_M)        /*!< OSCCLKSTOP flag clear bit */
#define SYSCON_NMIFLGCLR_CAN1NCE           (SYSCON_NMIFLGCLR_CAN1NCE_M)           /*!< CAN1NCE flag clear bit */
#define SYSCON_NMIFLGCLR_CANFD1NCE         (SYSCON_NMIFLGCLR_CANFD1NCE_M)         /*!< CANFD1NCE flag clear bit */
#define SYSCON_NMIFLGCLR_CANFD2NCE         (SYSCON_NMIFLGCLR_CANFD2NCE_M)         /*!< CANFD2NCE flag clear bit */
#define SYSCON_NMIFLGCLR_SW_ERR            (SYSCON_NMIFLGCLR_SW_ERR_M)            /*!< SW_ERR flag clear bit */
#define SYSCON_NMIFLGCLR_CLB1_NMI          (SYSCON_NMIFLGCLR_CLB1_NMI_M)          /*!< CLB1_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_CLB2_NMI          (SYSCON_NMIFLGCLR_CLB2_NMI_M)          /*!< CLB2_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_CLB3_NMI          (SYSCON_NMIFLGCLR_CLB3_NMI_M)          /*!< CLB3_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_CLB4_NMI          (SYSCON_NMIFLGCLR_CLB4_NMI_M)          /*!< CLB4_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_CLB5_NMI          (SYSCON_NMIFLGCLR_CLB5_NMI_M)          /*!< CLB5_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_CLB6_NMI          (SYSCON_NMIFLGCLR_CLB6_NMI_M)          /*!< CLB6_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_CPU2_NMIWDTRST    (SYSCON_NMIFLGCLR_CPU2_NMIWDTRST_M)    /*!< CPU2_NMIWDTRST flag clear bit */
#define SYSCON_NMIFLGCLR_CPU2_WWDGRST      (SYSCON_NMIFLGCLR_CPU2_WWDGRST_M)      /*!< CPU2_WWDGRST flag clear bit */
#define SYSCON_NMIFLGCLR_CPU2_IWDGRST      (SYSCON_NMIFLGCLR_CPU2_IWDGRST_M)      /*!< CPU2_IWDGRST flag clear bit */
#define SYSCON_NMIFLGCLR_CPU2_LOCKUPRST    (SYSCON_NMIFLGCLR_CPU2_LOCKUPRST_M)    /*!< CPU2_LOCKUPRST flag clear bit */
#define SYSCON_NMIFLGCLR_CPU2_SOFTRST      (SYSCON_NMIFLGCLR_CPU2_SOFTRST_M)      /*!< CPU2_SOFTRST flag clear bit */

/**
  * @}
  */

/** @defgroup SYSCON_NMIFLGFRC SYSCON NMI Flag Force Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI flag force register definition.
  */
#define SYSCON_NMIFLGFRC_HXTLSTOP          (SYSCON_NMIFLGFRC_HXTLSTOP_M)          /*!< HXTL STOP flag force bit */
#define SYSCON_NMIFLGFRC_FLASH_ECCERR      (SYSCON_NMIFLGFRC_FLASH_ECCERR_M)      /*!< FLASH_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_SRAM1_ECCERR      (SYSCON_NMIFLGFRC_SRAM1_ECCERR_M)      /*!< SRAM1_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_SRAM2_ECCERR      (SYSCON_NMIFLGFRC_SRAM2_ECCERR_M)      /*!< SRAM2_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_DTCM_ECCERR       (SYSCON_NMIFLGFRC_DTCM_ECCERR_M)       /*!< DTCM_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_ITCM_ECCERR       (SYSCON_NMIFLGFRC_ITCM_ECCERR_M)       /*!< ITCM_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_BKSRAM_PARERR     (SYSCON_NMIFLGFRC_BKSRAM_PARERR_M)     /*!< BKSRAM_PARERR flag clear bit */
#define SYSCON_NMIFLGFRC_MCD_NMI           (SYSCON_NMIFLGFRC_MCD_NMI_M)           /*!< MCD_NMI flag clear bit */
#define SYSCON_NMIFLGFRC_SMPU_ERR          (SYSCON_NMIFLGFRC_SMPU_ERR_M)          /*!< SMPU_ERR flag force bit */
#define SYSCON_NMIFLGFRC_LVD_NMI           (SYSCON_NMIFLGFRC_LVD_NMI_M)           /*!< LVD_NMI flag force bit */
#define SYSCON_NMIFLGFRC_OSCCLKSTOP        (SYSCON_NMIFLGFRC_OSCCLKSTOP_M)        /*!< OSCCLKSTOP flag clear bit */
#define SYSCON_NMIFLGFRC_CAN1NCE           (SYSCON_NMIFLGFRC_CAN1NCE_M)           /*!< CAN1NCE flag force bit */
#define SYSCON_NMIFLGFRC_CANFD1NCE         (SYSCON_NMIFLGFRC_CANFD1NCE_M)         /*!< CANFD1NCE flag force bit */
#define SYSCON_NMIFLGFRC_CANFD2NCE         (SYSCON_NMIFLGFRC_CANFD2NCE_M)         /*!< CANFD2NCE flag force bit */
#define SYSCON_NMIFLGFRC_SW_ERR            (SYSCON_NMIFLGFRC_SW_ERR_M)            /*!< SW_ERR flag force bit */
#define SYSCON_NMIFLGFRC_CLB1_NMI          (SYSCON_NMIFLGFRC_CLB1_NMI_M)          /*!< CLB1_NMI flag force bit */
#define SYSCON_NMIFLGFRC_CLB2_NMI          (SYSCON_NMIFLGFRC_CLB2_NMI_M)          /*!< CLB2_NMI flag force bit */
#define SYSCON_NMIFLGFRC_CLB3_NMI          (SYSCON_NMIFLGFRC_CLB3_NMI_M)          /*!< CLB3_NMI flag force bit */
#define SYSCON_NMIFLGFRC_CLB4_NMI          (SYSCON_NMIFLGFRC_CLB4_NMI_M)          /*!< CLB4_NMI flag force bit */
#define SYSCON_NMIFLGFRC_CLB5_NMI          (SYSCON_NMIFLGFRC_CLB5_NMI_M)          /*!< CLB5_NMI flag force bit */
#define SYSCON_NMIFLGFRC_CLB6_NMI          (SYSCON_NMIFLGFRC_CLB6_NMI_M)          /*!< CLB6_NMI flag force bit */
#define SYSCON_NMIFLGFRC_CPU2_NMIWDTRST    (SYSCON_NMIFLGFRC_CPU2_NMIWDTRST_M)    /*!< CPU2_NMIWDTRST flag force bit */
#define SYSCON_NMIFLGFRC_CPU2_WWDGRST      (SYSCON_NMIFLGFRC_CPU2_WWDGRST_M)      /*!< CPU2_WWDGRST flag force bit */
#define SYSCON_NMIFLGFRC_CPU2_IWDGRST      (SYSCON_NMIFLGFRC_CPU2_IWDGRST_M)      /*!< CPU2_IWDGRST flag force bit */
#define SYSCON_NMIFLGFRC_CPU2_LOCKUPRST    (SYSCON_NMIFLGFRC_CPU2_LOCKUPRST_M)    /*!< CPU2_LOCKUPRST flag force bit */
#define SYSCON_NMIFLGFRC_CPU2_SOFTRST      (SYSCON_NMIFLGFRC_CPU2_SOFTRST_M)      /*!< CPU2_SOFTRST flag clear bit */

/**
  * @}
  */

/** @defgroup SYSCON_NMISHDFLG SYSCON NMI Shadow Flag Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI shadow flag register definition.
  */
#define SYSCON_NMISHDFLG_HXTLSTOP          (SYSCON_NMISHDFLG_HXTLSTOP_M)          /*!< CLOCKFAIL shadow NMI flag */
#define SYSCON_NMISHDFLG_FLASH_ECCERR      (SYSCON_NMISHDFLG_FLASH_ECCERR_M)      /*!< FLASH_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_SRAM1_ECCERR      (SYSCON_NMISHDFLG_SRAM1_ECCERR_M)      /*!< SRAM1_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_SRAM2_ECCERR      (SYSCON_NMISHDFLG_SRAM2_ECCERR_M)      /*!< SRAM2_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_DTCM_ECCERR       (SYSCON_NMISHDFLG_DTCM_ECCERR_M)       /*!< DTCM_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_ITCM_ECCERR       (SYSCON_NMISHDFLG_ITCM_ECCERR_M)       /*!< ITCM_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_BKSRAM_PARERR     (SYSCON_NMISHDFLG_BKSRAM_PARERR_M)     /*!< BKSRAM_PARERR shadow NMI flag */
#define SYSCON_NMISHDFLG_MCD_NMI           (SYSCON_NMISHDFLG_MCD_NMI_M)           /*!< MCD_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_SMPU_ERR          (SYSCON_NMISHDFLG_SMPU_ERR_M)          /*!< SMPU_ERR shadow NMI flag */
#define SYSCON_NMISHDFLG_LVD_NMI           (SYSCON_NMISHDFLG_LVD_NMI_M)           /*!< LVD_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CAN1NCE           (SYSCON_NMISHDFLG_CAN1NCE_M)           /*!< CAN1NCE shadow NMI flag */
#define SYSCON_NMISHDFLG_CANFD1NCE         (SYSCON_NMISHDFLG_CANFD1NCE_M)         /*!< CANFD1NCE shadow NMI flag */
#define SYSCON_NMISHDFLG_CANFD2NCE         (SYSCON_NMISHDFLG_CANFD2NCE_M)         /*!< CANFD2NCE shadow NMI flag */
#define SYSCON_NMISHDFLG_SW_ERR            (SYSCON_NMISHDFLG_SW_ERR_M)            /*!< SW_ERR shadow NMI flag */
#define SYSCON_NMISHDFLG_CLB1_NMI          (SYSCON_NMISHDFLG_CLB1_NMI_M)          /*!< CLB1_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CLB2_NMI          (SYSCON_NMISHDFLG_CLB2_NMI_M)          /*!< CLB2_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CLB3_NMI          (SYSCON_NMISHDFLG_CLB3_NMI_M)          /*!< CLB3_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CLB4_NMI          (SYSCON_NMISHDFLG_CLB4_NMI_M)          /*!< CLB4_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CLB5_NMI          (SYSCON_NMISHDFLG_CLB5_NMI_M)          /*!< CLB5_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CLB6_NMI          (SYSCON_NMISHDFLG_CLB6_NMI_M)          /*!< CLB6_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_CPU2_NMIWDTRST    (SYSCON_NMISHDFLG_CPU2_NMIWDTRST_M)    /*!< CPU2_NMIWDTRST shadow NMI flag */
#define SYSCON_NMISHDFLG_CPU2_WWDGRST      (SYSCON_NMISHDFLG_CPU2_WWDGRST_M)      /*!< CPU2_WWDGRST shadow NMI flag */
#define SYSCON_NMISHDFLG_CPU2_IWDGRST      (SYSCON_NMISHDFLG_CPU2_IWDGRST_M)      /*!< CPU2_IWDGRST shadow NMI flag */
#define SYSCON_NMISHDFLG_CPU2_LOCKUPRST    (SYSCON_NMISHDFLG_CPU2_LOCKUPRST_M)    /*!< CPU2_LOCKUPRST shadow NMI flag */
#define SYSCON_NMISHDFLG_CPU2_SOFTRST      (SYSCON_NMISHDFLG_CPU2_SOFTRST_M)      /*!< CPU2_SOFTRST shadow NMI flag */

/**
  * @}
  */

/** @defgroup SYSCON_UNLOCK SYSCON UnLock Register
  * @{
  * @brief  Macro definitions about writing register UNLOCK
  */
#define SYSCON_LOCK      SYSCON->UNLOCK.WORDVAL = 0x55AA6698; __DSB()
#define SYSCON_UNLOCK    SYSCON->UNLOCK.WORDVAL = 0x55AA6699; __DSB()

/**
  * @}
  */

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
  * \brief  Set Cortex-M7 LockUp enable.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - true : LockUp reset enable.
  *                    - false: LockUp reset disable.
  */
static inline void SYSCON_setLockUpReset (SYSCON_TypeDef *syscon, bool en)
{
    WRITE_REG(syscon->CFGR0.WORDVAL, SYSCON_DEFAULT_KEY | (uint32_t)en);
}

/**
  * \brief  Set SPI1 NCS PIN Select.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  spi1Ncs    SPI1_NCS select
  *                     This parameter can be any value of @ref SYSCON_SPI1NCSSEL.
  */
static inline void SYSCON_setSpi1Ncs (SYSCON_TypeDef *syscon, SYSCON_Spi1NcsSel spi1Ncs)
{
    MODIFY_REG(syscon->SPINCSCR.WORDVAL, SYSCON_SPINCSCR_SPI1NCSSEL_M,
              SYSCON_DEFAULT_KEY | ((uint32_t)spi1Ncs << SYSCON_SPINCSCR_SPI1NCSSEL_S));
}

/**
  * \brief  Set SPI2 NCS PIN Select.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  spi2Ncs    SPI2_NCS select
  *                     This parameter can be any value of @ref SYSCON_SPI2NCSSEL.
  */
static inline void SYSCON_setSpi2Ncs (SYSCON_TypeDef *syscon, SYSCON_Spi2NcsSel spi2Ncs)
{
    MODIFY_REG(syscon->SPINCSCR.WORDVAL, SYSCON_SPINCSCR_SPI2NCSSEL_M,
              SYSCON_DEFAULT_KEY | ((uint32_t)spi2Ncs << SYSCON_SPINCSCR_SPI2NCSSEL_S));
}

/**
  * \brief  Set SPI3 NCS PIN Select.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  spi3Ncs    SPI3_NCS select
  *                     This parameter can be any value of @ref SYSCON_SPI3NCSSEL.
  */
static inline void SYSCON_setSpi3Ncs (SYSCON_TypeDef *syscon, SYSCON_Spi3NcsSel spi3Ncs)
{
    MODIFY_REG(syscon->SPINCSCR.WORDVAL, SYSCON_SPINCSCR_SPI3NCSSEL_M,
              SYSCON_DEFAULT_KEY | ((uint32_t)spi3Ncs << SYSCON_SPINCSCR_SPI3NCSSEL_S));
}

/**
  * \brief  Set SPI4 NCS PIN Select.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  spi4Ncs    SPI4_NCS select
  *                     This parameter can be any value of @ref SYSCON_SPI4NCSSEL.
  */
static inline void SYSCON_setSpi4Ncs (SYSCON_TypeDef *syscon, SYSCON_Spi4NcsSel spi4Ncs)
{
    MODIFY_REG(syscon->SPINCSCR.WORDVAL, SYSCON_SPINCSCR_SPI4NCSSEL_M,
              SYSCON_DEFAULT_KEY | ((uint32_t)spi4Ncs << SYSCON_SPINCSCR_SPI4NCSSEL_S));
}

/**
  * \brief  Set the EXTI pin select.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  sel       Exti sel.
  *                    This parameter can be any value of @ref SYSCON_EXTISEL.
  * \param  pinsel    Exti pin sel.
  *                    This parameter can be any value of @ref SYSCON_EXTIPINSEL.
  */
static inline void SYSCON_setExtiSel (SYSCON_TypeDef *syscon, SYSCON_ExtiSel sel, SYSCON_ExtiPinSel pinSel)
{
    volatile uint32_t *pExtiCr = (volatile uint32_t *)(&(syscon->EXTICR1) + (sel >> 3));
    uint32_t shift = (sel & 0x7UL) << 2;

    MODIFY_REG(*pExtiCr, SYSCON_EXTICR1_EXTI0SEL_M << shift, (uint32_t)pinSel << shift);
}

/**
  * \brief  Set the EPWM clock fail brake.
  * \param  syscon            The base address of the SYSCON module.
  *                            - SYSCON: SYSCON base address index
  * \param  clockFailBrken    CLKFAIL(CLK_TRIM)  EPWM clock fail brake control bit.
  *                            - false: clock fail brake disabled.
  *                            - true:  clock fail brake enabled.
  * \param  hxtlStopBrken     HXTL STOP EPWM clock fail brake control bit.
  *                            - false: clock fail brake disabled.
  *                            - true:  clock fail brake enabled.
  * \param mirc2StopBrken     MIRC2 STOP EPWM clock fail brake control bit.
  *                            - false: clock fail brake disabled.
  *                            - true:  clock fail brake enabled.
  * \param  OscclkStopBrken   OSCCLK STOP EPWM clock fail brake control bit.
  *                            - false: clock fail brake disabled.
  *                            - true:  clock fail brake enabled.
  */
static inline void SYSCON_setEpwmBrkCr (SYSCON_TypeDef *syscon, \
                                        bool clockFailBrken, \
                                        bool hxtlStopBrken, \
                                        bool mirc2StopBrken, \
										bool OscclkStopBrken)
{
    WRITE_REG(syscon->EPWMBRKCR.WORDVAL, SYSCON_DEFAULT_KEY | \
              ((uint32_t)clockFailBrken << SYSCON_EPWMBRKCR_CLKFAILBRKEN_S) | \
              ((uint32_t)hxtlStopBrken << SYSCON_EPWMBRKCR_HXTLSTOPBRKEN_S) | \
              ((uint32_t)mirc2StopBrken << SYSCON_EPWMBRKCR_MIRC2STOPBRKEN_S) | \
              ((uint32_t)OscclkStopBrken << SYSCON_EPWMBRKCR_OSCCLKSTOPBRKEN_S));
}

/**
  * \brief  Set the SYNCOUT Control.
  * \param  syscon        The base address of the SYSCON module.
  *                        - SYSCON: SYSCON base address index
  * \param  syncOutCyc    The SYNCOUT extension PCLK CYCLE count.
  *                        - uint8_t: 0x00 - 0x1F
  * \param  syncOutOe     SYNCOUT output enabled.
  *                        - false: SYNCOUT output disabled.
  *                        - true:  SYNCOUT output enabled.
  * \param  syncOutSel    SYNCOUT selection bit.
  *                        This parameter can be any value of @ref SYSCON_SYNCOUTCRSEL.
  */
static inline void SYSCON_setSyncOutSel (SYSCON_TypeDef *syscon, \
                                         uint8_t syncOutCyc, \
                                         bool syncOutOe, \
                                         SYSCON_SyncoutCrSel syncOutSel)
{
    WRITE_REG(syscon->SYNCOUTCR.WORDVAL, SYSCON_DEFAULT_KEY | \
              (syncOutCyc << SYSCON_SYNCOUTCR_SYNCOUTCYC_S) | \
              ((uint32_t)syncOutOe << SYSCON_SYNCOUTCR_SYNCOUTOE_S) | \
              ((uint32_t)syncOutSel << SYSCON_SYNCOUTCR_SYNCOUTSEL_S));
}

/**
  * \brief  Get the SYNCOUT Control.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the SYNCOUT widening status bit.
  *                    - bool: false/true
  */
static inline bool SYSCON_getSyncOutSt (SYSCON_TypeDef *syscon)
{
    return (READ_BIT(syscon->SYNCOUTCR.WORDVAL, SYSCON_SYNCOUTCR_SYNCOUTSTS_M) != 0UL);
}

/**
  * \brief  Set the SOCAOUT extension PCLK CYCLE count.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  cyc       CYCLE count.
  *                    - uint8_t: 0x00 - 0x1F
  */
static inline void SYSCON_setSocAOutCyc (SYSCON_TypeDef *syscon, uint8_t cyc)
{
    MODIFY_REG(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTCYC_M, ((uint32_t)cyc << SYSCON_SOCAOUTCR_SOCAOUTCYC_S));
}

/**
  * \brief  ADCSOCA output enabled.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - false: ADCSOCA output disabled.
  *                    - true:  ADCSOCA output enabled.
  */
static inline void SYSCON_setSocAOE (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTOE_M, ((uint32_t)en << SYSCON_SOCAOUTCR_SOCAOUTOE_S));
}

/**
  * \brief  Set the EPWMSOCA enable/disable bit about EPWM.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  epwmNum    Epwm number.
  *                     This parameter can be any value of @ref SYSCON_EPWMSOCAEN.
  * \param  en         Enable or disable.
  *                     - false: EPWMxSOCA is disable.
  *                     - true:  EPWMxSOCA is enable.
  */
static inline void SYSCON_setEpwmSocAEn (SYSCON_TypeDef *syscon, SYSCON_EpwmSocAEn epwmNum, bool en)
{
    MODIFY_REG(syscon->SOCAOUTCR.WORDVAL, 0x1UL << (uint32_t)epwmNum, (uint32_t)en << (uint32_t)epwmNum);
}

/**
  * \brief  Get the SOCAOUT widening status bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the SOCAOUT widening status bit.
  *                    - false: not during SOCAOUT widening
  *                    - true:  during SOCAOUT widenin
  */
static inline bool SYSCON_getSocAOutSt (SYSCON_TypeDef *syscon)
{
    return (READ_BIT(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTSTS_M) != 0UL);
}

/**
  * \brief  Set the SOCBOUT extension PCLK CYCLE count.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  cyc       CYCLE coun.
  *                    - uint8_t: 0x00 - 0x1F
  */
static inline void SYSCON_setSocBOutCyc (SYSCON_TypeDef *syscon, uint8_t cyc)
{
    MODIFY_REG(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTCYC_M, ((uint32_t)cyc << SYSCON_SOCBOUTCR_SOCBOUTCYC_S));
}

/**
  * \brief  ADCSOCB output enabled.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - false: ADCSOCB output disabled.
  *                    - true:  ADCSOCB output enabled.
  */
static inline void SYSCON_setSocBOE (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTOE_M, ((uint32_t)en << SYSCON_SOCBOUTCR_SOCBOUTOE_S));
}

/**
  * \brief  Set the EPWMSOCB enable/disable bit about EPWM.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  epwmNum    Epwm number.
  *                     This parameter can be any value of @ref SYSCON_EPWMSOCBEN.
  * \param  en         Enable or disable.
  *                     - false: EPWMxSOCB is disable.
  *                     - true:  EPWMxSOCB is enable.
  */
static inline void SYSCON_setEpwmSocBEn (SYSCON_TypeDef *syscon, SYSCON_EpwmSocBEn epwmNum, bool en)
{
    MODIFY_REG(syscon->SOCBOUTCR.WORDVAL, 0x1UL << (uint32_t)epwmNum, (uint32_t)en << (uint32_t)epwmNum);
}

/**
  * \brief  Get the SOCBOUT widening status bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the SOCBOUT widening status bit.
  *                    - false: not during SOCBOUT widening
  *                    - true:  during SOCBOUT widenin
  */
static inline bool SYSCON_getSocBOutSt (SYSCON_TypeDef *syscon)
{
    return (READ_BIT(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTSTS_M) != 0UL);
}

/**
  * \brief  Enable The Synchronization of the EPWM Base Clock Of The CPU Subsystem.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        TBCLKSYNC enable bit.
  *                    - false: TBCLKSYNC disabled
  *                    - true:  TBCLKSYNC enabled
  * \note   Solely used to synchronize the time-base clocks among all ePWM 
  *         modules belonging to the same CPU subsystem.
  */
static inline void SYSCON_setTbClkSync (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->TBCLKSYNCCR.WORDVAL, SYSCON_TBCLKSYNCCR_TBCLKSYNC_M, SYSCON_DEFAULT_KEY | (uint32_t)en);
}

/**
  * \brief  Enable The Synchronization of the EPWM Base Clock Of The Chip.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        TBCLKSYNC enable bit.
  *                    - false: TBCLKSYNC disabled
  *                    - true:  TBCLKSYNC enabled
  * \note   Can only be set by CPU1.
  */
static inline void SYSCON_setTbClkGlobalSync (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->TBCLKSYNCCR.WORDVAL,
               SYSCON_TBCLKSYNCCR_GTBCLKSYNC_M,
               SYSCON_DEFAULT_KEY | ((uint32_t)en << SYSCON_TBCLKSYNCCR_GTBCLKSYNC_S));
}

/**
  * \brief  Enable TIM1 Brake.
  * \param  syscon            The base address of the SYSCON module.
  *                            - SYSCON: SYSCON base address index
  * \param  oscClkStopBrkEn   Sscclk stop break enable.
  *                            - bool: false/true
  * \param  mirc2StopBrkEn    Mirc2 stop break enable.
  *                            - bool: false/true
  * \param  hxtlStopBrken     Hxtl stop break enable.
  *                            - bool: false/true
  * \param  clkFailBrke       clock fail break enable.
  *                            - bool: false/true
  * \param  brkOutCfg         Break output cfg.
  *                            - bool: false/true
  */
static inline void SYSCON_setTim1Brake (SYSCON_TypeDef *syscon, \
                                        bool oscClkStopBrkEn, \
                                        bool mirc2StopBrkEn, \
                                        bool hxtlStopBrkEn, \
                                        bool clkFailBrkEn, \
                                        bool brkOutCfg)
{
    uint32_t value = ((uint32_t)oscClkStopBrkEn << SYSCON_TIMBREAKCR_TIM1OSCCLKSTOPBRKEN_S) |
                     ((uint32_t)mirc2StopBrkEn << SYSCON_TIMBREAKCR_TIM1MIRC2STOPBRKEN_S) |
                     ((uint32_t)hxtlStopBrkEn << SYSCON_TIMBREAKCR_TIM1HXTLSTOPBRKEN_S) |
                     ((uint32_t)clkFailBrkEn << SYSCON_TIMBREAKCR_TIM1CLKFAILBRKEN_S) |
                     ((uint32_t)brkOutCfg << SYSCON_TIMBREAKCR_TIM1BRKOUTCFG_S);

    MODIFY_REG(syscon->TIMBREAKCR.WORDVAL,
               (SYSCON_TIMBREAKCR_TIM1OSCCLKSTOPBRKEN_M |
                SYSCON_TIMBREAKCR_TIM1MIRC2STOPBRKEN_M |
                SYSCON_TIMBREAKCR_TIM1HXTLSTOPBRKEN_M |
                SYSCON_TIMBREAKCR_TIM1CLKFAILBRKEN_M |
                SYSCON_TIMBREAKCR_TIM1BRKOUTCFG_M),
                SYSCON_DEFAULT_KEY | value);
}

/**
  * \brief  Enable TIM2 Brake.
  * \param  syscon            The base address of the SYSCON module.
  *                            - SYSCON: SYSCON base address index
  * \param  oscClkStopBrkEn   Sscclk stop break enable.
  *                            - bool: false/true
  * \param  mirc2StopBrkEn    Mirc2 stop break enable.
  *                            - bool: false/true
  * \param  hxtlStopBrken     Hxtl stop break enable.
  *                            - bool: false/true
  * \param  clkFailBrke       clock fail break enable.
  *                            - bool: false/true
  * \param  brkOutCfg         Break output cfg.
  *                            - bool: false/true
  */
static inline void SYSCON_setTim2Brake (SYSCON_TypeDef *syscon, \
                                        bool oscClkStopBrkEn, \
                                        bool mirc2StopBrkEn, \
                                        bool hxtlStopBrkEn, \
                                        bool clkFailBrkEn, \
                                        bool brkOutCfg)
{
    uint32_t value = ((uint32_t)oscClkStopBrkEn << SYSCON_TIMBREAKCR_TIM2OSCCLKSTOPBRKEN_S) |
                     ((uint32_t)mirc2StopBrkEn << SYSCON_TIMBREAKCR_TIM2MIRC2STOPBRKEN_S) |
                     ((uint32_t)hxtlStopBrkEn << SYSCON_TIMBREAKCR_TIM2HXTLSTOPBRKEN_S) |
                     ((uint32_t)clkFailBrkEn << SYSCON_TIMBREAKCR_TIM2CLKFAILBRKEN_S) |
                     ((uint32_t)brkOutCfg << SYSCON_TIMBREAKCR_TIM2BRKOUTCFG_S);

    MODIFY_REG(syscon->TIMBREAKCR.WORDVAL,
               (SYSCON_TIMBREAKCR_TIM2OSCCLKSTOPBRKEN_M |
                SYSCON_TIMBREAKCR_TIM2MIRC2STOPBRKEN_M |
                SYSCON_TIMBREAKCR_TIM2HXTLSTOPBRKEN_M |
                SYSCON_TIMBREAKCR_TIM2CLKFAILBRKEN_M |
                SYSCON_TIMBREAKCR_TIM2BRKOUTCFG_M),
                SYSCON_DEFAULT_KEY | value);
}

/**
  * \brief  Set the CAN1 Software Reset.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  reset     CAN1 software reset bit.
  *                    - false: CAN1 common mode.
  *                    - true:  CAN1 software reset bit.
  */
static inline void SYSCON_resetCan1 (SYSCON_TypeDef *syscon, bool reset)
{
    MODIFY_REG(syscon->CANSWRCR.WORDVAL,
               SYSCON_CANSWRCR_CAN1SWR_M,
               SYSCON_DEFAULT_KEY | ((uint32_t)reset << SYSCON_CANSWRCR_CAN1SWR_S));
}

/**
  * \brief  Set the CANFD1 Software Reset.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  reset     CANFD software reset bit.
  *                    - false: CANFD1 common mode.
  *                    - true:  CANFD1 software reset bit.
  */
static inline void SYSCON_resetCanfd1 (SYSCON_TypeDef *syscon, bool reset)
{
    MODIFY_REG(syscon->CANSWRCR.WORDVAL,
               SYSCON_CANSWRCR_CANFD1SWR_M,
               SYSCON_DEFAULT_KEY | ((uint32_t)reset << SYSCON_CANSWRCR_CANFD1SWR_S));
}

/**
  * \brief  Set the CANFD2 Software Reset.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  reset     CANFD software reset bit.
  *                    - false: CANFD2 common mode.
  *                    - true:  CANFD2 software reset bit.
  */
static inline void SYSCON_resetCanfd2 (SYSCON_TypeDef *syscon, bool reset)
{
    MODIFY_REG(syscon->CANSWRCR.WORDVAL, 
               SYSCON_CANSWRCR_CANFD2SWR_M,
               SYSCON_DEFAULT_KEY | ((uint32_t)reset << SYSCON_CANSWRCR_CANFD2SWR_S));
}

/**
  * \brief  Enable the NMI Global interrupt for the CPU subsystem.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_enableNmiGlobalInterrupt (SYSCON_TypeDef *syscon, bool en)
{
    WRITE_REG(syscon->NMICFG.WORDVAL, SYSCON_DEFAULT_KEY | (uint32_t)en);
}

/**
  * \brief  Read the NMI status flag register.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns Value of NMIFLG register.
  *                    - uint32_t: 0x0 - 0xFFFFFFFF
  */
static inline uint32_t SYSCON_getNmiStatus (SYSCON_TypeDef *syscon)
{
    return (READ_REG(syscon->NMIFLG.WORDVAL));
}

/**
  * \brief  Read the Specified NMI interrupt status flag.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiflags    The bit format of this parameter is same as of the NMIFLG register.
  *                      - SYSCON_NMIFLG_NMIINT
  *                      - SYSCON_NMIFLG_HXTLSTOP
  *                      - SYSCON_NMIFLG_FLASH_ECCERR
  *                      - SYSCON_NMIFLG_SRAM1_ECCERR
  *                      - SYSCON_NMIFLG_SRAM2_ECCERR
  *                      - SYSCON_NMIFLG_DTCM_ECCERR
  *                      - SYSCON_NMIFLG_ITCM_ECCERR
  *                      - SYSCON_NMIFLG_BKSRAM_PARERR
  *                      - SYSCON_NMIFLG_MCD_NMI
  *                      - SYSCON_NMIFLG_SMPU_ERR
  *                      - SYSCON_NMIFLG_LVD_NMI
  *                      - SYSCON_NMIFLG_OSCCLKSTOP
  *                      - SYSCON_NMIFLG_CAN1NCE
  *                      - SYSCON_NMIFLG_CANFD1NCE
  *                      - SYSCON_NMIFLG_CANFD2NCE
  *                      - SYSCON_NMIFLG_SW_ERR
  *                      - SYSCON_NMIFLG_CLB1_NMI
  *                      - SYSCON_NMIFLG_CLB2_NMI
  *                      - SYSCON_NMIFLG_CLB3_NMI
  *                      - SYSCON_NMIFLG_CLB4_NMI
  *                      - SYSCON_NMIFLG_CLB5_NMI
  *                      - SYSCON_NMIFLG_CLB6_NMI
  *                      - SYSCON_NMIFLG_CPU2_NMIWDTRST
  *                      - SYSCON_NMIFLG_CPU2_WWDGRST
  *                      - SYSCON_NMIFLG_CPU2_IWDG1RST
  *                      - SYSCON_NMIFLG_CPU2_LOCKUPRST
  *                      - SYSCON_NMIFLG_CPU2_SOFTRST
  * \return Returns the Value of true or false.
  *                      - bool: true/false
  */
static inline bool SYSCON_isNmiFlagSet (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    return ((READ_REG(syscon->NMIFLG.WORDVAL) & nmiFlags) != 0UL);
}

/**
  * \brief  Clear the Specified NMI interrupt status flag.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiflags    nmiFlags Bit mask of the NMI interrupts that user wants to clear.
  *                      - SYSCON_NMIFLGCLR_NMIINT
  *                      - SYSCON_NMIFLGCLR_HXTLSTOP
  *                      - SYSCON_NMIFLGCLR_FLASH_ECCERR
  *                      - SYSCON_NMIFLGCLR_SRAM1_ECCERR
  *                      - SYSCON_NMIFLGCLR_SRAM2_ECCERR
  *                      - SYSCON_NMIFLGCLR_DTCM_ECCERR
  *                      - SYSCON_NMIFLGCLR_ITCM_ECCERR
  *                      - SYSCON_NMIFLGCLR_BKSRAM_PARERR
  *                      - SYSCON_NMIFLGCLR_MCD_NMI
  *                      - SYSCON_NMIFLGCLR_SMPU_ERR
  *                      - SYSCON_NMIFLGCLR_LVD_NMI
  *                      - SYSCON_NMIFLGCLR_OSCCLKSTOP
  *                      - SYSCON_NMIFLGCLR_CAN1NCE
  *                      - SYSCON_NMIFLGCLR_CANFD1NCE
  *                      - SYSCON_NMIFLGCLR_CANFD2NCE
  *                      - SYSCON_NMIFLGCLR_SW_ERR
  *                      - SYSCON_NMIFLGCLR_CLB1_NMI
  *                      - SYSCON_NMIFLGCLR_CLB2_NMI
  *                      - SYSCON_NMIFLGCLR_CLB3_NMI
  *                      - SYSCON_NMIFLGCLR_CLB4_NMI
  *                      - SYSCON_NMIFLGCLR_CLB5_NMI
  *                      - SYSCON_NMIFLGCLR_CLB6_NMI
  *                      - SYSCON_NMIFLGCLR_CPU2_NMIWDTRST
  *                      - SYSCON_NMIFLGCLR_CPU2_WWDGRST
  *                      - SYSCON_NMIFLGCLR_CPU2_IWDGRST
  *                      - SYSCON_NMIFLGCLR_CPU2_LOCKUPRST
  *                      - SYSCON_NMIFLGCLR_CPU2_SOFTRST
  */
static inline void SYSCON_clearNmiStatus (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    WRITE_REG(syscon->NMIFLGCLR.WORDVAL, nmiFlags);
}

/**
  * \brief  Clear all the NMI Flags that are currently set.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  */
static inline void SYSCON_clearAllNmiFlags (SYSCON_TypeDef *syscon)
{
    uint32_t nmiFlags = SYSCON_getNmiStatus(syscon);
    WRITE_REG(syscon->NMIFLGCLR.WORDVAL, nmiFlags);
}

/**
  * \brief  Function to force individual NMI interrupt fail flags.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiFlags    nmiFlags Bit mask of the NMI interrupts that user wants to force.
  *                      - SYSCON_NMIFLGFRC_HXTLSTOP
  *                      - SYSCON_NMIFLGFRC_FLASH_ECCERR
  *                      - SYSCON_NMIFLGFRC_SRAM1_ECCERR
  *                      - SYSCON_NMIFLGFRC_SRAM2_ECCERR
  *                      - SYSCON_NMIFLGFRC_DTCM_ECCERR
  *                      - SYSCON_NMIFLGFRC_ITCM_ECCERR
  *                      - SYSCON_NMIFLGFRC_BKSRAM_PARERR
  *                      - SYSCON_NMIFLGFRC_MCD_NMI
  *                      - SYSCON_NMIFLGFRC_SMPU_ERR
  *                      - SYSCON_NMIFLGFRC_LVD_NMI
  *                      - SYSCON_NMIFLGFRC_OSCCLKSTOP
  *                      - SYSCON_NMIFLGFRC_CAN1NCE
  *                      - SYSCON_NMIFLGFRC_CANFD1NCE
  *                      - SYSCON_NMIFLGFRC_CANFD2NCE
  *                      - SYSCON_NMIFLGFRC_SW_ERR
  *                      - SYSCON_NMIFLGFRC_CLB1_NMI
  *                      - SYSCON_NMIFLGFRC_CLB2_NMI
  *                      - SYSCON_NMIFLGFRC_CLB3_NMI
  *                      - SYSCON_NMIFLGFRC_CLB4_NMI
  *                      - SYSCON_NMIFLGFRC_CLB5_NMI
  *                      - SYSCON_NMIFLGFRC_CLB6_NMI
  *                      - SYSCON_NMIFLGFRC_CPU2_NMIWDTRST
  *                      - SYSCON_NMIFLGFRC_CPU2_WWDGRST
  *                      - SYSCON_NMIFLGFRC_CPU2_IWDGRST
  *                      - SYSCON_NMIFLGFRC_CPU2_LOCKUPRST
  *                      - SYSCON_NMIFLGFRC_CPU2_SOFTRST
  */
static inline void SYSCON_forceNmiFlags (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    WRITE_REG(syscon->NMIFLGFRC.WORDVAL, nmiFlags);
}

/**
  * \brief  Gets the NMI watchdog counter value.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the NMI watchdog counter register's current value.
  *                    - uint16_t: 0x00-0xFFFF
  */
static inline uint16_t SYSCON_getNmiWatchdogCounter (SYSCON_TypeDef *syscon)
{
    return((uint16_t)syscon->NMIWDGCNT.WORDVAL);
}

/**
  * \brief  Sets the NMI watchdog period value.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  wdPeriod    wdPeriod is the 16-bit value at which a reset is generated.
  *                      - uint16_t: 0x00 - 0xFFFF
  */
static inline void SYSCON_setNmiWatchdogPeriod (SYSCON_TypeDef *syscon, uint16_t wdPeriod)
{
    WRITE_REG(syscon->NMIWDGPRD.WORDVAL, SYSCON_DEFAULT_KEY | wdPeriod);
}

/**
  * \brief  Gets the NMI watchdog period value.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the NMI watchdog period register's current value.
  *                    - uint16_t: 0x00 - 0xFFFF
  */
static inline uint16_t SYSCON_getNmiWatchdogPeriod (SYSCON_TypeDef *syscon)
{
    return((uint16_t)syscon->NMIWDGPRD.WORDVAL);
}

/**
  * \brief  Read the current state of individual NMI interrupts.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the value of NMISHDFLG register.
  *                    - uint32_t: 0x0 - 0xFFFFFFFF
  */
static inline uint32_t SYSCON_getNmiShadowFlagStatus (SYSCON_TypeDef *syscon)
{
    return(syscon->NMISHDFLG.WORDVAL);
}

/**
  * \brief  Check if the individual NMI shadow flags are set.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiFlags    nmiFlags Bit mask of the NMI shadow flag.
  *                      - SYSCON_NMISHDFLG_HXTLSTOP
  *                      - SYSCON_NMISHDFLG_FLASH_ECCERR
  *                      - SYSCON_NMISHDFLG_SRAM1_ECCERR
  *                      - SYSCON_NMISHDFLG_SRAM2_ECCERR
  *                      - SYSCON_NMISHDFLG_DTCM_ECCERR
  *                      - SYSCON_NMISHDFLG_ITCM_ECCERR
  *                      - SYSCON_NMISHDFLG_BKSRAM_PARERR
  *                      - SYSCON_NMISHDFLG_MCD_NMI
  *                      - SYSCON_NMISHDFLG_SMPU_ERR
  *                      - SYSCON_NMISHDFLG_LVD_NMI
  *                      - SYSCON_NMISHDFLG_CAN1NCE
  *                      - SYSCON_NMISHDFLG_CANFD1NCE
  *                      - SYSCON_NMISHDFLG_CANFD2NCE
  *                      - SYSCON_NMISHDFLG_SW_ERR
  *                      - SYSCON_NMISHDFLG_CLB1_NMI
  *                      - SYSCON_NMISHDFLG_CLB2_NMI
  *                      - SYSCON_NMISHDFLG_CLB3_NMI
  *                      - SYSCON_NMISHDFLG_CLB4_NMI
  *                      - SYSCON_NMISHDFLG_CLB5_NMI
  *                      - SYSCON_NMISHDFLG_CLB6_NMI
  *                      - SYSCON_NMISHDFLG_CPU2_NMIWDTRST
  *                      - SYSCON_NMISHDFLG_CPU2_WWDGRST
  *                      - SYSCON_NMISHDFLG_CPU2_IWDGRST
  *                      - SYSCON_NMISHDFLG_CPU2_LOCKUPRST
  *                      - SYSCON_NMISHDFLG_CPU2_SOFTRST
  * \return Returns the current state of NMI shadow flags.
  *                      - true:  any of the NMI asked for in the parameter bit mask is set.
  *                      - false: none of the NMI requested in the parameter bit mask are.
  */
static inline bool SYSCON_isNmiShadowFlagSet (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    return((syscon->NMISHDFLG.WORDVAL & nmiFlags) != 0UL);
}

/**
  * \brief  Set the Peripheral DOZE Request.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  id        Peripheral module id.
  *                    This parameter can be any value of @ref SYSCON_DOZEMODULEID.
  * \param  req       DOZE request.
  *                    - false: Common mode
  *                    - true:  DOZE request
  */
static inline void SYSCON_setPDozeReq (SYSCON_TypeDef *syscon, SYSCON_DozeModuleId id, bool req)
{
    MODIFY_REG(syscon->PDOZEREQR.WORDVAL, (1UL << (uint32_t)id),
               SYSCON_DEFAULT_KEY | ((uint32_t)req << (uint32_t)id));
}

/**
  * \brief  Set the Peripheral STOP Request.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  id        Peripheral module id.
  *                    This parameter can be any value of @ref SYSCON_STOPMODULEID.
  * \param  req       STOP request.
  *                    - false: Common mode
  *                    - true:  STOP request
  */
static inline void SYSCON_setPStopReq (SYSCON_TypeDef *syscon, SYSCON_StopModuleId id, bool req)
{
    MODIFY_REG(syscon->PSTOPREQR.WORDVAL, (1UL << (uint32_t)id),
               SYSCON_DEFAULT_KEY | ((uint32_t)req << (uint32_t)id));
}

/**
  * \brief  Get the Peripheral STOP Acknowledge.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  id        Peripheral module id.
  *                    This parameter can be any value of @ref SYSCON_STOPMODULEID.
  * \return Returns the stop acknowledgeBit.
  *                    - true:  stop acknowledge.
  *                    - false: common mode.
  */
static inline bool SYSCON_getPStopAck (SYSCON_TypeDef *syscon, SYSCON_StopModuleId id)
{
    return ((READ_REG(syscon->PSTOPACKR.WORDVAL) & (uint32_t)(1UL << id)) != 0UL);
}

/**
  * \brief  Set the EPWM1 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm1Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM1EALLOW_M, 
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM1EALLOW_S);
}

/**
  * \brief  Set the EPWM2 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm2Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM2EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM2EALLOW_S);
}

/**
  * \brief  Set the EPWM3 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm3Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM3EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM3EALLOW_S);
}

/**
  * \brief  Set the EPWM4 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm4Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM4EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM4EALLOW_S);
}

/**
  * \brief  Set the EPWM5 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm5Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM5EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM5EALLOW_S);
}

/**
  * \brief  Set the EPWM6 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm6Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM6EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM6EALLOW_S);
}

/**
  * \brief  Set the EPWM7 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm7Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM7EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM7EALLOW_S);
}

/**
  * \brief  Set the EPWM8 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm8Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM8EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM8EALLOW_S);
}

/**
  * \brief  Set the EPWM9 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm9Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM9EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM9EALLOW_S);
}

/**
  * \brief  Set the EPWM10 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm10Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM10EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM10EALLOW_S);
}

/**
  * \brief  Set the EPWM11 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm11Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM11EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM11EALLOW_S);
}

/**
  * \brief  Set the EPWM12 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm12Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM12EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM12EALLOW_S);
}

/**
  * \brief  Set the EPWM13 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm13Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM13EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM13EALLOW_S);
}

/**
  * \brief  Set the EPWM14 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm14Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM14EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM14EALLOW_S);
}

/**
  * \brief  Set the EPWM15 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm15Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM15EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM15EALLOW_S);
}

/**
  * \brief  Set the EPWM16 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm16Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM16EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM16EALLOW_S);
}

/**
  * \brief  Set the EPWM17 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm17Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM17EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM17EALLOW_S);
}

/**
  * \brief  Set the EPWM18 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEpwm18Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM18EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_EPWM18EALLOW_S);
}

/**
  * \brief  Set the ECAP1 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap1Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP1EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP1EALLOW_S);
}

/**
  * \brief  Set the ECAP2 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap2Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP2EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP2EALLOW_S);
}

/**
  * \brief  Set the ECAP3 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap3Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP3EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP3EALLOW_S);
}

/**
  * \brief  Set the ECAP4 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap4Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP4EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP4EALLOW_S);
}

/**
  * \brief  Set the ECAP5 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap5Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP5EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP5EALLOW_S);
}

/**
  * \brief  Set the ECAP6 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap6Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP6EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP6EALLOW_S);
}

/**
  * \brief  Set the ECAP7 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setEcap7Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP7EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW1_ECAP7EALLOW_S);
}

/**
  * \brief  Set the ADCA eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setAdcaEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ADCAEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_ADCAEALLOW_S);
}

/**
  * \brief  Set the ADCB eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setAdcbEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ADCBEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_ADCBEALLOW_S);
}

/**
  * \brief  Set the ADCC eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setAdccEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ADCCEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_ADCCEALLOW_S);
}

/**
  * \brief  Set the ADCD eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setAdcdEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ADCDEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_ADCDEALLOW_S);
}

/**
  * \brief  Set the DAC1 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setDac1Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_DAC1EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_DAC1EALLOW_S);
}

/**
  * \brief  Set the DAC3 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setDac3Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_DAC3EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_DAC3EALLOW_S);
}

/**
  * \brief  Set the SDFM1 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setSdfm1Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_SDFM1EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_SDFM1EALLOW_S);
}

/**
  * \brief  Set the SDFM2 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setSdfm2Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_SDFM2EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_SDFM2EALLOW_S);
}

/**
  * \brief  Set the SDFM3 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setSdfm3Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_SDFM3EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_SDFM3EALLOW_S);
}

/**
  * \brief  Set the SDFM4 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setSdfm4Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_SDFM4EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_SDFM4EALLOW_S);
}

/**
  * \brief  Set the ANASS eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setAnassEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ANASSEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_ANASSEALLOW_S);
}

/**
  * \brief  Set the XBAR eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setXbarEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_XBAREALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_XBAREALLOW_S);
}

/**
  * \brief  Set the CMPSS1 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss1Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS1EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS1EALLOW_S);
}

/**
  * \brief  Set the CMPSS2 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss2Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS2EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS2EALLOW_S);
}

/**
  * \brief  Set the CMPSS3 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss3Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS3EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS3EALLOW_S);
}

/**
  * \brief  Set the CMPSS4 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss4Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS4EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS4EALLOW_S);
}

/**
  * \brief  Set the CMPSS5 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss5Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS5EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS5EALLOW_S);
}

/**
  * \brief  Set the CMPSS6 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss6Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS6EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS6EALLOW_S);
}

/**
  * \brief  Set the CMPSS7 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss7Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS7EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS7EALLOW_S);
}

/**
  * \brief  Set the CMPSS8 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss8Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS8EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS8EALLOW_S);
}

/**
  * \brief  Set the CMPSS9 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss9Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS9EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS9EALLOW_S);
}

/**
  * \brief  Set the CMPSS10 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpssEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS10EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS10EALLOW_S);
}

/**
  * \brief  Set the CMPSS11 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setCmpss11Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS11EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_CMPSS11EALLOW_S);
}

/**
  * \brief  Set the UPP eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setUppEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_UPPEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_UPPEALLOW_S);
}

/**
  * \brief  Set the FMU eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setFmuEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_FMUEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW2_FMUEALLOW_S);
}

/**
  * \brief  Set the GPIOA eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioAEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOAEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOAEALLOW_S);
}

/**
  * \brief  Set the GPIOB eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioBEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOBEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOBEALLOW_S);
}

/**
  * \brief  Set the GPIOC eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioCEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOCEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOCEALLOW_S);
}

/**
  * \brief  Set the GPIOD eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioDEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIODEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIODEALLOW_S);
}

/**
  * \brief  Set the GPIOE eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioEEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOEEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOEEALLOW_S);
}

/**
  * \brief  Set the GPIOF eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioFEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOFEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOFEALLOW_S);
}

/**
  * \brief  Set the GPIOG eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioGEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOGEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOGEALLOW_S);
}

/**
  * \brief  Set the GPIOH eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setGpioHEallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOHEALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_GPIOHEALLOW_S);
}

/**
  * \brief  Set the CLB1 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setClb1Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_CLB1EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_CLB1EALLOW_S);
}

/**
  * \brief  Set the CLB2 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setClb2Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_CLB2EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_CLB2EALLOW_S);
}

/**
  * \brief  Set the CLB3 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setClb3Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_CLB3EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_CLB3EALLOW_S);
}

/**
  * \brief  Set the CLB4 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setClb4Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_CLB4EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_CLB4EALLOW_S);
}

/**
  * \brief  Set the CLB5 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setClb5Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_CLB5EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_CLB5EALLOW_S);
}

/**
  * \brief  Set the CLB6 eallow bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - bool: false/true
  */
static inline void SYSCON_setClb6Eallow (SYSCON_TypeDef *syscon, bool en)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_CLB6EALLOW_M,
               (uint32_t)en << SYSCON_SYSEALLOW3_CLB6EALLOW_S);
}

/**
  * \brief  Reset Core2.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  */
static inline void SYSCON_resetCore2 (SYSCON_TypeDef *syscon)
{
    WRITE_REG(syscon->CPU2RESCTL.WORDVAL, (0xA5A5UL << SYSCON_CPU2RESCTL_KEY_S) | SYSCON_CPU2RESCTL_CPU2RESCTL_RST_M);
}

/**
  * \brief  Release Core2.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  */
static inline void SYSCON_releaseCore2 (SYSCON_TypeDef *syscon)
{
    WRITE_REG(syscon->CPU2RESCTL.WORDVAL, (0xA5A5UL << SYSCON_CPU2RESCTL_KEY_S));
}


#ifdef __cplusplus
}
#endif


#endif /* __SYSCON_H__ */
