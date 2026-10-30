/**
  * @file       NS800RT7xxx_TI_epwmxbar.h
  * @author     wuxiao
  * @brief      Header file for NS800RT7xxx epwmxbar module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_EPWMXBAR_H__
#define __NS800RT7XXX_TI_EPWMXBAR_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* The following are defines for the XBAR register offsets */
#define XBAR_O_OUT1MUX0TO15CFG        (0x0UL)     /* ePWM XBAR Mux Configuration for Output1 */
#define XBAR_O_OUT1MUX16TO31CFG       (0x4UL)     /* ePWM XBAR Mux Configuration for Output1 */
#define XBAR_O_OUT1MUX32TO47CFG       (0x8UL)     /* ePWM XBAR Mux Configuration for Output1 */
#define XBAR_O_OUT1MUX48TO63CFG       (0xcUL)     /* ePWM XBAR Mux Configuration for Output1 */
#define XBAR_O_OUT2MUX0TO15CFG        (0x10UL)    /* ePWM XBAR Mux Configuration for Output2 */
#define XBAR_O_OUT2MUX16TO31CFG       (0x14UL)    /* ePWM XBAR Mux Configuration for Output2 */
#define XBAR_O_OUT2MUX32TO47CFG       (0x18UL)    /* ePWM XBAR Mux Configuration for Output2 */
#define XBAR_O_OUT2MUX48TO63CFG       (0x1CUL)    /* ePWM XBAR Mux Configuration for Output2 */
#define XBAR_O_OUT3MUX0TO15CFG        (0x20UL)    /* ePWM XBAR Mux Configuration for Output3 */
#define XBAR_O_OUT3MUX16TO31CFG       (0x24UL)    /* ePWM XBAR Mux Configuration for Output3 */
#define XBAR_O_OUT3MUX32TO47CFG       (0x28UL)    /* ePWM XBAR Mux Configuration for Output3 */
#define XBAR_O_OUT3MUX48TO63CFG       (0x2CUL)    /* ePWM XBAR Mux Configuration for Output3 */
#define XBAR_O_OUT4MUX0TO15CFG        (0x30UL)    /* ePWM XBAR Mux Configuration for Output4 */
#define XBAR_O_OUT4MUX16TO31CFG       (0x34UL)    /* ePWM XBAR Mux Configuration for Output4 */
#define XBAR_O_OUT4MUX32TO47CFG       (0x38UL)    /* ePWM XBAR Mux Configuration for Output4 */
#define XBAR_O_OUT4MUX48TO63CFG       (0x3CUL)    /* ePWM XBAR Mux Configuration for Output4 */
#define XBAR_O_OUT5MUX0TO15CFG        (0x40UL)    /* ePWM XBAR Mux Configuration for Output5 */
#define XBAR_O_OUT5MUX16TO31CFG       (0x44UL)    /* ePWM XBAR Mux Configuration for Output5 */
#define XBAR_O_OUT5MUX32TO47CFG       (0x48UL)    /* ePWM XBAR Mux Configuration for Output5 */
#define XBAR_O_OUT5MUX48TO63CFG       (0x4CUL)    /* ePWM XBAR Mux Configuration for Output5 */
#define XBAR_O_OUT6MUX0TO15CFG        (0x50UL)    /* ePWM XBAR Mux Configuration for Output6 */
#define XBAR_O_OUT6MUX16TO31CFG       (0x54UL)    /* ePWM XBAR Mux Configuration for Output6 */
#define XBAR_O_OUT6MUX32TO47CFG       (0x58UL)    /* ePWM XBAR Mux Configuration for Output6 */
#define XBAR_O_OUT6MUX48TO63CFG       (0x5CUL)    /* ePWM XBAR Mux Configuration for Output6 */
#define XBAR_O_OUT7MUX0TO15CFG        (0x60UL)    /* ePWM XBAR Mux Configuration for Output7 */
#define XBAR_O_OUT7MUX16TO31CFG       (0x64UL)    /* ePWM XBAR Mux Configuration for Output7 */
#define XBAR_O_OUT7MUX32TO47CFG       (0x68UL)    /* ePWM XBAR Mux Configuration for Output7 */
#define XBAR_O_OUT7MUX48TO63CFG       (0x6CUL)    /* ePWM XBAR Mux Configuration for Output7 */
#define XBAR_O_OUT8MUX0TO15CFG        (0x70UL)    /* ePWM XBAR Mux Configuration for Output8 */
#define XBAR_O_OUT8MUX16TO31CFG       (0x74UL)    /* ePWM XBAR Mux Configuration for Output8 */
#define XBAR_O_OUT8MUX32TO47CFG       (0x78UL)    /* ePWM XBAR Mux Configuration for Output8 */
#define XBAR_O_OUT8MUX48TO63CFG       (0x7CUL)    /* ePWM XBAR Mux Configuration for Output8 */
#define XBAR_O_OUT1MUXENABLE          (0x80UL)    /* ePWM XBAR Mux Enable for Output1 */
#define XBAR_O_OUT1MUXENABLE32TO64    (0x84UL)    /* ePWM XBAR Mux Enable for Output1 */
#define XBAR_O_OUT2MUXENABLE          (0x88UL)    /* ePWM XBAR Mux Enable for Output2 */
#define XBAR_O_OUT2MUXENABLE32TO64    (0x8CUL)    /* ePWM XBAR Mux Enable for Output2 */
#define XBAR_O_OUT3MUXENABLE          (0x90UL)    /* ePWM XBAR Mux Enable for Output3 */
#define XBAR_O_OUT3MUXENABLE32TO64    (0x94UL)    /* ePWM XBAR Mux Enable for Output3 */
#define XBAR_O_OUT4MUXENABLE          (0x98UL)    /* ePWM XBAR Mux Enable for Output4 */
#define XBAR_O_OUT4MUXENABLE32TO64    (0x9CUL)    /* ePWM XBAR Mux Enable for Output4 */
#define XBAR_O_OUT5MUXENABLE          (0xA0UL)    /* ePWM XBAR Mux Enable for Output5 */
#define XBAR_O_OUT5MUXENABLE32TO64    (0xA4UL)    /* ePWM XBAR Mux Enable for Output5 */
#define XBAR_O_OUT6MUXENABLE          (0xA8UL)    /* ePWM XBAR Mux Enable for Output6 */
#define XBAR_O_OUT6MUXENABLE32TO64    (0xACUL)    /* ePWM XBAR Mux Enable for Output6 */
#define XBAR_O_OUT7MUXENABLE          (0xB0UL)    /* ePWM XBAR Mux Enable for Output7 */
#define XBAR_O_OUT7MUXENABLE32TO64    (0xB4UL)    /* ePWM XBAR Mux Enable for Output7 */
#define XBAR_O_OUT8MUXENABLE          (0xB8UL)    /* ePWM XBAR Mux Enable for Output8 */
#define XBAR_O_OUT8MUXENABLE32TO64    (0xBCUL)    /* ePWM XBAR Mux Enable for Output8 */
#define XBAR_O_TRIPOUTINV             (0xC0UL)    /* ePWM XBAR Output Inversion Register */
#define XBAR_O_TRIPLOCK               (0xC4UL)    /* ePWM XBAR Configuration Lock register */

/* The following are defines for the bit fields in the OUT1MUX0TO15CFG register */
#define XBAR_OUT1MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT1MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT1MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT1 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT1MUX16TO31CFG register */
#define XBAR_OUT1MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT1MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT1MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT1 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT1MUX32TO47CFG register */
#define XBAR_OUT1MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT1MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT1MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT1MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT1MUX48TO63CFG register */
#define XBAR_OUT1MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT1MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT1MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT1 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT2MUX0TO15CFG register */
#define XBAR_OUT2MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT2MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT2MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT2 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT2MUX16TO31CFG register */
#define XBAR_OUT2MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT2MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT2MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT2 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT2MUX32TO47CFG register */
#define XBAR_OUT2MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT2MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT2MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT2MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT2MUX48TO63CFG register */
#define XBAR_OUT2MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT2MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT2MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT2 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT3MUX0TO15CFG register */
#define XBAR_OUT3MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT3MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT3MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT3 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT3MUX16TO31CFG register */
#define XBAR_OUT3MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT3MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT3MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT3 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT3MUX32TO47CFG register */
#define XBAR_OUT3MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT3MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT3MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT3MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT3MUX48TO63CFG register */
#define XBAR_OUT3MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT3MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT3MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT3 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT4MUX0TO15CFG register */
#define XBAR_OUT4MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT4MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX1_S     (2UL)
#define XBAR_OUT4MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX2_S     (4UL)
#define XBAR_OUT4MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX3_S     (6UL)
#define XBAR_OUT4MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX4_S     (8UL)
#define XBAR_OUT4MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX5_S     (10UL)
#define XBAR_OUT4MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX6_S     (12UL)
#define XBAR_OUT4MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX7_S     (14UL)
#define XBAR_OUT4MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX8_S     (16UL)
#define XBAR_OUT4MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX9_S     (18UL)
#define XBAR_OUT4MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX10_S    (20UL)
#define XBAR_OUT4MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX11_S    (22UL)
#define XBAR_OUT4MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX12_S    (24UL)
#define XBAR_OUT4MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX13_S    (26UL)
#define XBAR_OUT4MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX14_S    (28UL)
#define XBAR_OUT4MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX0TO15CFG_MUX15_S    (30UL)
#define XBAR_OUT4MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT4MUX16TO31CFG register */
#define XBAR_OUT4MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT4MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT4MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT4MUX32TO47CFG register */
#define XBAR_OUT4MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT4MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT4MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT4MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT4MUX48TO63CFG register */
#define XBAR_OUT4MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT4MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT4MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT5MUX0TO15CFG register */
#define XBAR_OUT5MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT5MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT5MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT5 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT5MUX16TO31CFG register */
#define XBAR_OUT5MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT5MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT5MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT5 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT5MUX32TO47CFG register */
#define XBAR_OUT5MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT5MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT5MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT5MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT5MUX48TO63CFG register */
#define XBAR_OUT5MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT5MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT5MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT5 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT6MUX0TO15CFG register */
#define XBAR_OUT6MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT6MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT6MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT6 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT6MUX16TO31CFG register */
#define XBAR_OUT6MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT6MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT6MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT6 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT6MUX32TO47CFG register */
#define XBAR_OUT6MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT6MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT6MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT6MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT6MUX48TO63CFG register */
#define XBAR_OUT6MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT6MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT6MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT6 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT7MUX0TO15CFG register */
#define XBAR_OUT7MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT7MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT7MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT7 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT7MUX16TO31CFG register */
#define XBAR_OUT7MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT7MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT7MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT7 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT7MUX32TO47CFG register */
#define XBAR_OUT7MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT7MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT7MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT7MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT7MUX48TO63CFG register */
#define XBAR_OUT7MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT7MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT7MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT7 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT8MUX0TO15CFG register */
#define XBAR_OUT8MUX0TO15CFG_MUX0_S     (0UL)
#define XBAR_OUT8MUX0TO15CFG_MUX0_M     (0x3UL)           /* MUX0 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX1_S     (2UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX1_M     (0xCUL)           /* MUX1 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX2_S     (4UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX2_M     (0x30UL)          /* MUX2 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX3_S     (6UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX3_M     (0xC0UL)          /* MUX3 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX4_S     (8UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX4_M     (0x300UL)         /* MUX4 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX5_S     (10UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX5_M     (0xC00UL)         /* MUX5 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX6_S     (12UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX6_M     (0x3000UL)        /* MUX6 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX7_S     (14UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX7_M     (0xC000UL)        /* MUX7 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX8_S     (16UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX8_M     (0x30000UL)       /* MUX8 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX9_S     (18UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX9_M     (0xC0000UL)       /* MUX9 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX10_S    (20UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX10_M    (0x300000UL)      /* MUX10 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX11_S    (22UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX11_M    (0xC00000UL)      /* MUX11 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX12_S    (24UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX12_M    (0x3000000UL)     /* MUX12 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX13_S    (26UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX13_M    (0xC000000UL)     /* MUX13 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX14_S    (28UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX14_M    (0x30000000UL)    /* MUX14 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX0TO15CFG_MUX15_S    (30UL) 
#define XBAR_OUT8MUX0TO15CFG_MUX15_M    (0xC0000000UL)    /* MUX15 Configuration for OUT8 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT8MUX16TO31CFG register */
#define XBAR_OUT8MUX16TO31CFG_MUX16_S    (0UL)
#define XBAR_OUT8MUX16TO31CFG_MUX16_M    (0x3UL)           /* MUX16 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX17_S    (2UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX17_M    (0xCUL)           /* MUX17 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX18_S    (4UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX18_M    (0x30UL)          /* MUX18 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX19_S    (6UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX19_M    (0xC0UL)          /* MUX19 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX20_S    (8UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX20_M    (0x300UL)         /* MUX20 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX21_S    (10UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX21_M    (0xC00UL)         /* MUX21 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX22_S    (12UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX22_M    (0x3000UL)        /* MUX22 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX23_S    (14UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX23_M    (0xC000UL)        /* MUX23 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX24_S    (16UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX24_M    (0x30000UL)       /* MUX24 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX25_S    (18UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX25_M    (0xC0000UL)       /* MUX25 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX26_S    (20UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX26_M    (0x300000UL)      /* MUX26 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX27_S    (22UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX27_M    (0xC00000UL)      /* MUX27 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX28_S    (24UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX28_M    (0x3000000UL)     /* MUX28 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX29_S    (26UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX29_M    (0xC000000UL)     /* MUX29 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX30_S    (28UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX30_M    (0x30000000UL)    /* MUX30 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX16TO31CFG_MUX31_S    (30UL) 
#define XBAR_OUT8MUX16TO31CFG_MUX31_M    (0xC0000000UL)    /* MUX31 Configuration for OUT8 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT8MUX32TO47CFG register */
#define XBAR_OUT8MUX32TO47CFG_MUX32_S    (0UL)
#define XBAR_OUT8MUX32TO47CFG_MUX32_M    (0x3UL)           /* MUX32 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX33_S    (2UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX33_M    (0xCUL)           /* MUX33 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX34_S    (4UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX34_M    (0x30UL)          /* MUX34 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX35_S    (6UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX35_M    (0xC0UL)          /* MUX35 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX36_S    (8UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX36_M    (0x300UL)         /* MUX36 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX37_S    (10UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX37_M    (0xC00UL)         /* MUX37 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX38_S    (12UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX38_M    (0x3000UL)        /* MUX38 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX39_S    (14UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX39_M    (0xC000UL)        /* MUX39 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX40_S    (16UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX40_M    (0x30000UL)       /* MUX40 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX41_S    (18UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX41_M    (0xC0000UL)       /* MUX41 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX42_S    (20UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX42_M    (0x300000UL)      /* MUX42 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX43_S    (22UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX43_M    (0xC00000UL)      /* MUX43 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX44_S    (24UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX44_M    (0x3000000UL)     /* MUX44 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX45_S    (26UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX45_M    (0xC000000UL)     /* MUX45 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX46_S    (28UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX46_M    (0x30000000UL)    /* MUX46 Configuration for TRIP4 of EPWM-XBAR */
#define XBAR_OUT8MUX32TO47CFG_MUX47_S    (30UL) 
#define XBAR_OUT8MUX32TO47CFG_MUX47_M    (0xC0000000UL)    /* MUX47 Configuration for TRIP4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT8MUX48TO63CFG register */
#define XBAR_OUT8MUX48TO63CFG_MUX48_S    (0UL)
#define XBAR_OUT8MUX48TO63CFG_MUX48_M    (0x3UL)           /* MUX48 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX49_S    (2UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX49_M    (0xCUL)           /* MUX49 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX50_S    (4UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX50_M    (0x30UL)          /* MUX50 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX51_S    (6UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX51_M    (0xC0UL)          /* MUX51 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX52_S    (8UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX52_M    (0x300UL)         /* MUX52 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX53_S    (10UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX53_M    (0xC00UL)         /* MUX53 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX54_S    (12UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX54_M    (0x3000UL)        /* MUX54 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX55_S    (14UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX55_M    (0xC000UL)        /* MUX55 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX56_S    (16UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX56_M    (0x30000UL)       /* MUX56 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX57_S    (18UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX57_M    (0xC0000UL)       /* MUX57 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX58_S    (20UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX58_M    (0x300000UL)      /* MUX58 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX59_S    (22UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX59_M    (0xC00000UL)      /* MUX59 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX60_S    (24UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX60_M    (0x3000000UL)     /* MUX60 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX61_S    (26UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX61_M    (0xC000000UL)     /* MUX61 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX62_S    (28UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX62_M    (0x30000000UL)    /* MUX62 Configuration for OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUX48TO63CFG_MUX63_S    (30UL) 
#define XBAR_OUT8MUX48TO63CFG_MUX63_M    (0xC0000000UL)    /* MUX63 Configuration for OUT8 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT1MUXENABLE register */
#define XBAR_OUT1MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT1 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT1MUXENABLE32TO64 register */
#define XBAR_OUT1MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT1 of EPWM-XBAR */
#define XBAR_OUT1MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT1 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT2MUXENABLE register */
#define XBAR_OUT2MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT2 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT2MUXENABLE32TO64 register */
#define XBAR_OUT2MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT2 of EPWM-XBAR */
#define XBAR_OUT2MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT2 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT3MUXENABLE register */
#define XBAR_OUT3MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT3 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT3MUXENABLE32TO64 register */
#define XBAR_OUT3MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT3 of EPWM-XBAR */
#define XBAR_OUT3MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT3 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT4MUXENABLE register */
#define XBAR_OUT4MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT4MUXENABLE32TO64 register */
#define XBAR_OUT4MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT4 of EPWM-XBAR */
#define XBAR_OUT4MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT4 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT5MUXENABLE register */
#define XBAR_OUT5MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT5 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT5MUXENABLE32TO64 register */
#define XBAR_OUT5MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT5 of EPWM-XBAR */
#define XBAR_OUT5MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT5 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT6MUXENABLE register */
#define XBAR_OUT6MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT6 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT6MUXENABLE32TO64 register */
#define XBAR_OUT6MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT6 of EPWM-XBAR */
#define XBAR_OUT6MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT6 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT7MUXENABLE register */
#define XBAR_OUT7MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT7 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT7MUXENABLE32TO64 register */
#define XBAR_OUT7MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT7 of EPWM-XBAR */
#define XBAR_OUT7MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT7 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT8MUXENABLE register */
#define XBAR_OUT8MUXENABLE_MUX0     (0x1UL)           /* MUX0 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX1     (0x2UL)           /* MUX1 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX2     (0x4UL)           /* MUX2 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX3     (0x8UL)           /* MUX3 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX4     (0x10UL)          /* MUX4 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX5     (0x20UL)          /* MUX5 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX6     (0x40UL)          /* MUX6 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX7     (0x80UL)          /* MUX7 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX8     (0x100UL)         /* MUX8 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX9     (0x200UL)         /* MUX9 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX10    (0x400UL)         /* MUX10 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX11    (0x800UL)         /* MUX11 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX12    (0x1000UL)        /* MUX12 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX13    (0x2000UL)        /* MUX13 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX14    (0x4000UL)        /* MUX14 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX15    (0x8000UL)        /* MUX15 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX16    (0x10000UL)       /* MUX16 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX17    (0x20000UL)       /* MUX17 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX18    (0x40000UL)       /* MUX18 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX19    (0x80000UL)       /* MUX19 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX20    (0x100000UL)      /* MUX20 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX21    (0x200000UL)      /* MUX21 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX22    (0x400000UL)      /* MUX22 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX23    (0x800000UL)      /* MUX23 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX24    (0x1000000UL)     /* MUX24 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX25    (0x2000000UL)     /* MUX25 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX26    (0x4000000UL)     /* MUX26 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX27    (0x8000000UL)     /* MUX27 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX28    (0x10000000UL)    /* MUX28 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX29    (0x20000000UL)    /* MUX29 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX30    (0x40000000UL)    /* MUX30 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE_MUX31    (0x80000000UL)    /* MUX31 to drive OUT8 of EPWM-XBAR */

/* The following are defines for the bit fields in the OUT8MUXENABLE32TO64 register */
#define XBAR_OUT8MUXENABLE32TO64_MUX32    (0x1UL)           /* MUX32 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX33    (0x2UL)           /* MUX33 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX34    (0x4UL)           /* MUX34 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX35    (0x8UL)           /* MUX35 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX36    (0x10UL)          /* MUX36 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX37    (0x20UL)          /* MUX37 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX38    (0x40UL)          /* MUX38 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX39    (0x80UL)          /* MUX39 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX40    (0x100UL)         /* MUX40 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX41    (0x200UL)         /* MUX41 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX42    (0x400UL)         /* MUX42 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX43    (0x800UL)         /* MUX43 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX44    (0x1000UL)        /* MUX44 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX45    (0x2000UL)        /* MUX45 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX46    (0x4000UL)        /* MUX46 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX47    (0x8000UL)        /* MUX47 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX48    (0x10000UL)       /* MUX48 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX49    (0x20000UL)       /* MUX49 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX50    (0x40000UL)       /* MUX50 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX51    (0x80000UL)       /* MUX51 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX52    (0x100000UL)      /* MUX52 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX53    (0x200000UL)      /* MUX53 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX54    (0x400000UL)      /* MUX54 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX55    (0x800000UL)      /* MUX55 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX56    (0x1000000UL)     /* MUX56 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX57    (0x2000000UL)     /* MUX57 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX58    (0x4000000UL)     /* MUX58 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX59    (0x8000000UL)     /* MUX59 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX60    (0x10000000UL)    /* MUX60 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX61    (0x20000000UL)    /* MUX61 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX62    (0x40000000UL)    /* MUX62 to drive OUT8 of EPWM-XBAR */
#define XBAR_OUT8MUXENABLE32TO64_MUX63    (0x80000000UL)    /* MUX63 to drive OUT8 of EPWM-XBAR */

/* The following are defines for the bit fields in the TRIPOUTINV register */
#define XBAR_TRIPOUTINV_OUT0    (0x1UL)     /* Selects polarity for OUT0 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT1    (0x2UL)     /* Selects polarity for OUT1 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT2    (0x4UL)     /* Selects polarity for OUT2 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT3    (0x8UL)     /* Selects polarity for OUT3 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT4    (0x10UL)    /* Selects polarity for OUT4 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT5    (0x20UL)    /* Selects polarity for OUT5 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT6    (0x40UL)    /* Selects polarity for OUT6 of EPWM-XBAR */
#define XBAR_TRIPOUTINV_OUT7    (0x80UL)    /* Selects polarity for OUT7 of EPWM-XBAR */

/* The following are defines for the bit fields in the TRIPLOCK register */
#define XBAR_TRIPLOCK_LOCK     (0x1UL)           /* Locks the configuration for EPWM-XBAR */ 
#define XBAR_TRIPLOCK_KEY_S    (16UL)
#define XBAR_TRIPLOCK_KEY_M    (0xFFFF0000UL)    /* Write protection KEY */ 


#ifdef __cplusplus
}
#endif


#endif
