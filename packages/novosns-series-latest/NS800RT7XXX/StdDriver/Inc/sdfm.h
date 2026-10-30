/**
  * @file       sdfm.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx sdfm module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SDFM_H__
#define __SDFM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_sdfm.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SDFM_EXPORTED_TYPES SDFM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'SDFM' module.
  */
  
/** @defgroup SDFM_FLITERTHRESHOLD_TYPES SDFM THRESHOLD AND FLITER PARAMETERS
  * @{
  * @brief  Macro definitions are used with all files threshold and fliter parameters.
  */
#define SDFM_GET_LOW_THRESHOLD(C)     ((uint16_t)(C))                        /*!< Macro to get the low threshold */
#define SDFM_GET_HIGH_THRESHOLD(C)    ((uint16_t)((uint32_t)(C) >> 16UL))    /*!<  Macro to get the high threshold */
#define SDFM_GET_LOW_THRESHOLD_BOTH(C1, C2) \
         ((((uint32_t)(SDFM_GET_LOW_THRESHOLD(C2))) << 16UL) |\
         ((uint32_t)(SDFM_GET_LOW_THRESHOLD(C1))))                           /*!< Macro to get the high threshold 1 & 2 to be passed as lowThreshold 
                                                                                  parameter to SDFM_setCompFilterLowThreshold() */
#define SDFM_GET_HIGH_THRESHOLD_BOTH(C1, C2) \
         ((((uint32_t)(SDFM_GET_HIGH_THRESHOLD(C2))) << 16UL) |\
         ((uint32_t)(SDFM_GET_HIGH_THRESHOLD(C1))))                          /*!< Macro to get the high threshold 1 & 2 to be passed as highThreshold
                                                                                  parameter to SDFM_setCompFilterHighThreshold() */
#define SDFM_COMPEVT_FILTER_CONFIG_M  (SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_M |\
         SDFM_SDCOMP1EVT1FLTCTL_THRESH_M)                                    /*!< Define to mask out the bits in the SDCOMPHFILCTL register that aren't
                                                                                  associated with comparator event filter configurations. Added for internal */
#define SDFM_COMPEVT_FILTER_LOCK_M    (SDFM_SDCOMPLOCK_SDCOMPCTL |\
         SDFM_SDCOMPLOCK_COMP)                                               /*!< Define to mask out the bits in the SDCOMPLOCK register that aren'tassociated 
                                                                                  with lock configuration. Added for internal use, not to be used */
#define SDFM_THRESHOLD(H, L)          ((((uint32_t)(H)) << 16UL) | (L))      /*!< Macro to combine high threshold and low threshold values */ 

/**
  * @}
  */

/** @defgroup SDFM_SETBIT_TYPES Set SDFM Function Bit
  * @{
  * @brief  Macro definitions are used with all files set bit handle.
  */
#define SDFM_SET_OSR(X)        (((X) - 1UL) << 8UL)    /*!< Macro to convert comparator over sampling ratio to acceptable bit location */
#define SDFM_SHIFT_VALUE(X)    ((X) << 2UL)            /*!< Macro to convert the data shift bit values to acceptable bit location */

/**
  * @}
  */

/** @defgroup SDFM_SET_FIFO Set SDFM Fifo Level
  * @{
  * @brief  Macro definitions are used with all files set fifo level.
  */
#define SDFM_SET_FIFO_LEVEL(X)    ((X) << 7UL)    /*!< Macro to set the FIFO level to acceptable bit location */

/**
  * @}
  */

/** @defgroup SDFM_FLITER_ENABLE Fliter Enable
  * @{
  * @brief  Macro definitions are used with all files set fliter enable.
  */
#define SDFM_FILTER_DISABLE    (0x0UL)
#define SDFM_FILTER_ENABLE     (0x2UL)    /*!<  Macros to enable or disable filter */

/**
  * @}
  */

/** @defgroup SDFM_SET_OFFSET Set SDFM Offset
  * @{
  * @brief  Macro definitions are used with all files about sdfm offset.
  */
#define SDFM_SDFIL_OFFSET          (SDFM_O_SDCTLPARM2 - SDFM_O_SDCTLPARM1)      /*!< SD filter offset */
#define SDFM_DIGFIL_OFFSET         (SDFM_O_SDCOMP2CTL - SDFM_O_SDCOMP1CTL)      /*!< Event Digital filter offset */
#define SDFM_SDFLT1CMPHx_OFFSET    (SDFM_O_SDFLT1CMPH2 - SDFM_O_SDFLT1CMPH1)    /*!< Offset between high threshold 1 & 2 registers */
#define SDFM_SDFLT1CMPLx_OFFSET    (SDFM_O_SDFLT1CMPL2 - SDFM_O_SDFLT1CMPL1)    /*!< Offset between low threshold 1 & 2 registers */

/**
  * @}
  */

/** @defgroup SDFM_SYNCHRONIZER_TYPES SDFM Synchronizer Types
  * @{
  * @brief  Macro definitions are used with all files about sdfm synchronizer types.
  */
#define SDFM_CLOCK_SYNCHRONIZER    (SDFM_SDCTLPARM1_SDCLKSYNC)     /*!< Define for Clock synchronizer Configuration */
#define SDFM_DATA_SYNCHRONIZER     (SDFM_SDCTLPARM1_SDDATASYNC)    /*!< Define for Data Synchronizer Configuration */ 

/**
  * @}
  */

/** @defgroup SDFM_INTERRUPT_TYPES SDFM Interrupt Types
  * @{
  * @brief  Macro definitions are used with all files about SDFM Interrupt Types.
  */
#define SDFM_MODULATOR_FAILURE_INTERRUPT          (0x200UL)         /*!< Interrupt is generated if Modulator fails */
#define SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT        (0x40UL)          /*!< Interrupt on Comparator low-level threshold */
#define SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT       (0x20UL)          /*!< Interrupt on Comparator high-level threshold */
#define SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT    (0x1UL)           /*!< Interrupt on Acknowledge flag */
#define SDFM_FIFO_INTERRUPT                       (0x1000UL)        /*!< Interrupt on FIFO level */
#define SDFM_FIFO_OVERFLOW_INTERRUPT              (0x8000UL)        /*!< Interrupt on FIFO overflow */
#define SDFM_MAIN_INTERRUPT_FLAG                  (0x80000000UL)    /*!< Main interrupt flag */

/**
  * @}
  */

/** @defgroup SDFM_FLITER_TYPES SDFM Fliter Parameters 
  * @{
  * @brief  Macro definitions are used with all files about sdfm fliter parameters.
  */
#define SDFM_FILTER_1_HIGH_THRESHOLD_FLAG    (0x1UL)         /*!< Filter 1 high -level threshold flag */
#define SDFM_FILTER_1_LOW_THRESHOLD_FLAG     (0x2UL)         /*!< Filter 1 low -level threshold flag */
#define SDFM_FILTER_2_HIGH_THRESHOLD_FLAG    (0x4UL)         /*!< Filter 2 high -level threshold flag */
#define SDFM_FILTER_2_LOW_THRESHOLD_FLAG     (0x8UL)         /*!< Filter 2 low -level threshold flag */
#define SDFM_FILTER_3_HIGH_THRESHOLD_FLAG    (0x10UL)        /*!< Filter 3 high -level threshold flag */
#define SDFM_FILTER_3_LOW_THRESHOLD_FLAG     (0x20UL)        /*!< Filter 3 low -level threshold flag */
#define SDFM_FILTER_4_HIGH_THRESHOLD_FLAG    (0x40UL)        /*!< Filter 4 high -level threshold flag */
#define SDFM_FILTER_4_LOW_THRESHOLD_FLAG     (0x80UL)        /*!< Filter 4 low -level threshold flag */
#define SDFM_FILTER_1_MOD_FAILED_FLAG        (0x100UL)       /*!< Filter 1 modulator failed flag */
#define SDFM_FILTER_2_MOD_FAILED_FLAG        (0x200UL)       /*!< Filter 2 modulator failed flag */
#define SDFM_FILTER_3_MOD_FAILED_FLAG        (0x400UL)       /*!< Filter 3 modulator failed flag */
#define SDFM_FILTER_4_MOD_FAILED_FLAG        (0x800UL)       /*!< Filter 4 modulator failed flag */
#define SDFM_FILTER_1_NEW_DATA_FLAG          (0x1000UL)      /*!< Filter 1 new data flag */
#define SDFM_FILTER_2_NEW_DATA_FLAG          (0x2000UL)      /*!< Filter 2 new data flag */
#define SDFM_FILTER_3_NEW_DATA_FLAG          (0x4000UL)      /*!< Filter 3 new data flag */
#define SDFM_FILTER_4_NEW_DATA_FLAG          (0x8000UL)      /*!< Filter 4 new data flag */
#define SDFM_FILTER_1_FIFO_OVERFLOW_FLAG     (0x10000UL)     /*!< Filter 1 FIFO overflow flag */
#define SDFM_FILTER_2_FIFO_OVERFLOW_FLAG     (0x20000UL)     /*!< Filter 2 FIFO overflow flag */
#define SDFM_FILTER_3_FIFO_OVERFLOW_FLAG     (0x40000UL)     /*!< Filter 3 FIFO overflow flag */
#define SDFM_FILTER_4_FIFO_OVERFLOW_FLAG     (0x80000UL)     /*!< Filter 4 FIFO overflow flag */
#define SDFM_FILTER_1_FIFO_INTERRUPT_FLAG    (0x100000UL)    /*!< Filter 1 FIFO overflow flag */
#define SDFM_FILTER_2_FIFO_INTERRUPT_FLAG    (0x200000UL)    /*!< Filter 2 FIFO overflow flag */
#define SDFM_FILTER_3_FIFO_INTERRUPT_FLAG    (0x400000UL)    /*!< Filter 3 FIFO overflow flag */
#define SDFM_FILTER_4_FIFO_INTERRUPT_FLAG    (0x800000UL)    /*!< Filter 4 FIFO overflow flag */

/**
  * @}
  */

/** @defgroup SDFM_OUTPUTTHRESHOLDSTATUS config status of output threshold
  * @{
  * @brief  Values that can be returned from SDFM_getThresholdStatus()
  */
typedef enum {
    SDFM_OUTPUT_WITHIN_THRESHOLD = 0x0U,    /*!< SDFM output is within threshold */
    SDFM_OUTPUT_ABOVE_THRESHOLD,            /*!< SDFM output is above threshold */
    SDFM_OUTPUT_BELOW_THRESHOLD             /*!< SDFM output is below threshold */
} SDFM_OutputThresholdStatus;

/**
  * @}
  */

/** @defgroup SDFM_FILTERNUMBER config the number of filter
  * @{
  * @brief  Values that can be passed to all functions as the filterNumber
  */
typedef enum {
    SDFM_FILTER_1 = 0x0U,    /*!< Digital filter 1 */
    SDFM_FILTER_2,           /*!< Digital filter 2 */
    SDFM_FILTER_3,           /*!< Digital filter 3 */
    SDFM_FILTER_4            /*!< Digital filter 4 */
} SDFM_FilterNumber;

/**
  * @}
  */

/** @defgroup SDFM_FILTER config the type of filter
  * @{
  * @brief  Values that can be passed to SDFM_setFilterType()
  */
 typedef enum {
    SDFM_FILTER_SINC_FAST = 0x0U,    /*!< Digital filter with SincFast structure */
    SDFM_FILTER_SINC_1,              /*!< Digital filter with Sinc1 structure */
    SDFM_FILTER_SINC_2,              /*!< Digital filter with Sinc3 structure */
    SDFM_FILTER_SINC_3               /*!< Digital filter with Sinc4 structure */
} SDFM_Filter;

/**
  * @}
  */

/** @defgroup SDFM_OUTPUTDATAFORMAT config output data format
  * @{
  * @brief  Values that can be passed to SDFM_setOutputDataFormat(),as the dataFormat parameter
  */
typedef enum {
    SDFM_DATA_FORMAT_16_BIT = 0x0U,    /*!< Filter output is in 16 bits 2's complement format */
    SDFM_DATA_FORMAT_32_BIT            /*!< Filter output is in 32 bits 2's complement format */
} SDFM_OutputDataFormat;

/**
  * @}
  */

/** @defgroup SDFM_DATAREADYINTERRUPTSOURCE config data ready intterrupt source
  * @{
  * @brief  Values that can be passed to SDFM_setDataReadyInterruptSource(),as the dataReadySource parameter
  */
typedef enum {
    SDFM_DATA_READY_SOURCE_DIRECT = 0x0U,    /*!< Data ready interrupt source is direct (non -FIFO) */
    SDFM_DATA_READY_SOURCE_FIFO              /*!< Data ready interrupt source is FIFO */
} SDFM_DataReadyInterruptSource;

/**
  * @}
  */

/** @defgroup SDFM_PWMSYNCSOURCE config sdfm pwm sync source 
  * @{
  * @brief  Values that can be passed to SDFM_setPWMSyncSource(),as the syncSource parameter
  */
typedef enum {
    SDFM_SYNC_PWM1_SOCA  = 0x00U,   /*!< SDFM sync source is PWM1 SOCA */
    SDFM_SYNC_PWM1_SOCB  = 0x01U,   /*!< SDFM sync source is PWM1 SOCB */
    SDFM_SYNC_PWM17_SOCA = 0x02U,   /*!< SDFM sync source is PWM17 SOCA */
    SDFM_SYNC_PWM17_SOCB = 0x03U,   /*!< SDFM sync source is PWM17 SOCB */
    SDFM_SYNC_PWM2_SOCA  = 0x04U,   /*!< SDFM sync source is PWM2 SOCA */
    SDFM_SYNC_PWM2_SOCB  = 0x05U,   /*!< SDFM sync source is PWM2 SOCB */
    SDFM_SYNC_PWM18_SOCA = 0x06U,   /*!< SDFM sync source is PWM18 SOCA */
    SDFM_SYNC_PWM18_SOCB = 0x07U,   /*!< SDFM sync source is PWM18 SOCB */
    SDFM_SYNC_PWM3_SOCA  = 0x08U,   /*!< SDFM sync source is PWM3 SOCA */
    SDFM_SYNC_PWM3_SOCB  = 0x09U,   /*!< SDFM sync source is PWM3 SOCB */
    SDFM_SYNC_PWM4_SOCA  = 0x0CU,   /*!< SDFM sync source is PWM4 SOCA */
    SDFM_SYNC_PWM4_SOCB  = 0x0DU,   /*!< SDFM sync source is PWM4 SOCB */
    SDFM_SYNC_PWM5_SOCA  = 0x10U,   /*!< SDFM sync source is PWM5 SOCA */
    SDFM_SYNC_PWM5_SOCB  = 0x11U,   /*!< SDFM sync source is PWM5 SOCB */
    SDFM_SYNC_PWM6_SOCA  = 0x14U,   /*!< SDFM sync source is PWM6 SOCA */
    SDFM_SYNC_PWM6_SOCB  = 0x15U,   /*!< SDFM sync source is PWM6 SOCB */
    SDFM_SYNC_PWM7_SOCA  = 0x18U,   /*!< SDFM sync source is PWM7 SOCA */
    SDFM_SYNC_PWM7_SOCB  = 0x19U,   /*!< SDFM sync source is PWM7 SOCB */
    SDFM_SYNC_PWM8_SOCA  = 0x1CU,   /*!< SDFM sync source is PWM8 SOCA */
    SDFM_SYNC_PWM8_SOCB  = 0x1DU,   /*!< SDFM sync source is PWM8 SOCB */
    SDFM_SYNC_PWM9_SOCA  = 0x20U,   /*!< SDFM sync source is PWM9 SOCA */
    SDFM_SYNC_PWM9_SOCB  = 0x21U,   /*!< SDFM sync source is PWM9 SOCB */
    SDFM_SYNC_PWM10_SOCA = 0x24U,   /*!< SDFM sync source is PWM10 SOCA */
    SDFM_SYNC_PWM10_SOCB = 0x25U,   /*!< SDFM sync source is PWM10 SOCB */
    SDFM_SYNC_PWM11_SOCA = 0x28U,   /*!< SDFM sync source is PWM11 SOCA */
    SDFM_SYNC_PWM11_SOCB = 0x29U,   /*!< SDFM sync source is PWM11 SOCB */
    SDFM_SYNC_PWM12_SOCA = 0x2CU,   /*!< SDFM sync source is PWM12 SOCA */
    SDFM_SYNC_PWM12_SOCB = 0x2DU,   /*!< SDFM sync source is PWM12 SOCB */
    SDFM_SYNC_PWM13_SOCA = 0x30U,   /*!< SDFM sync source is PWM13 SOCA */
    SDFM_SYNC_PWM13_SOCB = 0x31U,   /*!< SDFM sync source is PWM13 SOCB */
    SDFM_SYNC_PWM14_SOCA = 0x34U,   /*!< SDFM sync source is PWM14 SOCA */
    SDFM_SYNC_PWM14_SOCB = 0x35U,   /*!< SDFM sync source is PWM14 SOCB */
    SDFM_SYNC_PWM15_SOCA = 0x38U,   /*!< SDFM sync source is PWM15 SOCA */
    SDFM_SYNC_PWM15_SOCB = 0x39U    /*!< SDFM sync source is PWM15 SOCB */
} SDFM_PWMSyncSource;

/**
  * @}
  */

/** @defgroup SDFM_FIFOCLEARSYNCMODE config fifo clear sync mode 
  * @{
  * @brief  Values that can be passed to SDFM_setPWMSyncSource(),as the syncSource parameter.
  */
typedef enum {
    SDFM_FIFO_NOT_CLEARED_ON_SYNC = 0x0U,    /*!< SDFM FIFO buffer is not cleared on Sync signal */
    SDFM_FIFO_CLEARED_ON_SYNC                /*!< SDFM FIFO buffer is cleared on Sync signal */
} SDFM_FIFOClearSyncMode;

/**
  * @}
  */

/** @defgroup SDFM_WAITFORSYNCCLEARMODE config wait for sync clear mode
  * @{
  * @brief  Values that can be passed to SDFM_setWaitForSyncClearMode(),as the fifoClearSyncMode parameter.
  */
 typedef enum {
    SDFM_MANUAL_CLEAR_WAIT_FOR_SYNC = 0x0U,    /*!< Wait for sync cleared using software */
    SDFM_AUTO_CLEAR_WAIT_FOR_SYNC              /*!< Wait for sync cleared automatically */
} SDFM_WaitForSyncClearMode;

/**
  * @}
  */

/** @defgroup SDFM_COMPEVENTNUMBER config compare event number
  * @{
  * @brief  Values that can be passed to SDFM_selectCompEventSource() as the compEventNum parameter
  */
typedef enum {
    SDFM_COMP_EVENT_1 = SDFM_SDCPARM1_CEVT1SEL_S,    /*!< Selects CEVT1 */
    SDFM_COMP_EVENT_2 = SDFM_SDCPARM1_CEVT2SEL_S     /*!< Selects CEVT2 */
} SDFM_CompEventNumber;

/**
  * @}
  */

/** @defgroup SDFM_COMPEVENTSOURCE config compare event source 
  * @{
  * @brief  Values that can be passed to SDFM_selectCompEventSource() as the compEventSource parameter
  */
typedef enum {
    SDFM_COMP_EVENT_SRC_COMPH1 = 0x0U,    /*!< COMPH1 event is the source */
    SDFM_COMP_EVENT_SRC_COMPH1_L1,        /*!< Either of COMPH1 or COMPL1 event */
    SDFM_COMP_EVENT_SRC_COMPH2,           /*!< COMPH2 event is the source */
    SDFM_COMP_EVENT_SRC_COMPH2_L2,        /*!< Either of COMPH2 or COMPL2 event */
    SDFM_COMP_EVENT_SRC_COMPL1 = 0x0U,    /*!< COMPL1 event is the source */
    SDFM_COMP_EVENT_SRC_COMPL2 = 0x2U     /*!< COMPL2 event is the source */
} SDFM_CompEventSource;

/**
  * @}
  */

/** @defgroup SDFM_CLOCKSOURCE config clock source
  * @{
  * @brief  Values that can be passed to SDFM_selectClockSource() as the clkSource parameter.
  */
typedef enum {
    SDFM_CLK_SOURCE_CHANNEL_CLK = 0x0U,                   /*!< Source is respective channel clock */
    SDFM_CLK_SOURCE_SD1_CLK = SDFM_SDCTLPARM1_SDCLKSEL    /*!< Source is SD1 channel clock is the source */
} SDFM_ClockSource;

/**
  * @}
  */

/** @defgroup SDFM_COMPEVENTHIGHSOURCE config compare event high source
  * @{
  * @brief  Values that can be passed to SDFM_selectCompEventHighSource() as the source parameter
  */
typedef enum {
    SDFM_COMPHOUT_SOURCE_COMPHIN = 0x0U,    /*!< Comparator event high source is unfiltered event */
    SDFM_COMPHOUT_SOURCE_FILTER = 0x8U      /*!< Comparator event high source is filtered event */
} SDFM_CompEventHighSource;

/**
  * @}
  */

/** @defgroup SDFM_COMPEVENTLOWSOURCE config compare event low source 
  * @{
  * @brief  Values that can be passed to SDFM_selectCompEventLowSource() as the source parameter
  */
typedef enum {
    SDFM_COMPLOUT_SOURCE_COMPLIN = 0x0U,    /*!< Comparator event low source is unfiltered event */
    SDFM_COMPLOUT_SOURCE_FILTER = 0x800U    /*!< Comparator event low source is filtered event */
} SDFM_CompEventLowSource;

/**
  * @}
  */

/** @defgroup SDFM_SDCCOMPCTL config channel lock 
  * @{
  * @brief  Values that can be passed to SDFM_selectCompEventLowSource() as the source parameter
  */
typedef enum {
    SDFM_SDCOMP_CTL = 0x0U,     /*!< SDCOMPxLock CTL lock register bit */
    SDFM_SDCOMP_COMP = 0x03U    /*!< SDCOMPxLock COMP lock register bit  */
} SDFM_SdcCompCtl;

/**
  * @}
  */

/** @defgroup SDFM_INTCLRNUM config interrupt flag number
  * @{
  * @brief  Values that can be passed to SDFM_clearInterruptFlag() as the source parameter
  */
typedef enum {
    SDFM_FLT1_FLG_CEVT1 = 0x0U,    /*!< channel1 cevt1 interrupt number */
    SDFM_FLT1_FLG_CEVT2,           /*!< channel1 cevt2 interrupt number */
    SDFM_FLT2_FLG_CEVT1,           /*!< channel2 cevt1 interrupt number */
    SDFM_FLT2_FLG_CEVT2,           /*!< channel2 cevt2 interrupt number */
    SDFM_FLT3_FLG_CEVT1,           /*!< channel3 cevt1 interrupt number */
    SDFM_FLT3_FLG_CEVT2,           /*!< channel3 cevt2 interrupt number */
    SDFM_FLT4_FLG_CEVT1,           /*!< channel4 cevt1 interrupt number */
    SDFM_FLT4_FLG_CEVT2,           /*!< channel4 cevt2 interrupt number */
    SDFM_MF1,                      /*!< channel1 module error flag number */
    SDFM_MF2,                      /*!< channel2 module error flag number */
    SDFM_MF3,                      /*!< channel3 module error flag number */
    SDFM_MF4,                      /*!< channel4 module error flag number */
    SDFM_AF1,                      /*!< channel1 filter data ready clear flag number */
    SDFM_AF2,                      /*!< channel2 filter data ready clear flag number */
    SDFM_AF3,                      /*!< channel3 filter data ready clear flag number */
    SDFM_AF4,                      /*!< channel4 filter data ready clear flag number */
    SDFM_SDFFOVF1,                 /*!< channel1 fifo overflow clear flag number */
    SDFM_SDFFOVF2,                 /*!< channel2 fifo overflow clear flag number */
    SDFM_SDFFOVF3,                 /*!< channel3 fifo overflow clear flag number */
    SDFM_SDFFOVF4,                 /*!< channel4 fifo overflow clear flag number */
    SDFM_SDFFINT1,                 /*!< channel1 data ready flag number */
    SDFM_SDFFINT2,                 /*!< channel2 data ready flag number */
    SDFM_SDFFINT3,                 /*!< channel3 data ready flag number */
    SDFM_SDFFINT4,                 /*!< channel4 data ready flag number */
    SDFM_MIF = 0x1FU               /*!< channel interrupt clear flag number */
} SDFM_IntClrNum;

/**
  * @}
  */

/** @defgroup SDFM COMP Event Filter config struct.
  * @{
  * @brief  Values that can be passed to SDFM_configCompEventLowFilter() & 
  *         SDFM_configCompEventHighFilter() as the \e filterNumber.
  */
typedef struct
{
    uint16_t sampleWindow;    /*!< Sample window size */
    uint16_t threshold;       /*!< Majority voting threshold */
    uint16_t clkPrescale;     /*!< Sample clock pre-scale */
} SDFM_CompEventFilterConfig;

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
 * \brief  SDFM enable External Reset.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_enableExternalReset (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)), SDFM_SDDFPARM1_SDSYNCEN);
}

/**
 * \brief  SDFM disable External Reset.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_disableExternalReset (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)), SDFM_SDDFPARM1_SDSYNCEN);
}

/**
 * \brief  SDFM enable Filter.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_enableFilter (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)), SDFM_SDDFPARM1_FEN);
}

/**
 * \brief  SDFM disable Filter.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_disableFilter (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)), SDFM_SDDFPARM1_FEN);
}

/**
 * \brief  SDFM enable FIFO Buffer.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_enableFIFOBuffer (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)), SDFM_SDFIFOCTL1_FFEN);
}

/**
 * \brief  SDFM disable FIFO Buffer.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_disableFIFOBuffer (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)), SDFM_SDFIFOCTL1_FFEN);
}

/**
 * \brief  SDFM get zero cross trip status.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned the status of SDTATUS register
 *                          - 0: Compare filter results<SDCMPSSHZx.HLTZ (x=1/2/3/4)
 *                          - 1: Compare filter results>=SDCMPSSHZx.HLTZ(x=1/2/3/4)
 */
static inline bool SDFM_getZeroCrossTripStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return (((sdfm->SDSTATUS.WORDVAL >> (uint16_t)filterNumber) & 0x1UL) == 1UL);
}

/**
 * \brief  SDFM clear zero cross trip status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_clearZeroCrossTripStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(sdfm->SDCTL.WORDVAL, ((uint16_t)1UL << (uint16_t)filterNumber));
}

/**
 * \brief  SDFM enable comparator
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_enableComparator (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), SDFM_SDCPARM1_CEN);
}

/**
 * \brief  SDFM disable comparator
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_disableComparator (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), SDFM_SDCPARM1_CEN);
}

/**
 * \brief  SDFM select compare event source
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_selectCompEventSource (SDFM_TypeDef *sdfm,
                                               SDFM_FilterNumber filterNumber,
                                               SDFM_CompEventNumber compEventNum,
                                               SDFM_CompEventSource compEventSource)
{
    MODIFY_REG(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)),
               (0x3UL << (uint32_t)compEventNum),
               ((uint32_t)compEventSource << (uint32_t)compEventNum));
}

/**
 * \brief  SDFM set filter type
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  filterType      filter type config 
 *                          This parameter can be any value of @ref SDFM_FILTER
 */
static inline void SDFM_setFilterType (SDFM_TypeDef *sdfm,
                                       SDFM_FilterNumber filterNumber,
                                       SDFM_Filter filterType)
{
    MODIFY_REG(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)),
               SDFM_SDDFPARM1_SST_M,
               (uint32_t)filterType << SDFM_SDDFPARM1_SST_S);
}

/**
 * \brief  SDFM set filter over sampling ratio
 * \param  sdfm                 SDFM pointer to a SDFM_TypeDef structure
 *                               - SDFM1: SDFM1 base address index
 *                               - SDFM2: SDFM2 base address index
 *                               - SDFM3: SDFM3 base address index
 *                               - SDFM4: SDFM4 base address index
 * \param  filterNumber         filter number config 
 *                               This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  overSamplingRatio    over sampling ratio config 
 *                               This parameter is an unsigned integer that is greater
 *                               than or equal to 0x0UL and less than or equal to 0xFFUL
 */
static inline void SDFM_setFilterOverSamplingRatio (SDFM_TypeDef *sdfm,
                                                    SDFM_FilterNumber filterNumber,
                                                    uint16_t overSamplingRatio)
{
    MODIFY_REG(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)),
               SDFM_SDDFPARM1_DOSR_M,
               overSamplingRatio);
}

/**
 * \brief  SDFM setup modulator clock
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  clockMode       modulator clock mode config
 *                          -0: x1
 *                          -1: x0.5
 *                          -2: Working in Manchester encoding mode does not require a clock
 *                          -3: x2 
 */
static inline void SDFM_setupModulatorClock (SDFM_TypeDef *sdfm,
                                             SDFM_FilterNumber filterNumber,
                                             uint16_t clockMode)
{
    volatile uint32_t *pReg = (volatile uint32_t *)(&sdfm->SDCTLPARM1 + filterNumber * 14UL);

    /* Write to MOD bits */
    MODIFY_REG(*pReg, SDFM_SDCTLPARM1_MOD_M, clockMode & 0x3UL);

    /* Enable data and clock synchronizer */
    SET_BIT(*pReg, (SDFM_CLOCK_SYNCHRONIZER | SDFM_DATA_SYNCHRONIZER));
}

/**
 * \brief  SDFM set output data format
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  dataFormat      output data format config 
 *                          This parameter can be any value of @ref SDFM_OUTPUTDATAFORMAT
 */
static inline void SDFM_setOutputDataFormat (SDFM_TypeDef *sdfm,
                                             SDFM_FilterNumber filterNumber,
                                             SDFM_OutputDataFormat dataFormat)
{
    MODIFY_REG(TYPE32(&(sdfm->SDDPARM1) + (filterNumber * 14UL)), SDFM_SDDPARM1_DR, ((uint32_t)dataFormat << 10UL));
}

/**
 * \brief  SDFM set data shift value 
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  shiftValue      output data format config 
 *                          This parameter is an unsigned integer that is greater
 *                          than or equal to 0x0UL and less than or equal to 0x20UL
 */
static inline void SDFM_setDataShiftValue (SDFM_TypeDef *sdfm,
                                           SDFM_FilterNumber filterNumber,
                                           uint16_t shiftValue)
{
    MODIFY_REG(TYPE32(&(sdfm->SDDPARM1) + (filterNumber * 14UL)), SDFM_SDDPARM1_SH_M, shiftValue << SDFM_SDDPARM1_SH_S);
}

/**
 * \brief  SDFM Set Filter output high-level threshold.
 * \param  sdfm             SDFM pointer to a SDFM_TypeDef structure
 *                           - SDFM1: SDFM1 base address index
 *                           - SDFM2: SDFM2 base address index
 *                           - SDFM3: SDFM3 base address index
 *                           - SDFM4: SDFM4 base address index
 * \param  filterNumber     filter number config 
 *                           This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  highThreshold    high-level threshold 1 & 2
 *
 * This function sets the unsigned high-level threshold value for the
 * Comparator filter output. If the output value of the filter exceeds
 * highThreshold and interrupt generation is enabled, an interrupt will be
 * issued. The param \b highThreshold takes both high threshold 1 & 2 values.
 * The upper 16-bits represent the high threshold 2 value while lower 16-bits
 * represent the threshold 1 values.
 *
 */
static inline void SDFM_setCompFilterHighThreshold (SDFM_TypeDef *sdfm,
                                                    SDFM_FilterNumber filterNumber,
                                                    uint32_t highThreshold)
{
    WRITE_REG(TYPE32(&(sdfm->SDFLT1CMPH1) + (filterNumber * 14UL)), (uint16_t)highThreshold);
    WRITE_REG(TYPE32(&(sdfm->SDFLT1CMPH2) + (filterNumber * 14UL)), (uint16_t)(highThreshold >> 16U));
}

/**
 * \brief  SDFM Set Filter output low-level threshold.
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  lowThreshold    low-level threshold 1 & 2
 *
 * This function sets the unsigned low-level threshold value 1 or 2 for the
 * Comparator filter output. If the output value of the filter gets below
 * lowThreshold and interrupt generation is enabled, an interrupt will be
 * issued. The param \b lowThreshold takes both low threshold 1 & 2 values.
 * The upper 16-bits represent the low threshold 2 value while lower 16-bits
 * represent the threshold 1 values.
 */
static inline void SDFM_setCompFilterLowThreshold (SDFM_TypeDef *sdfm,
                                                   SDFM_FilterNumber filterNumber,
                                                   uint32_t lowThreshold)
{
    WRITE_REG(TYPE32(&(sdfm->SDFLT1CMPL1) + (filterNumber * 14UL)), (uint16_t)lowThreshold);
    WRITE_REG(TYPE32(&(sdfm->SDFLT1CMPL2) + (filterNumber * 14UL)), (uint16_t)(lowThreshold >> 16U));
}

/**
 * \brief  SDFM set compare filter zero cross threshold 
 * \param  sdfm                  SDFM pointer to a SDFM_TypeDef structure
 *                                - SDFM1: SDFM1 base address index
 *                                - SDFM2: SDFM2 base address index
 *                                - SDFM3: SDFM3 base address index
 *                                - SDFM4: SDFM4 base address index
 * \param  filterNumber          filter number config 
 *                                This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  zeroCrossThreshold    zero cross threshold
 *                                This parameter is an unsigned integer that is greater
 *                                than or equal to 0x0UL and less than or equal to 0x7FFF
 */
static inline void SDFM_setCompFilterZeroCrossThreshold (SDFM_TypeDef *sdfm,
                                                         SDFM_FilterNumber filterNumber,
                                                         uint16_t zeroCrossThreshold)
{
    MODIFY_REG(TYPE32(&(sdfm->SDFLT1CMPHZ) + (filterNumber * 14UL)), SDFM_SDFLT1CMPHZ_HLTZ_M, zeroCrossThreshold);
}

/**
 * \brief  SDFM enable zero cross edge detect
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_enableZeroCrossEdgeDetect (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), SDFM_SDCPARM1_HZEN);
}

/**
 * \brief  SDFM disable zero cross edge detect
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_disableZeroCrossEdgeDetect (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), SDFM_SDCPARM1_HZEN);
}

/**
 * \brief  SDFM enable interrupt
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  intFlags        Low, high threshold, Modulator failure config SDCPARM1 register
 *                          BIT9: SDFM_MODULATOR_FAILURE_INTERRUPT
 *                          BIT6: SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT
 *                          BIT5: SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT
 *                         Data filter acknowledge interrupt config SDDFPARM1 register
 *                          BIT9: SDFM_SDDFPARM1_AE
 *                         Data filter acknowledge interrupt config SDFIFOCTL1 register
 *                          BIT12: SDFM_FIFO_INTERRUPT
 *                          BIT15: SDFM_FIFO_OVERFLOW_INTERRUPT
 */
static inline void SDFM_enableInterrupt (SDFM_TypeDef *sdfm,
                                         SDFM_FilterNumber filterNumber,
                                         uint16_t intFlags)
{
    /* Low, high threshold, Modulator failure */
    if ((intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT | SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT | SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT)) != 0UL)
    {
        /* Set IEL or IEH or MFIE bit of SDFM_O_SDCPARMx */
        SET_BIT(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), (intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT |
                                                                    SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT |
                                                                    SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT)));
    }
    /* Data filter acknowledge interrupt */
    if ((intFlags & SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT) != 0UL)
    {
        SET_BIT(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)), SDFM_SDDFPARM1_AE);
    }
    /* Data filter acknowledge interrupt */
    if ((intFlags & (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT)) != 0UL)
    {
        SET_BIT(TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)), (intFlags & (SDFM_FIFO_INTERRUPT |
                                                                        SDFM_FIFO_OVERFLOW_INTERRUPT)));
    }
}

/**
 * \brief  SDFM disable interrupt
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  intFlags        Low, high threshold, Modulator failure config SDCPARM1 register
 *                          BIT9: SDFM_MODULATOR_FAILURE_INTERRUPT
 *                          BIT6: SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT
 *                          BIT5: SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT
 *                         Data filter acknowledge interrupt config SDDFPARM1 register
 *                          BIT9: SDFM_SDDFPARM1_AE
 *                         Data filter acknowledge interrupt config SDFIFOCTL1 register
 *                          BIT12: SDFM_FIFO_INTERRUPT
 *                          BIT15: SDFM_FIFO_OVERFLOW_INTERRUPT
 */
static inline void SDFM_disableInterrupt (SDFM_TypeDef *sdfm,
                                          SDFM_FilterNumber filterNumber,
                                          uint16_t intFlags)
{
    /* Low, high threshold, Modulator failure */
    if ((intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT | SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT | SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT)) != 0UL)
    {
        /* Set IEL or IEH or MFIE bit of SDFM_O_SDCPARMx */
        CLEAR_BIT(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), (intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT |
                                                                      SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT |
                                                                      SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT)));
    }
    /* Data filter acknowledge interrupt */
    if ((intFlags & SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT) != 0UL)
    {
        CLEAR_BIT(TYPE32(&(sdfm->SDDFPARM1) + (filterNumber * 14UL)), SDFM_SDDFPARM1_AE);
    }
    /* Data filter acknowledge interrupt */
    if ((intFlags & (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT)) != 0UL)
    {
        CLEAR_BIT(TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)), (intFlags & (SDFM_FIFO_INTERRUPT |
                                                                          SDFM_FIFO_OVERFLOW_INTERRUPT)));
    }
}

/**
 * \brief  SDFM set comparator filter type
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  filterType      filter type config 
 *                          This parameter can be any value of @ref SDFM_FILTER
 */
static inline void SDFM_setComparatorFilterType (SDFM_TypeDef *sdfm,
                                                 SDFM_FilterNumber filterNumber,
                                                 SDFM_Filter filterType)
{
    MODIFY_REG(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)),
               SDFM_SDCPARM1_CS1_CS0_M, 
               ((uint32_t)filterType << SDFM_SDCPARM1_CS1_CS0_S));
}

/**
 * \brief  SDFM set comparator filter over sampling ratio
 * \param  sdfm                 SDFM pointer to a SDFM_TypeDef structure
 *                               - SDFM1: SDFM1 base address index
 *                               - SDFM2: SDFM2 base address index
 *                               - SDFM3: SDFM3 base address index
 *                               - SDFM4: SDFM4 base address index
 * \param  filterNumber         filter number config 
 *                               This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  overSamplingRatio    over sampling ratio config 
 *                               This parameter is an unsigned integer that is greater
 *                               than or equal to 0x0UL and less than or equal to 0x1F
 */
static inline void SDFM_setCompFilterOverSamplingRatio (SDFM_TypeDef *sdfm,
                                                        SDFM_FilterNumber filterNumber,
                                                        uint16_t overSamplingRatio)
{
    MODIFY_REG(TYPE32(&(sdfm->SDCPARM1) + (filterNumber * 14UL)), SDFM_SDCPARM1_COSR_M, overSamplingRatio);
}

/**
 * \brief  SDFM get filter data
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned filter data 
 *                          This value is an unsigned integer that is greater
 *                          than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
static inline uint32_t SDFM_getFilterData (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return TYPE32(&(sdfm->SDDATA1) + (filterNumber * 14UL));
}

/**
 * \brief  SDFM get threshold status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned Output Threshold Status 
 *                          This value can be any value of @ref SDFM_OUTPUTTHRESHOLDSTATUS
 */
static inline uint8_t SDFM_getThresholdStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((SDFM_OutputThresholdStatus)((sdfm->SDIFLG.WORDVAL >> (2UL * (uint16_t)filterNumber)) & 0x3UL));
}

/**
 * \brief  SDFM get modulator status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned modulator Status 
 *                          - 1: cevt1 occur
 *                          - 0: cevt1 no occur
 */
static inline bool SDFM_getModulatorStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((((sdfm->SDIFLG.WORDVAL) >> ((uint16_t)filterNumber + 8UL)) & 0x1UL) != 0x1UL);
}

/**
 * \brief  SDFM get new filter data status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned new filter data Status 
 *                          - 1: filter new data 
 *                          - 0: filter no new data
 */
static inline bool SDFM_getNewFilterDataStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((((sdfm->SDIFLG.WORDVAL) >> ((uint16_t)filterNumber + 12UL)) & 0x1UL) == 0x1UL);
}

/**
 * \brief  SDFM get fifo over flow data status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned fifo over flow Status 
 *                          - 1: FIFO overflow
 *                          - 0: FIFO no overflow
 */
static inline bool SDFM_getFIFOOverflowStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((((sdfm->SDIFLG.WORDVAL) >> ((uint16_t)filterNumber + 16UL)) & 0x1UL) == 0x1UL);
}

/**
 * \brief  SDFM get fifo isr status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned fifo isr Status 
 *                          - 1: SDFIFO DATA Ready
 *                          - 0: SDFIFO DATA no Ready
 */
static inline bool SDFM_getFIFOISRStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((((sdfm->SDIFLG.WORDVAL) >> ((uint16_t)filterNumber + 20UL) & 0x1UL) == 0x1UL));
}

/**
 * \brief  SDFM get isr status
 * \param  sdfm    SDFM pointer to a SDFM_TypeDef structure
 *                  - SDFM1: SDFM1 base address index
 *                  - SDFM2: SDFM2 base address index
 *                  - SDFM3: SDFM3 base address index
 *                  - SDFM4: SDFM4 base address index
 * \return returned isr Status 
 *                  - 1: Error interrupt occur
 *                  - 0: Error interrupt no occur
 */ 
static inline bool SDFM_getIsrStatus (SDFM_TypeDef *sdfm)
{
    return (((sdfm->SDIFLG.WORDVAL) >> 31UL) == 0x1UL);
}

/**
 * \brief  SDFM clear interrupt flag
 * \param  sdfm               SDFM pointer to a SDFM_TypeDef structure
 *                             - SDFM1: SDFM1 base address index
 *                             - SDFM2: SDFM2 base address index
 *                             - SDFM3: SDFM3 base address index
 *                             - SDFM4: SDFM4 base address index
 * \param  interruptNumber    interrupt number
 *                             This parameter can be any value of @ref SDFM_INTCLRNUM
 *                
 */
static inline void SDFM_clearInterruptFlag (SDFM_TypeDef *sdfm, SDFM_IntClrNum interruptNumber)
{
    SET_BIT(sdfm->SDIFLGCLR.WORDVAL, (0x01 << interruptNumber));
}

/**
 * \brief  SDFM enable main interrupt
 * \param  sdfm    SDFM pointer to a SDFM_TypeDef structure
 *                  - SDFM1: SDFM1 base address index
 *                  - SDFM2: SDFM2 base address index
 *                  - SDFM3: SDFM3 base address index
 *                  - SDFM4: SDFM4 base address index
 */
static inline void SDFM_enableMainInterrupt (SDFM_TypeDef *sdfm)
{
    SET_BIT(sdfm->SDCTL.WORDVAL, SDFM_SDCTL_MIE);
}

/**
 * \brief  SDFM disable main interrupt
 * \param  sdfm    SDFM pointer to a SDFM_TypeDef structure
 *                  - SDFM1: SDFM1 base address index
 *                  - SDFM2: SDFM2 base address index
 *                  - SDFM3: SDFM3 base address index
 *                  - SDFM4: SDFM4 base address index
 */
static inline void SDFM_disableMainInterrupt (SDFM_TypeDef *sdfm)
{
    CLEAR_BIT(sdfm->SDCTL.WORDVAL, SDFM_SDCTL_MIE);
}

/**
 * \brief  SDFM enable main filter
 * \param  sdfm    SDFM pointer to a SDFM_TypeDef structure
 *                  - SDFM1: SDFM1 base address index
 *                  - SDFM2: SDFM2 base address index
 *                  - SDFM3: SDFM3 base address index
 *                  - SDFM4: SDFM4 base address index
 */
static inline void SDFM_enableMainFilter (SDFM_TypeDef *sdfm)
{
    SET_BIT(sdfm->SDMFILEN.WORDVAL, SDFM_SDMFILEN_MFE);
}

/**
 * \brief  SDFM disable main filter
 * \param  sdfm    SDFM pointer to a SDFM_TypeDef structure
 *                  - SDFM1: SDFM1 base address index
 *                  - SDFM2: SDFM2 base address index
 *                  - SDFM3: SDFM3 base address index
 *                  - SDFM4: SDFM4 base address index
 */
static inline void SDFM_disableMainFilter (SDFM_TypeDef *sdfm)
{
    CLEAR_BIT(sdfm->SDMFILEN.WORDVAL, SDFM_SDMFILEN_MFE);
}

/**
 * \brief  SDFM get fifo data count
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned fifo data count
 *                          This value is an unsigned integer that is greater
 *                          than or equal to 0x0UL and less than or equal to 0x1FUL
 */
static inline uint16_t SDFM_getFIFODataCount (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)) & SDFM_SDFIFOCTL1_SDFFST_M) >> SDFM_SDFIFOCTL1_SDFFST_S);
}

/**
 * \brief  SDFM get comparator sinc data
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned comprarator sinc data
 *                          This value is an unsigned integer that is greater
 *                          than or equal to 0x0UL and less than or equal to 0xFFFFUL
 */
static inline uint16_t SDFM_getComparatorSincData (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return (TYPE32(&(sdfm->SDCDATA1) + (filterNumber * 14UL)));
}

/**
 * \brief  SDFM get fifo data
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned fifo data
 *                          This value is an unsigned integer that is greater
 *                          than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
static inline uint32_t SDFM_getFIFOData (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return (TYPE32(&(sdfm->SDDATAFIFO1) + (filterNumber * 14UL)));
}

/**
 * \brief  SDFM set fifo interrupt level
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  fifoLevel       fifo level value
 *                          This value is an unsigned integer that is greater
 *                          than or equal to 0x0UL and less than or equal to 0x1FUL
 */
static inline void SDFM_setFIFOInterruptLevel (SDFM_TypeDef *sdfm,
                                               SDFM_FilterNumber filterNumber,
                                               uint16_t fifoLevel)
{
    MODIFY_REG(TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)),
               SDFM_SDFIFOCTL1_SDFFIL_M,
               fifoLevel & SDFM_SDFIFOCTL1_SDFFIL_M);
}

/**
 * \brief  SDFM set data ready interrupt source 
 * \param  sdfm               SDFM pointer to a SDFM_TypeDef structure
 *                             - SDFM1: SDFM1 base address index
 *                             - SDFM2: SDFM2 base address index
 *                             - SDFM3: SDFM3 base address index
 *                             - SDFM4: SDFM4 base address index
 * \param  filterNumber       filter number config 
 *                             This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  dataReadySource    data ready source
 *                             This parameter can be any value of @ref SDFM_DATAREADYINTRERRUPTSOURCE
 */
static inline void SDFM_setDataReadyInterruptSource (SDFM_TypeDef *sdfm,
                                                     SDFM_FilterNumber filterNumber,
                                                     SDFM_DataReadyInterruptSource dataReadySource)
{
    MODIFY_REG(TYPE32(&(sdfm->SDFIFOCTL1) + (filterNumber * 14UL)),
               SDFM_SDFIFOCTL1_DRINTSEL_M,
               (uint32_t)dataReadySource << SDFM_SDFIFOCTL1_DRINTSEL_S);
}

/**
 * \brief  SDFM get wait for sync status
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \return returned sync status of "1" or "0"
 */
static inline bool SDFM_getWaitForSyncStatus (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    return ((((TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL))) & SDFM_SDSYNC1_WTSYNFLG) >> 7UL) == 0x1UL);
}

/**
 * \brief  SDFM clear wait for sync flag
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_clearWaitForSyncFlag (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL)), SDFM_SDSYNC1_WTSYNCLR);
}

/**
 * \brief  SDFM enable wait for sync
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_enableWaitForSync (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL)), SDFM_SDSYNC1_WTSYNCEN);
}

/**
 * \brief  SDFM disable wait for sync
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_disableWaitForSync (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL)), SDFM_SDSYNC1_WTSYNCEN);
}

/**
 * \brief  SDFM set pwm sync source
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  syncSource      sync source config 
 *                          This parameter can be any value of @ref SDFM_PWMSYNCSOURCE
 */
static inline void SDFM_setPWMSyncSource (SDFM_TypeDef *sdfm,
                                          SDFM_FilterNumber filterNumber,
                                          SDFM_PWMSyncSource syncSource)
{
    MODIFY_REG(TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL)), SDFM_SDSYNC1_SYNCSEL_M, (uint32_t)syncSource);
    SDFM_enableExternalReset(sdfm, filterNumber);
}

/**
 * \brief  SDFM set fifo clear on sync mode
 * \param  sdfm                 SDFM pointer to a SDFM_TypeDef structure
 *                               - SDFM1: SDFM1 base address index
 *                               - SDFM2: SDFM2 base address index
 *                               - SDFM3: SDFM3 base address index
 *                               - SDFM4: SDFM4 base address index
 * \param  filterNumber         filter number config 
 *                               This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  fifoClearSyncMode    fifo clear sync mode config 
 *                               This parameter can be any value of @ref SDFM_FIFOCLEARSYNCMODE
 */
static inline void SDFM_setFIFOClearOnSyncMode (SDFM_TypeDef *sdfm,
                                                SDFM_FilterNumber filterNumber,
                                                SDFM_FIFOClearSyncMode fifoClearSyncMode)
{
    MODIFY_REG(TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL)),
               SDFM_SDSYNC1_FFSYNCCLREN_M,
               (uint32_t)fifoClearSyncMode << SDFM_SDSYNC1_FFSYNCCLREN_S);
}

/**
 * \brief  SDFM set wait for sync clear mode
 * \param  sdfm             SDFM pointer to a SDFM_TypeDef structure
 *                           - SDFM1: SDFM1 base address index
 *                           - SDFM2: SDFM2 base address index
 *                           - SDFM3: SDFM3 base address index
 *                           - SDFM4: SDFM4 base address index
 * \param  filterNumber     filter number config 
 *                           This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  syncClearMode    clear sync mode config 
 *                           This parameter can be any value of @ref SDFM_WAITFORSYNCCLEARMODE
 */
static inline void SDFM_setWaitForSyncClearMode (SDFM_TypeDef *sdfm,
                                                 SDFM_FilterNumber filterNumber,
                                                 SDFM_WaitForSyncClearMode syncClearMode)
{
    MODIFY_REG(TYPE32(&(sdfm->SDSYNC1) + (filterNumber * 14UL)),
               SDFM_SDSYNC1_WTSCLREN_M,
               (uint32_t)syncClearMode << SDFM_SDSYNC1_WTSCLREN_S);
}

/**
 * \brief  SDFM select clock source
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  clkSource       clock source config 
 *                          This parameter can be any value of @ref SDFM_CLOCKSOURCE
 */
static inline void SDFM_selectClockSource (SDFM_TypeDef *sdfm,
                                           SDFM_FilterNumber filterNumber,
                                           SDFM_ClockSource clkSource)
{
    MODIFY_REG(TYPE32(&(sdfm->SDCTLPARM1) + (filterNumber * 14UL)), SDFM_SDCTLPARM1_SDCLKSEL, (uint16_t)clkSource);
}

/**
 * \brief  SDFM enable synchronizer
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  syncConfig      sync config 
 *                          -1: open sync
 *                          -0: close sync
 */
static inline void SDFM_enableSynchronizer (SDFM_TypeDef *sdfm,
                                            SDFM_FilterNumber filterNumber,
                                            uint16_t syncConfig)
{
    SET_BIT(TYPE32(&(sdfm->SDCTLPARM1) + (filterNumber * 14UL)), syncConfig);
}

/**
 * \brief  SDFM disable synchronizer
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  syncConfig      sync config 
 *                          -1: open sync
 *                          -0: close sync
 */
static inline void SDFM_disableSynchronizer (SDFM_TypeDef *sdfm,
                                             SDFM_FilterNumber filterNumber,
                                             uint16_t syncConfig)
{
    CLEAR_BIT(TYPE32(&(sdfm->SDCTLPARM1) + (filterNumber * 14UL)), syncConfig);
}

/**
 * \brief  SDFM select comparator event high source 
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  source          comparator event high source 
 *                          This parameter can be any value of @ref SDFM_COMPEVENTHIGHSOURCE
 */
static inline void SDFM_selectCompEventHighSource (SDFM_TypeDef *sdfm,
                                                   SDFM_FilterNumber filterNumber,
                                                   SDFM_CompEventHighSource source)
{
    MODIFY_REG(TYPE32(&(sdfm->SDCOMP1CTL) + (filterNumber * 6UL)), SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_M, (uint32_t)source);
}

/**
 * \brief  SDFM select comparator event low source
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  source          comparator event high source 
 *                          This parameter can be any value of @ref SDFM_COMPEVENTLOWSOURCE
 */
static inline void SDFM_selectCompEventLowSource (SDFM_TypeDef *sdfm,
                                                  SDFM_FilterNumber filterNumber,
                                                  SDFM_CompEventLowSource source)
{
    MODIFY_REG(TYPE32(&(sdfm->SDCOMP1CTL) + (filterNumber * 6UL)), SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_M, (uint32_t)source);
}

/**
 * \brief  SDFM init comparator event low filter
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_initCompEventLowFilter (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDCOMP1EVT2FLTCTL) + (filterNumber * 6UL)), (uint16_t)SDFM_SDCOMP1EVT2FLTCTL_FILINIT);
}

/**
 * \brief  SDFM init comparator event high filter
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 */
static inline void SDFM_initCompEventHighFilter (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber)
{
    SET_BIT(TYPE32(&(sdfm->SDCOMP1EVT1FLTCTL) + (filterNumber * 6UL)), (uint16_t)SDFM_SDCOMP1EVT1FLTCTL_FILINIT);
}

/**
 * \brief  SDFM lock comparator event filter config
 * \param  sdfm            SDFM pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  lockConfig      lock config 
 *                          This parameter can be any value of @ref SDFM_SDCCOMPCTL
 */
static inline void SDFM_lockCompEventFilterConfig (SDFM_TypeDef *sdfm,
                                                   SDFM_FilterNumber filterNumber,
                                                   SDFM_SdcCompCtl lockConfig)
{
    SET_BIT(TYPE32(&(sdfm->SDCOMP1LOCK) + (filterNumber * 6UL)), (1 << lockConfig));
}

/**
 * \brief  SDFM config comparator.
 * \param  sdfm       sdfm pointer to a SDFM_TypeDef structure
 *                     - SDFM1: SDFM1 base address index
 *                     - SDFM2: SDFM2 base address index
 *                     - SDFM3: SDFM3 base address index
 *                     - SDFM4: SDFM4 base address index
 * \param  config1    sdfm config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x1FUL
 * \param  config2    sdfm config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x7FFUL
 * \param  config3    sdfm config3
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x7FFUL
 */
extern void SDFM_configComparator (SDFM_TypeDef *sdfm, uint16_t config1, uint32_t config2, uint16_t config3);

/**
 * \brief  SDFM config enhanced comparator.
 * \param  sdfm                  sdfm pointer to a SDFM_TypeDef structure
 *                                - SDFM1: SDFM1 base address index
 *                                - SDFM2: SDFM2 base address index
 *                                - SDFM3: SDFM3 base address index
 *                                - SDFM4: SDFM4 base address index
 * \param  filterConfig          filter config 
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x1FUL
 * \param  highLowThreshold1     high low threshold1
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x7FFUL
 * \param  highLowThreshold2     high low thredshold2
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x7FFUL
 * \param  zeroCrossThreshold    zero cross threshold
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x7FFUL
 */
extern void SDFM_configEnhancedComparator (SDFM_TypeDef *sdfm,
                                           uint16_t filterConfig,
                                           uint32_t highLowThreshold1,
                                           uint32_t highLowThreshold2,
                                           uint16_t zeroCrossThreshold);

/**
 * \brief  SDFM config data filter
 * \param  sdfm       sdfm pointer to a SDFM_TypeDef structure
 *                     - SDFM1: SDFM1 base address index
 *                     - SDFM2: SDFM2 base address index
 *                     - SDFM3: SDFM3 base address index
 *                     - SDFM4: SDFM4 base address index
 * @param  config1    Data filter config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x1FUL
 * @param  config2    Data filter config2
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x1FUL
 */
extern void SDFM_configDataFilter (SDFM_TypeDef *sdfm, uint16_t config1, uint16_t config2);

/**
 * \brief  SDFM config zero cross comparator
 * \param  sdfm       sdfm pointer to a SDFM_TypeDef structure
 *                     - SDFM1: SDFM1 base address index
 *                     - SDFM2: SDFM2 base address index
 *                     - SDFM3: SDFM3 base address index
 *                     - SDFM4: SDFM4 base address index
 * @param  config1    zero cross comparator config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0xffUL
 * @param  config2    zero cross comparator config2
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x7fffUL
 */
extern void SDFM_configZeroCrossComparator (SDFM_TypeDef *sdfm, uint16_t config1, uint16_t config2);

/**
 * \brief  SDFM config data filter fifo
 * \param  sdfm       sdfm pointer to a SDFM_TypeDef structure
 *                     - SDFM1: SDFM1 base address index
 *                     - SDFM2: SDFM2 base address index
 *                     - SDFM3: SDFM3 base address index
 *                     - SDFM4: SDFM4 base address index
 * @param  config1    data filter fifo config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x1FUL
 * @param  config2    data filter fifo config2
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x1UL
 */
extern void SDFM_configDataFilterFIFO (SDFM_TypeDef *sdfm, uint16_t config1, uint16_t config2);

/**
 * \brief  SDFM config comparator event low filter
 * \param  sdfm            sdfm pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  config          the struct of sdfm comp event filter config
 */
extern void SDFM_configCompEventLowFilter (SDFM_TypeDef *sdfm,
                                           SDFM_FilterNumber filterNumber,
                                           const SDFM_CompEventFilterConfig *config);

/**
 * \brief  SDFM config comparator event low filter
 * \param  sdfm            sdfm pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * \param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * \param  config          the struct of sdfm comp event filter config
 */
extern void SDFM_configCompEventHighFilter (SDFM_TypeDef *sdfm,
                                            SDFM_FilterNumber filterNumber,
                                            const SDFM_CompEventFilterConfig *config);



#ifdef __cplusplus
}
#endif


#endif
