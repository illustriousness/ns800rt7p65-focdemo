/**
  * @file       NS800RT7xxx_TI_sdfm.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx sdfm module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_SDFM_H__
#define __NS800RT7XXX_TI_SDFM_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
 * Definitions
 * ******************************************************************************/
/* The following are defines for the bit fileds in the sdfm register definition*/
#define SDFM_O_SDIFLG                              0x0UL           /*!< SD Interrupt Flag Register */
#define SDFM_O_SDIFLGCLR                           0x4UL           /*!< SD Interrupt Flag Clear Register */
#define SDFM_O_SDCTL                               0x8UL           /*!< SD Control Register */
#define SDFM_O_SDMFILEN                            0xCUL           /*!< SD Master Filter Enable */
#define SDFM_O_SDSTATUS                            0x10UL          /*!< SD Status Register */
#define SDFM_O_SDCTLPARM1                          0x14UL          /*!< Control Parameter Register for Ch1 */
#define SDFM_O_SDDFPARM1                           0x18UL          /*!< Data Filter Parameter Register for Ch1 */
#define SDFM_O_SDDPARM1                            0x1CUL          /*!< Data Parameter Register for Ch1 */
#define SDFM_O_SDFLT1CMPH1                         0x20UL          /*!< High-level Threshold Register for Ch1 */
#define SDFM_O_SDFLT1CMPL1                         0x24UL          /*!< Low-level Threshold Register for Ch1 */
#define SDFM_O_SDCPARM1                            0x28UL          /*!< Comparator Filter Parameter Register for Ch1 */
#define SDFM_O_SDDATA1                             0x2CUL          /*!< Data Filter Data Register (16 or 32bit) for Ch1 */
#define SDFM_O_SDDATFIFO1                          0x30UL          /*!< Filter Data FIFO Output(32b) for Ch1 */
#define SDFM_O_SDCDATA1                            0x34UL          /*!< Comparator Filter Data Register (16b) for Ch1 */
#define SDFM_O_SDFLT1CMPH2                         0x38UL          /*!< Second high level threhold  for CH1 */
#define SDFM_O_SDFLT1CMPHZ                         0x3CUL          /*!< High-level (Z) Threshold Register for Ch1 */
#define SDFM_O_SDFIFOCTL1                          0x40UL          /*!< FIFO Control Register for Ch1 */
#define SDFM_O_SDSYNC1                             0x44UL          /*!< SD Filter Sync control for Ch1 */
#define SDFM_O_SDFLT1CMPL2                         0x48UL          /*!< Second low level threhold  for CH1 */
#define SDFM_O_SDCTLPARM2                          0x4CUL          /*!< Control Parameter Register for Ch2 */
#define SDFM_O_SDDFPARM2                           0x50UL          /*!< Data Filter Parameter Register for Ch2 */
#define SDFM_O_SDDPARM2                            0x54UL          /*!< Data Parameter Register for Ch2 */
#define SDFM_O_SDFLT2CMPH1                         0x58UL          /*!< High-level Threshold Register for Ch2 */
#define SDFM_O_SDFLT2CMPL1                         0x5CUL          /*!< Low-level Threshold Register for Ch2 */
#define SDFM_O_SDCPARM2                            0x60UL          /*!< Comparator Filter Parameter Register for Ch2 */
#define SDFM_O_SDDATA2                             0x64UL          /*!< Data Filter Data Register (16 or 32bit) for Ch2 */
#define SDFM_O_SDDATFIFO2                          0x68UL          /*!< Filter Data FIFO Output(32b) for Ch2 */
#define SDFM_O_SDCDATA2                            0x6CUL          /*!< Comparator Filter Data Register (16b) for Ch2 */
#define SDFM_O_SDFLT2CMPH2                         0x70UL          /*!< Second high level threhold  for CH2 */
#define SDFM_O_SDFLT2CMPHZ                         0x74UL          /*!< High-level (Z) Threshold Register for Ch2 */
#define SDFM_O_SDFIFOCTL2                          0x78UL          /*!< FIFO Control Register for Ch2 */
#define SDFM_O_SDSYNC2                             0x7CUL          /*!< SD Filter Sync control for Ch2 */
#define SDFM_O_SDFLT2CMPL2                         0x80UL          /*!< Second low level threhold  for CH2 */
#define SDFM_O_SDCTLPARM3                          0x84UL          /*!< Control Parameter Register for Ch3 */
#define SDFM_O_SDDFPARM3                           0x88UL          /*!< Data Filter Parameter Register for Ch3 */
#define SDFM_O_SDDPARM3                            0x8CUL          /*!< Data Parameter Register for Ch3 */
#define SDFM_O_SDFLT3CMPH1                         0x90UL          /*!< High-level Threshold Register for Ch3 */
#define SDFM_O_SDFLT3CMPL1                         0x94UL          /*!< Low-level Threshold Register for Ch3 */
#define SDFM_O_SDCPARM3                            0x98UL          /*!< Comparator Filter Parameter Register for Ch3 */
#define SDFM_O_SDDATA3                             0x9CUL          /*!< Data Filter Data Register (16 or 32bit) for Ch3 */
#define SDFM_O_SDDATFIFO3                          0xA0UL          /*!< Filter Data FIFO Output(32b) for Ch3 */
#define SDFM_O_SDCDATA3                            0xA4UL          /*!< Comparator Filter Data Register (16b) for Ch3 */
#define SDFM_O_SDFLT3CMPH2                         0xA8UL          /*!< Second high level threhold  for CH3 */
#define SDFM_O_SDFLT3CMPHZ                         0xACUL          /*!< High-level (Z) Threshold Register for Ch3 */
#define SDFM_O_SDFIFOCTL3                          0xB0UL          /*!< FIFO Control Register for Ch3 */
#define SDFM_O_SDSYNC3                             0xB4UL          /*!< SD Filter Sync control for Ch3 */
#define SDFM_O_SDFLT3CMPL2                         0xB8UL          /*!< Second low level threhold  for CH3 */
#define SDFM_O_SDCTLPARM4                          0xBCUL          /*!< Control Parameter Register for Ch4 */
#define SDFM_O_SDDFPARM4                           0xC0UL          /*!< Data Filter Parameter Register for Ch4 */
#define SDFM_O_SDDPARM4                            0xC4UL          /*!< Data Parameter Register for Ch4 */
#define SDFM_O_SDFLT4CMPH1                         0xC8UL          /*!< High-level Threshold Register for Ch4 */
#define SDFM_O_SDFLT4CMPL1                         0xCCUL          /*!< Low-level Threshold Register for Ch4 */
#define SDFM_O_SDCPARM4                            0xD0UL          /*!< Comparator Filter Parameter Register for Ch4 */
#define SDFM_O_SDDATA4                             0xD4UL          /*!< Data Filter Data Register (16 or 32bit) for Ch4 */
#define SDFM_O_SDDATFIFO4                          0xD8UL          /*!< Filter Data FIFO Output(32b) for Ch4 */
#define SDFM_O_SDCDATA4                            0xDCUL          /*!< Comparator Filter Data Register (16b) for Ch4 */
#define SDFM_O_SDFLT4CMPH2                         0xE0UL          /*!< Second high level threhold  for CH4 */
#define SDFM_O_SDFLT4CMPHZ                         0xE4UL          /*!< High-level (Z) Threshold Register for Ch4 */
#define SDFM_O_SDFIFOCTL4                          0xE8UL          /*!< FIFO Control Register for Ch4 */
#define SDFM_O_SDSYNC4                             0xECUL          /*!< SD Filter Sync control for Ch4 */
#define SDFM_O_SDSYNC4                             0xECUL          /*!< SD Filter Sync control for Ch4 */
#define SDFM_O_SDSYNC4                             0xECUL          /*!< SD Filter Sync control for Ch4 */
#define SDFM_O_SDFLT4CMPL2                         0xF0UL          /*!< Second low level threhold  for CH4 */
#define SDFM_O_SDCOMP1CTL                          0xF4UL          /*!< SD Comparator event filter1 Control Register */
#define SDFM_O_SDCOMP1EVT2FLTCTL                   0xF8UL          /*!< COMPL/CEVT2 Digital filter1 Control Register */
#define SDFM_O_SDCOMP1EVT2FLTCLKCTL                0xFCUL          /*!< COMPL/CEVT2 Digital filter1 Clock Control Register */
#define SDFM_O_SDCOMP1EVT1FLTCTL                   0x100UL         /*!< COMPH/CEVT1 Digital filter1 Control Register */
#define SDFM_O_SDCOMP1EVT1FLTCLKCTL                0x104UL         /*!< COMPH/CEVT1 Digital filter1 Clock Control Register */
#define SDFM_O_SDCOMP1LOCK                         0x108UL         /*!< SD  compartor event filter1 Lock Register */
#define SDFM_O_SDCOMP2CTL                          0x10CUL         /*!< SD Comparator event filter2 Control Register */
#define SDFM_O_SDCOMP2EVT2FLTCTL                   0x110UL         /*!< COMPL/CEVT2 Digital filter2 Control Register */
#define SDFM_O_SDCOMP2EVT2FLTCLKCTL                0x114UL         /*!< COMPL/CEVT2 Digital filter2 Clock Control Register */
#define SDFM_O_SDCOMP2EVT1FLTCTL                   0x118UL         /*!< COMPH/CEVT1 Digital filter2 Control Register */
#define SDFM_O_SDCOMP2EVT1FLTCLKCTL                0x11CUL         /*!< COMPH/CEVT1 Digital filter2 Clock Control Register */
#define SDFM_O_SDCOMP2LOCK                         0x120UL         /*!< SD  compartor event filter2 Lock Register */
#define SDFM_O_SDCOMP3CTL                          0x124UL         /*!< SD Comparator event filter3 Control Register */
#define SDFM_O_SDCOMP3EVT2FLTCTL                   0x128UL         /*!< COMPL/CEVT2 Digital filter3 Control Register */
#define SDFM_O_SDCOMP3EVT2FLTCLKCTL                0x12CUL         /*!< COMPL/CEVT2 Digital filter3 Clock Control Register */
#define SDFM_O_SDCOMP3EVT1FLTCTL                   0x130UL         /*!< COMPH/CEVT1 Digital filter3 Control Register */
#define SDFM_O_SDCOMP3EVT1FLTCLKCTL                0x134UL         /*!< COMPH/CEVT1 Digital filter3 Clock Control Register */
#define SDFM_O_SDCOMP3LOCK                         0x138UL         /*!< SD  compartor event filter3 Lock Register */
#define SDFM_O_SDCOMP4CTL                          0x13CUL         /*!< SD Comparator event filter4 Control Register */
#define SDFM_O_SDCOMP4EVT2FLTCTL                   0x140UL         /*!< COMPL/CEVT2 Digital filter4 Control Register */
#define SDFM_O_SDCOMP4EVT2FLTCLKCTL                0x144UL         /*!< COMPL/CEVT2 Digital filter4 Clock Control Register */
#define SDFM_O_SDCOMP4EVT1FLTCTL                   0x148UL         /*!< COMPH/CEVT1 Digital filter4 Control Register */
#define SDFM_O_SDCOMP4EVT1FLTCLKCTL                0x14CUL         /*!< COMPH/CEVT1 Digital filter4 Clock Control Register */
#define SDFM_O_SDCOMP4LOCK                         0x150UL         /*!< SD  compartor event filter4 Lock Register */
#define SDFM_O_SDDMACTL                            0x154UL         /*!< SD  compartor event filter4 Lock Register */
#define SDFM_SDIFLG_FLT1_FLG_CEVT1                 0x1UL           /*!< High-level Interrupt flag for Ch1 */
#define SDFM_SDIFLG_FLT1_FLG_CEVT2                 0x2UL           /*!< Low-level Interrupt flag for Ch1 */
#define SDFM_SDIFLG_FLT2_FLG_CEVT1                 0x4UL           /*!< High-level Interrupt flag for Ch2 */
#define SDFM_SDIFLG_FLT2_FLG_CEVT2                 0x8UL           /*!< Low-level Interrupt flag for Ch2 */
#define SDFM_SDIFLG_FLT3_FLG_CEVT1                 0x10UL          /*!< High-level Interrupt flag for Ch3 */
#define SDFM_SDIFLG_FLT3_FLG_CEVT2                 0x20UL          /*!< Low-level Interrupt flag for Ch3 */
#define SDFM_SDIFLG_FLT4_FLG_CEVT1                 0x40UL          /*!< High-level Interrupt flag for Ch4 */
#define SDFM_SDIFLG_FLT4_FLG_CEVT2                 0x80UL          /*!< Low-level Interrupt flag for Ch4 */
#define SDFM_SDIFLG_MF1                            0x100UL         /*!< Modulator Failure for Filter 1 */
#define SDFM_SDIFLG_MF2                            0x200UL         /*!< Modulator Failure for Filter 2 */
#define SDFM_SDIFLG_MF3                            0x400UL         /*!< Modulator Failure for Filter 3 */
#define SDFM_SDIFLG_MF4                            0x800UL         /*!< Modulator Failure for Filter 4 */
#define SDFM_SDIFLG_AF1                            0x1000UL        /*!< Acknowledge flag for Filter 1 */
#define SDFM_SDIFLG_AF2                            0x2000UL        /*!< Acknowledge flag for Filter 2 */
#define SDFM_SDIFLG_AF3                            0x4000UL        /*!< Acknowledge flag for Filter 3 */
#define SDFM_SDIFLG_AF4                            0x8000UL        /*!< Acknowledge flag for Filter 4 */
#define SDFM_SDIFLG_SDFFOVF1                       0x10000UL       /*!< FIFO Overflow Flag for Ch1 */
#define SDFM_SDIFLG_SDFFOVF2                       0x20000UL       /*!< FIFO Overflow Flag for Ch2 */
#define SDFM_SDIFLG_SDFFOVF3                       0x40000UL       /*!< FIFO Overflow Flag for Ch3 */
#define SDFM_SDIFLG_SDFFOVF4                       0x80000UL       /*!< FIFO Overflow Flag for Ch4 */
#define SDFM_SDIFLG_SDFFINT1                       0x100000UL      /*!< SDFIFO interrupt for Ch1 */
#define SDFM_SDIFLG_SDFFINT2                       0x200000UL      /*!< SDFIFO interrupt for Ch2 */
#define SDFM_SDIFLG_SDFFINT3                       0x400000UL      /*!< SDFIFO interrupt for Ch3 */
#define SDFM_SDIFLG_SDFFINT4                       0x800000UL      /*!< SDFIFO interrupt for Ch4 */
#define SDFM_SDIFLG_MIF                            0x80000000UL    /*!< Master Interrupt Flag */
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT1              0x1UL           /*!< High-level Interrupt flag for Ch1 */
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT2              0x2UL           /*!< Low-level Interrupt flag for Ch1 */
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT1              0x4UL           /*!< High-level Interrupt flag for Ch2 */
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT2              0x8UL           /*!< Low-level Interrupt flag for Ch2 */
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT1              0x10UL          /*!< High-level Interrupt flag for Ch3 */
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT2              0x20UL          /*!< Low-level Interrupt flag for Ch3 */
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT1              0x40UL          /*!< High-level Interrupt flag for Ch4 */
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT2              0x80UL          /*!< Low-level Interrupt flag for Ch4 */
#define SDFM_SDIFLGCLR_MF1                         0x100UL         /*!< Modulator Failure for Filter 1 */
#define SDFM_SDIFLGCLR_MF2                         0x200UL         /*!< Modulator Failure for Filter 2 */
#define SDFM_SDIFLGCLR_MF3                         0x400UL         /*!< Modulator Failure for Filter 3 */
#define SDFM_SDIFLGCLR_MF4                         0x800UL         /*!< Modulator Failure for Filter 4 */
#define SDFM_SDIFLGCLR_AF1                         0x1000UL        /*!< Acknowledge flag for Filter 1 */
#define SDFM_SDIFLGCLR_AF2                         0x2000UL        /*!< Acknowledge flag for Filter 2 */
#define SDFM_SDIFLGCLR_AF3                         0x4000UL        /*!< Acknowledge flag for Filter 3 */
#define SDFM_SDIFLGCLR_AF4                         0x8000UL        /*!< Acknowledge flag for Filter 4 */
#define SDFM_SDIFLGCLR_SDFFOVF1                    0x10000UL       /*!< SDFIFO overflow clear Ch1 */
#define SDFM_SDIFLGCLR_SDFFOVF2                    0x20000UL       /*!< SDFIFO overflow clear Ch2 */
#define SDFM_SDIFLGCLR_SDFFOVF3                    0x40000UL       /*!< SDFIFO overflow clear Ch3 */
#define SDFM_SDIFLGCLR_SDFFOVF4                    0x80000UL       /*!< SDFIFO overflow clear Ch4 */
#define SDFM_SDIFLGCLR_SDFFINT1                    0x100000UL      /*!< SDFIFO Interrupt flag-clear bit for Ch1 */
#define SDFM_SDIFLGCLR_SDFFINT2                    0x200000UL      /*!< SDFIFO Interrupt flag-clear bit for Ch2 */
#define SDFM_SDIFLGCLR_SDFFINT3                    0x400000UL      /*!< SDFIFO Interrupt flag-clear bit for Ch3 */
#define SDFM_SDIFLGCLR_SDFFINT4                    0x800000UL      /*!< SDFIFO Interrupt flag-clear bit for Ch4 */
#define SDFM_SDIFLGCLR_MIF                         0x80000000UL    /*!< Master Interrupt Flag */
#define SDFM_SDCTL_HZ1                             0x1UL           /*!< High-level Threshold crossing (Z) flag Ch1 */
#define SDFM_SDCTL_HZ2                             0x2UL           /*!< High-level Threshold crossing (Z) flag Ch2 */
#define SDFM_SDCTL_HZ3                             0x4UL           /*!< High-level Threshold crossing (Z) flag Ch3 */
#define SDFM_SDCTL_HZ4                             0x8UL          /*!< High-level Threshold crossing (Z) flag Ch4 */
#define SDFM_SDCTL_MIE                             0x2000UL        /*!< Master SDy_ERR Interrupt enable */
#define SDFM_SDMFILEN_MFE                          0x801UL         /*!< Master Filter Enable */
#define SDFM_SDSTATUS_HZ1                          0x1UL           /*!< High-level Threshold crossing (Z) flag Ch1 */
#define SDFM_SDSTATUS_HZ2                          0x2UL           /*!< High-level Threshold crossing (Z) flag Ch2 */
#define SDFM_SDSTATUS_HZ3                          0x4UL           /*!< High-level Threshold crossing (Z) flag Ch3 */
#define SDFM_SDSTATUS_HZ4                          0x8UL           /*!< High-level Threshold crossing (Z) flag Ch4 */
#define SDFM_SDCTLPARM1_SDCLKSEL                   0x8UL           /*!< SD1 Clock source select */
#define SDFM_SDCTLPARM1_SDCLKSYNC                  0x10UL          /*!< Enable Synchronizer on SD clock */
#define SDFM_SDCTLPARM1_SDDATASYNC                 0x40UL          /*!< Enable Synchronizer on SD data */
#define SDFM_SDDFPARM1_FEN                         0x100UL         /*!< Filter Enable */
#define SDFM_SDDFPARM1_AE                          0x200UL         /*!< Ack Enable */
#define SDFM_SDDFPARM1_SDSYNCEN                    0x1000UL        /*!< Data Filter Reset Enable */
#define SDFM_SDDPARM1_DR                           0x400UL         /*!< Data Representation (0/1 = 16/32b 2's complement) */
#define SDFM_SDCPARM1_EN_CEVT1                     0x20UL          /*!< CEVT1 Interrupt enable */
#define SDFM_SDCPARM1_EN_CEVT2                     0x40UL          /*!< CEVT2 Interrupt enable */
#define SDFM_SDCPARM1_CS1_CS0_S                    7UL
#define SDFM_SDCPARM1_CS1_CS0_M                    0x180UL         /*!< Comparator Filter Structure (SincFast/1/2/3) */
#define SDFM_SDCPARM1_MFIE                         0x200UL         /*!< Modulator Failure Interrupt enable */
#define SDFM_SDCPARM1_HZEN                         0x400UL         /*!< High level (Z) Threshold crossing output enable */
#define SDFM_SDCPARM1_CEN                          0x2000UL        /*!< Comparator Enable */
#define SDFM_SDFIFOCTL1_FFIEN                      0x1000UL        /*!< SDFIFO data ready Interrupt Enable */
#define SDFM_SDFIFOCTL1_FFEN                       0x2000UL        /*!< SDFIFO Enable */
#define SDFM_SDFIFOCTL1_DRINTSEL                   0x4000UL        /*!< Data-Ready Interrupt Source Select */
#define SDFM_SDFIFOCTL1_OVFIEN                     0x8000UL        /*!< SDFIFO Overflow interrupt enable */
#define SDFM_SDSYNC1_WTSYNCEN                      0x40UL          /*!< Wait-for-Sync Enable */
#define SDFM_SDSYNC1_WTSYNFLG                      0x80UL          /*!< Wait-for-Sync Flag */
#define SDFM_SDSYNC1_WTSYNCLR                      0x100UL         /*!< Wait-for-Sync Flag Clear */
#define SDFM_SDSYNC1_FFSYNCCLREN                   0x200UL         /*!< FIFO Clear-on-SDSYNC Enable */
#define SDFM_SDSYNC1_WTSCLREN                      0x400UL         /*!< WTSYNFLG Clear-on-FIFOINT Enable */
#define SDFM_SDCTLPARM2_SDCLKSEL                   0x8UL           /*!< SD2 Clock source select */
#define SDFM_SDCTLPARM2_SDCLKSYNC                  0x10UL          /*!< Enable Synchronizer on SD clock */
#define SDFM_SDCTLPARM2_SDDATASYNC                 0x40UL          /*!< Enable Synchronizer on SD data */
#define SDFM_SDDFPARM2_FEN                         0x100UL         /*!< Filter Enable */
#define SDFM_SDDFPARM2_AE                          0x200UL         /*!< Ack Enable */
#define SDFM_SDDFPARM2_SDSYNCEN                    0x1000UL        /*!< Data Filter Reset Enable */
#define SDFM_SDDPARM2_DR                           0x400UL         /*!< Data Representation (0/1 = 16/32b 2's complement) */
#define SDFM_SDCPARM2_EN_CEVT1                     0x20UL          /*!< CEVT1 Interrupt enable */
#define SDFM_SDCPARM2_EN_CEVT2                     0x40UL          /*!< CEVT2 Interrupt enable */
#define SDFM_SDCPARM2_MFIE                         0x200UL         /*!< Modulator Failure Interrupt enable */
#define SDFM_SDCPARM2_HZEN                         0x400UL         /*!< High level (Z) Threshold crossing output enable */
#define SDFM_SDCPARM2_CEN                          0x2000UL        /*!< Comparator Enable */
#define SDFM_SDFIFOCTL2_FFIEN                      0x1000UL        /*!< SDFIFO data ready Interrupt Enable */
#define SDFM_SDFIFOCTL2_FFEN                       0x2000UL        /*!< SDFIFO Enable */
#define SDFM_SDFIFOCTL2_DRINTSEL                   0x4000UL        /*!< Data-Ready Interrupt Source Select */
#define SDFM_SDFIFOCTL2_OVFIEN                     0x8000UL        /*!< SDFIFO Overflow interrupt enable */
#define SDFM_SDSYNC2_WTSYNCEN                      0x40UL          /*!< Wait-for-Sync Enable */
#define SDFM_SDSYNC2_WTSYNFLG                      0x80UL          /*!< Wait-for-Sync Flag */
#define SDFM_SDSYNC2_WTSYNCLR                      0x100UL         /*!< Wait-for-Sync Flag Clear */
#define SDFM_SDSYNC2_FFSYNCCLREN                   0x200UL         /*!< FIFO Clear-on-SDSYNC Enable */
#define SDFM_SDSYNC2_WTSCLREN                      0x400UL         /*!< WTSYNFLG Clear-on-FIFOINT Enable */
#define SDFM_SDCTLPARM3_SDCLKSEL                   0x8UL           /*!< SD3 Clock source select */
#define SDFM_SDCTLPARM3_SDCLKSYNC                  0x10UL          /*!< Enable Synchronizer on SD clock */
#define SDFM_SDCTLPARM3_SDDATASYNC                 0x40UL          /*!< Enable Synchronizer on SD data */
#define SDFM_SDDFPARM3_FEN                         0x100UL         /*!< Filter Enable */
#define SDFM_SDDFPARM3_AE                          0x200UL         /*!< Ack Enable */
#define SDFM_SDDFPARM3_SDSYNCEN                    0x1000UL        /*!< Data Filter Reset Enable */
#define SDFM_SDDPARM3_DR                           0x400UL         /*!< Data Representation (0/1 = 16/32b 2's complement) */
#define SDFM_SDCPARM3_EN_CEVT1                     0x20UL          /*!< CEVT1 Interrupt enable */
#define SDFM_SDCPARM3_EN_CEVT2                     0x40UL          /*!< CEVT2 Interrupt enable */
#define SDFM_SDCPARM3_MFIE                         0x200UL         /*!< Modulator Failure Interrupt enable */
#define SDFM_SDCPARM3_HZEN                         0x400UL         /*!< High level (Z) Threshold crossing output enable */
#define SDFM_SDCPARM3_CEN                          0x2000UL        /*!< Comparator Enable */
#define SDFM_SDFIFOCTL3_FFIEN                      0x1000UL        /*!< SDFIFO data ready Interrupt Enable */
#define SDFM_SDFIFOCTL3_FFEN                       0x2000UL        /*!< SDFIFO Enable */
#define SDFM_SDFIFOCTL3_DRINTSEL                   0x4000UL        /*!< Data-Ready Interrupt Source Select */
#define SDFM_SDFIFOCTL3_OVFIEN                     0x8000UL        /*!< SDFIFO Overflow interrupt enable */
#define SDFM_SDSYNC3_WTSYNCEN                      0x40UL          /*!< Wait-for-Sync Enable */
#define SDFM_SDSYNC3_WTSYNFLG                      0x80UL          /*!< Wait-for-Sync Flag */
#define SDFM_SDSYNC3_WTSYNCLR                      0x100UL         /*!< Wait-for-Sync Flag Clear */
#define SDFM_SDSYNC3_FFSYNCCLREN                   0x200UL         /*!< FIFO Clear-on-SDSYNC Enable */
#define SDFM_SDSYNC3_WTSCLREN                      0x400UL         /*!< WTSYNFLG Clear-on-FIFOINT Enable */
#define SDFM_SDCTLPARM4_SDCLKSEL                   0x8UL           /*!< SD4 Clock source select */
#define SDFM_SDCTLPARM4_SDCLKSYNC                  0x10UL          /*!< Enable Synchronizer on SD clock */
#define SDFM_SDCTLPARM4_SDDATASYNC                 0x40UL          /*!< Enable Synchronizer on SD data */
#define SDFM_SDDFPARM4_FEN                         0x100UL         /*!< Filter Enable */
#define SDFM_SDDFPARM4_AE                          0x200UL         /*!< Ack Enable */
#define SDFM_SDFIFOCTL1                            0x1000UL        /*!< Data Filter Reset Enable */
#define SDFM_SDDPARM4_DR                           0x400UL         /*!< Data Representation (0/1 = 16/32b 2's complement) */
#define SDFM_SDCPARM4_EN_CEVT1                     0x20UL          /*!< CEVT1 Interrupt enable */
#define SDFM_SDCPARM4_EN_CEVT2                     0x40UL          /*!< CEVT2 Interrupt enable */
#define SDFM_SDCPARM4_MFIE                         0x200UL         /*!< Modulator Failure Interrupt enable */
#define SDFM_SDCPARM4_HZEN                         0x400UL         /*!< High level (Z) Threshold crossing output enable */
#define SDFM_SDCPARM4_CEN                          0x2000UL        /*!< Comparator Enable */
#define SDFM_SDFIFOCTL4_FFIEN                      0x1000UL        /*!< SDFIFO data ready Interrupt Enable */
#define SDFM_SDFIFOCTL4_FFEN                       0x2000UL        /*!< SDFIFO Enable */
#define SDFM_SDFIFOCTL4_DRINTSEL                   0x4000UL        /*!< Data-Ready Interrupt Source Select */
#define SDFM_SDFIFOCTL4_OVFIEN                     0x8000UL        /*!< SDFIFO Overflow interrupt enable */
#define SDFM_SDSYNC4_WTSYNCEN                      0x40UL          /*!< Wait-for-Sync Enable */
#define SDFM_SDSYNC4_WTSYNFLG                      0x80UL          /*!< Wait-for-Sync Flag */
#define SDFM_SDSYNC4_WTSYNCLR                      0x100UL         /*!< Wait-for-Sync Flag Clear */
#define SDFM_SDSYNC4_FFSYNCCLREN                   0x200UL         /*!< FIFO Clear-on-SDSYNC Enable */
#define SDFM_SDSYNC4_WTSCLREN                      0x400UL         /*!< WTSYNFLG Clear-on-FIFOINT Enable */
#define SDFM_SDCOMP1EVT2FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP1EVT1FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP1LOCK_SDCOMP1CTL                0x1UL           /*!< COMPCTL Lock */
#define SDFM_SDCOMP1LOCK_COMP                      0x8UL           /*!< COMPevent filter registers Lock */
#define SDFM_SDCOMP2EVT2FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP2EVT1FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP2LOCK_SDCOMP2CTL                0x1UL           /*!< COMPCTL Lock */
#define SDFM_SDCOMP2LOCK_COMP                      0x8UL           /*!< COMPevent filter registers Lock */
#define SDFM_SDCOMP3EVT2FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP3EVT1FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP3LOCK_SDCOMP3CTL                0x1UL           /*!< COMPCTL Lock */
#define SDFM_SDCOMP3LOCK_COMP                      0x8UL           /*!< COMPevent filter registers Lock */
#define SDFM_SDCOMP4EVT2FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP4EVT1FLTCTL_FILINIT             0x8000UL        /*!< Filter Initialization Bit */
#define SDFM_SDCOMP4LOCK_SDCOMP4CTL                0x1UL           /*!< COMPCTL Lock*/
#define SDFM_SDCOMP4LOCK_COMP                      0x8UL           /*!< COMPevent filter registers Lock */

#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_SDFM_H__ */
