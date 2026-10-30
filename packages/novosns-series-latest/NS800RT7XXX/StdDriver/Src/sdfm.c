/**
  * @file       sdfm.c
  * @author     bilang.xiong
  * @brief      Function file for NS800RT7xxx sdfm module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "sdfm.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SDFM_PRIVATE_TYPES SDFM PRIVATED Types
  * @{
  * @brief  Macro definitions are used with all files private about 'SDFM' module.
  */

/** @defgroup SDFM_FILTER_THRESHOLD_TYPES SDFM Fliter and Threshold
  * @{
  * @brief  Macro definitions are used with all files about Fliter and Threshold.
  */
#define SDFM_GET_OSR(C)                ((C) >> 8UL)
#define SDFM_MAX_COMP_FILTER_OSR       (31UL)
#define SDFM_MAX_DATA_FILTER_OSR       (255UL)
#define SDFM_GET_FILTER_TYPE(C)        ((C) & 0x30UL)
#define SDFM_GET_FILTER_NUMBER(C)      ((C) & 0x3UL)
#define SDFM_GET_ZHIGH_THRESHOLD(C)    ((C) & 0x7FFFUL)
#define SDFM_ZHIGH_ENABLE_MASK         (0x8000UL)
#define SDFM_GET_SHIFT_VALUE(C)        (((C) >> 2UL) & 0x1FUL)

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
 * @brief  SDFM config comparator.
 * @param  sdfm       sdfm pointer to a SDFM_TypeDef structure
 *                     - SDFM1: SDFM1 base address index
 *                     - SDFM2: SDFM2 base address index
 *                     - SDFM3: SDFM3 base address index
 *                     - SDFM4: SDFM4 base address index
 * @param  config1    sdfm config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x1FUL
 * @param  config2    sdfm config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x7FFUL
 * @param  config3    sdfm config3
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x7FFUL
 */
void SDFM_configComparator (SDFM_TypeDef *sdfm, uint16_t config1, uint32_t config2, uint16_t config3)
{
    SDFM_FilterNumber filter;
    uint16_t ratio;
    SDFM_Filter filterType;

    filter = (SDFM_FilterNumber)(SDFM_GET_FILTER_NUMBER(config1));
    ratio = SDFM_GET_OSR(config1);
    filterType = (SDFM_Filter)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_COMP_FILTER_OSR)
    {
        ratio = SDFM_MAX_COMP_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setComparatorFilterType(sdfm, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setCompFilterOverSamplingRatio(sdfm, filter, ratio);

    /* Set the comparator high threshold value */
    SDFM_setCompFilterHighThreshold(sdfm, filter, SDFM_GET_HIGH_THRESHOLD(config2));

    /* Set the comparator low threshold value */
    SDFM_setCompFilterLowThreshold(sdfm, filter, SDFM_GET_LOW_THRESHOLD(config2));

    /* If requested, enable and set the zero-cross high threshold value */
    if ((config3 & SDFM_ZHIGH_ENABLE_MASK) != 0UL)
    {
        SDFM_setCompFilterZeroCrossThreshold(sdfm, filter, SDFM_GET_ZHIGH_THRESHOLD(config3));
        SDFM_enableZeroCrossEdgeDetect(sdfm, filter);
    }
}

/**
 * @brief  SDFM config enhanced comparator.
 * @param  sdfm                  sdfm pointer to a SDFM_TypeDef structure
 *                                - SDFM1: SDFM1 base address index
 *                                - SDFM2: SDFM2 base address index
 *                                - SDFM3: SDFM3 base address index
 *                                - SDFM4: SDFM4 base address index
 * @param  filterConfig          filter config 
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x1FUL
 * @param  highLowThreshold1     high low threshold1
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x7FFUL
 * @param  highLowThreshold2     high low thredshold2
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x7FFUL
 * @param  zeroCrossThreshold    zero cross threshold
 *                                this parameter is an unsigned integer that is greater 
 *                                than or equal to 0x0UL and less than or equal to 0x7FFUL
 */
void SDFM_configEnhancedComparator (SDFM_TypeDef *sdfm,
                                    uint16_t filterConfig,
                                    uint32_t highLowThreshold1,
                                    uint32_t highLowThreshold2,
                                    uint16_t zeroCrossThreshold)
{
    SDFM_FilterNumber filter;
    uint16_t ratio;
    SDFM_Filter filterType;

    filter = (SDFM_FilterNumber)(SDFM_GET_FILTER_NUMBER(filterConfig));
    ratio = SDFM_GET_OSR(filterConfig);
    filterType = (SDFM_Filter)SDFM_GET_FILTER_TYPE(filterConfig);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_COMP_FILTER_OSR)
    {
        ratio = SDFM_MAX_COMP_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setComparatorFilterType(sdfm, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setCompFilterOverSamplingRatio(sdfm, filter, ratio);

    /* Set the comparator high threshold value */
    SDFM_setCompFilterHighThreshold(sdfm, filter, SDFM_GET_HIGH_THRESHOLD_BOTH(highLowThreshold1, highLowThreshold2));

    /* Set the comparator low threshold value */
    SDFM_setCompFilterLowThreshold(sdfm, filter, SDFM_GET_LOW_THRESHOLD_BOTH(highLowThreshold1, highLowThreshold2));

    /* If requested, enable and set the zero-cross high threshold value */
    if ((zeroCrossThreshold & SDFM_ZHIGH_ENABLE_MASK) != 0UL)
    {
        SDFM_setCompFilterZeroCrossThreshold(sdfm, filter, SDFM_GET_ZHIGH_THRESHOLD(zeroCrossThreshold));
        SDFM_enableZeroCrossEdgeDetect(sdfm, filter);
    }
}

/**
 * @brief  SDFM config data filter.
 * @param  sdfm       sdfm pointer to a SDFM_TypeDef structure
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
void SDFM_configDataFilter (SDFM_TypeDef *sdfm, uint16_t config1, uint16_t config2)
{
    SDFM_FilterNumber filter;
    uint16_t ratio;
    SDFM_Filter filterType;

    filter = (SDFM_FilterNumber)(SDFM_GET_FILTER_NUMBER(config1));
    ratio = SDFM_GET_OSR(config1);
    filterType = (SDFM_Filter)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_DATA_FILTER_OSR)
    {
        ratio = SDFM_MAX_DATA_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setFilterType(sdfm, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setFilterOverSamplingRatio(sdfm, filter, ratio);

    /* If filter switch on */
    if ((config2 & SDFM_FILTER_ENABLE) == SDFM_FILTER_ENABLE)
    {
        SDFM_enableFilter(sdfm, filter);
    }
    else
    {
        SDFM_disableFilter(sdfm, filter);
    }

    /* Set output data format */
    SDFM_setOutputDataFormat(sdfm, filter, (SDFM_OutputDataFormat)(config2 & 0x1UL));

    /* Set the shift value if data is in 16-bit 2's complement format */
    if ((config2 & 0x1U) == (uint16_t)(SDFM_DATA_FORMAT_16_BIT))
    {
        SDFM_setDataShiftValue(sdfm, filter, SDFM_GET_SHIFT_VALUE(config2));
    }
}

/**
 * @brief  SDFM config zero cross comparator
 * @param  sdfm       sdfm pointer to a SDFM_TypeDef structure
 *                     - SDFM1: SDFM1 base address index
 *                     - SDFM2: SDFM2 base address index
 *                     - SDFM3: SDFM3 base address index
 *                     - SDFM4: SDFM4 base address index
 * @param  config1    zero cross comparator config1
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0xFFUL
 * @param  config2    zero cross comparator config2
 *                     this parameter is an unsigned integer that is greater 
 *                     than or equal to 0x0UL and less than or equal to 0x7FFFUL
 */
void SDFM_configZeroCrossComparator (SDFM_TypeDef *sdfm, uint16_t config1, uint16_t config2)
{
    SDFM_FilterNumber filter;
    uint16_t ratio;
    SDFM_Filter filterType;

    filter = (SDFM_FilterNumber)(SDFM_GET_FILTER_NUMBER(config1));
    ratio = SDFM_GET_OSR(config1);
    filterType = (SDFM_Filter)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_COMP_FILTER_OSR)
    {
        ratio = SDFM_MAX_COMP_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setComparatorFilterType(sdfm, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setCompFilterOverSamplingRatio(sdfm, filter, ratio);

    /* Set the zero cross threshold value */
    SDFM_setCompFilterZeroCrossThreshold(sdfm, filter, config2);
}

/**
 * @brief  SDFM config data filter fifo
 * @param  sdfm       sdfm pointer to a SDFM_TypeDef structure
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
void SDFM_configDataFilterFIFO (SDFM_TypeDef *sdfm, uint16_t config1, uint16_t config2)
{
    SDFM_FilterNumber filter;
    uint16_t ratio;
    uint16_t fifoLevel;
    SDFM_Filter filterType;

    filter = (SDFM_FilterNumber)(SDFM_GET_FILTER_NUMBER(config1));
    fifoLevel = ((config2 >> 7UL) & 0x1FUL);
    ratio = SDFM_GET_OSR(config1);
    filterType = (SDFM_Filter)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_DATA_FILTER_OSR)
    {
        ratio = SDFM_MAX_DATA_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setFilterType(sdfm, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setFilterOverSamplingRatio(sdfm, filter, ratio);

    /* If filter switch on */
    if ((config2 & SDFM_FILTER_ENABLE) == SDFM_FILTER_ENABLE)
    {
        SDFM_enableFilter(sdfm, filter);
    }
    else
    {
        SDFM_disableFilter(sdfm, filter);
    }

    /* Set output data format */
    SDFM_setOutputDataFormat(sdfm, filter, (SDFM_OutputDataFormat)(config2 & 0x1U));

    /* Set the shift value if data is in 16bit 2's complement format */
    if ((config2 & 0x1U) == (uint16_t)(SDFM_DATA_FORMAT_16_BIT))
    {
        SDFM_setDataShiftValue(sdfm, filter, SDFM_GET_SHIFT_VALUE(config2));
    }

    /* Set the FIFO level */
    SDFM_setFIFOInterruptLevel(sdfm, filter, fifoLevel);
    SDFM_enableFIFOBuffer(sdfm, filter);
}

/**
 * @brief  SDFM config comparator event low filter
 * @param  sdfm            sdfm pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * @param  filterNumber    filter number config
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * @param  config          the struct of sdfm comp event filter config
 */
void SDFM_configCompEventLowFilter (SDFM_TypeDef *sdfm, SDFM_FilterNumber filterNumber,
                                    const SDFM_CompEventFilterConfig *config)
{
    /* Configure sample window & threshold */
    MODIFY_REG(TYPE32(&(sdfm->SDCOMP1EVT2FLTCTL) + (filterNumber * 6UL)), SDFM_COMPEVT_FILTER_CONFIG_M,
               ((config->sampleWindow - 1U) << SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_S) |
               (config->threshold << SDFM_SDCOMP1EVT2FLTCTL_THRESH_S));

    /* Configure clock pre-scale.*/
    MODIFY_REG(TYPE32(&(sdfm->SDCOMP1EVT2FLTCLKCTL) + (filterNumber * 6UL)),
               SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_M,
               config->clkPrescale);
}

/**
 * @brief  SDFM config comparator event high filter
 * @param  sdfm            sdfm pointer to a SDFM_TypeDef structure
 *                          - SDFM1: SDFM1 base address index
 *                          - SDFM2: SDFM2 base address index
 *                          - SDFM3: SDFM3 base address index
 *                          - SDFM4: SDFM4 base address index
 * @param  filterNumber    filter number config 
 *                          This parameter can be any value of @ref SDFM_FILTERNUMBER
 * @param  config          the struct of sdfm comp event filter config
 */
void SDFM_configCompEventHighFilter (SDFM_TypeDef *sdfm,
                                     SDFM_FilterNumber filterNumber,
                                     const SDFM_CompEventFilterConfig *config)
{
    /* Configure sample window & threshold.*/
    MODIFY_REG(TYPE32(&(sdfm->SDCOMP1EVT1FLTCTL) + (filterNumber * 6UL)), SDFM_COMPEVT_FILTER_CONFIG_M,
              ((config->sampleWindow - 1U) << SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_S) |
              (config->threshold << SDFM_SDCOMP1EVT1FLTCTL_THRESH_S));

    /* Configure clock pre-scale.*/
    MODIFY_REG(TYPE32(&(sdfm->SDCOMP1EVT1FLTCLKCTL) + (filterNumber * 6UL)),
               SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_M,
               config->clkPrescale);
}
