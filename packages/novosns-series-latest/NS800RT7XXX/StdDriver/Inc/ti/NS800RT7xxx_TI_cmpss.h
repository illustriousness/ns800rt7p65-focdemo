/**
  * @file       NS800RT7xxx_TI_cmpss.h
  * @author     zhoukai
  * @brief      Header file for NS800RT7xxx cmpss module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_CMPSS_H__
#define __NS800RT7XXX_TI_CMPSS_H__


#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup CMPSS_COMPDACCFG CMPSS Internal Dac Config
  * @{
  * @brief  Macro definitions about CMPSS internal dac configuration. 
  *         Values that can be passed to CMPSS_configDAC() as the \e config parameter.   
  */ 
#define CMPSS_DACVAL_SYSCLK     (0x00UL)    /*!< DAC value updated from SYSCLK */
#define CMPSS_DACVAL_PWMSYNC    (0x80UL)    /*!< DAC value updated from PWMSYNC */
#define CMPSS_DACREF_VDDA       (0x60UL)    /*!< VDDA is the voltage reference */
#define CMPSS_DACREF_VREF       (0x40UL)    /*!< VREF is the voltage reference */
#define CMPSS_DACREF_VDAC       (0x20UL)    /*!< VDAC is the voltage reference */
#define CMPSS_DACSRC_SHDW       (0x00UL)    /*!< DAC value updated from shadow register */
#define CMPSS_DACSRC_RAMP       (0x01UL)    /*!< DAC value is updated from the ramp register */

/**
  * @}
  */
 
/** @defgroup CMPSS_COMPCTL CMPSS Control Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS control register definition.  
  */ 
#define CMPSS_COMPCTL_COMPHSOURCE       (0x1UL)          /*!< High comparator input source */
#define CMPSS_COMPCTL_COMPHINV          (0x2UL)          /*!< High comparator output invert */
#define CMPSS_COMPCTL_ASYNCHEN          (0x40UL)         /*!< High comparator asynchronous path enable */                              
#define CMPSS_COMPCTL_COMPDACEH         (0x80UL)         /*!< High comparator/DAC enable */                           
#define CMPSS_COMPCTL_COMPLSOURCE       (0x100UL)        /*!< Low comparator input source */                             
#define CMPSS_COMPCTL_COMPLINV          (0x200UL)        /*!< Low comparator output invert */                             
#define CMPSS_COMPCTL_ASYNCLEN          (0x4000UL)       /*!< Low comparator/DAC enable */
#define CMPSS_COMPCTL_COMPDACEL         (0x8000UL)       /*!< Low comparator asynchronous path enable */    
#define CMPSS_COMPCTL_COMPHANAVOSW      (0x10000UL)      /*!< High comparator asynchronous output software control */                             
#define CMPSS_COMPCTL_COMPHLPMEN        (0x20000UL)      /*!< Enable high comparator and low power consumption */                             
#define CMPSS_COMPCTL_COMPLANAVOSW      (0x1000000UL)    /*!< Low comparator asynchronous output software control */                             
#define CMPSS_COMPCTL_COMPLLPMEN        (0x2000000UL)    /*!< Enable low comparator and low power consumption */                             

/**
  * @}
  */
 
/** @defgroup CMPSS_COMPHYSCTL CMPSS Hysteresis Control Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS hystersis control register definition.     
  */ 
#define CMPSS_COMPHYSCTL_COMPHHYS_S    (0x0UL)     /*!< High comparator hysteresis */ 
#define CMPSS_COMPHYSCTL_COMPHHYS_M    (0x7UL)     /*!< COMPHHYS Mask */
#define CMPSS_COMPHYSCTL_COMPLHYS_S    (4UL)       /*!< Low comparator hysteresis */
#define CMPSS_COMPHYSCTL_COMPLHYS_M    (0x70UL)    /*!< COMPLHYS Mask */

/**
  * @}
  */

/** @defgroup CMPSS_COMPSTS CMPSS Status Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS status register definition.   
  */ 
#define CMPSS_COMPSTS_COMPHSTS      (0x1UL)      /*!< High comparator digital filter output */
#define CMPSS_COMPSTS_COMPHLATCH    (0x2UL)      /*!< Latched value of high comparator digital filter output */
#define CMPSS_COMPSTS_COMPLSTS      (0x100UL)    /*!< Low comparator digital filter output */
#define CMPSS_COMPSTS_COMPLLATCH    (0x200UL)    /*!< Latched value of low comparator digital filter output */

/**
  * @}
  */

/** @defgroup CMPSS_COMPSTSCLR CMPSS Status Clear Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS status clear register definition.    
  */
#define CMPSS_COMPSTSCLR_HLATCHCLR     (0x2UL)      /*!< High comparator latch software clear */
#define CMPSS_COMPSTSCLR_HSYNCCLREN    (0x4UL)      /*!< High comparator latch EPWMSYNCPER clear */
#define CMPSS_COMPSTSCLR_LLATCHCLR     (0x200UL)    /*!< Low comparator latch software clear */
#define CMPSS_COMPSTSCLR_LSYNCCLREN    (0x400UL)    /*!< Low comparator latch EPWMSYNCPER clear */

/**
  * @}
  */

/** @defgroup CMPSS_COMPDACHCTL CMPSS High DAC Control Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS high DAC control register definition.   
  */ 
#define CMPSS_COMPDACHCTL_DACSOURCE          (0x1UL)        /*!< DAC source select */
#define CMPSS_COMPDACHCTL_SWLOADSEL          (0x80UL)       /*!< Software load select */
#define CMPSS_COMPDACHCTL_BLANKEN            (0x1000UL)     /*!< EPWMBLANK enable */
#define CMPSS_COMPDACHCTL_RAMPHLOADSEL       (0x2000UL)     /*!< Ramp load select */
#define CMPSS_COMPDACHCTL_RAMPHDIR           (0x10000UL)    /*!< High ramp direction control */

/**
  * @}
  */

/** @defgroup CMPSS_COMPDACHCTL2 CMPSS High DAC Control2 Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS high DAC control2 register definition.   
  */ 
#define CMPSS_COMPDACHCTL2_DEENABLE          (0x1UL)       /*!< DE enable */
#define CMPSS_COMPDACHCTL2_BLANKSOURCESEL    (0x100UL)     /*!< Blank source select */
#define CMPSS_COMPDACHCTL2_RAMPSOURCESEL     (0x400UL)     /*!< Ramp source select */

/**
  * @}
  */

/** @defgroup CMPSS_DACHVALS CMPSS High DAC Value Shadow Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS DAC value shadow register definition.
  */ 
#define CMPSS_DACHVALS_DACVALS_S    (0UL)       /*!< High DAC shadow value */
#define CMPSS_DACHVALS_DACVALS_M    (0xFFUL)    /*!< DACVALS Mask */

/**
  * @}
  */

/** @defgroup CMPSS_DACHVALA CMPSS High DAC Value Active Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS DAC value active register definition.
  */ 
#define CMPSS_DACHVALA_DACVALA_S    (0UL)       /*!< High DAC active value */
#define CMPSS_DACHVALA_DACVALA_M    (0xFFUL)    /*!< DACVALA Mask */

/**
  * @}
  */

/** @defgroup CMPSS_CTRIPLFILCTL CMPSS CTRIPL Filter Control Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS ctripl filter control register definition.  
  */
#define CMPSS_CTRIPLFILCTL_FILINIT        (0x8000UL)    /*!< Low filter initialization */

/**
  * @}
  */

/** @defgroup CMPSS_CTRIPHFILCTL CMPSS CTRIPH Filter Control Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS ctriph filter control register definition.   
  */
#define CMPSS_CTRIPHFILCTL_FILINIT        (0x8000UL)    /*!< High filter initialization */

/**
  * @}
  */

/** @defgroup CMPSS_COMPLOCK CMPSS Lock Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS lock register definition.   
  */ 
#define CMPSS_COMPLOCK_COMPCTL       (0x1UL)           /*!< Lock write-access to the COMPCTL register */
#define CMPSS_COMPLOCK_COMPHYSCTL    (0x2UL)           /*!< Lock write-access to the COMPHYSCTL register */
#define CMPSS_COMPLOCK_DACCTL        (0x4UL)           /*!< Lock write-access to the COMPDACCTL register */
#define CMPSS_COMPLOCK_CTRIP         (0x8UL)           /*!< Lock write-access to the CTRIPxFILTCTL and CTRIPxFILCLKCTL registers */
#define CMPSS_COMPLOCK_KEY           (0xA5A50000UL)    /*!< Write permissions key */

/**
  * @}
  */

/** @defgroup CMPSS_DACLVALS2 CMPSS Low DAC Value Shadow2 Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS low DAC value shadow2 register definition.
  */ 
#define CMPSS_DACLVALS2_DACVALS2_S    (0UL)       /*!< Low DAC shadow2 value */
#define CMPSS_DACLVALS2_DACVALS2_M    (0xFFUL)    /*!< DACLVALS2 Mask */

/**
  * @}
  */

/** @defgroup CMPSS_COMPDACLCTL CMPSS Low DAC Control Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS low DAC control register definition.   
  */ 
#define CMPSS_COMPDACLCTL_DACSOURCE        (0x1UL)        /*!< DAC source select */
#define CMPSS_COMPDACLCTL_BLANKEN          (0x1000UL)     /*!< EPWMBLANK enable */
#define CMPSS_COMPDACLCTL_RAMPLLOADSEL     (0x2000UL)     /*!< Ramp load select */
#define CMPSS_COMPDACLCTL_RAMPLDIR         (0x10000UL)    /*!< High ramp direction control */

/**
  * @}
  */

/** @defgroup CMPSS_COMPDACLCTL2 CMPSS Low DAC Control2 Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS low DAC control2 register definition.   
  */ 
#define CMPSS_COMPDACLCTL2_BLANKSOURCEUSEL    (0x100UL)    /*!< Blank source select */
#define CMPSS_COMPDACLCTL2_RAMPSOURCEUSEL     (0x400UL)    /*!< Ramp source select */

/**
  * @}
  */

/** @defgroup CMPSS_COMPDACTEST CMPSS DAC Test Register
  * @{
  * @brief  Macro definitions about the bit fields in the CMPSS DAC test register definition.   
  */
#define CMPSS_COMPDACTEST_DAC_TEST_S               (6UL)             /*!< Analog debug signal */
#define CMPSS_COMPDACTEST_DAC_TEST_M               (0xC0UL)          /*!< DAC_TEST Mask */
#define CMPSS_COMPDACTEST_KEY                      (0xA5A50000UL)    /*!< Write permissions key */
#define CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_ENABLE     (0x80UL)          /*!< DAC test high comp negative output enable */
#define CMPSS_COMP_HIGH_NEGATIVE_OUTPUT_DISABLE    (0UL)             /*!< DAC test high comp negative output disable */
#define CMPSS_COMP_LOW_NEGATIVE_OUTPUT_ENABLE      (0x40UL)          /*!< DAC test low comp negative output enable */
#define CMPSS_COMP_LOW_NEGATIVE_OUTPUT_DISABLE     (0UL)             /*!< DAC test low comp negative output disable */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_CMPSS_H__ */
