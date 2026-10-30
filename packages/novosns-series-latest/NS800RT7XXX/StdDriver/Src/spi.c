/**
  * @file       spi.c
  * @author     Zhoukai, Alex-J
  * @brief      Function file for NS800RT7xxx spi module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "spi.h"


/******************************************************************************
 * Definitions
 ******************************************************************************/


/******************************************************************************
 * Variables
 ******************************************************************************/


/******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * @brief  SPI set baudrate
 * @param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * @param  bitRate  SPI bitrate
 *                   This parameter is an unsigned integer that is greater
 *                   than or equal to 0x0UL and less than or equal to lspclkHz divided by 2
 * @return returned spi baudrate status
 *                   This parameter is an unsigned integer which means 
 *                   spi baudrate set failed unless it equal to 0UL.
 */
uint32_t SPI_setBaudRate (SPI_TypeDef *spi, uint32_t bitRate)
{
    uint32_t spr = 0UL;
    uint32_t brdv = 0UL;

    /* SPI disable */
    SPI_disableModule(spi);

    /* Calculate the clock.*/
    uint32_t desired_divider = RCC_getPclk2Frequency() / bitRate;
    if (desired_divider > SPI_CLK_MAX_DIV)
    {
        /* Configure max bitrate (SPI_CLK / 4096) */
        brdv = 3;
        spr = 0xFF;
    }
    else if (desired_divider < SPI_CLK_MIN_DIV)
    {
        /* Configure max bitrate (SPI_CLK / 2) */
        brdv = 0;
        spr = 0;
    }
    else
    {
        uint8_t i;
        for (i = 0; i < 4; i++)
        {
            if (desired_divider <= (SPI_CLK_N_DIV_MULTIPLIER << i))
            {
                break;
            }
        }

        brdv = i & 0x03U;

        uint32_t spbr_divisor = (2U * (1U << i));
        spr = (uint8_t) ((desired_divider / spbr_divisor) - 1U) & 0xFFUL;
    }

    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPR_M, (spr << SPI_SPCR3_SPR_S));
    MODIFY_REG(spi->SPCMD[0].WORDVAL, SPI_SPCMD_BRDV_M, (brdv << SPI_SPCMD_BRDV_S));

    return 0;
}

/**
 * @brief  SPI set config
 * @param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 *                     - SPI3: SPI3 base address index
 *                     - SPI4: SPI4 base address index
 * @param  protocol   SPI transfer protocol
 *                     This parameter can be any value of @ref SPI_TRANSFERPROTOCOL
 * @param  mode       SPI Work mode
 *                     This parameter can be any value of @ref SPI_MODE
 * @param  commmode   SPI Communication mode
 *                     This parameter can be any value of @ref SPI_COMMMODE
 * @param  bitRate    SPI Transfer bitRate
 *                     This parameter is an unsigned integer that is greater
 *                     than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 * @param  dataWidth  SPI transfer data width
 *                     This parameter can be any value of @ref SPI_BitWidth_t
 * @return returned SPI config status
 *                     This parameter is an unsigned integer which means 
 *                     spi init config set failed unless it equal to 0UL.
 */
uint32_t SPI_setConfig (
    SPI_TypeDef *spi,
    SPI_TransferProtocol protocol,
    SPI_Mode mode,
    SPI_CommMode commmode,
    uint32_t bitRate,
    SPI_BitWidth dataWidth)
{
    uint32_t config_status = 0;
    /* SPI disable */
    SPI_disableModule(spi);
    SPI_resetFifo(spi);

    WRITE_REG(spi->SPCR1.WORDVAL, (spi->SPCR1.WORDVAL & ~(SPI_SPCR1_MSTR_M | SPI_SPCR1_TXMD_M)) |
                                      (mode << SPI_SPCR1_MSTR_S) | (commmode << SPI_SPCR1_TXMD_S));

    WRITE_REG(spi->SPCMD[0].WORDVAL,
              (spi->SPCMD[0].WORDVAL & ~(SPI_SPCMD_CPHA_M | SPI_SPCMD_CPOL_M | SPI_SPCMD_SPB_M)) |
                  (protocol << SPI_SPCMD_CPHA_S) | (dataWidth << SPI_SPCMD_SPB_S));

    /* Set the baudrate. */
    config_status = SPI_setBaudRate(spi, bitRate);

    return config_status;
}

/**
 * @brief  SPI Multi-Commands configuration
 * @param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * @param  cmd_len  SPI cmnd length
 *                   This parameter can be any value of @ref SPI_CmdSequence
 */
void SPI_configMultiCmds (SPI_TypeDef *spi, SPI_CmdSequence cmd_len)
{
    if(cmd_len == SPI_CMD_SEQUENCE_0_0)
    {
        return;
    }
    
    if(spi->SPCR1.BIT.MSTR == 1 && spi->SPCR1.BIT.SPE == 1)
    {
        while(spi->SPSR.BIT.IDLNF  != 0)
        {
        }
    }

    /* SPI disable */
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPSLN_M, (cmd_len << SPI_SPCR3_SPSLN_S));

    for(uint8_t i = SPI_CMD_SEQUENCE_0_1; i <= cmd_len; i++)
    {
        WRITE_REG(spi->SPCMD[i].WORDVAL, spi->SPCMD[0].WORDVAL);
    }
}

/**
 * @brief  SPI enable Multi-Commands into Burst Mode
 * @param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * @param  cmd_len  SPI cmd length
 *                   This parameter can be any value of @ref SPI_CmdSequence
 */
void SPI_enableBurstMode (SPI_TypeDef *spi, SPI_CmdSequence cmd_len)
{
    if(spi->SPCR1.BIT.MSTR == 1 && spi->SPCR1.BIT.SPE == 1)
    {
        while(spi->SPSR.BIT.IDLNF  != 0)
        {
        }
    }

    /* SPI disable */
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPSLN_M, (cmd_len << SPI_SPCR3_SPSLN_S));

    for(uint8_t i = SPI_CMD_SEQUENCE_0_0; i < cmd_len; i++)
    {
        SET_BIT(spi->SPCMD[i].WORDVAL, SPI_SPCMD_SSLKP_M);
    }

    CLEAR_BIT(spi->SPCMD[cmd_len].WORDVAL, SPI_SPCMD_SSLKP_M);
}

/**
 * @brief  SPI disable Burst Mode
 * @param  spi      SPI pointer to a SPI_TypeDef structure
 *                   - SPI1: SPI1 base address index
 *                   - SPI2: SPI2 base address index
 *                   - SPI3: SPI3 base address index
 *                   - SPI4: SPI4 base address index
 * @param  cmd_len  SPI cmnd length
 *                   This parameter can be any value of @ref SPI_CmdSequence
 */
void SPI_disableBurstMode (SPI_TypeDef *spi, SPI_CmdSequence cmd_len)
{
    if(spi->SPCR1.BIT.MSTR == 1 && spi->SPCR1.BIT.SPE == 1)
    {
        while(spi->SPSR.BIT.IDLNF  != 0)
        {
        }
    }

    /* SPI disable */
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPSLN_M, (cmd_len << SPI_SPCR3_SPSLN_S));

    for(uint8_t i = SPI_CMD_SEQUENCE_0_0; i <= cmd_len; i++)
    {
        CLEAR_BIT(spi->SPCMD[i].WORDVAL, SPI_SPCMD_SSLKP_M);
    }
}

/**
 * @brief  SPI polling fifo transaction
 * @param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 *                      - SPI3: SPI3 base address index
 *                      - SPI4: SPI4 base address index
 * @param  pTxBuffer   SPI Tx Buffer pointer
 * @param  pRxBuffer   SPI Rx Buffer pointer
 * @param  numOfWords  SPI Transfer data length
 *                      This parameter is an unsigned integer that is greater
 *                      than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
void SPI_pollingFifoTransaction (SPI_TypeDef *spi, uint32_t *pTxBuffer, uint32_t *pRxBuffer, uint32_t numOfWords)
{
    /* Determine the number of 16-level words from number of words to be */
    /* transmitted / received */
    uint32_t numOfSixteenWords = numOfWords / (uint32_t)SPI_FIFO_TXEMPTY;

    /* Determine the number of remaining words from number of words to be */
    /* transmitted / received */
    uint32_t remainingWords    = numOfWords % (uint32_t)SPI_FIFO_TXEMPTY;

    uint32_t count             = 0UL;
    uint32_t i                 = 0UL;
    uint32_t txBuffer_pos      = 0UL;
    uint32_t rxBuffer_pos      = 0UL;

    /* Number of transactions is based on numOfSixteenWords */
    /* Each transaction will transmit and receive 16 words. */
    while (count < numOfSixteenWords)
    {
        /* Fill-up the SPI Transmit FIFO buffers */
        for (i = 1UL; i <= (uint32_t)SPI_FIFO_TXEMPTY; i++)
        {
            SPI_writeDataBlockingFifo(spi, pTxBuffer[txBuffer_pos]);
            txBuffer_pos++;
        }

        /* Wait till SPI Receive FIFO buffer is full */
        while (SPI_getRxFifoStatus(spi) < SPI_FIFO_RXFULL)
        {
        }

        /* Read the SPI Receive FIFO buffers */
        for (i = 1UL; i <= (uint32_t)SPI_FIFO_RXFULL; i++)
        {
            if (pRxBuffer == NULL)
            {
                SPI_readDataBlockingFifo(spi);
            }
            else
            {
                pRxBuffer[rxBuffer_pos] = SPI_readDataBlockingFifo(spi);
                rxBuffer_pos++;
            }
        }
        count++;
    }

    /* Number of transactions is based on remainingWords */
    for (i = 0UL; i < remainingWords; i++)
    {
        SPI_writeDataBlockingFifo(spi, pTxBuffer[txBuffer_pos]);
        txBuffer_pos++;
    }

    /* Wait till SPI Receive FIFO buffer remaining words */
    while ((uint32_t)SPI_getRxFifoStatus(spi) < remainingWords)
    {
    }

    /* Read the SPI Receive FIFO buffers */
    for (i = 0UL; i < remainingWords; i++)
    {
        if (pRxBuffer == NULL)
        {
            SPI_readDataBlockingFifo(spi);
        }
        else
        {
            pRxBuffer[rxBuffer_pos] = SPI_readDataBlockingFifo(spi);
            rxBuffer_pos++;
        }
    }
}

