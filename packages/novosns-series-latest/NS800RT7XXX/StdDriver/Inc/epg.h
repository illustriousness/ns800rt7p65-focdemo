/**
  * @file       epg.h
  * @author     Alex-J
  * @brief      Header file for NS800RTxxx epg module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __EPG_H__
#define __EPG_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_epg.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup EPG_EXPORTED_TYPES EPG Exported Types
 * @{
 * @brief  Macro definitions are used with all files publicly about 'EPG' module.
 */

/** @defgroup EPG_GCTL0_REGBIT EPG GCTL0 register bits
 * @{
 * @brief  Macro definitions about EPG GCTL0 register bits definition.
 */
#define EPG_GCTL0_EN            (0x1UL)       /*!< Enable EPG */
#define EPG_GCTL0_DMA_EN        (0x2UL)       /*!< Enable EPG DMA */
#define EPG_GCTL0_EPGOUT0SEL    (0x100UL)     /*!< EPG output 0 Clock/signal select */
#define EPG_GCTL0_EPGOUT1SEL    (0x200UL)     /*!< EPG output 1 Clock/signal select */
#define EPG_GCTL0_EPGOUT2SEL    (0x400UL)     /*!< EPG output 2 Clock/signal select */
#define EPG_GCTL0_EPGOUT3SEL    (0x800UL)     /*!< EPG output 3 Clock/signal select */
#define EPG_GCTL0_EPGOUT4SEL    (0x1000UL)    /*!< EPG output 4 Clock/signal select */
#define EPG_GCTL0_EPGOUT5SEL    (0x2000UL)    /*!< EPG output 5 Clock/signal select */
#define EPG_GCTL0_EPGOUT6SEL    (0x4000UL)    /*!< EPG output 6 Clock/signal select */
#define EPG_GCTL0_EPGOUT7SEL    (0x8000UL)    /*!< EPG output 7 Clock/signal select */

/**
 * @}
 */

/** @defgroup EPG_GCTL1_REGBIT EPG GCTL1 register bits
 * @{
 * @brief  Macro definitions about EPG GCTL1 register bits definition.
 */
#define EPG_GCTL1_SIGGEN0_CLKSEL_S    (0UL)
#define EPG_GCTL1_SIGGEN0_CLKSEL_M    (0x7UL)    /*!< Clock source select of SIGGEN0 */

/**
 * @}
 */

/** @defgroup EPG_GCTL2_REGBIT EPG GCTL2 register bits
 * @{
 * @brief  Macro definitions about EPG GCTL2 register bits definition.
 */
#define EPG_GCTL2_EPGOUT0_CLKOUTSEL_S    (0UL)             /*!< GCTL2_EPGOUT0_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT0_CLKOUTSEL_M    (0x7UL)           /*!< Selects the clock signal source of EPG output 0. */
#define EPG_GCTL2_EPGOUT1_CLKOUTSEL_S    (4UL)             /*!< GCTL2_EPGOUT1_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT1_CLKOUTSEL_M    (0x70UL)          /*!< Selects the clock signal source of EPG output 1. */
#define EPG_GCTL2_EPGOUT2_CLKOUTSEL_S    (8UL)             /*!< GCTL2_EPGOUT2_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT2_CLKOUTSEL_M    (0x700UL)         /*!< Selects the clock signal source of EPG output 2. */
#define EPG_GCTL2_EPGOUT3_CLKOUTSEL_S    (12UL)            /*!< GCTL2_EPGOUT3_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT3_CLKOUTSEL_M    (0x7000UL)        /*!< Selects the clock signal source of EPG output 3. */
#define EPG_GCTL2_EPGOUT4_CLKOUTSEL_S    (16UL)            /*!< GCTL2_EPGOUT4_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT4_CLKOUTSEL_M    (0x70000UL)       /*!< Selects the clock signal source of EPG output 4. */
#define EPG_GCTL2_EPGOUT5_CLKOUTSEL_S    (20UL)            /*!< GCTL2_EPGOUT5_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT5_CLKOUTSEL_M    (0x700000UL)      /*!< Selects the clock signal source of EPG output 5. */
#define EPG_GCTL2_EPGOUT6_CLKOUTSEL_S    (24UL)            /*!< GCTL2_EPGOUT6_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT6_CLKOUTSEL_M    (0x7000000UL)     /*!< Selects the clock signal source of EPG output 6. */
#define EPG_GCTL2_EPGOUT7_CLKOUTSEL_S    (28UL)            /*!< GCTL2_EPGOUT7_CLKOUTSEL Bit Position */
#define EPG_GCTL2_EPGOUT7_CLKOUTSEL_M    (0x70000000UL)    /*!< Selects the clock signal source of EPG output 7. */

/**
 * @}
 */

/** @defgroup EPG_GCTL3_REGBIT EPG GCTL3 register bits
 * @{
 * @brief  Macro definitions about EPG GCTL3 register bits definition.
 */
#define EPG_GCTL3_EPGOUT0_SIGOUTSEL_S    (0UL)             /*!< GCTL3_EPGOUT0_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT0_SIGOUTSEL_M    (0x7UL)           /*!< Selects the signal source of EPG output 0. */
#define EPG_GCTL3_EPGOUT1_SIGOUTSEL_S    (4UL)             /*!< GCTL3_EPGOUT1_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT1_SIGOUTSEL_M    (0x70UL)          /*!< Selects the signal source of EPG output 1. */
#define EPG_GCTL3_EPGOUT2_SIGOUTSEL_S    (8UL)             /*!< GCTL3_EPGOUT2_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT2_SIGOUTSEL_M    (0x700UL)         /*!< Selects the signal source of EPG output 2. */
#define EPG_GCTL3_EPGOUT3_SIGOUTSEL_S    (12UL)            /*!< GCTL3_EPGOUT3_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT3_SIGOUTSEL_M    (0x7000UL)        /*!< Selects the signal source of EPG output 3. */
#define EPG_GCTL3_EPGOUT4_SIGOUTSEL_S    (16UL)            /*!< GCTL3_EPGOUT4_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT4_SIGOUTSEL_M    (0x70000UL)       /*!< Selects the signal source of EPG output 4. */
#define EPG_GCTL3_EPGOUT5_SIGOUTSEL_S    (20UL)            /*!< GCTL3_EPGOUT5_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT5_SIGOUTSEL_M    (0x700000UL)      /*!< Selects the signal source of EPG output 5. */
#define EPG_GCTL3_EPGOUT6_SIGOUTSEL_S    (24UL)            /*!< GCTL3_EPGOUT6_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT6_SIGOUTSEL_M    (0x7000000UL)     /*!< Selects the signal source of EPG output 6. */
#define EPG_GCTL3_EPGOUT7_SIGOUTSEL_S    (28UL)            /*!< GCTL3_EPGOUT7_SIGOUTSEL Bit Position */
#define EPG_GCTL3_EPGOUT7_SIGOUTSEL_M    (0x70000000UL)    /*!< Selects the signal source of EPG output 7. */

/**
 * @}
 */

/** @defgroup EPG_LOCK_REGBIT EPG LOCK register bits
 * @{
 * @brief  Macro definitions about EPG LOCK register bits definition.
 */
#define EPG_LOCK_GCTL0           (0x1UL)     /*!< GCTL0 Lock bit */
#define EPG_LOCK_GCTL1           (0x2UL)     /*!< GCTL1 Lock bit */
#define EPG_LOCK_GCTL2           (0x4UL)     /*!< GCTL2 Lock bit */
#define EPG_LOCK_GCTL3           (0x8UL)     /*!< GCTL3 Lock bit */
#define EPG_LOCK_CLKDIV0_CTL0    (0x10UL)    /*!< CLKDIV0_CTL0 Lock bit */
#define EPG_LOCK_CLKDIV1_CTL0    (0x20UL)    /*!< CLKDIV1_CTL0 Lock bit */
#define EPG_LOCK_SIGGEN0_CTL0    (0x40UL)    /*!< SIGGEN0_CTL0 Lock bit */
#define EPG_LOCK_SIGGEN0_CTL1    (0x80UL)    /*!< SIGGEN0_CTL1 Lock bit */

/**
 * @}
 */

/** @defgroup EPG_COMMIT_REGBIT EPG COMMIT register bits
 * @{
 * @brief  Macro definitions about EPG COMMIT register bits definition.
 */
#define EPG_COMMIT_GCTL0           (0x1UL)     /*!< GCTL0 Commit bit */
#define EPG_COMMIT_GCTL1           (0x2UL)     /*!< GCTL1 Commit bit */
#define EPG_COMMIT_GCTL2           (0x4UL)     /*!< GCTL2 Commit bit */
#define EPG_COMMIT_GCTL3           (0x8UL)     /*!< GCTL3 Commit bit */
#define EPG_COMMIT_CLKDIV0_CTL0    (0x10UL)    /*!< CLKDIV0_CTL0 Commit bit */
#define EPG_COMMIT_CLKDIV1_CTL0    (0x20UL)    /*!< CLKDIV1_CTL0 Commit bit */
#define EPG_COMMIT_SIGGEN0_CTL0    (0x40UL)    /*!< SIGGEN0_CTL0 Commit bit */
#define EPG_COMMIT_SIGGEN0_CTL1    (0x80UL)    /*!< SIGGEN0_CTL1 Commit bit */

/**
 * @}
 */

/** @defgroup EPG_GINTSTS_REGBIT EPG GINTSTS register bits
 * @{
 * @brief  Macro definitions about EPG GINTSTS register bits definition.
 */
#define EPG_GINTSTS_INT             (0x1UL)    /*!< Global interrupt flag register */
#define EPG_GINTSTS_SIGGEN0_DONE    (0x2UL)    /*!< SIGGEN0 operation done interrupt enable */
#define EPG_GINTSTS_SIGGEN0_FILL    (0x4UL)    /*!< SIGGEN0 data fill interrupt enable */

/**
 * @}
 */

/** @defgroup EPG_GINTEN_REGBIT EPG GINTEN register bits
 * @{
 * @brief  Macro definitions about EPG GINTEN register bits definition.
 */
#define EPG_GINTEN_SIGGEN0_DONE    (0x2UL)    /*!< SIGGEN0 operation done interrupt enable */
#define EPG_GINTEN_SIGGEN0_FILL    (0x4UL)    /*!< SIGGEN0 data fill interrupt enable */

/**
 * @}
 */

/** @defgroup EPG_GINTCLR_REGBIT EPG GINTCLR register bits
 * @{
 * @brief  Macro definitions about EPG GINTCLR register bits definition.
 */
#define EPG_GINTCLR_INT             (0x1UL)    /*!< Global interrupt flag clear */
#define EPG_GINTCLR_SIGGEN0_DONE    (0x2UL)    /*!< SIGGEN0 operation done interrupt flag clear */
#define EPG_GINTCLR_SIGGEN0_FILL    (0x4UL)    /*!< SIGGEN0 data fill interrupt flag clear */

/**
 * @}
 */

/** @defgroup EPG_GINTFRC_REGBIT EPG GINTFRC register bits
 * @{
 * @brief  Macro definitions about EPG GINTFRC register bits definition.
 */
#define EPG_GINTFRC_SIGGEN0_DONE    (0x2UL)    /*!< SIGGEN0 operation done interrupt flag set */
#define EPG_GINTFRC_SIGGEN0_FILL    (0x4UL)    /*!< SIGGEN0 data fill interrupt flag set */

/**
 * @}
 */

/** @defgroup EPG_CLKDIV0_CTL0_REGBIT EPG CLKDIV0_CTL0 register bits
 * @{
 * @brief  Macro definitions about EPG CLKDIV0_CTL0 register bits definition.
 */
#define EPG_CLKDIV0_CTL0_PRD_S        (0UL)          /*!< CTL0_PRD Bit Position */
#define EPG_CLKDIV0_CTL0_PRD_M        (0xFFUL)       /*!< Clock divider value */
#define EPG_CLKDIV0_CTL0_CLKSTOP_S    (16UL)         /*!< CTL0_CLKSTOP Bit Position */
#define EPG_CLKDIV0_CTL0_CLKSTOP_M    (0x70000UL)    /*!< Clock Stop Configuration */

/**
 * @}
 */

/** @defgroup EPG_CLKDIV0_CLKOFFSET_REGBIT EPG CLKDIV0_CLKOFFSET register bits
 * @{
 * @brief  Macro definitions about EPG CLKDIV0_CLKOFFSET register bits definition.
 */
#define EPG_CLKDIV0_CLKOFFSET_CLK0OFFSET_S    (0UL)             /*!< CLK0OFFSET Bit Position */
#define EPG_CLKDIV0_CLKOFFSET_CLK0OFFSET_M    (0xFFUL)          /*!< Clock output 0 offset delay value. */
#define EPG_CLKDIV0_CLKOFFSET_CLK1OFFSET_S    (8UL)             /*!< CLK1OFFSET Bit Position */
#define EPG_CLKDIV0_CLKOFFSET_CLK1OFFSET_M    (0xFF00UL)        /*!< Clock output 0 offset delay value. */
#define EPG_CLKDIV0_CLKOFFSET_CLK2OFFSET_S    (16UL)            /*!< CLK2OFFSET Bit Position */
#define EPG_CLKDIV0_CLKOFFSET_CLK2OFFSET_M    (0xFF0000UL)      /*!< Clock output 0 offset delay value. */
#define EPG_CLKDIV0_CLKOFFSET_CLK3OFFSET_S    (24UL)            /*!< CLK3OFFSET Bit Position */
#define EPG_CLKDIV0_CLKOFFSET_CLK3OFFSET_M    (0xFF000000UL)    /*!< Clock output 0 offset delay value. */

/**
 * @}
 */

/** @defgroup EPG_CLKDIV1_CTL0_REGBIT EPG CLKDIV1_CTL0 register bits
 * @{
 * @brief  Macro definitions about EPG CLKDIV1_CTL0 register bits definition.
 */
#define EPG_CLKDIV1_CTL0_PRD_S        (0UL)          /*!< CTL0_PRD Bit Position */
#define EPG_CLKDIV1_CTL0_PRD_M        (0xFFUL)       /*!< Clock divider value */
#define EPG_CLKDIV1_CTL0_CLKSTOP_S    (16UL)         /*!< CTL0_CLKSTOP Bit Position */
#define EPG_CLKDIV1_CTL0_CLKSTOP_M    (0x70000UL)    /*!< Clock Stop Configuration */

/**
 * @}
 */

/** @defgroup EPG_CLKDIV1_CLKOFFSET_REGBIT EPG CLKDIV1_CLKOFFSET register bits
 * @{
 * @brief  Macro definitions about EPG CLKDIV1_CLKOFFSET register bits definition.
 */
#define EPG_CLKDIV1_CLKOFFSET_CLK0OFFSET_S    (0UL)             /*!< CLK0OFFSET Bit Position */
#define EPG_CLKDIV1_CLKOFFSET_CLK0OFFSET_M    (0xFFUL)          /*!< Clock output 0 offset delay value. */
#define EPG_CLKDIV1_CLKOFFSET_CLK1OFFSET_S    (8UL)             /*!< CLK1OFFSET Bit Position */
#define EPG_CLKDIV1_CLKOFFSET_CLK1OFFSET_M    (0xFF00UL)        /*!< Clock output 0 offset delay value. */
#define EPG_CLKDIV1_CLKOFFSET_CLK2OFFSET_S    (16UL)            /*!< CLK2OFFSET Bit Position */
#define EPG_CLKDIV1_CLKOFFSET_CLK2OFFSET_M    (0xFF0000UL)      /*!< Clock output 0 offset delay value. */
#define EPG_CLKDIV1_CLKOFFSET_CLK3OFFSET_S    (24UL)            /*!< CLK3OFFSET Bit Position */
#define EPG_CLKDIV1_CLKOFFSET_CLK3OFFSET_M    (0xFF000000UL)    /*!< Clock output 0 offset delay value. */

/**
 * @}
 */

/** @defgroup EPG_SIGGEN0_CTL0_REGBIT EPG SIGGEN0_CTL0 register bits
 * @{
 * @brief  Macro definitions about EPG SIGGEN0_CTL0 register bits definition.
 */
#define EPG_SIGGEN0_CTL0_MODE_S         (0UL)           /*!< CTL0_MODE Bit Position */
#define EPG_SIGGEN0_CTL0_MODE_M         (0xFUL)         /*!< Signal generator modes */
#define EPG_SIGGEN0_CTL0_EN             (0x10UL)        /*!< Signal generator enable */
#define EPG_SIGGEN0_CTL0_BRIN           (0x20UL)        /*!< Reverse bits before transform */
#define EPG_SIGGEN0_CTL0_BROUT          (0x40UL)        /*!< Reverse bits after transform */
#define EPG_SIGGEN0_CTL0_BITLENGTH_S    (16UL)          /*!< CTL0_BITLENGTH Bit Position */
#define EPG_SIGGEN0_CTL0_BITLENGTH_M    (0xFF0000UL)    /*!< Length of bit stream */

/**
 * @}
 */

/** @defgroup EPG_SIGGEN0_CTL1_REGBIT EPG SIGGEN0_CTL1 register bits
 * @{
 * @brief  Macro definitions about EPG SIGGEN0_CTL1 register bits definition.
 */
#define EPG_SIGGEN0_CTL1_DATA0_INSEL_S     (0UL)             /*!< CTL1_DATA0_INSEL Bit Position */
#define EPG_SIGGEN0_CTL1_DATA0_INSEL_M     (0xFUL)           /*!< Select the source of DATA[0] bit. */
#define EPG_SIGGEN0_CTL1_DATA63_INSEL_S    (28UL)            /*!< CTL1_DATA63_INSEL Bit Position */
#define EPG_SIGGEN0_CTL1_DATA63_INSEL_M    (0xF0000000UL)    /*!< Select the source of DATA[63] bit. */

/**
 * @}
 */

/** @defgroup EPG_MXSEL0_REGBIT EPG MXSEL0 register bits
 * @{
 * @brief  Macro definitions about EPG MXSEL0 register bits definition.
 */
#define EPG_MXSEL0_SEL0     (0x1UL)           /*!< DATAOUT[0] mux select. */
#define EPG_MXSEL0_SEL1     (0x2UL)           /*!< DATAOUT[1] mux select. */
#define EPG_MXSEL0_SEL2     (0x4UL)           /*!< DATAOUT[2] mux select. */
#define EPG_MXSEL0_SEL3     (0x8UL)           /*!< DATAOUT[3] mux select. */
#define EPG_MXSEL0_SEL4     (0x10UL)          /*!< DATAOUT[4] mux select. */
#define EPG_MXSEL0_SEL5     (0x20UL)          /*!< DATAOUT[5] mux select. */
#define EPG_MXSEL0_SEL6     (0x40UL)          /*!< DATAOUT[6] mux select. */
#define EPG_MXSEL0_SEL7     (0x80UL)          /*!< DATAOUT[7] mux select. */
#define EPG_MXSEL0_SEL8     (0x100UL)         /*!< DATAOUT[8] mux select. */
#define EPG_MXSEL0_SEL9     (0x200UL)         /*!< DATAOUT[9] mux select. */
#define EPG_MXSEL0_SEL10    (0x400UL)         /*!< DATAOUT[10] mux select. */
#define EPG_MXSEL0_SEL11    (0x800UL)         /*!< DATAOUT[11] mux select. */
#define EPG_MXSEL0_SEL12    (0x1000UL)        /*!< DATAOUT[12] mux select. */
#define EPG_MXSEL0_SEL13    (0x2000UL)        /*!< DATAOUT[13] mux select. */
#define EPG_MXSEL0_SEL14    (0x4000UL)        /*!< DATAOUT[14] mux select. */
#define EPG_MXSEL0_SEL15    (0x8000UL)        /*!< DATAOUT[15] mux select. */
#define EPG_MXSEL0_SEL16    (0x10000UL)       /*!< DATAOUT[16] mux select. */
#define EPG_MXSEL0_SEL17    (0x20000UL)       /*!< DATAOUT[17] mux select. */
#define EPG_MXSEL0_SEL18    (0x40000UL)       /*!< DATAOUT[18] mux select. */
#define EPG_MXSEL0_SEL19    (0x80000UL)       /*!< DATAOUT[19] mux select. */
#define EPG_MXSEL0_SEL20    (0x100000UL)      /*!< DATAOUT[20] mux select. */
#define EPG_MXSEL0_SEL21    (0x200000UL)      /*!< DATAOUT[21] mux select. */
#define EPG_MXSEL0_SEL22    (0x400000UL)      /*!< DATAOUT[22] mux select. */
#define EPG_MXSEL0_SEL23    (0x800000UL)      /*!< DATAOUT[23] mux select. */
#define EPG_MXSEL0_SEL24    (0x1000000UL)     /*!< DATAOUT[24] mux select. */
#define EPG_MXSEL0_SEL25    (0x2000000UL)     /*!< DATAOUT[25] mux select. */
#define EPG_MXSEL0_SEL26    (0x4000000UL)     /*!< DATAOUT[26] mux select. */
#define EPG_MXSEL0_SEL27    (0x8000000UL)     /*!< DATAOUT[27] mux select. */
#define EPG_MXSEL0_SEL28    (0x10000000UL)    /*!< DATAOUT[28] mux select. */
#define EPG_MXSEL0_SEL29    (0x20000000UL)    /*!< DATAOUT[29] mux select. */
#define EPG_MXSEL0_SEL30    (0x40000000UL)    /*!< DATAOUT[30] mux select. */
#define EPG_MXSEL0_SEL31    (0x80000000UL)    /*!< DATAOUT[31] mux select. */

/**
 * @}
 */

/** @defgroup EPG_MXSEL1_REGBIT EPG MXSEL1 register bits
 * @{
 * @brief  Macro definitions about EPG MXSEL1 register bits definition.
 */
#define EPG_MXSEL1_SEL32    (0x1UL)           /*!< DATAOUT[32] mux select. */
#define EPG_MXSEL1_SEL33    (0x2UL)           /*!< DATAOUT[33] mux select. */
#define EPG_MXSEL1_SEL34    (0x4UL)           /*!< DATAOUT[34] mux select. */
#define EPG_MXSEL1_SEL35    (0x8UL)           /*!< DATAOUT[35] mux select. */
#define EPG_MXSEL1_SEL36    (0x10UL)          /*!< DATAOUT[36] mux select. */
#define EPG_MXSEL1_SEL37    (0x20UL)          /*!< DATAOUT[37] mux select. */
#define EPG_MXSEL1_SEL38    (0x40UL)          /*!< DATAOUT[38] mux select. */
#define EPG_MXSEL1_SEL39    (0x80UL)          /*!< DATAOUT[39] mux select. */
#define EPG_MXSEL1_SEL40    (0x100UL)         /*!< DATAOUT[40] mux select. */
#define EPG_MXSEL1_SEL41    (0x200UL)         /*!< DATAOUT[41] mux select. */
#define EPG_MXSEL1_SEL42    (0x400UL)         /*!< DATAOUT[42] mux select. */
#define EPG_MXSEL1_SEL43    (0x800UL)         /*!< DATAOUT[43] mux select. */
#define EPG_MXSEL1_SEL44    (0x1000UL)        /*!< DATAOUT[44] mux select. */
#define EPG_MXSEL1_SEL45    (0x2000UL)        /*!< DATAOUT[45] mux select. */
#define EPG_MXSEL1_SEL46    (0x4000UL)        /*!< DATAOUT[46] mux select. */
#define EPG_MXSEL1_SEL47    (0x8000UL)        /*!< DATAOUT[47] mux select. */
#define EPG_MXSEL1_SEL48    (0x10000UL)       /*!< DATAOUT[48] mux select. */
#define EPG_MXSEL1_SEL49    (0x20000UL)       /*!< DATAOUT[49] mux select. */
#define EPG_MXSEL1_SEL50    (0x40000UL)       /*!< DATAOUT[50] mux select. */
#define EPG_MXSEL1_SEL51    (0x80000UL)       /*!< DATAOUT[51] mux select. */
#define EPG_MXSEL1_SEL52    (0x100000UL)      /*!< DATAOUT[52] mux select. */
#define EPG_MXSEL1_SEL53    (0x200000UL)      /*!< DATAOUT[53] mux select. */
#define EPG_MXSEL1_SEL54    (0x400000UL)      /*!< DATAOUT[54] mux select. */
#define EPG_MXSEL1_SEL55    (0x800000UL)      /*!< DATAOUT[55] mux select. */
#define EPG_MXSEL1_SEL56    (0x1000000UL)     /*!< DATAOUT[56] mux select. */
#define EPG_MXSEL1_SEL57    (0x2000000UL)     /*!< DATAOUT[57] mux select. */
#define EPG_MXSEL1_SEL58    (0x4000000UL)     /*!< DATAOUT[58] mux select. */
#define EPG_MXSEL1_SEL59    (0x8000000UL)     /*!< DATAOUT[59] mux select. */
#define EPG_MXSEL1_SEL60    (0x10000000UL)    /*!< DATAOUT[60] mux select. */
#define EPG_MXSEL1_SEL61    (0x20000000UL)    /*!< DATAOUT[61] mux select. */
#define EPG_MXSEL1_SEL62    (0x40000000UL)    /*!< DATAOUT[62] mux select. */
#define EPG_MXSEL1_SEL63    (0x80000000UL)    /*!< DATAOUT[63] mux select. */

/**
 * @}
 */

/** @defgroup EPG_MXSELLOCK_REGBIT EPG MXSELLOCK register bits
 * @{
 * @brief  Macro definitions about EPG MXSELLOCK register bits definition.
 */
#define EPG_MXSELLOCK_EPGMXSEL0    (0x1UL)    /*!< EPGMXSEL0 lock bit */
#define EPG_MXSELLOCK_EPGMXSEL1    (0x2UL)    /*!< EPGMXSEL1 lock bit */

/**
 * @}
 */

/** @defgroup EPG_MXSELCOMMIT_REGBIT EPG MXSELCOMMIT register bits
 * @{
 * @brief  Macro definitions about EPG MXSELCOMMIT register bits definition.
 */
#define EPG_MXSELCOMMIT_EPGMXSEL0    (0x1UL)    /*!< EPGMXSEL0 commit bit */
#define EPG_MXSELCOMMIT_EPGMXSEL1    (0x2UL)    /*!< EPGMXSEL1 commit bit */

/**
 * @}
 */

/** @defgroup EPG_INT_REGBIT EPG Interrupt Register Bits
 * @{
 * @brief  Interrupt Flags that can be passed to EPG_enableInterruptFlag(),
 *         EPG_diableInterruptFlag, EPG_forceInterruptFlag, EPG_clearInterruptFlag
 *         as \e intFlags parameter.
 */
#define EPG_INT_SIGGEN0_DONE    (0x2UL)    /*!< Signal Generator 0 Operation Done */
#define EPG_INT_SIGGEN0_FILL    (0x4UL)    /*!< Signal Generator 0 Data Fill */

/**
 * @}
 */

/** @defgroup EPG_LOCK_REGFLAG EPG Lock Register Flags
 * @{
 * @brief  Register Flags that can be passed to EPG_releaseLockReg,
 *         EPG_LockReg, EPG_commitRegLock as \e regFlags parameter.
 */
#define EPG_LOCK_REG_GCTL0           (0x1UL)     /*!< GCTL0 Register */
#define EPG_LOCK_REG_GCTL1           (0x2UL)     /*!< GCTL1 Register */
#define EPG_LOCK_REG_GCTL2           (0x4UL)     /*!< GCTL2 Register */
#define EPG_LOCK_REG_GCTL3           (0x8UL)     /*!< GCTL3 Register */
#define EPG_LOCK_REG_CLKDIV0_CTL0    (0x10UL)    /*!< CLK divider 0 CTL0 Register */
#define EPG_LOCK_REG_CLKDIV1_CTL0    (0x20UL)    /*!< CLK divider 1 CTL0 Register */
#define EPG_LOCK_REG_SIGGEN0_CTL0    (0x40UL)    /*!< Signal gen 0 CTL0 Register */
#define EPG_LOCK_REG_SIGGEN0_CTL1    (0x80UL)    /*!< Signal gen 0 CTL1 Register */

/**
 * @}
 */

/** @defgroup EPG_MX_SEL_LOCK_REGFLAG EPG MX_SEL_LOCK Register Flags
 * @{
 * @brief  Register Flags that can be passed to EPG_releaseLockMXSelReg,
 *         EPG_lockMXSelReg, EPG_commitMXSelRegLock as \e regFlags parameter.
 */
#define EPG_MX_SEL_LOCK_REG_MXSEL0    (0x1UL)    /*!< Mux Select 0 Register */

/**
 * @}
 */

/** @defgroup EPG_USEFUL_DEF EPG Useful Defines
 * @{
 * @brief  Useful defines used within the driver functions. Not intended for use by
 *         application code.
 */
#define EPG_GCTL0_EPGOUTSEL_S    (8UL)        /*!< EPGOUTSEL Bit Position */
#define EPG_GCTL0_EPGOUTSEL_M    (0xFF00U)    /*!< EPG Output Select Mask */

/**
 * @}
 */

/** @defgroup EPG_OUTPUTSELECT EPG Output Select
 * @{
 * @brief  Values that can be passed to EPG_selectGlobalOutput() as the \e gPinOutSel
 *         parameter.
 */
typedef enum {
    EPG_OUT_SEL_SIG = 0x0U,    /*!< Signal Generator mux output */
    EPG_OUT_SEL_CLK            /*!< Clock Generator mux output */
} EPG_OutputSelect;

/**
 * @}
 */

/** @defgroup EPG_SIGNALGENOUT EPG Signal Generator Output
 * @{
 * @brief  Values that can be passed to EPG_selectSignalOutput() as the
 *         \e sigGenOutput parameter.
 */
typedef enum {
    EPG_SIGGEN0_DATATRANOUT0 = 0x0U,    /*!< Signal Generator 0 Data Transform out 0 */
    EPG_SIGGEN0_DATATRANOUT1,           /*!< Signal Generator 0 Data Transform out 1 */
    EPG_SIGGEN0_DATATRANOUT2,           /*!< Signal Generator 0 Data Transform out 2 */
    EPG_SIGGEN0_DATATRANOUT3,           /*!< Signal Generator 0 Data Transform out 3 */
    EPG_SIGGEN0_DATATRANOUT4,           /*!< Signal Generator 0 Data Transform out 4 */
    EPG_SIGGEN0_DATATRANOUT5,           /*!< Signal Generator 0 Data Transform out 5 */
    EPG_SIGGEN0_DATATRANOUT6,           /*!< Signal Generator 0 Data Transform out 6 */
    EPG_SIGGEN0_DATATRANOUT7            /*!< Signal Generator 0 Data Transform out 7 */
} EPG_SignalGenOut;

/**
 * @}
 */

/** @defgroup EPG_CLOCKGENOUT EPG Clock Generator Output
 * @{
 * @brief  Values that can be passed to EPG_selectClkOutput()
 *         as the \e clkGenOutput parameter.
 */
typedef enum {
    EPG_CLKGEN0_CLKOUT0_DCLK = 0x0U,    /*!< Clock Generator 0 Clk output 0 DCLK */
    EPG_CLKGEN0_CLKOUT1_DCLK,           /*!< Clock Generator 0 Clk output 1 DCLK */
    EPG_CLKGEN0_CLKOUT2_DCLK,           /*!< Clock Generator 0 Clk output 2 DCLK */
    EPG_CLKGEN0_CLKOUT3_DCLK,           /*!< Clock Generator 0 Clk output 3 DCLK */
    EPG_CLKGEN1_CLKOUT0_DCLK,           /*!< Clock Generator 1 Clk output 0 DCLK */
    EPG_CLKGEN1_CLKOUT1_DCLK,           /*!< Clock Generator 1 Clk output 1 DCLK */
    EPG_CLKGEN1_CLKOUT2_DCLK,           /*!< Clock Generator 1 Clk output 2 DCLK */
    EPG_CLKGEN1_CLKOUT3_DCLK            /*!< Clock Generator 1 Clk output 3 DCLK */
} EPG_ClockGenOut;

/**
 * @}
 */

/** @defgroup EPG_CLOCKGENGCLKOUT EPG Clock Generator GCLK Output
 * @{
 * @brief  Values that can be passed to EPG_selectSigGenClkSource()
 *         as the \e clkGenOutput parameter.
 */
typedef enum {
    EPG_CLKGEN0_CLKOUT0_GCLK = 0x0U,    /*!< Clock Generator 0 Clk output 0 GCLK */
    EPG_CLKGEN0_CLKOUT1_GCLK,           /*!< Clock Generator 0 Clk output 1 GCLK */
    EPG_CLKGEN0_CLKOUT2_GCLK,           /*!< Clock Generator 0 Clk output 2 GCLK */
    EPG_CLKGEN0_CLKOUT3_GCLK,           /*!< Clock Generator 0 Clk output 3 GCLK */
    EPG_CLKGEN1_CLKOUT0_GCLK,           /*!< Clock Generator 1 Clk output 0 GCLK */
    EPG_CLKGEN1_CLKOUT1_GCLK,           /*!< Clock Generator 1 Clk output 1 GCLK */
    EPG_CLKGEN1_CLKOUT2_GCLK,           /*!< Clock Generator 1 Clk output 2 GCLK */
    EPG_CLKGEN1_CLKOUT3_GCLK            /*!< Clock Generator 1 Clk output 3 GCLK */
} EPG_ClockGenGclkOut;

/**
 * @}
 */

/** @defgroup EPG_CLOCKSTOPEDGE EPG Clock Stop Edge
 * @{
 * @brief  Values that can be passed to EPG_setClkGenStopEdge(),
 *         as the \e stopEdge parameter.
 */
typedef enum {
    EPG_CLK_STOP_EDGE_CLKOUT0 = 0x000U,    /*!< Stop on Clk output 0 */
    EPG_CLK_STOP_EDGE_CLKOUT1 = 0x010U,    /*!< Stop on Clk output 1 */
    EPG_CLK_STOP_EDGE_CLKOUT2 = 0x100U,    /*!< Stop on Clk output 2 */
    EPG_CLK_STOP_EDGE_CLKOUT3 = 0x110U     /*!< Stop on Clk output 3 */
} EPG_ClockStopEdge;

/**
 * @}
 */

/** @defgroup EPG_SIGNALGENMODE EPG Signal Generator Mode
 * @{
 * @brief  Values that can be passed to EPG_setSignalGenMode(),
 *         as the \e sigGenMode parameter.
 */
typedef enum {
    EPG_SIGGEN_MODE_BIT_BANG = 0x0U,        /*!< BIT BANG MODE */
    EPG_SIGGEN_MODE_SHIFT_RIGHT_ONCE,       /*!< SHIFT RIGHT ONCE MODE */
    EPG_SIGGEN_MODE_ROTATE_RIGHT_ONCE,      /*!< ROTATE RIGHT ONCE MODE */
    EPG_SIGGEN_MODE_ROTATE_RIGHT_REPEAT,    /*!< ROTATE RIGHT REPEAT MODE */
    EPG_SIGGEN_MODE_SHIFT_LEFT_ONCE,        /*!< SHIFT LEFT ONCE MODE */
    EPG_SIGGEN_MODE_ROTATE_LEFT_ONCE,       /*!< ROTATE LEFT ONCE MODE */
    EPG_SIGGEN_MODE_ROTATE_LEFT_REPEAT,     /*!< ROTATE LEFT REPEAT */
    EPG_SIGGEN_MODE_SHIFT_RIGHT_REPEAT,     /*!< SHIFT RIGHT REPEAT MODE */
    EPG_SIGGEN_MODE_SHIFT_LEFT_REPEAT       /*!< SHIGT LEFT REPEAT MODE */
} EPG_SignalGenMode;

/**
 * @}
 */

/** @defgroup EPG_SIGNALGENDATA0IN EPG Signal Generator Data0 Input
 * @{
 * @brief  Values that can be passed to EPG_setData0In(),
 *         as the \e data0Input parameter.
 */
typedef enum {
    EPG_SIGGEN_DATA0_DATA_NEXT0 = 0x0U,    /*!< DATA TRANSFORM NEXT[0] */
    EPG_SIGGEN_DATA0_EPGIN0,               /*!< EPG Input 0 */
    EPG_SIGGEN_DATA0_EPGIN1,               /*!< EPG Input 1 */
    EPG_SIGGEN_DATA0_EPGIN2,               /*!< EPG Input 2 */
    EPG_SIGGEN_DATA0_EPGIN3,               /*!< EPG Input 3 */
    EPG_SIGGEN_DATA0_EPGIN4,               /*!< EPG Input 4 */
    EPG_SIGGEN_DATA0_EPGIN5,               /*!< EPG Input 5 */
    EPG_SIGGEN_DATA0_EPGIN6,               /*!< EPG Input 6 */
    EPG_SIGGEN_DATA0_EPGIN7                /*!< EPG Input 7 */
} EPG_SignalGenData0In;

/**
 * @}
 */

/** @defgroup EPG_SIGNALGENDATA63IN EPG Signal Generator Data63 Input
 * @{
 * @brief  Values that can be passed to EPG_setData63In(),
 *         as the \e data63Input parameter.
 */
typedef enum {
    EPG_SIGGEN_DATA63_DATA_NEXT63 = 0x0U,    /*!< DATA TRANSFORM NEXT[63] */
    EPG_SIGGEN_DATA63_EPGIN0,                /*!< EPG Input 0 */
    EPG_SIGGEN_DATA63_EPGIN1,                /*!< EPG Input 1 */
    EPG_SIGGEN_DATA63_EPGIN2,                /*!< EPG Input 2 */
    EPG_SIGGEN_DATA63_EPGIN3,                /*!< EPG Input 3 */
    EPG_SIGGEN_DATA63_EPGIN4,                /*!< EPG Input 4 */
    EPG_SIGGEN_DATA63_EPGIN5,                /*!< EPG Input 5 */
    EPG_SIGGEN_DATA63_EPGIN6,                /*!< EPG Input 6 */
    EPG_SIGGEN_DATA63_EPGIN7                 /*!< EPG Input 7 */
} EPG_SignalGenData63In;

/**
 * @}
 */

/** @defgroup EPG_OUT EPG Output
 * @{
 * @brief  Values that can be passed to EPG_selectEPGOutput(), EPG_selectClkOutput,
 *         EPG_selectSignalOutput as the \e gPinNum parameter.
 */
typedef enum {
    EPG_OUT0 = 0x0U,     /*!< EPG Output 0 */
    EPG_OUT1 = 0x4U,     /*!< EPG Output 1 */
    EPG_OUT2 = 0x8U,     /*!< EPG Output 2 */
    EPG_OUT3 = 0xCU,     /*!< EPG Output 3 */
    EPG_OUT4 = 0x10U,    /*!< EPG Output 4 */
    EPG_OUT5 = 0x14U,    /*!< EPG Output 5 */
    EPG_OUT6 = 0x18U,    /*!< EPG Output 6 */
    EPG_OUT7 = 0x1CU     /*!< EPG Output 7 */
} EPG_OUT;

/**
 * @}
 */

/** @defgroup EPG_SIGGEN EPG Signal Generator
 * @{
 * @brief  Values that can be used for \e sigGenNum parameter.
 */
typedef enum {
    EPG_SIGGEN0 = 0x0U    /*!< Signal Generator 0 */
} EPG_SIGGEN;

/**
 * @}
 */

/** @defgroup EPG_CLKGEN EPG Clock Generator
 * @{
 * @brief  Values that can be used for \e clkGenNum parameter.
 */
typedef enum
{
    EPG_CLKGEN0 = 0x0U,    /*!< Clock Generator 0 */
    EPG_CLKGEN1            /*!< Clock Generator 1 */
} EPG_CLKGEN;

/**
 * @}
 */

/** @defgroup EPG_DATAIN EPG Data Input
 * @{
 * @brief  Values that can be passed to EPG_selectEPGDataOut(),
 *         as the \e dataIn parameter.
 */
typedef enum {
    EPG_DATAIN_CANARX  = 0,     /*!< CANA Receive input (RX) */
    EPG_DATAIN_MCANARX,         /*!< MCANA Receive input (RX) */
    EPG_DATAIN_SD1C1   = 19,    /*!< SDFM1 C1 input */
    EPG_DATAIN_SD1C2,           /*!< SDFM1 C2 input */
    EPG_DATAIN_SD1C3,           /*!< SDFM1 C3 input */
    EPG_DATAIN_SD1C4,           /*!< SDFM1 C4 input */
    EPG_DATAIN_SD2C1,           /*!< SDFM2 C1 input */
    EPG_DATAIN_SD2C2,           /*!< SDFM2 C2 input */
    EPG_DATAIN_SD2C3,           /*!< SDFM2 C3 input */
    EPG_DATAIN_SD2C4            /*!< SDFM2 C4 input */
} EPG_DataIn;

/**
 * @}
 */

/** @defgroup EPG_DATAOUTSEL EPG Data Output Select
 * @{
 * @brief  Values that can be passed to EPG_selectEPGDataOut(),
 *         as the \e dataOutSel parameter.
 */
typedef enum {
    EPG_DATAOUT_DATAIN = 0x0U, /*!< Input Data */
    EPG_DATAOUT_EPGOUT         /*!< EPG output */
} EPG_DataOutSel;

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
 * \brief  Enable EPG and starts signal and clock generator
 * \note   This function enables the EPG module and starts signal and clock generator.
 *
 * \param  epg  epg pointer to a EPG_TypeDef structure
 *                 - EPG: EPG base address index
 */
static inline void EPG_enableGlobal (EPG_TypeDef *epg)
{
    SET_BIT(epg->GCTL0.WORDVAL, EPG_GCTL0_EN);
}

/**
 * \brief  Disable EPG and stops signal and clock generator
 * \note   This function disables the EPG module and stops signal and clock generator.
 *
 * \param  epg  epg pointer to a EPG_TypeDef structure
 *                 - EPG: EPG base address index
 */
static inline void EPG_disableGlobal (EPG_TypeDef *epg)
{
    CLEAR_BIT(epg->GCTL0.WORDVAL, (uint32_t)EPG_GCTL0_EN);
}

/**
 * \brief  Enable EPG module DMA
 * \note   This function enables the EPG module DMA.
 *
 * \param  epg  epg pointer to a EPG_TypeDef structure
 *                 - EPG: EPG base address index
 */
static inline void EPG_enableDMA (EPG_TypeDef *epg)
{
    SET_BIT(epg->GCTL0.WORDVAL, EPG_GCTL0_DMA_EN);
}

/**
 * \brief  Disable EPG module DMA
 * \note   This function disables the EPG module DMA.
 *
 * \param  epg  epg pointer to a EPG_TypeDef structure
 *                 - EPG: EPG base address index
 */
static inline void EPG_disableDMA (EPG_TypeDef *epg)
{
    CLEAR_BIT(epg->GCTL0.WORDVAL, (uint32_t)EPG_GCTL0_DMA_EN);
}

/**
 * \brief  Select the EPG output source
 * \note   This function selects the global EPG output source to be clock or signal.
 *         This output can then be routed to any GPIO through xbar, mux sel.
 *
 * \param  epg         epg pointer to a EPG_TypeDef structure
 *                        - EPG: EPG base address index
 * \param  gPinNum     the global EPG Output number.
 * \param  gPinOutSel  the mux output of the \e gPinNum.
 */
static inline void EPG_selectEPGOutput (EPG_TypeDef *epg, EPG_OUT gPinNum, EPG_OutputSelect gPinOutSel)
{
    uint16_t regOffset = (uint16_t)(gPinNum >> 2) + EPG_GCTL0_EPGOUTSEL_S;

    MODIFY_REG(epg->GCTL0.WORDVAL, (1UL << regOffset), ((uint32_t)gPinOutSel << regOffset));
}

/**
 * \brief  Select the individual EPG pin signal data output
 * \note   This function selects the individual EPG pin's signal generator data output.
 *         This output can then be routed to EPG global output by selecting signal
 *         generator as source for that pin.
 *
 * \param  epg           epg pointer to a EPG_TypeDef structure
 *                          - EPG: EPG base address index
 * \param  gPinNum       the global EPG Output number.
 * \param  sigGenOutput  the mux output of the \e gPinNum signal generators data output.
 */
static inline void EPG_selectSignalOutput (EPG_TypeDef *epg, EPG_OUT gPinNum, EPG_SignalGenOut sigGenOutput)
{
    MODIFY_REG(epg->GCTL3.WORDVAL, ((uint32_t)EPG_GCTL3_EPGOUT0_SIGOUTSEL_M << gPinNum),
               ((uint32_t)sigGenOutput << gPinNum));
}

/**
 * \brief  Select the individual EPG pin clock data output
 * \note   This function selects the individual EPG pin's clock generator data output.
 *         This output can then be routed to EPG global output by selecting clock
 *         generator as source for that pin.
 *
 * \param  epg           epg pointer to a EPG_TypeDef structure
 *                          - EPG: EPG base address index
 * \param  gPinNum       the global EPG Output number.
 * \param  clkGenOutput  the mux output of the \e gPinNum clock generators data output.
 */
static inline void EPG_selectClkOutput (EPG_TypeDef *epg, EPG_OUT gPinNum, EPG_ClockGenOut clkGenOutput)
{
    MODIFY_REG(epg->GCTL2.WORDVAL, ((uint32_t)EPG_GCTL2_EPGOUT0_CLKOUTSEL_M << gPinNum),
               ((uint32_t)clkGenOutput << gPinNum));
}

/**
 * \brief  Select the signal generator's clock source
 * \note   This function selects the signal generator's clock source.
 *         This clock source is used to generate the periodic or aperiodic signals by
 *         the signal generator.
 *
 * \param  epg           epg pointer to a EPG_TypeDef structure
 *                          - EPG: EPG base address index
 * \param  sigGenNum     the Signal generator number whose clk source is being
 *                       configured based on the availability.
 * \param  clkGenOutput  the mux output of the \e gPinNum clock generators data
 *                       output to be selected as source.
 */
static inline void EPG_selectSigGenClkSource (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, EPG_ClockGenGclkOut clkGenOutput)
{
    (void)sigGenNum;
    MODIFY_REG(epg->GCTL1.WORDVAL, ((uint32_t)EPG_GCTL1_SIGGEN0_CLKSEL_M), ((uint32_t)clkGenOutput));
}

/**
 * \brief  Set the clock generator period
 * \note   This function Sets the clock generator's period
 *         Clock divider counter counts up to \e periodValue and snaps back to 0.
 *
 * \param  epg          epg pointer to a EPG_TypeDef structure
 *                         - EPG: EPG base address index
 * \param  clkGenNum    the clock generator number which is being configured.
 * \param  periodValue  the mux output of the \e gPinNum clock generators data
 *                      output to be selected as source.
 */
static inline void EPG_setClkGenPeriod (EPG_TypeDef *epg, EPG_CLKGEN clkGenNum, uint32_t periodValue)
{
    if (clkGenNum == EPG_CLKGEN0)
    {
        MODIFY_REG(epg->CLKDIV0CTL0.WORDVAL, ((uint32_t)EPG_CLKDIV0_CTL0_PRD_M), periodValue);
    }
    else
    {
        MODIFY_REG(epg->CLKDIV1CTL0.WORDVAL, ((uint32_t)EPG_CLKDIV0_CTL0_PRD_M), periodValue);
    }
}

/**
 * \brief  Set the clock generator stop value
 * \note   This Determines on which of the CLKOUTs edge clock generation is stopped
 *         following a clear of SIGGEN1_CTL0.EN.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  clkGenNum  the clock generator number which is being configured.
 * \param  stopEdge   the Edge signal at which clock stops.
 */
static inline void EPG_setClkGenStopEdge (EPG_TypeDef *epg, EPG_CLKGEN clkGenNum, EPG_ClockStopEdge stopEdge)
{
    if (clkGenNum == EPG_CLKGEN0)
    {
        MODIFY_REG(epg->CLKDIV0CTL0.WORDVAL, ((uint32_t)EPG_CLKDIV0_CTL0_CLKSTOP_M),
                   ((uint32_t)stopEdge << EPG_CLKDIV0_CTL0_CLKSTOP_S));
    }
    else
    {
        MODIFY_REG(epg->CLKDIV1CTL0.WORDVAL, ((uint32_t)EPG_CLKDIV0_CTL0_CLKSTOP_M),
                   ((uint32_t)stopEdge << EPG_CLKDIV0_CTL0_CLKSTOP_S));
    }
}

/**
 * \brief  Set the clock generator clock offset
 * \note   This function Sets the clock generator output's offset.
 *         This Determines number of source clock cycles by which the divided clock
 *         output is delayed.
 *
 * \param  epg              epg pointer to a EPG_TypeDef structure
 *                             - EPG: EPG base address index
 * \param  clkGenNum        the clock generator number which is being configured.
 * \param  clkGenOutputNum  the output number of particular clock generator
 *                          whose offset is being set. it can take values from 0 to 3 inclusive.
 * \param  offsetValue      the offset value in number of system clk cycles
 */
static inline void EPG_setClkGenOffset (EPG_TypeDef *epg, EPG_CLKGEN clkGenNum, uint32_t clkGenOutputNum,
                                        uint32_t offsetValue)
{
    if (clkGenNum == EPG_CLKGEN0)
    {
        MODIFY_REG(epg->CLKDIV0CLKOFFSET.WORDVAL,
                   ((uint32_t)EPG_CLKDIV0_CLKOFFSET_CLK0OFFSET_M << (clkGenOutputNum << 3)),
                   ((uint32_t)offsetValue << (clkGenOutputNum << 3)));
    }
    else
    {
        MODIFY_REG(epg->CLKDIV1CLKOFFSET.WORDVAL,
                   ((uint32_t)EPG_CLKDIV0_CLKOFFSET_CLK0OFFSET_M << (clkGenOutputNum << 3)),
                   ((uint32_t)offsetValue << (clkGenOutputNum << 3)));
    }
}

/**
 * \brief  Enable EPG signal generator
 * \note   This function enables the Signal generator after which the signal generator
 *         functions as per the mode definition.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is enabled.
 */
static inline void EPG_enableSignalGen (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;
    SET_BIT(epg->SIGGEN0CTL0.WORDVAL, EPG_SIGGEN0_CTL0_EN);
}

/**
 * \brief  Disable EPG signal generator
 * \note   This function Disables the Signal generator and stops its operation.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is disabled.
 */
static inline void EPG_disableSignalGen (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;
    CLEAR_BIT(epg->SIGGEN0CTL0.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL0_EN);
}

/**
 * \brief  Set EPG signal generator Mode
 * \note   This function Sets the EPG signal generator's Mode.
 *         This mode effects the operation of the signal generator on the DATA input.
 *
 * \param  epg         epg pointer to a EPG_TypeDef structure
 *                        - EPG: EPG base address index
 * \param  sigGenNum   the Signal generator number which is beign configured.
 * \param  sigGenMode  the Signal generator mode being set.
 */
static inline void EPG_setSignalGenMode (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, EPG_SignalGenMode sigGenMode)
{
    (void)sigGenNum;
    MODIFY_REG(epg->SIGGEN0CTL0.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL0_MODE_M, (uint32_t)sigGenMode);
}

/**
 * \brief  Perform bit reversal on input of signal generator
 * \note   This function set's signal generator to Perform bit reversal on input.
 *         This results in bit reversal on data input of data transform block.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 */
static inline void EPG_enableBitRevOnDataIn (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;
    SET_BIT(epg->SIGGEN0CTL0.WORDVAL, EPG_SIGGEN0_CTL0_BRIN);
}

/**
 * \brief  Disable bit reversal on input of signal generator
 * \note   This function set's signal generator to disable bit reversal on input.
 *         This results in no bit reversal on data input of data transform block.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 */
static inline void EPG_disableBitRevOnDataIn (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;
    CLEAR_BIT(epg->SIGGEN0CTL0.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL0_BRIN);
}

/**
 * \brief  Perform bit reversal on output of signal generator
 * \note   This function set's signal generator to Perform bit reversal on output.
 *         This results in bit reversal on data output of data transform block.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 */
static inline void EPG_enableBitRevOnDataOut (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;
    SET_BIT(epg->SIGGEN0CTL0.WORDVAL, EPG_SIGGEN0_CTL0_BROUT);
}

/**
 * \brief  Disable bit reversal on output of signal generator
 * \note   This function set's signal generator to disable bit reversal on output.
 *         This results in no bit reversal on data output of data transform block.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 */
static inline void EPG_disableBitRevOnDataOut (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;
    CLEAR_BIT(epg->SIGGEN0CTL0.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL0_BROUT);
}

/**
 * \brief  Set EPG signal generators data bit length
 * \note   This function Sets EPG signal generators data bit length.
 *         This defines the number bits which participates in the shift rotate
 *         operations.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 * \param  bitLength  the number of bits of the signal generator input data
 */
static inline void EPG_setDataBitLen (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, uint32_t bitLength)
{
    (void)sigGenNum;
    MODIFY_REG(epg->SIGGEN0CTL0.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL0_BITLENGTH_M,
               (uint32_t)(bitLength << EPG_SIGGEN0_CTL0_BITLENGTH_S));
}

/**
 * \brief  Set EPG signal generator data bit 0 input
 * \note   This function Sets EPG signal generator data bit 0 input.
 *         This provides the ability to capture the data.
 *
 * \param  epg         epg pointer to a EPG_TypeDef structure
 *                        - EPG: EPG base address index
 * \param  sigGenNum   the Signal generator number which is beign configured.
 * \param  data0Input  the source input of bit 0 of Data Register.
 */
static inline void EPG_setData0In (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, EPG_SignalGenData0In data0Input)
{
    (void)sigGenNum;
    MODIFY_REG(epg->SIGGEN0CTL1.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL1_DATA0_INSEL_M, (uint32_t)(data0Input));
}

/**
 * \brief  Set EPG signal generator data bit 63 input
 * \note   This function Sets EPG signal generator data bit 63 input.
 *         This provides the ability to capture the data.
 *
 * \param  epg          epg pointer to a EPG_TypeDef structure
 *                         - EPG: EPG base address index
 * \param  sigGenNum    the Signal generator number which is beign configured.
 * \param  data63Input  the source input of bit 63 of Data Register.
 */
static inline void EPG_setData63In (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, EPG_SignalGenData63In data63Input)
{
    (void)sigGenNum;
    MODIFY_REG(epg->SIGGEN0CTL1.WORDVAL, (uint32_t)EPG_SIGGEN0_CTL1_DATA63_INSEL_M,
               (uint32_t)(data63Input << EPG_SIGGEN0_CTL1_DATA63_INSEL_S));
}

/**
 * \brief  Write EPG signal generator data 0 [0:31] input
 * \note   This function Writes EPG signal generator data 0 [0:31] input.
 *         This is the Data used in signal bit stream.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 * \param  data0      the first 32 bits of Data Register.
 */
static inline void EPG_setData0Word (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, uint32_t data0)
{
    (void)sigGenNum;
    WRITE_REG(epg->SIGGEN0DATA0.WORDVAL, (uint32_t)data0);
}

/**
 * \brief  Write EPG signal generator data 1 [32:63] input
 * \note   This function Writes EPG signal generator data 1 [32:63] input.
 *         This is the Data used in signal bit stream.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 * \param  data1      the last 32 bits of 63 bit Data Register.
 */
static inline void EPG_setData1Word (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum, uint32_t data1)
{
    (void)sigGenNum;
    WRITE_REG(epg->SIGGEN0DATA1.WORDVAL, (uint32_t)data1);
}

/**
 * \brief  Get EPG signal generator data 0 active register [0:31] value
 * \note   This function Reads EPG signal generator data 0 active [0:31] value
 *         which is the Data resulted from the transformation.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 *
 * \return Returns the Data 0 Active register value.
 */
static inline uint32_t EPG_getData0ActiveReg (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;

    return (epg->SIGGEN0DATA0ACTIVE.WORDVAL);
}

/**
 * \brief  Get EPG signal generator data 1 active register [32:64] value
 * \note   This function Reads EPG signal generator data 1 active [32:64] value
 *         which is the Data resulted from the transformation.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  sigGenNum  the Signal generator number which is beign configured.
 *
 * \return Returns the Data 1 Active register value.
 */
static inline uint32_t EPG_getData1ActiveReg (EPG_TypeDef *epg, EPG_SIGGEN sigGenNum)
{
    (void)sigGenNum;

    return (epg->SIGGEN0DATA1ACTIVE.WORDVAL);
}

/**
 * \brief  Enable the EPG interrupt sources
 * \note   This function enables the indicated EPG interrupt sources. Only the
 *         sources that are enabled can be reflected to the processor interrupt.
 *         Disabled sources have no effect on the processor.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  intFlags  a bit mask of the interrupt sources to be enabled.
 */
static inline void EPG_enableInterruptFlag (EPG_TypeDef *epg, uint32_t intFlags)
{
    SET_BIT(epg->GINTEN.WORDVAL, intFlags);
}

/**
 * \brief  Disables the EPG interrupt sources
 * \note   This function enables the indicated EPG interrupt sources. Only the
 *         sources that are enabled can be reflected to the processor interrupt.
 *         Disabled sources have no effect on the processor.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  intFlags  a bit mask of the interrupt sources to be disabled.
 */
static inline void EPG_disableInterruptFlag (EPG_TypeDef *epg, uint32_t intFlags)
{
    CLEAR_BIT(epg->GINTEN.WORDVAL, intFlags);
}

/**
 * \brief  Get the EPG interrupt sources
 * \note   This function returns the EPG interrupt sources that are active.
 *
 * \param  epg  epg pointer to a EPG_TypeDef structure
 *                 - EPG: EPG base address index
 *
 * \return Returns the bit mask of the interrupt sources which are currently triggered.
 */
static inline uint32_t EPG_getInterruptStatus (EPG_TypeDef *epg)
{
    return (epg->GINTSTS.WORDVAL);
}

/**
 * \brief  Clear EPG Interrupt Sources
 * \note   This function clears the indicated EPG interrupt sources if pending.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  intFlags  a bit mask of the interrupt sources to be clear.
 */
static inline void EPG_clearInterruptFlag (EPG_TypeDef *epg, uint32_t intFlags)
{
    WRITE_REG(epg->GINTCLR.WORDVAL, intFlags);
}

/**
 * \brief  Force EPG Interrupt Sources
 * \note   This function triggers the indicated EPG interrupt sources. Only the
 *         sources that are enabled can be reflected to the processor interrupt.
 *         Disabled sources have no effect on the processor.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  intFlags  a bit mask of the interrupt sources to be trigger.
 */
static inline void EPG_forceInterruptFlag (EPG_TypeDef *epg, uint32_t intFlags)
{
    WRITE_REG(epg->GINTFRC.WORDVAL, intFlags);
}

/**
 * \brief  Lock EPG Register
 * \note   This function Locks EPG Register from being written further.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  regFlags  a bit mask of the EPG registers that need to locked.
 */
static inline void EPG_lockReg (EPG_TypeDef *epg, uint32_t regFlags)
{
    SET_BIT(epg->EPGLOCK.WORDVAL, regFlags);
}

/**
 * \brief  Release Locks of EPG Register
 * \note   This function Releases Locks of EPG Register so they can be overwritten.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  regFlags  a bit mask of EPG registers whose lock to be released.
 */
static inline void EPG_releaseLockReg (EPG_TypeDef *epg, uint32_t regFlags)
{
    CLEAR_BIT(epg->EPGLOCK.WORDVAL, regFlags);
}

/**
 * \brief  Commit EPG registers Lock
 * \note   This function Commits Locks of EPG lock register so that the EPG locks
 *         cannot be removed.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  regFlags  a bit mask of EPG registers whose lock to be commited.
 */
static inline void EPG_commitRegLock (EPG_TypeDef *epg, uint32_t regFlags)
{
    SET_BIT(epg->EPGCOMMIT.WORDVAL, regFlags);
}

/**
 * \brief  EPG Mux Select Register-0 Configuration
 * \note   This function config EPG Mux Sel Register-0 every bit field.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  regFields  a bit mask of the EPG Mux Select registers.
 *                       - N = <0,...,31>
 *                       - if Bit<N> = 0, EPG Mux Select DATAIN[N]
 *                       - if Bit<N> = 1, EPG Mux Select EPGOUT[N%8]
 */
static inline void EPG_configMXSel0Reg (EPG_TypeDef *epg, uint32_t regFields)
{
    MODIFY_REG(epg->EPGMXSEL0.WORDVAL, 0xFFFFFFFF, regFields);
}

/**
 * \brief  EPG Mux Select Register-1 Configuration
 * \note   This function config EPG Mux Sel Register-1 every bit field.
 *
 * \param  epg        epg pointer to a EPG_TypeDef structure
 *                       - EPG: EPG base address index
 * \param  regFields  a bit mask of the EPG Mux Select registers.
 *                       - N = <0,...,31>
 *                       - if Bit<N> = 0, EPG Mux Select DATAIN[N+32]
 *                       - if Bit<N> = 1, EPG Mux Select EPGOUT[N%8]
 */
static inline void EPG_configMXSel1Reg (EPG_TypeDef *epg, uint32_t regFields)
{
    MODIFY_REG(epg->EPGMXSEL1.WORDVAL, 0xFFFFFFFF, regFields);
}

/**
 * \brief  Lock EPG Mux Select Register
 * \note   This function Locks EPG Mux Select Register from being written further.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  regFlags  a bit mask of the EPG Mux Select registers.
 */
static inline void EPG_lockMXSelReg (EPG_TypeDef *epg, uint32_t regFlags)
{
    SET_BIT(epg->EPGMXSELLOCK.WORDVAL, regFlags);
}

/**
 * \brief  Release Locks of EPG Mux Select Register
 * \note   This function Releases Locks of EPG Mux Sel Registers to allow overwriting
 *         the registers.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  regFlags  a bit mask of the EPG Mux Select registers.
 */
static inline void EPG_releaseLockMXSelReg (EPG_TypeDef *epg, uint32_t regFlags)
{
    CLEAR_BIT(epg->EPGMXSELLOCK.WORDVAL, regFlags);
}

/**
 * \brief  Commit EPG Mux Select Registers Lock
 * \note   This function Commits the Locks of EPG Mux Sel Registers so that the locks
 *         cannot be updated further.
 *
 * \param  epg       epg pointer to a EPG_TypeDef structure
 *                      - EPG: EPG base address index
 * \param  regFlags  a bit mask of the EPG Mux Select registers.
 */
static inline void EPG_commitMXSelRegLock (EPG_TypeDef *epg, uint32_t regFlags)
{
    SET_BIT(epg->EPGMXSELCOMMIT.WORDVAL, regFlags);
}

/**
 * \brief  Select EPG Data Output
 * \note   This function selects EPG Modules's Final Data Output which can be used to
 *         feed EPG outputs to inputs of certain IPs or bypass the IP's input as is.
 *
 * \param  epg         epg pointer to a EPG_TypeDef structure
 *                        - EPG: EPG base address index
 * \param  dataIn      the bit of EPG Data Input to be configured.
 * \param  dataOutSel  the source of \e dataOutBit to configure.
 */
extern void EPG_selectEPGDataOut (EPG_TypeDef *epg, EPG_DataIn dataIn, EPG_DataOutSel dataOutSel);


#ifdef __cplusplus
}
#endif


#endif /* __EPG_H__ */
