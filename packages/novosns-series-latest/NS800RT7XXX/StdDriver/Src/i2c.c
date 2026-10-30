/**
  * @file       i2c.c
  * @author     Haven-X
  * @brief      Function file for NS800RT7xxx i2c module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "i2c.h"


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
  * @brief  Configure master baudrate.
  * @param  i2c            I2C pointer to a I2C_TypeDef structure
  *                         - I2C1: I2C1 base address index
  *                         - I2C2: I2C2 base address index
  * @param  sourceClock    The input clock frequency of the module, use Hz as the unit.
  *                         This frequency can be obtained by using @ref RCC_getPclk2Frequency().
  * @param  baudRate       The expected I2C communication frequency, use Hz as the unit.
  */
void I2C_configMasterBaudRate (I2C_TypeDef *i2c, uint32_t sourceClock, uint32_t baudRate)
{
    bool wasEnabled;
    uint8_t filtScl = READ_BIT(i2c->MCFGR2.WORDVAL, I2C_MCFGR2_FILTSCL_M) >> I2C_MCFGR2_FILTSCL_S;

    uint8_t divider     = 1U;
    uint8_t bestDivider = 1U;
    uint8_t prescale    = 0U;
    uint8_t bestPre     = 0U;

    uint8_t clkCycle;
    uint8_t bestclkCycle = 0U;

    uint32_t absError  = 0U;
    uint32_t bestError = 0xffffffffU;
    uint32_t computedRate;

    /* Disable master mode. */
    wasEnabled = READ_BIT(i2c->MCR.WORDVAL, I2C_MCR_MEN_M);
    I2C_disableMasterModule(i2c);

    /* Baud rate = (sourceClock / 2 ^ prescale) / (CLKLO + 1 + CLKHI + 1 + SCL_LATENCY)
     * SCL_LATENCY = ROUNDDOWN((2 + FILTSCL) / (2 ^ prescale)) */
    for (prescale = 0U; prescale <= 7U; prescale++)
    {
        /* Calculate the clkCycle, clkCycle = CLKLO + CLKHI, divider = 2 ^ prescale */
        clkCycle = (uint8_t)((10U * sourceClock / divider / baudRate + 5U) / 10U - (2U + filtScl) / divider - 2U);

        if (clkCycle > (120U - (2U + filtScl) / divider))
        {
            divider <<= 1U;
            continue;
        }
        /* Calculate the computed baudrate and compare it with the desired baudrate */
        computedRate = (sourceClock / (uint32_t)divider) /
                        ((uint32_t)clkCycle + 2U + (2U + (uint32_t)filtScl) / (uint32_t)divider);
        absError = (baudRate > computedRate) ? (baudRate - computedRate) : (computedRate - baudRate);
        if (absError < bestError)
        {
            bestPre      = prescale;
            bestDivider  = divider;
            bestclkCycle = clkCycle;
            bestError    = absError;

            /* If the error is 0, then we can stop searching because we won't find a better match. */
            if (absError == 0U)
            {
                break;
            }
        }
        divider <<= 1U;
    }

    uint8_t tmpHigh = (bestclkCycle - (2U + filtScl) / bestDivider) / 2U;
    while (tmpHigh > (bestclkCycle - 52U * sourceClock / baudRate / bestDivider / 100U + 1U))
    {
        tmpHigh = tmpHigh - 1U;
    }

    /* Calculate DATAVD and SETHOLD.
       To meet the timing requirement of I2C spec for standard mode, fast mode and fast mode plus: */
    uint8_t tmpHold = (uint8_t)(sourceClock / baudRate / bestDivider / 2U) - 1U;
    uint8_t tmpDataVd = (uint8_t)(sourceClock / baudRate / bestDivider / 4U) - 1U;

    if ((sourceClock / baudRate / 20U) > (bestDivider + 2U))
    {
        /* Read out the FILTSDA configuration, if it is smaller than expected, change the setting. */
        __IO uint8_t filtSda = (uint8_t)(READ_BIT(i2c->MCFGR2.WORDVAL, I2C_MCFGR2_FILTSDA_M) >> I2C_MCFGR2_FILTSDA_S);
        if (filtSda < (sourceClock / baudRate / 20U - bestDivider - 2U))
        {
            filtSda = (uint8_t)(sourceClock / baudRate / 20U) - bestDivider - 2U;
        }
        MODIFY_REG(i2c->MCFGR2.WORDVAL, I2C_MCFGR2_FILTSDA_M, (filtSda << I2C_MCFGR2_FILTSDA_S) & I2C_MCFGR2_FILTSDA_M);
    }

    /* Set CLKHI, CLKLO, SETHOLD, DATAVD value. */
    WRITE_REG(i2c->MCCR0.WORDVAL, ((tmpHigh << I2C_MCCR0_CLKHI_S) & I2C_MCCR0_CLKHI_M) | 
                                  (((bestclkCycle - tmpHigh) << I2C_MCCR0_CLKLO_S) & I2C_MCCR0_CLKLO_M) |
                                  ((tmpHold << I2C_MCCR0_SETHOLD_S) & I2C_MCCR0_SETHOLD_M) |
                                  ((tmpDataVd << I2C_MCCR0_DATAVD_S) & I2C_MCCR0_DATAVD_M));
    /* Set PRESCALE value. */
    MODIFY_REG(i2c->MCFGR1.WORDVAL, I2C_MCFGR1_PRESCALER_M, (bestPre << I2C_MCFGR1_PRESCALER_S) & I2C_MCFGR1_PRESCALER_M);

    /* Restore master mode. */
    if (wasEnabled)
    {
        I2C_enableMasterModule(i2c);
    }
}

/**
  * @brief  Configure master data match.
  * @param  i2c                I2C pointer to a I2C_TypeDef structure
  *                             - I2C1: I2C1 base address index
  *                             - I2C2: I2C2 base address index
  * @param  matchMode          The data match mode for master
  *                             This parameter can be any value of @ref I2C_MASTER_MATCHMODE
  * @param  matchCode0         The match data 0.
  *                             The range of values is from 0 to 255.
  * @param  matchCode1         The match data 1.
  *                             The range of values is from 0 to 255.
  * @param  rxMatchDataOnly    I2C master only receives the data that matches.
  *                             This parameter can be any value of @ref I2C_MASTER_RXMATCHDATAONLY
  */
void I2C_configMasterDataMatch (I2C_TypeDef *i2c, I2C_MasterMatchMode matchMode, 
                                uint8_t matchCode0, uint8_t matchCode1, I2C_MasterRxMatchDataOnly rxMatchDataOnly)
{
    /* Disable master mode. */
    uint8_t wasEnabled = READ_BIT(i2c->MCR.WORDVAL, I2C_MCR_MEN_M);
    I2C_disableMasterModule(i2c);

    MODIFY_REG(i2c->MCFGR1.WORDVAL, I2C_MCFGR1_MATCFG_M, (uint32_t)matchMode);
    MODIFY_REG(i2c->MCFGR0.WORDVAL, I2C_MCFGR0_RDMO_M, (uint32_t)rxMatchDataOnly);
    WRITE_REG(i2c->MDMR.WORDVAL, matchCode0 | (matchCode1 << 16U));

    /* Restore master mode. */
    if (wasEnabled)
    {
        I2C_enableMasterModule(i2c);
    }
}

/**
  * @brief  check and clear master error.
  * @param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * @param  status    The master status flags
  *                    This parameter can be obtained by reading the MSR register.
  * @return Returned the status of master
  *                    This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_checkAndClearMasterError (I2C_TypeDef *i2c, uint32_t status)
{
    I2C_Status result = I2C_STATUS_SUCCESS;

    /* Check for error. These errors cause a stop to automatically be sent. 
       We must clear the errors before a new transfer can start. */
    if (status & I2C_MASTER_FLAG_STOP)
    {
        status &= (uint32_t)I2C_MASTER_FLAG_ERROR;
        if (0U != status)
        {
            /* Select the correct error code. Ordered by severity, with bus issues first. */
            if (status & (uint32_t)I2C_MASTER_FLAG_PINLOWTIMEOUT)
            {
                result = I2C_STATUS_PINLOWTIMEOUT;
            }
            else if (status & (uint32_t)I2C_MASTER_FLAG_ARBLOST)
            {
                result = I2C_STATUS_ARBLOST;
            }
            else if (status & (uint32_t)I2C_MASTER_FLAG_NACK)
            {
                result = I2C_STATUS_NAK;
            }
            else if (status & (uint32_t)I2C_MASTER_FLAG_FIFOERR)
            {
                result = I2C_STATUS_FIFOERROR;
            }

            /* Reset fifos. */
            I2C_resetMasterFIFO(i2c, I2C_FIFORESET_TXRX);
            
            /* Clear the flags. */
            I2C_clearMasterStatusFlags(i2c, status);
        }
    }

    return result;
}

/**
  * @brief  Waiting for the master TX-FIFO to have space available.
  * @param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * @return Returned the status of master
  *                 This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_waitMasterTxReady (I2C_TypeDef *i2c)
{
    I2C_Status result = I2C_STATUS_SUCCESS;
    uint32_t status;
    uint8_t txCount;
    uint8_t txFifoSize = 16U;

    do
    {   /* Get the number of words in the tx fifo and compute empty slots. */
        txCount = txFifoSize - I2C_getMasterTxFifoCounts(i2c);

        /* Check for error flags. */
        status = I2C_getMasterStatusFlags(i2c);
        result = I2C_checkAndClearMasterError(i2c, status);
        if (I2C_STATUS_SUCCESS != result)
            break;
    } while (0U == txCount);

    return result;
}

/**
  * @brief  Check the busy signal on the master bus.
  * @param  i2c    I2C pointer to a I2C_TypeDef structure
  *                 - I2C1: I2C1 base address index
  *                 - I2C2: I2C2 base address index
  * @return Returned the status of master
  *                 This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_checkMasterBusyBus (I2C_TypeDef *i2c)
{
    I2C_Status result = I2C_STATUS_SUCCESS;

    __IO uint32_t status = I2C_getMasterStatusFlags(i2c);
    if ((0U != (status & (uint32_t)I2C_MASTER_FLAG_BUSBUSY)) && (0U == (status & (uint32_t)I2C_MASTER_FLAG_BUSY)))
    {
        result = I2C_STATUS_BUSY;
    }

    return result;
}

/**
  * @brief  Check if the slave is ready from the master.
  * @param  i2c        I2C pointer to a I2C_TypeDef structure
  *                     - I2C1: I2C1 base address index
  *                     - I2C2: I2C2 base address index
  * @param  address    I2C device address
  *                     The range of this parameter's value is from 0 to 127.
  * @param  trials     The number of times the host sends addressing requests
  *                     When set to 0, it will enter an infinite loop until the device becomes ready.
  *                     When set to non-zero, it will repeat the addressing operation trials times.
  */
void I2C_isDeviceReady (I2C_TypeDef *i2c, uint8_t address, uint32_t trials)
{
    __IO uint32_t awaysLoop = (trials == 0U) ? 1U : 0U;

    /* Return an error if the bus is already in use not by us. */
    I2C_Status result = I2C_checkMasterBusyBus(i2c);
    if (I2C_STATUS_SUCCESS == result)
    {
        /* Clear all flags. */
        I2C_clearMasterStatusFlags(i2c, (uint32_t)I2C_MASTER_FLAG_CLEAR);
        
        /* Turn off auto-stop option. */
        I2C_disableMasterAutoStop(i2c);

        while (awaysLoop || trials--)
        {
            /* Wait until there is room in the fifo. */
            result = I2C_waitMasterTxReady(i2c);
            if (I2C_STATUS_SUCCESS == result)
            {
                /* Issue start command. */
                WRITE_REG(i2c->MTDR.WORDVAL, 
                          (uint32_t)I2C_COMMAND_START_EXPNACK | (((uint32_t)address & 0xFE) | (uint32_t)I2C_DIRECTION_WRITE));
            }
            else if (result == I2C_STATUS_NAK)
            {
                break;
            }
        }
    }
    
    //I2C_sendStop(i2c);
}

/**
  * @brief  The master send start and the address.
  * @param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * @param  address      I2C device address
  *                      The range of this parameter's value is from 0 to 127.
  * @param  direction    I2C transmission direction
  *                       This parameter can be any value of @ref I2C_DIRECTION
  * @return Returned the status of master
  *                       This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_sendStart (I2C_TypeDef *i2c, uint8_t address, I2C_Direction direction)
{
    /* Return an error if the bus is already in use not by us. */
    I2C_Status result = I2C_checkMasterBusyBus(i2c);
    if (I2C_STATUS_SUCCESS == result)
    {
        /* Clear all flags. */
        I2C_clearMasterStatusFlags(i2c, (uint32_t)I2C_MASTER_FLAG_CLEAR);

        /* Turn off auto-stop option. */
        I2C_disableMasterAutoStop(i2c);

        /* Wait until there is room in the fifo. */
        result = I2C_waitMasterTxReady(i2c);
        if (I2C_STATUS_SUCCESS == result)
        {
            /* Issue start command. */
            WRITE_REG(i2c->MTDR.WORDVAL, 
                      (uint32_t)I2C_COMMAND_START_EXPACK | (((uint32_t)address & 0xFE) | (uint32_t)direction));
        }
    }

    return result;
}

/**
  * @brief  The master send re-start and the address.
  * @param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * @param  address      I2C device address
  *                       The range of this parameter's value is from 0 to 127.
  * @param  direction    I2C transmission direction
  *                       This parameter can be any value of @ref I2C_DIRECTION
  * @return Returned the status of master
  *                       This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_sendReStart (I2C_TypeDef *i2c, uint8_t address, I2C_Direction direction)
{
    return I2C_sendStart(i2c, address, direction);
}

/**
  * @brief  The master send stop.
  * @param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * @return Returned the status of master
  *                       This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_sendStop (I2C_TypeDef *i2c)
{
    /* Wait until there is room in the fifo. */
    I2C_Status result = I2C_waitMasterTxReady(i2c);
    if (I2C_STATUS_SUCCESS == result)
    {
        /* Send the STOP signal */
        WRITE_REG(i2c->MTDR.WORDVAL, (uint32_t)I2C_COMMAND_STOP);
        uint32_t status;
        do
        {
            status = I2C_getMasterStatusFlags(i2c);
            /* Check if the stop was sent successfully. */
        } while (!(status & (uint32_t)I2C_MASTER_FLAG_STOP));
        result = I2C_checkAndClearMasterError(i2c, status);
        I2C_clearMasterStatusFlags(i2c, (uint32_t)I2C_MASTER_FLAG_CLEAR);
    }

    return result;
}

/**
  * @brief  The master transmits the memory address of the slave unit.
  * @param  i2c               I2C pointer to a I2C_TypeDef structure
  *                            - I2C1: I2C1 base address index
  *                            - I2C2: I2C2 base address index
  * @param  subAddress        I2C device memory address
  *                            The range of this parameter's value is from 0 to 0xFFFFFFFF.
  * @param  subAddressSize    I2C device memory address size
  *                            This parameter can be any value of @ref I2C_SUBADDRSIZE
  * @return Returned the status of master
  *                            This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_sendSubAddrMaster (I2C_TypeDef *i2c, uint32_t subAddress, I2C_SubAddressSize subAddressSize)
{
    uint8_t subAddrBuf[4];
    uint8_t count = 0;

    /* Subaddress, MSB first. */
    if (I2C_SUBADDRSIZE_NONE != subAddressSize)
    {
        uint32_t subaddressRemaining = subAddressSize;
        while (0U != subaddressRemaining--)
        {
            uint8_t subaddressByte = (uint8_t)((subAddress >> (8U * subaddressRemaining)) & 0xFFU);
            subAddrBuf[count++] = subaddressByte;
        }
    }

    return I2C_sendDataMaster(i2c, &subAddrBuf, (uint8_t)subAddressSize);
}

/**
  * @brief  The master send data.
  * @param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * @param  txBuff    The pointer of the data that the I2C master needs to send
  * @param  txSize    The amount of data that the I2C master needs to send
  * @return Returned the status of master
  *                   This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_sendDataMaster (I2C_TypeDef *i2c, void *txBuff, uint32_t txSize)
{
    I2C_Status result = I2C_STATUS_SUCCESS;
    __IO uint8_t *buf = (__IO uint8_t *)txBuff;
    
    /* Send data buffer */
    while (0U != (txSize--))
    {
        /* Wait until there is room in the fifo. This also checks for errors. */
        result = I2C_waitMasterTxReady(i2c);
        if (I2C_STATUS_SUCCESS != result)
        {
            break;
        }

        /* Write byte into I2C master data register. */
        WRITE_REG(i2c->MTDR.WORDVAL, *buf++);
    }

    return result;
}

/**
  * @brief  The master receive data.
  * @param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * @param  rxBuff    The pointer of the data that the I2C master needs to receive
  * @param  rxSize    The amount of data that the I2C master needs to receive
  *                    The maximum number of received bytes cannot exceed 3840.
  * @return Returned the status of master
  *                    This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_receiveDataMaster (I2C_TypeDef *i2c, void *rxBuff, uint32_t rxSize)
{
    I2C_Status result = I2C_STATUS_SUCCESS;
    uint8_t *buf = (uint8_t *)rxBuff;
    uint32_t tmpRxSize = rxSize;

    /* Check transfer data size. */
    if (rxSize > (256UL * 15U))
    {
        return I2C_STATUS_INVALIDARGUMENT;
    }

    /* Handle empty read. */
    if (rxSize != 0U)
    {
        /* Wait until there is room in the command fifo. */
        result = I2C_waitMasterTxReady(i2c);
        if (I2C_STATUS_SUCCESS == result)
        {
            /* Issue command to receive data. A single write to MTDR can issue read operation of 0xFFU + 1 byte of data
               at most, so when the rxSize is larger than 256, push multiple read commands to MTDR until rxSize is
               reached. */
            while (tmpRxSize != 0U)
            {
                if (tmpRxSize > 256U)
                {
                    WRITE_REG(i2c->MTDR.WORDVAL, (uint32_t)(I2C_COMMAND_RXDATA) | 0xFFU);
                    tmpRxSize -= 256U;
                }
                else
                {
                    WRITE_REG(i2c->MTDR.WORDVAL, (uint32_t)(I2C_COMMAND_RXDATA) | (tmpRxSize - 1U));
                    tmpRxSize  = 0U;
                }
            }

            /* Receive data */
            while (0U != (rxSize--))
            {
                /* Read I2C receive fifo register. The register includes a flag to indicate whether */
                /* the FIFO is empty, so we can both get the data and check if we need to keep reading */
                /* using a single register read. */
                uint32_t value = 0U;
                do
                {
                    result = I2C_checkAndClearMasterError(i2c, I2C_getMasterStatusFlags(i2c));
                    if (I2C_STATUS_SUCCESS != result)
                    {
                        break;
                    }
                    value = READ_REG(i2c->MRDR.WORDVAL);

                } while (0U != (value & I2C_MRDR_RXEMPTY_M));
                
                if (I2C_STATUS_SUCCESS != result)
                {
                    break;
                }

                *buf++ = (uint8_t)(value & I2C_MRDR_DATA_M);
            }
        }
    }

    return result;
}

/**
  * @brief  Configure slave address matching.
  * @param  i2c          I2C pointer to a I2C_TypeDef structure
  *                       - I2C1: I2C1 base address index
  *                       - I2C2: I2C2 base address index
  * @param  matchMode    I2C slave match mode
  *                       This parameter can be any value of @ref I2C_SLAVE_MATCHMODE
  * @param  address0     I2C slave address 0
  *                       This address can be 7-b or 10-b.
  * @param  address1     I2C slave address 1
  *                       This address can be 7-b or 10-b.
  */
void I2C_configSlaveAddressMatch (I2C_TypeDef *i2c, I2C_SlaveMatchMode matchMode, uint16_t address0, uint16_t address1)
{
    /* Disable slave mode. */
    uint8_t wasEnabled = READ_BIT(i2c->SCR.WORDVAL, I2C_SCR_SEN_M);
    I2C_disableSlaveModule(i2c);

    MODIFY_REG(i2c->SCFGR1.WORDVAL, I2C_SCFGR1_ADDRCFG_M, matchMode);
    WRITE_REG(i2c->SAMR.WORDVAL, (address0 & 0x3FFU) | ((address1 & 0x3FFU) << 16U));

    /* Restore slave mode. */
    if (wasEnabled)
    {
        I2C_enableSlaveModule(i2c);
    }
}

/**
  * @brief  check and clear slave error.
  * @param  i2c       I2C pointer to a I2C_TypeDef structure
  *                    - I2C1: I2C1 base address index
  *                    - I2C2: I2C2 base address index
  * @param  status    The slave status flags
  *                    This parameter can be obtained by reading the SSR register.
  * @return Returned the status of slave
  *                    This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_checkAndClearSlaveError (I2C_TypeDef *i2c, uint32_t status)
{
    I2C_Status result = I2C_STATUS_SUCCESS;

    status &= (uint32_t)I2C_SLAVE_FLAG_ERROR;
    if (0U != status)
    {
        if (0U != (status & (uint32_t)I2C_SLAVE_FLAG_BITERR))
        {
            result = I2C_STATUS_BITERROR;
        }
        else if (0U != (status & (uint32_t)I2C_SLAVE_FLAG_FIFOERR))
        {
            result = I2C_STATUS_FIFOERROR;
        }

        /* Clear the errors. */
        I2C_clearSlaveStatusFlags(i2c, status);
    }

    return result;
}

/**
  * @brief  The slave send data.
  * @param  i2c             I2C pointer to a I2C_TypeDef structure
  *                          - I2C1: I2C1 base address index
  *                          - I2C2: I2C2 base address index
  * @param  txBuff          The pointer of the data that the I2C slave needs to send
  * @param  txSize          The amount of data that the I2C salve needs to send
  * @param  actualTxSize    The actual number of received data by the I2C slave device
  * @return Returned the status of slave
  *                         This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_sendDataSlave (I2C_TypeDef *i2c, void *txBuff, uint32_t txSize, uint32_t *actualTxSize)
{
    I2C_Status result  = I2C_STATUS_SUCCESS;
    uint8_t *buf       = (uint8_t *)txBuff;
    uint32_t remaining = txSize;

    /* Clear stop flag. */
    I2C_clearSlaveStatusFlags(i2c, (uint32_t)I2C_SLAVE_FLAG_STOP | (uint32_t)I2C_SLAVE_FLAG_RESTART);

    while (0U != remaining)
    {
        uint32_t flags;

        /* Wait until we can transmit. */
        do
        {   /* Check for errors */
            flags  = I2C_getSlaveStatusFlags(i2c);
            result = I2C_checkAndClearSlaveError(i2c, flags);
            if (I2C_STATUS_SUCCESS != result)
            {
                if (0U != actualTxSize)
                {
                    *actualTxSize = txSize - remaining;
                }
                break;
            }
        } while (0U == (flags & ((uint32_t)I2C_SLAVE_FLAG_TXREADY | (uint32_t)I2C_SLAVE_FLAG_STOP |
                                 (uint32_t)I2C_SLAVE_FLAG_RESTART)));

        if (I2C_STATUS_SUCCESS != result)
        {
            break;
        }
        
        /* Send a byte. */
        if (0U != (flags & (uint32_t)I2C_SLAVE_FLAG_TXREADY))
        {
            WRITE_REG(i2c->STDR.WORDVAL, *buf++);
            --remaining;
        }

        /* Exit loop if we see a stop or restart in transfer*/
        if ((0U != (flags & ((uint32_t)I2C_SLAVE_FLAG_STOP | (uint32_t)I2C_SLAVE_FLAG_RESTART))) &&
            (remaining != 0U))
        {
            I2C_clearSlaveStatusFlags(i2c, (uint32_t)I2C_SLAVE_FLAG_STOP | (uint32_t)I2C_SLAVE_FLAG_RESTART);
            break;
        }
    }

    if (0U != actualTxSize)
    {
        *actualTxSize = txSize - remaining;
    }

    return result;
}

/**
  * @brief  The slave receive data.
  * @param  i2c             I2C pointer to a I2C_TypeDef structure
  *                          - I2C1: I2C1 base address index
  *                          - I2C2: I2C2 base address index
  * @param  rxBuff          The pointer for the I2C slave expecting to receive data
  * @param  rxSize          The expected quantity of data to be received by the I2C slave device
  * @param  actualTxSize    The actual number of received data by the I2C slave device
  * @return Returned the status of slave
  *                         This value can be any value of @ref I2C_STATUS
  */
I2C_Status I2C_receiveDataSlave (I2C_TypeDef *i2c, void *rxBuff, uint32_t rxSize, uint32_t *actualRxSize)
{
    I2C_Status result  = I2C_STATUS_SUCCESS;
    uint8_t *buf       = (uint8_t *)rxBuff;
    uint32_t remaining = rxSize;

    /* Clear stop flag. */
    I2C_clearSlaveStatusFlags(i2c, (uint32_t)I2C_SLAVE_FLAG_STOP | (uint32_t)I2C_SLAVE_FLAG_RESTART);

    while (0U != remaining)
    {
        uint32_t flags;

        /* Wait until we can receive. */
        do
        {   /* Check for errors */
            flags  = I2C_getSlaveStatusFlags(i2c);
            result = I2C_checkAndClearSlaveError(i2c, flags);
            if (I2C_STATUS_SUCCESS != result)
            {
                if (0U != actualRxSize)
                {
                    *actualRxSize = rxSize - remaining;
                }
                break;
            }
        } while (0U == (flags & ((uint32_t)I2C_SLAVE_FLAG_RXREADY | (uint32_t)I2C_SLAVE_FLAG_STOP |
                                 (uint32_t)I2C_SLAVE_FLAG_RESTART)));

        if (I2C_STATUS_SUCCESS != result)
        {
            break;
        }

        /* Receive a byte. */
        if (flags & (uint32_t)I2C_SLAVE_FLAG_RXREADY)
        {
            *buf++ = (uint8_t)READ_BIT(i2c->SRDR.WORDVAL, I2C_SRDR_DATA_M);
            --remaining;
        }

        /* Exit loop if we see a stop or restart */
        if ((flags & ((uint32_t)I2C_SLAVE_FLAG_STOP | (uint32_t)I2C_SLAVE_FLAG_RESTART)) && (remaining != 0U))
        {
            I2C_clearSlaveStatusFlags(i2c, (uint32_t)I2C_SLAVE_FLAG_STOP | (uint32_t)I2C_SLAVE_FLAG_RESTART);
            break;
        }
    }

    if (0U != actualRxSize)
    {
        *actualRxSize = rxSize - remaining;
    }
    
    return result;
}
