/**
  * @file       flash.c
  * @author     xiacj
  * @brief      Function file for NS800RT7xxx flash module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "flash.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief  Erase all Flash pages in Bank1
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note   User should disable icache and dcache.
 * @note   User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseAllPageInBank1 (void)
{
    FLASH_unlockRegs1();
    FLASH_clearOperationCompleteFlag1();

    uint32_t Bak = READ_REG(FLASH->CR1.WORDVAL);
    Bak &= ~FLASH_OP_MASK;
    WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_MER);
    WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_MER | FLASH_CR1_START_M);
    __DSB();
    while (FLASH_isBusy1()){;}
    WRITE_REG(FLASH->CR1.WORDVAL, Bak);

    FLASH_lockRegs1();

    return !!FLASH_getOperationCompleteFlag1();
}

/**
 * @brief  Erase all Flash pages in Bank2
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note   User should disable icache and dcache.
 * @note   User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseAllPageInBank2 (void)
{
    FLASH_unlockRegs2();
    FLASH_clearOperationCompleteFlag2();

    uint32_t Bak = READ_REG(FLASH->CR2.WORDVAL);
    Bak &= ~FLASH_OP_MASK;
    WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_MER);
    WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_MER | FLASH_CR2_START_M);
    __DSB();
    while (FLASH_isBusy2()){;}
    WRITE_REG(FLASH->CR2.WORDVAL, Bak);

    FLASH_lockRegs2();

    return !!FLASH_getOperationCompleteFlag2();
}

/**
 * @brief  Erase One Flash Page in area1
 * @param  addr  addr of flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseOnePageInArea1 (uint32_t addr)
{
    FLASH_unlockRegs1();
    FLASH_clearOperationCompleteFlag1();

    uint32_t Bak = READ_REG(FLASH->CR1.WORDVAL);
    Bak &= ~FLASH_OP_MASK;
    WRITE_REG(FLASH->AR1.WORDVAL, addr);
    WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_PER);
    WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_PER | FLASH_CR1_START_M);
    __DSB();
    while (FLASH_isBusy1()){;}
    WRITE_REG(FLASH->CR1.WORDVAL, Bak);

    FLASH_lockRegs1();

    return !!FLASH_getOperationCompleteFlag1();
}

/**
 * @brief  Erase One Flash Page in area2
 * @param  addr  addr of flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseOnePageInArea2 (uint32_t addr)
{
    FLASH_unlockRegs2();
    FLASH_clearOperationCompleteFlag2();

    uint32_t Bak = READ_REG(FLASH->CR2.WORDVAL);
    Bak &= ~FLASH_OP_MASK;
    WRITE_REG(FLASH->AR2.WORDVAL, addr);
    WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_PER);
    WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_PER | FLASH_CR2_START_M);
    __DSB();
    while (FLASH_isBusy2()){;}
    WRITE_REG(FLASH->CR2.WORDVAL, Bak);

    FLASH_lockRegs2();

    return !!FLASH_getOperationCompleteFlag2();
}

/**
 * @brief  Erase One Flash Page in Bank1
 * @param  addr  addr of flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseOnePageInBank1 (uint32_t addr)
{
    if ((addr >= FLASH_BANK1_STARTADDR) && (addr <= FLASH_BANK1_ENDADDR))
    {
       return FLASH_eraseOnePageInArea1(addr);
    }

    return 0;
}

/**
 * @brief  Erase One Flash Page in Bank2
 * @param  addr  addr of flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseOnePageInBank2 (uint32_t addr)
{
    if ((addr >= FLASH_BANK2_STARTADDR) && (addr <= FLASH_BANK2_ENDADDR))
    {
         return FLASH_eraseOnePageInArea2(addr);
    }

    return 0;
}

/**
 * @brief  Erase one Data Flash Page
 * @param  addr  addr of data flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseOneDataPage (uint32_t addr)
{
    if ((addr >= FLASH_DATAFLASH_STARTADDR) && (addr <= FLASH_DATAFLASH_ENDADDR))
    {
        if (FLASH_isSwaped() == 0)
        {
            return FLASH_eraseOnePageInArea1(addr);
        }
        else
        {
            return FLASH_eraseOnePageInArea2(addr);
        }
    }

    return 0;
}

/**
 * @brief  Check Flash or DataFlash is blank or not
 * @param  addr     Addr of memery need to be check
 * @param  byteCnt  The quantity of data to be checked
 * @return Returns blank status
 *          - bool: 0: not blank
 *                  1: blank
 */
uint8_t FLASH_isBlank (uint32_t addr, uint32_t byteCnt)
{
    for (uint32_t i = 0; i < byteCnt; i++)
    {
        if ((*((__IO uint8_t *)(addr + i))) != 0xFF)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief  Erase one Option Flash Page
 * @param  addr  addr of data flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_eraseOneOptionPage (uint32_t addr)
{
    if ((addr >= FLASH_OPTIONBYTES1_STARTADDR) && (addr <= FLASH_OPTIONBYTES2_ENDADDR))
    {
        if (FLASH_isSwaped() == 0)
        {
            FLASH_unlockRegs1();
            FLASH_unlockOptionBytes();
            FLASH_clearOperationCompleteFlag1();

            uint32_t Bak = READ_REG(FLASH->CR1.WORDVAL);
            Bak &= ~FLASH_OP_MASK;
            WRITE_REG(FLASH->AR1.WORDVAL, addr);
            WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_OPTER);
            WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_OPTER | FLASH_CR1_START_M);
            __DSB();
            while (FLASH_isBusy1()){;}
            WRITE_REG(FLASH->CR1.WORDVAL, Bak);

            FLASH_lockOptionBytes1();
            FLASH_lockRegs1();

            return !!FLASH_getOperationCompleteFlag1();
        }
        else
        {
            FLASH_unlockRegs2();
            FLASH_unlockOptionBytes();
            FLASH_clearOperationCompleteFlag2();

            uint32_t Bak = READ_REG(FLASH->CR2.WORDVAL);
            Bak &= ~FLASH_OP_MASK;
            WRITE_REG(FLASH->AR2.WORDVAL, addr);
            WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_OPTER);
            WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_OPTER | FLASH_CR2_START_M);
            __DSB();
            while (FLASH_isBusy2()){;}
            WRITE_REG(FLASH->CR2.WORDVAL, Bak);

            FLASH_lockOptionBytes2();
            FLASH_lockRegs2();

            return !!FLASH_getOperationCompleteFlag2();
        }
    }

    return 0;
}

/**
 * @brief  Write data to Area1
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytesToArea1 (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    uint8_t flag = 0;
    if (((byteCnt % 8) == 0) && ((addr % 8) == 0))
    {
        flag = 1;
        FLASH_unlockRegs1();
        uint32_t Bak = READ_REG(FLASH->CR1.WORDVAL);
        Bak &= ~FLASH_OP_MASK;
        WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_PG);
        __DSB();

        while (byteCnt && flag)
        {
            uint64_t tmp64 = (((uint64_t)pBuf[0]) << 0 ) | (((uint64_t)pBuf[1]) << 8 ) |\
                             (((uint64_t)pBuf[2]) << 16) | (((uint64_t)pBuf[3]) << 24) |\
                             (((uint64_t)pBuf[4]) << 32) | (((uint64_t)pBuf[5]) << 40) |\
                             (((uint64_t)pBuf[6]) << 48) | (((uint64_t)pBuf[7]) << 56);
            *((__IO uint64_t *)addr) = tmp64;
            __DSB();
            while (FLASH_isBusy1()){;}
            if ( *((__IO uint64_t *)addr) != tmp64 )
            {
                flag = 0;
            }
            byteCnt -= 8;
            addr += 8;
            pBuf += 8;
        }

        WRITE_REG(FLASH->CR1.WORDVAL, Bak);
        FLASH_lockRegs1();
    }

    return flag;
}

/**
 * @brief  Write data to Area2
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytesToArea2 (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    uint8_t flag = 0;
    if (((byteCnt % 8) == 0) && ((addr % 8) == 0))
    {
        flag = 1;
        FLASH_unlockRegs2();
        uint32_t Bak = READ_REG(FLASH->CR2.WORDVAL);
        Bak &= ~FLASH_OP_MASK;
        WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_PG);
        __DSB();

        while (byteCnt && flag)
        {
            uint64_t tmp64 = (((uint64_t)pBuf[0]) << 0 ) | (((uint64_t)pBuf[1]) << 8 ) |\
                             (((uint64_t)pBuf[2]) << 16) | (((uint64_t)pBuf[3]) << 24) |\
                             (((uint64_t)pBuf[4]) << 32) | (((uint64_t)pBuf[5]) << 40) |\
                             (((uint64_t)pBuf[6]) << 48) | (((uint64_t)pBuf[7]) << 56);
            *((__IO uint64_t *)addr) = tmp64;
            __DSB();
            while (FLASH_isBusy2()){;}
            if ( *((__IO uint64_t *)addr) != tmp64 )
            {
                flag = 0;
            }
            byteCnt -= 8;
            addr += 8;
            pBuf += 8;
        }

        WRITE_REG(FLASH->CR2.WORDVAL, Bak);
        FLASH_lockRegs2();
    }

    return flag;
}

/**
 * @brief  Write data to Main Flash Bank1
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytesToBank1 (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    if ((addr >= FLASH_BANK1_STARTADDR) && ((addr + byteCnt - 1) <= FLASH_BANK1_ENDADDR))
    {
        return FLASH_writeBytesToArea1(addr, pBuf, byteCnt);
    }

    return 0;
}

/**
 * @brief  Write data to Main Flash Bank2
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytesToBank2 (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    if ((addr >= FLASH_BANK2_STARTADDR) && ((addr + byteCnt - 1) <= FLASH_BANK2_ENDADDR))
    {
        return FLASH_writeBytesToArea2(addr, pBuf, byteCnt);
    }

    return 0;
}

/**
 * @brief  Write data to DataFlash
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytesToDataPage (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    if ((addr >= FLASH_DATAFLASH_STARTADDR) && (addr <= FLASH_DATAFLASH_ENDADDR))
    {
        if (FLASH_isSwaped() == 0)
        {
            return FLASH_writeBytesToArea1(addr, pBuf, byteCnt);
        }
        else
        {
            return FLASH_writeBytesToArea2(addr, pBuf, byteCnt);
        }
    }

    return 0;
}

/**
 * @brief  Write data to OptionFlash
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytesToOptionPage (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    uint8_t ret = 0;

    if ((addr >= FLASH_OPTIONBYTES1_STARTADDR) && ((addr + byteCnt - 1) <= FLASH_OPTIONBYTES2_ENDADDR))
    {
        if (((byteCnt % 8) == 0) && ((addr % 8) == 0))
        {
            ret = 1;
            if (FLASH_isSwaped() == 0)
            {
                FLASH_unlockRegs1();
                FLASH_unlockOptionBytes();
                FLASH_clearOperationCompleteFlag1();

                uint32_t Bak = READ_REG(FLASH->CR1.WORDVAL);
                Bak &= ~FLASH_OP_MASK;
                WRITE_REG(FLASH->CR1.WORDVAL, Bak | FLASH_OP_OPTPG);
                __DSB();

                pBuf += (byteCnt - 8);
                addr += (byteCnt - 8);
                while (byteCnt && ret)
                {
                    uint64_t tmp64 = (((uint64_t)pBuf[0]) << 0 ) | (((uint64_t)pBuf[1]) << 8 ) |\
                                     (((uint64_t)pBuf[2]) << 16) | (((uint64_t)pBuf[3]) << 24) |\
                                     (((uint64_t)pBuf[4]) << 32) | (((uint64_t)pBuf[5]) << 40) |\
                                     (((uint64_t)pBuf[6]) << 48) | (((uint64_t)pBuf[7]) << 56);
                    *((__IO uint64_t *)addr) = tmp64;
                    __DSB();
                    while (FLASH_isBusy1()){;}
                    if ( *((__IO uint64_t *)addr) != tmp64 )
                    {
                        ret = 0;
                    }
                    byteCnt -= 8;
                    addr -= 8;
                    pBuf -= 8;
                }

                WRITE_REG(FLASH->CR1.WORDVAL, Bak);
                FLASH_lockOptionBytes1();
                FLASH_lockRegs1();
            }
            else
            {
                FLASH_unlockRegs2();
                FLASH_unlockOptionBytes();
                FLASH_clearOperationCompleteFlag2();

                uint32_t Bak = READ_REG(FLASH->CR2.WORDVAL);
                Bak &= ~FLASH_OP_MASK;
                WRITE_REG(FLASH->CR2.WORDVAL, Bak | FLASH_OP_OPTPG);
                __DSB();

                pBuf += (byteCnt - 8);
                addr += (byteCnt - 8);
                while (byteCnt)
                {
                    uint64_t tmp64 = (((uint64_t)pBuf[0]) << 0 ) | (((uint64_t)pBuf[1]) << 8 ) |\
                                     (((uint64_t)pBuf[2]) << 16) | (((uint64_t)pBuf[3]) << 24) |\
                                     (((uint64_t)pBuf[4]) << 32) | (((uint64_t)pBuf[5]) << 40) |\
                                     (((uint64_t)pBuf[6]) << 48) | (((uint64_t)pBuf[7]) << 56);
                    *((__IO uint64_t *)addr) = tmp64;
                    __DSB();
                    while (FLASH_isBusy2()){;}
                    if ( *((__IO uint64_t *)addr) != tmp64 )
                    {
                        ret = 0;
                    }
                    byteCnt -= 8;
                    addr -= 8;
                    pBuf -= 8;
                }

                WRITE_REG(FLASH->CR2.WORDVAL, Bak);
                FLASH_lockOptionBytes2();
                FLASH_lockRegs2();
            }
        }
    }

    return ret;
}

/**
 * @brief  Write SwapTag to Swap Config Page
 * @param  SwapEn    Enable or Disable Bank swap
 *                    - 0x00: do not swap bank1 and bank2
 *                    - 0x01: swap bank1 and bank2 after reset
 * @return Returns current option status
 *                    - bool: 0: Fail
 *                            1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_writeSwapTag (uint8_t SwapEn)
{
    uint64_t tag;

    tag = SwapEn ? 0xFFFFFFA50000005A : 0xFFFFFFFF00000000;
    if (FLASH_isSwaped() == 0)
    {
        if (FLASH_eraseOnePageInArea1(FLASH_SWAPTAG_ADDR))
        {
            if (FLASH_writeBytesToArea1(FLASH_SWAPTAG_ADDR, (uint8_t *)&tag, 8))
            {
                return 1;
            }
        }
    }
    else
    {
        if (FLASH_eraseOnePageInArea2(FLASH_SWAPTAG_ADDR))
        {
            if (FLASH_writeBytesToArea2(FLASH_SWAPTAG_ADDR, (uint8_t *)&tag, 8))
            {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * @brief  Get Write Protect Status of Bank1.
 * @param  pBuf    Pointer to the write protect status buf
 * @note Returns Protect Status ( 16 bytes ) at pBuf
 */
void FLASH_getWriteProtectStatus1 (uint8_t *pBuf)
{
    for (uint32_t i = 0; i < 16; i++)
    {
        pBuf[i] = *(((uint8_t *)&FLASH->WRPR11.WORDVAL) + i);
    }
}

/**
 * @brief  Get Write Protect Status of Bank2.
 * @param  pBuf    Pointer to the write protect status buf
 * @note Returns Protect Status ( 16 bytes ) at pBuf
 */
void FLASH_getWriteProtectStatus2 (uint8_t *pBuf)
{
    for (uint32_t i = 0; i < 16; i++)
    {
        pBuf[i] = *(((uint8_t *)&FLASH->WRPR21.WORDVAL) + i);
    }
}

/**
 * @brief  Modify Option Bytes.
 * @param  addr       Addr of option byte memery need to be modify
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note addr must in user optionbyte page1.
 */
uint8_t FLASH_modifyOptionBytes (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    uint32_t flag = 1;
    uint8_t OptionPageBakBuf[FLASH_OPTIONBYTES_SIZE];
    uint32_t offset = addr - FLASH_OPTIONBYTES1_STARTADDR;

    if (addr >= FLASH_OPTIONBYTES1_STARTADDR && (addr + byteCnt - 1) <= FLASH_OPTIONBYTES1_ENDADDR)
    {
        /* Prepare the data to be written */
        for (uint32_t i=0; i<1024; i++)
        {
            OptionPageBakBuf[i] = TYPE8(FLASH_OPTIONBYTES1_STARTADDR + i);
        }
        for (uint32_t i=0; i<byteCnt; i++)
        {
            OptionPageBakBuf[i+offset] = pBuf[i];
        }
        OptionPageBakBuf[3] = 0x5A;
        for (uint32_t i=0; i<=0x70; i+=8)
        {
            *((uint32_t *)(OptionPageBakBuf+i+4)) = ~(*((uint32_t *)(OptionPageBakBuf+i)));
        }

        /* Backup UserOptionByte1 to  UserOptionByte2 */
        if (flag)
        {
            flag = FLASH_eraseOneOptionPage(FLASH_OPTIONBYTES2_STARTADDR);
        }
        if (flag)
        {
            flag = FLASH_writeBytesToOptionPage(FLASH_OPTIONBYTES2_STARTADDR, (uint8_t *)FLASH_OPTIONBYTES1_STARTADDR, FLASH_OPTIONBYTES_SIZE);
        }

        /* Write Data to UserOptionByte1 */
        if (flag)
        {
            flag = FLASH_eraseOneOptionPage(FLASH_OPTIONBYTES1_STARTADDR);
        }
        if (flag)
        {
            flag = FLASH_writeBytesToOptionPage(FLASH_OPTIONBYTES1_STARTADDR, OptionPageBakBuf, FLASH_OPTIONBYTES_SIZE);
        }
    }

    return flag;
}

/**
 * @brief  Maintain Option Bytes.
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_maintainOptionBytes (void)
{
    uint8_t flag = 1;
    if (*((__IO uint8_t *)FLASH_OPTIONBYTES1_TAGADDR) != 0x5A)
    {
        if (*((__IO uint8_t *)FLASH_OPTIONBYTES2_TAGADDR) == 0x5A)
        {
            if (flag)
            {
                flag = FLASH_eraseOneOptionPage(FLASH_OPTIONBYTES1_STARTADDR);
            }
            if (flag)
            {
                flag = FLASH_writeBytesToOptionPage(FLASH_OPTIONBYTES1_STARTADDR, (uint8_t *)FLASH_OPTIONBYTES2_STARTADDR, 1024);
            }
        }
    }

    return flag;
}

/**
 * @brief  Config readout protect level.
 * @param  rdpLevel    readout protect level
 *                      - 0: No protect
 *                      - 1: readout protect level-1
 *                      - 2: readout protect level-2
 * @return Returns current option status
 *                      - bool: 0: Fail
 *                              1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_configReadoutProtectLevel (uint32_t rdpLevel)
{
    uint8_t tmp = 0x00;
    uint8_t RpdKeys[] = {0xAA, 0x11, 0xCC};

    if (rdpLevel <= 2)
    {
        tmp = FLASH_modifyOptionBytes(FLASH_OPTIONBYTES1_STARTADDR, &RpdKeys[rdpLevel], 1);
    }

    return tmp;
}

/**
 * @brief  Get readout protect level.
 * @return Returns readout protect level
 *          - 0: No protect
 *          - 1: readout protect level-1
 *          - 2: readout protect level-2
 */
uint8_t FLASH_getReadoutProtectLevel (void)
{
    uint32_t tmp32a = *((__IO uint32_t *)(FLASH_OPTIONBYTES1_STARTADDR + 0));
    uint32_t tmp32b = *((__IO uint32_t *)(FLASH_OPTIONBYTES1_STARTADDR + 4));
    if (tmp32a == ~tmp32b)
    {
        tmp32a &= 0xFF;
        if (tmp32a == 0xAA)
        {
            return 0;
        }
        if (tmp32a == 0xCC)
        {
            return 2;
        }
    }

    return 1;
}
