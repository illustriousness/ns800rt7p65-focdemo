/**
  * @file       clb.c
  * @author     Favian
  * @brief      Function file for NS800RT7xxx clb module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "clb.h"


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
  * @brief  Set the emulation mode.CLB_configCounterLoadMatch
  * @param  clb          The base address of a CLB tile's logic config register.
  *                       - CLB1: CLB1 base address index
  *                       - CLB2: CLB2 base address index
  *                       - CLB3: CLB3 base address index
  *                       - CLB4: CLB4 base address index
  *                       - CLB5: CLB5 base address index
  *                       - CLB6: CLB6 base address index
  * @param  counterID    The specified counter unit.
  * @param  load         The value for counter's load mode.
  * @param  match1       The value for counter's match 1.
  * @param  match2       The value for counter's match 2.
  */
void CLB_configCounterLoadMatch (CLB_TypeDef *clb, CLB_Counters counterID,
                                 uint32_t load, uint32_t match1, uint32_t match2)
{
    switch(counterID)
    {
        case CLB_CTR0:
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_0_LOAD, load);
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_0_MATCH1, match1);
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_0_MATCH2, match2);
            break;

        case CLB_CTR1:
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_1_LOAD, load);
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_1_MATCH1, match1);
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_1_MATCH2, match2);
            break;

        case CLB_CTR2:
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_2_LOAD, load);
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_2_MATCH1, match1);
            CLB_writeInterface(clb, CLB_ADDR_COUNTER_2_MATCH2, match2);
            break;

        default:
            /* Invalid counterID value */
            break;
    }
}

/**
  * @brief  Clear FIFO registers.
  *         This function clears the PUSH/PULL FIFOs as well as its pointers.
  * @param  clb    The base address of a CLB tile's logic config register.
  *                 - CLB1: CLB1 base address index
  *                 - CLB2: CLB2 base address index
  *                 - CLB3: CLB3 base address index
  *                 - CLB4: CLB4 base address index
  *                 - CLB5: CLB5 base address index
  *                 - CLB6: CLB6 base address index
  * 
  * @attention      Accessing PUSH/PULL FIFO by PUSHX/PULLX register MUST
  *                 disable \e Overflow-and-Underflow-detection , Call
  *                  @ref CLB_disableFIFOsOverFlowDetection()
  */
void CLB_clearFIFOs (CLB_TypeDef *clb)
{
    uint16_t i;

    for(i = 0U; i < CLB_FIFO_SIZE; i++)
    {
        WRITE_REG(clb->PULLX[i].WORDVAL, 0);
    }

    WRITE_REG(clb->BUFPTR.WORDVAL, CLB_BUFPTR_PUSHCLR_M | CLB_BUFPTR_PULLCLR_M);
    WRITE_REG(clb->BUFPTR.WORDVAL, 0);
}

/**
  * @brief  Configure the FIFO registers.
  *         This function writes to the PULL FIFO. This also clears the FIFOs and
  *         its pointer using the CLB_clearFIFOs() API prior to writing to
  *         the FIFO.
  * @param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB2 base address index
  *                      - CLB3: CLB3 base address index
  *                      - CLB4: CLB4 base address index
  *                      - CLB5: CLB5 base address index
  *                      - CLB6: CLB6 base address index
  * @param  pullData    Pointer to an array of bytes which needs to be
  *                     written into the FIFO. The 0th FIFO data is in the 0th index.
  *
  * @attention      Accessing PUSH/PULL FIFO by PUSHX/PULLX register MUST
  *                 disable \e Overflow-and-Underflow-detection ,
  *                 @ref CLB_disableFIFOsOverFlowDetection()
  */
void CLB_writeFIFOs (CLB_TypeDef *clb, const uint32_t pullData[])
{
    /* Clear the FIFO and pointer */
    CLB_clearFIFOs(clb);

    /* Write data into the FIFO. */
    WRITE_REG(clb->PULLX[0].WORDVAL, pullData[0]);
    WRITE_REG(clb->PULLX[1].WORDVAL, pullData[1]);
    WRITE_REG(clb->PULLX[2].WORDVAL, pullData[2]);
    WRITE_REG(clb->PULLX[3].WORDVAL, pullData[3]);
}

/**
  * @brief  Read FIFO registers.
  *         This function reads from the PUSH FIFO. The 0th FIFO data would be in
  *         the 0th index.
  * @param  clb         The base address of a CLB tile's logic config register.
  *                      - CLB1: CLB1 base address index
  *                      - CLB2: CLB1 base address index
  *                      - CLB3: CLB1 base address index
  *                      - CLB4: CLB1 base address index
  *                      - CLB5: CLB1 base address index
  *                      - CLB6: CLB1 base address index
  * @param  pushData    Pointer to an array of bytes which needs to be
  *                     read from the FIFO.
  * 
  * @attention      Accessing PUSH/PULL FIFO by PUSHX/PULLX register MUST
  *                 disable \e Overflow-and-Underflow-detection ,
  *                 @ref CLB_disableFIFOsOverFlowDetection()
  */
void CLB_readFIFOs (CLB_TypeDef *clb, uint32_t pushData[])
{
    /* Read data from the FIFO. */
    pushData[0U] = READ_REG(clb->PUSHX[0].WORDVAL);
    pushData[1U] = READ_REG(clb->PUSHX[1].WORDVAL);
    pushData[2U] = READ_REG(clb->PUSHX[2].WORDVAL);
    pushData[3U] = READ_REG(clb->PUSHX[3].WORDVAL);
}
