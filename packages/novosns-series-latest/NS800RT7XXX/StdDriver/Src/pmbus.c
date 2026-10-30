/**
  * @file       pmbus.c
  * @author     Favian
  * @brief      Function file for NS800RT7xxx pmbus module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "pmbus.h"


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
  * @brief  This function set the scl count value for a particular speed mode
  *          (standard, fast) and clock phase (low, high).
  * @param  pmbus   Base address of PMBUS module.
  * @param  mode    Speed mode of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SPEEDMODE.
  * @param  phase   SCL phase of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SCLPHASE.
  * @param  count   Count value to set.
  * @note   The PMBUS must be disabled in order to set any of the scl count
  *         values.  The programmable value for any of these registers
  *         shown below:
  *         ______________________________________________________
  *         | PMBUS_SpeedMode | PMBUS_SclPhase | minimum | maximum |
  *         |        X        | PMBUS_SCL_HIGH |    6    | 0xFFF5  |
  *         |        X        | PMBUS_SCL_LOW  |    8    | 0xFFF5  |
  *         ------------------------------------------------------
  */
void PMBUS_setSclCount (
    PMBUS_TypeDef *pmbus, PMBUS_SpeedMode mode, PMBUS_SclPhase phase, uint16_t count)
{
    if(mode == PMBUS_SPEED_FAST)
    {
        if(phase == PMBUS_SCL_LOW)
            WRITE_REG(pmbus->FSLR.WORDVAL, count);
        else
            WRITE_REG(pmbus->FSHR.WORDVAL, count);
    }
    else if(mode == PMBUS_SPEED_STANDARD)
    {
        if(phase == PMBUS_SCL_LOW)
            WRITE_REG(pmbus->SSLR.WORDVAL, count);
        else
            WRITE_REG(pmbus->SSHR.WORDVAL, count);
    }
    else
    {
        /* never to here */
    }
}

/**
  * @brief  This function returns the current scl count value for all speed
  *         modes (standard, fast, high) and phases (low, high).
  * @param  pmbus   Base address of PMBUS module.
  * @param  mode    Speed mode of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SPEEDMODE.
  * @param  phase   SCL phase of count value to set.  This parameter can have one
  *                 enumeration value from @ref PMBUS_SCLPHASE.
  * @return The current specified scl count value.
  */
uint16_t PMBUS_getSclCount (
    PMBUS_TypeDef *pmbus, PMBUS_SpeedMode mode, PMBUS_SclPhase phase)
{
    uint16_t retval = 0;
    if(mode == PMBUS_SPEED_FAST)
    {
        if(phase == PMBUS_SCL_LOW)
            retval = READ_REG(pmbus->FSLR.WORDVAL);
        else
            retval = READ_REG(pmbus->FSHR.WORDVAL);
    }
    else if(mode == PMBUS_SPEED_STANDARD)
    {
        if(phase == PMBUS_SCL_LOW)
            retval = READ_REG(pmbus->SSLR.WORDVAL);
        else
            retval = READ_REG(pmbus->SSHR.WORDVAL);
    }
    else
    {
        /* never to here */
    }

    return retval;
}

/**
  * @brief  Clears specified PMBUS interrupt(s).  Only the following interrupts
  *         can be cleared in this fashion: rx_under, rx_over, tx_over, rd_req,
  *         tx_abrt, rx_done, activity, stop_det, start_det, gen_call.  Although
  *         they can be specified, the tx_empty interrupts cannot be
  *         cleared using this function.
  * @param  pmbus       Base address of PMBUS module.
  * @param  interrupts  Interrupt(s) to clear.
  *                     This parameter takes a bitwise OR combination of one or more
  *                     values from the @ref PMBUS_INTERRUPT.
  */
void PMBUS_clearInterruptStatus (PMBUS_TypeDef *pmbus, uint32_t interrupts)
{
    if (interrupts == PMBUS_INT_ALL)
    {
        READ_REG(pmbus->ICR.WORDVAL);
        return;
    }

    if ((interrupts & PMBUS_INT_RX_OVER) == PMBUS_INT_RX_OVER)
    {
        READ_REG(pmbus->CLRRXOV.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_RD_REQ) == PMBUS_INT_RD_REQ)
    {
        READ_REG(pmbus->CLRREQ.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_TX_ABRT) == PMBUS_INT_TX_ABRT)
    {
        READ_REG(pmbus->CLRTXABT.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_RX_DONE) == PMBUS_INT_RX_DONE)
    {
        READ_REG(pmbus->CLRRXDO.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_ACTIVITY) == PMBUS_INT_ACTIVITY)
    {
        READ_REG(pmbus->CLRACTY.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_STOP_DET) == PMBUS_INT_STOP_DET)
    {
        READ_REG(pmbus->CLRSTOP.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_START_DET) == PMBUS_INT_START_DET)
    {
        READ_REG(pmbus->CLRSTART.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_GEN_CALL) == PMBUS_INT_GEN_CALL)
    {
        READ_REG(pmbus->CLRGC.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_RESTART_DET) == PMBUS_INT_RESTART_DET)
    {
        READ_REG(pmbus->CLRRESTART.WORDVAL);
    }

    if ((interrupts & PMBUS_INT_SCL_LOW) == PMBUS_INT_SCL_LOW)
    {
        READ_REG(pmbus->CLRSCLL.WORDVAL);
    }
}
