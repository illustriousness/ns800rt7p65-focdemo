/**
  * @file       NS800RT7xxx_TI_dac.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx dac module(TI).
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __NS800RT7XXX_TI_DAC_H__
#define __NS800RT7XXX_TI_DAC_H__


#ifdef __cplusplus
extern "C" {
#endif


#if defined (NS800RT7P65X)
  #include "NS800RT7P65x.h"
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* DAC Individual Register Bit Definitions: */
struct DACCTL_BITS {                 /* bits description */
    volatile uint32_t RSVD1:1;       /* 0 Reserved */
    volatile uint32_t DAC_EN:1;      /* 1 DAC Module Code */
    volatile uint32_t LOADMODE:1;    /* 2 DACVALA Load Mode */
    volatile uint32_t DACOUTEN:1;    /* 3 DAC Output Code */
    volatile uint32_t SYNCSEL:4;     /* 7:4 DAC EPWMSYNCPER Select */
    volatile uint32_t PSC:4;         /* 11:8 DAC EPWMSYNCPER Select */
    volatile uint32_t RSVD2:20;      /* 31:12 Reserved */
};

union DACCTL_REG {
    volatile uint32_t  all;
    struct  DACCTL_BITS  bit;
};

struct DACVALA_BITS {                /* bits description */
    volatile uint32_t DACVALA:12;    /* 11:0 DAC Active Output Code */
    volatile uint32_t RSVD1:20;      /* 31:12 Reserved */
};

union DACVALA_REG {
    volatile uint32_t  all;
    struct  DACVALA_BITS  bit;
};

struct DACVALS_BITS {                /* bits description */
    volatile uint32_t DACVALS:12;    /* 11:0 DAC Shadow Output Code */
    volatile uint32_t RSVD1:20;      /* 31:12 Reserved */
};

union DACVALS_REG {
    volatile uint32_t  all;
    struct  DACVALS_BITS  bit;
};

struct DACLOCK_BITS {               /* bits description */
    volatile uint32_t DACCTL:1;     /* 0 DAC Control Register Lock */
    volatile uint32_t DACVAL:1;     /* 1 DAC Value Register Lock */
    volatile uint32_t RSVD1:1;      /* 2 Reserved */
    volatile uint32_t DACTRIM:1;    /* 3 DAC Offset Trim Register Lock */
    volatile uint32_t RSVD2:8;      /* 11:4 Reserved */
    volatile uint32_t KEY:4;        /* 15:12 DAC Register Lock Key */
    volatile uint32_t RSVD3:16;     /* 11:4 Reserved */
};

union DACLOCK_REG {
    volatile uint32_t  all;
    struct  DACLOCK_BITS  bit;
};

struct DACTRIM_BITS {                   /* bits description */
    volatile uint32_t OFFSET_TRIM:8;    /* 7:0 DAC Offset Trim */
    volatile uint32_t RSVD1:24;         /* 31:8 Reserved */
};

union DACTRIM_REG {
    volatile uint32_t  all;
    struct  DACTRIM_BITS  bit;
};

typedef struct {
    volatile uint32_t       REG1RSVD;    /* Reserved */
    union    DACCTL_REG     DACCTL;      /* DAC Control Register */
    union    DACVALA_REG    DACVALA;     /* DAC Value Register - Active */
    union    DACVALS_REG    DACVALS;     /* DAC Value Register - Shadow */
    volatile uint32_t       REG2RSVD;    /* Reserved */
    union    DACLOCK_REG    DACLOCK;     /* DAC Lock Register */
    union    DACTRIM_REG    DACTRIM;     /* DAC Trim Register */
} DAC_REGS;


/* DAC TI name */
#define DacaRegs    ((DAC_REGS*)DAC1_BASE)
#define DacbRegs    ((DAC_REGS*)DAC2_BASE)


#ifdef __cplusplus
}
#endif


#endif  /* __NS800RT7XXX_TI_DAC_H__ */
