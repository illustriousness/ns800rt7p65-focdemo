/**
  * @file       uart.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx uart module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "uart.h"


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
  * @brief  Sets UART baud rate
  * @param  uart        UART port address
  *                      - UART1: UART1 base address index
  *                      - UART2: UART2 base address index
  *                      - UART3: UART3 base address index
  *                      - UART4: UART4 base address index
  * @param  baudrate    UART Baud rate value to set, with a maximum of 30 Mbps
  *                      Standard rates include 9600, 19200, 38400, 43000, 57600, 76800,
  *                      115200, 128000, 230400, 256000, 460800, 921600
  *
  */
void UART_setBaud (UART_TypeDef* uart, uint32_t baudrate)
{
    uint16_t sbr, sbrTemp, i;
    uint32_t osr = 4, tempDiff, calculatedBaud;
    uint32_t baudDiff, maxOsr;

    /* UART clock source = PCLK2 clock */
    uint32_t apb24Clk = RCC_getPclk2Frequency();

    sbr = (uint16_t)(apb24Clk / (baudrate * osr));
    calculatedBaud = (apb24Clk / (osr * sbr));
    if (calculatedBaud > baudrate)
    {
        baudDiff = calculatedBaud - baudrate;
    }
    else
    {
        baudDiff = baudrate - calculatedBaud;
    }

    /* Finds the highest supported OSR value */
    maxOsr = apb24Clk / baudrate;
    if (maxOsr > 32)
    {
        maxOsr = 32;
    }

    /* Optimizes OSR selection through iterative calculation */
    if (maxOsr >= 5)
    {
        for (i = 5; i <= maxOsr; i++)
        {
            sbrTemp = (uint16_t)(apb24Clk / (baudrate * i));
            calculatedBaud = (apb24Clk / (i * sbrTemp));
            if (calculatedBaud > baudrate)
            {
                tempDiff = calculatedBaud - baudrate;
            }
            else
            {
                tempDiff = baudrate - calculatedBaud;
            }
            if (tempDiff <= baudDiff)
            {
                baudDiff = tempDiff;
                osr = i;
                sbr = sbrTemp;
            }
        }
    }

    /* When OSR value is between 4x and 7x oversampling, set the BOTHEDGE bit in BAUD register */
    if (osr < 8)
    {
        SET_BIT(uart->BAUD.WORDVAL, UART_BAUD_BOTHEDGE_M);
    }

    /* Writes the OSR and SBR values to the BAUD registers */
    MODIFY_REG(uart->BAUD.WORDVAL, UART_BAUD_OSR_M | UART_BAUD_SBR_M, \
              ((osr - 1) << UART_BAUD_OSR_S) | (sbr << UART_BAUD_SBR_S));
}

/**
  * @brief  Writes a character array to UART transmitter
  * @note   Supports only 7-bit and 8-bit character formats
  * @param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * @param  array     Pointer to transmit data buffer
  * @param  length    Number of bytes to transmit
  */
void UART_writeCharArray (UART_TypeDef* uart, const uint8_t *const array, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        /* Wait until space is available in UART transmitter */
        while (!UART_isSpaceAvailable(uart))
        {
            ;
        }

        /* Send a character to UART transmitter */
        UART_writeChar(uart, array[i]);
    }

    /* Wait until transmission completes */
    while (!READ_BIT(uart->STAT.WORDVAL, UART_STAT_TC_M))
    {
        ;
    }
}

/**
  * @brief  Reads a character array from UART receiver
  * @note   Supports only 7-bit and 8-bit character formats
  * @param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * @param  array     Pointer to receive data buffer
  * @param  length    Number of bytes to receive
  */
void UART_readCharArray (UART_TypeDef* uart, uint8_t *const array, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        /* Wait until a character is available in UART receiver */
        while (UART_getRxFifoStatus(uart) == UART_FIFO_RX0)
        {
            ;
        }

        /* Read a character from UART receiver */
        array[i] = UART_readChar(uart);
    }
}

/**
  * @brief  Writes a character array to UART transmitter
  * @note   Supports only 9-bit character formats
  * @param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * @param  array     Pointer to transmit data buffer
  * @param  length    Number of bytes to transmit
  */
void UART_writeChar9Array (UART_TypeDef* uart, const uint16_t *const array, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        /* Wait until space is available in UART transmitter */
        while (!UART_isSpaceAvailable(uart))
        {
            ;
        }

        /* Send 9-bit data to UART transmitter */
        UART_writeChar9(uart, array[i]);
    }

    /* Wait until transmission completes */
    while (!READ_BIT(uart->STAT.WORDVAL, UART_STAT_TC_M))
    {
        ;
    }
}

/**
  * @brief  Reads a character array from UART receiver
  * @note   Supports only 9-bit character formats
  * @param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * @param  array     Pointer to receive data buffer
  * @param  length    Number of bytes to receive
  */
void UART_readChar9Array (UART_TypeDef* uart, uint16_t *const array, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        /* Wait until a character is available in UART receiver */
        while (UART_getRxFifoStatus(uart) == UART_FIFO_RX0)
        {
            ;
        }

        /* Read 9-bit data from UART receiver */
        array[i] = UART_readChar9(uart);
    }
}

/**
  * @brief  Writes a character array to UART transmitter
  * @note   Supports only 10-bit character formats
  * @param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * @param  array     Pointer to transmit data buffer
  * @param  length    Number of bytes to transmit
  */
void UART_writeChar10Array (UART_TypeDef* uart, const uint16_t *const array, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        /* Wait until space is available in UART transmitter */
        while (!UART_isSpaceAvailable(uart))
        {
            ;
        }

        /* Send 10-bit data to UART transmitter */
        UART_writeChar10(uart, array[i]);
    }

    /* Wait until transmission completes */
    while (!READ_BIT(uart->STAT.WORDVAL, UART_STAT_TC_M))
    {
        ;
    }
}

/**
  * @brief  Reads a character array from UART receiver
  * @note   Supports only 10-bit character formats
  * @param  uart      UART port address
  *                    - UART1: UART1 base address index
  *                    - UART2: UART2 base address index
  *                    - UART3: UART3 base address index
  *                    - UART4: UART4 base address index
  * @param  array     Pointer to receive data buffer
  * @param  length    Number of bytes to receive
  */
void UART_readChar10Array (UART_TypeDef* uart, uint16_t *const array, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        /* Wait until a character is available in UART receiver */
        while (UART_getRxFifoStatus(uart) == UART_FIFO_RX0)
        {
            ;
        }

        /* Read 10-bit data from UART receiver */
        array[i] = UART_readChar10(uart);
    }
}
