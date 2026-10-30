/**
  * @file       lin.c
  * @author     Alex-J
  * @brief      Function file for NS800RTxxx LIN module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "lin.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup LIN_PRIVATED_TYPES LIN Privated Types
 * @{
 * @brief  Macro definitions are used with all files privately about 'LIN' module.
 */

/** @defgroup LIN_BUFFER_SIZE LIN Buffer Size
 * @{
 * @brief  Macro definitions about LIN buffer size.
 */
#define BUFFER_DATA_SIZE_LIMIT    (8U)

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
 * @brief  Sets the LIN module baudrate
 * @note   This function sets the baudrate for the LIN module.
 *
 * @param  lin       lin pointer to a LIN_TypeDef structure
 *                     - LIN1: LIN1 base address index
 *                     - LIN2: LIN2 base address index
 * @param  baudrate  a value of baudrate.
 */
void LIN_setBaudrateConfig (LIN_TypeDef *lin, uint32_t baudrate)
{
    /* lin_clk = Hclk */
    uint32_t ahb4Clk = RCC_getHclkFrequency();
    float baudTemp;
    uint32_t intBaud;
    uint8_t fracBaud;

    baudTemp = ahb4Clk / (16.0f * baudrate);
    intBaud  = (uint32_t)baudTemp;
    fracBaud = (uint8_t)((baudTemp - intBaud) * 16 + 0.5f);

    LIN_setFracBaudrate(lin, (LIN_FracBaudRate)fracBaud);
    LIN_setIntegerBaudrate(lin, intBaud);
}

/**
 * @brief  Sets the byte array of the tx data buffer.
 * @note   This function writes given bytes to the tx data buffer.
 *
 * @param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * @param  data  send data bytes array.
 * @param  size  send data bytes array size.
 */
void LIN_sendData (LIN_TypeDef *lin, uint8_t *data, uint8_t size)
{
    uint8_t i = 0;
    volatile uint8_t *pDataReg = (uint8_t *)(&lin->BDRL.WORDVAL);

    if (size > BUFFER_DATA_SIZE_LIMIT)
    {
        return;
    }

    for (i = 0; i < size; i++)
    {
        pDataReg[i] = data[i];
    }
}

/**
 * @brief  Gets the byte array of the rx data buffer.
 * @note   This function gets bytes to the rx data buffer.
 *
 * @param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * @param  data  get data bytes array.
 * @param  size  get data bytes array size.
 */
void LIN_getData (LIN_TypeDef *lin, uint8_t *data, uint8_t size)
{
    uint8_t i = 0;
    uint8_t *pDataReg = (uint8_t *)(&lin->BDRL.WORDVAL);

    if(size > BUFFER_DATA_SIZE_LIMIT)
        size = BUFFER_DATA_SIZE_LIMIT;

    for (i = 0; i < size; i++)
    {
        data[i] = pDataReg[i];
    }
}

/*---------------------------------------- LIN Uart Mode -------------------------------------------*/

/**
 * @brief  Configure the word length in UART mode
 * @note   This function configures the word length in UART mode.
 *
 * @param  lin          lin pointer to a LIN_TypeDef structure
 *                        - LIN1: LIN1 base address index
 *                        - LIN2: LIN2 base address index
 * @param  uartWordLen  a value of the word length.
 */
void LIN_configUartWordLength (LIN_TypeDef *lin, LIN_UartWordLen uartWordLen)
{
    LIN_setUartWordLenghth(lin, ((uint8_t)uartWordLen >> 0), ((uint8_t)uartWordLen >> 1));
}

/**
 * @brief  Configure the parity in UART mode
 * @note   This function configures the parity in UART mode.
 *
 * @param  lin         lin pointer to a LIN_TypeDef structure
 *                       - LIN1: LIN1 base address index
 *                       - LIN2: LIN2 base address index
 * @param  uartParity  a value of the parity.
 */
void LIN_configUartParity (LIN_TypeDef *lin, LIN_UartParity uartParity)
{
    if (uartParity == LIN_UART_NO_PARITY)
    {
        LIN_setUartParity(lin, 0, 0, 0);
    }
    else
    {
        LIN_setUartParity(lin, 1, ((uint8_t)uartParity >> 0), ((uint8_t)uartParity >> 1));
    }
}

/**
 * @brief  Sets the byte array of the UART tx buffer data.
 * @note   This function writes given bytes to the UART tx buffer data.
 *
 * @param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * @param  data  send data bytes array.
 * @param  size  send data bytes array size.
 */
void LIN_uartSendBufferData (LIN_TypeDef *lin, uint8_t *data, uint8_t size)
{
    uint8_t i = 0;
    uint8_t *pDataReg = (uint8_t *)(&lin->BDRL.WORDVAL);
    uint8_t tmpSize = LIN_getUartTDFLTFC(lin);

    if (size > (tmpSize + 1))
    {
        size = (tmpSize + 1);
    }

    for (i = 0; i < size; i++)
    {
        pDataReg[i] = data[i];
    }
}

/**
 * @brief  Receives the byte array of the UART rx buffer data.
 * @note   This function receives bytes to the UART rx buffer data.
 *
 * @param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * @param  data  receiving data bytes array.
 * @param  size  receiving data bytes array size.
 */
void LIN_uartRecvBufferData (LIN_TypeDef *lin, uint8_t *data, uint8_t size)
{
    uint8_t i = 0;
    uint8_t *pDataReg = (uint8_t *)(&lin->BDRM.WORDVAL);

    size = LIN_getUartRDFLRFC(lin) + 1;

    for (i = 0; i < size; i++)
    {
        data[i] = pDataReg[i];
    }
}

/**
 * @brief  Sets the byte array of the UART tx fifo data.
 * @note   This function writes given bytes to the UART tx fifo data.
 *
 * @param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * @param  data  send data bytes array.
 * @param  size  send data bytes array size.
 */
void LIN_uartSendFifoData (LIN_TypeDef *lin, uint8_t *data, uint8_t size)
{
    uint8_t i = 0;
    volatile uint8_t *pDataReg = (uint8_t *)(&lin->BDRL.WORDVAL);

    for (i = 0; i < size; i++)
    {
        while(LIN_getUartStatus(lin) & LIN_UARTSR_DTFTFF_M);
        *pDataReg = data[i];
    }
}

/**
 * @brief  Receives the byte array of the UART rx fifo data.
 * @note   This function receives bytes to the UART rx fifo data.
 *
 * @param  lin   lin pointer to a LIN_TypeDef structure
 *                 - LIN1: LIN1 base address index
 *                 - LIN2: LIN2 base address index
 * @param  data  receiving data bytes array.
 * @param  size  receiving data bytes array size.
 */
uint8_t LIN_uartRecvFifoData (LIN_TypeDef *lin)
{
    uint8_t *pDataReg = (uint8_t *)(&lin->BDRM.WORDVAL);

    return (uint8_t)(*pDataReg);
}

/*--------------------------------------------------------------------------------------------------*/
