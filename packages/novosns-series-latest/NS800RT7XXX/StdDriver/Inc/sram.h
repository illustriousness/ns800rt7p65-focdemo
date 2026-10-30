/**
  * @file       sram.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx sram module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SRAM_H__
#define __SRAM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SRAM_EXPORTED_TYPES SRAM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'SRAM' module.
  */

/** @defgroup SRAM_LOCK_TSTCR SRAM KEY TSTCR
  * @{
  * @brief  Macro definitions about sram key and tstcr enable.
  */
#define SRAM_UNLOCK_KEY               ((uint32_t)0x695a0001UL)    /*!< SRAM UNLOCK KEY */
#define SRAM_LOCK_KEY                 ((uint32_t)0x695a0000UL)    /*!< SRAM LOCK KEY */
#define SRAM_TSTCR_BYPASS_EANBLE      ((uint32_t)0x66990001UL)    /*!< Enable SRAM ECCBYPASS */
#define SRAM_TSTCR_BYPASS_DISANBLE    ((uint32_t)0x66990000UL)    /*!< Disable SRAM ECCBYPASS */

/**
  * @}
  */

/** @defgroup ECC_MEMNUM ECC Enable Bit Config
  * @{
  * @brief  Macro definitions about SRAM Bank Ecc Enable ctrl.
  */
typedef enum {
    ECC_SRAM1_MEM = 0x0U,    /*!< select sram1 memory */ 
    ECC_SRAM2_MEM,           /*!< select sram2 memory */
    ECC_CORE1_ITCM_MEM,      /*!< select itcm memory */
    ECC_CORE1_DTCM_MEM,      /*!< select dtcm memory */
    ECC_CORE2_ITCM_MEM,      /*!< select itcm memory */
    ECC_CORE2_DTCM_MEM       /*!< select dtcm memory */
} ECC_MemNum;

/**
  * @}
  */

/** @defgroup PIPE_MEMNUM PIPE Enable Bit Config
  * @{
  * @brief  Macro definitions about SRAM Bank Pipe Enable ctrl.
  */
typedef enum {
          /*!< select sram2 memory */
    PIPE_CORE1_ITCM_MEM = 0x0U,      /*!< select itcm memory */
    PIPE_CORE1_DTCM_MEM,             /*!< select dtcm memory */
    PIPE_CORE2_ITCM_MEM,             /*!< select itcm memory */
    PIPE_CORE2_DTCM_MEM,             /*!< select dtcm memory */
    PIPE_SRAM1_MEM ,                 /*!< select sram1 memory */ 
    PIPE_SRAM2_MEM
} PIPE_MemNum;

/**
  * @}
  */

/** @defgroup RWAIT_MEMNUM RWAIT Enable Bit Config
  * @{
  * @brief  Macro definitions about SRAM Bank Rwait Enable ctrl.
  */
typedef enum {
          /*!< select sram2 memory */
    RWAIT_CORE1_ITCM_MEM = 0x0U,      /*!< select itcm memory */
    RWAIT_CORE1_DTCM_MEM,             /*!< select dtcm memory */
    RWAIT_CORE2_ITCM_MEM,             /*!< select itcm memory */
    RWAIT_CORE2_DTCM_MEM              /*!< select dtcm memory */
} Rwait_MemNum;

/**
  * @}
  */

/** @defgroup SRAM_STNUM SRAM Status 
  * @{
  * @brief  Macro definitions about SRAM status num.
  */
typedef enum {
    SRAM_SRAM1ST1 = 0x0U,     /*!< sram sram1 status */ 
    SRAM_SRAM1ST2,
    SRAM_SRAM2ST1,           /*!< sram sram2 status1 */
    SRAM_SRAM2ST2,           /*!< sram sram2 status2 */
    SRAM_CORE1_ITCMST1,            /*!< sram itcm status1 */
    SRAM_CORE1_ITCMST2,            /*!< sram dtcm status2 */
    SRAM_CORE1_D0TCMST1,            /*!< sram dtcm status1 */
    SRAM_CORE1_D0TCMST2,            /*!< sram dtcm status2 */
    SRAM_CORE1_D1TCMST1,            /*!< sram dtcm status1 */
    SRAM_CORE1_D1TCMST2,            /*!< sram dtcm status2 */
    SRAM_CORE2_ITCMST1,            /*!< sram itcm status1 */
    SRAM_CORE2_ITCMST2,            /*!< sram dtcm status2 */
    SRAM_CORE2_D0TCMST1,            /*!< sram dtcm status1 */
    SRAM_CORE2_D0TCMST2,            /*!< sram dtcm status2 */
    SRAM_CORE2_D1TCMST1,            /*!< sram dtcm status1 */
    SRAM_CORE2_D1TCMST2,            /*!< sram dtcm status2 */
    BACKSRAMST
} SRAM_StNum;

/**
  * @}
  */

/** @defgroup SRAM_CHK typedef SRAM check error 
  * @{
  * @brief    Macro definitions about SRAM check operation error num
  */
typedef enum {
    ECC1_SRAM1_OAD = 0x0U,    /*!< select sram1 memory */
    ECC2_SRAM1_OAD ,          /*!< select sram1 memory */
    ECC1_SRAM2_OAD,           /*!< select sram2 memory */
    ECC2_SRAM2_OAD,           /*!< select sram2 memory */
    ECC1_CORE1_ITCM_OAD,      /*!< select core1 itcm memory */
    ECC2_CORE1_ITCM_OAD,      /*!< select core1 itcm memory */
    ECC1_CORE1_D0TCM_OAD,     /*!< select core1 d0tcm memory */
    ECC2_CORE1_D0TCM_OAD,     /*!< select core1 d0tcm memory */
    ECC1_CORE1_D1TCM_OAD,     /*!< select core1 d2tcm memory */
    ECC2_CORE1_D1TCM_OAD,     /*!< select core1 d2tcm memory */
    ECC1_CORE2_ITCM_OAD,      /*!< select core2 itcm  memory */
    ECC2_CORE2_ITCM_OAD,      /*!< select core2 itcm  memory */
    ECC1_CORE2_D0TCM_OAD,     /*!< select core2 d0tcm memory */
    ECC2_CORE2_D0TCM_OAD,     /*!< select core2 d0tcm memory */
    ECC1_CORE2_D1TCM_OAD,      /*!< select core2 d2tcm memory */
    ECC2_CORE2_D1TCM_OAD,      /*!< select core2 d2tcm memory */
    BACKSRAM_OAD
} SRAM_Chk;

/**
  * @}
  */

/** @defgroup SRAM_ERROP SRAM error of operation
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    ECC1_NOACK = 0x0U,       /*!< error operation interrupt */ 
    ECC1_INT = 0x01U,        /*!< SRAM error operation nmi */ 
    ECC2_INT = 0x0U,         /*!< SRAM2 error operation interrupt */ 
    ECC2_NMI = 0x01U,        /*!< ITCM error operation interrupt */
    BACKSRAM_INT = 0x0U,     /*!< ITCM error operation interrupt */ 
    BACKSRAM_NMI = 0x1U      /*!< ITCM error operation interrupt */
} SRAM_ErrOp;

/**
  * @}
  */


/** @defgroup SRAM_ECCERR_ADR SRAM error of operation
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    SRAM1_ECCERR_ADDR = 0x0U,    /*!< select sram1 memory */
    SRAM2_ECCERR_ADDR ,          /*!< select sram1 memory */
    CORE1_ITCM_ECCERR_ADDR,      /*!< select core1 itcm memory */
    CORE1_D0TCM_ECCERR_ADDR,     /*!< select core1 d0tcm memory */
    CORE1_D1TCM_ECCERR_ADDR,     /*!< select core1 d1tcm memory */
    CORE2_ITCM_ECCERR_ADDR,      /*!< select core2 itcm memory */
    CORE2_D0TCM_ECCERR_ADDR,     /*!< select core2 d0tcm memory */
    CORE2_D1TCM_ECCERR_ADDR,     /*!< select core2 d1tcm memory */
} SRAM_EccErr_Adr;

/**
  * @}
  */

/** @defgroup SRAM_EICTRL SRAM ECC error injection control register
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    SRAM1_EI_EN = 0x0U,    /*!< select sram1 memory */
    SRAM2_EI_EN ,          /*!< select sram1 memory */
    CORE1_ITCM_EI_EN,      /*!< select core1 itcm memory */
    CORE1_D0TCM_EI_EN,     /*!< select core1 d0tcm memory */
    CORE1_D1TCM_EI_EN,     /*!< select core1 d1tcm memory */
    CORE2_ITCM_EI_EN,      /*!< select core2 itcm memory */
    CORE2_D0TCM_EI_EN,     /*!< select core2 d0tcm memory */
    CORE2_D1TCM_EI_EN,     /*!< select core2 d1tcm memory */
} SRAM_EiCtrl;

/**
  * @}
  */

  /** @defgroup SRAM_ECCERRORINJMASK SRAM ECC error injection data MASK
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    SRAM_EI_DM_LOW = 0x0U,  /*!< select sram low memory */
    SRAM_EI_DM_HIGH ,       /*!< select sram1 high memory */
    SRAM_EI_CHK,            /*!< select sram chk memory */
    ITCM_EI_DM_LOW,         /*!< select itcm low memory */
    ITCM_EI_DM_HIGH,        /*!< select itcm high memory */
    ITCM_EI_CHK,            /*!< select itcm chk memory */
    D0TCM_EI_DM,            /*!< select d0tcm  memory */
    D0TCM_EI_CHK,           /*!< select d0tcm chk memory */
    D1TCM_EI_DM,            /*!< select d1tcm  memory */
    D1TCM_EI_CHK            /*!< select d1tcm chk memory */
} SRAM_EccErrorInjMask;
 
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
 * \brief  get sram related register status.
 * \param  sram    SRAM pointer to a SRAM_TypeDef structure
 *                  - SRAM: SRAM base address index
 * \return Returned the value of check registor
 *                  - bit0:    SRAM1ST 
 *                  - bit2:    SRAM2ST1 
 *                  - bit3:    SRAM2ST2 
 *                  - bit4:    DTCMST1 
 *                  - bit5:    DTCMST2 
 *                  - bit6:    ITCMST1 
 *                  - bit7:    ITCMST2 
 */
static inline uint32_t SRAM_getStatusReg (SRAM_TypeDef *sram)
{
    return (uint32_t)sram->CHKCR.WORDVAL;
}

/**
 * \brief  Enable SRAM Registon Backup Sram Parity ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 */
static inline void SRAM_enableRegionBackupParityCtrl (SRAM_TypeDef *sram)
{
    SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<22));
}

/**
 * @brief  Disable SRAM Registon  Backup Sram Parity ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 */
static inline void SRAM_disableRegionBackupParityCtrl (SRAM_TypeDef *sram)
{
    CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<22));
}

/**
 * \brief  Get SRAM ECC error address register
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  sramStNum    SRAM Reset Flag num of @ref SRAM_ECCERR_ADR 
 * \return Returned the error address
 */
 static inline uint32_t SRAM_getErrorAddress (SRAM_TypeDef *sram, SRAM_EccErr_Adr sramStNum)
 {
    uint32_t tmpreg;
    tmpreg = READ_REG(TYPE32(&sram->SRAM1_ECC_ERR_ADDR.WORDVAL) + sramStNum); 
    return tmpreg;
 }


 /**
 * \brief  SRAM ECC error injection control register Enable
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  SRAM_EiCtrl    SRAM Reset Flag num of @ref SRAM_EICTRL 
 * \return Returned the error address
 */
 static inline void SRAM_enableEccInjectionCtrl (SRAM_TypeDef *sram, SRAM_EiCtrl sramStNum)
 {

     SET_BIT(sram->EI_CTRL.WORDVAL,0x1UL << sramStNum); 

 }

 /**
 * \brief  SRAM ECC error injection control register Disable
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  SRAM_EiCtrl    SRAM Reset Flag num of @ref SRAM_EICTRL 
 * \return Returned the error address
 */
 static inline void SRAM_DisableEccInjectionCtrl (SRAM_TypeDef *sram, SRAM_EiCtrl sramStNum)
 {

     CLEAR_BIT(sram->EI_CTRL.WORDVAL,0x1UL << sramStNum); 
 }

/**
 * \brief  SRAM ECC error injection data MASK
 * \param  sram               SRAM pointer to a SRAM_TypeDef structure
 *                             - SRAM: SRAM base address index
 * \param  sramStNum          SRAM Reset Flag num of @ref SRAM_ECCERRORINJMASK 
 * \param  EccCheckDataInv    The corresponding bit of ECC check data is inverted.
 * \return Returned the error address
 */
 static inline void SRAM_SetInvEccCheckData (SRAM_TypeDef *sram, SRAM_EccErrorInjMask sramStNum ,uint32_t EccCheckDataInv)
 {
    uint32_t addr;
    addr = (TYPE32(&sram->EI_DM_LOW.WORDVAL) + sramStNum);
    if(sramStNum == SRAM_EI_CHK || sramStNum == ITCM_EI_CHK ||sramStNum == D0TCM_EI_CHK ||sramStNum == D1TCM_EI_CHK)
    {
        MODIFY_REG(addr,0xF,EccCheckDataInv);
    }
    else
    {
        MODIFY_REG(addr,0xFFFF,EccCheckDataInv);
    }
 }

/**
 * \brief  Configure the SRAM Read/Write wait cycle
 * \param  sram        SRAM pointer to a SRAM_TypeDef structure
 *                      - SRAM: SRAM base address index
 * \param  sram2Rwt    SRAM Read wait cycle
 *                      - 0: 0 wait cycle
 *                      - 1: 1 wait cycle
 * \param  sram2Wwt    SRAM write wait cycle
 *                      - 0: 0 wait cycle
 *                      - 1: 1 wait cycle
 */
extern void SRAM_configWtCr (SRAM_TypeDef *sram, uint32_t sram2Rwt, uint32_t sram2Wwt);

/**
 * \brief  Configure the SRAM Ecc check enable.
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  chk          SRAM CHKT Typedef
 *                       This parameter can be any value of @ref SRAM_CHK
 * \param  operation    SRAM ERROROPERATION Typedef
 *                       This parameter can be any value of @ref SRAM_ERROP
 */
extern void SRAM_configChkCr (SRAM_TypeDef *sram, SRAM_Chk chk, SRAM_ErrOp operation);

/**
 * \brief  Enable SRAM Registon Ecc ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 * \param  memSel     memroy select 
 *                     This parameter can be any value of @ref ECC_MEMNUM
 * 
 */
extern void SRAM_enableRegionEccCtrl (SRAM_TypeDef *sram, ECC_MemNum memSel);

/**
 * @brief  Disable SRAM Registon Ecc ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref ECC_MEMNUM
 */
extern void SRAM_disableRegionEccCtrl (SRAM_TypeDef *sram, ECC_MemNum memSel);

/**
 * \brief  Enable SRAM Registon Pipe ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 * \param  memSel     memroy select 
 *                     This parameter can be any value of @ref PIPE_MEMNUM
 * 
 */
extern void SRAM_enableRegionPipeCtrl (SRAM_TypeDef *sram, PIPE_MemNum memSel);

/**
 * @brief  Disable SRAM Registon Pipe ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref PIPE_MEMNUM
 */
extern void SRAM_disableRegionPipeCtrl (SRAM_TypeDef *sram, PIPE_MemNum memSel);

/**
 * \brief  Enable SRAM Registon Rwait ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 * \param  memSel     memroy select 
 *                     This parameter can be any value of @ref RWAIT_MEMNUM
 * 
 */
extern void SRAM_enableRegionRwaitCtrl (SRAM_TypeDef *sram, Rwait_MemNum memSel);

/**
 * @brief  Disable SRAM Registon Rwait ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref RWAIT_MEMNUM
 */
extern void SRAM_disableRegionRwaitCtrl (SRAM_TypeDef *sram, Rwait_MemNum memSel);

/**
 * \brief  Get SRAM Status from SRAM_CHKSR register.
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  sramStNum    SRAM Reset Flag num of @ref SRAM_STNUM 
 * \return Returned the status of check registor
 *                       - 1: error 
 *                       - 0: no error 
 */
extern uint32_t SRAM_getStatusFlag (SRAM_TypeDef *sram, SRAM_StNum sramStNum);


/**
 * \brief  Clear Status Register.
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  sramStNum    SRAM Reset Flag num of @ref SRAM_STNUM
 */
extern void SRAM_clearStatusFlag (SRAM_TypeDef *sram, SRAM_StNum sramStNum);


#ifdef __cplusplus
}
#endif


#endif
