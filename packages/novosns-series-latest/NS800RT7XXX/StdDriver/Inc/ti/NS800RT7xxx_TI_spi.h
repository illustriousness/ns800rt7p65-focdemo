/**
  * @file       NS800RT7xxx_TI_spi.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx spi module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_SPI_H__
#define __NS800RT7XXX_TI_SPI_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
  * Definitions
******************************************************************************/
/* The following are defines for the SPI register offsets */
#define SPI_O_SPDR      0x0UL     /*!< SPDR Register*/
#define SPI_O_SPDLR     0x4UL     /*!< SPDLR Register*/
#define SPI_O_SPCR1     0x8UL     /*!< SPCR1 Register */
#define SPI_O_SPCR2     0xCUL     /*!< SPCR2 Register */
#define SPI_O_SPCR3     0x10UL    /*!< SPCR3 Register */
#define SPI_O_SPCMD0    0x14UL    /*!< SPCMD0 Register */
#define SPI_O_SPCMD1    0x18UL    /*!< SPCMD1 Register */
#define SPI_O_SPCMD2    0x1CUL    /*!< SPCMD2 Register */
#define SPI_O_SPCMD3    0x20UL    /*!< SPCMD3 Register */
#define SPI_O_SPCMD4    0x24UL    /*!< SPCMD4 Register */
#define SPI_O_SPCMD5    0x28UL    /*!< SPCMD5 Register */
#define SPI_O_SPCMD6    0x2CUL    /*!< SPCMD6 Register */
#define SPI_O_SPCMD7    0x30UL    /*!< SPCMD7 Register*/
#define SPI_O_SPDCR1    0x40UL    /*!< SPDCR1 Register */
#define SPI_O_SPDCR2    0x44UL    /*!< SPDCR2 Register */
#define SPI_O_SPSR      0x50UL    /*!< SPSR Register */
#define SPI_O_SPTFSR    0x58UL    /*!< SPTFSR Register */
#define SPI_O_SPRFSR    0x5CUL    /*!< SPRFSR Register */
#define SPI_O_SPPSR     0x60UL    /*!< SPPSR Register */
#define SPI_O_SPSCR     0x68UL    /*!< SPSCR Register */
#define SPI_O_SPFCR     0x6CUL    /*!< SPFCR Register */

/* The following are defines for the bit fileds in the SPCR1 register definition*/
#define SPI_SPCR1_SPE        0x1UL           /*!< SPCR1 SPE */
#define SPI_SPCR1_SPPE       0x100UL         /*!< SPCR1 SPPE */
#define SPI_SPCR1_SPOE       0x200UL         /*!< SPCR1 SPOE */
#define SPI_SPCR1_PTE        0x800UL         /*!< SPCR1 PTE */
#define SPI_SPCR1_CLKASE     0x1000UL        /*!< SPCR1 SCKASE */
#define SPI_SPCR1_BFDS       0x2000UL        /*!< SPCR1 BFDS */
#define SPI_SPCR1_MODFEN     0x4000UL        /*!< SPCR1 MODFEN */
#define SPI_SPCR1_SPEIE      0x10000UL       /*!< SPCR1 SPEIE */
#define SPI_SPCR1_SPRIE      0x20000UL       /*!< SPCR1 SPRIE */
#define SPI_SPCR1_SPIIE      0x40000UL       /*!< SPCR1 SPIIE */
#define SPI_SPCR1_SPDRES     0x80000UL       /*!< SPCR1 SPDRES */
#define SPI_SPCR1_SPTIE      0x100000UL      /*!< SPCR1 SPTIE */
#define SPI_SPCR1_CENDIE     0x200000UL      /*!< SPCR1 CENDIE */
#define SPI_SPCR1_RXDMAEN    0x400000UL      /*!< SPCR1 RXDMAEN */
#define SPI_SPCR1_TXDMAEN    0x800000UL      /*!< SPCR1 TXDMAEN */
#define SPI_SPCR1_SPMS       0x1000000UL     /*!< SPCR1 SPMS */
#define SPI_SPCR1_MSTR       0x40000000UL    /*!< SPCR1 MSTR */

/* The following are defines for the bit fileds in the SPCR2 register definition*/
#define SPI_SPCR2_RMEDTG     0x40UL        /*!< SPCR2 RMEDTG */
#define SPI_SPCR2_RMSTTG     0x80UL        /*!< SPCR2 RMSTTG */
#define SPI_SPCR2_SPLP1      0x10000UL     /*!< SPCR2 SPLP1 */
#define SPI_SPCR2_SPLP2      0x20000UL     /*!< SPCR2 SPLP2 */
#define SPI_SPCR2_SPOM       0x40000UL     /*!< SPCR2 SPOM */
#define SPI_SPCR2_MOIFV      0x100000UL    /*!< SPCR2 MOIFV */
#define SPI_SPCR2_MOIFE      0x200000UL    /*!< SPCR2 MOIFE */

/* The following are defines for the bit fileds in the SPCR3 register definition*/
#define SPI_SPCR3_NSSP       0x1UL          /*!< SPCR3 NSSP */

/* The following are defines for the bit fileds in the SPCMD0--7 register definition*/
#define SPI_SPCMD_CPHA      0x1UL         /*!< SPCMD CPHA */
#define SPI_SPCMD_CPOL      0x2UL         /*!< SPCMD CPOL */
#define SPI_SPCMD_BRDV_S    2UL           /*!< SPCMD BRDV Shift */
#define SPI_SPCMD_BRDV_M    0xCUL         /*!< SPCMD BRDV Mask */
#define SPI_SPCMD_NSSKP     0x80UL        /*!< SPCMD NSSKP */
#define SPI_SPCMD_LSBF      0x1000UL      /*!< SPCMD LSBF */
#define SPI_SPCMD_SPNDEN    0x2000UL      /*!< SPCMD SPNDEN */
#define SPI_SPCMD_SLNDEN    0x4000UL      /*!< SPCMD SLNDEN */
#define SPI_SPCMD_CLKDEN    0x8000UL      /*!< SPCMD CLKDEN */
#define SPI_SPCMD_SPB_S     16UL          /*!< SPCMD SPB Shift */
#define SPI_SPCMD_SPB_M     0x1F0000UL    /*!< SPCMD SPB Mask */

/* The following are defines for the bit fileds in the SPDCR1 register definition*/
#define SPI_SPDCR1_BYSW      0x1UL      /*!< SPDCR1 BYSW */
#define SPI_SPDCR1_SPRDTD    0x8UL      /*!< SPDCR1 SPRDTD */
#define SPI_SPDCR1_SINV      0x10UL     /*!< SPDCR1 SINV */

/* The following are defines for the bit fileds in the SPSR register definition*/
#define SPI_SPSR_SPDRF      0x800000UL      /*!< SPSR SPDRF */
#define SPI_SPSR_OVRF       0x1000000UL     /*!< SPSR OVRF */
#define SPI_SPSR_IDLNF      0x2000000UL     /*!< SPSR IDLNF */
#define SPI_SPSR_MODF       0x4000000UL     /*!< SPSR MODF */
#define SPI_SPSR_PERF       0x8000000UL     /*!< SPSR PERF */
#define SPI_SPSR_ULDRF      0x10000000UL    /*!< SPSR ULDRF */
#define SPI_SPSR_SPTEF      0x20000000UL    /*!< SPSR SPIEF */
#define SPI_SPSR_CENDF      0x40000000UL    /*!< SPSR CENDF */
#define SPI_SPSR_SPRF       0x80000000UL    /*!< SPSR SPRF */

/* The following are defines for the bit fileds in the SPPSR register definition*/
#define SPI_SPPSR_SPEPS    0x1UL    /*!< SPPSR SPEPS */

/* The following are defines for the bit fileds in the SPSCR register definition*/
#define SPI_SPSCR_SPDRFC    0x800000UL      /*!< SPPSR SPDRFC */
#define SPI_SPSCR_OVRFC     0x1000000UL     /*!< SPSCR OVRFC */
#define SPI_SPSCR_MODFC     0x4000000UL     /*!< SPSCR MODFC */
#define SPI_SPSCR_PERFC     0x8000000UL     /*!< SPPSR PERFC */
#define SPI_SPSCR_UDRFC     0x10000000UL    /*!< SPSCR ULDRFC */
#define SPI_SPSCR_SPTEFC    0x20000000UL    /*!< SPSCR SPIEFC */
#define SPI_SPSCR_CENDFC    0x40000000UL    /*!< SPSCR CENDFC */
#define SPI_SPSCR_SPRFC     0x80000000UL    /*!< SPSCR SPRFC */

/* The following are defines for the bit fileds in the SPFCR register definition*/
#define SPI_SPFCR_SPFRST    0x1UL    /*!< SPFCR SPFRST */


#ifdef __cplusplus
}
#endif


#endif /* __NS800RT7XXX_TI_SPI_H__ */
