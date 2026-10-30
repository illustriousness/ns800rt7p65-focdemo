/**
  * @file       gpio.c
  * @author     yangjun
  * @brief      Function file for NS800RT7xxx gpio module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "gpio.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
/** @defgroup GPIO_PRIVATE_VARIABLES UART Private Variables
  * @{
  * @brief  These private static variables do not need to be configured by the user
  */

/** @defgroup XINT_INDEX the index about XINT channel within XBAR
  * @{
  * @brief  This static constant array identifies about the index of XINT channel(N - 1)
  */
static const uint32_t xintIndex[5] = {3, 4, 5, 12, 13};

/**
  * @}
  */

/**
  * @}
  */


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
  * @brief  Sets the direction and mode of the specified pin
  * @param  port   GPIO port address
  *                 - GPIOA: GPIO A port
  *                 - GPIOB: GPIO B port
  *                 - GPIOC: GPIO C port
  *                 - GPIOC: GPIO D port
  *                 - GPIOC: GPIO E port
  *                 - GPIOC: GPIO F port
  *                 - GPIOC: GPIO G port
  *                 - GPIOH: GPIO H port
  * @param  pin    GPIO pin number
  *                 This parameter can be any value of @ref GPIO_PINNUM range from -1 to 1
  * @param  pinIO  GPIO pin direction mode
  *                 This parameter can be any value of @ref GPIO_DIRECTION
  */
void GPIO_setDirectionMode (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_Direction pinIO)
{
    if (pinIO == GPIO_DIR_MODE_IN)
    {
        CLEAR_BIT(port->DIR.WORDVAL, (0x1UL << pin));
    }
    else
    {
        SET_BIT(port->DIR.WORDVAL, (0x1UL << pin));
    }
}

/**
  * @brief  Gets the direction mode of one pin
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * @return Returns one of the enumerated data types described for GPIO_setDirectionMode()
  *                - GPIO_DIR_MODE_IN
  *                - GPIO_DIR_MODE_OUT
  */
GPIO_Direction GPIO_getDirectionMode (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    return READ_BIT(port->DIR.WORDVAL, (0x1UL << pin))? GPIO_DIR_MODE_OUT : GPIO_DIR_MODE_IN;
}

/**
  * @brief  Sets the pad configuration for the specified pin
  * @note   Multiple pin-type can be set together
  * @param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOC: GPIO D port
  *                   - GPIOC: GPIO E port
  *                   - GPIOC: GPIO F port
  *                   - GPIOC: GPIO G port
  *                   - GPIOH: GPIO H port
  * @param  pin      GPIO pin number
  *                   This parameter can be any value of @ref GPIO_PINNUM
  * @param  pinType  GPIO pin type
  *                   This parameter can be any value of @ref GPIO_PADCONFIG
  */
void GPIO_setPadConfig (GPIO_TypeDef *port, GPIO_PinNum pin, uint32_t pinType)
{
    uint32_t pinMask = (0x1UL << pin);

    /* Set input pull-xxx mode */
    if (pinType & GPIO_PIN_TYPE_PULLUP)
    {
        /* Set input pull-up mode */
        SET_BIT(port->PS.WORDVAL, pinMask);
        SET_BIT(port->PE.WORDVAL, pinMask);
    }
    else if (pinType & GPIO_PIN_TYPE_PULLDOWN)
    {
        /* Set input pull-down mode */
        CLEAR_BIT(port->PS.WORDVAL, pinMask);
        SET_BIT(port->PE.WORDVAL, pinMask);
    }
    else
    {
        /* Set input floating mode */
        CLEAR_BIT(port->PE.WORDVAL, pinMask);
    }
    /* Set input polarity */
    if (pinType & GPIO_PIN_TYPE_INVERT)
    {
        /* Set input invert polarity */
        SET_BIT(port->INV.WORDVAL, pinMask);
    }
    else
    {
        /* Set input normal polarity */
        CLEAR_BIT(port->INV.WORDVAL, pinMask);
    }
    /* Set output method */
    if (pinType & GPIO_PIN_TYPE_OD)
    {
        /* Set output OD mode */
        SET_BIT(port->ODR.WORDVAL, pinMask);
    }
    else
    {
        /* Set output PP mode */
        CLEAR_BIT(port->ODR.WORDVAL, pinMask);
    }
}

/**
  * @brief  Gets the pad configuration for the specified pin
  * @note   Multiple pin-type can be return together
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * @return Returns a bit field of the values
  *                This parameter can be any value of @ref GPIO_PADCONFIG
  */
uint32_t GPIO_getPadConfig (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    uint32_t pinType, pinMask = (0x1UL << pin);

    /* Get input pull-xxx mode */
    if (READ_BIT(port->PE.WORDVAL, pinMask))
    {
        if (READ_BIT(port->PS.WORDVAL, pinMask))
        {
            pinType = GPIO_PIN_TYPE_PULLUP;
        }
        else
        {
            pinType = GPIO_PIN_TYPE_PULLDOWN;
        }
    }
    else
    {
        pinType = GPIO_PIN_TYPE_STD;
    }
    /* Get input polarity */
    if (READ_BIT(port->INV.WORDVAL, pinMask))
    {
        pinType |= GPIO_PIN_TYPE_INVERT;
    }
    /* Get output method */
    if (READ_BIT(port->ODR.WORDVAL, pinMask))
    {
        pinType |= GPIO_PIN_TYPE_OD;
    }

    return pinType;
}

/**
  * @brief  Sets the qualification mode for the specified pin
  * @param  port           GPIO port address
  *                         - GPIOA: GPIO A port
  *                         - GPIOB: GPIO B port
  *                         - GPIOC: GPIO C port
  *                         - GPIOC: GPIO D port
  *                         - GPIOC: GPIO E port
  *                         - GPIOC: GPIO F port
  *                         - GPIOC: GPIO G port
  *                         - GPIOH: GPIO H port
  * @param  pin            GPIO pin number
  *                         This parameter can be any value of @ref GPIO_PINNUM
  * @param  qualification  GPIO qualification mode
  *                         This parameter can be any value of @ref GPIO_SMPMODE
  */
void GPIO_setQualificationMode (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_QualificationMode qualification)
{
    uint32_t temp;
    __IO uint32_t *addrQsel;

    temp = (pin > GPIO_PIN_15)? 1 : 0;
    addrQsel = (uint32_t *)(&(port->QSEL1) + temp);
    temp = (pin - (temp << 4)) << 1;
    MODIFY_REG(*addrQsel,  (0x3UL << temp), ((qualification & 0x3UL) << temp));
}

/**
  * @brief  Gets the qualification type for the specified pin
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * @return Returns the qualification mode in the form of one of the values
  */
GPIO_QualificationMode GPIO_getQualificationMode (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    uint32_t temp;
    __IO uint32_t *addrQsel;

    temp = (pin > GPIO_PIN_15)? 1 : 0;
    addrQsel = (uint32_t *)(&(port->QSEL1) + temp);
    temp = (pin - (temp << 4)) << 1;

    return (GPIO_QualificationMode)READ_BIT((*addrQsel) >> temp,  0x03UL);
}

/**
  * @brief  Sets the qualification mode for the specified pin
  * @param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOC: GPIO D port
  *                   - GPIOC: GPIO E port
  *                   - GPIOC: GPIO F port
  *                   - GPIOC: GPIO G port
  *                   - GPIOH: GPIO H port
  * @param  pin      GPIO pin number
  *                   This parameter can be any value of @ref GPIO_PINNUM
  * @param  divider  GPIO sampling divider
  *                   This parameter can be any value of @ref GPIO_SMPCLK
  */
void GPIO_setQualificationPeriod (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_SmpClk divider)
{
    uint32_t temp;

    temp = (uint32_t)pin & 0xFFFFFFF8UL;
    MODIFY_REG(port->CTRL.WORDVAL,  (0xFFUL << temp), ((divider & 0xFFUL) << temp));
}

/**
  * @brief  Selects the controller core of a specified pin
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * @param  core  GPIO is the core controller of the specified pin
  *                This parameter can be any value of @ref GPIO_CORESELECT
  */
void GPIO_setControllerCore (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_CoreSelect core)
{
    uint32_t temp;
    __IO uint32_t *addrCsel;

    temp = pin >> 3;
    addrCsel = (uint32_t *)(&(port->CSEL1) + temp);
    temp = (pin & 0x7) << 2;
    MODIFY_REG(*addrCsel, (0x1UL << temp), ((core & 0x1UL) << temp));
}

/**
  * @brief  Sets the drive strength for the specified pin
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * @param  lev   GPIO output drive strength
  *                This parameter can be any value of @ref GPIO_DRVLEV
  */
void GPIO_setDriveLevel (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_DrvLev lev)
{
    uint32_t temp;
    __IO uint32_t *addrDr;

    temp = (pin > GPIO_PIN_15)? 1 : 0;
    addrDr = (uint32_t *)(&(port->DR1) + temp);
    temp = (pin - (temp << 4)) << 1;
    MODIFY_REG(*addrDr,  (0x3UL << temp), ((lev & 0x3UL) << temp));
}

/**
  * @brief  Gets the drive strength for the specified pin
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  */
GPIO_DrvLev GPIO_getDriveLevel (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    uint32_t temp;
    __IO uint32_t *addrDr;

    temp = (pin > GPIO_PIN_15)? 1 : 0;
    addrDr = (uint32_t *)(&(port->DR1) + temp);
    temp = (pin - (temp << 4)) << 1;

    return (GPIO_DrvLev)READ_BIT((*addrDr) >> temp,  0x03UL);
}

/**
  * @brief  Sets the qualification mode for the specified pin
  * @param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * @param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * @param  mode  GPIO analog mode
  *                This parameter can be any value of @ref GPIO_ANALOGMODE
  */
void GPIO_setAnalogMode (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_AnalogMode mode)
{
    if (mode == GPIO_ANALOG_ENABLED)
    {
        SET_BIT(port->AMSEL.WORDVAL, (0x1UL << pin));
    }
    else
    {
        CLEAR_BIT(port->AMSEL.WORDVAL, (0x1UL << pin));
    }
}

/**
  * @brief  Configures the alternate function of one GPIO pin
  * @param  port       GPIO port address
  *                     - GPIOA: GPIO A port
  *                     - GPIOB: GPIO B port
  *                     - GPIOC: GPIO C port
  *                     - GPIOC: GPIO D port
  *                     - GPIOC: GPIO E port
  *                     - GPIOC: GPIO F port
  *                     - GPIOC: GPIO G port
  *                     - GPIOH: GPIO H port
  * @param  pin        GPIO pin number
  *                     This parameter can be any value of @ref GPIO_PINNUM
  * @param  pinConfig  GPIO alternate function
  *                     This parameter can be any value of @ref GPIO_ALTFUNC
  */
void GPIO_setPinConfig (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_AltFunc pinConfig)
{
    uint32_t temp;
    __IO uint32_t *addrMux, *addrGmux;

    temp = (pin > GPIO_PIN_15)? 1 : 0;
    addrMux  = (uint32_t *)(&(port->MUX1) + temp);
    addrGmux = (uint32_t *)(&(port->GMUX1) + temp);
    temp = (pin - (temp << 4)) << 1;
    CLEAR_BIT(*addrMux, (0x3UL << temp));
    MODIFY_REG(*addrGmux, (0x3UL << temp), (((pinConfig >> 2) & 0x3UL) << temp));
    SET_BIT(*addrMux, ((pinConfig & 0x3UL) << temp));
}

/**
  * @brief  Sets the external interrupt pin
  * @param  port      GPIO port address
  *                    - GPIOA: GPIO A port
  *                    - GPIOB: GPIO B port
  *                    - GPIOC: GPIO C port
  *                    - GPIOC: GPIO D port
  *                    - GPIOC: GPIO E port
  *                    - GPIOC: GPIO F port
  *                    - GPIOC: GPIO G port
  *                    - GPIOH: GPIO H port
  * @param pin        GPIO pin number
  *                    This parameter can be any value of @ref GPIO_PINNUM
  * @param extIntNum  GPIO external interrupt number
  *                    This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
void GPIO_setInterruptPin (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_ExternalIntNum extIntNum)
{
    __IO uint32_t *addrXbarInputSel;
    uint32_t pinIO;

    addrXbarInputSel = (uint32_t *)(&(XBAR->INPUTXSEL[xintIndex[(uint8_t)extIntNum]].WORDVAL));
    pinIO = (((uint32_t)port >> 5) & 0x000007E0UL) + (uint32_t)pin;
    WRITE_REG(*addrXbarInputSel, pinIO);
}
