/**
  * @file       rcc.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT7xxx rcc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __RCC_H__
#define __RCC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#if defined (NS800RT737X)
  #include "NS800RT737x.h"
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup RCC_EXPORTED_TYPES RCC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'RCC' module.
  */

/** @defgroup RCC_FUNON RCC FUNCTIONAL STATE
  * @{
  * @brief  Functional State.
  */
typedef enum {
    RCC_FUN_OFF = 0U,    /*!< Disable the function */
    RCC_FUN_ON           /*!< Enable the function */
} RCC_FunOn;

/**
  * @}
  */

/** @defgroup RCC_MCOSEL RCC MCO Selection
  * @{
  * @brief  Macro definitions for selecting the MCO output source.
  */
typedef enum {
    RCC_MCO1 = 0U,    /*!< MCO1 output source */
    RCC_MCO2          /*!< MCO2 output source */
} RCC_McoSel;

/**
  * @}
  */

/** @defgroup RCC_HXTLBYPASSSEL RCC HXTL Bypass Selection
  * @{
  * @brief  Macro definitions for selecting the HXTL mode.
  */
typedef enum {
    RCC_HXTL_NORMAL = 0U,    /*!< Normal state of the crystal oscillator */
    RCC_HXTL_BYPASS          /*!< Bypass state of the crystal oscillator */
} RCC_HxtlBypassSel;

/**
  * @}
  */

/** @defgroup RCC_MCOSOURCESEL RCC MCO Output Clock Source Selection
  * @{
  * @brief  Macro definitions for selecting the MCO output clock source.
  */
typedef enum {
    RCC_MCO_SEL_SYSCLK = 0U,    /*!< Selects system clock as MCO output */
    RCC_MCO_SEL_HXTL,           /*!< Selects high-speed external crystal oscillator as MCO output */
    RCC_MCO_SEL_LIRC,           /*!< Selects low-speed internal RC oscillator as MCO output */
    RCC_MCO_SEL_MIRC1,          /*!< Selects Medium-Speed internal RC oscillator 1 as MCO output */
    RCC_MCO_SEL_MIRC2,          /*!< Selects Medium-Speed internal RC oscillator 2 as MCO output */
    RCC_MCO_SEL_PLL,            /*!< Selects PLL as MCO output */
    RCC_MCO_SEL_AUXCLK,         /*!< Selects Auxiliary Clock as MCO output */
    RCC_MCO_SEL_NONE            /*!< No clock selected for MCO output */
} RCC_McoSourceSel;

/**
  * @}
  */

/** @defgroup RCC_MCODIVSEL RCC MCO Clock Division Selection
  * @{
  * @brief  Macro definitions about MCO clock division.
  */
typedef enum {
    RCC_MCO_DIV_1 = 0U,    /*!< No division (divide by 1) */
    RCC_MCO_DIV_2,         /*!< Divide by 2 */
    RCC_MCO_DIV_4,         /*!< Divide by 4 */
    RCC_MCO_DIV_6,         /*!< Divide by 6 */
    RCC_MCO_DIV_8,         /*!< Divide by 8 */
    RCC_MCO_DIV_10,        /*!< Divide by 10 */
    RCC_MCO_DIV_12,        /*!< Divide by 12 */
    RCC_MCO_DIV_14,        /*!< Divide by 14 */
    RCC_MCO_DIV_16,        /*!< Divide by 16 */
    RCC_MCO_DIV_18,        /*!< Divide by 18 */
    RCC_MCO_DIV_20,        /*!< Divide by 20 */
    RCC_MCO_DIV_22,        /*!< Divide by 22 */
    RCC_MCO_DIV_24,        /*!< Divide by 24 */
    RCC_MCO_DIV_26,        /*!< Divide by 26 */
    RCC_MCO_DIV_28,        /*!< Divide by 28 */
    RCC_MCO_DIV_30,        /*!< Divide by 30 */
    RCC_MCO_DIV_32,        /*!< Divide by 32 */
    RCC_MCO_DIV_34,        /*!< Divide by 34 */
    RCC_MCO_DIV_36,        /*!< Divide by 36 */
    RCC_MCO_DIV_38,        /*!< Divide by 38 */
    RCC_MCO_DIV_40,        /*!< Divide by 40 */
    RCC_MCO_DIV_42,        /*!< Divide by 42 */
    RCC_MCO_DIV_44,        /*!< Divide by 44 */
    RCC_MCO_DIV_46,        /*!< Divide by 46 */
    RCC_MCO_DIV_48,        /*!< Divide by 48 */
    RCC_MCO_DIV_50,        /*!< Divide by 50 */
    RCC_MCO_DIV_52,        /*!< Divide by 52 */
    RCC_MCO_DIV_54,        /*!< Divide by 54 */
    RCC_MCO_DIV_56,        /*!< Divide by 56 */
    RCC_MCO_DIV_58,        /*!< Divide by 58 */
    RCC_MCO_DIV_60,        /*!< Divide by 60 */
    RCC_MCO_DIV_62,        /*!< Divide by 62 */
    RCC_MCO_DIV_64,        /*!< Divide by 64 */
    RCC_MCO_DIV_66,        /*!< Divide by 66 */
    RCC_MCO_DIV_68,        /*!< Divide by 68 */
    RCC_MCO_DIV_70,        /*!< Divide by 70 */
    RCC_MCO_DIV_72,        /*!< Divide by 72 */
    RCC_MCO_DIV_74,        /*!< Divide by 74 */
    RCC_MCO_DIV_76,        /*!< Divide by 76 */
    RCC_MCO_DIV_78,        /*!< Divide by 78 */
    RCC_MCO_DIV_80,        /*!< Divide by 80 */
    RCC_MCO_DIV_82,        /*!< Divide by 82 */
    RCC_MCO_DIV_84,        /*!< Divide by 84 */
    RCC_MCO_DIV_86,        /*!< Divide by 86 */
    RCC_MCO_DIV_88,        /*!< Divide by 88 */
    RCC_MCO_DIV_90,        /*!< Divide by 90 */
    RCC_MCO_DIV_92,        /*!< Divide by 92 */
    RCC_MCO_DIV_94,        /*!< Divide by 94 */
    RCC_MCO_DIV_96,        /*!< Divide by 96 */
    RCC_MCO_DIV_98,        /*!< Divide by 98 */
    RCC_MCO_DIV_100,       /*!< Divide by 100 */
    RCC_MCO_DIV_102,       /*!< Divide by 102 */
    RCC_MCO_DIV_104,       /*!< Divide by 104 */
    RCC_MCO_DIV_106,       /*!< Divide by 106 */
    RCC_MCO_DIV_108,       /*!< Divide by 108 */
    RCC_MCO_DIV_110,       /*!< Divide by 110 */
    RCC_MCO_DIV_112,       /*!< Divide by 112 */
    RCC_MCO_DIV_114,       /*!< Divide by 114 */
    RCC_MCO_DIV_116,       /*!< Divide by 116 */
    RCC_MCO_DIV_118,       /*!< Divide by 118 */
    RCC_MCO_DIV_120,       /*!< Divide by 120 */
    RCC_MCO_DIV_122,       /*!< Divide by 122 */
    RCC_MCO_DIV_124,       /*!< Divide by 124 */
    RCC_MCO_DIV_126,       /*!< Divide by 126 */
    RCC_MCO_DIV_128,       /*!< Divide by 128 */
    RCC_MCO_DIV_130,       /*!< Divide by 130 */
    RCC_MCO_DIV_132,       /*!< Divide by 132 */
    RCC_MCO_DIV_134,       /*!< Divide by 134 */
    RCC_MCO_DIV_136,       /*!< Divide by 136 */
    RCC_MCO_DIV_138,       /*!< Divide by 138 */
    RCC_MCO_DIV_140,       /*!< Divide by 140 */
    RCC_MCO_DIV_142,       /*!< Divide by 142 */
    RCC_MCO_DIV_144,       /*!< Divide by 144 */
    RCC_MCO_DIV_146,       /*!< Divide by 146 */
    RCC_MCO_DIV_148,       /*!< Divide by 148 */
    RCC_MCO_DIV_150,       /*!< Divide by 150 */
    RCC_MCO_DIV_152,       /*!< Divide by 152 */
    RCC_MCO_DIV_154,       /*!< Divide by 154 */
    RCC_MCO_DIV_156,       /*!< Divide by 156 */
    RCC_MCO_DIV_158,       /*!< Divide by 158 */
    RCC_MCO_DIV_160,       /*!< Divide by 160 */
    RCC_MCO_DIV_162,       /*!< Divide by 162 */
    RCC_MCO_DIV_164,       /*!< Divide by 164 */
    RCC_MCO_DIV_166,       /*!< Divide by 166 */
    RCC_MCO_DIV_168,       /*!< Divide by 168 */
    RCC_MCO_DIV_170,       /*!< Divide by 170 */
    RCC_MCO_DIV_172,       /*!< Divide by 172 */
    RCC_MCO_DIV_174,       /*!< Divide by 174 */
    RCC_MCO_DIV_176,       /*!< Divide by 176 */
    RCC_MCO_DIV_178,       /*!< Divide by 178 */
    RCC_MCO_DIV_180,       /*!< Divide by 180 */
    RCC_MCO_DIV_182,       /*!< Divide by 182 */
    RCC_MCO_DIV_184,       /*!< Divide by 184 */
    RCC_MCO_DIV_186,       /*!< Divide by 186 */
    RCC_MCO_DIV_188,       /*!< Divide by 188 */
    RCC_MCO_DIV_190,       /*!< Divide by 190 */
    RCC_MCO_DIV_192,       /*!< Divide by 192 */
    RCC_MCO_DIV_194,       /*!< Divide by 194 */
    RCC_MCO_DIV_196,       /*!< Divide by 196 */
    RCC_MCO_DIV_198,       /*!< Divide by 198 */
    RCC_MCO_DIV_200,       /*!< Divide by 200 */
    RCC_MCO_DIV_202,       /*!< Divide by 202 */
    RCC_MCO_DIV_204,       /*!< Divide by 204 */
    RCC_MCO_DIV_206,       /*!< Divide by 206 */
    RCC_MCO_DIV_208,       /*!< Divide by 208 */
    RCC_MCO_DIV_210,       /*!< Divide by 210 */
    RCC_MCO_DIV_212,       /*!< Divide by 212 */
    RCC_MCO_DIV_214,       /*!< Divide by 214 */
    RCC_MCO_DIV_216,       /*!< Divide by 216 */
    RCC_MCO_DIV_218,       /*!< Divide by 218 */
    RCC_MCO_DIV_220,       /*!< Divide by 220 */
    RCC_MCO_DIV_222,       /*!< Divide by 222 */
    RCC_MCO_DIV_224,       /*!< Divide by 224 */
    RCC_MCO_DIV_226,       /*!< Divide by 226 */
    RCC_MCO_DIV_228,       /*!< Divide by 228 */
    RCC_MCO_DIV_230,       /*!< Divide by 230 */
    RCC_MCO_DIV_232,       /*!< Divide by 232 */
    RCC_MCO_DIV_234,       /*!< Divide by 234 */
    RCC_MCO_DIV_236,       /*!< Divide by 236 */
    RCC_MCO_DIV_238,       /*!< Divide by 238 */
    RCC_MCO_DIV_240,       /*!< Divide by 240 */
    RCC_MCO_DIV_242,       /*!< Divide by 242 */
    RCC_MCO_DIV_244,       /*!< Divide by 244 */
    RCC_MCO_DIV_246,       /*!< Divide by 246 */
    RCC_MCO_DIV_248,       /*!< Divide by 248 */
    RCC_MCO_DIV_250,       /*!< Divide by 250 */
    RCC_MCO_DIV_252,       /*!< Divide by 252 */
    RCC_MCO_DIV_254,       /*!< Divide by 254 */
    RCC_MCO_DIV_256,       /*!< Divide by 256 */
    RCC_MCO_DIV_258,       /*!< Divide by 258 */
    RCC_MCO_DIV_260,       /*!< Divide by 260 */
    RCC_MCO_DIV_262,       /*!< Divide by 262 */
    RCC_MCO_DIV_264,       /*!< Divide by 264 */
    RCC_MCO_DIV_266,       /*!< Divide by 266 */
    RCC_MCO_DIV_268,       /*!< Divide by 268 */
    RCC_MCO_DIV_270,       /*!< Divide by 270 */
    RCC_MCO_DIV_272,       /*!< Divide by 272 */
    RCC_MCO_DIV_274,       /*!< Divide by 274 */
    RCC_MCO_DIV_276,       /*!< Divide by 276 */
    RCC_MCO_DIV_278,       /*!< Divide by 278 */
    RCC_MCO_DIV_280,       /*!< Divide by 280 */
    RCC_MCO_DIV_282,       /*!< Divide by 282 */
    RCC_MCO_DIV_284,       /*!< Divide by 284 */
    RCC_MCO_DIV_286,       /*!< Divide by 286 */
    RCC_MCO_DIV_288,       /*!< Divide by 288 */
    RCC_MCO_DIV_290,       /*!< Divide by 290 */
    RCC_MCO_DIV_292,       /*!< Divide by 292 */
    RCC_MCO_DIV_294,       /*!< Divide by 294 */
    RCC_MCO_DIV_296,       /*!< Divide by 296 */
    RCC_MCO_DIV_298,       /*!< Divide by 298 */
    RCC_MCO_DIV_300,       /*!< Divide by 300 */
    RCC_MCO_DIV_302,       /*!< Divide by 302 */
    RCC_MCO_DIV_304,       /*!< Divide by 304 */
    RCC_MCO_DIV_306,       /*!< Divide by 306 */
    RCC_MCO_DIV_308,       /*!< Divide by 308 */
    RCC_MCO_DIV_310,       /*!< Divide by 310 */
    RCC_MCO_DIV_312,       /*!< Divide by 312 */
    RCC_MCO_DIV_314,       /*!< Divide by 314 */
    RCC_MCO_DIV_316,       /*!< Divide by 316 */
    RCC_MCO_DIV_318,       /*!< Divide by 318 */
    RCC_MCO_DIV_320,       /*!< Divide by 320 */
    RCC_MCO_DIV_322,       /*!< Divide by 322 */
    RCC_MCO_DIV_324,       /*!< Divide by 324 */
    RCC_MCO_DIV_326,       /*!< Divide by 326 */
    RCC_MCO_DIV_328,       /*!< Divide by 328 */
    RCC_MCO_DIV_330,       /*!< Divide by 330 */
    RCC_MCO_DIV_332,       /*!< Divide by 332 */
    RCC_MCO_DIV_334,       /*!< Divide by 334 */
    RCC_MCO_DIV_336,       /*!< Divide by 336 */
    RCC_MCO_DIV_338,       /*!< Divide by 338 */
    RCC_MCO_DIV_340,       /*!< Divide by 340 */
    RCC_MCO_DIV_342,       /*!< Divide by 342 */
    RCC_MCO_DIV_344,       /*!< Divide by 344 */
    RCC_MCO_DIV_346,       /*!< Divide by 346 */
    RCC_MCO_DIV_348,       /*!< Divide by 348 */
    RCC_MCO_DIV_350,       /*!< Divide by 350 */
    RCC_MCO_DIV_352,       /*!< Divide by 352 */
    RCC_MCO_DIV_354,       /*!< Divide by 354 */
    RCC_MCO_DIV_356,       /*!< Divide by 356 */
    RCC_MCO_DIV_358,       /*!< Divide by 358 */
    RCC_MCO_DIV_360,       /*!< Divide by 360 */
    RCC_MCO_DIV_362,       /*!< Divide by 362 */
    RCC_MCO_DIV_364,       /*!< Divide by 364 */
    RCC_MCO_DIV_366,       /*!< Divide by 366 */
    RCC_MCO_DIV_368,       /*!< Divide by 368 */
    RCC_MCO_DIV_370,       /*!< Divide by 370 */
    RCC_MCO_DIV_372,       /*!< Divide by 372 */
    RCC_MCO_DIV_374,       /*!< Divide by 374 */
    RCC_MCO_DIV_376,       /*!< Divide by 376 */
    RCC_MCO_DIV_378,       /*!< Divide by 378 */
    RCC_MCO_DIV_380,       /*!< Divide by 380 */
    RCC_MCO_DIV_382,       /*!< Divide by 382 */
    RCC_MCO_DIV_384,       /*!< Divide by 384 */
    RCC_MCO_DIV_386,       /*!< Divide by 386 */
    RCC_MCO_DIV_388,       /*!< Divide by 388 */
    RCC_MCO_DIV_390,       /*!< Divide by 390 */
    RCC_MCO_DIV_392,       /*!< Divide by 392 */
    RCC_MCO_DIV_394,       /*!< Divide by 394 */
    RCC_MCO_DIV_396,       /*!< Divide by 396 */
    RCC_MCO_DIV_398,       /*!< Divide by 398 */
    RCC_MCO_DIV_400,       /*!< Divide by 400 */
    RCC_MCO_DIV_402,       /*!< Divide by 402 */
    RCC_MCO_DIV_404,       /*!< Divide by 404 */
    RCC_MCO_DIV_406,       /*!< Divide by 406 */
    RCC_MCO_DIV_408,       /*!< Divide by 408 */
    RCC_MCO_DIV_410,       /*!< Divide by 410 */
    RCC_MCO_DIV_412,       /*!< Divide by 412 */
    RCC_MCO_DIV_414,       /*!< Divide by 414 */
    RCC_MCO_DIV_416,       /*!< Divide by 416 */
    RCC_MCO_DIV_418,       /*!< Divide by 418 */
    RCC_MCO_DIV_420,       /*!< Divide by 420 */
    RCC_MCO_DIV_422,       /*!< Divide by 422 */
    RCC_MCO_DIV_424,       /*!< Divide by 424 */
    RCC_MCO_DIV_426,       /*!< Divide by 426 */
    RCC_MCO_DIV_428,       /*!< Divide by 428 */
    RCC_MCO_DIV_430,       /*!< Divide by 430 */
    RCC_MCO_DIV_432,       /*!< Divide by 432 */
    RCC_MCO_DIV_434,       /*!< Divide by 434 */
    RCC_MCO_DIV_436,       /*!< Divide by 436 */
    RCC_MCO_DIV_438,       /*!< Divide by 438 */
    RCC_MCO_DIV_440,       /*!< Divide by 440 */
    RCC_MCO_DIV_442,       /*!< Divide by 442 */
    RCC_MCO_DIV_444,       /*!< Divide by 444 */
    RCC_MCO_DIV_446,       /*!< Divide by 446 */
    RCC_MCO_DIV_448,       /*!< Divide by 448 */
    RCC_MCO_DIV_450,       /*!< Divide by 450 */
    RCC_MCO_DIV_452,       /*!< Divide by 452 */
    RCC_MCO_DIV_454,       /*!< Divide by 454 */
    RCC_MCO_DIV_456,       /*!< Divide by 456 */
    RCC_MCO_DIV_458,       /*!< Divide by 458 */
    RCC_MCO_DIV_460,       /*!< Divide by 460 */
    RCC_MCO_DIV_462,       /*!< Divide by 462 */
    RCC_MCO_DIV_464,       /*!< Divide by 464 */
    RCC_MCO_DIV_466,       /*!< Divide by 466 */
    RCC_MCO_DIV_468,       /*!< Divide by 468 */
    RCC_MCO_DIV_470,       /*!< Divide by 470 */
    RCC_MCO_DIV_472,       /*!< Divide by 472 */
    RCC_MCO_DIV_474,       /*!< Divide by 474 */
    RCC_MCO_DIV_476,       /*!< Divide by 476 */
    RCC_MCO_DIV_478,       /*!< Divide by 478 */
    RCC_MCO_DIV_480,       /*!< Divide by 480 */
    RCC_MCO_DIV_482,       /*!< Divide by 482 */
    RCC_MCO_DIV_484,       /*!< Divide by 484 */
    RCC_MCO_DIV_486,       /*!< Divide by 486 */
    RCC_MCO_DIV_488,       /*!< Divide by 488 */
    RCC_MCO_DIV_490,       /*!< Divide by 490 */
    RCC_MCO_DIV_492,       /*!< Divide by 492 */
    RCC_MCO_DIV_494,       /*!< Divide by 494 */
    RCC_MCO_DIV_496,       /*!< Divide by 496 */
    RCC_MCO_DIV_498,       /*!< Divide by 498 */
    RCC_MCO_DIV_500,       /*!< Divide by 500 */
    RCC_MCO_DIV_502,       /*!< Divide by 502 */
    RCC_MCO_DIV_504,       /*!< Divide by 504 */
    RCC_MCO_DIV_506,       /*!< Divide by 506 */
    RCC_MCO_DIV_508,       /*!< Divide by 508 */
    RCC_MCO_DIV_510        /*!< Divide by 510 */
} RCC_McoDivSel;

/**
  * @}
  */

/** @defgroup RCC_APB5SRC RCC APB5 Clock Source Selection
  * @{
  * @brief  Macro definitions about APB5 clock source.
  */
typedef enum {
    RCC_APB5_HCLK_DIV1 = 0U,    /*!< APB5 Clock From HCLK divided by 1 */
    RCC_APB5_HCLK_DIV2,         /*!< APB5 Clock From HCLK divided by 2 */
    RCC_APB5_HCLK_DIV4,         /*!< APB5 Clock From HCLK divided by 4 */
    RCC_APB5_HCLK_DIV8,         /*!< APB5 Clock From HCLK divided by 8 */
    RCC_APB5_HCLK_DIV16         /*!< APB5 Clock From HCLK divided by 16 */
} RCC_Apb5Src;

/**
  * @}
  */

/** @defgroup RCC_APB2AND4SRC RCC APB2 and APB4 Clock Source Selection
  * @{
  * @brief  Macro definitions for APB2 and APB4 clock source selection.
  */
typedef enum {
    RCC_APB2_4_HCLK_DIV1 = 0U,    /*!< APB2 and APB4 Clock From HCLK divided by 1 */
    RCC_APB2_4_HCLK_DIV2,         /*!< APB2 and APB4 Clock From HCLK divided by 2 */
    RCC_APB2_4_HCLK_DIV4,         /*!< APB2 and APB4 Clock From HCLK divided by 4 */
    RCC_APB2_4_HCLK_DIV8,         /*!< APB2 and APB4 Clock From HCLK divided by 8 */
    RCC_APB2_4_HCLK_DIV16         /*!< APB2 and APB4 Clock From HCLK divided by 16 */
} RCC_Apb2And4Src;

/**
  * @}
  */

/** @defgroup RCC_APB1AND3SRC RCC APB1 and APB3 Clock Source Selection
  * @{
  * @brief  Macro definitions for APB1 and APB3 clock source selection.
  */
typedef enum {
    RCC_APB1_3_HCLK_DIV1 = 0U,    /*!< APB1 and APB3 Clock From HCLK divided by 1 */
    RCC_APB1_3_HCLK_DIV2,         /*!< APB1 and APB3 Clock From HCLK divided by 2 */
    RCC_APB1_3_HCLK_DIV4,         /*!< APB1 and APB3 Clock From HCLK divided by 4 */
    RCC_APB1_3_HCLK_DIV8,         /*!< APB1 and APB3 Clock From HCLK divided by 8 */
    RCC_APB1_3_HCLK_DIV16         /*!< APB1 and APB3 Clock From HCLK divided by 16 */
} RCC_Apb1And3Src;

/**
  * @}
  */

/** @defgroup RCC_HCLKSEL RCC BUS Clock Source Selection
  * @{
  * @brief  Macro definitions for BUS clock source selection.
  */
typedef enum {
    RCC_HCLKSOURCE_CPUCLK = 0U,    /*!< BUS Clock divided by 1 */
    RCC_HCLKSOURCE_CPUCLK_2        /*!< BUS Clock divided by 2 */
} RCC_HclkSel;

/**
  * @}
  */

/** @defgroup RCC_SYSCLKDIVSEL RCC System Clock Division Selection
  * @{
  * @brief  Macro definitions for system clock division selection.
  */
typedef enum {
    RCC_SYSCLK_DIV1 = 0U,    /*!< System Clock From SYSCLK divided by 1 */
    RCC_SYSCLK_DIV2,         /*!< System Clock From SYSCLK divided by 2 */
    RCC_SYSCLK_DIV4,         /*!< System Clock From SYSCLK divided by 4 */
    RCC_SYSCLK_DIV8,         /*!< System Clock From SYSCLK divided by 8 */
    RCC_SYSCLK_DIV16,        /*!< System Clock From SYSCLK divided by 16 */
    RCC_SYSCLK_DIV32,        /*!< System Clock From SYSCLK divided by 32 */
    RCC_SYSCLK_DIV64,        /*!< System Clock From SYSCLK divided by 64 */
    RCC_SYSCLK_DIV128,       /*!< System Clock From SYSCLK divided by 128 */
    RCC_SYSCLK_DIV256,       /*!< System Clock From SYSCLK divided by 256 */
    RCC_SYSCLK_DIV512        /*!< System Clock From SYSCLK divided by 512 */
} RCC_SysclkDivSel;

/**
  * @}
  */

/** @defgroup RCC_SYSCLKSTATUS RCC System Clock Status
  * @{
  * @brief  Macro definitions for system clock status.
  */
typedef enum {
    RCC_SYSCLKSTATUS_MIRC2 = 0U,    /*!< System Clock from MIRC2 */
    RCC_SYSCLKSTATUS_HXTL,          /*!< System Clock from HXTL */
    RCC_SYSCLKSTATUS_PLL,           /*!< System Clock from PLL */
    RCC_SYSCLKSTATUS_MIRC1          /*!< System Clock from MIRC1 */
} RCC_SysclkStatus;

/**
  * @}
  */

/** @defgroup RCC_SYSCLKSRC RCC System Clock Source Selection
  * @{
  * @brief  Macro definitions for system clock source selection.
  */
typedef enum {
    RCC_SYSCLKSOURCE_MIRC2 = 0U,    /*!< Select System Clock from MIRC2 */
    RCC_SYSCLKSOURCE_HXTL,          /*!< Select System Clock from HXTL */
    RCC_SYSCLKSOURCE_PLL,           /*!< Select System Clock from PLL */
    RCC_SYSCLKSOURCE_MIRC1          /*!< Select System Clock from MIRC1 */
} RCC_SysclkSrc;

/**
  * @}
  */

/** @defgroup RCC_PLLSRC RCC PLL Clock Source Selection
  * @{
  * @brief  Macro definitions for PLL clock source selection.
  */
typedef enum {
    RCC_PLLSOURCE_MIRC2 = 0U,    /*!< Select PLL Clock from MIRC2 */
    RCC_PLLSOURCE_HXTL,          /*!< Select PLL Clock from HXTL */
    RCC_PLLSOURCE_MIRC1          /*!< Select PLL Clock from MIRC1 */
} RCC_PllSrc;

/**
  * @}
  */

/** @defgroup RCC_OSCCLKFAULTINTSEL RCC OSCCLK Fault interruption source Selection
  * @{
  * @brief  When OSCCLK Fault, NMI/CMU interrupt is generated.
  */
typedef enum {
    RCC_OSCCLKFAULTINTSEL_NMI = 0x0U,    /*!< When OSCCLK Fault, NMI interrupt is generated. */
    RCC_OSCCLKFAULTINTSEL_CMU            /*!< When OSCCLK Fault, CMU interrupt is generated. */
} RCC_OscclkFaultIntSel;

/**
  * @}
  */

/** @defgroup RCC_HXTLFAULTINTSEL RCC OSCCLK Fault interruption source Selection
  * @{
  * @brief  When HXTL Fault, NMI/CMU interrupt is generated.
  */
typedef enum {
    RCC_HXTLFAULTINTSEL_NMI = 0x0U,    /*!< When HXTL Fault, NMI interrupt is generated. */
    RCC_HXTLFAULTINTSEL_CMU            /*!< When HXTL Fault, CMU interrupt is generated. */
} RCC_HxtlFaultIntSel;

/**
  * @}
  */

/** @defgroup RCC_CANFDPCLKSOURCE CANFD Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for selecting the clock source for the CANFD peripheral.
  */
typedef enum {
    RCC_CANFDPCLK_SOURCE_OSC = 0U,    /*!< Select OSC (Oscillator) as the CANFD peripheral clock source */
    RCC_CANFDPCLK_SOURCE_PERIPHERAL   /*!< Select PERIPHERAL (Peripheral Clock) as the CANFD peripheral clock source */
} RCC_CanfdPclkSource;

/**
  * @}
  */

/** @defgroup RCC_CANFDTIMECLKDIV CANFD Time Base Clock Division Selection
  * @{
  * @brief  Macro definitions for CANFD time base clock division selection.
  */
typedef enum {
    RCC_CANFD_TIMECLK_DIV8 = 0U,    /*!< Divide the CANFD time base clock by 8 */
    RCC_CANFD_TIMECLK_DIV16,        /*!< Divide the CANFD time base clock by 16 */
    RCC_CANFD_TIMECLK_DIV24,        /*!< Divide the CANFD time base clock by 24 */
    RCC_CANFD_TIMECLK_DIV48         /*!< Divide the CANFD time base clock by 48 */
} RCC_CanfdTimeclkDiv;

/**
  * @}
  */

/** @defgroup RCC_CANFDOSCCLK CANFD Oscillator Clock Source Selection
  * @{
  * @brief  Macro definitions for CANFD oscillator clock source selection.
  */
typedef enum {
    RCC_CANFD_OSCCLK_SEL_MIRC2KER = 0U,    /*!< Select MIRC2 as the CANFD oscillator clock source */
    RCC_CANFD_OSCCLK_SEL_HXTLKER,          /*!< Select HXTL as the CANFD oscillator clock source */
    RCC_CANFD_OSCCLK_SEL_AUX               /*!< Select AUX as the CANFD oscillator clock source */
} RCC_CanfdOscClk;

/**
  * @}
  */

/** @defgroup RCC_CANFD1PERIPHERALCLK CANFD1 Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for CANFD1 peripheral clock source selection.
  */
typedef enum {
    RCC_CANFD1_PERIPHERAL_CLK_SEL_HCLK = 0U,    /*!< Select HCLK as the CANFD1 peripheral clock source */
    RCC_CANFD1_PERIPHERAL_CLK_SEL_PLL_CLKQ      /*!< Select PLL_CLKQ as the CANFD1 peripheral clock source */
} RCC_Canfd1PeripheralClk;

/**
  * @}
  */

/** @defgroup RCC_CANFD2PERIPHERALCLK CANFD2 Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for CANFD2 peripheral clock source selection.
  */
typedef enum {
    RCC_CANFD2_PERIPHERAL_CLK_SEL_HCLK = 0U,    /*!< Select HCLK as the CANFD2 peripheral clock source */
    RCC_CANFD2_PERIPHERAL_CLK_SEL_PLL_CLKR      /*!< Select PLL_CLKR as the CANFD2 peripheral clock source */
} RCC_Canfd2PeripheralClk;

/**
  * @}
  */

/** @defgroup RCC_CAN1PCLKSOURCE CAN1 Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for CAN1 peripheral clock source selection.
  */
typedef enum {
    RCC_CAN1PCLK_SOURCE_OSC = 0U,    /*!< Select OSC as the CAN1 peripheral clock source */
    RCC_CAN1PCLK_SOURCE_PERIPHERAL   /*!< Select PERIPHERAL as the CAN1 peripheral clock source */
} RCC_Can1PclkSource;

/**
  * @}
  */

/** @defgroup RCC_CAN1TIMECLKDIV CAN1 Time Base Clock Division Selection
  * @{
  * @brief  Macro definitions for CAN1 time base clock division selection.
  */
typedef enum {
    RCC_CAN1_TIMECLK_DIV8 = 0U,    /*!< Divide the CAN1 time base clock by 8 */
    RCC_CAN1_TIMECLK_DIV16,        /*!< Divide the CAN1 time base clock by 16 */
    RCC_CAN1_TIMECLK_DIV24,        /*!< Divide the CAN1 time base clock by 24 */
    RCC_CAN1_TIMECLK_DIV48         /*!< Divide the CAN1 time base clock by 48 */
} RCC_Can1TimeclkDiv;

/**
  * @}
  */

/** @defgroup RCC_CAN1OSCCLK CAN1 Oscillator Clock Source Selection
  * @{
  * @brief  Macro definitions for CAN1 oscillator clock source selection.
  */
typedef enum {
    RCC_CAN1_OSCCLK_SEL_MIRC2KER = 0U,    /*!< Select MIRC2 as the CAN1 oscillator clock source */
    RCC_CAN1_OSCCLK_SEL_HXTLKER,          /*!< Select HXTL as the CAN1 oscillator clock source */
    RCC_CAN1_OSCCLK_SEL_AUX               /*!< Select AUX as the CAN1 oscillator clock source */
} RCC_Can1OscClk;

/**
  * @}
  */

/** @defgroup RCC_CAN1PERIPHERALCLK CAN1 Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for CAN1 peripheral clock source selection.
  */
typedef enum {
    RCC_CAN1_PERIPHERAL_CLK_SEL_HCLK = 0U,    /*!< Select HCLK as the CAN1 peripheral clock source */
    RCC_CAN1_PERIPHERAL_CLK_SEL_PLL_CLKR,     /*!< Select PLL_CLKR as the CAN1 peripheral clock source */
} RCC_Can1PeripheralClk;

/**
  * @}
  */

/** @defgroup RCC_PLLMSELECTION RCC PLLM Selection
  * @{
  * @brief  Macro definitions for selecting the PLLM doubling factor.
  */
typedef enum {
    RCC_PLLM_2 = 2U,    /*!< Select PLLM doubling factor as 2 */
    RCC_PLLM_3,         /*!< Select PLLM doubling factor as 3 */
    RCC_PLLM_4,         /*!< Select PLLM doubling factor as 4 */
    RCC_PLLM_5,         /*!< Select PLLM doubling factor as 5 */
    RCC_PLLM_6,         /*!< Select PLLM doubling factor as 6 */
    RCC_PLLM_7,         /*!< Select PLLM doubling factor as 7 */
    RCC_PLLM_8,         /*!< Select PLLM doubling factor as 8 */
    RCC_PLLM_9,         /*!< Select PLLM doubling factor as 9 */
    RCC_PLLM_10,        /*!< Select PLLM doubling factor as 10 */
    RCC_PLLM_11,        /*!< Select PLLM doubling factor as 11 */
    RCC_PLLM_12,        /*!< Select PLLM doubling factor as 12 */
    RCC_PLLM_13,        /*!< Select PLLM doubling factor as 13 */
    RCC_PLLM_14,        /*!< Select PLLM doubling factor as 14 */
    RCC_PLLM_15,        /*!< Select PLLM doubling factor as 15 */
    RCC_PLLM_16,        /*!< Select PLLM doubling factor as 16 */
    RCC_PLLM_17,        /*!< Select PLLM doubling factor as 17 */
    RCC_PLLM_18,        /*!< Select PLLM doubling factor as 18 */
    RCC_PLLM_19,        /*!< Select PLLM doubling factor as 19 */
    RCC_PLLM_20,        /*!< Select PLLM doubling factor as 20 */
    RCC_PLLM_21,        /*!< Select PLLM doubling factor as 21 */
    RCC_PLLM_22,        /*!< Select PLLM doubling factor as 22 */
    RCC_PLLM_23,        /*!< Select PLLM doubling factor as 23 */
    RCC_PLLM_24,        /*!< Select PLLM doubling factor as 24 */
    RCC_PLLM_25,        /*!< Select PLLM doubling factor as 25 */
    RCC_PLLM_26,        /*!< Select PLLM doubling factor as 26 */
    RCC_PLLM_27,        /*!< Select PLLM doubling factor as 27 */
    RCC_PLLM_28,        /*!< Select PLLM doubling factor as 28 */
    RCC_PLLM_29,        /*!< Select PLLM doubling factor as 29 */
    RCC_PLLM_30,        /*!< Select PLLM doubling factor as 30 */
    RCC_PLLM_31,        /*!< Select PLLM doubling factor as 31 */
    RCC_PLLM_32,        /*!< Select PLLM doubling factor as 32 */
    RCC_PLLM_33,        /*!< Select PLLM doubling factor as 33 */
    RCC_PLLM_34,        /*!< Select PLLM doubling factor as 34 */
    RCC_PLLM_35,        /*!< Select PLLM doubling factor as 35 */
    RCC_PLLM_36,        /*!< Select PLLM doubling factor as 36 */
    RCC_PLLM_37,        /*!< Select PLLM doubling factor as 37 */
    RCC_PLLM_38,        /*!< Select PLLM doubling factor as 38 */
    RCC_PLLM_39,        /*!< Select PLLM doubling factor as 39 */
    RCC_PLLM_40,        /*!< Select PLLM doubling factor as 40 */
    RCC_PLLM_41,        /*!< Select PLLM doubling factor as 41 */
    RCC_PLLM_42,        /*!< Select PLLM doubling factor as 42 */
    RCC_PLLM_43,        /*!< Select PLLM doubling factor as 43 */
    RCC_PLLM_44,        /*!< Select PLLM doubling factor as 44 */
    RCC_PLLM_45,        /*!< Select PLLM doubling factor as 45 */
    RCC_PLLM_46,        /*!< Select PLLM doubling factor as 46 */
    RCC_PLLM_47,        /*!< Select PLLM doubling factor as 47 */
    RCC_PLLM_48,        /*!< Select PLLM doubling factor as 48 */
    RCC_PLLM_49,        /*!< Select PLLM doubling factor as 49 */
    RCC_PLLM_50,        /*!< Select PLLM doubling factor as 50 */
    RCC_PLLM_51,        /*!< Select PLLM doubling factor as 51 */
    RCC_PLLM_52,        /*!< Select PLLM doubling factor as 52 */
    RCC_PLLM_53,        /*!< Select PLLM doubling factor as 53 */
    RCC_PLLM_54,        /*!< Select PLLM doubling factor as 54 */
    RCC_PLLM_55,        /*!< Select PLLM doubling factor as 55 */
    RCC_PLLM_56,        /*!< Select PLLM doubling factor as 56 */
    RCC_PLLM_57,        /*!< Select PLLM doubling factor as 57 */
    RCC_PLLM_58,        /*!< Select PLLM doubling factor as 58 */
    RCC_PLLM_59,        /*!< Select PLLM doubling factor as 59 */
    RCC_PLLM_60,        /*!< Select PLLM doubling factor as 60 */
    RCC_PLLM_61,        /*!< Select PLLM doubling factor as 61 */
    RCC_PLLM_62,        /*!< Select PLLM doubling factor as 62 */
    RCC_PLLM_63,        /*!< Select PLLM doubling factor as 63 */
    RCC_PLLM_64,        /*!< Select PLLM doubling factor as 64 */
    RCC_PLLM_65,        /*!< Select PLLM doubling factor as 65 */
    RCC_PLLM_66,        /*!< Select PLLM doubling factor as 66 */
    RCC_PLLM_67,        /*!< Select PLLM doubling factor as 67 */
    RCC_PLLM_68,        /*!< Select PLLM doubling factor as 68 */
    RCC_PLLM_69,        /*!< Select PLLM doubling factor as 69 */
    RCC_PLLM_70,        /*!< Select PLLM doubling factor as 70 */
    RCC_PLLM_71,        /*!< Select PLLM doubling factor as 71 */
    RCC_PLLM_72,        /*!< Select PLLM doubling factor as 72 */
    RCC_PLLM_73,        /*!< Select PLLM doubling factor as 73 */
    RCC_PLLM_74,        /*!< Select PLLM doubling factor as 74 */
    RCC_PLLM_75,        /*!< Select PLLM doubling factor as 75 */
    RCC_PLLM_76,        /*!< Select PLLM doubling factor as 76 */
    RCC_PLLM_77,        /*!< Select PLLM doubling factor as 77 */
    RCC_PLLM_78,        /*!< Select PLLM doubling factor as 78 */
    RCC_PLLM_79,        /*!< Select PLLM doubling factor as 79 */
    RCC_PLLM_80,        /*!< Select PLLM doubling factor as 80 */
    RCC_PLLM_81,        /*!< Select PLLM doubling factor as 81 */
    RCC_PLLM_82,        /*!< Select PLLM doubling factor as 82 */
    RCC_PLLM_83,        /*!< Select PLLM doubling factor as 83 */
    RCC_PLLM_84,        /*!< Select PLLM doubling factor as 84 */
    RCC_PLLM_85,        /*!< Select PLLM doubling factor as 85 */
    RCC_PLLM_86,        /*!< Select PLLM doubling factor as 86 */
    RCC_PLLM_87,        /*!< Select PLLM doubling factor as 87 */
    RCC_PLLM_88,        /*!< Select PLLM doubling factor as 88 */
    RCC_PLLM_89,        /*!< Select PLLM doubling factor as 89 */
    RCC_PLLM_90,        /*!< Select PLLM doubling factor as 90 */
    RCC_PLLM_91,        /*!< Select PLLM doubling factor as 91 */
    RCC_PLLM_92,        /*!< Select PLLM doubling factor as 92 */
    RCC_PLLM_93,        /*!< Select PLLM doubling factor as 93 */
    RCC_PLLM_94,        /*!< Select PLLM doubling factor as 94 */
    RCC_PLLM_95,        /*!< Select PLLM doubling factor as 95 */
    RCC_PLLM_96,        /*!< Select PLLM doubling factor as 96 */
    RCC_PLLM_97,        /*!< Select PLLM doubling factor as 97 */
    RCC_PLLM_98,        /*!< Select PLLM doubling factor as 98 */
    RCC_PLLM_99,        /*!< Select PLLM doubling factor as 99 */
    RCC_PLLM_100,       /*!< Select PLLM doubling factor as 100 */
    RCC_PLLM_101,       /*!< Select PLLM doubling factor as 101 */
    RCC_PLLM_102,       /*!< Select PLLM doubling factor as 102 */
    RCC_PLLM_103,       /*!< Select PLLM doubling factor as 103 */
    RCC_PLLM_104,       /*!< Select PLLM doubling factor as 104 */
    RCC_PLLM_105,       /*!< Select PLLM doubling factor as 105 */
    RCC_PLLM_106,       /*!< Select PLLM doubling factor as 106 */
    RCC_PLLM_107,       /*!< Select PLLM doubling factor as 107 */
    RCC_PLLM_108,       /*!< Select PLLM doubling factor as 108 */
    RCC_PLLM_109,       /*!< Select PLLM doubling factor as 109 */
    RCC_PLLM_110,       /*!< Select PLLM doubling factor as 110 */
    RCC_PLLM_111,       /*!< Select PLLM doubling factor as 111 */
    RCC_PLLM_112,       /*!< Select PLLM doubling factor as 112 */
    RCC_PLLM_113,       /*!< Select PLLM doubling factor as 113 */
    RCC_PLLM_114,       /*!< Select PLLM doubling factor as 114 */
    RCC_PLLM_115,       /*!< Select PLLM doubling factor as 115 */
    RCC_PLLM_116,       /*!< Select PLLM doubling factor as 116 */
    RCC_PLLM_117,       /*!< Select PLLM doubling factor as 117 */
    RCC_PLLM_118,       /*!< Select PLLM doubling factor as 118 */
    RCC_PLLM_119,       /*!< Select PLLM doubling factor as 119 */
    RCC_PLLM_120,       /*!< Select PLLM doubling factor as 120 */
    RCC_PLLM_121,       /*!< Select PLLM doubling factor as 121 */
    RCC_PLLM_122,       /*!< Select PLLM doubling factor as 122 */
    RCC_PLLM_123,       /*!< Select PLLM doubling factor as 123 */
    RCC_PLLM_124,       /*!< Select PLLM doubling factor as 124 */
    RCC_PLLM_125,       /*!< Select PLLM doubling factor as 125 */
    RCC_PLLM_126,       /*!< Select PLLM doubling factor as 126 */
    RCC_PLLM_127,       /*!< Select PLLM doubling factor as 127 */
    RCC_PLLM_128,       /*!< Select PLLM doubling factor as 128 */
    RCC_PLLM_129,       /*!< Select PLLM doubling factor as 129 */
    RCC_PLLM_130,       /*!< Select PLLM doubling factor as 130 */
    RCC_PLLM_131,       /*!< Select PLLM doubling factor as 131 */
    RCC_PLLM_132,       /*!< Select PLLM doubling factor as 132 */
    RCC_PLLM_133,       /*!< Select PLLM doubling factor as 133 */
    RCC_PLLM_134,       /*!< Select PLLM doubling factor as 134 */
    RCC_PLLM_135,       /*!< Select PLLM doubling factor as 135 */
    RCC_PLLM_136,       /*!< Select PLLM doubling factor as 136 */
    RCC_PLLM_137,       /*!< Select PLLM doubling factor as 137 */
    RCC_PLLM_138,       /*!< Select PLLM doubling factor as 138 */
    RCC_PLLM_139,       /*!< Select PLLM doubling factor as 139 */
    RCC_PLLM_140,       /*!< Select PLLM doubling factor as 140 */
    RCC_PLLM_141,       /*!< Select PLLM doubling factor as 141 */
    RCC_PLLM_142,       /*!< Select PLLM doubling factor as 142 */
    RCC_PLLM_143,       /*!< Select PLLM doubling factor as 143 */
    RCC_PLLM_144,       /*!< Select PLLM doubling factor as 144 */
    RCC_PLLM_145,       /*!< Select PLLM doubling factor as 145 */
    RCC_PLLM_146,       /*!< Select PLLM doubling factor as 146 */
    RCC_PLLM_147,       /*!< Select PLLM doubling factor as 147 */
    RCC_PLLM_148,       /*!< Select PLLM doubling factor as 148 */
    RCC_PLLM_149,       /*!< Select PLLM doubling factor as 149 */
    RCC_PLLM_150,       /*!< Select PLLM doubling factor as 150 */
    RCC_PLLM_151,       /*!< Select PLLM doubling factor as 151 */
    RCC_PLLM_152,       /*!< Select PLLM doubling factor as 152 */
    RCC_PLLM_153,       /*!< Select PLLM doubling factor as 153 */
    RCC_PLLM_154,       /*!< Select PLLM doubling factor as 154 */
    RCC_PLLM_155,       /*!< Select PLLM doubling factor as 155 */
    RCC_PLLM_156,       /*!< Select PLLM doubling factor as 156 */
    RCC_PLLM_157,       /*!< Select PLLM doubling factor as 157 */
    RCC_PLLM_158,       /*!< Select PLLM doubling factor as 158 */
    RCC_PLLM_159,       /*!< Select PLLM doubling factor as 159 */
    RCC_PLLM_160,       /*!< Select PLLM doubling factor as 160 */
    RCC_PLLM_161,       /*!< Select PLLM doubling factor as 161 */
    RCC_PLLM_162,       /*!< Select PLLM doubling factor as 162 */
    RCC_PLLM_163,       /*!< Select PLLM doubling factor as 163 */
    RCC_PLLM_164,       /*!< Select PLLM doubling factor as 164 */
    RCC_PLLM_165,       /*!< Select PLLM doubling factor as 165 */
    RCC_PLLM_166,       /*!< Select PLLM doubling factor as 166 */
    RCC_PLLM_167,       /*!< Select PLLM doubling factor as 167 */
    RCC_PLLM_168,       /*!< Select PLLM doubling factor as 168 */
    RCC_PLLM_169,       /*!< Select PLLM doubling factor as 169 */
    RCC_PLLM_170,       /*!< Select PLLM doubling factor as 170 */
    RCC_PLLM_171,       /*!< Select PLLM doubling factor as 171 */
    RCC_PLLM_172,       /*!< Select PLLM doubling factor as 172 */
    RCC_PLLM_173,       /*!< Select PLLM doubling factor as 173 */
    RCC_PLLM_174,       /*!< Select PLLM doubling factor as 174 */
    RCC_PLLM_175,       /*!< Select PLLM doubling factor as 175 */
    RCC_PLLM_176,       /*!< Select PLLM doubling factor as 176 */
    RCC_PLLM_177,       /*!< Select PLLM doubling factor as 177 */
    RCC_PLLM_178,       /*!< Select PLLM doubling factor as 178 */
    RCC_PLLM_179,       /*!< Select PLLM doubling factor as 179 */
    RCC_PLLM_180,       /*!< Select PLLM doubling factor as 180 */
    RCC_PLLM_181,       /*!< Select PLLM doubling factor as 181 */
    RCC_PLLM_182,       /*!< Select PLLM doubling factor as 182 */
    RCC_PLLM_183,       /*!< Select PLLM doubling factor as 183 */
    RCC_PLLM_184,       /*!< Select PLLM doubling factor as 184 */
    RCC_PLLM_185,       /*!< Select PLLM doubling factor as 185 */
    RCC_PLLM_186,       /*!< Select PLLM doubling factor as 186 */
    RCC_PLLM_187,       /*!< Select PLLM doubling factor as 187 */
    RCC_PLLM_188,       /*!< Select PLLM doubling factor as 188 */
    RCC_PLLM_189,       /*!< Select PLLM doubling factor as 189 */
    RCC_PLLM_190,       /*!< Select PLLM doubling factor as 190 */
    RCC_PLLM_191,       /*!< Select PLLM doubling factor as 191 */
    RCC_PLLM_192,       /*!< Select PLLM doubling factor as 192 */
    RCC_PLLM_193,       /*!< Select PLLM doubling factor as 193 */
    RCC_PLLM_194,       /*!< Select PLLM doubling factor as 194 */
    RCC_PLLM_195,       /*!< Select PLLM doubling factor as 195 */
    RCC_PLLM_196,       /*!< Select PLLM doubling factor as 196 */
    RCC_PLLM_197,       /*!< Select PLLM doubling factor as 197 */
    RCC_PLLM_198,       /*!< Select PLLM doubling factor as 198 */
    RCC_PLLM_199,       /*!< Select PLLM doubling factor as 199 */
    RCC_PLLM_200,       /*!< Select PLLM doubling factor as 200 */
    RCC_PLLM_201,       /*!< Select PLLM doubling factor as 201 */
    RCC_PLLM_202,       /*!< Select PLLM doubling factor as 202 */
    RCC_PLLM_203,       /*!< Select PLLM doubling factor as 203 */
    RCC_PLLM_204,       /*!< Select PLLM doubling factor as 204 */
    RCC_PLLM_205,       /*!< Select PLLM doubling factor as 205 */
    RCC_PLLM_206,       /*!< Select PLLM doubling factor as 206 */
    RCC_PLLM_207,       /*!< Select PLLM doubling factor as 207 */
    RCC_PLLM_208,       /*!< Select PLLM doubling factor as 208 */
    RCC_PLLM_209,       /*!< Select PLLM doubling factor as 209 */
    RCC_PLLM_210,       /*!< Select PLLM doubling factor as 210 */
    RCC_PLLM_211,       /*!< Select PLLM doubling factor as 211 */
    RCC_PLLM_212,       /*!< Select PLLM doubling factor as 212 */
    RCC_PLLM_213,       /*!< Select PLLM doubling factor as 213 */
    RCC_PLLM_214,       /*!< Select PLLM doubling factor as 214 */
    RCC_PLLM_215,       /*!< Select PLLM doubling factor as 215 */
    RCC_PLLM_216,       /*!< Select PLLM doubling factor as 216 */
    RCC_PLLM_217,       /*!< Select PLLM doubling factor as 217 */
    RCC_PLLM_218,       /*!< Select PLLM doubling factor as 218 */
    RCC_PLLM_219,       /*!< Select PLLM doubling factor as 219 */
    RCC_PLLM_220,       /*!< Select PLLM doubling factor as 220 */
    RCC_PLLM_221,       /*!< Select PLLM doubling factor as 221 */
    RCC_PLLM_222,       /*!< Select PLLM doubling factor as 222 */
    RCC_PLLM_223,       /*!< Select PLLM doubling factor as 223 */
    RCC_PLLM_224,       /*!< Select PLLM doubling factor as 224 */
    RCC_PLLM_225,       /*!< Select PLLM doubling factor as 225 */
    RCC_PLLM_226,       /*!< Select PLLM doubling factor as 226 */
    RCC_PLLM_227,       /*!< Select PLLM doubling factor as 227 */
    RCC_PLLM_228,       /*!< Select PLLM doubling factor as 228 */
    RCC_PLLM_229,       /*!< Select PLLM doubling factor as 229 */
    RCC_PLLM_230,       /*!< Select PLLM doubling factor as 230 */
    RCC_PLLM_231,       /*!< Select PLLM doubling factor as 231 */
    RCC_PLLM_232,       /*!< Select PLLM doubling factor as 232 */
    RCC_PLLM_233,       /*!< Select PLLM doubling factor as 233 */
    RCC_PLLM_234,       /*!< Select PLLM doubling factor as 234 */
    RCC_PLLM_235,       /*!< Select PLLM doubling factor as 235 */
    RCC_PLLM_236,       /*!< Select PLLM doubling factor as 236 */
    RCC_PLLM_237,       /*!< Select PLLM doubling factor as 237 */
    RCC_PLLM_238,       /*!< Select PLLM doubling factor as 238 */
    RCC_PLLM_239,       /*!< Select PLLM doubling factor as 239 */
    RCC_PLLM_240,       /*!< Select PLLM doubling factor as 240 */
    RCC_PLLM_241,       /*!< Select PLLM doubling factor as 241 */
    RCC_PLLM_242,       /*!< Select PLLM doubling factor as 242 */
    RCC_PLLM_243,       /*!< Select PLLM doubling factor as 243 */
    RCC_PLLM_244,       /*!< Select PLLM doubling factor as 244 */
    RCC_PLLM_245,       /*!< Select PLLM doubling factor as 245 */
    RCC_PLLM_246,       /*!< Select PLLM doubling factor as 246 */
    RCC_PLLM_247,       /*!< Select PLLM doubling factor as 247 */
    RCC_PLLM_248,       /*!< Select PLLM doubling factor as 248 */
    RCC_PLLM_249,       /*!< Select PLLM doubling factor as 249 */
    RCC_PLLM_250,       /*!< Select PLLM doubling factor as 250 */
    RCC_PLLM_251,       /*!< Select PLLM doubling factor as 251 */
    RCC_PLLM_252,       /*!< Select PLLM doubling factor as 252 */
    RCC_PLLM_253,       /*!< Select PLLM doubling factor as 253 */
    RCC_PLLM_254,       /*!< Select PLLM doubling factor as 254 */
    RCC_PLLM_255        /*!< Select PLLM doubling factor as 255 */
} RCC_PllmSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLNSELECTION RCC PLLN Selection
  * @{
  * @brief Macro definitions for selecting the PLLN division factor.
  */
typedef enum {
    RCC_PLLN_DIV1 = 0U,    /*!< Select PLLN division factor as 1 */
    RCC_PLLN_DIV2,         /*!< Select PLLN division factor as 2 */
    RCC_PLLN_DIV3,         /*!< Select PLLN division factor as 3 */
    RCC_PLLN_DIV4,         /*!< Select PLLN division factor as 4 */
    RCC_PLLN_DIV5,         /*!< Select PLLN division factor as 5 */
    RCC_PLLN_DIV6,         /*!< Select PLLN division factor as 6 */
    RCC_PLLN_DIV7,         /*!< Select PLLN division factor as 7 */
    RCC_PLLN_DIV8,         /*!< Select PLLN division factor as 8 */
    RCC_PLLN_DIV9,         /*!< Select PLLN division factor as 9 */
    RCC_PLLN_DIV10,        /*!< Select PLLN division factor as 10 */
    RCC_PLLN_DIV11,        /*!< Select PLLN division factor as 11 */
    RCC_PLLN_DIV12,        /*!< Select PLLN division factor as 12 */
    RCC_PLLN_DIV13,        /*!< Select PLLN division factor as 13 */
    RCC_PLLN_DIV14,        /*!< Select PLLN division factor as 14 */
    RCC_PLLN_DIV15,        /*!< Select PLLN division factor as 15 */
    RCC_PLLN_DIV16         /*!< Select PLLN division factor as 16 */
} RCC_PllnSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLPSELECTION RCC PLLP Selection
  * @{
  * @brief Macro definitions for selecting the PLLP division factor.
  */
typedef enum {
    RCC_PLLP_DIV2 = 0U,    /*!< Select PLLP division factor as 2 */
    RCC_PLLP_DIV4,         /*!< Select PLLP division factor as 4 */
    RCC_PLLP_DIV6,         /*!< Select PLLP division factor as 6 */
    RCC_PLLP_DIV8,         /*!< Select PLLP division factor as 8 */
    RCC_PLLP_DIV10,        /*!< Select PLLP division factor as 10 */
    RCC_PLLP_DIV12,        /*!< Select PLLP division factor as 12 */
    RCC_PLLP_DIV14,        /*!< Select PLLP division factor as 14 */
    RCC_PLLP_DIV16,        /*!< Select PLLP division factor as 16 */
    RCC_PLLP_DIV18,        /*!< Select PLLP division factor as 18 */
    RCC_PLLP_DIV20,        /*!< Select PLLP division factor as 20 */
    RCC_PLLP_DIV22,        /*!< Select PLLP division factor as 22 */
    RCC_PLLP_DIV24,        /*!< Select PLLP division factor as 24 */
    RCC_PLLP_DIV26,        /*!< Select PLLP division factor as 26 */
    RCC_PLLP_DIV28,        /*!< Select PLLP division factor as 28 */
    RCC_PLLP_DIV30,        /*!< Select PLLP division factor as 30 */
    RCC_PLLP_DIV32,        /*!< Select PLLP division factor as 32 */
    RCC_PLLP_DIV34,        /*!< Select PLLP division factor as 34 */
    RCC_PLLP_DIV36,        /*!< Select PLLP division factor as 36 */
    RCC_PLLP_DIV38,        /*!< Select PLLP division factor as 38 */
    RCC_PLLP_DIV40,        /*!< Select PLLP division factor as 40 */
    RCC_PLLP_DIV42,        /*!< Select PLLP division factor as 42 */
    RCC_PLLP_DIV44,        /*!< Select PLLP division factor as 44 */
    RCC_PLLP_DIV46,        /*!< Select PLLP division factor as 46 */
    RCC_PLLP_DIV48,        /*!< Select PLLP division factor as 48 */
    RCC_PLLP_DIV50,        /*!< Select PLLP division factor as 50 */
    RCC_PLLP_DIV52,        /*!< Select PLLP division factor as 52 */
    RCC_PLLP_DIV54,        /*!< Select PLLP division factor as 54 */
    RCC_PLLP_DIV56,        /*!< Select PLLP division factor as 56 */
    RCC_PLLP_DIV58,        /*!< Select PLLP division factor as 58 */
    RCC_PLLP_DIV60,        /*!< Select PLLP division factor as 60 */
    RCC_PLLP_DIV62         /*!< Select PLLP division factor as 62 */
} RCC_PllpSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLQSELECTION RCC PLLQ Selection
  * @{
  * @brief Macro definitions for selecting the PLLQ division factor.
  */
typedef enum {
    RCC_PLLQ_DIV2 = 0U,    /*!< Select PLLQ division factor as 2 */
    RCC_PLLQ_DIV4,         /*!< Select PLLQ division factor as 4 */
    RCC_PLLQ_DIV6,         /*!< Select PLLQ division factor as 6 */
    RCC_PLLQ_DIV8,         /*!< Select PLLQ division factor as 8 */
    RCC_PLLQ_DIV10,        /*!< Select PLLQ division factor as 10 */
    RCC_PLLQ_DIV12,        /*!< Select PLLQ division factor as 12 */
    RCC_PLLQ_DIV14,        /*!< Select PLLQ division factor as 14 */
    RCC_PLLQ_DIV16,        /*!< Select PLLQ division factor as 16 */
    RCC_PLLQ_DIV18,        /*!< Select PLLQ division factor as 18 */
    RCC_PLLQ_DIV20,        /*!< Select PLLQ division factor as 20 */
    RCC_PLLQ_DIV22,        /*!< Select PLLQ division factor as 22 */
    RCC_PLLQ_DIV24,        /*!< Select PLLQ division factor as 24 */
    RCC_PLLQ_DIV26,        /*!< Select PLLQ division factor as 26 */
    RCC_PLLQ_DIV28,        /*!< Select PLLQ division factor as 28 */
    RCC_PLLQ_DIV30,        /*!< Select PLLQ division factor as 30 */
    RCC_PLLQ_DIV32,        /*!< Select PLLQ division factor as 32 */
    RCC_PLLQ_DIV34,        /*!< Select PLLQ division factor as 34 */
    RCC_PLLQ_DIV36,        /*!< Select PLLQ division factor as 36 */
    RCC_PLLQ_DIV38,        /*!< Select PLLQ division factor as 38 */
    RCC_PLLQ_DIV40,        /*!< Select PLLQ division factor as 40 */
    RCC_PLLQ_DIV42,        /*!< Select PLLQ division factor as 42 */
    RCC_PLLQ_DIV44,        /*!< Select PLLQ division factor as 44 */
    RCC_PLLQ_DIV46,        /*!< Select PLLQ division factor as 46 */
    RCC_PLLQ_DIV48,        /*!< Select PLLQ division factor as 48 */
    RCC_PLLQ_DIV50,        /*!< Select PLLQ division factor as 50 */
    RCC_PLLQ_DIV52,        /*!< Select PLLQ division factor as 52 */
    RCC_PLLQ_DIV54,        /*!< Select PLLQ division factor as 54 */
    RCC_PLLQ_DIV56,        /*!< Select PLLQ division factor as 56 */
    RCC_PLLQ_DIV58,        /*!< Select PLLQ division factor as 58 */
    RCC_PLLQ_DIV60,        /*!< Select PLLQ division factor as 60 */
    RCC_PLLQ_DIV62         /*!< Select PLLQ division factor as 62 */
} RCC_PllqSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLRSELECTION RCC PLLR Selection
  * @{
  * @brief Macro definitions for selecting the PLLR division factor.
  */
typedef enum {
    RCC_PLLR_DIV2 = 0U,    /*!< Select PLLR division factor as 2 */
    RCC_PLLR_DIV4,         /*!< Select PLLR division factor as 4 */
    RCC_PLLR_DIV6,         /*!< Select PLLR division factor as 6 */
    RCC_PLLR_DIV8,         /*!< Select PLLR division factor as 8 */
    RCC_PLLR_DIV10,        /*!< Select PLLR division factor as 10 */
    RCC_PLLR_DIV12,        /*!< Select PLLR division factor as 12 */
    RCC_PLLR_DIV14,        /*!< Select PLLR division factor as 14 */
    RCC_PLLR_DIV16,        /*!< Select PLLR division factor as 16 */
    RCC_PLLR_DIV18,        /*!< Select PLLR division factor as 18 */
    RCC_PLLR_DIV20,        /*!< Select PLLR division factor as 20 */
    RCC_PLLR_DIV22,        /*!< Select PLLR division factor as 22 */
    RCC_PLLR_DIV24,        /*!< Select PLLR division factor as 24 */
    RCC_PLLR_DIV26,        /*!< Select PLLR division factor as 26 */
    RCC_PLLR_DIV28,        /*!< Select PLLR division factor as 28 */
    RCC_PLLR_DIV30,        /*!< Select PLLR division factor as 30 */
    RCC_PLLR_DIV32,        /*!< Select PLLR division factor as 32 */
    RCC_PLLR_DIV34,        /*!< Select PLLR division factor as 34 */
    RCC_PLLR_DIV36,        /*!< Select PLLR division factor as 36 */
    RCC_PLLR_DIV38,        /*!< Select PLLR division factor as 38 */
    RCC_PLLR_DIV40,        /*!< Select PLLR division factor as 40 */
    RCC_PLLR_DIV42,        /*!< Select PLLR division factor as 42 */
    RCC_PLLR_DIV44,        /*!< Select PLLR division factor as 44 */
    RCC_PLLR_DIV46,        /*!< Select PLLR division factor as 46 */
    RCC_PLLR_DIV48,        /*!< Select PLLR division factor as 48 */
    RCC_PLLR_DIV50,        /*!< Select PLLR division factor as 50 */
    RCC_PLLR_DIV52,        /*!< Select PLLR division factor as 52 */
    RCC_PLLR_DIV54,        /*!< Select PLLR division factor as 54 */
    RCC_PLLR_DIV56,        /*!< Select PLLR division factor as 56 */
    RCC_PLLR_DIV58,        /*!< Select PLLR division factor as 58 */
    RCC_PLLR_DIV60,        /*!< Select PLLR division factor as 60 */
    RCC_PLLR_DIV62         /*!< Select PLLR division factor as 62 */
} RCC_PllrSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLFORCELKDT RCC PLL LKDT Selection
  * @{
  * @brief Configuration for Force PLL Lock Detection.
  */
typedef enum {
    RCC_PLL_FORCELK_DISABLE = 0U,    /*!< Disable Force Lock Detection */
    RCC_PLL_FORCELK_ENABLE           /*!< Enable Force Lock Detection */
} RCC_PllForceLkdt;

/**
  * @}
  */

/** @defgroup RCC_PLLLKDTSELECTION RCC PLL LKDT Selection
  * @{
  * @brief PLL Lock and Unlock Deviation Value Configuration Bits.
  */
typedef enum {
    RCC_PLL_LKDT_SEL_0 = 0U,    /*!< Lock Count Deviation Value 2%, Unlock Count Deviation Value 4% */
    RCC_PLL_LKDT_SEL_1,         /*!< Lock Count Deviation Value 4%, Unlock Count Deviation Value 8% */
    RCC_PLL_LKDT_SEL_2,         /*!< Lock Count Deviation Value 6%, Unlock Count Deviation Value 12% */
    RCC_PLL_LKDT_SEL_3          /*!< Lock Count Deviation Value 10%, Unlock Count Deviation Value 20% */
} RCC_PllLkdtSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLAWKDIVSELECTION RCC HXTL AWK Div Selection
  * @{
  * @brief Configuration bits for AWK HXTL clock prescaler.
  */
typedef enum {
    RCC_HXTL_AWK_DIV_1 = 0U,    /*!< HXTL clock divided by 1 (no division) */
    RCC_HXTL_AWK_DIV_2,         /*!< HXTL clock divided by 2 */
    RCC_HXTL_AWK_DIV_3,         /*!< HXTL clock divided by 3 */
    RCC_HXTL_AWK_DIV_4,         /*!< HXTL clock divided by 4 */
    RCC_HXTL_AWK_DIV_5,         /*!< HXTL clock divided by 5 */
    RCC_HXTL_AWK_DIV_6,         /*!< HXTL clock divided by 6 */
    RCC_HXTL_AWK_DIV_7,         /*!< HXTL clock divided by 7 */
    RCC_HXTL_AWK_DIV_8,         /*!< HXTL clock divided by 8 */
    RCC_HXTL_AWK_DIV_9,         /*!< HXTL clock divided by 9 */
    RCC_HXTL_AWK_DIV_10,        /*!< HXTL clock divided by 10 */
    RCC_HXTL_AWK_DIV_11,        /*!< HXTL clock divided by 11 */
    RCC_HXTL_AWK_DIV_12,        /*!< HXTL clock divided by 12 */
    RCC_HXTL_AWK_DIV_13,        /*!< HXTL clock divided by 13 */
    RCC_HXTL_AWK_DIV_14,        /*!< HXTL clock divided by 14 */
    RCC_HXTL_AWK_DIV_15,        /*!< HXTL clock divided by 15 */
    RCC_HXTL_AWK_DIV_16,        /*!< HXTL clock divided by 16 */
    RCC_HXTL_AWK_DIV_17,        /*!< HXTL clock divided by 17 */
    RCC_HXTL_AWK_DIV_18,        /*!< HXTL clock divided by 18 */
    RCC_HXTL_AWK_DIV_19,        /*!< HXTL clock divided by 19 */
    RCC_HXTL_AWK_DIV_20,        /*!< HXTL clock divided by 20 */
    RCC_HXTL_AWK_DIV_21,        /*!< HXTL clock divided by 21 */
    RCC_HXTL_AWK_DIV_22,        /*!< HXTL clock divided by 22 */
    RCC_HXTL_AWK_DIV_23,        /*!< HXTL clock divided by 23 */
    RCC_HXTL_AWK_DIV_24,        /*!< HXTL clock divided by 24 */
    RCC_HXTL_AWK_DIV_25,        /*!< HXTL clock divided by 25 */
    RCC_HXTL_AWK_DIV_26,        /*!< HXTL clock divided by 26 */
    RCC_HXTL_AWK_DIV_27,        /*!< HXTL clock divided by 27 */
    RCC_HXTL_AWK_DIV_28,        /*!< HXTL clock divided by 28 */
    RCC_HXTL_AWK_DIV_29,        /*!< HXTL clock divided by 29 */
    RCC_HXTL_AWK_DIV_30,        /*!< HXTL clock divided by 30 */
    RCC_HXTL_AWK_DIV_31,        /*!< HXTL clock divided by 31 */
    RCC_HXTL_AWK_DIV_32,        /*!< HXTL clock divided by 32 */
    RCC_HXTL_AWK_DIV_33,        /*!< HXTL clock divided by 33 */
    RCC_HXTL_AWK_DIV_34,        /*!< HXTL clock divided by 34 */
    RCC_HXTL_AWK_DIV_35,        /*!< HXTL clock divided by 35 */
    RCC_HXTL_AWK_DIV_36,        /*!< HXTL clock divided by 36 */
    RCC_HXTL_AWK_DIV_37,        /*!< HXTL clock divided by 37 */
    RCC_HXTL_AWK_DIV_38,        /*!< HXTL clock divided by 38 */
    RCC_HXTL_AWK_DIV_39,        /*!< HXTL clock divided by 39 */
    RCC_HXTL_AWK_DIV_40,        /*!< HXTL clock divided by 40 */
    RCC_HXTL_AWK_DIV_41,        /*!< HXTL clock divided by 41 */
    RCC_HXTL_AWK_DIV_42,        /*!< HXTL clock divided by 42 */
    RCC_HXTL_AWK_DIV_43,        /*!< HXTL clock divided by 43 */
    RCC_HXTL_AWK_DIV_44,        /*!< HXTL clock divided by 44 */
    RCC_HXTL_AWK_DIV_45,        /*!< HXTL clock divided by 45 */
    RCC_HXTL_AWK_DIV_46,        /*!< HXTL clock divided by 46 */
    RCC_HXTL_AWK_DIV_47,        /*!< HXTL clock divided by 47 */
    RCC_HXTL_AWK_DIV_48,        /*!< HXTL clock divided by 48 */
    RCC_HXTL_AWK_DIV_49,        /*!< HXTL clock divided by 49 */
    RCC_HXTL_AWK_DIV_50,        /*!< HXTL clock divided by 50 */
    RCC_HXTL_AWK_DIV_51,        /*!< HXTL clock divided by 51 */
    RCC_HXTL_AWK_DIV_52,        /*!< HXTL clock divided by 52 */
    RCC_HXTL_AWK_DIV_53,        /*!< HXTL clock divided by 53 */
    RCC_HXTL_AWK_DIV_54,        /*!< HXTL clock divided by 54 */
    RCC_HXTL_AWK_DIV_55,        /*!< HXTL clock divided by 55 */
    RCC_HXTL_AWK_DIV_56,        /*!< HXTL clock divided by 56 */
    RCC_HXTL_AWK_DIV_57,        /*!< HXTL clock divided by 57 */
    RCC_HXTL_AWK_DIV_58,        /*!< HXTL clock divided by 58 */
    RCC_HXTL_AWK_DIV_59,        /*!< HXTL clock divided by 59 */
    RCC_HXTL_AWK_DIV_60,        /*!< HXTL clock divided by 60 */
    RCC_HXTL_AWK_DIV_61,        /*!< HXTL clock divided by 61 */
    RCC_HXTL_AWK_DIV_62,        /*!< HXTL clock divided by 62 */
    RCC_HXTL_AWK_DIV_63,        /*!< HXTL clock divided by 63 */
    RCC_HXTL_AWK_DIV_64,        /*!< HXTL clock divided by 64 */
    RCC_HXTL_AWK_DIV_65,        /*!< HXTL clock divided by 65 */
    RCC_HXTL_AWK_DIV_66,        /*!< HXTL clock divided by 66 */
    RCC_HXTL_AWK_DIV_67,        /*!< HXTL clock divided by 67 */
    RCC_HXTL_AWK_DIV_68,        /*!< HXTL clock divided by 68 */
    RCC_HXTL_AWK_DIV_69,        /*!< HXTL clock divided by 69 */
    RCC_HXTL_AWK_DIV_70,        /*!< HXTL clock divided by 70 */
    RCC_HXTL_AWK_DIV_71,        /*!< HXTL clock divided by 71 */
    RCC_HXTL_AWK_DIV_72,        /*!< HXTL clock divided by 72 */
    RCC_HXTL_AWK_DIV_73,        /*!< HXTL clock divided by 73 */
    RCC_HXTL_AWK_DIV_74,        /*!< HXTL clock divided by 74 */
    RCC_HXTL_AWK_DIV_75,        /*!< HXTL clock divided by 75 */
    RCC_HXTL_AWK_DIV_76,        /*!< HXTL clock divided by 76 */
    RCC_HXTL_AWK_DIV_77,        /*!< HXTL clock divided by 77 */
    RCC_HXTL_AWK_DIV_78,        /*!< HXTL clock divided by 78 */
    RCC_HXTL_AWK_DIV_79,        /*!< HXTL clock divided by 79 */
    RCC_HXTL_AWK_DIV_80,        /*!< HXTL clock divided by 80 */
    RCC_HXTL_AWK_DIV_81,        /*!< HXTL clock divided by 81 */
    RCC_HXTL_AWK_DIV_82,        /*!< HXTL clock divided by 82 */
    RCC_HXTL_AWK_DIV_83,        /*!< HXTL clock divided by 83 */
    RCC_HXTL_AWK_DIV_84,        /*!< HXTL clock divided by 84 */
    RCC_HXTL_AWK_DIV_85,        /*!< HXTL clock divided by 85 */
    RCC_HXTL_AWK_DIV_86,        /*!< HXTL clock divided by 86 */
    RCC_HXTL_AWK_DIV_87,        /*!< HXTL clock divided by 87 */
    RCC_HXTL_AWK_DIV_88,        /*!< HXTL clock divided by 88 */
    RCC_HXTL_AWK_DIV_89,        /*!< HXTL clock divided by 89 */
    RCC_HXTL_AWK_DIV_90,        /*!< HXTL clock divided by 90 */
    RCC_HXTL_AWK_DIV_91,        /*!< HXTL clock divided by 91 */
    RCC_HXTL_AWK_DIV_92,        /*!< HXTL clock divided by 92 */
    RCC_HXTL_AWK_DIV_93,        /*!< HXTL clock divided by 93 */
    RCC_HXTL_AWK_DIV_94,        /*!< HXTL clock divided by 94 */
    RCC_HXTL_AWK_DIV_95,        /*!< HXTL clock divided by 95 */
    RCC_HXTL_AWK_DIV_96,        /*!< HXTL clock divided by 96 */
    RCC_HXTL_AWK_DIV_97,        /*!< HXTL clock divided by 97 */
    RCC_HXTL_AWK_DIV_98,        /*!< HXTL clock divided by 98 */
    RCC_HXTL_AWK_DIV_99,        /*!< HXTL clock divided by 99 */
    RCC_HXTL_AWK_DIV_100,       /*!< HXTL clock divided by 100 */
    RCC_HXTL_AWK_DIV_101,       /*!< HXTL clock divided by 101 */
    RCC_HXTL_AWK_DIV_102,       /*!< HXTL clock divided by 102 */
    RCC_HXTL_AWK_DIV_103,       /*!< HXTL clock divided by 103 */
    RCC_HXTL_AWK_DIV_104,       /*!< HXTL clock divided by 104 */
    RCC_HXTL_AWK_DIV_105,       /*!< HXTL clock divided by 105 */
    RCC_HXTL_AWK_DIV_106,       /*!< HXTL clock divided by 106 */
    RCC_HXTL_AWK_DIV_107,       /*!< HXTL clock divided by 107 */
    RCC_HXTL_AWK_DIV_108,       /*!< HXTL clock divided by 108 */
    RCC_HXTL_AWK_DIV_109,       /*!< HXTL clock divided by 109 */
    RCC_HXTL_AWK_DIV_110,       /*!< HXTL clock divided by 110 */
    RCC_HXTL_AWK_DIV_111,       /*!< HXTL clock divided by 111 */
    RCC_HXTL_AWK_DIV_112,       /*!< HXTL clock divided by 112 */
    RCC_HXTL_AWK_DIV_113,       /*!< HXTL clock divided by 113 */
    RCC_HXTL_AWK_DIV_114,       /*!< HXTL clock divided by 114 */
    RCC_HXTL_AWK_DIV_115,       /*!< HXTL clock divided by 115 */
    RCC_HXTL_AWK_DIV_116,       /*!< HXTL clock divided by 116 */
    RCC_HXTL_AWK_DIV_117,       /*!< HXTL clock divided by 117 */
    RCC_HXTL_AWK_DIV_118,       /*!< HXTL clock divided by 118 */
    RCC_HXTL_AWK_DIV_119,       /*!< HXTL clock divided by 119 */
    RCC_HXTL_AWK_DIV_120,       /*!< HXTL clock divided by 120 */
    RCC_HXTL_AWK_DIV_121,       /*!< HXTL clock divided by 121 */
    RCC_HXTL_AWK_DIV_122,       /*!< HXTL clock divided by 122 */
    RCC_HXTL_AWK_DIV_123,       /*!< HXTL clock divided by 123 */
    RCC_HXTL_AWK_DIV_124,       /*!< HXTL clock divided by 124 */
    RCC_HXTL_AWK_DIV_125,       /*!< HXTL clock divided by 125 */
    RCC_HXTL_AWK_DIV_126,       /*!< HXTL clock divided by 126 */
    RCC_HXTL_AWK_DIV_127,       /*!< HXTL clock divided by 127 */
    RCC_HXTL_AWK_DIV_128,       /*!< HXTL clock divided by 128 */
    RCC_HXTL_AWK_DIV_129,       /*!< HXTL clock divided by 129 */
    RCC_HXTL_AWK_DIV_130,       /*!< HXTL clock divided by 130 */
    RCC_HXTL_AWK_DIV_131,       /*!< HXTL clock divided by 131 */
    RCC_HXTL_AWK_DIV_132,       /*!< HXTL clock divided by 132 */
    RCC_HXTL_AWK_DIV_133,       /*!< HXTL clock divided by 133 */
    RCC_HXTL_AWK_DIV_134,       /*!< HXTL clock divided by 134 */
    RCC_HXTL_AWK_DIV_135,       /*!< HXTL clock divided by 135 */
    RCC_HXTL_AWK_DIV_136,       /*!< HXTL clock divided by 136 */
    RCC_HXTL_AWK_DIV_137,       /*!< HXTL clock divided by 137 */
    RCC_HXTL_AWK_DIV_138,       /*!< HXTL clock divided by 138 */
    RCC_HXTL_AWK_DIV_139,       /*!< HXTL clock divided by 139 */
    RCC_HXTL_AWK_DIV_140,       /*!< HXTL clock divided by 140 */
    RCC_HXTL_AWK_DIV_141,       /*!< HXTL clock divided by 141 */
    RCC_HXTL_AWK_DIV_142,       /*!< HXTL clock divided by 142 */
    RCC_HXTL_AWK_DIV_143,       /*!< HXTL clock divided by 143 */
    RCC_HXTL_AWK_DIV_144,       /*!< HXTL clock divided by 144 */
    RCC_HXTL_AWK_DIV_145,       /*!< HXTL clock divided by 145 */
    RCC_HXTL_AWK_DIV_146,       /*!< HXTL clock divided by 146 */
    RCC_HXTL_AWK_DIV_147,       /*!< HXTL clock divided by 147 */
    RCC_HXTL_AWK_DIV_148,       /*!< HXTL clock divided by 148 */
    RCC_HXTL_AWK_DIV_149,       /*!< HXTL clock divided by 149 */
    RCC_HXTL_AWK_DIV_150,       /*!< HXTL clock divided by 150 */
    RCC_HXTL_AWK_DIV_151,       /*!< HXTL clock divided by 151 */
    RCC_HXTL_AWK_DIV_152,       /*!< HXTL clock divided by 152 */
    RCC_HXTL_AWK_DIV_153,       /*!< HXTL clock divided by 153 */
    RCC_HXTL_AWK_DIV_154,       /*!< HXTL clock divided by 154 */
    RCC_HXTL_AWK_DIV_155,       /*!< HXTL clock divided by 155 */
    RCC_HXTL_AWK_DIV_156,       /*!< HXTL clock divided by 156 */
    RCC_HXTL_AWK_DIV_157,       /*!< HXTL clock divided by 157 */
    RCC_HXTL_AWK_DIV_158,       /*!< HXTL clock divided by 158 */
    RCC_HXTL_AWK_DIV_159,       /*!< HXTL clock divided by 159 */
    RCC_HXTL_AWK_DIV_160,       /*!< HXTL clock divided by 160 */
    RCC_HXTL_AWK_DIV_161,       /*!< HXTL clock divided by 161 */
    RCC_HXTL_AWK_DIV_162,       /*!< HXTL clock divided by 162 */
    RCC_HXTL_AWK_DIV_163,       /*!< HXTL clock divided by 163 */
    RCC_HXTL_AWK_DIV_164,       /*!< HXTL clock divided by 164 */
    RCC_HXTL_AWK_DIV_165,       /*!< HXTL clock divided by 165 */
    RCC_HXTL_AWK_DIV_166,       /*!< HXTL clock divided by 166 */
    RCC_HXTL_AWK_DIV_167,       /*!< HXTL clock divided by 167 */
    RCC_HXTL_AWK_DIV_168,       /*!< HXTL clock divided by 168 */
    RCC_HXTL_AWK_DIV_169,       /*!< HXTL clock divided by 169 */
    RCC_HXTL_AWK_DIV_170,       /*!< HXTL clock divided by 170 */
    RCC_HXTL_AWK_DIV_171,       /*!< HXTL clock divided by 171 */
    RCC_HXTL_AWK_DIV_172,       /*!< HXTL clock divided by 172 */
    RCC_HXTL_AWK_DIV_173,       /*!< HXTL clock divided by 173 */
    RCC_HXTL_AWK_DIV_174,       /*!< HXTL clock divided by 174 */
    RCC_HXTL_AWK_DIV_175,       /*!< HXTL clock divided by 175 */
    RCC_HXTL_AWK_DIV_176,       /*!< HXTL clock divided by 176 */
    RCC_HXTL_AWK_DIV_177,       /*!< HXTL clock divided by 177 */
    RCC_HXTL_AWK_DIV_178,       /*!< HXTL clock divided by 178 */
    RCC_HXTL_AWK_DIV_179,       /*!< HXTL clock divided by 179 */
    RCC_HXTL_AWK_DIV_180,       /*!< HXTL clock divided by 180 */
    RCC_HXTL_AWK_DIV_181,       /*!< HXTL clock divided by 181 */
    RCC_HXTL_AWK_DIV_182,       /*!< HXTL clock divided by 182 */
    RCC_HXTL_AWK_DIV_183,       /*!< HXTL clock divided by 183 */
    RCC_HXTL_AWK_DIV_184,       /*!< HXTL clock divided by 184 */
    RCC_HXTL_AWK_DIV_185,       /*!< HXTL clock divided by 185 */
    RCC_HXTL_AWK_DIV_186,       /*!< HXTL clock divided by 186 */
    RCC_HXTL_AWK_DIV_187,       /*!< HXTL clock divided by 187 */
    RCC_HXTL_AWK_DIV_188,       /*!< HXTL clock divided by 188 */
    RCC_HXTL_AWK_DIV_189,       /*!< HXTL clock divided by 189 */
    RCC_HXTL_AWK_DIV_190,       /*!< HXTL clock divided by 190 */
    RCC_HXTL_AWK_DIV_191,       /*!< HXTL clock divided by 191 */
    RCC_HXTL_AWK_DIV_192,       /*!< HXTL clock divided by 192 */
    RCC_HXTL_AWK_DIV_193,       /*!< HXTL clock divided by 193 */
    RCC_HXTL_AWK_DIV_194,       /*!< HXTL clock divided by 194 */
    RCC_HXTL_AWK_DIV_195,       /*!< HXTL clock divided by 195 */
    RCC_HXTL_AWK_DIV_196,       /*!< HXTL clock divided by 196 */
    RCC_HXTL_AWK_DIV_197,       /*!< HXTL clock divided by 197 */
    RCC_HXTL_AWK_DIV_198,       /*!< HXTL clock divided by 198 */
    RCC_HXTL_AWK_DIV_199,       /*!< HXTL clock divided by 199 */
    RCC_HXTL_AWK_DIV_200,       /*!< HXTL clock divided by 200 */
    RCC_HXTL_AWK_DIV_201,       /*!< HXTL clock divided by 201 */
    RCC_HXTL_AWK_DIV_202,       /*!< HXTL clock divided by 202 */
    RCC_HXTL_AWK_DIV_203,       /*!< HXTL clock divided by 203 */
    RCC_HXTL_AWK_DIV_204,       /*!< HXTL clock divided by 204 */
    RCC_HXTL_AWK_DIV_205,       /*!< HXTL clock divided by 205 */
    RCC_HXTL_AWK_DIV_206,       /*!< HXTL clock divided by 206 */
    RCC_HXTL_AWK_DIV_207,       /*!< HXTL clock divided by 207 */
    RCC_HXTL_AWK_DIV_208,       /*!< HXTL clock divided by 208 */
    RCC_HXTL_AWK_DIV_209,       /*!< HXTL clock divided by 209 */
    RCC_HXTL_AWK_DIV_210,       /*!< HXTL clock divided by 210 */
    RCC_HXTL_AWK_DIV_211,       /*!< HXTL clock divided by 211 */
    RCC_HXTL_AWK_DIV_212,       /*!< HXTL clock divided by 212 */
    RCC_HXTL_AWK_DIV_213,       /*!< HXTL clock divided by 213 */
    RCC_HXTL_AWK_DIV_214,       /*!< HXTL clock divided by 214 */
    RCC_HXTL_AWK_DIV_215,       /*!< HXTL clock divided by 215 */
    RCC_HXTL_AWK_DIV_216,       /*!< HXTL clock divided by 216 */
    RCC_HXTL_AWK_DIV_217,       /*!< HXTL clock divided by 217 */
    RCC_HXTL_AWK_DIV_218,       /*!< HXTL clock divided by 218 */
    RCC_HXTL_AWK_DIV_219,       /*!< HXTL clock divided by 219 */
    RCC_HXTL_AWK_DIV_220,       /*!< HXTL clock divided by 220 */
    RCC_HXTL_AWK_DIV_221,       /*!< HXTL clock divided by 221 */
    RCC_HXTL_AWK_DIV_222,       /*!< HXTL clock divided by 222 */
    RCC_HXTL_AWK_DIV_223,       /*!< HXTL clock divided by 223 */
    RCC_HXTL_AWK_DIV_224,       /*!< HXTL clock divided by 224 */
    RCC_HXTL_AWK_DIV_225,       /*!< HXTL clock divided by 225 */
    RCC_HXTL_AWK_DIV_226,       /*!< HXTL clock divided by 226 */
    RCC_HXTL_AWK_DIV_227,       /*!< HXTL clock divided by 227 */
    RCC_HXTL_AWK_DIV_228,       /*!< HXTL clock divided by 228 */
    RCC_HXTL_AWK_DIV_229,       /*!< HXTL clock divided by 229 */
    RCC_HXTL_AWK_DIV_230,       /*!< HXTL clock divided by 230 */
    RCC_HXTL_AWK_DIV_231,       /*!< HXTL clock divided by 231 */
    RCC_HXTL_AWK_DIV_232,       /*!< HXTL clock divided by 232 */
    RCC_HXTL_AWK_DIV_233,       /*!< HXTL clock divided by 233 */
    RCC_HXTL_AWK_DIV_234,       /*!< HXTL clock divided by 234 */
    RCC_HXTL_AWK_DIV_235,       /*!< HXTL clock divided by 235 */
    RCC_HXTL_AWK_DIV_236,       /*!< HXTL clock divided by 236 */
    RCC_HXTL_AWK_DIV_237,       /*!< HXTL clock divided by 237 */
    RCC_HXTL_AWK_DIV_238,       /*!< HXTL clock divided by 238 */
    RCC_HXTL_AWK_DIV_239,       /*!< HXTL clock divided by 239 */
    RCC_HXTL_AWK_DIV_240,       /*!< HXTL clock divided by 240 */
    RCC_HXTL_AWK_DIV_241,       /*!< HXTL clock divided by 241 */
    RCC_HXTL_AWK_DIV_242,       /*!< HXTL clock divided by 242 */
    RCC_HXTL_AWK_DIV_243,       /*!< HXTL clock divided by 243 */
    RCC_HXTL_AWK_DIV_244,       /*!< HXTL clock divided by 244 */
    RCC_HXTL_AWK_DIV_245,       /*!< HXTL clock divided by 245 */
    RCC_HXTL_AWK_DIV_246,       /*!< HXTL clock divided by 246 */
    RCC_HXTL_AWK_DIV_247,       /*!< HXTL clock divided by 247 */
    RCC_HXTL_AWK_DIV_248,       /*!< HXTL clock divided by 248 */
    RCC_HXTL_AWK_DIV_249,       /*!< HXTL clock divided by 249 */
    RCC_HXTL_AWK_DIV_250,       /*!< HXTL clock divided by 250 */
    RCC_HXTL_AWK_DIV_251,       /*!< HXTL clock divided by 251 */
    RCC_HXTL_AWK_DIV_252,       /*!< HXTL clock divided by 252 */
    RCC_HXTL_AWK_DIV_253,       /*!< HXTL clock divided by 253 */
    RCC_HXTL_AWK_DIV_254,       /*!< HXTL clock divided by 254 */
    RCC_HXTL_AWK_DIV_255,       /*!< HXTL clock divided by 255 */
    RCC_HXTL_AWK_DIV_256        /*!< HXTL clock divided by 256 */
} RCC_HxtlAwkDivSelection;

/**
  * @}
  */

/** @defgroup RCC_TRACECLOCKDIVSELECTION RCC TRACE Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the TRACE clock divider relative to HCLK.
  */
typedef enum {
    RCC_TRACE_DIV_1 = 0U,    /*!< TRACE clock divided by HCLK 1 */
    RCC_TRACE_DIV_2,         /*!< TRACE clock divided by HCLK 2 */
    RCC_TRACE_DIV_4,         /*!< TRACE clock divided by HCLK 4 */
    RCC_TRACE_DIV_8,         /*!< TRACE clock divided by HCLK 8 */
    RCC_TRACE_DIV_16         /*!< TRACE clock divided by HCLK 16 */
} RCC_TraceClockDivSelection;

/**
  * @}
  */

/** @defgroup RCC_EMIFCLOCKDIVSELECTION RCC EMIF Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the EMIF clock divider relative to HCLK.
  */
typedef enum {
    RCC_EMIF_DIV_1 = 0U,    /*!< EMIF clock divided by HCLK 1 */
    RCC_EMIF_DIV_2,         /*!< EMIF clock divided by HCLK 2 */
    RCC_EMIF_DIV_4,         /*!< EMIF clock divided by HCLK 4 */
    RCC_EMIF_DIV_8,         /*!< EMIF clock divided by HCLK 8 */
    RCC_EMIF_DIV_16         /*!< EMIF clock divided by HCLK 16 */
} RCC_EmifClockDivSelection;

/**
  * @}
  */

/** @defgroup EPWMCLKDIV RCC FLASH Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the EPWMCLK clock divider relative to HCLK.
  */
typedef enum {
    RCC_EPWM_DIV_1 = 0U,    /*!< FLASH clock divided by HCLK 1 */
    RCC_EPWM_DIV_2          /*!< FLASH clock divided by HCLK 2 */
} RCC_EPWMClockDivSelection;

/**
  * @}
  */

/** @defgroup RCC_FLASHCLOCKDIVSELECTION RCC FLASH Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the FLASH clock divider relative to HCLK.
  */
typedef enum {
    RCC_FLASH_DIV_1 = 0U,    /*!< FLASH clock divided by HCLK 1 */
    RCC_FLASH_DIV_2,         /*!< FLASH clock divided by HCLK 2 */
    RCC_FLASH_DIV_4,         /*!< FLASH clock divided by HCLK 4 */
    RCC_FLASH_DIV_8,         /*!< FLASH clock divided by HCLK 8 */
    RCC_FLASH_DIV_16         /*!< FLASH clock divided by HCLK 16 */
} RCC_FlashClockDivSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLLOOPFILTERCAPSELECTION RCC PLL loopFilterCap Selection
  * @{
  * @brief  Defines the possible values for configuring the PLL loopFilterCap.
  */
typedef enum {
    RCC_PLL_LOOP_FILTER_CAP_40PF = 4U,    /*!< PLL Loop Filter Cap: C2 = 40pF */
    RCC_PLL_LOOP_FILTER_CAP_64PF = 6U,    /*!< PLL Loop Filter Cap: C2 = 64.5pF */
    RCC_PLL_LOOP_FILTER_CAP_84PF = 7U     /*!< PLL Loop Filter Cap: C2 = 84pF */
} RCC_PllLoopFilterCapSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLCHARGEPUMPCURRENTSELECTION RCC PLL Charge Pump Current Selection
  * @{
  * @brief  Defines the possible values for configuring the PLL Charge Pump Current.
  */
typedef enum {
    RCC_PLL_CHARGE_PUMP_CURRENT_2UA = 0U,    /*!< PLL Charge Pump Current: 2 µA */
    RCC_PLL_CHARGE_PUMP_CURRENT_1UA,         /*!< PLL Charge Pump Current: 1 µA */
    RCC_PLL_CHARGE_PUMP_CURRENT_4UA          /*!< PLL Charge Pump Current: 4 µA */
} RCC_PllChargePumpCurrentSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLLOOPFILTERRESSELECTION RCC PLL loopFilterRes Selection
  * @{
  * @brief  Defines the possible values for configuring the PLL loopFilterRes.
  */
typedef enum {
    RCC_PLL_LOOP_FILTER_RES_45K = 0U,    /*!< PLL Loop Filter Resistor: 45 kΩ */
    RCC_PLL_LOOP_FILTER_RES_20K = 2U,    /*!< PLL Loop Filter Resistor: 20 kΩ */
    RCC_PLL_LOOP_FILTER_RES_10K = 3U     /*!< PLL Loop Filter Resistor: 10 kΩ */
} RCC_PllLoopFilterResSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLVCOFREQUENCYSELECTION RCC PLL VCO Frequency Selection
  * @{
  * @brief  Defines the possible values for configuring the PLL vco frequency.
  */
typedef enum {
    RCC_PLL_VCO_200_400M = 0U,    /*!< PLL VCO Frequency Range: 200 MHz to 400 MHz */
    RCC_PLL_VCO_200_600M,         /*!< PLL VCO Frequency Range: 200 MHz to 600 MHz */
    RCC_PLL_VCO_300_750M,         /*!< PLL VCO Frequency Range: 300 MHz to 750 MHz */
    RCC_PLL_VCO_400_800M         /*!< PLL VCO Frequency Range: 400 MHz to 1000 MHz */
} RCC_PllVcoFrequencySelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLFILTENABLESELECTION RCC HXTL Filter Enable Selection
  * @{
  * @brief  Defines the possible values for enabling or disabling the HXTL filter.
  */
typedef enum {
    RCC_HXTL_FILT_DISABLE = 0U,    /*!< HXTL Filter: Disabled */
    RCC_HXTL_FILT_ENABLE          /*!< HXTL Filter: Enabled */
} RCC_HxtlFiltEnableSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLFEEDBACKENABLESELECTION RCC HXTL Feedback Resistor Enable Selection
  * @{
  * @brief  Defines the possible values for enabling or disabling the HXTL feedback resistor.
  */
typedef enum {
    RCC_HXTL_FEEDBACK_DISABLE = 0U,    /*!< HXTL Feedback Resistor: Disabled */
    RCC_HXTL_FEEDBACK_ENABLE           /*!< HXTL Feedback Resistor: Enabled */
} RCC_HxtlFeedbackEnableSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLFEEDBACKSELECTION RCC HXTL Feedback Resistor Selection
  * @{
  * @brief  Defines the possible values for configuring the HXTL Feedback Resistor.
  */
typedef enum {
    RCC_HXTL_FEEDBACK_RES_1_4M = 0U,    /*!< HXTL Feedback Resistor: 1.4 MΩ */
    RCC_HXTL_FEEDBACK_RES_0_8M          /*!< HXTL Feedback Resistor: 0.8 MΩ */
} RCC_HxtlFeedbackResSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLSTARTUPSELECTION  RCC Xhtl Startup Selection
  * @{
  * @brief  Defines the possible values for configuring the hxtl startup.
  */
typedef enum {
    RCC_HXTL_STARTUP_1024 = 0U,    /*!< HXTL Startup Time: 1024 cycles */
    RCC_HXTL_STARTUP_2048,         /*!< HXTL Startup Time: 2048 cycles */
    RCC_HXTL_STARTUP_4096,         /*!< HXTL Startup Time: 4096 cycles */
    RCC_HXTL_STARTUP_16384         /*!< HXTL Startup Time: 16384 cycles */
} RCC_HxtlStartupSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLDRIVERSELECTION RCC hxtlMode Selection
  * @{
  * @brief  Defines the possible values for configuring the hxtlMode.
  */
typedef enum {
    RCC_HXTL_8M_AGC_DISABLE  = 0x54U,    /*!< HXTL Frequency: 8 MHz, AGC Disabled */
    RCC_HXTL_12M_AGC_DISABLE = 0x76U,    /*!< HXTL Frequency: 12 MHz, AGC Disabled */
    RCC_HXTL_16M_AGC_DISABLE = 0x98U,    /*!< HXTL Frequency: 16 MHz, AGC Disabled */
    RCC_HXTL_24M_AGC_DISABLE = 0xBAU,    /*!< HXTL Frequency: 24 MHz, AGC Disabled */
    RCC_HXTL_32M_AGC_DISABLE = 0xDCU,    /*!< HXTL Frequency: 32 MHz, AGC Disabled */
    RCC_HXTL_8M_AGC_ENABLE   = 0x44U,    /*!< HXTL Frequency: 8 MHz, AGC Enabled */
    RCC_HXTL_12M_AGC_ENABLE  = 0x66U,    /*!< HXTL Frequency: 12 MHz, AGC Enabled */
    RCC_HXTL_16M_AGC_ENABLE  = 0x88U,    /*!< HXTL Frequency: 16 MHz, AGC Enabled */
    RCC_HXTL_24M_AGC_ENABLE  = 0xAAU,    /*!< HXTL Frequency: 24 MHz, AGC Enabled */
    RCC_HXTL_32M_AGC_ENABLE  = 0xCCU     /*!< HXTL Frequency: 32 MHz, AGC Enabled */
} RCC_HxtlDriverSelection;

/**
  * @}
  */

/** @defgroup RCC_MCDMRICCYCSELECTION RCC mirc1Mirc2Cyc Selection
  * @{
  * @brief  Defines the possible values for configuring the Mirc1 Mirc2 Cyc.
  */
typedef enum {
    RCC_MCD_MIRC1_8192_MIRC2_256 = 0x0U,    /*!< MIRC1: 8192 cycles, MIRC2: 256 cycles */
    RCC_MCD_MIRC1_16384_MIRC2_512,          /*!< MIRC1: 16384 cycles, MIRC2: 512 cycles */
    RCC_MCD_MIRC1_32768_MIRC2_1024,         /*!< MIRC1: 32768 cycles, MIRC2: 1024 cycles */
    RCC_MCD_MIRC1_65536_MIRC2_2048,         /*!< MIRC1: 65536 cycles, MIRC2: 2048 cycles */
    RCC_MCD_MIRC1_131072_MIRC2_4096,        /*!< MIRC1: 131072 cycles, MIRC2: 4096 cycles */
    RCC_MCD_MIRC1_262144_MIRC2_8192,        /*!< MIRC1: 262144 cycles, MIRC2: 8192 cycles */
    RCC_MCD_MIRC1_524288_MIRC2_16384,       /*!< MIRC1: 524288 cycles, MIRC2: 16384 cycles */
    RCC_MCD_MIRC1_1048576_MIRC2_32768       /*!< MIRC1: 1048576 cycles, MIRC2: 32768 cycles */
} RCC_McdMircCycleSelection;

/**
  * @}
  */

/** @defgroup RCC_MCDINTSELECTION RCC Fault interruption source Selection
  * @{
  * @brief  When MCD fails, NMI/CMU interrupt is generated.
  */
typedef enum {
    RCC_MCDINTSEL_NMI = 0x0U,    /*!< When MCD fails, NMI interrupt is generated. */
    RCC_MCDINTSEL_CMU            /*!< When MCD fails, CMU interrupt is generated. */
} RCC_McdIntSelection;

/**
  * @}
  */

/** @defgroup RCC_INTSOURCESELECTION RCC Interrupt Source Selection
  * @{
  * @brief  Defines the possible values for configuring the RCC interrupt sources.
  */
typedef enum {
    RCC_MIRC2RDY    = 0x00000002U,    /*!< MIRC2 Ready Interrupt */
    RCC_MIRC1RDY    = 0x00000200U,    /*!< MIRC1 Ready Interrupt */
    RCC_LIRCRDY     = 0x00008000U,    /*!< Low Impedance Reference Ready Interrupt */
    RCC_HXTLRDY     = 0x00020000U,    /*!< High-Speed Crystal Oscillator Ready Interrupt */
    RCC_HXTLFAIL    = 0x00100000U,    /*!< High-Speed Crystal Oscillator Failure Interrupt */
    RCC_PLL_LKDT    = 0x02000000U,    /*!< PLL Lock Detection Interrupt */
    RCC_PLL_LOL     = 0x20000000U,    /*!< PLL Loss of Lock Interrupt */
    RCC_OSCCLK_STOP = 0x80000000U     /*!< OSCCLK Stop Interrupt */
} RCC_IntSourceSelection;

/**
  * @}
  */

/** @defgroup RCC_CANFDSOURCESELECTION RCC CANFD Source Selection
  * @{
  * @brief  Defines the possible values for configuring the RCC CANFD sources.
  */
typedef enum {
    RCC_CANFD1SEL = 0U,    /*!< Select CANFD1 */
    RCC_CANFD2SEL          /*!< Select CANFD2 */
} RCC_CanfdSourceSelection;

/**
  * @}
  */

/** @defgroup RCC_REG_KEY RCC registers key mask
  * @{
  * @brief Macro definitions for RCC registers key mask.
  * @note  These masks are used to configure and control the registers that need key mask.
  */
#define RCC_PLLCR4_KEY     (0x5A69UL << 16)    /*!< PLLCR4 control key */
#define RCC_MIRC1CR_KEY    RCC_PLLCR4_KEY      /*!< MIRC1 control key */
#define RCC_MIRC2CR_KEY    RCC_PLLCR4_KEY      /*!< MIRC2 control key */
#define RCC_HXTLCR_KEY     RCC_PLLCR4_KEY      /*!< HXTL control key */
#define RCC_MCDCR_KEY      RCC_PLLCR4_KEY      /*!< MCD control key */

/**
  * @}
  */

/** @defgroup RCC_RSTCROPT RCC RSTCR Register Operations
  * @{
  * @brief Macro definitions for controlling system reset operations.
  * @note  These macros define specific keys used for reset and related operations.
  */
#define RCC_CPURST_VALUE    (0x55AA669AUL)     /*!< CPU reset value */
#define RCC_SIMXRS_VALUE    (0x55AA6699UL)     /*!< System reset value */

/**
  * @}
  */

/** @defgroup RCC_UNLOCK RCC Lock and Unlock Macros
  * @{
  * @brief Macro definitions for RCC lock and unlock operations.
  * @note These macros are used to enable or disable critical sections in the RCC configuration.
  */
#define RCC_UNLOCK    (0x55AA6699UL)    /*!< Unlock RCC register access */
#define RCC_LOCK      (0x55AA6698UL)    /*!< Lock RCC register access */

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
  * \brief  Enable PLL Loss of Lock Reset
  * \note   This function enables the PLL (Phase-Locked Loop) Loss of Lock Reset by setting 
  *         the PLLLOSERST bit in the RCC Control Register (RCC->CR).
  *         When the PLL loses its lock, this feature triggers a system reset.
  */
static inline void RCC_enablePllLoseRst (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_PLLLOSERST_M);
}

/**
  * \brief  Disable PLL Loss of Lock Reset
  * \note   This function disables the PLL (Phase-Locked Loop) Loss of Lock Reset by clearing 
  *         the PLLLOSERST bit in the RCC Control Register (RCC->CR).
  *         When the PLL loses its lock, this feature triggers a intterupt.
  */
static inline void RCC_disablePllLoseRst (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_PLLLOSERST_M);
}

/**
  * \brief  Read the PLL Lock Flag Status.
  * \note   This function checks the PLL lock bit (PLLLOCK) in the RCC Control Register (RCC->CR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the PLL Lock Flag.
  *          - 0: The PLL lock flag is not set.
  *          - 1: The PLL lock flag is set.
  */
static inline uint32_t RCC_readPllLockFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_CR_PLLLOCK_M) ? 1UL : 0UL;
}

/**
  * \brief  Enable PLL
  * \note   This function enables the PLL (Phase-Locked Loop) by setting the PLLEN bit 
  *         in the RCC Control Register (RCC->CR).
  *         Once enabled, the PLL can be used to generate higher frequency clock signals.
  */
static inline void RCC_enablePll (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_PLLEN_M);
}

/**
  * \brief  Disable PLL
  * \note   This function disables the PLL (Phase-Locked Loop) by clearing the PLLEN bit 
  *         in the RCC Control Register (RCC->CR).
  *         Once disabled, the PLL will no longer generate higher frequency clock signals.
  */
static inline void RCC_disablePll (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_PLLEN_M);
}

/**
  * \brief  Enable peripheral Kernal to Use HXTL (High-Speed External Crystal Oscillator)
  * \note   This function enables the use of the high-speed external crystal oscillator (HXTL) 
  *         for the kernal
  *         by setting the HXTLKEREN bit in the RCC Control Register (RCC->CR).
  */
static inline void RCC_enablePeriphKernalUseHxtl (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLKEREN_M);
}

/**
  * \brief  Disable peripheral Kernal from Using HXTL (High-Speed External Crystal Oscillator)
  * \note   This function disables the use of the high-speed external crystal oscillator (HXTL) 
  *         for the kernal
  *         by clearing the HXTLKEREN bit in the RCC Control Register (RCC->CR).
  */
static inline void RCC_disablePeriphKernalUseHxtl (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLKEREN_M);
}

/**
  * \brief  Enable HXTL Failure Reset
  * \note   This function enables the reset triggered by a failure of the high-speed external crystal oscillator (HXTL)
  *         by setting the HXTLFAILRST bit in the RCC Control Register (RCC->CR).
  *         When the HXTL fail, this feature triggers a system reset.
  */
static inline void RCC_enableHxtlFailRst (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLFAILRST_M);
}

/**
  * \brief  Disable HXTL Failure Reset
  * \note   This function disables the reset triggered by a failure of the high-speed external crystal oscillator (HXTL)
  *         by clearing the HXTLFAIL_RST bit in the RCC Control Register (RCC->CR).
  *         When the HXTL fail, this feature triggers a intterupt.
  */
static inline void RCC_disableHxtlFailRst (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLFAILRST_M);
}

/**
  * \brief  Enable HXTL Failure Detection
  * \note   This function enables the detection of failures in the high-speed external crystal oscillator (HXTL)
  *         by setting the HXTLDETEN bit in the RCC Control Register (RCC->CR).
  */
static inline void RCC_enableHxtlFailDetection (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLDETEN_M);
}

/**
  * \brief  Disable HXTL Failure Detection
  * \note   This function disables the detection of failures in the high-speed external crystal oscillator (HXTL)
  *         by clearing the HXTLDETEN bit in the RCC Control Register (RCC->CR).
  */
static inline void RCC_disableHxtlFailDetection (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLDETEN_M);
}

/**
  * \brief  Enable HXTL Bypass Mode
  * \note   This function enables the bypass mode for the high-speed external crystal oscillator (HXTL)
  *         by setting the HXTLBYP bit in the RCC Control Register (RCC->CR).
  *         When enabled, the HXTL input is bypassed, and an external clock signal can be used instead.
  */
static inline void RCC_enableHxtlBypass (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLBYP_M);
}

/**
  * \brief  Disable HXTL Bypass Mode
  * \note   This function disables the bypass mode for the high-speed external crystal oscillator (HXTL)
  *         by clearing the HXTLBYP bit in the RCC Control Register (RCC->CR).
  *         When disabled, the HXTL operates normally as a crystal oscillator.
  */
static inline void RCC_disableHxtlBypass (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLBYP_M);
}

/**
  * \brief  Read the High-Speed External Crystal Oscillator Ready Flag Status.
  * \note   This function checks the HXTL_RDY bit in the RCC Control Register (RCC->CR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the High-Speed External Crystal Oscillator Ready Flag.
  *          - 0: The high-speed external crystal oscillator ready flag is not set.
  *          - 1: The high-speed external crystal oscillator ready flag is set.
  */
static inline uint32_t RCC_readHxtlRdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLRDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Enable HXTL Oscillator
  * \note   This function enables the high-speed external crystal oscillator (HXTL)
  *         by setting the HXTLEN bit in the RCC Control Register (RCC->CR).
  *         When enabled, the HXTL oscillator starts operating.
  */
static inline void RCC_enableHxtl (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLEN_M);
}

/**
  * \brief  Disable HXTL Oscillator
  * \note   This function disables the high-speed external crystal oscillator (HXTL)
  *         by clearing the HXTLEN bit in the RCC Control Register (RCC->CR).
  *         When disabled, the HXTL oscillator stops operating.
  */
static inline void RCC_disableHxtl (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_HXTLEN_M);
}

/**
  * \brief  Read the Low-Speed Internal RC Oscillator Ready Flag Status.
  * \note   This function checks the LIRC_RDY bit in the RCC Control Register (RCC->CR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the Low-Speed Internal RC Oscillator Ready Flag.
  *          - 0: The low-speed internal RC oscillator ready flag is not set.
  *          - 1: The low-speed internal RC oscillator ready flag is set.
  */
static inline uint32_t RCC_readLircRdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_CR_LIRCRDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Enable Low-Speed Internal RC Oscillator (LIRC)
  * \note   This function enables the low-speed internal RC oscillator (LIRC)
  *         by setting the LIRCEN bit in the RCC Control Register (RCC->CR).
  *         When enabled, the LIRC oscillator starts operating.
  */
static inline void RCC_enableLirc (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_LIRCEN_M);
}

/**
  * \brief  Disable Low-Speed Internal RC Oscillator (LIRC)
  * \note   This function disables the low-speed internal RC oscillator (LIRC)
  *         by clearing the LIRCEN bit in the RCC Control Register (RCC->CR).
  *         When disabled, the LIRC oscillator stops operating.
  */
static inline void RCC_disableLirc (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_LIRCEN_M);
}

/**
  * \brief  Enable Peripheral Kernal Usage of Medium-Speed Internal RC Oscillator 1 (MIRC1)
  * \note   This function enables the kernal to use the Medium-Speed internal RC oscillator 1 (MIRC1)
  *         by setting the MIRC1KEREN bit in the RCC Control Register (RCC->CR).
  *         When enabled, the kernal can utilize MIRC1 as a clock source.
  */
static inline void RCC_enablePeriphKernalUseMirc1 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC1KEREN_M);
}

/**
  * \brief  Disable Peripheral Kernal Usage of Medium-Speed Internal RC Oscillator 1 (MIRC1)
  * \note   This function disables the kernal from using the Medium-Speed internal RC oscillator 1 (MIRC1)
  *         by clearing the MIRC1KEREN bit in the RCC Control Register (RCC->CR).
  *         When disabled, the kernal will not use MIRC1 as a clock source.
  */
static inline void RCC_disablePeriphKernalUseMirc1 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC1KEREN_M);
}

/**
  * \brief  Read the Medium-Speed Internal RC Oscillator 1 Ready Flag Status.
  * \note   This function checks the MIRC1_RDY bit in the RCC Control Register (RCC->CR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the Medium-Speed Internal RC Oscillator 1 Ready Flag.
  *          - 0: The Medium-Speed internal RC oscillator 1 ready flag is not set.
  *          - 1: The Medium-Speed internal RC oscillator 1 ready flag is set.
  */
static inline uint32_t RCC_readMirc1RdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC1RDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Enable Medium-Speed Internal RC Oscillator 1 (MIRC1)
  * \note   This function enables the Medium-Speed internal RC oscillator 1 (MIRC1)
  *         by setting the MIRC1EN bit in the RCC Control Register (RCC->CR).
  *         When enabled, the MIRC1 oscillator starts operating and can be used as a clock source.
  */
static inline void RCC_enableMirc1 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC1EN_M);
}

/**
  * \brief  Disable Medium-Speed Internal RC Oscillator 1 (MIRC1)
  * \note   This function disables the medium-speed internal RC oscillator 1 (MIRC1)
  *         by clearing the MIRC1EN bit in the RCC Control Register (RCC->CR).
  *         When disabled, the MIRC1 oscillator stops operating and cannot be used as a clock source.
  */
static inline void RCC_disableMirc1 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC1EN_M);
}

/**
  * \brief  Enable Peripheral Kernal Usage of Medium-Speed Internal RC Oscillator 2 (MIRC2)
  * \note   This function enables the Kernal to use the medium-speed internal RC oscillator 2 (MIRC2)
  *         by setting the MIRC2KEREN bit in the RCC Control Register (RCC->CR).
  *         When enabled, the Kernal can utilize MIRC2 as a clock source.
  */
static inline void RCC_enablePeriphKernalUseMirc2 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC2KEREN_M);
}

/**
  * \brief  Disable Peripheral Kernal Usage of Medium-Speed Internal RC Oscillator 2 (MIRC2)
  * \note   This function disables the kernal from using the medium-speed internal RC oscillator 2 (MIRC2)
  *         by clearing the MIRC2KEREN bit in the RCC Control Register (RCC->CR).
  *         When disabled, the kernal will not use MIRC2 as a clock source.
  */
static inline void RCC_disablePeriphKernalUseMirc2 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC2KEREN_M);
}

/**
  * \brief  Read the Medium-Speed Internal RC Oscillator 2 Ready Flag Status.
  * \note   This function checks the MIRC2_RDY bit in the RCC Control Register (RCC->CR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the Medium-Speed Internal RC Oscillator 2 Ready Flag.
  *          - 0: The Medium-Speed internal RC oscillator 2 ready flag is not set.
  *          - 1: The Medium-Speed internal RC oscillator 2 ready flag is set.
  */
static inline uint32_t RCC_readMirc2RdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC2RDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Enable Medium-Speed Internal RC Oscillator 2 (MIRC2)
  * \note   This function enables the medium-speed internal RC oscillator 2 (MIRC2)
  *         by setting the MIRC2EN bit in the RCC Control Register (RCC->CR).
  *         When enabled, the MIRC2 oscillator starts operating and can be used as a clock source.
  */
static inline void RCC_enableMirc2 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC2EN_M);
}

/**
  * \brief  Disable Medium-Speed Internal RC Oscillator 2 (MIRC2)
  * \note   This function disables the medium-speed internal RC oscillator 2 (MIRC2)
  *         by clearing the MIRC2EN bit in the RCC Control Register (RCC->CR).
  *         When disabled, the MIRC2 oscillator stops operating and cannot be used as a clock source.
  */
static inline void RCC_disableMirc2 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_CR_MIRC2EN_M);
}

/**
  * \brief  Enable Main Clock Output 2 (MCO2)
  * \note   This function enables the main clock output 2 (MCO2)
  *         by setting the MCO2EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
  *         When enabled, the MCO2 signal can be used as an external clock source.
  */
static inline void RCC_enableMco2 (void)
{
    SET_BIT(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO2EN_M);
}

/**
  * \brief  Disable Main Clock Output 2 (MCO2)
  * \note   This function disables the main clock output 2 (MCO2)
  *         by clearing the MCO2EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
  *         When disabled, the MCO2 signal is not active and cannot be used as an external clock source.
  */
static inline void RCC_disableMco2 (void)
{
    CLEAR_BIT(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO2EN_M);
}

/**
  * \brief  Select the Source for Main Clock Output 2 (MCO2)
  * \param  mco2SrcSel  RCC mco2 output source selection
  *                      This parameter can be any value of @ref RCC_MCOSOURCESEL
  * \note   This function selects the clock source for MCO2 by modifying the MCO2SEL bits
  *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
  */
static inline void RCC_selectMco2OutputSource (RCC_McoSourceSel mco2SrcSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO2SRC_M, ((uint32_t)mco2SrcSel << RCC_MCOCR_MCO2SRC_S));
}

/**
  * \brief  Select the Division Factor for Main Clock Output 2 (MCO2)
  * \param  mco2DivSel  Specifies the division factor for MCO2.
  *                         This parameter can be any value of @ref RCC_MCODIVSEL
  * \note   This function sets the division factor for MCO2 by modifying the MCO2DIV bits
  *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
  */
static inline void RCC_selectMco2OutputDiv (RCC_McoDivSel mco2DivSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO2DIV_M, (mco2DivSel << RCC_MCOCR_MCO2DIV_S));
}

/**
  * \brief  Enable Main Clock Output 1 (MCO1)
  * \note   This function enables the main clock output 1 (MCO1)
  *         by setting the MCO1EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
  *         When enabled, the MCO1 signal can be used as an external clock source.
  */
static inline void RCC_enableMco1 (void)
{
    SET_BIT(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO1EN_M);
}

/**
  * \brief  Disable Main Clock Output 1 (MCO1)
  * \note   This function disables the main clock output 1 (MCO1)
  *         by clearing the MCO1EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
  *         When disabled, the MCO1 signal is not active and cannot be used as an external clock source.
  */
static inline void RCC_disableMco1 (void)
{
    CLEAR_BIT(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO1EN_M);
}

/**
  * \brief  Select the Source for Main Clock Output 1 (MCO1)
  * \note   This function selects the clock source for MCO1 by modifying the MCO1SEL bits
  *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
  * \param  mco1SrcSel  RCC mco1 source selection
  *                      This parameter can be any value of @ref RCC_MCOSOURCESEL
  */
static inline void RCC_selectMco1OutputSource (RCC_McoSourceSel mco1SrcSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO1SRC_M, ((uint32_t)mco1SrcSel << RCC_MCOCR_MCO1SRC_S));
}

/**
  * \brief  Select the Division Factor for Main Clock Output 1 (MCO1)
  * \note   This function sets the division factor for MCO1 by modifying the MCO1DIV bits
  *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
  * \param  mco1DivSel  Specifies the division factor for MCO1.
  *                      This parameter can be any value of @ref RCC_MCODIVSEL
  */
static inline void RCC_selectMco1OutputDiv (RCC_McoDivSel mco1DivSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCOCR_MCO1DIV_M, mco1DivSel);
}

/**
  * \brief  Select the Division Factor for APB5 Clock Source
  * \note   This function sets the division factor for the APB5 clock source by modifying
  *         the APB5DIV bits in the RCC Configuration Register (RCC->CFGR).
  * \param  apb5ClkSrcDivSel  Specifies the division factor for the APB5 clock source.
  *                            This parameter can be any value of @ref RCC_APB5SRC
  */
static inline void RCC_selectApb5ClkSourceDiv (RCC_Apb5Src apb5ClkSrcDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_CFGR_APB5DIV_M, (apb5ClkSrcDivSel << RCC_CFGR_APB5DIV_S));
}

/**
  * \brief  Get the Division Factor for APB5 Clock (APB5CLK)
  * \note   This function retrieves the division factor for the APB5 clock by reading
  *         the APB5DIV bits in the RCC Configuration Register (RCC->CFGR).
  * \return The division factor for the APB5 clock.
  *         This value corresponds to one of the definitions in @ref RCC_APB5SRC
  */
static inline RCC_Apb5Src RCC_getApb5ClkDiv (void)
{
    return (RCC_Apb5Src)(READ_BIT(RCC->CFGR.WORDVAL, RCC_CFGR_APB5DIV_M) >> RCC_CFGR_APB5DIV_S);
}

/**
  * \brief  Select the Division Factor for APB2_4 Clock Source
  * \note   This function sets the division factor for the APB2_4 clock source by modifying
  *         the APB2DIV bits in the RCC Configuration Register (RCC->CFGR).
  * \param  apb2ClkSrcDivSel: Specifies the division factor for the APB2_4 clock source.
  *                         This parameter can be any value of @ref RCC_APB2AND4SRC
  */
static inline void RCC_selectApb2ClkSourceDiv (RCC_Apb2And4Src apb2ClkSrcDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_CFGR_APB2DIV_M, (apb2ClkSrcDivSel << RCC_CFGR_APB2DIV_S));
}

/**
  * \brief  Get the Division Factor for APB2 Clock (APB2CLK)
  * \note   This function retrieves the division factor for the APB2 clock by reading
  *         the APB2DIV bits in the RCC Configuration Register (RCC->CFGR).
  * \return The division factor for the APB2 clock.
  *         This value corresponds to one of the definitions in @ref RCC_APB2AND4SRC
  */
static inline RCC_Apb2And4Src RCC_getApb2ClkDiv (void)
{
    return (RCC_Apb2And4Src)(READ_BIT(RCC->CFGR.WORDVAL, RCC_CFGR_APB2DIV_M) >> RCC_CFGR_APB2DIV_S);
}

/**
  * \brief  Select the Division Factor for APB1_3 Clock Source
  * \note   This function sets the division factor for the APB1_3 clock source by modifying
  *         the APB1DIV bits in the RCC Configuration Register (RCC->CFGR).
  * \param  apb1ClkSrcDivSel: Specifies the division factor for the APB1_3 clock source.
  *                         This parameter can be any value of @ref RCC_APB1AND3SRC
  */
static inline void RCC_selectApb1ClkSourceDiv (RCC_Apb1And3Src apb1ClkSrcDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_CFGR_APB1DIV_M, (apb1ClkSrcDivSel << RCC_CFGR_APB1DIV_S));
}

/**
  * \brief  Get the Division Factor for APB1 Clock (APB1CLK)
  * \note   This function retrieves the division factor for the APB1 clock by reading
  *         the APB1DIV bits in the RCC Configuration Register (RCC->CFGR).
  * \return The division factor for the APB1 clock.
  *         This value corresponds to one of the definitions in @ref RCC_APB1AND3SRC
  */
static inline RCC_Apb1And3Src RCC_getApb1ClkDiv (void)
{
    return (RCC_Apb1And3Src)(READ_BIT(RCC->CFGR.WORDVAL, RCC_CFGR_APB1DIV_M) >> RCC_CFGR_APB1DIV_S);
}

/**
  * \brief  Select the Division Factor for HCLK Clock Source
  * \note   This function sets the division factor for the HCLK clock source by modifying
  *         the HCLK bits in the RCC Configuration Register (RCC->CFGR).
  * \param  HclkClkSrcSel: Specifies the division factor for the HCLK clock source.
  *                         This parameter can be any value of @ref RCC_HCLKSEL
  */
static inline void RCC_selectHclkClkSource (RCC_HclkSel HclkClkSrcSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_CFGR_HCLKSEL_M, (HclkClkSrcSel << RCC_CFGR_HCLKSEL_S));
}

/**
  * \brief  Get the Division Factor for HCLK Clock (HclkCLK)
  * \note   This function retrieves the division factor for the HCLK clock by reading
  *         the HCLKDIV bits in the RCC Configuration Register (RCC->CFGR).
  * \return The division factor for the Hclk clock.
  *         This value corresponds to one of the definitions in @ref RCC_HCLKSEL
  */
static inline RCC_HclkSel RCC_getHclkClkSelecton (void)
{
    return (RCC_HclkSel)(READ_BIT(RCC->CFGR.WORDVAL, RCC_CFGR_HCLKSEL_M) >> RCC_CFGR_HCLKSEL_S);
}

/**
  * \brief  Select the Division Factor for System Clock (SYSCLK)
  * \note   This function sets the division factor for the system clock by modifying
  *         the SYSDIV bits in the RCC Configuration Register (RCC->CFGR).
  * \param  sysClkDivSel: Specifies the division factor for the system clock.
  *                         This parameter can be any value of @ref RCC_SYSCLKDIVSEL
  */
static inline void RCC_selectSysClkDiv (RCC_SysclkDivSel sysClkDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_CFGR_SYSDIV_M, (sysClkDivSel << RCC_CFGR_SYSDIV_S));
}

/**
  * \brief  Get the Division Factor for System Clock (SYSCLK)
  * \note   This function retrieves the division factor for the system clock by reading
  *         the SYSDIV bits in the RCC Configuration Register (RCC->CFGR).
  * \return The division factor for the system clock.
  *         This value corresponds to one of the definitions in @ref RCC_SYSCLKDIVSEL
  */
static inline RCC_SysclkDivSel RCC_getSysClkDiv (void)
{
    return (RCC_SysclkDivSel)(READ_BIT(RCC->CFGR.WORDVAL, RCC_CFGR_SYSDIV_M) >> RCC_CFGR_SYSDIV_S);
}

/**
  * \brief  Select the System Clock Source
  * \note   This function selects the system clock source by modifying
  *         the SWSEL bits in the RCC Configuration Register (RCC->CFGR).
  * \param  sysClkSrc: Specifies the system clock source.
  *                      This parameter can be any value of \e RCC_SysclkSrc
  */
static inline void RCC_selectSystemClock (RCC_SysclkSrc sysClkSrc)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_CFGR_SWSEL_M, ((uint32_t)sysClkSrc << RCC_CFGR_SWSEL_S));
}

/**
  * \brief  Read the System Clock Switch Status.
  * \note   This function reads the SWSTA bit in the RCC Configuration Register (RCC->CFGR)
  *         and returns its value after shifting it right by 4 bits.
  * \return Returns the system clock switch status.
  *          - 0: RCC_SYSCLKSTATUS_MIRC2
  *          - 1: RCC_SYSCLKSTATUS_HXTL
  *          - 2: RCC_SYSCLKSTATUS_PLL
  *          - 3: RCC_SYSCLKSTATUS_MIRC1
  */
static inline uint32_t RCC_readSysClkSwitchStatus (void)
{
    return (READ_BIT(RCC->CFGR.WORDVAL, RCC_CFGR_SWSTA_M) >> RCC_CFGR_SWSTA_S);
}

/**
  * \brief  Enable OSCCLK fault detection
  * \note   This function enables the OSCCLK fault detection by setting
  *         the OSCCLKDETEN bit in the RCC PLL controller Register (RCC->PLLCR).
  */
static inline void RCC_enableOscclkFaultDetect (void)
{
    SET_BIT(RCC->PLLCR.WORDVAL, RCC_PLLCR_OSCCLKMONEN_M);
}

/**
  * \brief  Disable OSCCLK fault detection
  * \note   This function disables the OSCCLK fault detection by clearing
  *         the OSCCLKDETEN bit in the RCC PLL controller Register (RCC->PLLCR).
  */
static inline void RCC_disableOscclkFaultDetect (void)
{
    CLEAR_BIT(RCC->PLLCR.WORDVAL, RCC_PLLCR_OSCCLKMONEN_M);
}

/**
  * \brief  Set OSCCLK fault monitor start
  * \note   This function sets the OSCCLK fault monitor start by setting
  *         the OSCCLKMONSTART bit in the RCC PLL controller Register (RCC->PLLCR).
  * 
  * \param  enable  Specifies the OSCCLK fault monitor start mode.
  *                     This parameter can be true or false:
  *                       - 1: Software preparation
  *                       - 0: Hardware preparation
  */
static inline void RCC_setOscclkFaultMonitorStart (bool enable)
{
    MODIFY_REG(RCC->PLLCR.WORDVAL, RCC_PLLCR_OSCCLKMONSTART_M, (uint32_t)enable << RCC_PLLCR_OSCCLKMONSTART_S);
}

/**
  * \brief  Read the PLL Clock Source 
  * \note   This function reads the PLLSRC bit in the PLL Configuration Register (RCC->PLLCR).
  * \return Returns the PLL Clock Source.
  *          - 0: RCC_PLLSOURCE_MIRC2
  *          - 1: RCC_PLLSOURCE_HXTL
  *          - 2: RCC_PLLSOURCE_MIRC1
  */
static inline uint32_t RCC_readPllClockSource (void)
{
    return READ_BIT(RCC->PLLCR.WORDVAL, RCC_PLLCR_SRC_M);
}

/**
  * \brief  Select the PLL Clock Source
  * \note   This function selects the clock source for the PLL by modifying
  *         the PLLSRC bits in the PLL Configuration Register (RCC->PLLCR).
  * \param  pllClkSrc  Specifies the clock source for the PLL.
  *                     This parameter can be any value of @ref RCC_PLLSRC
  */
static inline void RCC_selectPllClockSource (RCC_PllSrc pllClkSrc)
{
    MODIFY_REG(RCC->PLLCR.WORDVAL, RCC_PLLCR_SRC_M, pllClkSrc);
}

/**
  * \brief  Enable OSCCLK stop Interrupt
  * \note   This function enables the OSCCLK stop (OSCCLKSTOP) interrupt by setting
  *         the OSCCLKSTOPIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated if the OSCCLK stop.
  */
static inline void RCC_enableOscclkStopInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_OSCCLKSTOP_M);
}

/**
  * \brief  Disable OSCCLK stop Interrupt
  * \note   This function disables the OSCCLK stop (OSCCLKSTOP) interrupt by clearing
  *         the OSCCLKSTOPIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated if the OSCCLK stop.
  */
static inline void RCC_disableOscclkStopInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_OSCCLKSTOP_M);
}

/**
  * \brief  Select the OSCCLK Fault Interrupt.
  * \note   This function selects the OSCCLK Fault interrupt source in the IER register (RCC->IER).
  * \param  oscclkFaultIntSel  Specifies the OSCCLK stop interrupt selection.
  *                             This parameter can be any value of @ref RCC_OSCCLKFAULTINTSEL
  */
static inline void RCC_selectOscclkFaultIntFunc (RCC_OscclkFaultIntSel oscclkFaultIntSel)
{
    MODIFY_REG(RCC->IER.WORDVAL, RCC_IER_OSCCLKFAULT_M, ((uint32_t)oscclkFaultIntSel << RCC_IER_OSCCLKFAULT_S));
}

/**
  * \brief  Enable PLL Loss of Lock Interrupt
  * \note   This function enables the PLL Loss of Lock (LOSE) interrupt by setting
  *         the PLL_LOLIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated if the PLL loses lock.
  */
static inline void RCC_enablePllLoseInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_PLLLOSE_M);
}

/**
  * \brief  Disable PLL Loss of Lock Interrupt
  * \note   This function disables the PLL Loss of Lock (LOSE) interrupt by clearing
  *         the PLL_LOLIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated if the PLL loses lock.
  */
static inline void RCC_disablePllLoseInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_PLLLOSE_M);
}

/**
  * \brief  Enable PLL Lock Detection Interrupt
  * \note   This function enables the PLL Lock Detection (LOCK) interrupt by setting
  *         the PLL_LKDTIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated if the PLL lock detection.
  */
static inline void RCC_enablePllLockInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_PLLLOCK_M);
}

/**
  * \brief  Disable PLL Lock Detection Interrupt
  * \note   This function disables the PLL Lock Detection (LOCK) interrupt by clearing
  *         the PLL_LKDTIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated if the PLL lock detection.
  */
static inline void RCC_disablePllLockInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_PLLLOCK_M);
}

/**
  * \brief  Enable High-Speed Crystal Oscillator Failure Interrupt
  * \note   This function enables the High-Speed Crystal Oscillator (HXTL) failure interrupt by setting
  *         the HXTLFAIL bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated if the high-speed crystal oscillator fails.
  */
static inline void RCC_enableHxtlFailInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_HXTLFAIL_M);
}

/**
  * \brief  Disable High-Speed Crystal Oscillator Failure Interrupt
  * \note   This function disables the High-Speed Crystal Oscillator (HXTL) failure interrupt by clearing
  *         the HXTLFAIL bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated if the high-speed crystal oscillator fails.
  */
static inline void RCC_disableHxtlFailInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_HXTLFAIL_M);
}

/**
  * \brief  Enable High-Speed Crystal Oscillator Ready Interrupt
  * \note   This function enables the High-Speed Crystal Oscillator (HXTL) ready interrupt by setting
  *         the HXTLRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated when the high-speed crystal oscillator is ready.
  */
static inline void RCC_enableHxtlRdyInt(void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_HXTLRDY_M);
}

/**
  * \brief  Disable High-Speed Crystal Oscillator Ready Interrupt
  * \note   This function disables the High-Speed Crystal Oscillator (HXTL) ready interrupt by clearing
  *         the HXTLRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated when the high-speed crystal oscillator is ready.
  */
static inline void RCC_disableHxtlRdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_HXTLRDY_M);
}

/**
  * \brief  Select the HXTL Fault Interrupt.
  * \note   This function selects the HXTL Fault interrupt source in the IER register (RCC->IER).
  * \param  hxtlFaultIntSel  Specifies the HXTL Fault interrupt selection.
  *                             This parameter can be any value of @ref RCC_XHTLFAULTINTSEL
  */
static inline void RCC_selectHxtlFaultIntFunc (RCC_HxtlFaultIntSel hxtlFaultIntSel)
{
    MODIFY_REG(RCC->IER.WORDVAL, RCC_IER_HXTLFAULT_M, ((uint32_t)hxtlFaultIntSel << RCC_IER_HXTLFAULT_S));
}

/**
  * \brief  Enable Low-Speed Internal RC Oscillator Ready Interrupt
  * \note   This function enables the Low-Speed Internal RC Oscillator (LIRC) ready interrupt by setting
  *         the LIRCRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated when the low-speed internal RC oscillator is ready.
  */
static inline void RCC_enableLircRdyInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_LIRCRDY_M);
}

/**
  * \brief  Disable Low-Speed Internal RC Oscillator Ready Interrupt
  * \note   This function disables the Low-Speed Internal RC Oscillator (LIRC) ready interrupt by clearing
  *         the LIRCRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated when the low-speed internal RC oscillator is ready.
  */
static inline void RCC_disableLircRdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_LIRCRDY_M);
}

/**
  * \brief  Enable Medium-Speed Internal RC Oscillator 1 Ready Interrupt
  * \note   This function enables the Medium-Speed Internal RC Oscillator 1 (MIRC1) ready interrupt by setting
  *         the MIRC1RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated when the medium-speed internal RC oscillator 1 is ready.
  */
static inline void RCC_enableMirc1RdyInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_MIRC1RDY_M);
}

/**
  * \brief  Disable Medium-Speed Internal RC Oscillator 1 Ready Interrupt
  * \note   This function disables the Medium-Speed Internal RC Oscillator 1 (MIRC1) ready interrupt by clearing
  *         the MIRC1RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated when the medium-speed internal RC oscillator 1 is ready.
  */
static inline void RCC_disableMirc1RdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_MIRC1RDY_M);
}

/**
  * \brief  Enable Medium-Speed Internal RC Oscillator 2 Ready Interrupt
  * \note   This function enables the Medium-Speed Internal RC Oscillator 2 (MIRC2) ready interrupt by setting
  *         the MIRC2RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When enabled, an interrupt will be generated when the medium-speed internal RC oscillator 2 is ready.
  */
static inline void RCC_enableMirc2RdyInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_IER_MIRC2RDY_M);
}

/**
  * \brief  Disable Medium-Speed Internal RC Oscillator 2 Ready Interrupt
  * \note   This function disables the Medium-Speed Internal RC Oscillator 2 (MIRC2) ready interrupt by clearing
  *         the MIRC2RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
  *         When disabled, no interrupt will be generated when the medium-speed internal RC oscillator 2 is ready.
  */
static inline void RCC_disableMirc2RdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_IER_MIRC2RDY_M);
}

/**
  * \brief  Read the OSCCLK stop Interrupt Flag.
  * \note   This function checks the OSCCLKSTOP bit in the OSCCLK stop Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the OSCCLK stop Interrupt Flag.
  *          - 0: The OSCCLK stop Interrupt Flag is not set.
  *          - 1: The OSCCLK stop Interrupt Flag is set.
  */
static inline uint32_t RCC_readOscclkStopIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_OSCCLKSTOP_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the PLL Loss of Lock Interrupt Flag.
  * \note   This function checks the PLLLOSE bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the PLL Loss of Lock Interrupt Flag.
  *          - 0: The PLL Loss of Lock Interrupt Flag is not set.
  *          - 1: The PLL Loss of Lock Interrupt Flag is set.
  */
static inline uint32_t RCC_readPllLoseIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_PLLLOSE_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the PLL Lock Interrupt Flag.
  * \note   This function checks the PLLLOCK bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the PLL Lock Interrupt Flag.
  *          - 0: The PLL Lock Interrupt Flag is not set.
  *          - 1: The PLL Lock Interrupt Flag is set.
  */
static inline uint32_t RCC_readPllLockIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_PLLLOCK_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the HXTL Fail Interrupt Flag.
  * \note   This function checks the HXTLFAIL bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the HXTL Fail Interrupt Flag.
  *          - 0: The HXTL Fail Interrupt Flag is not set.
  *          - 1: The HXTL Fail Interrupt Flag is set.
  */
static inline uint32_t RCC_readHxtlFailIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_HXTLFAIL_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the HXTL Ready Interrupt Flag.
  * \note   This function checks the HXTLRDY bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the HXTL Ready Interrupt Flag.
  *          - 0: The HXTL Ready Interrupt Flag is not set.
  *          - 1: The HXTL Ready Interrupt Flag is set.
  */
static inline uint32_t RCC_readHxtlRdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_HXTLRDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the LIRC Ready Interrupt Flag.
  * \note   This function checks the LIRCRDY bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the LIRC Ready Interrupt Flag.
  *          - 0: The LIRC Ready Interrupt Flag is not set.
  *          - 1: The LIRC Ready Interrupt Flag is set.
  */
static inline uint32_t RCC_readLircRdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_LIRCRDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the MIRC1 Ready Interrupt Flag.
  * \note   This function checks the MIRC1RDY bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the MIRC1 Ready Interrupt Flag.
  *          - 0: The MIRC1 Ready Interrupt Flag is not set.
  *          - 1: The MIRC1 Ready Interrupt Flag is set.
  */
static inline uint32_t RCC_readMirc1RdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_MIRC1RDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the MIRC2 Ready Interrupt Flag.
  * \note   This function checks the MIRC2RDY bit in the RCC Interrupt Flag Register (RCC->IFR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the MIRC2 Ready Interrupt Flag.
  *          - 0: The MIRC2 Ready Interrupt Flag is not set.
  *          - 1: The MIRC2 Ready Interrupt Flag is set.
  */
static inline uint32_t RCC_readMirc2RdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_IFR_MIRC2RDY_M) ? 1UL : 0UL;
}

/**
  * \brief  Clear the OSCCLK stop Interrupt Flag.
  * \note   This function clears the OSCCLKSTOP bit in the RCC Clear Register (RCC->CLR)
  *         by setting the OSCCLKSTOP bit.
  *         Clearing this flag is necessary after a OSCCLK stop interrupt occurs.
  */
static inline void RCC_clearOscclkStopIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_OSCCLKSTOP_M);
}

/**
  * \brief  Clear the PLL Loss of Lock Interrupt Flag.
  * \note   This function clears the PLLLOSE bit in the RCC Clear Register (RCC->CLR)
  *         by setting the PLLLOSE bit.
  *         Clearing this flag is necessary after a PLL loss of lock interrupt occurs.
  */
static inline void RCC_clearPllLoseIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_PLLLOSE_M);
}

/**
  * \brief  Clear the PLL Lock Interrupt Flag.
  * \note   This function clears the PLLLOCK bit in the RCC Clear Register (RCC->CLR)
  *         by setting the PLLLOCK bit.
  *         Clearing this flag is necessary after a PLL lock interrupt occurs.
  */
static inline void RCC_clearPllLockIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_PLLLOCK_M);
}

/**
  * \brief  Clear the High-Speed External Crystal Oscillator (HXTL) Failure Interrupt Flag.
  * \note   This function clears the HXTLFAIL bit in the RCC Clear Register (RCC->CLR)
  *         by setting the HXTLFAIL bit.
  *         Clearing this flag is necessary after an external high-speed crystal oscillator failure interrupt occurs.
  */
static inline void RCC_clearHxtlFailIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_HXTLFAIL_M);
}

/**
  * \brief  Clear the High-Speed External Crystal Oscillator (HXTL) Ready Interrupt Flag.
  * \note   This function clears the HXTLRDY bit in the RCC Clear Register (RCC->CLR)
  *         by setting the HXTLRDY bit.
  *         Clearing this flag is necessary after an external high-speed crystal oscillator ready interrupt occurs.
  */
static inline void RCC_clearHxtlRdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_HXTLRDY_M);
}

/**
  * \brief  Clear the Low-Speed Internal RC Oscillator (LIRC) Ready Interrupt Flag.
  * \note   This function clears the LIRCRDY bit in the RCC Clear Register (RCC->CLR)
  *         by setting the LIRCRDYCLR bit.
  *         Clearing this flag is necessary after an internal low-speed RC oscillator ready interrupt occurs.
  */
static inline void RCC_clearLircRdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_LIRCRDY_M);
}

/**
  * \brief  Clear the Medium-Speed Internal RC Oscillator 1 (MIRC1) Ready Interrupt Flag.
  * \note   This function clears the MIRC1RDY bit in the RCC Clear Register (RCC->CLR)
  *         by setting the MIRC1RDY bit.
  *         Clearing this flag is necessary after an internal medium-speed RC oscillator 1 ready interrupt occurs.
  */
static inline void RCC_clearMirc1RdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_MIRC1RDY_M);
}

/**
  * \brief  Clear the Medium-Speed Internal RC Oscillator 2 (MIRC2) Ready Interrupt Flag.
  * \note   This function clears the MIRC2RDY bit in the RCC Clear Register (RCC->CLR)
  *         by setting the MIRC2RDY bit.
  *         Clearing this flag is necessary after an internal medium-speed RC oscillator 2 ready interrupt occurs.
  */
static inline void RCC_clearMirc2RdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_CLR_MIRC2RDY_M);
}

/**
  * \brief  Enable the Auxiliary Clock Input.
  * \note   This function enables the auxiliary clock input by setting the AUXCLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Enabling this bit allows the system to use the auxiliary clock source.
  */
static inline void RCC_enableAuxClockIn (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_AUXCLKEN_M);
}

/**
  * \brief  Disable the Auxiliary Clock Input.
  * \note   This function disables the auxiliary clock input by clearing the AUXCLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Clearing this bit prevents the system from using the auxiliary clock source.
  */
static inline void RCC_disableAuxClockIn (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_AUXCLKEN_M);
}

/**
  * \brief  Select the Auxiliary Clock Input Reset Mode.
  * \note   This function selects the auxiliary clock input reset mode by setting the AUXCLKRST bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Setting this bit configures the system to use the auxiliary clock source in reset mode.
  */
static inline void RCC_selectAuxClockInResetMode (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_AUXCLKRST_M);
}

/**
  * \brief  Select the Auxiliary Clock Input Normal Mode.
  * \note   This function selects the auxiliary clock input normal mode by clearing the AUXCLKRST bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Clearing this bit configures the system to use the auxiliary clock source in normal mode.
  */
static inline void RCC_selectAuxClockInNormalMode (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_AUXCLKRST_M);
}

/**
  * \brief  Enable the DLL2 Clock.
  * \note   This function enables the DLL2 clock by setting the DLL2CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Enabling this bit allows the system to use the DLL2 clock source.
  */
static inline void RCC_enableDll2Clock (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_DLL2CLKEN_M);
}

/**
  * \brief  Disable the DLL2 Clock.
  * \note   This function disables the DLL2 clock by clearing the DLL2CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Clearing this bit prevents the system from using the DLL2 clock source.
  */
static inline void RCC_disableDll2Clock (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_DLL2CLKEN_M);
}

/**
  * \brief  Enable the HRPWM2 Clock.
  * \note   This function enables the HRPWM2 clock by setting the HRPWM2CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Enabling this bit allows the system to use the HRPWM2 clock source.
  */
static inline void RCC_enableHrpwm2Clock (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_HRPWM2CLKEN_M);
}

/**
  * \brief  Disable the HRPWM2 Clock.
  * \note   This function disables the HRPWM2 clock by clearing the HRPWM2CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Clearing this bit prevents the system from using the HRPWM2 clock source.
  */
static inline void RCC_disableHrpwm2Clock (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_HRPWM2CLKEN_M);
}

/**
  * \brief  Enable the DLL1 Clock.
  * \note   This function enables the DLL1 clock by setting the DLL1CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Enabling this bit allows the system to use the DLL1 clock source.
  */
static inline void RCC_enableDll1Clock (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_DLL1CLKEN_M);
}

/**
  * \brief  Disable the DLL1 Clock.
  * \note   This function disables the DLL1 clock by clearing the DLL1CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Clearing this bit prevents the system from using the DLL1 clock source.
  */
static inline void RCC_disableDll1Clock (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_DLL1CLKEN_M);
}

/**
  * \brief  Enable the HRPWM1 Clock.
  * \note   This function enables the HRPWM1 clock by setting the HRPWM1CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Enabling this bit allows the system to use the HRPWM1 clock source.
  */
static inline void RCC_enableHrpwm1Clock (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_HRPWM1CLKEN_M);
}

/**
  * \brief  Disable the HRPWM1 Clock.
  * \note   This function disables the HRPWM1 clock by clearing the HRPWM1CLKEN bit in the
  *         RCC IP Clock Select Register (RCC->IPCLKSEL).
  *         Clearing this bit prevents the system from using the HRPWM1 clock source.
  */
static inline void RCC_disableHrpwm1Clock (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_HRPWM1CLKEN_M);
}

/**
  * \brief  Read the CANFD PCLK Source Status.
  * \note   This function checks the CANFDPCLK_ST bit in the RCC IP Clock Select Register (RCC->IPCLKSEL)
  *         and returns a boolean value indicating the status of the CANFD peripheral clock source.
  * \param  canfdSource  Select the source of CANFD.
  *                           This parameter can be any value of @ref RCC_CANFDSOURCESELECTION
  * \return Returns the status of the CANFD peripheral clock source.
  *         - 0: CANFD pclock source is OSC (Oscillator)
  *         - 1: CANFD pclock source is PERIPHERAL (Peripheral clock)
  */
static inline uint32_t RCC_readCanfdPclkSourceStatus (RCC_CanfdSourceSelection canfdSource)
{
    if (canfdSource == RCC_CANFD1SEL)
    {
        return READ_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD1PCLKST_M) ? 1UL : 0UL;
    }
    else
    {
        return READ_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD2PCLKST_M) ? 1UL : 0UL;
    }
}

/**
  * \brief  Select the CANFD Time Base Clock Division
  * \note   This function selects the division factor for the CANFD time base clock by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  canfdSource  Select the source of CANFD.
  *                           This parameter can be any value of @ref RCC_CANFDSOURCESELECTION
  * \param  canfdTimeClkDiv  Specifies the division factor for the CANFD time base clock.
  *                           This parameter can be any value of @ref RCC_CANFDTIMECLKDIV
  */
static inline void RCC_selectCanfdTimeClkDiv (RCC_CanfdSourceSelection canfdSource, RCC_CanfdTimeclkDiv canfdTimeClkDiv)
{
    if (canfdSource == RCC_CANFD1SEL)
    {
        MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD1TIMCLKDIV_M, (canfdTimeClkDiv << RCC_IPCLKSEL_CANFD1TIMCLKDIV_S));
    }
    else
    {
        MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD2TIMCLKDIV_M, (canfdTimeClkDiv << RCC_IPCLKSEL_CANFD2TIMCLKDIV_S));
    }
}

/**
  * \brief  Select the CANFD Oscillator Clock Source
  * \note   This function selects the clock source for the CANFD oscillator by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  canfdSource  Select the source of CANFD.
  *                           This parameter can be any value of @ref RCC_CANFDSOURCESELECTION
  * \param  canfdOscClk  Specifies the clock source for the CANFD oscillator.
  *                       This parameter can be any value of @ref RCC_CANFDOSCCLK
  */
static inline void RCC_selectCanfdOscClkSource (RCC_CanfdSourceSelection canfdSource, RCC_CanfdOscClk canfdOscClk)
{
    if (canfdSource == RCC_CANFD1SEL)
    {
        MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD1OSCSEL_M, (canfdOscClk << RCC_IPCLKSEL_CANFD1OSCSEL_S));
    }
    else
    {
        MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD2OSCSEL_M, (canfdOscClk << RCC_IPCLKSEL_CANFD2OSCSEL_S));
    }
}

/**
  * \brief  Select the CANFD1 Peripheral Clock Source
  * \note   This function selects the clock source for the CANFD1 peripheral by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  canfd1PeripheralClk  Specifies the clock source for the CANFD1 peripheral.
  *                               This parameter can be any value of @ref RCC_CANFD1PERIPHERALCLK
  */
static inline void RCC_selectCanfd1PeripheralClkSource (RCC_Canfd1PeripheralClk canfd1PeripheralClk)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD1CLKSEL_M, ((uint32_t)canfd1PeripheralClk << RCC_IPCLKSEL_CANFD1CLKSEL_S));
}

/**
  * \brief  Select the CANFD2 Peripheral Clock Source
  * \note   This function selects the clock source for the CANFD2 peripheral by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  canfd2PeripheralClk  Specifies the clock source for the CANFD2 peripheral.
  *                               This parameter can be any value of @ref RCC_CANFD2PERIPHERALCLK
  */
static inline void RCC_selectCanfd2PeripheralClkSource (RCC_Canfd2PeripheralClk canfd2PeripheralClk)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CANFD2CLKSEL_M, ((uint32_t)canfd2PeripheralClk << RCC_IPCLKSEL_CANFD2CLKSEL_S));
}

/**
  * \brief  Read the CAN1 PCLK Source Status.
  * \note   This function checks the CAN1PCLK_ST bit in the RCC IP Clock Select Register (RCC->IPCLKSEL)
  *         and returns a boolean value indicating the status of the CAN1 peripheral clock source.
  * \return Returns the status of the CAN1 pclock source.
  *          - 0: CAN1 pclock source is OSC (Oscillator)
  *          - 1: CAN1 pclock source is PERIPHERAL (Peripheral clock)
  */
static inline uint32_t RCC_readCan1PclkSourceStatus (void)
{
    return READ_BIT(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CAN1PCLKST_M) ? 1UL : 0UL;
}

/**
  * \brief  Select the CAN1 Time Base Clock Division
  * \note   This function selects the division factor for the CAN1 time base clock by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  can1TimeClkDiv  Specifies the division factor for the CAN1 time base clock.
  *                          This parameter can be any value of @ref RCC_CAN1TIMECLKDIV
  */
static inline void RCC_selectCan1TimeClkDiv (RCC_Can1TimeclkDiv can1TimeClkDiv)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CAN1TIMCLKDIV_M, (can1TimeClkDiv << RCC_IPCLKSEL_CAN1TIMCLKDIV_S));
}

/**
  * \brief  Select the CAN1 Oscillator Clock Source
  * \note   This function selects the clock source for the CAN1 oscillator by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  can1OscClk  Specifies the clock source for the CAN1 oscillator.
  *                      This parameter can be any value of @ref RCC_CAN1OSCCLK
  */
static inline void RCC_selectCan1OscClkSource (RCC_Can1OscClk can1OscClk)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CAN1OSCSEL_M, (can1OscClk << RCC_IPCLKSEL_CAN1OSCSEL_S));
}

/**
  * \brief  Select the CAN1 Peripheral Clock Source
  * \note   This function selects the clock source for the CAN1 peripheral by modifying
  *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
  * \param  can1PeripheralClk  Specifies the clock source for the CAN1 peripheral.
  *                             This parameter can be any value of @ref RCC_CAN1PERIPHERALCLK
  */
static inline void RCC_selectCan1PeripheralClkSource (RCC_Can1PeripheralClk can1PeripheralClk)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_IPCLKSEL_CAN1CLKSEL_M, can1PeripheralClk);
}

/**
  * \brief  Read the PLL Multiplication Factor (PLLM) value.
  * \note   This function reads the PLLM bits in the RCC PLL Configuration Register (RCC->PLLCR1)
  *         and returns their value after shifting it right by 8 bits.
  * \return Returns the PLLM value.
  */
static inline uint32_t RCC_readPllmValue (void)
{
    return (READ_BIT(RCC->PLLCR1.WORDVAL, RCC_PLLCR1_PLLM_M) >> RCC_PLLCR1_PLLM_S);
}

/**
  * \brief  Select the PLLM Multiplication Factor
  * \note   This function selects the PLLM Multiplication factor by modifying
  *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
  * \param  pllmSelection  Specifies the PLLM Multiplication factor.
  *                         This parameter can be any value of @ref RCC_PLLMSELECTION.
  */
static inline void RCC_selectPllm (RCC_PllmSelection pllmSelection)
{
    MODIFY_REG(RCC->PLLCR1.WORDVAL, RCC_PLLCR1_PLLM_M, (pllmSelection << RCC_PLLCR1_PLLM_S));
}

/**
  * \brief  Read the PLL Division Factor (PLLN) value.
  * \note   This function reads the PLLN bits in the RCC PLL Configuration Register (RCC->PLLCR1)
  *         and returns their value after shifting it right by 4 bits.
  * \return Returns the PLLN value.
  */
static inline uint32_t RCC_readPllnValue (void)
{
    return (READ_BIT(RCC->PLLCR1.WORDVAL, RCC_PLLCR1_PLLN_M) >> RCC_PLLCR1_PLLN_S);
}

/**
  * \brief  Select the PLLN Division Factor
  * \note   This function selects the PLLN Division factor by modifying
  *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
  * \param  pllnSelection  Specifies the PLLN Division factor.
  *                         This parameter can be any value of @ref RCC_PLLNSELECTION
  */
static inline void RCC_selectPlln (RCC_PllnSelection pllnSelection)
{
    MODIFY_REG(RCC->PLLCR1.WORDVAL, RCC_PLLCR1_PLLN_M, (pllnSelection << RCC_PLLCR1_PLLN_S));
}

/**
  * \brief  Read the PLL Post-Division Factor (PLLP) value.
  * \note   This function reads the PLLP bits in the RCC PLL Configuration Register (RCC->PLLCR1)
  *         and returns their value after shifting it right by 17 bits.
  * \return Returns the PLLP value.
  */
static inline uint32_t RCC_readPllpValue (void)
{
    return (READ_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_PDIV_M) >> RCC_PLLCR2_PDIV_S);
}

/**
  * \brief  Select the PLLP Division Factor
  * \note   This function selects the PLLP Division factor by modifying
  *         the appropriate bits in the PLLCR2 register (RCC->PLLCR2).
  * \param  pllpSelection  Specifies the PLLP Division factor.
  *                         This parameter can be any value of @ref RCC_PLLPSELECTION
  */
static inline void RCC_selectPllp (RCC_PllpSelection pllpSelection)
{
    MODIFY_REG(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_PDIV_M, (pllpSelection << RCC_PLLCR2_PDIV_S));
}

/**
  * \brief  Enable the PLLP Clock Output.
  * \note   This function enables the PLLP clock output by setting the PLLPEN bit in the
  *         RCC PLL Control Register (RCC->PLLCR2).
  *         Enabling this bit allows the system to use the PLLP clock source.
  */
static inline void RCC_enablePllpClockOutput (void)
{
    SET_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_PEN_M);
}

/**
  * \brief  Disable the PLLP Clock Output.
  * \note   This function disables the PLLP clock output by clearing the PLLPEN bit in the
  *         RCC PLL Control Register (RCC->PLLCR2).
  *         Disabling this bit stops the system from using the PLLP clock source.
  */
static inline void RCC_disablePllpClockOutput (void)
{
    CLEAR_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_PEN_M);
}

/**
  * \brief  Select the PLLQ Division Factor
  * \note   This function selects the PLLQ Division factor by modifying
  *         the appropriate bits in the PLLCR2 register (RCC->PLLCR2).
  * \param  pllqSelection  Specifies the PLLQ Division factor.
  *                         This parameter can be any value of @ref RCC_PLLQSELECTION
  */
static inline void RCC_selectPllq (RCC_PllqSelection pllqSelection)
{
    MODIFY_REG(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_QDIV_M, (pllqSelection << RCC_PLLCR2_QDIV_S));
}

/**
  * \brief  Enable the PLLQ Clock Output.
  * \note   This function enables the PLLQ clock output by setting the PLLQEN bit in the
  *         RCC PLL Control Register (RCC->PLLCR2).
  *         Enabling this bit allows the system to use the PLLQ clock source.
  */
static inline void RCC_enablePllqClockOutput (void)
{
    SET_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_QEN_M);
}

/**
  * \brief  Disable the PLLQ Clock Output.
  * \note   This function disables the PLLQ clock output by clearing the PLLQEN bit in the
  *         RCC PLL Control Register (RCC->PLLCR2).
  *         Disabling this bit stops the system from using the PLLQ clock source.
  */
static inline void RCC_disablePllqClockOutput (void)
{
    CLEAR_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_QEN_M);
}

/**
  * \brief  Select the PLLR Division Factor
  * \note   This function selects the PLLR Division factor by modifying
  *         the appropriate bits in the PLLCR2 register (RCC->PLLCR2).
  * \param  pllrSelection  Specifies the PLLR Division factor.
  *                         This parameter can be any value of @ref RCC_PLLRSELECTION
  */
static inline void RCC_selectPllr (RCC_PllrSelection pllrSelection)
{
    MODIFY_REG(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_RDIV_M, (pllrSelection << RCC_PLLCR2_RDIV_S));
}

/**
  * \brief  Read the the PLLR Division value.
  * \note   This function reads the PLLR bits in the RCC PLL Configuration Register (RCC->PLLCR2)
  *         and returns their value after shifting it right by 1 bits.
  * \return Returns the PLLR value.
  */
static inline uint32_t RCC_readPllrValue (void)
{
    return (READ_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_RDIV_M) >> RCC_PLLCR2_RDIV_S);
}

/**
  * \brief  Enable the PLLR Clock Output.
  * \note   This function enables the PLLR clock output by setting the PLLREN bit in the
  *         RCC PLL Control Register (RCC->PLLCR2).
  *         Enabling this bit allows the system to use the PLLR clock source.
  */
static inline void RCC_enablePllrClockOutput (void)
{
    SET_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_REN_M);
}

/**
  * \brief  Disable the PLLR Clock Output.
  * \note   This function disables the PLLR clock output by clearing the PLLREN bit in the
  *         RCC PLL Control Register (RCC->PLLCR2).
  *         Disabling this bit stops the system from using the PLLR clock source.
  */
static inline void RCC_disablePllrClockOutput (void)
{
    CLEAR_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLCR2_REN_M);
}

/**
  * \brief  Enable the PLL Force Lock.
  * \note   This function enables the PLL force lock by setting the FORCELKEN bit in the
  *         RCC PLL Control Register (RCC->PLLCR3).
  *         Enabling this bit forces the PLL to lock.
  */
static inline void RCC_enablePllForceLock (void)
{
    SET_BIT(RCC->PLLCR3.WORDVAL, RCC_PLLCR3_FORCELKEN_M);
}

/**
  * \brief  Disable the PLL Force Lock.
  * \note   This function disables the PLL force lock by clearing the FORCELKEN bit in the
  *         RCC PLL Control Register (RCC->PLLCR3).
  *         Disabling this bit stops forcing the PLL to lock.
  */
static inline void RCC_disablePllForceLock (void)
{
    CLEAR_BIT(RCC->PLLCR3.WORDVAL, RCC_PLLCR3_FORCELKEN_M);
}

/**
  * \brief  Select the PLL Lock Detection Threshold
  * \note   This function selects the PLL lock detection threshold by modifying
  *         the appropriate bits in the PLLCR3 register (RCC->PLLCR3).
  * \param  pllLkdtSelection  Specifies the PLL lock detection threshold.
  *                            This parameter can be any value of @ref RCC_PLLLKDTSELECTION
  */
static inline void RCC_selectPllLdkt (RCC_PllLkdtSelection pllLkdtSelection)
{
    MODIFY_REG(RCC->PLLCR3.WORDVAL, RCC_PLLCR3_PLLLKDTSET_M, pllLkdtSelection);
}

/**
  * \brief  Read the PLL Lock Over Count.
  * \note   This function reads the value of the PLL Status Register 1 (PLLSR1)
  *         and returns the word value of the register.
  * \return Returns the value of the PLL Status Register 1 (PLLSR1).
  */
static inline uint32_t RCC_readPllLockOverCnt (void)
{
    return READ_REG(RCC->PLLSR1.WORDVAL);
}

/**
  * \brief  Reset the UPP module.
  * \note   This function resets the UPP module by setting the UPP bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the UPP module.
  */
static inline void RCC_resetUppModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_UPPRST_M);
}

/**
  * \brief  Release the reset of the UPP module.
  * \note   This function releases the reset of the UPP module by clearing the UPP bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the UPP module to resume normal operation after a reset.
  */
static inline void RCC_releaseUppModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_UPPRST_M);
}

/**
  * \brief  Reset the EMIF module.
  * \note   This function resets the EMIF module by setting the EMIF bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the EMIF module.
  */
static inline void RCC_resetEmifModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EMIFRST_M);
}

/**
  * \brief  Release the reset of the EMIF module.
  * \note   This function releases the reset of the EMIF module by clearing the EMIF bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the EMIF module to resume normal operation after a reset.
  */
static inline void RCC_releaseEmifModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EMIFRST_M);
}

/**
  * \brief  Reset the SEMA module.
  * \note   This function resets the SEMA module by setting the SEMA bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the SEMA module.
  */
static inline void RCC_resetSemaModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_SEMARST_M);
}

/**
  * \brief  Release the reset of the SEMA module.
  * \note   This function releases the reset of the SEMA module by clearing the SEMA bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the SEMA module to resume normal operation after a reset.
  */
static inline void RCC_releaseSemaModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_SEMARST_M);
}

/**
  * \brief  Reset the MU module.
  * \note   This function resets the MU module by setting the MU bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the MU module.
  */
static inline void RCC_resetMuModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_MURST_M);
}

/**
  * \brief  Release the reset of the MU module.
  * \note   This function releases the reset of the MU module by clearing the MU bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the MU module to resume normal operation after a reset.
  */
static inline void RCC_releaseMuModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_MURST_M);
}

/**
  * \brief  Reset the GPIOH module.
  * \note   This function resets the GPIOH module by setting the GPIOH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the GPIOH module.
  */
static inline void RCC_resetGpiohModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOHRST_M);
}

/**
  * \brief  Release the reset of the GPIOH module.
  * \note   This function releases the reset of the GPIOH module by clearing the GPIOH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOH module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpiohModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOHRST_M);
}

/**
  * \brief  Reset the GPIOG module.
  * \note   This function resets the GPIOG module by setting the GPIOG bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the GPIOG module.
  */
static inline void RCC_resetGpiogModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOGRST_M);
}

/**
  * \brief  Release the reset of the GPIOG module.
  * \note   This function releases the reset of the GPIOG module by clearing the GPIOG bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOG module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpiogModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOGRST_M);
}

/**
  * \brief  Reset the GPIOF module.
  * \note   This function resets the GPIOF module by setting the GPIOF bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the GPIOF module.
  */
static inline void RCC_resetGpiofModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOFRST_M);
}

/**
  * \brief  Release the reset of the GPIOF module.
  * \note   This function releases the reset of the GPIOF module by clearing the GPIOF bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOF module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpiofModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOFRST_M);
}

/**
  * \brief  Reset the GPIOE module.
  * \note   This function resets the GPIOE module by setting the GPIOE bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the GPIOE module.
  */
static inline void RCC_resetGpioeModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOERST_M);
}

/**
  * \brief  Release the reset of the GPIOE module.
  * \note   This function releases the reset of the GPIOE module by clearing the GPIOE bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOE module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpioeModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOERST_M);
}

/**
  * \brief  Reset the GPIOD module.
  * \note   This function resets the GPIOD module by setting the GPIOD bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Resetting this bit allows for a reset of the GPIOD module.
  */
static inline void RCC_resetGpiodModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIODRST_M);
}

/**
  * \brief  Release the reset of the GPIOD module.
  * \note   This function releases the reset of the GPIOD module by clearing the GPIOD bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOD module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpiodModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIODRST_M);
}

/**
  * \brief  Reset the GPIOC module.
  * \note   This function resets the GPIOC module by setting the GPIOC bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the GPIOC module.
  */
static inline void RCC_resetGpiocModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOCRST_M);
}

/**
  * \brief  Release the reset of the GPIOC module.
  * \note   This function releases the reset of the GPIOC module by clearing the GPIOC bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOC module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpiocModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOCRST_M);
}

/**
  * \brief  Reset the GPIOB module.
  * \note   This function resets the GPIOB module by setting the GPIOB bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the GPIOB module.
  */
static inline void RCC_resetGpiobModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOBRST_M);
}

/**
  * \brief  Release the reset of the GPIOB module.
  * \note   This function releases the reset of the GPIOB module by clearing the GPIOB bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOB module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpiobModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOBRST_M);
}

/**
  * \brief  Reset the GPIOA module.
  * \note   This function resets the GPIOA module by setting the GPIOA bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the GPIOA module.
  */
static inline void RCC_resetGpioaModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOARST_M);
}

/**
  * \brief  Release the reset of the GPIOA module.
  * \note   This function releases the reset of the GPIOA module by clearing the GPIOA bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the GPIOA module to resume normal operation after a reset.
  */
static inline void RCC_releaseGpioaModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_GPIOARST_M);
}

/**
  * \brief  Reset the EMATH module.
  * \note   This function resets the EMATH module by setting the EMATH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the EMATH module.
  */
static inline void RCC_resetEmathModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EMATHRST_M);
}

/**
  * \brief  Release the reset of the EMATH module.
  * \note   This function releases the reset of the EMATH module by clearing the EMATH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the EMATH module to resume normal operation after a reset.
  */
static inline void RCC_releaseEmathModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EMATHRST_M);
}

/**
  * \brief  Reset the QSPI module.
  * \note   This function resets the QSPI module by setting the QSPI bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the QSPI module.
  */
static inline void RCC_resetQspiModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_QSPIRST_M);
}

/**
  * \brief  Release the reset of the QSPI module.
  * \note   This function releases the reset of the QSPI module by clearing the QSPI bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the QSPI module to resume normal operation after a reset.
  */
static inline void RCC_releaseQspiModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_QSPIRST_M);
}

/**
  * \brief  Reset the CPU2MMATH module.
  * \note   This function resets the CPU2MMATH module by setting the CPU2MMATH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the CPU2MMATH module.
  */
static inline void RCC_resetCpu2mmathModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_CPU2MMATHRST_M);
}

/**
  * \brief  Release the reset of the CPU2MMATH module.
  * \note   This function releases the reset of the CPU2MMATH module by clearing the CPU2MMATH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the CPU2MMATH module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu2mmathModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_CPU2MMATHRST_M);
}

/**
  * \brief  Reset the CPU1MMATH module.
  * \note   This function resets the CPU1MMATH module by setting the CPU1MMATH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the CPU1MMATH module.
  */
static inline void RCC_resetCpu1mmathModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_CPU1MMATHRST_M);
}

/**
  * \brief  Release the reset of the CPU1MMATH module.
  * \note   This function releases the reset of the CPU1MMATH module by clearing the CPU1MMATH bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the CPU1MMATH module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu1mmathModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_CPU1MMATHRST_M);
}

/**
  * \brief  Reset the EDMA2 module.
  * \note   This function resets the EDMA2 module by setting the EDMA2 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the EDMA2 module.
  */
static inline void RCC_resetEdma2Module (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EDMA2RST_M);
}

/**
  * \brief  Release the reset of the EDMA2 module.
  * \note   This function releases the reset of the EDMA2 module by clearing the EDMA2 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the EDMA2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEdma2Module (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EDMA2RST_M);
}

/**
  * \brief  Reset the EDMA1 module.
  * \note   This function resets the EDMA1 module by setting the EDMA1 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the EDMA1 module.
  */
static inline void RCC_resetEdma1Module (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EDMA1RST_M);
}

/**
  * \brief  Release the reset of the EDMA1 module.
  * \note   This function releases the reset of the EDMA1 module by clearing the EDMA1 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the EDMA1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEdma1Module (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_EDMA1RST_M);
}

/**
  * \brief  Reset the DMAMUX2 module.
  * \note   This function resets the DMAMUX2 module by setting the DMAMUX2 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the DMAMUX2 module.
  */
static inline void RCC_resetDmamux2Module (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_DMAMUX2RST_M);
}

/**
  * \brief  Release the reset of the DMAMUX2 module.
  * \note   This function releases the reset of the DMAMUX2 module by clearing the DMAMUX2 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the DMAMUX2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDmamux2Module (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_DMAMUX2RST_M);
}

/**
  * \brief  Reset the DMAMUX1 module.
  * \note   This function resets the DMAMUX1 module by setting the DMAMUX1 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the DMAMUX1 module.
  */
static inline void RCC_resetDmamux1Module (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_DMAMUX1RST_M);
}

/**
  * \brief  Release the reset of the DMAMUX1 module.
  * \note   This function releases the reset of the DMAMUX1 module by clearing the DMAMUX1 bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the DMAMUX1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDmamux1Module (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_DMAMUX1RST_M);
}

/**
  * \brief  Reset the SMPU module.
  * \note   This function resets the SMPU module by setting the SMPU bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the SMPU module.
  */
static inline void RCC_resetSmpuModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_SMPURST_M);
}

/**
  * \brief  Release the reset of the SMPU module.
  * \note   This function releases the reset of the SMPU module by clearing the SMPU bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the SMPU module to resume normal operation after a reset.
  */
static inline void RCC_releaseSmpuModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_SMPURST_M);
}

/**
  * \brief  Reset the FMU module.
  * \note   This function resets the FMU module by setting the FMU bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Setting this bit allows for a reset of the FMU module.
  */
static inline void RCC_resetFmuModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_FMURST_M);
}

/**
  * \brief  Release the reset of the FMU module.
  * \note   This function releases the reset of the FMU module by clearing the FMU bit in the
  *         RCC AHB1 Reset Register (RCC->AHBRST1).
  *         Clearing this bit allows the FMU module to resume normal operation after a reset.
  */
static inline void RCC_releaseFmuModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHBRST1_FMURST_M);
}

/**
  * \brief  Reset the CANFD2 module.
  * \note   This function resets the CANFD2 module by setting the CANFD2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the CANFD2 module.
  */
static inline void RCC_resetCanfd2Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CANFD2RST_M);
}

/**
  * \brief  Release the reset of the CANFD2 module.
  * \note   This function releases the reset of the Canfd2 module by clearing the CANFD2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the CANFD2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCanfd2Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CANFD2RST_M);
}

/**
  * \brief  Reset the CANFD1 module.
  * \note   This function resets the CANFD1 module by setting the CANFD1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the CANFD1 module.
  */
static inline void RCC_resetCanfd1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CANFD1RST_M);
}

/**
  * \brief  Release the reset of the CANFD1 module.
  * \note   This function releases the reset of the CANFD1 module by clearing the CANFD1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the CANFD1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCanfd1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CANFD1RST_M);
}

/**
  * \brief  Reset the CAN1 module.
  * \note   This function resets the CAN1 module by setting the CAN1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the CAN1 module.
  */
static inline void RCC_resetCan1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CAN1RST_M);
}

/**
  * \brief  Release the reset of the CAN1 module.
  * \note   This function releases the reset of the CAN1 module by clearing the CAN1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the CAN1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCan1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CAN1RST_M);
}

/**
  * \brief  Reset the LIN2 module.
  * \note   This function resets the LIN2 module by setting the LIN2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the LIN2 module.
  */
static inline void RCC_resetLin2Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_LIN2RST_M);
}

/**
  * \brief  Release the reset of the LIN2 module.
  * \note   This function releases the reset of the LIN2 module by clearing the LIN2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the LIN2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseLin2Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_LIN2RST_M);
}

/**
  * \brief  Reset the LIN1 module.
  * \note   This function resets the LIN1 module by setting the LIN1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the LIN1 module.
  */
static inline void RCC_resetLin1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_LIN1RST_M);
}

/**
  * \brief  Release the reset of the LIN1 module.
  * \note   This function releases the reset of the LIN1 module by clearing the LIN1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the LIN1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseLin1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_LIN1RST_M);
}

/**
  * \brief  Reset the BGCRC2 module.
  * \note   This function resets the BGCRC2 module by setting the BGCRC2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the BGCRC2 module.
  */
static inline void RCC_resetBgcrc2Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_BGCRC2RST_M);
}

/**
  * \brief  Release the reset of the BGCRC2 module.
  * \note   This function releases the reset of the BGCRC2 module by clearing the BGCRC2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the BGCRC2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseBgcrc2Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_BGCRC2RST_M);
}

/**
  * \brief  Reset the BGCRC1 module.
  * \note   This function resets the BGCRC1 module by setting the BGCRC1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the BGCRC1 module.
  */
static inline void RCC_resetBgcrc1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_BGCRC1RST_M);
}

/**
  * \brief  Release the reset of the BGCRC1 module.
  * \note   This function releases the reset of the BGCRC1 module by clearing the BGCRC1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the BGCRC1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseBgcrc1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_BGCRC1RST_M);
}

/**
  * \brief  Reset the CRC2 module.
  * \note   This function resets the CRC2 module by setting the CRC2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the CRC2 module.
  */
static inline void RCC_resetCrc2Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CRC2RST_M);
}

/**
  * \brief  Release the reset of the CRC2 module.
  * \note   This function releases the reset of the CRC2 module by clearing the CRC2 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the CRC2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCrc2Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CRC2RST_M);
}

/**
  * \brief  Reset the CRC1 module.
  * \note   This function resets the CRC1 module by setting the CRC1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the CRC1 module.
  */
static inline void RCC_resetCrc1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CRC1RST_M);
}

/**
  * \brief  Release the reset of the CRC1 module.
  * \note   This function releases the reset of the CRC1 module by clearing the CRC1 bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the CRC1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCrc1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_CRC1RST_M);
}

/**
  * \brief  Reset the AESHASH module.
  * \note   This function resets the AESHASH module by setting the AESHASH bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the AESHASH module.
  */
static inline void RCC_resetAesHashModule (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_AESHASHRST_M);
}

/**
  * \brief  Release the reset of the AESHASH module.
  * \note   This function releases the reset of the AES module by clearing the AESHASH bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the AESHASH module to resume normal operation after a reset.
  */
static inline void RCC_releaseAesHashModule (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_AESHASHRST_M);
}

/**
  * \brief  Reset the TRNG module.
  * \note   This function resets the TRNG module by setting the TRNG bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Setting this bit allows for a reset of the TRNG module.
  */
static inline void RCC_resetTrngModule (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_TRNGRST_M);
}

/**
  * \brief  Release the reset of the TRNG module.
  * \note   This function releases the reset of the TRNG module by clearing the TRNG bit in the
  *         RCC AHB2 Reset Register (RCC->AHBRST2).
  *         Clearing this bit allows the TRNG module to resume normal operation after a reset.
  */
static inline void RCC_releaseTrngModule (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHBRST2_TRNGRST_M);
}

/**
  * \brief  Reset the EPWM18 module.
  * \note   This function resets the EPWM18 module by setting the EPWM18 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM18 module.
  */
static inline void RCC_resetEpwm18Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM18RST_M);
}

/**
  * \brief  Release the reset of the EPWM18 module.
  * \note   This function releases the reset of the EPWM18 module by clearing the EPWM18 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM18 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm18Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM18RST_M);
}

/**
  * \brief  Reset the EPWM17 module.
  * \note   This function resets the EPWM17 module by setting the EPWM17 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM17 module.
  */
static inline void RCC_resetEpwm17Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM17RST_M);
}

/**
  * \brief  Release the reset of the EPWM17 module.
  * \note   This function releases the reset of the EPWM17 module by clearing the EPWM17 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM17 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm17Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM17RST_M);
}

/**
  * \brief  Reset the EQEP6 module.
  * \note   This function resets the EQEP6 module by setting the EQEP6 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EQEP6 module.
  */
static inline void RCC_resetEqep6Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP6RST_M);
}

/**
  * \brief  Release the reset of the EQEP6 module.
  * \note   This function releases the reset of the EQEP6 module by clearing the EQEP6 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EQEP6 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEqep6Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP6RST_M);
}

/**
  * \brief  Reset the EQEP5 module.
  * \note   This function resets the EQEP5 module by setting the EQEP5 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EQEP5 module.
  */
static inline void RCC_resetEqep5Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP5RST_M);
}

/**
  * \brief  Release the reset of the EQEP5 module.
  * \note   This function releases the reset of the EQEP5 module by clearing the EQEP5 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EQEP5 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEqep5Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP5RST_M);
}

/**
  * \brief  Reset the EQEP4 module.
  * \note   This function resets the EQEP4 module by setting the EQEP4 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EQEP4 module.
  */
static inline void RCC_resetEqep4Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP4RST_M);
}

/**
  * \brief  Release the reset of the EQEP4 module.
  * \note   This function releases the reset of the EQEP4 module by clearing the EQEP4 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EQEP4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEqep4Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP4RST_M);
}

/**
  * \brief  Reset the EQEP3 module.
  * \note   This function resets the EQEP3 module by setting the EQEP3 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EQEP3 module.
  */
static inline void RCC_resetEqep3Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP3RST_M);
}

/**
  * \brief  Release the reset of the EQEP3 module.
  * \note   This function releases the reset of the EQEP3 module by clearing the EQEP3 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EQEP3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEqep3Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP3RST_M);
}

/**
  * \brief  Reset the EQEP2 module.
  * \note   This function resets the EQEP2 module by setting the EQEP2 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EQEP2 module.
  */
static inline void RCC_resetEqep2Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP2RST_M);
}

/**
  * \brief  Release the reset of the EQEP2 module.
  * \note   This function releases the reset of the EQEP2 module by clearing the EQEP2 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EQEP2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEqep2Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP2RST_M);
}

/**
  * \brief  Reset the EQEP1 module.
  * \note   This function resets the EQEP1 module by setting the EQEP1 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EQEP1 module.
  */
static inline void RCC_resetEqep1Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP1RST_M);
}

/**
  * \brief  Release the reset of the EQEP1 module.
  * \note   This function releases the reset of the EQEP1 module by clearing the EQEP1 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EQEP1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEqep1Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EQEP1RST_M);
}

/**
  * \brief  Reset the ECAP7 module.
  * \note   This function resets the ECAP7 module by setting the ECAP7 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP7 module.
  */
static inline void RCC_resetEcap7Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP7RST_M);
}

/**
  * \brief  Release the reset of the ECAP7 module.
  * \note   This function releases the reset of the ECAP7 module by clearing the ECAP7 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP7 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap7Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP7RST_M);
}

/**
  * \brief  Reset the ECAP6 module.
  * \note   This function resets the ECAP6 module by setting the ECAP6 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP6 module.
  */
static inline void RCC_resetEcap6Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP6RST_M);
}

/**
  * \brief  Release the reset of the ECAP6 module.
  * \note   This function releases the reset of the ECAP6 module by clearing the ECAP6 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP6 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap6Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP6RST_M);
}

/**
  * \brief  Reset the ECAP5 module.
  * \note   This function resets the ECAP5 module by setting the ECAP5 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP5 module.
  */
static inline void RCC_resetEcap5Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP5RST_M);
}

/**
  * \brief  Release the reset of the ECAP5 module.
  * \note   This function releases the reset of the ECAP5 module by clearing the ECAP5 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP5 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap5Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP5RST_M);
}

/**
  * \brief  Reset the ECAP4 module.
  * \note   This function resets the ECAP4 module by setting the ECAP4 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP4 module.
  */
static inline void RCC_resetEcap4Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP4RST_M);
}

/**
  * \brief  Release the reset of the ECAP4 module.
  * \note   This function releases the reset of the ECAP4 module by clearing the ECAP4 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap4Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP4RST_M);
}

/**
  * \brief  Reset the ECAP3 module.
  * \note   This function resets the ECAP3 module by setting the ECAP3 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP3 module.
  */
static inline void RCC_resetEcap3Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP3RST_M);
}

/**
  * \brief  Release the reset of the ECAP3 module.
  * \note   This function releases the reset of the ECAP3 module by clearing the ECAP3 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap3Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP3RST_M);
}

/**
  * \brief  Reset the ECAP2 module.
  * \note   This function resets the ECAP2 module by setting the ECAP2 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP2 module.
  */
static inline void RCC_resetEcap2Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP2RST_M);
}

/**
  * \brief  Release the reset of the ECAP2 module.
  * \note   This function releases the reset of the ECAP2 module by clearing the ECAP2 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap2Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP2RST_M);
}

/**
  * \brief  Reset the ECAP1 module.
  * \note   This function resets the ECAP1 module by setting the ECAP1 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the ECAP1 module.
  */
static inline void RCC_resetEcap1Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP1RST_M);
}

/**
  * \brief  Release the reset of the ECAP1 module.
  * \note   This function releases the reset of the ECAP1 module by clearing the ECAP1 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the ECAP1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEcap1Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_ECAP1RST_M);
}

/**
  * \brief  Reset the EPWM16 module.
  * \note   This function resets the EPWM16 module by setting the EPWM16 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM16 module.
  */
static inline void RCC_resetEpwm16Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM16RST_M);
}

/**
  * \brief  Release the reset of the EPWM16 module.
  * \note   This function releases the reset of the EPWM16 module by clearing the EPWM16 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM16 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm16Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM16RST_M);
}

/**
  * \brief  Reset the EPWM15 module.
  * \note   This function resets the EPWM15 module by setting the EPWM15 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM15 module.
  */
static inline void RCC_resetEpwm15Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM15RST_M);
}

/**
  * \brief  Release the reset of the EPWM15 module.
  * \note   This function releases the reset of the EPWM15 module by clearing the EPWM15 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM15 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm15Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM15RST_M);
}

/**
  * \brief  Reset the EPWM14 module.
  * \note   This function resets the EPWM14 module by setting the EPWM14 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM14 module.
  */
static inline void RCC_resetEpwm14Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM14RST_M);
}

/**
  * \brief  Release the reset of the EPWM14 module.
  * \note   This function releases the reset of the EPWM14 module by clearing the EPWM14 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM14 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm14Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM14RST_M);
}

/**
  * \brief  Reset the EPWM13 module.
  * \note   This function resets the EPWM13 module by setting the EPWM13 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM13 module.
  */
static inline void RCC_resetEpwm13Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM13RST_M);
}

/**
  * \brief  Release the reset of the EPWM13 module.
  * \note   This function releases the reset of the EPWM13 module by clearing the EPWM13 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM13 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm13Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM13RST_M);
}

/**
  * \brief  Reset the EPWM12 module.
  * \note   This function resets the EPWM12 module by setting the EPWM12 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM12 module.
  */
static inline void RCC_resetEpwm12Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM12RST_M);
}

/**
  * \brief  Release the reset of the EPWM12 module.
  * \note   This function releases the reset of the EPWM12 module by clearing the EPWM12 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM12 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm12Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM12RST_M);
}

/**
  * \brief  Reset the EPWM11 module.
  * \note   This function resets the EPWM11 module by setting the EPWM11 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM11 module.
  */
static inline void RCC_resetEpwm11Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM11RST_M);
}

/**
  * \brief  Release the reset of the EPWM11 module.
  * \note   This function releases the reset of the EPWM11 module by clearing the EPWM11 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM11 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm11Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM11RST_M);
}

/**
  * \brief  Reset the EPWM10 module.
  * \note   This function resets the EPWM10 module by setting the EPWM10 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM11 module.
  */
static inline void RCC_resetEpwm10Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM10RST_M);
}

/**
  * \brief  Release the reset of the EPWM10 module.
  * \note   This function releases the reset of the EPWM10 module by clearing the EPWM10 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM10 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm10Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM10RST_M);
}

/**
  * \brief  Reset the EPWM9 module.
  * \note   This function resets the EPWM9 module by setting the EPWM9 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM9 module.
  */
static inline void RCC_resetEpwm9Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM9RST_M);
}

/**
  * \brief  Release the reset of the EPWM9 module.
  * \note   This function releases the reset of the EPWM9 module by clearing the EPWM9 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM9 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm9Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM9RST_M);
}

/**
  * \brief  Reset the EPWM8 module.
  * \note   This function resets the EPWM8 module by setting the EPWM8 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM8 module.
  */
static inline void RCC_resetEpwm8Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM8RST_M);
}

/**
  * \brief  Release the reset of the EPWM8 module.
  * \note   This function releases the reset of the EPWM8 module by clearing the EPWM8 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM8 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm8Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM8RST_M);
}

/**
  * \brief  Reset the EPWM7 module.
  * \note   This function resets the EPWM7 module by setting the EPWM7 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM7 module.
  */
static inline void RCC_resetEpwm7Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM7RST_M);
}

/**
  * \brief  Release the reset of the EPWM7 module.
  * \note   This function releases the reset of the EPWM7 module by clearing the EPWM7 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM7 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm7Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM7RST_M);
}

/**
  * \brief  Reset the EPWM6 module.
  * \note   This function resets the EPWM6 module by setting the EPWM6 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM6 module.
  */
static inline void RCC_resetEpwm6Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM6RST_M);
}

/**
  * \brief  Release the reset of the EPWM6 module.
  * \note   This function releases the reset of the EPWM6 module by clearing the EPWM6 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM6 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm6Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM6RST_M);
}

/**
  * \brief  Reset the EPWM5 module.
  * \note   This function resets the EPWM5 module by setting the EPWM5 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM5 module.
  */
static inline void RCC_resetEpwm5Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM5RST_M);
}

/**
  * \brief  Release the reset of the EPWM5 module.
  * \note   This function releases the reset of the EPWM5 module by clearing the EPWM5 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM5 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm5Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM5RST_M);
}

/**
  * \brief  Reset the EPWM4 module.
  * \note   This function resets the EPWM4 module by setting the EPWM4 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM4 module.
  */
static inline void RCC_resetEpwm4Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM4RST_M);
}

/**
  * \brief  Release the reset of the EPWM4 module.
  * \note   This function releases the reset of the EPWM4 module by clearing the EPWM4 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm4Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM4RST_M);
}

/**
  * \brief  Reset the EPWM3 module.
  * \note   This function resets the EPWM3 module by setting the EPWM3 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM3 module.
  */
static inline void RCC_resetEpwm3Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM3RST_M);
}

/**
  * \brief  Release the reset of the EPWM3 module.
  * \note   This function releases the reset of the EPWM3 module by clearing the EPWM3 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm3Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM3RST_M);
}

/**
  * \brief  Reset the EPWM2 module.
  * \note   This function resets the EPWM2 module by setting the EPWM2 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM2 module.
  */
static inline void RCC_resetEpwm2Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM2RST_M);
}

/**
  * \brief  Release the reset of the EPWM2 module.
  * \note   This function releases the reset of the EPWM2 module by clearing the EPWM2 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm2Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM2RST_M);
}

/**
  * \brief  Reset the EPWM1 module.
  * \note   This function resets the EPWM1 module by setting the EPWM1 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Setting this bit allows for a reset of the EPWM1 module.
  */
static inline void RCC_resetEpwm1Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM1RST_M);
}

/**
  * \brief  Release the reset of the EPWM1 module.
  * \note   This function releases the reset of the EPWM1 module by clearing the EPWM1 bit in the
  *         RCC APB Reset Register 1 (RCC->APBRST1).
  *         Clearing this bit allows the EPWM1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpwm1Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APBRST1_EPWM1RST_M);
}

/**
  * \brief  Reset the CMPSS11 module.
  * \note   This function resets the CMPSS11 module by setting the CMPSS11 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS11 module.
  */
static inline void RCC_resetCmpss11Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS11RST_M);
}

/**
  * \brief  Release the reset of the CMPSS11 module.
  * \note   This function releases the reset of the CMPSS11 module by clearing the CMPSS11 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS11 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss11Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS11RST_M);
}

/**
  * \brief  Reset the CMPSS10 module.
  * \note   This function resets the CMPSS10 module by setting the CMPSS10 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS10 module.
  */
static inline void RCC_resetCmpss10Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS10RST_M);
}

/**
  * \brief  Release the reset of the CMPSS10 module.
  * \note   This function releases the reset of the CMPSS10 module by clearing the CMPSS10 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS10 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss10Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS10RST_M);
}

/**
  * \brief  Reset the CMPSS9 module.
  * \note   This function resets the CMPSS9 module by setting the CMPSS9 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS9 module.
  */
static inline void RCC_resetCmpss9Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS9RST_M);
}

/**
  * \brief  Release the reset of the CMPSS9 module.
  * \note   This function releases the reset of the CMPSS9 module by clearing the CMPSS9 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS9 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss9Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS9RST_M);
}

/**
  * \brief  Reset the CMPSS8 module.
  * \note   This function resets the CMPSS8 module by setting the CMPSS8 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS8 module.
  */
static inline void RCC_resetCmpss8Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS8RST_M);
}

/**
  * \brief  Release the reset of the CMPSS8 module.
  * \note   This function releases the reset of the CMPSS8 module by clearing the CMPSS8 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS8 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss8Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS8RST_M);
}

/**
  * \brief  Reset the CMPSS7 module.
  * \note   This function resets the CMPSS7 module by setting the CMPSS7 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS7 module.
  */
static inline void RCC_resetCmpss7Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS7RST_M);
}

/**
  * \brief  Release the reset of the CMPSS7 module.
  * \note   This function releases the reset of the CMPSS7 module by clearing the CMPSS7 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS7 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss7Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS7RST_M);
}

/**
  * \brief  Reset the CMPSS6 module.
  * \note   This function resets the CMPSS6 module by setting the CMPSS6 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS6 module.
  */
static inline void RCC_resetCmpss6Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS6RST_M);
}

/**
  * \brief  Release the reset of the CMPSS6 module.
  * \note   This function releases the reset of the CMPSS6 module by clearing the CMPSS6 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS6 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss6Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS6RST_M);
}

/**
  * \brief  Reset the CMPSS5 module.
  * \note   This function resets the CMPSS5 module by setting the CMPSS5 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS5 module.
  */
static inline void RCC_resetCmpss5Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS5RST_M);
}

/**
  * \brief  Release the reset of the CMPSS5 module.
  * \note   This function releases the reset of the CMPSS5 module by clearing the CMPSS5 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS5 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss5Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS5RST_M);
}

/**
  * \brief  Reset the CMPSS4 module.
  * \note   This function resets the CMPSS4 module by setting the CMPSS4 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS4 module.
  */
static inline void RCC_resetCmpss4Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS4RST_M);
}

/**
  * \brief  Release the reset of the CMPSS4 module.
  * \note   This function releases the reset of the CMPSS4 module by clearing the CMPSS4 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss4Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS4RST_M);
}

/**
  * \brief  Reset the CMPSS3 module.
  * \note   This function resets the CMPSS3 module by setting the CMPSS3 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS3 module.
  */
static inline void RCC_resetCmpss3Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS3RST_M);
}

/**
  * \brief  Release the reset of the CMPSS3 module.
  * \note   This function releases the reset of the CMPSS3 module by clearing the CMPSS3 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss3Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS3RST_M);
}

/**
  * \brief  Reset the CMPSS2 module.
  * \note   This function resets the CMPSS2 module by setting the CMPSS2 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS2 module.
  */
static inline void RCC_resetCmpss2Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS2RST_M);
}

/**
  * \brief  Release the reset of the CMPSS2 module.
  * \note   This function releases the reset of the CMPSS2 module by clearing the CMPSS2 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss2Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS2RST_M);
}

/**
  * \brief  Reset the CMPSS1 module.
  * \note   This function resets the CMPSS1 module by setting the CMPSS1 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the CMPSS1 module.
  */
static inline void RCC_resetCmpss1Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS1RST_M);
}

/**
  * \brief  Release the reset of the CMPSS1 module.
  * \note   This function releases the reset of the CMPSS1 module by clearing the CMPSS1 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the CMPSS1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCmpss1Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_CMPSS1RST_M);
}

/**
  * \brief  Reset the XBAR module.
  * \note   This function resets the XBAR module by setting the XBAR bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the XBAR module.
  */
static inline void RCC_resetXbarModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_XBARRST_M);
}

/**
  * \brief  Release the reset of the XBAR module.
  * \note   This function releases the reset of the XBAR module by clearing the XBAR bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the XBAR module to resume normal operation after a reset.
  */
static inline void RCC_releaseXbarModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_XBARRST_M);
}

/**
  * \brief  Reset the ADCD module.
  * \note   This function resets the ADCD module by setting the ADCD bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the ADCD module.
  */
static inline void RCC_resetAdcdModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCDRST_M);
}

/**
  * \brief  Release the reset of the ADCD module.
  * \note   This function releases the reset of the ADCD module by clearing the ADCD bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the ADCD module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcdModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCDRST_M);
}

/**
  * \brief  Reset the ADCC module.
  * \note   This function resets the ADCC module by setting the ADCC bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the ADCC module.
  */
static inline void RCC_resetAdccModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCCRST_M);
}

/**
  * \brief  Release the reset of the ADCC module.
  * \note   This function releases the reset of the ADCC module by clearing the ADCC bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the ADCC module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdccModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCCRST_M);
}

/**
  * \brief  Reset the ADCB module.
  * \note   This function resets the ADCB module by setting the ADCB bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the ADCB module.
  */
static inline void RCC_resetAdcbModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCBRST_M);
}

/**
  * \brief  Release the reset of the ADCB module.
  * \note   This function releases the reset of the ADCB module by clearing the ADCB bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the ADCB module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcbModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCBRST_M);
}

/**
  * \brief  Reset the ADCA module.
  * \note   This function resets the ADCA module by setting the ADCA bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the ADCA module.
  */
static inline void RCC_resetAdcaModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCARST_M);
}

/**
  * \brief  Release the reset of the ADCA module.
  * \note   This function releases the reset of the ADCA module by clearing the ADCA bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the ADCA module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcaModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_ADCARST_M);
}

/**
  * \brief  Reset the SDFM4 module.
  * \note   This function resets the SDFM4 module by setting the SDFM4 bit in the
  *         RCC APB Reset Register 4 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the SDFM4 module.
  */
static inline void RCC_resetSdfm4Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM4RST_M);
}

/**
  * \brief  Release the reset of the SDFM4 module.
  * \note   This function releases the reset of the SDFM4 module by clearing the SDFM4 bit in the
  *         RCC APB Reset Register 4 (RCC->APBRST2).
  *         Clearing this bit allows the SDFM4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSdfm4Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM4RST_M);
}

/**
  * \brief  Reset the SDFM3 module.
  * \note   This function resets the SDFM3 module by setting the SDFM3 bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the SDFM3 module.
  */
static inline void RCC_resetSdfm3Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM3RST_M);
}

/**
  * \brief  Release the reset of the SDFM3 module.
  * \note   This function releases the reset of the SDFM3 module by clearing the SDFM3 bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST2).
  *         Clearing this bit allows the SDFM3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSdfm3Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM3RST_M);
}

/**
  * \brief  Reset the SDFM2 module.
  * \note   This function resets the SDFM2 module by setting the SDFM2 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the SDFM2 module.
  */
static inline void RCC_resetSdfm2Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM2RST_M);
}

/**
  * \brief  Release the reset of the SDFM2 module.
  * \note   This function releases the reset of the SDFM2 module by clearing the SDFM2 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the SDFM2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSdfm2Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM2RST_M);
}

/**
  * \brief  Reset the SDFM1 module.
  * \note   This function resets the SDFM1 module by setting the SDFM1 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Setting this bit allows for a reset of the SDFM1 module.
  */
static inline void RCC_resetSdfm1Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM1RST_M);
}

/**
  * \brief  Release the reset of the SDFM1 module.
  * \note   This function releases the reset of the SDFM1 module by clearing the SDFM1 bit in the
  *         RCC APB Reset Register 2 (RCC->APBRST2).
  *         Clearing this bit allows the SDFM1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSdfm1Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APBRST2_SDFM1RST_M);
}

/**
  * \brief  Reset the Analogss module.
  * \note   This function resets the Analogss module by setting the ANALOGSS bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST3).
  *         Setting this bit allows for a reset of the Analogss module.
  */
static inline void RCC_resetAnalogssModule (void)
{
    SET_BIT(RCC->APBRST3.WORDVAL, RCC_APBRST3_ANALOGSS_M);
}

/**
  * \brief  Release the reset of the Analogss module.
  * \note   This function releases the reset of the Analogss module by clearing the ANALOGSS bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST3).
  *         Clearing this bit allows the Analogss module to resume normal operation after a reset.
  */
static inline void RCC_releaseAnalogssModule (void)
{
    CLEAR_BIT(RCC->APBRST3.WORDVAL, RCC_APBRST3_ANALOGSS_M);
}

/**
  * \brief  Reset the DAC3 module.
  * \note   This function resets the DAC3 module by setting the DAC3 bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST3).
  *         Setting this bit allows for a reset of the DAC3 module.
  */
static inline void RCC_resetDac3Module (void)
{
    SET_BIT(RCC->APBRST3.WORDVAL, RCC_APBRST3_DAC3RST_M);
}

/**
  * \brief  Release the reset of the DAC3 module.
  * \note   This function releases the reset of the DAC3 module by clearing the DAC3 bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST3).
  *         Clearing this bit allows the DAC3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDac3Module (void)
{
    CLEAR_BIT(RCC->APBRST3.WORDVAL, RCC_APBRST3_DAC3RST_M);
}

/**
  * \brief  Reset the DAC1 module.
  * \note   This function resets the DAC1 module by setting the DAC1 bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST3).
  *         Setting this bit allows for a reset of the DAC1 module.
  */
static inline void RCC_resetDac1Module (void)
{
    SET_BIT(RCC->APBRST3.WORDVAL, RCC_APBRST3_DAC1RST_M);
}

/**
  * \brief  Release the reset of the DAC1 module.
  * \note   This function releases the reset of the DAC1 module by clearing the DAC1 bit in the
  *         RCC APB Reset Register 3 (RCC->APBRST3).
  *         Clearing this bit allows the DAC1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDac1Module (void)
{
    CLEAR_BIT(RCC->APBRST3.WORDVAL, RCC_APBRST3_DAC1RST_M);
}

/**
  * \brief  Reset the DCC1 module.
  * \note   This function resets the DCC1 module by setting the DCC1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the DCC1 module.
  */
static inline void RCC_resetDcc1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_DCC1RST_M);
}

/**
  * \brief  Release the reset of the DCC1 module.
  * \note   This function releases the reset of the DCC1 module by clearing the DCC1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the DCC1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDcc1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_DCC1RST_M);
}

/**
  * \brief  Reset the EPG module.
  * \note   This function resets the EPG module by setting the EPG bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the EPG module.
  */
static inline void RCC_resetEpgModule (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_EPGRST_M);
}

/**
  * \brief  Release the reset of the EPG module.
  * \note   This function releases the reset of the EPG module by clearing the EPG bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the EPG module to resume normal operation after a reset.
  */
static inline void RCC_releaseEpgModule (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_EPGRST_M);
}

/**
  * \brief  Reset the PMBUS module.
  * \note   This function resets the PMBUS module by setting the PMBUS bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the PMBUS module.
  */
static inline void RCC_resetPmbusModule (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_PMBUSRST_M);
}

/**
  * \brief  Release the reset of the PMBUS module.
  * \note   This function releases the reset of the PMBUS module by clearing the PMBUS bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the PMBUS module to resume normal operation after a reset.
  */
static inline void RCC_releasePmbusModule (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_PMBUSRST_M);
}

/**
  * \brief  Reset the I2C2 module.
  * \note   This function resets the I2C2 module by setting the I2C2 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the I2C2 module.
  */
static inline void RCC_resetI2c2Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_I2C2RST_M);
}

/**
  * \brief  Release the reset of the I2C2 module.
  * \note   This function releases the reset of the I2C2 module by clearing the I2C2 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the I2C2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseI2c2Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_I2C2RST_M);
}

/**
  * \brief  Reset the I2C1 module.
  * \note   This function resets the I2C1 module by setting the I2C1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the I2C1 module.
  */
static inline void RCC_resetI2c1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_I2C1RST_M);
}

/**
  * \brief  Release the reset of the I2C1 module.
  * \note   This function releases the reset of the I2C1 module by clearing the I2C1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the I2C1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseI2c1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_I2C1RST_M);
}

/**
  * \brief  Reset the SPI4 module.
  * \note   This function resets the SPI4 module by setting the SPI4 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the SPI4 module.
  */
static inline void RCC_resetSpi4Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI4RST_M);
}

/**
  * \brief  Release the reset of the SPI4 module.
  * \note   This function releases the reset of the SPI4 module by clearing the SPI4 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the SPI4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSpi4Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI4RST_M);
}

/**
  * \brief  Reset the SPI3 module.
  * \note   This function resets the SPI3 module by setting the SPI3 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the SPI3 module.
  */
static inline void RCC_resetSpi3Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI3RST_M);
}

/**
  * \brief  Release the reset of the SPI3 module.
  * \note   This function releases the reset of the SPI3 module by clearing the SPI3 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the SPI3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSpi3Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI3RST_M);
}

/**
  * \brief  Reset the SPI2 module.
  * \note   This function resets the SPI2 module by setting the SPI2 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the SPI2 module.
  */
static inline void RCC_resetSpi2Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI2RST_M);
}

/**
  * \brief  Release the reset of the SPI2 module.
  * \note   This function releases the reset of the SPI2 module by clearing the SPI2 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the SPI2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSpi2Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI2RST_M);
}

/**
  * \brief  Reset the SPI1 module.
  * \note   This function resets the SPI1 module by setting the SPI1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the SPI1 module.
  */
static inline void RCC_resetSpi1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI1RST_M);
}

/**
  * \brief  Release the reset of the SPI1 module.
  * \note   This function releases the reset of the SPI1 module by clearing the SPI1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the SPI1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseSpi1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_SPI1RST_M);
}

/**
  * \brief  Reset the UART4 module.
  * \note   This function resets the UART4 module by setting the UART4 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the UART4 module.
  */
static inline void RCC_resetUart4Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART4RST_M);
}

/**
  * \brief  Release the reset of the UART4 module.
  * \note   This function releases the reset of the UART4 module by clearing the UART4 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the UART4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseUart4Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART4RST_M);
}

/**
  * \brief  Reset the UART3 module.
  * \note   This function resets the UART3 module by setting the UART3 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the UART3 module.
  */
static inline void RCC_resetUart3Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART3RST_M);
}

/**
  * \brief  Release the reset of the UART3 module.
  * \note   This function releases the reset of the UART3 module by clearing the UART3 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the UART3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseUart3Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART3RST_M);
}

/**
  * \brief  Reset the UART2 module.
  * \note   This function resets the UART2 module by setting the UART2 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the UART2 module.
  */
static inline void RCC_resetUart2Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART2RST_M);
}

/**
  * \brief  Release the reset of the UART2 module.
  * \note   This function releases the reset of the UART2 module by clearing the UART2 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the UART2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseUart2Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART2RST_M);
}

/**
  * \brief  Reset the UART1 module.
  * \note   This function resets the UART1 module by setting the UART1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Setting this bit allows for a reset of the UART1 module.
  */
static inline void RCC_resetUart1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART1RST_M);
}

/**
  * \brief  Release the reset of the UART1 module.
  * \note   This function releases the reset of the UART1 module by clearing the UART1 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST5).
  *         Clearing this bit allows the UART1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseUart1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APBRST5_UART1RST_M);
}

/**
  * \brief  Reset the DCC3 module.
  * \note   This function resets the DCC3 module by setting the DCC3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the DCC3 module.
  */
static inline void RCC_resetDcc3Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_DCC3RST_M);
}

/**
  * \brief  Release the reset of the DCC3 module.
  * \note   This function releases the reset of the DCC3 module by clearing the DCC3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the DCC3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDcc3Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_DCC3RST_M);
}

/**
  * \brief  Reset the DCC2 module.
  * \note   This function resets the DCC2 module by setting the DCC2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the DCC2 module.
  */
static inline void RCC_resetDcc2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_DCC2RST_M);
}

/**
  * \brief  Release the reset of the DCC2 module.
  * \note   This function releases the reset of the DCC2 module by clearing the DCC2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the DCC2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseDcc2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_DCC2RST_M);
}

/**
  * \brief  Reset the BTIM2 module.
  * \note   This function resets the BTIM2 module by setting the BTIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the BTIM2 module.
  */
static inline void RCC_resetBtim2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_BTIM2RST_M);
}

/**
  * \brief  Release the reset of the BTIM2 module.
  * \note   This function releases the reset of the BTIM2 module by clearing the BTIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the BTIM2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseBtim2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_BTIM2RST_M);
}

/**
  * \brief  Reset the BTIM1 module.
  * \note   This function resets the BTIM1 module by setting the BTIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the BTIM1 module.
  */
static inline void RCC_resetBtim1Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_BTIM1RST_M);
}

/**
  * \brief  Release the reset of the BTIM1 module.
  * \note   This function releases the reset of the BTIM1 module by clearing the BTIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the BTIM1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseBtim1Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_BTIM1RST_M);
}

/**
  * \brief  Reset the CPU2STIM3 module.
  * \note   This function resets the CPU2STIM3 module by setting the CPU2STIM3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CPU2STIM3 module.
  */
static inline void RCC_resetCpu2Stim3Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU2STIM3RST_M);
}

/**
  * \brief  Release the reset of the CPU2STIM3 module.
  * \note   This function releases the reset of the STIM6 module by clearing the CPU2STIM3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CPU2STIM3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu2Stim3Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU2STIM3RST_M);
}

/**
  * \brief  Reset the CPU2STIM2 module.
  * \note   This function resets the CPU2STIM2 module by setting the CPU2STIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CPU2STIM2 module.
  */
static inline void RCC_resetCpu2Stim2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU2STIM2RST_M);
}

/**
  * \brief  Release the reset of the CPU2STIM2 module.
  * \note   This function releases the reset of the STIM5 module by clearing the CPU2STIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CPU2STIM2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu2Stim2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU2STIM2RST_M);
}

/**
  * \brief  Reset the CPU2STIM1 module.
  * \note   This function resets the CPU2STIM1 module by setting the CPU2STIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CPU2STIM1 module.
  */
static inline void RCC_resetCpu2Stim1Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU2STIM1RST_M);
}

/**
  * \brief  Release the reset of the CPU2STIM1 module.
  * \note   This function releases the reset of the CPU2STIM1 module by clearing the CPU2STIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CPU2STIM1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu2Stim1Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU2STIM1RST_M);
}

/**
  * \brief  Reset the CPU1STIM3 module.
  * \note   This function resets the CPU1STIM3 module by setting the CPU1STIM3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CPU1STIM3 module.
  */
static inline void RCC_resetCpu1Stim3Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU1STIM3RST_M);
}

/**
  * \brief  Release the reset of the CPU1STIM3 module.
  * \note   This function releases the reset of the CPU1STIM3 module by clearing the CPU1STIM3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CPU1STIM3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu1Stim3Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU1STIM3RST_M);
}

/**
  * \brief  Reset the CPU1STIM2 module.
  * \note   This function resets the CPU1STIM2 module by setting the CPU1STIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CPU1STIM2 module.
  */
static inline void RCC_resetCpu1Stim2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU1STIM2RST_M);
}

/**
  * \brief  Release the reset of the CPU1STIM2 module.
  * \note   This function releases the reset of the CPU1STIM2 module by clearing the CPU1STIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CPU1STIM2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu1Stim2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU1STIM2RST_M);
}

/**
  * \brief  Reset the CPU1STIM1 module.
  * \note   This function resets the CPU1STIM1 module by setting the CPU1STIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CPU1STIM1 module.
  */
static inline void RCC_resetCpu1Stim1Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU1STIM1RST_M);
}

/**
  * \brief  Release the reset of the CPU1STIM1 module.
  * \note   This function releases the reset of the CPU1STIM1 module by clearing the CPU1STIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CPU1STIM1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseCpu1Stim1Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CPU1STIM1RST_M);
}

/**
  * \brief  Reset the CLB6 module.
  * \note   This function resets the CLB6 module by setting the CLB6 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CLB6 module.
  */
static inline void RCC_resetClb6Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB6RST_M);
}

/**
  * \brief  Release the reset of the CLB6 module.
  * \note   This function releases the reset of the CLB6 module by clearing the CLB6 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CLB6 module to resume normal operation after a reset.
  */
static inline void RCC_releaseClb6Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB6RST_M);
}

/**
  * \brief  Reset the CLB5 module.
  * \note   This function resets the CLB5 module by setting the CLB5 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CLB5 module.
  */
static inline void RCC_resetClb5Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB5RST_M);
}

/**
  * \brief  Release the reset of the CLB5 module.
  * \note   This function releases the reset of the CLB5 module by clearing the CLB5 bit in the
  *         RCC APB Reset Register 5 (RCC->APBRST6).
  *         Clearing this bit allows the CLB5 module to resume normal operation after a reset.
  */
static inline void RCC_releaseClb5Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB5RST_M);
}

/**
  * \brief  Reset the CLB4 module.
  * \note   This function resets the CLB4 module by setting the CLB4 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CLB4 module.
  */
static inline void RCC_resetClb4Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB4RST_M);
}

/**
  * \brief  Release the reset of the CLB4 module.
  * \note   This function releases the reset of the CLB4 module by clearing the CLB4 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CLB4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseClb4Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB4RST_M);
}

/**
  * \brief  Reset the CLB3 module.
  * \note   This function resets the CLB3 module by setting the CLB3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CLB3 module.
  */
static inline void RCC_resetClb3Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB3RST_M);
}

/**
  * \brief  Release the reset of the CLB3 module.
  * \note   This function releases the reset of the CLB3 module by clearing the CLB3 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CLB3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseClb3Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB3RST_M);
}

/**
  * \brief  Reset the CLB2 module.
  * \note   This function resets the CLB2 module by setting the CLB2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CLB2 module.
  */
static inline void RCC_resetClb2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB2RST_M);
}

/**
  * \brief  Release the reset of the CLB2 module.
  * \note   This function releases the reset of the CLB2 module by clearing the CLB2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CLB2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseClb2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB2RST_M);
}

/**
  * \brief  Reset the CLB1 module.
  * \note   This function resets the CLB1 module by setting the CLB1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the CLB1 module.
  */
static inline void RCC_resetClb1Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB1RST_M);
}

/**
  * \brief  Release the reset of the CLB1 module.
  * \note   This function releases the reset of the CLB1 module by clearing the CLB1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the CLB1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseClb1Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_CLB1RST_M);
}

/**
  * \brief  Reset the TIM2 module.
  * \note   This function resets the TIM2 module by setting the TIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the TIM2 module.
  */
static inline void RCC_resetTim2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_TIM2RST_M);
}

/**
  * \brief  Release the reset of the TIM2 module.
  * \note   This function releases the reset of the TIM2 module by clearing the TIM2 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the TIM2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseTim2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_TIM2RST_M);
}

/**
  * \brief  Reset the TIM1 module.
  * \note   This function resets the TIM1 module by setting the TIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Setting this bit allows for a reset of the TIM1 module.
  */
static inline void RCC_resetTim1Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_TIM1RST_M);
}

/**
  * \brief  Release the reset of the TIM1 module.
  * \note   This function releases the reset of the TIM1 module by clearing the TIM1 bit in the
  *         RCC APB Reset Register 6 (RCC->APBRST6).
  *         Clearing this bit allows the TIM1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseTim1Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APBRST6_TIM1RST_M);
}

/**
  * \brief  Reset the ADCAGG2 module.
  * \note   This function resets the ADCAGG2 module by setting the ADCAGG2 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCAGG2 module.
  */
static inline void RCC_resetAdcagg2Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCAGG2RST_M);
}

/**
  * \brief  Release the reset of the ADCAGG2 module.
  * \note   This function releases the reset of the ADCAGG2 module by clearing the ADCAGG2 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCAGG2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcagg2Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCAGG2RST_M);
}

/**
  * \brief  Reset the ADCAGG1 module.
  * \note   This function resets the ADCAGG1 module by setting the ADCAGG1 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCAGG1 module.
  */
static inline void RCC_resetAdcagg1Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCAGG1RST_M);
}

/**
  * \brief  Release the reset of the ADCAGG1 module.
  * \note   This function releases the reset of the ADCAGG1 module by clearing the ADCAGG1 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCAGG1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcagg1Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCAGG1RST_M);
}

/**
  * \brief  Reset the ADCCHK8 module.
  * \note   This function resets the ADCCHK8 module by setting the ADCCHK8 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK8 module.
  */
static inline void RCC_resetAdcchk8Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK8RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK8 module.
  * \note   This function releases the reset of the ADCCHK8 module by clearing the ADCCHK8 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK8 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk8Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK8RST_M);
}

/**
  * \brief  Reset the ADCCHK7 module.
  * \note   This function resets the ADCCHK7 module by setting the ADCCHK7 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK7 module.
  */
static inline void RCC_resetAdcchk7Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK7RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK7 module.
  * \note   This function releases the reset of the ADCCHK7 module by clearing the ADCCHK7 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK7 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk7Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK7RST_M);
}

/**
  * \brief  Reset the ADCCHK6 module.
  * \note   This function resets the ADCCHK6 module by setting the ADCCHK6 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK6 module.
  */
static inline void RCC_resetAdcchk6Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK6RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK6 module.
  * \note   This function releases the reset of the ADCCHK6 module by clearing the ADCCHK6 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK6 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk6Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK6RST_M);
}

/**
  * \brief  Reset the ADCCHK5 module.
  * \note   This function resets the ADCCHK5 module by setting the ADCCHK5 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK5 module.
  */
static inline void RCC_resetAdcchk5Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK5RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK5 module.
  * \note   This function releases the reset of the ADCCHK5 module by clearing the ADCCHK5 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK5 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk5Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK5RST_M);
}

/**
  * \brief  Reset the ADCCHK4 module.
  * \note   This function resets the ADCCHK4 module by setting the ADCCHK4 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK4 module.
  */
static inline void RCC_resetAdcchk4Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK4RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK4 module.
  * \note   This function releases the reset of the ADCCHK4 module by clearing the ADCCHK4 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK4 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk4Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK4RST_M);
}

/**
  * \brief  Reset the ADCCHK3 module.
  * \note   This function resets the ADCCHK3 module by setting the ADCCHK3 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK3 module.
  */
static inline void RCC_resetAdcchk3Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK3RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK3 module.
  * \note   This function releases the reset of the ADCCHK3 module by clearing the ADCCHK3 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK3 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk3Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK3RST_M);
}

/**
  * \brief  Reset the ADCCHK2 module.
  * \note   This function resets the ADCCHK2 module by setting the ADCCHK2 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK2 module.
  */
static inline void RCC_resetAdcchk2Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK2RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK2 module.
  * \note   This function releases the reset of the ADCCHK2 module by clearing the ADCCHK2 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK2 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk2Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK2RST_M);
}

/**
  * \brief  Reset the ADCCHK1 module.
  * \note   This function resets the ADCCHK1 module by setting the ADCCHK1 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the ADCCHK1 module.
  */
static inline void RCC_resetAdcchk1Module (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK1RST_M);
}

/**
  * \brief  Release the reset of the ADCCHK1 module.
  * \note   This function releases the reset of the ADCCHK1 module by clearing the ADCCHK1 bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the ADCCHK1 module to resume normal operation after a reset.
  */
static inline void RCC_releaseAdcchk1Module (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_ADCCHK1RST_M);
}

/**
  * \brief  Reset the LPTIM module.
  * \note   This function resets the LPTIM module by setting the LPTIM bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the LPTIM module.
  */
static inline void RCC_resetLptimModule (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_LPTIMRST_M);
}

/**
  * \brief  Release the reset of the LPTIM module.
  * \note   This function releases the reset of the LPTIM module by clearing the LPTIM bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the LPTIM module to resume normal operation after a reset.
  */
static inline void RCC_releaseLptimModule (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_LPTIMRST_M);
}

/**
  * \brief  Reset the PWR module.
  * \note   This function resets the PWR module by setting the PWR bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Setting this bit allows for a reset of the PWR module.
  */
static inline void RCC_resetPwrModule (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_PWRRST_M);
}

/**
  * \brief  Release the reset of the PWR module.
  * \note   This function releases the reset of the PWR module by clearing the PWR bit in the
  *         RCC APB Reset Register 8 (RCC->APBRST8).
  *         Clearing this bit allows the PWR module to resume normal operation after a reset.
  */
static inline void RCC_releasePwrModule (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APBRST8_PWRRST_M);
}

/**
  * \brief  Enable the UPP clock.
  * \note   This function enables the clock for the UPP module by setting the UPP bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the UPP module to operate.
  */
static inline void RCC_enableUppClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_UPPEN_M);
}

/**
  * \brief  Disable the UPP clock.
  * \note   This function disables the clock for the UPP module by clearing the UPP bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the UPP module from operating.
  */
static inline void RCC_disableUppClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_UPPEN_M);
}

/**
  * \brief  Enable the EMIF clock.
  * \note   This function enables the clock for the EMIF module by setting the EMIF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the EMIF module to operate.
  */
static inline void RCC_enableEmifClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EMIFEN_M);
}

/**
  * \brief  Disable the EMIF clock.
  * \note   This function disables the clock for the EMIF module by clearing the EMIF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the EMIF module from operating.
  */
static inline void RCC_disableEmifClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EMIFEN_M);
}

/**
  * \brief  Enable the SEMA clock.
  * \note   This function enables the clock for the SEMA module by setting the SEMA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the SEMA module to operate.
  */
static inline void RCC_enableSemaClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_SEMAEN_M);
}

/**
  * \brief  Disable the SEMA clock.
  * \note   This function disables the clock for the SEMA module by clearing the SEMA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the SEMA module from operating.
  */
static inline void RCC_disableSemaClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_SEMAEN_M);
}

/**
  * \brief  Enable the MU clock.
  * \note   This function enables the clock for the MU module by setting the MU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the MU module to operate.
  */
static inline void RCC_enableMuClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_MUEN_M);
}

/**
  * \brief  Disable the MU clock.
  * \note   This function disables the clock for the MU module by clearing the MU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the MU module from operating.
  */
static inline void RCC_disableMuClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_MUEN_M);
}

/**
  * \brief  Enable the GPIOH clock.
  * \note   This function enables the clock for the GPIOH module by setting the GPIOH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOH module to operate.
  */
static inline void RCC_enableGpiohClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOHEN_M);
}

/**
  * \brief  Disable the GPIOH clock.
  * \note   This function disables the clock for the GPIOH module by clearing the GPIOH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOH module from operating.
  */
static inline void RCC_disableGpiohClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOHEN_M);
}

/**
  * \brief  Enable the GPIOG clock.
  * \note   This function enables the clock for the GPIOG module by setting the GPIOG bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOG module to operate.
  */
static inline void RCC_enableGpiogClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOGEN_M);
}

/**
  * \brief  Disable the GPIOG clock.
  * \note   This function disables the clock for the GPIOG module by clearing the GPIOG bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOG module from operating.
  */
static inline void RCC_disableGpiogClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOGEN_M);
}

/**
  * \brief  Enable the GPIOF clock.
  * \note   This function enables the clock for the GPIOF module by setting the GPIOF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOF module to operate.
  */
static inline void RCC_enableGpiofClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOFEN_M);
}

/**
  * \brief  Disable the GPIOF clock.
  * \note   This function disables the clock for the GPIOF module by clearing the GPIOF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOF module from operating.
  */
static inline void RCC_disableGpiofClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOFEN_M);
}

/**
  * \brief  Enable the GPIOE clock.
  * \note   This function enables the clock for the GPIOE module by setting the GPIOE bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOE module to operate.
  */
static inline void RCC_enableGpioeClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOEEN_M);
}

/**
  * \brief  Disable the GPIOE clock.
  * \note   This function disables the clock for the GPIOE module by clearing the GPIOE bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOE module from operating.
  */
static inline void RCC_disableGpioeClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOEEN_M);
}

/**
  * \brief  Enable the GPIOD clock.
  * \note   This function enables the clock for the GPIOD module by setting the GPIOD bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOD module to operate.
  */
static inline void RCC_enableGpiodClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIODEN_M);
}

/**
  * \brief  Disable the GPIOD clock.
  * \note   This function disables the clock for the GPIOD module by clearing the GPIOD bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOD module from operating.
  */
static inline void RCC_disableGpiodClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIODEN_M);
}

/**
  * \brief  Enable the GPIOC clock.
  * \note   This function enables the clock for the GPIOC module by setting the GPIOC bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOC module to operate.
  */
static inline void RCC_enableGpiocClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOCEN_M);
}

/**
  * \brief  Disable the GPIOC clock.
  * \note   This function disables the clock for the GPIOC module by clearing the GPIOC bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOC module from operating.
  */
static inline void RCC_disableGpiocClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOCEN_M);
}

/**
  * \brief  Enable the GPIOB clock.
  * \note   This function enables the clock for the GPIOB module by setting the GPIOB bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOB module to operate.
  */
static inline void RCC_enableGpiobClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOBEN_M);
}

/**
  * \brief  Disable the GPIOB clock.
  * \note   This function disables the clock for the GPIOB module by clearing the GPIOB bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOB module from operating.
  */
static inline void RCC_disableGpiobClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOBEN_M);
}

/**
  * \brief  Enable the GPIOA clock.
  * \note   This function enables the clock for the GPIOA module by setting the GPIOA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the GPIOA module to operate.
  */
static inline void RCC_enableGpioaClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOAEN_M);
}

/**
  * \brief  Disable the GPIOA clock.
  * \note   This function disables the clock for the GPIOA module by clearing the GPIOA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the GPIOA module from operating.
  */
static inline void RCC_disableGpioaClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_GPIOAEN_M);
}

/**
  * \brief  Enable the EMATH clock.
  * \note   This function enables the clock for the EMATH module by setting the EMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the EMATH module to operate.
  */
static inline void RCC_enableEmathClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EMATHEN_M);
}

/**
  * \brief  Disable the EMATH clock.
  * \note   This function disables the clock for the EMATH module by clearing the EMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the EMATH module from operating.
  */
static inline void RCC_disableEmathClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EMATHEN_M);
}

/**
  * \brief  Enable the QSPI clock.
  * \note   This function enables the clock for the QSPI module by setting the QSPI bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the QSPI module to operate.
  */
static inline void RCC_enableQspiClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_QSPIEN_M);
}

/**
  * \brief  Disable the QSPI clock.
  * \note   This function disables the clock for the QSPI module by clearing the QSPI bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the QSPI module from operating.
  */
static inline void RCC_disableQspiClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_QSPIEN_M);
}

/**
  * \brief  Enable the CPUxMMATH clock.
  * \note   This function enables the clock for the CPUxMMATH module by setting the CPUxMMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the CPUxMMATH module to operate.
  */
static inline void RCC_enableCpuxMmathClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_CPUXMMATHEN_M);
}

/**
  * \brief  Disable the CPUxMMATH clock.
  * \note   This function disables the clock for the CPUxMMATH module by clearing the CPUxMMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the CPUxMMATH module from operating.
  */
static inline void RCC_disableCpuxMmathClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_CPUXMMATHEN_M);
}

/**
  * \brief  Enable the EDMA2 clock.
  * \note   This function enables the clock for the EDMA2 module by setting the EDMA2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the EDMA2 module to operate.
  */
static inline void RCC_enableEdma2Clock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EDMA2EN_M);
}

/**
  * \brief  Disable the EDMA2 clock.
  * \note   This function disables the clock for the EDMA2 module by clearing the EDMA2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the EDMA2 module from operating.
  */
static inline void RCC_disableEdma2Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EDMA2EN_M);
}

/**
  * \brief  Enable the EDMA1 clock.
  * \note   This function enables the clock for the EDMA1 module by setting the EDMA1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the EDMA1 module to operate.
  */
static inline void RCC_enableEdma1Clock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EDMA1EN_M);
}

/**
  * \brief  Disable the EDMA1 clock.
  * \note   This function disables the clock for the EDMA1 module by clearing the EDMA1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the EDMA1 module from operating.
  */
static inline void RCC_disableEdma1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_EDMA1EN_M);
}

/**
  * \brief  Enable the DMAMUX2 clock.
  * \note   This function enables the clock for the DMAMUX2 module by setting the DMAMUX2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the DMAMUX2 module to operate.
  */
static inline void RCC_enableDmamux2Clock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_DMAMUX2EN_M);
}

/**
  * \brief  Disable the DMAMUX2 clock.
  * \note   This function disables the clock for the DMAMUX2 module by clearing the DMAMUX2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the DMAMUX2 module from operating.
  */
static inline void RCC_disableDmamux2Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_DMAMUX2EN_M);
}

/**
  * \brief  Enable the DMAMUX1 clock.
  * \note   This function enables the clock for the DMAMUX1 module by setting the DMAMUX1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the DMAMUX1 module to operate.
  */
static inline void RCC_enableDmamux1Clock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_DMAMUX1EN_M);
}

/**
  * \brief  Disable the DMAMUX1 clock.
  * \note   This function disables the clock for the DMAMUX1 module by clearing the DMAMUX1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the DMAMUX1 module from operating.
  */
static inline void RCC_disableDmamux1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_DMAMUX1EN_M);
}

/**
  * \brief  Enable the SMPU clock.
  * \note   This function enables the clock for the SMPU module by setting the SMPU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the SMPU module to operate.
  */
static inline void RCC_enableSmpuClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_SMPUEN_M);
}

/**
  * \brief  Disable the SMPU clock.
  * \note   This function disables the clock for the SMPU module by clearing the SMPU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the SMPU module from operating.
  */
static inline void RCC_disableSmpuClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_SMPUEN_M);
}

/**
  * \brief  Enable the FMU clock.
  * \note   This function enables the clock for the FMU module by setting the FMU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Setting this bit allows the FMU module to operate.
  */
static inline void RCC_enableFmuClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_FMUEN_M);
}

/**
  * \brief  Disable the FMU clock.
  * \note   This function disables the clock for the FMU module by clearing the FMU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
  *         Clearing this bit stops the FMU module from operating.
  */
static inline void RCC_disableFmuClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_HCLKEN1_FMUEN_M);
}

/**
  * \brief  Enable the CANFD2 clock.
  * \note   This function enables the clock for the Canfd2 module by setting the CANFD2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the CANFD2 module to operate.
  */
static inline void RCC_enableCanfd2Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CANFD2EN_M);
}

/**
  * \brief  Disable the CANFD2 clock.
  * \note   This function disables the clock for the Canfd2 module by clearing the CANFD2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the CANFD2 module from operating.
  */
static inline void RCC_disableCanfd2Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CANFD2EN_M);
}

/**
  * \brief  Enable the CANFD1 clock.
  * \note   This function enables the clock for the CANFD1 module by setting the CANFD1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the CANFD1 module to operate.
  */
static inline void RCC_enableCanfd1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CANFD1EN_M);
}

/**
  * \brief  Disable the CANFD1 clock.
  * \note   This function disables the clock for the CANFD1 module by clearing the CANFD1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the CANFD1 module from operating.
  */
static inline void RCC_disableCanfd1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CANFD1EN_M);
}

/**
  * \brief  Enable the CAN1 clock.
  * \note   This function enables the clock for the CAN1 module by setting the CAN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the CAN1 module to operate.
  */
static inline void RCC_enableCan1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CAN1EN_M);
}

/**
  * \brief  Disable the CAN1 clock.
  * \note   This function disables the clock for the CAN1 module by clearing the CAN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the CAN1 module from operating.
  */
static inline void RCC_disableCan1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CAN1EN_M);
}

/**
  * \brief  Enable the LIN2 clock.
  * \note   This function enables the clock for the LIN2 module by setting the LIN2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the LIN2 module to operate.
  */
static inline void RCC_enableLin2Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_LIN2EN_M);
}

/**
  * \brief  Disable the LIN2 clock.
  * \note   This function disables the clock for the LIN2 module by clearing the LIN2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the LIN2 module from operating.
  */
static inline void RCC_disableLin2Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_LIN2EN_M);
}

/**
  * \brief  Enable the LIN1 clock.
  * \note   This function enables the clock for the LIN1 module by setting the LIN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the LIN1 module to operate.
  */
static inline void RCC_enableLin1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_LIN1EN_M);
}

/**
  * \brief  Disable the LIN1 clock.
  * \note   This function disables the clock for the LIN1 module by clearing the LIN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the LIN1 module from operating.
  */
static inline void RCC_disableLin1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_LIN1EN_M);
}

/**
  * \brief  Enable the BGCRC2 clock.
  * \note   This function enables the clock for the BGCRC2 module by setting the BGCRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the BGCRC2 module to operate.
  */
static inline void RCC_enableBgcrc2Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_BGCRC2EN_M);
}

/**
  * \brief  Disable the BGCRC2 clock.
  * \note   This function disables the clock for the BGCRC2 module by clearing the BGCRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the BGCRC2 module from operating.
  */
static inline void RCC_disableBgcrc2Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_BGCRC2EN_M);
}

/**
  * \brief  Enable the BGCRC1 clock.
  * \note   This function enables the clock for the BGCRC1 module by setting the BGCRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the BGCRC1 module to operate.
  */
static inline void RCC_enableBgcrc1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_BGCRC1EN_M);
}

/**
  * \brief  Disable the BGCRC1 clock.
  * \note   This function disables the clock for the BGCRC1 module by clearing the BGCRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the BGCRC1 module from operating.
  */
static inline void RCC_disableBgcrc1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_BGCRC1EN_M);
}

/**
  * \brief  Enable the CRC2 clock.
  * \note   This function enables the clock for the CRC2 module by setting the CRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the CRC2 module to operate.
  */
static inline void RCC_enableCrc2Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CRC2EN_M);
}

/**
  * \brief  Disable the CRC2 clock.
  * \note   This function disables the clock for the CRC2 module by clearing the CRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the CRC2 module from operating.
  */
static inline void RCC_disableCrc2Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CRC2EN_M);
}

/**
  * \brief  Enable the CRC1 clock.
  * \note   This function enables the clock for the CRC1 module by setting the CRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the CRC1 module to operate.
  */
static inline void RCC_enableCrc1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CRC1EN_M);
}

/**
  * \brief  Disable the CRC1 clock.
  * \note   This function disables the clock for the CRC1 module by clearing the CRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the CRC1 module from operating.
  */
static inline void RCC_disableCrc1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_CRC1EN_M);
}

/**
  * \brief  Enable the AESHASH clock.
  * \note   This function enables the clock for the AESHASH module by setting the AESHASH bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the AESHASH module to operate.
  */
static inline void RCC_enableAesHashClock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_AESHASHEN_M);
}

/**
  * \brief  Disable the AESHASH clock.
  * \note   This function disables the clock for the AESHASH module by clearing the AESHASH bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the AESHASH module from operating.
  */
static inline void RCC_disableAesHashClock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_AESHASHEN_M);
}

/**
  * \brief  Enable the TRNG clock.
  * \note   This function enables the clock for the TRNG module by setting the TRNG bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Setting this bit allows the TRNG module to operate.
  */
static inline void RCC_enableTrngClock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_TRNGEN_M);
}

/**
  * \brief  Disable the TRNG clock.
  * \note   This function disables the clock for the TRNG module by clearing the TRNG bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
  *         Clearing this bit stops the TRNG module from operating.
  */
static inline void RCC_disableTrngClock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_HCLKEN2_TRNGEN_M);
}

/**
  * \brief  Enable the EPWM18 clock.
  * \note   This function enables the clock for the EPWM18 module by setting the EPWM18 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM18 module to operate.
  */
static inline void RCC_enableEpwm18Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM18EN_M);
}

/**
  * \brief  Disable the EPWM18 clock.
  * \note   This function disables the clock for the EPWM18 module by clearing the EPWM18 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM18 module from operating.
  */
static inline void RCC_disableEpwm18Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM18EN_M);
}

/**
  * \brief  Enable the EPWM17 clock.
  * \note   This function enables the clock for the EPWM17 module by setting the EPWM17 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM17 module to operate.
  */
static inline void RCC_enableEpwm17Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM17EN_M);
}

/**
  * \brief  Disable the EPWM17 clock.
  * \note   This function disables the clock for the EPWM17 module by clearing the EPWM17 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM17 module from operating.
  */
static inline void RCC_disableEpwm17Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM17EN_M);
}

/**
  * \brief  Enable the EQEP6 clock.
  * \note   This function enables the clock for the EQEP6 module by setting the EQEP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EQEP6 module to operate.
  */
static inline void RCC_enableEqep6Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP6EN_M);
}

/**
  * \brief  Disable the EQEP6 clock.
  * \note   This function disables the clock for the EQEP6 module by clearing the EQEP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EQEP6 module from operating.
  */
static inline void RCC_disableEqep6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP6EN_M);
}

/**
  * \brief  Enable the EQEP5 clock.
  * \note   This function enables the clock for the EQEP5 module by setting the EQEP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EQEP5 module to operate.
  */
static inline void RCC_enableEqep5Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP5EN_M);
}

/**
  * \brief  Disable the EQEP5 clock.
  * \note   This function disables the clock for the EQEP5 module by clearing the EQEP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EQEP5 module from operating.
  */
static inline void RCC_disableEqep5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP5EN_M);
}

/**
  * \brief  Enable the EQEP4 clock.
  * \note   This function enables the clock for the EQEP4 module by setting the EQEP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EQEP4 module to operate.
  */
static inline void RCC_enableEqep4Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP4EN_M);
}

/**
  * \brief  Disable the EQEP4 clock.
  * \note   This function disables the clock for the EQEP4 module by clearing the EQEP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EQEP4 module from operating.
  */
static inline void RCC_disableEqep4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP4EN_M);
}

/**
  * \brief  Enable the EQEP3 clock.
  * \note   This function enables the clock for the EQEP3 module by setting the EQEP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EQEP3 module to operate.
  */
static inline void RCC_enableEqep3Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP3EN_M);
}

/**
  * \brief  Disable the EQEP3 clock.
  * \note   This function disables the clock for the EQEP3 module by clearing the EQEP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EQEP3 module from operating.
  */
static inline void RCC_disableEqep3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP3EN_M);
}

/**
  * \brief  Enable the EQEP2 clock.
  * \note   This function enables the clock for the EQEP2 module by setting the EQEP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EQEP2 module to operate.
  */
static inline void RCC_enableEqep2Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP2EN_M);
}

/**
  * \brief  Disable the EQEP2 clock.
  * \note   This function disables the clock for the EQEP2 module by clearing the EQEP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EQEP2 module from operating.
  */
static inline void RCC_disableEqep2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP2EN_M);
}

/**
  * \brief  Enable the EQEP1 clock.
  * \note   This function enables the clock for the EQEP1 module by setting the EQEP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EQEP1 module to operate.
  */
static inline void RCC_enableEqep1Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP1EN_M);
}

/**
  * \brief  Disable the EQEP1 clock.
  * \note   This function disables the clock for the EQEP1 module by clearing the EQEP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EQEP1 module from operating.
  */
static inline void RCC_disableEqep1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EQEP1EN_M);
}

/**
  * \brief  Enable the ECAP7 clock.
  * \note   This function enables the clock for the ECAP7 module by setting the ECAP7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP7 module to operate.
  */
static inline void RCC_enableEcap7Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP7EN_M);
}

/**
  * \brief  Disable the ECAP7 clock.
  * \note   This function disables the clock for the ECAP7 module by clearing the ECAP7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP7 module from operating.
  */
static inline void RCC_disableEcap7Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP7EN_M);
}

/**
  * \brief  Enable the ECAP6 clock.
  * \note   This function enables the clock for the ECAP6 module by setting the ECAP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP6 module to operate.
  */
static inline void RCC_enableEcap6Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP6EN_M);
}

/**
  * \brief  Disable the ECAP6 clock.
  * \note   This function disables the clock for the ECAP6 module by clearing the ECAP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP6 module from operating.
  */
static inline void RCC_disableEcap6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP6EN_M);
}

/**
  * \brief  Enable the ECAP5 clock.
  * \note   This function enables the clock for the ECAP5 module by setting the ECAP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP5 module to operate.
  */
static inline void RCC_enableEcap5Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP5EN_M);
}

/**
  * \brief  Disable the ECAP5 clock.
  * \note   This function disables the clock for the ECAP5 module by clearing the ECAP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP5 module from operating.
  */
static inline void RCC_disableEcap5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP5EN_M);
}

/**
  * \brief  Enable the ECAP4 clock.
  * \note   This function enables the clock for the ECAP4 module by setting the ECAP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP4 module to operate.
  */
static inline void RCC_enableEcap4Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP4EN_M);
}

/**
  * \brief  Disable the ECAP4 clock.
  * \note   This function disables the clock for the ECAP4 module by clearing the ECAP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP4 module from operating.
  */
static inline void RCC_disableEcap4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP4EN_M);
}

/**
  * \brief  Enable the ECAP3 clock.
  * \note   This function enables the clock for the ECAP3 module by setting the ECAP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP3 module to operate.
  */
static inline void RCC_enableEcap3Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP3EN_M);
}

/**
  * \brief  Disable the ECAP3 clock.
  * \note   This function disables the clock for the ECAP3 module by clearing the ECAP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP3 module from operating.
  */
static inline void RCC_disableEcap3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP3EN_M);
}

/**
  * \brief  Enable the ECAP2 clock.
  * \note   This function enables the clock for the ECAP2 module by setting the ECAP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP2 module to operate.
  */
static inline void RCC_enableEcap2Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP2EN_M);
}

/**
  * \brief  Disable the ECAP2 clock.
  * \note   This function disables the clock for the ECAP2 module by clearing the ECAP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP2 module from operating.
  */
static inline void RCC_disableEcap2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP2EN_M);
}

/**
  * \brief  Enable the ECAP1 clock.
  * \note   This function enables the clock for the ECAP1 module by setting the ECAP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the ECAP1 module to operate.
  */
static inline void RCC_enableEcap1Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP1EN_M);
}

/**
  * \brief  Disable the ECAP1 clock.
  * \note   This function disables the clock for the ECAP1 module by clearing the ECAP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the ECAP1 module from operating.
  */
static inline void RCC_disableEcap1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_ECAP1EN_M);
}

/**
  * \brief  Enable the EPWM16 clock.
  * \note   This function enables the clock for the EPWM16 module by setting the EPWM16 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM16 module to operate.
  */
static inline void RCC_enableEpwm16Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM16EN_M);
}

/**
  * \brief  Disable the EPWM16 clock.
  * \note   This function disables the clock for the EPWM16 module by clearing the EPWM16 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM16 module from operating.
  */
static inline void RCC_disableEpwm16Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM16EN_M);
}

/**
  * \brief  Enable the EPWM15 clock.
  * \note   This function enables the clock for the EPWM15 module by setting the EPWM15 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM15 module to operate.
  */
static inline void RCC_enableEpwm15Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM15EN_M);
}

/**
  * \brief  Disable the EPWM15 clock.
  * \note   This function disables the clock for the EPWM15 module by clearing the EPWM15 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM15 module from operating.
  */
static inline void RCC_disableEpwm15Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM15EN_M);
}

/**
  * \brief  Enable the EPWM14 clock.
  * \note   This function enables the clock for the EPWM14 module by setting the EPWM14 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM14 module to operate.
  */
static inline void RCC_enableEpwm14Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM14EN_M);
}

/**
  * \brief  Disable the EPWM14 clock.
  * \note   This function disables the clock for the EPWM14 module by clearing the EPWM14 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM14 module from operating.
  */
static inline void RCC_disableEpwm14Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM14EN_M);
}

/**
  * \brief  Enable the EPWM13 clock.
  * \note   This function enables the clock for the EPWM13 module by setting the EPWM13 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM13 module to operate.
  */
static inline void RCC_enableEpwm13Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM13EN_M);
}

/**
  * \brief  Disable the EPWM13 clock.
  * \note   This function disables the clock for the EPWM13 module by clearing the EPWM13 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM13 module from operating.
  */
static inline void RCC_disableEpwm13Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM13EN_M);
}

/**
  * \brief  Enable the EPWM12 clock.
  * \note   This function enables the clock for the EPWM12 module by setting the EPWM12 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM12 module to operate.
  */
static inline void RCC_enableEpwm12Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM12EN_M);
}

/**
  * \brief  Disable the EPWM12 clock.
  * \note   This function disables the clock for the EPWM12 module by clearing the EPWM12 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM12 module from operating.
  */
static inline void RCC_disableEpwm12Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM12EN_M);
}

/**
  * \brief  Enable the EPWM11 clock.
  * \note   This function enables the clock for the EPWM11 module by setting the EPWM11 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM11 module to operate.
  */
static inline void RCC_enableEpwm11Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM11EN_M);
}

/**
  * \brief  Disable the EPWM11 clock.
  * \note   This function disables the clock for the EPWM11 module by clearing the EPWM11 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM11 module from operating.
  */
static inline void RCC_disableEpwm11Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM11EN_M);
}

/**
  * \brief  Enable the EPWM10 clock.
  * \note   This function enables the clock for the EPWM10 module by setting the EPWM10 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM10 module to operate.
  */
static inline void RCC_enableEpwm10Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM10EN_M);
}

/**
  * \brief  Disable the EPWM10 clock.
  * \note   This function disables the clock for the EPWM10 module by clearing the EPWM10 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM10 module from operating.
  */
static inline void RCC_disableEpwm10Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM10EN_M);
}

/**
  * \brief  Enable the EPWM9 clock.
  * \note   This function enables the clock for the EPWM9 module by setting the EPWM9 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM9 module to operate.
  */
static inline void RCC_enableEPWM9Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM9EN_M);
}

/**
  * \brief  Disable the EPWM9 clock.
  * \note   This function disables the clock for the EPWM9 module by clearing the EPWM9 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM9 module from operating.
  */
static inline void RCC_disableEpwm9Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM9EN_M);
}

/**
  * \brief  Enable the EPWM8 clock.
  * \note   This function enables the clock for the EPWM8 module by setting the EPWM8 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM8 module to operate.
  */
static inline void RCC_enableEpwm8Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM8EN_M);
}

/**
  * \brief  Disable the EPWM8 clock.
  * \note   This function disables the clock for the EPWM8 module by clearing the EPWM8 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM8 module from operating.
  */
static inline void RCC_disableEpwm8Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM8EN_M);
}

/**
  * \brief  Enable the EPWM7 clock.
  * \note   This function enables the clock for the EPWM7 module by setting the EPWM7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM7 module to operate.
  */
static inline void RCC_enableEpwm7Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM7EN_M);
}

/**
  * \brief  Disable the EPWM7 clock.
  * \note   This function disables the clock for the EPWM7 module by clearing the EPWM7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM7 module from operating.
  */
static inline void RCC_disableEpwm7Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM7EN_M);
}

/**
  * \brief  Enable the EPWM6 clock.
  * \note   This function enables the clock for the EPWM6 module by setting the EPWM6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM6 module to operate.
  */
static inline void RCC_enableEpwm6Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM6EN_M);
}

/**
  * \brief  Disable the EPWM6 clock.
  * \note   This function disables the clock for the EPWM6 module by clearing the EPWM6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM6 module from operating.
  */
static inline void RCC_disableEpwm6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM6EN_M);
}

/**
  * \brief  Enable the EPWM5 clock.
  * \note   This function enables the clock for the EPWM5 module by setting the EPWM5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM5 module to operate.
  */
static inline void RCC_enableEpwm5Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM5EN_M);
}

/**
  * \brief  Disable the EPWM5 clock.
  * \note   This function disables the clock for the EPWM5 module by clearing the EPWMEPWM55EN bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM5 module from operating.
  */
static inline void RCC_disableEpwm5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM5EN_M);
}

/**
  * \brief  Enable the EPWM4 clock.
  * \note   This function enables the clock for the EPWM4 module by setting the EPWM4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM4 module to operate.
  */
static inline void RCC_enableEpwm4Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM4EN_M);
}

/**
  * \brief  Disable the EPWM4 clock.
  * \note   This function disables the clock for the EPWM4 module by clearing the EPWM4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM4 module from operating.
  */
static inline void RCC_disableEpwm4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM4EN_M);
}

/**
  * \brief  Enable the EPWM3 clock.
  * \note   This function enables the clock for the EPWM3 module by setting the EPWM3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM3 module to operate.
  */
static inline void RCC_enableEpwm3Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM3EN_M);
}

/**
  * \brief  Disable the EPWM3 clock.
  * \note   This function disables the clock for the EPWM3 module by clearing the EPWM3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM3 module from operating.
  */
static inline void RCC_disableEpwm3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM3EN_M);
}

/**
  * \brief  Enable the EPWM2 clock.
  * \note   This function enables the clock for the EPWM2 module by setting the EPWM2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM2 module to operate.
  */
static inline void RCC_enableEpwm2Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM2EN_M);
}

/**
  * \brief  Disable the EPWM2 clock.
  * \note   This function disables the clock for the EPWM2 module by clearing the EPWM2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM2 module from operating.
  */
static inline void RCC_disableEpwm2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM2EN_M);
}

/**
  * \brief  Enable the EPWM1 clock.
  * \note   This function enables the clock for the EPWM1 module by setting the EPWM1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Setting this bit allows the EPWM1 module to operate.
  */
static inline void RCC_enableEpwm1Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM1EN_M);
}

/**
  * \brief  Disable the EPWM1 clock.
  * \note   This function disables the clock for the EPWM1 module by clearing the EPWM1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
  *         Clearing this bit stops the EPWM1 module from operating.
  */
static inline void RCC_disableEpwm1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_PCLKEN1_EPWM1EN_M);
}

/**
  * \brief  Enable the CMPSS11 clock.
  * \note   This function enables the clock for the CMPSS11 module by setting the CMPSS11 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS11 module to operate.
  */
static inline void RCC_enableCmpss11Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS11EN_M);
}

/**
  * \brief  Disable the CMPSS11 clock.
  * \note   This function disables the clock for the CMPSS11 module by clearing the CMPSS11 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS11 module from operating.
  */
static inline void RCC_disableCmpss11Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS11EN_M);
}

/**
  * \brief  Enable the CMPSS10 clock.
  * \note   This function enables the clock for the CMPSS10 module by setting the CMPSS10 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS10 module to operate.
  */
static inline void RCC_enableCmpss10Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS10EN_M);
}

/**
  * \brief  Disable the CMPSS10 clock.
  * \note   This function disables the clock for the CMPSS10 module by clearing the CMPSS10 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS10 module from operating.
  */
static inline void RCC_disableCmpss10Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS10EN_M);
}

/**
  * \brief  Enable the CMPSS9 clock.
  * \note   This function enables the clock for the CMPSS9 module by setting the CMPSS9 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS9 module to operate.
  */
static inline void RCC_enableCmpss9Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS9EN_M);
}

/**
  * \brief  Disable the CMPSS9 clock.
  * \note   This function disables the clock for the CMPSS9 module by clearing the CMPSS9 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS9 module from operating.
  */
static inline void RCC_disableCmpss9Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS9EN_M);
}

/**
  * \brief  Enable the CMPSS8 clock.
  * \note   This function enables the clock for the CMPSS8 module by setting the CMPSS8 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS8 module to operate.
  */
static inline void RCC_enableCmpss8Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS8EN_M);
}

/**
  * \brief  Disable the CMPSS8 clock.
  * \note   This function disables the clock for the CMPSS8 module by clearing the CMPSS8 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS8 module from operating.
  */
static inline void RCC_disableCmpss8Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS8EN_M);
}

/**
  * \brief  Enable the CMPSS7 clock.
  * \note   This function enables the clock for the CMPSS7 module by setting the CMPSS7 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS7 module to operate.
  */
static inline void RCC_enableCmpss7Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS7EN_M);
}

/**
  * \brief  Disable the CMPSS7 clock.
  * \note   This function disables the clock for the CMPSS7 module by clearing the CMPSS7 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS7 module from operating.
  */
static inline void RCC_disableCmpss7Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS7EN_M);
}

/**
  * \brief  Enable the CMPSS6 clock.
  * \note   This function enables the clock for the CMPSS6 module by setting the CMPSS6 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS6 module to operate.
  */
static inline void RCC_enableCmpss6Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS6EN_M);
}

/**
  * \brief  Disable the CMPSS6 clock.
  * \note   This function disables the clock for the CMPSS6 module by clearing the CMPSS6 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS6 module from operating.
  */
static inline void RCC_disableCmpss6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS6EN_M);
}

/**
  * \brief  Enable the CMPSS5 clock.
  * \note   This function enables the clock for the CMPSS5 module by setting the CMPSS5 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS5 module to operate.
  */
static inline void RCC_enableCmpss5Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS5EN_M);
}

/**
  * \brief  Disable the CMPSS5 clock.
  * \note   This function disables the clock for the CMPSS5 module by clearing the CMPSS5 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS5 module from operating.
  */
static inline void RCC_disableCmpss5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS5EN_M);
}

/**
  * \brief  Enable the CMPSS4 clock.
  * \note   This function enables the clock for the CMPSS4 module by setting the CMPSS4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS4 module to operate.
  */
static inline void RCC_enableCmpss4Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS4EN_M);
}

/**
  * \brief  Disable the CMPSS4 clock.
  * \note   This function disables the clock for the CMPSS4 module by clearing the CMPSS4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS4 module from operating.
  */
static inline void RCC_disableCmpss4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS4EN_M);
}

/**
  * \brief  Enable the CMPSS3 clock.
  * \note   This function enables the clock for the CMPSS3 module by setting the CMPSS3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS3 module to operate.
  */
static inline void RCC_enableCmpss3Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS3EN_M);
}

/**
  * \brief  Disable the CMPSS3 clock.
  * \note   This function disables the clock for the CMPSS3 module by clearing the CMPSS3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS3 module from operating.
  */
static inline void RCC_disableCmpss3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS3EN_M);
}

/**
  * \brief  Enable the CMPSS2 clock.
  * \note   This function enables the clock for the CMPSS2 module by setting the CMPSS2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS2 module to operate.
  */
static inline void RCC_enableCmpss2Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS2EN_M);
}

/**
  * \brief  Disable the CMPSS2 clock.
  * \note   This function disables the clock for the CMPSS2 module by clearing the CMPSS2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS2 module from operating.
  */
static inline void RCC_disableCmpss2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS2EN_M);
}

/**
  * \brief  Enable the CMPSS1 clock.
  * \note   This function enables the clock for the CMPSS1 module by setting the CMPSS1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the CMPSS1 module to operate.
  */
static inline void RCC_enableCmpss1Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS1EN_M);
}

/**
  * \brief  Disable the CMPSS1 clock.
  * \note   This function disables the clock for the CMPSS1 module by clearing the CMPSS1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the CMPSS1 module from operating.
  */
static inline void RCC_disableCmpss1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_CMPSS1EN_M);
}

/**
  * \brief  Enable the XBAR clock.
  * \note   This function enables the clock for the XBAR module by setting the XBAR bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the XBAR module to operate.
  */
static inline void RCC_enableXbarClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_XBAREN_M);
}

/**
  * \brief  Disable the XBAR clock.
  * \note   This function disables the clock for the XBAR module by clearing the XBAR bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the XBAR module from operating.
  */
static inline void RCC_disableXbarClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_XBAREN_M);
}

/**
  * \brief  Enable the ADCD clock.
  * \note   This function enables the clock for the ADCD module by setting the ADCD bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the ADCD module to operate.
  */
static inline void RCC_enableAdcdClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCDEN_M);
}

/**
  * \brief  Disable the ADCD clock.
  * \note   This function disables the clock for the ADCD module by clearing the ADCD bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the ADCD module from operating.
  */
static inline void RCC_disableAdcdClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCDEN_M);
}

/**
  * \brief  Enable the ADCC clock.
  * \note   This function enables the clock for the ADCC module by setting the ADCC bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the ADCC module to operate.
  */
static inline void RCC_enableAdccClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCCEN_M);
}

/**
  * \brief  Disable the ADCC clock.
  * \note   This function disables the clock for the ADCC module by clearing the ADCC bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the ADCC module from operating.
  */
static inline void RCC_disableAdccClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCCEN_M);
}

/**
  * \brief  Enable the ADCB clock.
  * \note   This function enables the clock for the ADCB module by setting the ADCB bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the ADCB module to operate.
  */
static inline void RCC_enableAdcbClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCBEN_M);
}

/**
  * \brief  Disable the ADCB clock.
  * \note   This function disables the clock for the ADCB module by clearing the ADCB bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the ADCB module from operating.
  */
static inline void RCC_disableAdcbClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCBEN_M);
}

/**
  * \brief  Enable the ADCA clock.
  * \note   This function enables the clock for the ADCA module by setting the ADCA bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the ADCA module to operate.
  */
static inline void RCC_enableAdcaClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCAEN_M);
}

/**
  * \brief  Disable the ADCA clock.
  * \note   This function disables the clock for the ADCA module by clearing the ADCA bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the ADCA module from operating.
  */
static inline void RCC_disableAdcaClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_ADCAEN_M);
}

/**
  * \brief  Enable the SDFM4 clock.
  * \note   This function enables the clock for the SDFM4 module by setting the SDFM4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the SDFM4 module to operate.
  */
static inline void RCC_enableSdfm4Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM4EN_M);
}

/**
  * \brief  Disable the SDFM4 clock.
  * \note   This function disables the clock for the SDFM4 module by clearing the SDFM4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the SDFM4 module from operating.
  */
static inline void RCC_disableSdfm4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM4EN_M);
}

/**
  * \brief  Enable the SDFM3 clock.
  * \note   This function enables the clock for the SDFM3 module by setting the SDFM3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the SDFM3 module to operate.
  */
static inline void RCC_enableSdfm3Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM3EN_M);
}

/**
  * \brief  Disable the SDFM3 clock.
  * \note   This function disables the clock for the SDFM3 module by clearing the SDFM3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the SDFM3 module from operating.
  */
static inline void RCC_disableSdfm3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM3EN_M);
}

/**
  * \brief  Enable the SDFM2 clock.
  * \note   This function enables the clock for the SDFM2 module by setting the SDFM2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the SDFM2 module to operate.
  */
static inline void RCC_enableSdfm2Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM2EN_M);
}

/**
  * \brief  Disable the SDFM2 clock.
  * \note   This function disables the clock for the SDFM2 module by clearing the SDFM2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the SDFM2 module from operating.
  */
static inline void RCC_disableSdfm2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM2EN_M);
}

/**
  * \brief  Enable the SDFM1 clock.
  * \note   This function enables the clock for the SDFM1 module by setting the SDFM1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Setting this bit allows the SDFM1 module to operate.
  */
static inline void RCC_enableSdfm1Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM1EN_M);
}

/**
  * \brief  Disable the SDFM1 clock.
  * \note   This function disables the clock for the SDFM1 module by clearing the SDFM1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
  *         Clearing this bit stops the SDFM1 module from operating.
  */
static inline void RCC_disableSdfm1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_PCLKEN2_SDFM1EN_M);
}

/**
  * \brief  Enable the ANALOGSS clock.
  * \note   This function enables the clock for the ANALOGSS module by setting the ANALOGSS bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
  *         Setting this bit allows the ANALOGSS module to operate.
  */
static inline void RCC_enableAnalogssClock (void)
{
    SET_BIT(RCC->PCLKEN3.WORDVAL, RCC_PCLKEN3_ANALOGSS_M);
}

/**
  * \brief  Disable the ANALOGSS clock.
  * \note   This function disables the clock for the ANALOGSS module by clearing the ANALOGSS bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
  *         Clearing this bit stops the ANALOGSS module from operating.
  */
static inline void RCC_disableAnalogssClock (void)
{
    CLEAR_BIT(RCC->PCLKEN3.WORDVAL, RCC_PCLKEN3_ANALOGSS_M);
}

/**
  * \brief  Enable the DAC3 clock.
  * \note   This function enables the clock for the DAC3 module by setting the DAC3 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
  *         Setting this bit allows the DAC3 module to operate.
  */
static inline void RCC_enableDac3Clock (void)
{
    SET_BIT(RCC->PCLKEN3.WORDVAL, RCC_PCLKEN3_DAC3EN_M);
}

/**
  * \brief  Disable the DAC3 clock.
  * \note   This function disables the clock for the DAC3 module by clearing the DAC3 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
  *         Clearing this bit stops the DAC3 module from operating.
  */
static inline void RCC_disableDac3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN3.WORDVAL, RCC_PCLKEN3_DAC3EN_M);
}

/**
  * \brief  Enable the DAC1 clock.
  * \note   This function enables the clock for the DAC1 module by setting the DAC1 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
  *         Setting this bit allows the DAC1 module to operate.
  */
static inline void RCC_enableDac1Clock (void)
{
    SET_BIT(RCC->PCLKEN3.WORDVAL, RCC_PCLKEN3_DAC1EN_M);
}

/**
  * \brief  Disable the DAC1 clock.
  * \note   This function disables the clock for the DAC1 module by clearing the DAC1 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
  *         Clearing this bit stops the DAC1 module from operating.
  */
static inline void RCC_disableDac1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN3.WORDVAL, RCC_PCLKEN3_DAC1EN_M);
}

/**
  * \brief  Enable the DCC1 clock.
  * \note   This function enables the clock for the DCC1 module by setting the DCC1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the DCC1 module to operate.
  */
static inline void RCC_enableDcc1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_DCC1EN_M);
}

/**
  * \brief  Disable the DCC1 clock.
  * \note   This function disables the clock for the DCC1 module by clearing the DCC1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the DCC1 module from operating.
  */
static inline void RCC_disableDcc1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_DCC1EN_M);
}

/**
  * \brief  Enable the CPUxWWDG clock.
  * \note   This function enables the clock for the CPUxWWDG module by setting the CPUxWWDG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the CPUxWWDG module to operate.
  */
static inline void RCC_enableCPUxWWDGClock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_CPUXWWDGEN_M);
}

/**
  * \brief  Disable the CPUxWWDG clock.
  * \note   This function disables the clock for the CPUxWWDG module by clearing the CPUxWWDG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the CPUxWWDG module from operating.
  */
static inline void RCC_disableCPUxWWDGClock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_CPUXWWDGEN_M);
}

/**
  * \brief  Enable the EPG clock.
  * \note   This function enables the clock for the EPG module by setting the EPG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the EPG module to operate.
  */
static inline void RCC_enableEpgClock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_EPGEN_M);
}

/**
  * \brief  Disable the EPG clock.
  * \note   This function disables the clock for the EPG module by clearing the EPG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the EPG module from operating.
  */
static inline void RCC_disableEpgClock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_EPGEN_M);
}

/**
  * \brief  Enable the PMBUS clock.
  * \note   This function enables the clock for the PMBUS module by setting the PMBUS bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the PMBUS module to operate.
  */
static inline void RCC_enablePmbusClock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_PMBUSEN_M);
}

/**
  * \brief  Disable the PMBUS clock.
  * \note   This function disables the clock for the PMBUS module by clearing the PMBUS bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the PMBUS module from operating.
  */
static inline void RCC_disablePmbusClock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_PMBUSEN_M);
}

/**
  * \brief  Enable the I2C2 clock.
  * \note   This function enables the clock for the I2C2 module by setting the I2C2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the I2C2 module to operate.
  */
static inline void RCC_enableI2c2Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_I2C2EN_M);
}

/**
  * \brief  Disable the I2C2 clock.
  * \note   This function disables the clock for the I2C2 module by clearing the I2C2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the I2C2 module from operating.
  */
static inline void RCC_disableI2c2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_I2C2EN_M);
}

/**
  * \brief  Enable the I2C1 clock.
  * \note   This function enables the clock for the I2C1 module by setting the I2C1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the I2C1 module to operate.
  */
static inline void RCC_enableI2c1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_I2C1EN_M);
}

/**
  * \brief  Disable the I2C1 clock.
  * \note   This function disables the clock for the I2C1 module by clearing the I2C1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the I2C1 module from operating.
  */
static inline void RCC_disableI2c1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_I2C1EN_M);
}

/**
  * \brief  Enable the SPI4 clock.
  * \note   This function enables the clock for the SPI4 module by setting the SPI4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the SPI4 module to operate.
  */
static inline void RCC_enableSpi4Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI4EN_M);
}

/**
  * \brief  Disable the SPI4 clock.
  * \note   This function disables the clock for the SPI4 module by clearing the SPI4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the SPI4 module from operating.
  */
static inline void RCC_disableSpi4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI4EN_M);
}

/**
  * \brief  Enable the SPI3 clock.
  * \note   This function enables the clock for the SPI3 module by setting the SPI3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the SPI3 module to operate.
  */
static inline void RCC_enableSpi3Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI3EN_M);
}

/**
  * \brief  Disable the SPI3 clock.
  * \note   This function disables the clock for the SPI3 module by clearing the SPI3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the SPI3 module from operating.
  */
static inline void RCC_disableSpi3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI3EN_M);
}

/**
  * \brief  Enable the SPI2 clock.
  * \note   This function enables the clock for the SPI2 module by setting the SPI2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the SPI2 module to operate.
  */
static inline void RCC_enableSpi2Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI2EN_M);
}

/**
  * \brief  Disable the SPI2 clock.
  * \note   This function disables the clock for the SPI2 module by clearing the SPI2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the SPI2 module from operating.
  */
static inline void RCC_disableSpi2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI2EN_M);
}

/**
  * \brief  Enable the SPI1 clock.
  * \note   This function enables the clock for the SPI1 module by setting the SPI1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the SPI1 module to operate.
  */
static inline void RCC_enableSpi1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI1EN_M);
}

/**
  * \brief  Disable the SPI1 clock.
  * \note   This function disables the clock for the SPI1 module by clearing the SPI1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the SPI1 module from operating.
  */
static inline void RCC_disableSpi1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_SPI1EN_M);
}

/**
  * \brief  Enable the UART4 clock.
  * \note   This function enables the clock for the UART4 module by setting the UART4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the UART4 module to operate.
  */
static inline void RCC_enableUart4Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART4EN_M);
}

/**
  * \brief  Disable the UART4 clock.
  * \note   This function disables the clock for the UART4 module by clearing the UART4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the UART4 module from operating.
  */
static inline void RCC_disableUart4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART4EN_M);
}

/**
  * \brief  Enable the UART3 clock.
  * \note   This function enables the clock for the UART3 module by setting the UART3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the UART3 module to operate.
  */
static inline void RCC_enableUart3Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART3EN_M);
}

/**
  * \brief  Disable the UART3 clock.
  * \note   This function disables the clock for the UART3 module by clearing the UART3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the UART3 module from operating.
  */
static inline void RCC_disableUart3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART3EN_M);
}

/**
  * \brief  Enable the UART2 clock.
  * \note   This function enables the clock for the UART2 module by setting the UART2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the UART2 module to operate.
  */
static inline void RCC_enableUart2Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART2EN_M);
}

/**
  * \brief  Disable the UART2 clock.
  * \note   This function disables the clock for the UART2 module by clearing the UART2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the UART2 module from operating.
  */
static inline void RCC_disableUart2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART2EN_M);
}

/**
  * \brief  Enable the UART1 clock.
  * \note   This function enables the clock for the UART1 module by setting the UART1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Setting this bit allows the UART1 module to operate.
  */
static inline void RCC_enableUart1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART1EN_M);
}

/**
  * \brief  Disable the UART1 clock.
  * \note   This function disables the clock for the UART1 module by clearing the UART1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
  *         Clearing this bit stops the UART1 module from operating.
  */
static inline void RCC_disableUart1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_PCLKEN5_UART1EN_M);
}

/**
  * \brief  Enable the DCC3 clock.
  * \note   This function enables the clock for the DCC3 module by setting the DCC3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the DCC3 module to operate.
  */
static inline void RCC_enableDcc3Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_DCC3EN_M);
}

/**
  * \brief  Disable the DCC3 clock.
  * \note   This function disables the clock for the DCC3 module by clearing the DCC3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the DCC3 module from operating.
  */
static inline void RCC_disableDcc3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_DCC3EN_M);
}

/**
  * \brief  Enable the DCC2 clock.
  * \note   This function enables the clock for the DCC2 module by setting the DCC2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the DCC2 module to operate.
  */
static inline void RCC_enableDcc2Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_DCC2EN_M);
}

/**
  * \brief  Disable the DCC2 clock.
  * \note   This function disables the clock for the DCC2 module by clearing the DCC2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the DCC2 module from operating.
  */
static inline void RCC_disableDcc2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_DCC2EN_M);
}

/**
  * \brief  Enable the BTIM2 clock.
  * \note   This function enables the clock for the BTIM2 module by setting the BTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the BTIM2 module to operate.
  */
static inline void RCC_enableBtim2Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_BTIM2EN_M);
}

/**
  * \brief  Disable the BTIM2 clock.
  * \note   This function disables the clock for the BTIM2 module by clearing the BTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the BTIM2 module from operating.
  */
static inline void RCC_disableBtim2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_BTIM2EN_M);
}

/**
  * \brief  Enable the BTIM1 clock.
  * \note   This function enables the clock for the BTIM1 module by setting the BTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the BTIM1 module to operate.
  */
static inline void RCC_enableBtim1Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_BTIM1EN_M);
}

/**
  * \brief  Disable the BTIM1 clock.
  * \note   This function disables the clock for the BTIM1 module by clearing the BTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the BTIM1 module from operating.
  */
static inline void RCC_disableBtim1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_BTIM1EN_M);
}

/**
  * \brief  Enable the CPUxSTIM3 clock.
  * \note   This function enables the clock for the CPUxSTIM3 module by setting the CPUxSTIM3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CPUxSTIM3 module to operate.
  */
static inline void RCC_enableCpuxStim3Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CPUXSTIM3EN_M);
}

/**
  * \brief  Disable the CPUxSTIM3 clock.
  * \note   This function disables the clock for the CPUxSTIM3 module by clearing the CPUxSTIM3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CPUxSTIM3 module from operating.
  */
static inline void RCC_disableCpuxStim3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CPUXSTIM3EN_M);
}

/**
  * \brief  Enable the CPUxSTIM2 clock.
  * \note   This function enables the clock for the CPUxSTIM2 module by setting the CPUxSTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CPUxSTIM2 module to operate.
  */
static inline void RCC_enableCpuxStim2Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CPUXSTIM2EN_M);
}

/**
  * \brief  Disable the CPUxSTIM2 clock.
  * \note   This function disables the clock for the CPUxSTIM2 module by clearing the CPUxSTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CPUxSTIM2 module from operating.
  */
static inline void RCC_disableCpuxStim2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CPUXSTIM2EN_M);
}

/**
  * \brief  Enable the CPUxSTIM1 clock.
  * \note   This function enables the clock for the CPUxSTIM1 module by setting the CPUxSTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CPUxSTIM1 module to operate.
  */
static inline void RCC_enableCpuxStim1Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CPUXSTIM1EN_M);
}

/**
  * \brief  Disable the CPUxSTIM1 clock.
  * \note   This function disables the clock for the CPUxSTIM1 module by clearing the CPUxSTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CPUxSTIM1 module from operating.
  */
static inline void RCC_disableCpuxStim1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CPUXSTIM1EN_M);
}

/**
  * \brief  Enable the CLB6 clock.
  * \note   This function enables the clock for the CLB6 module by setting the CLB6 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CLB6 module to operate.
  */
static inline void RCC_enableClb6Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB6EN_M);
}

/**
  * \brief  Disable the CLB6 clock.
  * \note   This function disables the clock for the CLB6 module by clearing the CLB6 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CLB6 module from operating.
  */
static inline void RCC_disableClb6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB6EN_M);
}

/**
  * \brief  Enable the CLB5 clock.
  * \note   This function enables the clock for the CLB5 module by setting the CLB5 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CLB5 module to operate.
  */
static inline void RCC_enableClb5Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB5EN_M);
}

/**
  * \brief  Disable the CLB5 clock.
  * \note   This function disables the clock for the CLB5 module by clearing the CLB5 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CLB5 module from operating.
  */
static inline void RCC_disableClb5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB5EN_M);
}

/**
  * \brief  Enable the CLB4 clock.
  * \note   This function enables the clock for the CLB4 module by setting the CLB4 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CLB4 module to operate.
  */
static inline void RCC_enableClb4Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB4EN_M);
}

/**
  * \brief  Disable the CLB4 clock.
  * \note   This function disables the clock for the CLB4 module by clearing the CLB4 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CLB4 module from operating.
  */
static inline void RCC_disableCLB4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB4EN_M);
}

/**
  * \brief  Enable the CLB3 clock.
  * \note   This function enables the clock for the CLB3 module by setting the CLB3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CLB3 module to operate.
  */
static inline void RCC_enableClb3Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB3EN_M);
}

/**
  * \brief  Disable the CLB3 clock.
  * \note   This function disables the clock for the CLB3 module by clearing the CLB3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CLB3 module from operating.
  */
static inline void RCC_disableClb3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB3EN_M);
}

/**
  * \brief  Enable the CLB2 clock.
  * \note   This function enables the clock for the CLB2 module by setting the CLB2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CLB2 module to operate.
  */
static inline void RCC_enableClb2Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB2EN_M);
}

/**
  * \brief  Disable the CLB2 clock.
  * \note   This function disables the clock for the CLB2 module by clearing the CLB2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CLB2 module from operating.
  */
static inline void RCC_disableClb2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB2EN_M);
}

/**
  * \brief  Enable the CLB1 clock.
  * \note   This function enables the clock for the CLB1 module by setting the CLB1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the CLB1 module to operate.
  */
static inline void RCC_enableClb1Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB1EN_M);
}

/**
  * \brief  Disable the CLB1 clock.
  * \note   This function disables the clock for the CLB1 module by clearing the CLB1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the CLB1 module from operating.
  */
static inline void RCC_disableClb1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_CLB1EN_M);
}

/**
  * \brief  Enable the TIM2 clock.
  * \note   This function enables the clock for the TIM2 module by setting the TIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the TIM2 module to operate.
  */
static inline void RCC_enableTim2Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_TIM2EN_M);
}

/**
  * \brief  Disable the TIM2 clock.
  * \note   This function disables the clock for the TIM2 module by clearing the TIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the TIM2 module from operating.
  */
static inline void RCC_disableTim2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_TIM2EN_M);
}

/**
  * \brief  Enable the TIM1 clock.
  * \note   This function enables the clock for the TIM1 module by setting the TIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Setting this bit allows the TIM1 module to operate.
  */
static inline void RCC_enableTim1Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_TIM1EN_M);
}

/**
  * \brief  Disable the TIM1 clock.
  * \note   This function disables the clock for the TIM1 module by clearing the TIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
  *         Clearing this bit stops the TIM1 module from operating.
  */
static inline void RCC_disableTim1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_PCLKEN6_TIM1EN_M);
}

/**
  * \brief  Enable the ADCAGG2 clock.
  * \note   This function enables the clock for the ADCAGG2 module by setting the ADCAGG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCAGG2 module to operate.
  */
static inline void RCC_enableAdcAgg2Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCAGG2EN_M);
}

/**
  * \brief  Disable the ADCAGG2 clock.
  * \note   This function disables the clock for the ADCAGG2 module by clearing the ADCAGG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCAGG2 module from operating.
  */
static inline void RCC_disableAdcAgg2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCAGG2EN_M);
}

/**
  * \brief  Enable the ADCAGG1 clock.
  * \note   This function enables the clock for the ADCAGG1 module by setting the ADCAGG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCAGG1 module to operate.
  */
static inline void RCC_enableAdcAgg1Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCAGG1EN_M);
}

/**
  * \brief  Disable the ADCAGG1 clock.
  * \note   This function disables the clock for the ADCAGG1 module by clearing the ADCAGG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCAGG1 module from operating.
  */
static inline void RCC_disableAdcAgg1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCAGG1EN_M);
}

/**
  * \brief  Enable the ADCCHK8 clock.
  * \note   This function enables the clock for the ADCCHK8 module by setting the ADCCHK8 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK8 module to operate.
  */
static inline void RCC_enableAdcChk8Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK8EN_M);
}

/**
  * \brief  Disable the ADCCHK8 clock.
  * \note   This function disables the clock for the ADCCHK8 module by clearing the ADCCHK8 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK8 module from operating.
  */
static inline void RCC_disableAdcChk8Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK8EN_M);
}

/**
  * \brief  Enable the ADCCHK7 clock.
  * \note   This function enables the clock for the ADCCHK7 module by setting the ADCCHK7 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK7 module to operate.
  */
static inline void RCC_enableAdcChk7Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK7EN_M);
}

/**
  * \brief  Disable the ADCCHK7 clock.
  * \note   This function disables the clock for the ADCCHK7 module by clearing the ADCCHK7 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK7 module from operating.
  */
static inline void RCC_disableAdcChk7Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK7EN_M);
}

/**
  * \brief  Enable the ADCCHK6 clock.
  * \note   This function enables the clock for the ADCCHK6 module by setting the ADCCHK6 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK6 module to operate.
  */
static inline void RCC_enableAdcChk6Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK6EN_M);
}

/**
  * \brief  Disable the ADCCHK6 clock.
  * \note   This function disables the clock for the ADCCHK6 module by clearing the ADCCHK6 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK6 module from operating.
  */
static inline void RCC_disableAdcChk6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK6EN_M);
}

/**
  * \brief  Enable the ADCCHK5 clock.
  * \note   This function enables the clock for the ADCCHK5 module by setting the ADCCHK5 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK5 module to operate.
  */
static inline void RCC_enableAdcChk5Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK5EN_M);
}

/**
  * \brief  Disable the ADCCHK5 clock.
  * \note   This function disables the clock for the ADCCHK5 module by clearing the ADCCHK5 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK5 module from operating.
  */
static inline void RCC_disableAdcChk5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK5EN_M);
}

/**
  * \brief  Enable the ADCCHK4 clock.
  * \note   This function enables the clock for the ADCCHK4 module by setting the ADCCHK4 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK4 module to operate.
  */
static inline void RCC_enableAdcChk4Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK4EN_M);
}

/**
  * \brief  Disable the ADCCHK4 clock.
  * \note   This function disables the clock for the ADCCHK4 module by clearing the ADCCHK4 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK4 module from operating.
  */
static inline void RCC_disableAdcChk4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK4EN_M);
}

/**
  * \brief  Enable the ADCCHK3 clock.
  * \note   This function enables the clock for the ADCCHK3 module by setting the ADCCHK3 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK3 module to operate.
  */
static inline void RCC_enableAdcChk3Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK3EN_M);
}

/**
  * \brief  Disable the ADCCHK3 clock.
  * \note   This function disables the clock for the ADCCHK3 module by clearing the ADCCHK3 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK3 module from operating.
  */
static inline void RCC_disableAdcChk3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK3EN_M);
}

/**
  * \brief  Enable the ADCCHK2 clock.
  * \note   This function enables the clock for the ADCCHK2 module by setting the ADCCHK2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK2 module to operate.
  */
static inline void RCC_enableAdcChk2Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK2EN_M);
}

/**
  * \brief  Disable the ADCCHK2 clock.
  * \note   This function disables the clock for the ADCCHK2 module by clearing the ADCCHK2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK2 module from operating.
  */
static inline void RCC_disableAdcChk2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK2EN_M);
}

/**
  * \brief  Enable the ADCCHK1 clock.
  * \note   This function enables the clock for the ADCCHK1 module by setting the ADCCHK1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the ADCCHK1 module to operate.
  */
static inline void RCC_enableAdcChk1Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK1EN_M);
}

/**
  * \brief  Disable the ADCCHK1 clock.
  * \note   This function disables the clock for the ADCCHK1 module by clearing the ADCCHK1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the ADCCHK1 module from operating.
  */
static inline void RCC_disableAdcChk1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_ADCCHK1EN_M);
}

/**
  * \brief  Enable the AWK clock.
  * \note   This function enables the clock for the AWK module by setting the AWK bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the AWK module to operate.
  */
static inline void RCC_enableAwkClock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_AWKEN_M);
}

/**
  * \brief  Disable the AWK clock.
  * \note   This function disables the clock for the AWK module by clearing the AWK bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the AWK module from operating.
  */
static inline void RCC_disableAwkClock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_AWKEN_M);
}

/**
  * \brief  Enable the LPTIM clock.
  * \note   This function enables the clock for the LPTIM module by setting the LPTIM bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the LPTIM module to operate.
  */
static inline void RCC_enableLptimClock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_LPTIMEN_M);
}

/**
  * \brief  Disable the LPTIM clock.
  * \note   This function disables the clock for the LPTIM module by clearing the LPTIM bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the LPTIM module from operating.
  */
static inline void RCC_disableLptimClock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_LPTIMEN_M);
}

/**
  * \brief  Enable the IWDG2 clock.
  * \note   This function enables the clock for the IWDG2 module by setting the IWDG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the IWDG2 module to operate.
  */
static inline void RCC_enableIwdg2Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_IWDG2EN_M);
}

/**
  * \brief  Disable the IWDG2 clock.
  * \note   This function disables the clock for the IWDG2 module by clearing the IWDG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the IWDG2 module from operating.
  */
static inline void RCC_disableIwdg2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_IWDG2EN_M);
}

/**
  * \brief  Enable the CPUxIWDG1 clock.
  * \note   This function enables the clock for the CPUxIWDG1 module by setting the CPUxIWDG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the CPUxIWDG1 module to operate.
  */
static inline void RCC_enableCpuxIwdg1Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_CPUXIWDG1EN_M);
}

/**
  * \brief  Disable the CPUxIWDG1 clock.
  * \note   This function disables the clock for the CPUxIWDG1 module by clearing the CPUxIWDG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the CPUxIWDG1 module from operating.
  */
static inline void RCC_disableCpuxIwdg1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_CPUXIWDG1EN_M);
}

/**
  * \brief  Enable the PWR clock.
  * \note   This function enables the clock for the PWR module by setting the PWR bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Setting this bit allows the PWR module to operate.
  */
static inline void RCC_enablePwrClock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_PWREN_M);
}

/**
  * \brief  Disable the PWR clock.
  * \note   This function disables the clock for the PWR module by clearing the PWR bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
  *         Clearing this bit stops the PWR module from operating.
  */
static inline void RCC_disablePwrClock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_PCLKEN8_PWREN_M);
}

/**
  * \brief  Enable the UPP clock in sleep mode.
  * \note   This function enables the clock for the UPP module by setting the UPP bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the UPP module to operate in sleep mode.
  */
static inline void RCC_enableUppClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_UPPEN_M);
}

/**
  * \brief  Disable the UPP clock in sleep mode.
  * \note   This function disables the clock for the UPP module by clearing the UPP bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the UPPLP module from operating in sleep mode.
  */
static inline void RCC_disableUppClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_UPPEN_M);
}

/**
  * \brief  Enable the EMIF clock in sleep mode.
  * \note   This function enables the clock for the EMIF module by setting the EMIF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the EMIFLP module to operate in sleep mode.
  */
static inline void RCC_enableEmifClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EMIFEN_M);
}

/**
  * \brief  Disable the EMIF clock in sleep mode.
  * \note   This function disables the clock for the EMIF module by clearing the EMIF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the EMIF module from operating in sleep mode.
  */
static inline void RCC_disableEmifClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EMIFEN_M);
}

/**
  * \brief  Enable the SEMA clock in sleep mode.
  * \note   This function enables the clock for the SEMA module by setting the SEMA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the SEMA module to operate in sleep mode.
  */
static inline void RCC_enableSemaClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_SEMAEN_M);
}

/**
  * \brief  Disable the SEMA clock in sleep mode.
  * \note   This function disables the clock for the SEMA module by clearing the SEMA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the SEMA module from operating in sleep mode.
  */
static inline void RCC_disableSemaClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_SEMAEN_M);
}

/**
  * \brief  Enable the MU clock in sleep mode.
  * \note   This function enables the clock for the MU module by setting the MU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the MU module to operate in sleep mode.
  */
static inline void RCC_enableMuClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_MUEN_M);
}

/**
  * \brief  Disable the MU clock in sleep mode.
  * \note   This function disables the clock for the MU module by clearing the MU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the MU module from operating in sleep mode.
  */
static inline void RCC_disableMuClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_MUEN_M);
}

/**
  * \brief  Enable the GPIOH clock in sleep mode.
  * \note   This function enables the clock for the GPIOH module by setting the GPIOH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOH module to operate in sleep mode.
  */
static inline void RCC_enableGpiohClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOHEN_M);
}

/**
  * \brief  Disable the GPIOH clock in sleep mode.
  * \note   This function disables the clock for the GPIOH module by clearing the GPIOH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOH module from operating in sleep mode.
  */
static inline void RCC_disableGpiohClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOHEN_M);
}

/**
  * \brief  Enable the GPIOG clock in sleep mode.
  * \note   This function enables the clock for the GPIOG module by setting the GPIOG bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOG module to operate in sleep mode.
  */
static inline void RCC_enableGpiogClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOGEN_M);
}

/**
  * \brief  Disable the GPIOG clock in sleep mode.
  * \note   This function disables the clock for the GPIOG module by clearing the GPIOG bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOG module from operating in sleep mode.
  */
static inline void RCC_disableGpiogClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOGEN_M);
}

/**
  * \brief  Enable the GPIOF clock in sleep mode.
  * \note   This function enables the clock for the GPIOF module by setting the GPIOF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOF module to operate in sleep mode.
  */
static inline void RCC_enableGpiofClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOFEN_M);
}

/**
  * \brief  Disable the GPIOF clock in sleep mode.
  * \note   This function disables the clock for the GPIOF module by clearing the GPIOF bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOF module from operating in sleep mode.
  */
static inline void RCC_disableGpiofClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOFEN_M);
}

/**
  * \brief  Enable the GPIOE clock in sleep mode.
  * \note   This function enables the clock for the GPIOE module by setting the GPIOE bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOE module to operate in sleep mode.
  */
static inline void RCC_enableGpioelockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOEEN_M);
}

/**
  * \brief  Disable the GPIOE clock in sleep mode.
  * \note   This function disables the clock for the GPIOE module by clearing the GPIOE bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOE module from operating in sleep mode.
  */
static inline void RCC_disableGpioeClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOEEN_M);
}

/**
  * \brief  Enable the GPIOD clock in sleep mode.
  * \note   This function enables the clock for the GPIOD module by setting the GPIOD bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOD module to operate in sleep mode.
  */
static inline void RCC_enableGpiodlockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIODEN_M);
}

/**
  * \brief  Disable the GPIOD clock in sleep mode.
  * \note   This function disables the clock for the GPIOD module by clearing the GPIOD bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOD module from operating in sleep mode.
  */
static inline void RCC_disableGpiodClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIODEN_M);
}

/**
  * \brief  Enable the GPIOC clock in sleep mode.
  * \note   This function enables the clock for the GPIOC module by setting the GPIOC bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOC module to operate in sleep mode.
  */
static inline void RCC_enableGpiocClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOCEN_M);
}

/**
  * \brief  Disable the GPIOC clock in sleep mode.
  * \note   This function disables the clock for the GPIOC module by clearing the GPIOC bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOC module from operating in sleep mode.
  */
static inline void RCC_disableGpiocClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOCEN_M);
}

/**
  * \brief  Enable the GPIOB clock in sleep mode.
  * \note   This function enables the clock for the GPIOB module by setting the GPIOB bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOB module to operate in sleep mode.
  */
static inline void RCC_enableGpiobClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOBEN_M);
}

/**
  * \brief  Disable the GPIOB clock in sleep mode.
  * \note   This function disables the clock for the GPIOB module by clearing the GPIOB bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOB module from operating in sleep mode.
  */
static inline void RCC_disableGpiobClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOBEN_M);
}

/**
  * \brief  Enable the GPIOA clock in sleep mode.
  * \note   This function enables the clock for the GPIOA module by setting the GPIOA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the GPIOA module to operate in sleep mode.
  */
static inline void RCC_enableGpioaClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOAEN_M);
}

/**
  * \brief  Disable the GPIOA clock in sleep mode.
  * \note   This function disables the clock for the GPIOA module by clearing the GPIOA bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the GPIOA module from operating in sleep mode.
  */
static inline void RCC_disableGpioaClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_GPIOAEN_M);
}

/**
  * \brief  Enable the EMATH clock in sleep mode.
  * \note   This function enables the clock for the EMATH module by setting the EMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the EMATH module to operate in sleep mode.
  */
static inline void RCC_enableEmathClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EMATHEN_M);
}

/**
  * \brief  Disable the EMATH clock in sleep mode.
  * \note   This function disables the clock for the EMATH module by clearing the EMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the EMATH module from operating in sleep mode.
  */
static inline void RCC_disableEmathClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EMATHEN_M);
}

/**
  * \brief  Enable the QSPI clock in sleep mode.
  * \note   This function enables the clock for the QSPI module by setting the QSPI bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the QSPI module to operate in sleep mode.
  */
static inline void RCC_enableQspiClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_QSPIEN_M);
}

/**
  * \brief  Disable the QSPI clock in sleep mode.
  * \note   This function disables the clock for the QSPI module by clearing the QSPI bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the QSPI module from operating in sleep mode.
  */
static inline void RCC_disableQspiClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_QSPIEN_M);
}

/**
  * \brief  Enable the CPUxMMATH clock in sleep mode.
  * \note   This function enables the clock for the CPUxMMATH module by setting the CPUxMMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the CPUxMMATH module to operate in sleep mode.
  */
static inline void RCC_enableCpuxMmathClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_CPUXMMATHEN_M);
}

/**
  * \brief  Disable the CPUxMMATH clock in sleep mode.
  * \note   This function disables the clock for the CPUxMMATH module by clearing the CPUxMMATH bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the CPUxMMATH module from operating in sleep mode.
  */
static inline void RCC_disableCpuxMmathClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_CPUXMMATHEN_M);
}

/**
  * \brief  Enable the EDMA2 clock in sleep mode.
  * \note   This function enables the clock for the EDMA2 module by setting the EDMA2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the EDMA2 module to operate in sleep mode.
  */
static inline void RCC_enableEdma2ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EDMA2EN_M);
}

/**
  * \brief  Disable the EDMA2 clock in sleep mode.
  * \note   This function disables the clock for the EDMA2 module by clearing the EDMA2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the EDMA2 module from operating in sleep mode.
  */
static inline void RCC_disableEdma2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EDMA2EN_M);
}

/**
  * \brief  Enable the EDMA1 clock in sleep mode.
  * \note   This function enables the clock for the EDMA1 module by setting the EDMA1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the EDMA1 module to operate in sleep mode.
  */
static inline void RCC_enableEdma1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EDMA1EN_M);
}

/**
  * \brief  Disable the EDMA1 clock in sleep mode.
  * \note   This function disables the clock for the EDMA1 module by clearing the EDMA1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the EDMA1 module from operating in sleep mode.
  */
static inline void RCC_disableEdma1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_EDMA1EN_M);
}

/**
  * \brief  Enable the DMAMUX2 clock in sleep mode.
  * \note   This function enables the clock for the DMAMUX2 module by setting the DMAMUX2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the DMAMUX2 module to operate in sleep mode.
  */
static inline void RCC_enableDmamux2ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_DMAMUX2EN_M);
}

/**
  * \brief  Disable the DMAMUX2 clock in sleep mode.
  * \note   This function disables the clock for the DMAMUX2 module by clearing the DMAMUX2 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the DMAMUX2 module from operating in sleep mode.
  */
static inline void RCC_disableDmamux2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_DMAMUX2EN_M);
}

/**
  * \brief  Enable the DMAMUX1 clock in sleep mode.
  * \note   This function enables the clock for the DMAMUX1 module by setting the DMAMUX1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the DMAMUX1 module to operate in sleep mode.
  */
static inline void RCC_enableDmamux1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_DMAMUX1EN_M);
}

/**
  * \brief  Disable the DMAMUX1 clock in sleep mode.
  * \note   This function disables the clock for the DMAMUX1 module by clearing the DMAMUX1 bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the DMAMUX1 module from operating in sleep mode.
  */
static inline void RCC_disableDmamux1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_DMAMUX1EN_M);
}

/**
  * \brief  Enable the SMPU clock in sleep mode.
  * \note   This function enables the clock for the SMPU module by setting the SMPU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the SMPU module to operate in sleep mode.
  */
static inline void RCC_enableSmpuClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_SMPUEN_M);
}

/**
  * \brief  Disable the SMPU clock in sleep mode.
  * \note   This function disables the clock for the SMPU module by clearing the SMPU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the SMPU module from operating in sleep mode.
  */
static inline void RCC_disableSmpuClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_SMPUEN_M);
}

/**
  * \brief  Enable the FMU clock in sleep mode.
  * \note   This function enables the clock for the FMU module by setting the FMU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the FMU module to operate in sleep mode.
  */
static inline void RCC_enableFmuClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_FMUEN_M);
}

/**
  * \brief  Disable the FMU clock in sleep mode.
  * \note   This function disables the clock for the FMU module by clearing the FMU bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the FMU module from operating in sleep mode.
  */
static inline void RCC_disableFmuClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_FMUEN_M);
}

/**
  * \brief  Enable the BUS clock in sleep mode.
  * \note   This function enables the clock for the BUS module by setting the BUS bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Setting this bit allows the BUS module to operate in sleep mode.
  */
static inline void RCC_enableBusClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_BUSEN_M);
}

/**
  * \brief  Disable the BUS clock in sleep mode.
  * \note   This function disables the clock for the BUS module by clearing the BUS bit in the
  *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
  *         Clearing this bit stops the BUS module from operating in sleep mode.
  */
static inline void RCC_disableBusClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_HCLKLPEN1_BUSEN_M);
}

/**
  * \brief  Enable the TCM clock in sleep mode.
  * \note   This function enables the clock for the TCM module by setting the TCM bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the TCM module to operate in sleep mode.
  */
static inline void RCC_enableTcmClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_TCMEN_M);
}

/**
  * \brief  Disable the TCM clock in sleep mode.
  * \note   This function disables the clock for the TCM module by clearing the TCM bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the TCM module from operating in sleep mode.
  */
static inline void RCC_disableTcmClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_TCMEN_M);
}

/**
  * \brief  Enable the CANFD2 clock in sleep mode.
  * \note   This function enables the clock for the Candf2 module by setting the CANFD2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the CANFD2 module to operate in sleep mode.
  */
static inline void RCC_enableCanfd2ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CANFD2EN_M);
}

/**
  * \brief  Disable the CANFD2 clock in sleep mode.
  * \note   This function disables the clock for the canfd2 module by clearing the CANFD2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the CANFD2 module from operating in sleep mode.
  */
static inline void RCC_disableCanfd2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CANFD2EN_M);
}

/**
  * \brief  Enable the CANFD1 clock in sleep mode.
  * \note   This function enables the clock for the canfd1 module by setting the CANFD1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the CANFD1 module to operate in sleep mode.
  */
static inline void RCC_enableCanfd1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CANFD1EN_M);
}

/**
  * \brief  Disable the CANFD1 clock in sleep mode.
  * \note   This function disables the clock for the CANFD1 module by clearing the CANFD1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the CANFD1 module from operating in sleep mode.
  */
static inline void RCC_disableCanfd1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CANFD1EN_M);
}

/**
  * \brief  Enable the CAN1 clock in sleep mode.
  * \note   This function enables the clock for the CAN1 module by setting the CAN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the CAN1 module to operate in sleep mode.
  */
static inline void RCC_enableCan1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CAN1EN_M);
}

/**
  * \brief  Disable the CAN1 clock in sleep mode.
  * \note   This function disables the clock for the CAN1 module by clearing the CAN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the CAN1 module from operating in sleep mode.
  */
static inline void RCC_disableCan1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CAN1EN_M);
}

/**
  * \brief  Enable the LIN2 clock in sleep mode.
  * \note   This function enables the clock for the LIN2 module by setting the LIN2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the LIN2 module to operate in sleep mode.
  */
static inline void RCC_enableLin2ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_LIN2EN_M);
}

/**
  * \brief  Disable the LIN2 clock in sleep mode.
  * \note   This function disables the clock for the LIN2 module by clearing the LIN2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the LIN2 module from operating in sleep mode.
  */
static inline void RCC_disableLin2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_LIN2EN_M);
}

/**
  * \brief  Enable the LIN1 clock in sleep mode.
  * \note   This function enables the clock for the LIN1 module by setting the LIN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the LIN1 module to operate in sleep mode.
  */
static inline void RCC_enableLin1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_LIN1EN_M);
}

/**
  * \brief  Disable the LIN1 clock in sleep mode.
  * \note   This function disables the clock for the LIN1 module by clearing the LIN1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the LIN1 module from operating in sleep mode.
  */
static inline void RCC_disableLin1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_LIN1EN_M);
}

/**
  * \brief  Enable the BGCRC2 clock in sleep mode.
  * \note   This function enables the clock for the BGCRC2 module by setting the BGCRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the BGCRC2 module to operate in sleep mode.
  */
static inline void RCC_enableBgcrc2ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_BGCRC2EN_M);
}

/**
  * \brief  Disable the BGCRC2 clock in sleep mode.
  * \note   This function disables the clock for the BGCRC2 module by clearing the BGCRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the BGCRC2 module from operating in sleep mode.
  */
static inline void RCC_disableBgcrc2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_BGCRC2EN_M);
}

/**
  * \brief  Enable the BGCRC1 clock in sleep mode.
  * \note   This function enables the clock for the BGCRC1 module by setting the BGCRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the BGCRC1 module to operate in sleep mode.
  */
static inline void RCC_enableBcrc1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_BGCRC1EN_M);
}

/**
  * \brief  Disable the BGCRC1 clock in sleep mode.
  * \note   This function disables the clock for the BGCRC1 module by clearing the BGCRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the BGCRC1 module from operating in sleep mode.
  */
static inline void RCC_disableBcrc1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_BGCRC1EN_M);
}

/**
  * \brief  Enable the CRC2 clock in sleep mode.
  * \note   This function enables the clock for the CRC2 module by setting the CRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the CRC2 module to operate in sleep mode.
  */
static inline void RCC_enableCrc2ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CRC2EN_M);
}

/**
  * \brief  Disable the CRC2 clock in sleep mode.
  * \note   This function disables the clock for the CRC2 module by clearing the CRC2 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the CRC2 module from operating in sleep mode.
  */
static inline void RCC_disableCrc2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CRC2EN_M);
}

/**
  * \brief  Enable the CRC1 clock in sleep mode.
  * \note   This function enables the clock for the CRC1 module by setting the CRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the CRC1 module to operate in sleep mode.
  */
static inline void RCC_enableCrc1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CRC1EN_M);
}

/**
  * \brief  Disable the CRC1 clock in sleep mode.
  * \note   This function disables the clock for the CRC1 module by clearing the CRC1 bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the CRC1 module from operating in sleep mode.
  */
static inline void RCC_disableCrc1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_CRC1EN_M);
}

/**
  * \brief  Enable the AESHASH clock in sleep mode.
  * \note   This function enables the clock for the AESHASH module by setting the AESHASH bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the AESHASH module to operate in sleep mode.
  */
static inline void RCC_enableAesHashClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_AESHASHEN_M);
}

/**
  * \brief  Disable the AESHASH clock in sleep mode.
  * \note   This function disables the clock for the AESHASH module by clearing the AESHASH bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the AESHASH module from operating in sleep mode.
  */
static inline void RCC_disableAesHashClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_AESHASHEN_M);
}

/**
  * \brief  Enable the TRNG clock in sleep mode.
  * \note   This function enables the clock for the TRNG module by setting the TRNG bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Setting this bit allows the TRNG module to operate in sleep mode.
  */
static inline void RCC_enableTrngClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_TRNGEN_M);
}

/**
  * \brief  Disable the TRNG clock in sleep mode.
  * \note   This function disables the clock for the TRNG module by clearing the TRNG bit in the
  *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
  *         Clearing this bit stops the TRNG module from operating in sleep mode.
  */
static inline void RCC_disableTrngClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_HCLKLPEN2_TRNGEN_M);
}

/**
  * \brief  Enable the EPWM18 clock in sleep mode.
  * \note   This function enables the clock for the EPWM18 module by setting the EPWM18 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM18 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm18ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM18EN_M);
}

/**
  * \brief  Disable the EPWM18 clock in sleep mode.
  * \note   This function disables the clock for the EPWM18 module by clearing the EPWM18 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM18 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm18ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM18EN_M);
}

/**
  * \brief  Enable the EPWM17 clock in sleep mode.
  * \note   This function enables the clock for the EPWM17 module by setting the EPWM17 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM17 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm17ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM17EN_M);
}

/**
  * \brief  Disable the EPWM17 clock in sleep mode.
  * \note   This function disables the clock for the EPWM17 module by clearing the EPWM17 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM17 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm17ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM17EN_M);
}

/**
  * \brief  Enable the EQEP6 clock in sleep mode.
  * \note   This function enables the clock for the EQEP6 module by setting the EQEP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EQEP6 module to operate in sleep mode.
  */
static inline void RCC_enableEqep6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP6EN_M);
}

/**
  * \brief  Disable the EQEP6 clock in sleep mode.
  * \note   This function disables the clock for the EQEP6 module by clearing the EQEP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EQEP6 module from operating in sleep mode.
  */
static inline void RCC_disableEqep6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP6EN_M);
}

/**
  * \brief  Enable the EQEP5 clock in sleep mode.
  * \note   This function enables the clock for the EQEP5 module by setting the EQEP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EQEP5 module to operate in sleep mode.
  */
static inline void RCC_enableEqep5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP5EN_M);
}

/**
  * \brief  Disable the EQEP5 clock in sleep mode.
  * \note   This function disables the clock for the EQEP5 module by clearing the EQEP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EQEP5 module from operating in sleep mode.
  */
static inline void RCC_disableEqep5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP5EN_M);
}

/**
  * \brief  Enable the EQEP4 clock in sleep mode.
  * \note   This function enables the clock for the EQEP4 module by setting the EQEP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EQEP4 module to operate in sleep mode.
  */
static inline void RCC_enableEqep4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP4EN_M);
}

/**
  * \brief  Disable the EQEP4 clock in sleep mode.
  * \note   This function disables the clock for the EQEP4 module by clearing the EQEP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EQEP4 module from operating in sleep mode.
  */
static inline void RCC_disableEqep4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP4EN_M);
}

/**
  * \brief  Enable the EQEP3 clock in sleep mode.
  * \note   This function enables the clock for the EQEP3 module by setting the EQEP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EQEP3 module to operate in sleep mode.
  */
static inline void RCC_enableEqep3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP3EN_M);
}

/**
  * \brief  Disable the EQEP3 clock in sleep mode.
  * \note   This function disables the clock for the EQEP3 module by clearing the EQEP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EQEP3 module from operating in sleep mode.
  */
static inline void RCC_disableEqep3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP3EN_M);
}

/**
  * \brief  Enable the EQEP2 clock in sleep mode.
  * \note   This function enables the clock for the EQEP2 module by setting the EQEP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EQEP2 module to operate in sleep mode.
  */
static inline void RCC_enableEqep2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP2EN_M);
}

/**
  * \brief  Disable the EQEP2 clock in sleep mode.
  * \note   This function disables the clock for the EQEP2 module by clearing the EQEP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EQEP2 module from operating in sleep mode.
  */
static inline void RCC_disableEqep2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP2EN_M);
}

/**
  * \brief  Enable the EQEP1 clock in sleep mode.
  * \note   This function enables the clock for the EQEP1 module by setting the EQEP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EQEP1 module to operate in sleep mode.
  */
static inline void RCC_enableEqep1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP1EN_M);
}

/**
  * \brief  Disable the EQEP1 clock in sleep mode.
  * \note   This function disables the clock for the EQEP1 module by clearing the EQEP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EQEP1 module from operating in sleep mode.
  */
static inline void RCC_disableEqep1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EQEP1EN_M);
}

/**
  * \brief  Enable the ECAP7 clock in sleep mode.
  * \note   This function enables the clock for the ECAP7 module by setting the ECAP7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP7 module to operate in sleep mode.
  */
static inline void RCC_enableEcap7ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP7EN_M);
}

/**
  * \brief  Disable the ECAP7 clock in sleep mode.
  * \note   This function disables the clock for the ECAP7 module by clearing the ECAP7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP7 module from operating in sleep mode.
  */
static inline void RCC_disableEcap7ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP7EN_M);
}

/**
  * \brief  Enable the ECAP6 clock in sleep mode.
  * \note   This function enables the clock for the ECAP6 module by setting the ECAP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP6 module to operate in sleep mode.
  */
static inline void RCC_enableEcap6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP6EN_M);
}

/**
  * \brief  Disable the ECAP6 clock in sleep mode.
  * \note   This function disables the clock for the ECAP6 module by clearing the ECAP6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP6 module from operating in sleep mode.
  */
static inline void RCC_disableEcap6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP6EN_M);
}

/**
  * \brief  Enable the ECAP5 clock in sleep mode.
  * \note   This function enables the clock for the ECAP5 module by setting the ECAP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP5 module to operate in sleep mode.
  */
static inline void RCC_enableEcap5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP5EN_M);
}

/**
  * \brief  Disable the ECAP5 clock in sleep mode.
  * \note   This function disables the clock for the ECAP5 module by clearing the ECAP5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP5 module from operating in sleep mode.
  */
static inline void RCC_disableEcap5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP5EN_M);
}

/**
  * \brief  Enable the ECAP4 clock in sleep mode.
  * \note   This function enables the clock for the ECAP4 module by setting the ECAP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP4 module to operate in sleep mode.
  */
static inline void RCC_enableEcap4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP4EN_M);
}

/**
  * \brief  Disable the ECAP4 clock in sleep mode.
  * \note   This function disables the clock for the ECAP4 module by clearing the ECAP4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP4 module from operating in sleep mode.
  */
static inline void RCC_disableEcap4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP4EN_M);
}

/**
  * \brief  Enable the ECAP3 clock in sleep mode.
  * \note   This function enables the clock for the ECAP3 module by setting the ECAP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP3 module to operate in sleep mode.
  */
static inline void RCC_enableEcap3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP3EN_M);
}

/**
  * \brief  Disable the ECAP3 clock in sleep mode.
  * \note   This function disables the clock for the ECAP3 module by clearing the ECAP3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP3 module from operating in sleep mode.
  */
static inline void RCC_disableEcap3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP3EN_M);
}

/**
  * \brief  Enable the ECAP2 clock in sleep mode.
  * \note   This function enables the clock for the ECAP2 module by setting the ECAP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP2 module to operate in sleep mode.
  */
static inline void RCC_enableEcap2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP2EN_M);
}

/**
  * \brief  Disable the ECAP2 clock in sleep mode.
  * \note   This function disables the clock for the ECAP2 module by clearing the ECAP2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP2 module from operating in sleep mode.
  */
static inline void RCC_disableEcap2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP2EN_M);
}

/**
  * \brief  Enable the ECAP1 clock in sleep mode.
  * \note   This function enables the clock for the ECAP1 module by setting the ECAP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the ECAP1 module to operate in sleep mode.
  */
static inline void RCC_enableEcap1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP1EN_M);
}

/**
  * \brief  Disable the ECAP1 clock in sleep mode.
  * \note   This function disables the clock for the ECAP1 module by clearing the ECAP1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the ECAP1 module from operating in sleep mode.
  */
static inline void RCC_disableEcap1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_ECAP1EN_M);
}

/**
  * \brief  Enable the EPWM16 clock in sleep mode.
  * \note   This function enables the clock for the EPWM16 module by setting the EPWM16 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM16 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm16ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM16EN_M);
}

/**
  * \brief  Disable the EPWM16 clock in sleep mode.
  * \note   This function disables the clock for the EPWM16 module by clearing the EPWM16 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM16 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm16ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM16EN_M);
}

/**
  * \brief  Enable the EPWM15 clock in sleep mode.
  * \note   This function enables the clock for the EPWM15 module by setting the EPWM15 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM15 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm15ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM15EN_M);
}

/**
  * \brief  Disable the EPWM15 clock in sleep mode.
  * \note   This function disables the clock for the EPWM15 module by clearing the EPWM15 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM15 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm15ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM15EN_M);
}

/**
  * \brief  Enable the EPWM14 clock in sleep mode.
  * \note   This function enables the clock for the EPWM14 module by setting the EPWM14 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM14 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm14ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM14EN_M);
}

/**
  * \brief  Disable the EPWM14 clock in sleep mode.
  * \note   This function disables the clock for the EPWM14 module by clearing the EPWM14 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM14 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm14ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM14EN_M);
}

/**
  * \brief  Enable the EPWM13 clock in sleep mode.
  * \note   This function enables the clock for the EPWM13 module by setting the EPWM13 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM13 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm13ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM13EN_M);
}

/**
  * \brief  Disable the EPWM13 clock in sleep mode.
  * \note   This function disables the clock for the EPWM13 module by clearing the EPWM13 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM13 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm13ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM13EN_M);
}

/**
  * \brief  Enable the EPWM12 clock in sleep mode.
  * \note   This function enables the clock for the EPWM12 module by setting the EPWM12 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM12 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm12ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM12EN_M);
}

/**
  * \brief  Disable the EPWM12 clock in sleep mode.
  * \note   This function disables the clock for the EPWM12 module by clearing the EPWM12 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM12 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm12ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM12EN_M);
}

/**
  * \brief  Enable the EPWM11 clock in sleep mode.
  * \note   This function enables the clock for the EPWM11 module by setting the EPWM11 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM11 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm11ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM11EN_M);
}

/**
  * \brief  Disable the EPWM11 clock in sleep mode.
  * \note   This function disables the clock for the EPWM11 module by clearing the EPWM11 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM11 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm11ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM11EN_M);
}

/**
  * \brief  Enable the EPWM10 clock in sleep mode.
  * \note   This function enables the clock for the EPWM10 module by setting the EPWM10 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM10 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm10ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM10EN_M);
}

/**
  * \brief  Disable the EPWM10 clock in sleep mode.
  * \note   This function disables the clock for the EPWM10 module by clearing the EPWM10 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM10 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm10ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM10EN_M);
}

/**
  * \brief  Enable the EPWM9 clock in sleep mode.
  * \note   This function enables the clock for the EPWM9 module by setting the EPWM9 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM9 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm9ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM9EN_M);
}

/**
  * \brief  Disable the EPWM9 clock in sleep mode.
  * \note   This function disables the clock for the EPWM9 module by clearing the EPWM9 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM9 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm9ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM9EN_M);
}

/**
  * \brief  Enable the EPWM8 clock in sleep mode.
  * \note   This function enables the clock for the EPWM8 module by setting the EPWM8 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM8 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm8ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM8EN_M);
}

/**
  * \brief  Disable the EPWM8 clock in sleep mode.
  * \note   This function disables the clock for the EPWM8 module by clearing the EPWM8 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM8 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm8ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM8EN_M);
}

/**
  * \brief  Enable the EPWM7 clock in sleep mode.
  * \note   This function enables the clock for the EPWM7 module by setting the EPWM7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM7 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm7ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM7EN_M);
}

/**
  * \brief  Disable the EPWM7 clock in sleep mode.
  * \note   This function disables the clock for the EPWM7 module by clearing the EPWM7 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM7 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm7ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM7EN_M);
}

/**
  * \brief  Enable the EPWM6 clock in sleep mode.
  * \note   This function enables the clock for the EPWM6 module by setting the EPWM6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM6 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM6EN_M);
}

/**
  * \brief  Disable the EPWM6 clock in sleep mode.
  * \note   This function disables the clock for the EPWM6 module by clearing the EPWM6 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM6 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM6EN_M);
}

/**
  * \brief  Enable the EPWM5 clock in sleep mode.
  * \note   This function enables the clock for the EPWM5 module by setting the EPWM5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM5 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM5EN_M);
}

/**
  * \brief  Disable the EPWM5 clock in sleep mode.
  * \note   This function disables the clock for the EPWM5 module by clearing the EPWM5 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM5 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM5EN_M);
}

/**
  * \brief  Enable the EPWM4 clock in sleep mode.
  * \note   This function enables the clock for the EPWM4 module by setting the EPWM4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM4 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM4EN_M);
}

/**
  * \brief  Disable the EPWM4 clock in sleep mode.
  * \note   This function disables the clock for the EPWM4 module by clearing the EPWM4 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM4 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM4EN_M);
}

/**
  * \brief  Enable the EPWM3 clock in sleep mode.
  * \note   This function enables the clock for the EPWM3 module by setting the EPWM3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM3 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM3EN_M);
}

/**
  * \brief  Disable the EPWM3 clock in sleep mode.
  * \note   This function disables the clock for the EPWM3 module by clearing the EPWM3 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM3 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM3EN_M);
}

/**
  * \brief  Enable the EPWM2 clock in sleep mode.
  * \note   This function enables the clock for the EPWM2 module by setting the EPWM2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM2 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM2EN_M);
}

/**
  * \brief  Disable the EPWM2 clock in sleep mode.
  * \note   This function disables the clock for the EPWM2 module by clearing the EPWM2 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM2 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM2EN_M);
}

/**
  * \brief  Enable the EPWM1 clock in sleep mode.
  * \note   This function enables the clock for the EPWM1 module by setting the EPWM1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Setting this bit allows the EPWM1 module to operate in sleep mode.
  */
static inline void RCC_enableEpwm1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM1EN_M);
}

/**
  * \brief  Disable the EPWM1 clock in sleep mode.
  * \note   This function disables the clock for the EPWM1 module by clearing the EPWM1 bit in the
  *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
  *         Clearing this bit stops the EPWM1 module from operating in sleep mode.
  */
static inline void RCC_disableEpwm1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_PCLKLPEN1_EPWM1EN_M);
}

/**
  * \brief  Enable the CMPSS11 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS11 module by setting the CMPSS11 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS11 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss11ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS11EN_M);
}

/**
  * \brief  Disable the CMPSS11 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS11 module by clearing the CMPSS11 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS11 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss11ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS11EN_M);
}

/**
  * \brief  Enable the CMPSS10 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS10 module by setting the CMPSS10 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS10 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss10ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS10EN_M);
}

/**
  * \brief  Disable the CMPSS10 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS10 module by clearing the CMPSS10 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS10 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss10ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS10EN_M);
}

/**
  * \brief  Enable the CMPSS9 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS9 module by setting the CMPSS9 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS9 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss9ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS9EN_M);
}

/**
  * \brief  Disable the CMPSS9 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS9 module by clearing the CMPSS9 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS9 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss9ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS9EN_M);
}

/**
  * \brief  Enable the CMPSS8 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS8 module by setting the CMPSS8 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS8 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss8ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS8EN_M);
}

/**
  * \brief  Disable the CMPSS8 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS8 module by clearing the CMPSS8 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS8 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss8ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS8EN_M);
}

/**
  * \brief  Enable the CMPSS7 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS7 module by setting the CMPSS7 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS7 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss7ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS7EN_M);
}

/**
  * \brief  Disable the CMPSS7 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS7 module by clearing the CMPSS7 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS7 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss7ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS7EN_M);
}

/**
  * \brief  Enable the CMPSS6 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS6 module by setting the CMPSS6 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS6 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS6EN_M);
}

/**
  * \brief  Disable the CMPSS6 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS6 module by clearing the CMPSS6 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS6 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS6EN_M);
}

/**
  * \brief  Enable the CMPSS5 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS5 module by setting the CMPSS5 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS5 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS5EN_M);
}

/**
  * \brief  Disable the CMPSS5 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS5 module by clearing the CMPSS5 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS5 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS5EN_M);
}

/**
  * \brief  Enable the CMPSS4 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS4 module by setting the CMPSS4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS4 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS4EN_M);
}

/**
  * \brief  Disable the CMPSS4 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS4 module by clearing the CMPSS4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS4 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS4EN_M);
}

/**
  * \brief  Enable the CMPSS3 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS3 module by setting the CMPSS3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS3 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS3EN_M);
}

/**
  * \brief  Disable the CMPSS3 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS3 module by clearing the CMPSS3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS3 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS3EN_M);
}

/**
  * \brief  Enable the CMPSS2 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS2 module by setting the CMPSS2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS2 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS2EN_M);
}

/**
  * \brief  Disable the CMPSS2 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS2 module by clearing the CMPSS2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS2 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS2EN_M);
}

/**
  * \brief  Enable the CMPSS1 clock in sleep mode.
  * \note   This function enables the clock for the CMPSS1 module by setting the CMPSS1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the CMPSS1 module to operate in sleep mode.
  */
static inline void RCC_enableCmpss1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS1EN_M);
}

/**
  * \brief  Disable the CMPSS1 clock in sleep mode.
  * \note   This function disables the clock for the CMPSS1 module by clearing the CMPSS1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the CMPSS1 module from operating in sleep mode.
  */
static inline void RCC_disableCmpss1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_CMPSS1EN_M);
}

/**
  * \brief  Enable the XBAR clock in sleep mode.
  * \note   This function enables the clock for the XBAR module by setting the XBAR bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the XBAR module to operate in sleep mode.
  */
static inline void RCC_enableXbarClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_XBAREN_M);
}

/**
  * \brief  Disable the XBAR clock in sleep mode.
  * \note   This function disables the clock for the XBAR module by clearing the XBAR bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the XBAR module from operating in sleep mode.
  */
static inline void RCC_disableXbarClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_XBAREN_M);
}

/**
  * \brief  Enable the ADCD clock in sleep mode.
  * \note   This function enables the clock for the ADCD module by setting the ADCD bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the ADCD module to operate in sleep mode.
  */
static inline void RCC_enableAdcdClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCDEN_M);
}

/**
  * \brief  Disable the ADCD clock in sleep mode.
  * \note   This function disables the clock for the ADCD module by clearing the ADCD bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the ADCD module from operating in sleep mode.
  */
static inline void RCC_disableAdcdClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCDEN_M);
}

/**
  * \brief  Enable the ADCC clock in sleep mode.
  * \note   This function enables the clock for the ADCC module by setting the ADCC bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the ADCC module to operate in sleep mode.
  */
static inline void RCC_enableAdccClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCCEN_M);
}

/**
  * \brief  Disable the ADCC clock in sleep mode.
  * \note   This function disables the clock for the ADCC module by clearing the ADCC bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the ADCC module from operating in sleep mode.
  */
static inline void RCC_disableAdccClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCCEN_M);
}

/**
  * \brief  Enable the ADCB clock in sleep mode.
  * \note   This function enables the clock for the ADCB module by setting the ADCB bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the ADCB module to operate in sleep mode.
  */
static inline void RCC_enableAdcbClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCBEN_M);
}

/**
  * \brief  Disable the ADCB clock in sleep mode.
  * \note   This function disables the clock for the ADCB module by clearing the ADCB bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the ADCB module from operating in sleep mode.
  */
static inline void RCC_disableAdcbClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCBEN_M);
}

/**
  * \brief  Enable the ADCA clock in sleep mode.
  * \note   This function enables the clock for the ADCA module by setting the ADCA bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the ADCA module to operate in sleep mode.
  */
static inline void RCC_enableAdcaClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCAEN_M);
}

/**
  * \brief  Disable the ADCA clock in sleep mode.
  * \note   This function disables the clock for the ADCA module by clearing the ADCA bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the ADCA module from operating in sleep mode.
  */
static inline void RCC_disableAdcaClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_ADCAEN_M);
}

/**
  * \brief  Enable the SDFM4 clock in sleep mode.
  * \note   This function enables the clock for the SDFM4 module by setting the SDFM4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the SDFM4 module to operate in sleep mode.
  */
static inline void RCC_enableSdfm4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM4EN_M);
}

/**
  * \brief  Disable the SDFM4 clock in sleep mode.
  * \note   This function disables the clock for the SDFM4 module by clearing the SDFM4 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the SDFM4 module from operating in sleep mode.
  */
static inline void RCC_disableSdfm4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM4EN_M);
}

/**
  * \brief  Enable the SDFM3 clock in sleep mode.
  * \note   This function enables the clock for the SDFM3 module by setting the SDFM3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the SDFM3 module to operate in sleep mode.
  */
static inline void RCC_enableSdfm3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM3EN_M);
}

/**
  * \brief  Disable the SDFM3 clock in sleep mode.
  * \note   This function disables the clock for the SDFM3 module by clearing the SDFM3 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the SDFM3 module from operating in sleep mode.
  */
static inline void RCC_disableSdfm3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM3EN_M);
}

/**
  * \brief  Enable the SDFM2 clock in sleep mode.
  * \note   This function enables the clock for the SDFM2 module by setting the SDFM2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the SDFM2 module to operate in sleep mode.
  */
static inline void RCC_enableSdfm2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM2EN_M);
}

/**
  * \brief  Disable the SDFM2 clock in sleep mode.
  * \note   This function disables the clock for the SDFM2 module by clearing the SDFM2 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the SDFM2 module from operating in sleep mode.
  */
static inline void RCC_disableSdfm2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM2EN_M);
}

/**
  * \brief  Enable the SDFM1 clock in sleep mode.
  * \note   This function enables the clock for the SDFM1 module by setting the SDFM1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Setting this bit allows the SDFM1 module to operate in sleep mode.
  */
static inline void RCC_enableSdfm1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM1EN_M);
}

/**
  * \brief  Disable the SDFM1 clock in sleep mode.
  * \note   This function disables the clock for the SDFM1 module by clearing the SDFM1 bit in the
  *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
  *         Clearing this bit stops the SDFM1 module from operating in sleep mode.
  */
static inline void RCC_disableSdfm1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_PCLKLPEN2_SDFM1EN_M);
}

/**
  * \brief  Enable the ANALOGSS clock in sleep mode.
  * \note   This function enables the clock for the ANALOGSS module by setting the ANALOGSS bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
  *         Setting this bit allows the ANALOGSS module to operate in sleep mode.
  */
static inline void RCC_enableAnalogssClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_PCLKLPEN3_ANALOGSS_M);
}

/**
  * \brief  Disable the ANALOGSS clock in sleep mode.
  * \note   This function disables the clock for the ANALOGSS module by clearing the ANALOGSS bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
  *         Clearing this bit stops the ANALOGSS module from operating in sleep mode.
  */
static inline void RCC_disableAnalogssClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_PCLKLPEN3_ANALOGSS_M);
}

/**
  * \brief  Enable the DAC3 clock in sleep mode.
  * \note   This function enables the clock for the DAC3 module by setting the DAC3 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
  *         Setting this bit allows the DAC3 module to operate in sleep mode.
  */
static inline void RCC_enableDac3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_PCLKLPEN3_DAC3EN_M);
}

/**
  * \brief  Disable the DAC3 clock in sleep mode.
  * \note   This function disables the clock for the DAC3 module by clearing the DAC3 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
  *         Clearing this bit stops the DAC3 module from operating in sleep mode.
  */
static inline void RCC_disableDac3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_PCLKLPEN3_DAC3EN_M);
}

/**
  * \brief  Enable the DAC1 clock in sleep mode.
  * \note   This function enables the clock for the DAC1 module by setting the DAC1 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
  *         Setting this bit allows the DAC1 module to operate in sleep mode.
  */
static inline void RCC_enableDac1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_PCLKLPEN3_DAC1EN_M);
}

/**
  * \brief  Disable the DAC1 clock in sleep mode.
  * \note   This function disables the clock for the DAC1 module by clearing the DAC1 bit in the
  *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
  *         Clearing this bit stops the DAC1 module from operating in sleep mode.
  */
static inline void RCC_disableDac1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_PCLKLPEN3_DAC1EN_M);
}

/**
  * \brief  Enable the DCC1 clock in sleep mode.
  * \note   This function enables the clock for the DCC1 module by setting the DCC1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the DCC1 module to operate in sleep mode.
  */
static inline void RCC_enableDcc1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_DCC1EN_M);
}

/**
  * \brief  Disable the DCC1 clock in sleep mode.
  * \note   This function disables the clock for the DCC1 module by clearing the DCC1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the DCC1 module from operating in sleep mode.
  */
static inline void RCC_disableDcc1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_DCC1EN_M);
}

/**
  * \brief  Enable the CPUxWWDG clock in sleep mode.
  * \note   This function enables the clock for the CPUxWWDG module by setting the CPUxWWDG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the CPUxWWDG module to operate in sleep mode.
  */
static inline void RCC_enableCpuxWwdgClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_CPUXWWDGEN_M);
}

/**
  * \brief  Disable the CPUxWWDG clock in sleep mode.
  * \note   This function disables the clock for the CPUxWWDG module by clearing the CPUxWWDG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the CPUxWWDG module from operating in sleep mode.
  */
static inline void RCC_disableCpuxWwdgClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_CPUXWWDGEN_M);
}

/**
  * \brief  Enable the EPG clock in sleep mode.
  * \note   This function enables the clock for the EPG module by setting the EPG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the EPG module to operate in sleep mode.
  */
static inline void RCC_enableEpgClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_EPGEN_M);
}

/**
  * \brief  Disable the EPG clock in sleep mode.
  * \note   This function disables the clock for the EPG module by clearing the EPG bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the EPG module from operating in sleep mode.
  */
static inline void RCC_disableEpgClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_EPGEN_M);
}

/**
  * \brief  Enable the PMBUS clock in sleep mode.
  * \note   This function enables the clock for the PMBUS module by setting the PMBUS bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the PMBUS module to operate in sleep mode.
  */
static inline void RCC_enablePmbusClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_PMBUSEN_M);
}

/**
  * \brief  Disable the PMBUS clock in sleep mode.
  * \note   This function disables the clock for the PMBUS module by clearing the PMBUS bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the PMBUS module from operating in sleep mode.
  */
static inline void RCC_disablePmbusClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_PMBUSEN_M);
}

/**
  * \brief  Enable the I2C2 clock in sleep mode.
  * \note   This function enables the clock for the I2C2 module by setting the I2C2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the I2C2 module to operate in sleep mode.
  */
static inline void RCC_enableI2c2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_I2C2EN_M);
}

/**
  * \brief  Disable the I2C2 clock in sleep mode.
  * \note   This function disables the clock for the I2C2 module by clearing the I2C2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the I2C2 module from operating in sleep mode.
  */
static inline void RCC_disableI2c2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_I2C2EN_M);
}

/**
  * \brief  Enable the I2C1 clock in sleep mode.
  * \note   This function enables the clock for the I2C1 module by setting the I2C1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the I2C1 module to operate in sleep mode.
  */
static inline void RCC_enableI2c1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_I2C1EN_M);
}

/**
  * \brief  Disable the I2C1 clock in sleep mode.
  * \note   This function disables the clock for the I2C1 module by clearing the I2C1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the I2C1 module from operating in sleep mode.
  */
static inline void RCC_disableI2c1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_I2C1EN_M);
}

/**
  * \brief  Enable the SPI4 clock in sleep mode.
  * \note   This function enables the clock for the SPI4 module by setting the SPI4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the SPI4 module to operate in sleep mode.
  */
static inline void RCC_enableSpi4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI4EN_M);
}

/**
  * \brief  Disable the SPI4 clock in sleep mode.
  * \note   This function disables the clock for the SPI4 module by clearing the SPI4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the SPI4 module from operating in sleep mode.
  */
static inline void RCC_disableSpi4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI4EN_M);
}

/**
  * \brief  Enable the SPI3 clock in sleep mode.
  * \note   This function enables the clock for the SPI3 module by setting the SPI3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the SPI3 module to operate in sleep mode.
  */
static inline void RCC_enableSpi3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI3EN_M);
}

/**
  * \brief  Disable the SPI3 clock in sleep mode.
  * \note   This function disables the clock for the SPI3 module by clearing the SPI3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the SPI3 module from operating in sleep mode.
  */
static inline void RCC_disableSpi3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI3EN_M);
}

/**
  * \brief  Enable the SPI2 clock in sleep mode.
  * \note   This function enables the clock for the SPI2 module by setting the SPI2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the SPI2 module to operate in sleep mode.
  */
static inline void RCC_enableSpi2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI2EN_M);
}

/**
  * \brief  Disable the SPI2 clock in sleep mode.
  * \note   This function disables the clock for the SPI2 module by clearing the SPI2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the SPI2 module from operating in sleep mode.
  */
static inline void RCC_disableSpi2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI2EN_M);
}

/**
  * \brief  Enable the SPI1 clock in sleep mode.
  * \note   This function enables the clock for the SPI1 module by setting the SPI1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the SPI1 module to operate in sleep mode.
  */
static inline void RCC_enableSpi1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI1EN_M);
}

/**
  * \brief  Disable the SPI1 clock in sleep mode.
  * \note   This function disables the clock for the SPI1 module by clearing the SPI1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the SPI1 module from operating in sleep mode.
  */
static inline void RCC_disableSpi1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_SPI1EN_M);
}

/**
  * \brief  Enable the UART4 clock in sleep mode.
  * \note   This function enables the clock for the UART4 module by setting the UART4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the UART4 module to operate in sleep mode.
  */
static inline void RCC_enableUart4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART4EN_M);
}

/**
  * \brief  Disable the UART4 clock in sleep mode.
  * \note   This function disables the clock for the UART4 module by clearing the UART4 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the UART4 module from operating in sleep mode.
  */
static inline void RCC_disableUart4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART4EN_M);
}

/**
  * \brief  Enable the UART3 clock in sleep mode.
  * \note   This function enables the clock for the UART3 module by setting the UART3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the UART3 module to operate in sleep mode.
  */
static inline void RCC_enableUart3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART3EN_M);
}

/**
  * \brief  Disable the UART3 clock in sleep mode.
  * \note   This function disables the clock for the UART3 module by clearing the UART3 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the UART3 module from operating in sleep mode.
  */
static inline void RCC_disableUart3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART3EN_M);
}

/**
  * \brief  Enable the UART2 clock in sleep mode.
  * \note   This function enables the clock for the UART2 module by setting the UART2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the UART2 module to operate in sleep mode.
  */
static inline void RCC_enableUart2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART2EN_M);
}

/**
  * \brief  Disable the UART2 clock in sleep mode.
  * \note   This function disables the clock for the UART2 module by clearing the UART2 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the UART2 module from operating in sleep mode.
  */
static inline void RCC_disableUart2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART2EN_M);
}

/**
  * \brief  Enable the UART1 clock in sleep mode.
  * \note   This function enables the clock for the UART1 module by setting the UART1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Setting this bit allows the UART1 module to operate in sleep mode.
  */
static inline void RCC_enableUart1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART1EN_M);
}

/**
  * \brief  Disable the UART1 clock in sleep mode.
  * \note   This function disables the clock for the UART1 module by clearing the UART1 bit in the
  *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
  *         Clearing this bit stops the UART1 module from operating in sleep mode.
  */
static inline void RCC_disableUart1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_PCLKLPEN5_UART1EN_M);
}

/**
  * \brief  Enable the DCC3 clock in sleep mode.
  * \note   This function enables the clock for the DCC3 module by setting the DCC3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the DCC3 module to operate in sleep mode.
  */
static inline void RCC_enableDcc3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_DCC3EN_M);
}

/**
  * \brief  Disable the DCC3 clock in sleep mode.
  * \note   This function disables the clock for the DCC3 module by clearing the DCC3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the DCC3 module from operating in sleep mode.
  */
static inline void RCC_disableDcc3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_DCC3EN_M);
}

/**
  * \brief  Enable the DCC2 clock in sleep mode.
  * \note   This function enables the clock for the DCC2 module by setting the DCC2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the DCC2 module to operate in sleep mode.
  */
static inline void RCC_enableDcc2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_DCC2EN_M);
}

/**
  * \brief  Disable the DCC2 clock in sleep mode.
  * \note   This function disables the clock for the DCC2 module by clearing the DCC2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the DCC2 module from operating in sleep mode.
  */
static inline void RCC_disableDcc2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_DCC2EN_M);
}

/**
  * \brief  Enable the BTIM2 clock in sleep mode.
  * \note   This function enables the clock for the BTIM2 module by setting the BTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the BTIM2 module to operate in sleep mode.
  */
static inline void RCC_enableBtim2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_BTIM2EN_M);
}

/**
  * \brief  Disable the BTIM2 clock in sleep mode.
  * \note   This function disables the clock for the BTIM2 module by clearing the BTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the BTIM2 module from operating in sleep mode.
  */
static inline void RCC_disableBtim2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_BTIM2EN_M);
}

/**
  * \brief  Enable the BTIM1 clock in sleep mode.
  * \note   This function enables the clock for the BTIM1 module by setting the BTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the BTIM1 module to operate in sleep mode.
  */
static inline void RCC_enableBtim1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_BTIM1EN_M);
}

/**
  * \brief  Disable the BTIM1 clock in sleep mode.
  * \note   This function disables the clock for the BTIM1 module by clearing the BTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the BTIM1 module from operating in sleep mode.
  */
static inline void RCC_disableBtim1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_BTIM1EN_M);
}

/**
  * \brief  Enable the CPUxSTIM3 clock in sleep mode.
  * \note   This function enables the clock for the CPUxSTIM3 module by setting the CPUxSTIM3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CPUxSTIM3 module to operate in sleep mode.
  */
static inline void RCC_enableCpuxStim3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CPUXSTIM3EN_M);
}

/**
  * \brief  Disable the CPUxSTIM3 clock in sleep mode.
  * \note   This function disables the clock for the CPUxSTIM3 module by clearing the CPUxSTIM3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CPUxSTIM3 module from operating in sleep mode.
  */
static inline void RCC_disableCpuxStim3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CPUXSTIM3EN_M);
}

/**
  * \brief  Enable the CPUxSTIM2 clock in sleep mode.
  * \note   This function enables the clock for the CPUxSTIM2 module by setting the CPUxSTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CPUxSTIM2 module to operate in sleep mode.
  */
static inline void RCC_enableCpuxStim2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CPUXSTIM2EN_M);
}

/**
  * \brief  Disable the CPUxSTIM2 clock in sleep mode.
  * \note   This function disables the clock for the CPUxSTIM2 module by clearing the CPUxSTIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CPUxSTIM2 module from operating in sleep mode.
  */
static inline void RCC_disableCpuxStim2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CPUXSTIM2EN_M);
}

/**
  * \brief  Enable the CPUxSTIM1 clock in sleep mode.
  * \note   This function enables the clock for the CPUxSTIM1 module by setting the CPUxSTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CPUxSTIM1 module to operate in sleep mode.
  */
static inline void RCC_enableCpuxStim1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CPUXSTIM1EN_M);
}

/**
  * \brief  Disable the CPUxSTIM1 clock in sleep mode.
  * \note   This function disables the clock for the CPUxSTIM1 module by clearing the CPUxSTIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CPUxSTIM1 module from operating in sleep mode.
  */
static inline void RCC_disableCpuxStim1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CPUXSTIM1EN_M);
}

/**
  * \brief  Enable the CLB6 clock in sleep mode.
  * \note   This function enables the clock for the CLB6 module by setting the CLB6 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CLB6 module to operate in sleep mode.
  */
static inline void RCC_enableClb6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB6EN_M);
}

/**
  * \brief  Disable the CLB6 clock in sleep mode.
  * \note   This function disables the clock for the CLB6 module by clearing the CLB6 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CLB6 module from operating in sleep mode.
  */
static inline void RCC_disableClb6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB6EN_M);
}

/**
  * \brief  Enable the CLB5 clock in sleep mode.
  * \note   This function enables the clock for the CLB5 module by setting the CLB5 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CLB5 module to operate in sleep mode.
  */
static inline void RCC_enableClb5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB5EN_M);
}

/**
  * \brief  Disable the CLB5 clock in sleep mode.
  * \note   This function disables the clock for the CLB5 module by clearing the CLB5 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CLB5 module from operating in sleep mode.
  */
static inline void RCC_disableClb5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB5EN_M);
}

/**
  * \brief  Enable the CLB4 clock in sleep mode.
  * \note   This function enables the clock for the CLB4 module by setting the CLB4 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CLB4 module to operate in sleep mode.
  */
static inline void RCC_enableClb4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB4EN_M);
}

/**
  * \brief  Disable the CLB4 clock in sleep mode.
  * \note   This function disables the clock for the CLB4 module by clearing the CLB4 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CLB4 module from operating in sleep mode.
  */
static inline void RCC_disableClb4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB4EN_M);
}

/**
  * \brief  Enable the CLB3 clock in sleep mode.
  * \note   This function enables the clock for the CLB3 module by setting the CLB3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CLB3 module to operate in sleep mode.
  */
static inline void RCC_enableClb3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB3EN_M);
}

/**
  * \brief  Disable the CLB3 clock in sleep mode.
  * \note   This function disables the clock for the CLB3 module by clearing the CLB3 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CLB3 module from operating in sleep mode.
  */
static inline void RCC_disableClb3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB3EN_M);
}

/**
  * \brief  Enable the CLB2 clock in sleep mode.
  * \note   This function enables the clock for the CLB2 module by setting the CLB2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CLB2 module to operate in sleep mode.
  */
static inline void RCC_enableClb2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB2EN_M);
}

/**
  * \brief  Disable the CLB2 clock in sleep mode.
  * \note   This function disables the clock for the CLB2 module by clearing the CLB2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CLB2 module from operating in sleep mode.
  */
static inline void RCC_disableClb2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB2EN_M);
}

/**
  * \brief  Enable the CLB1 clock in sleep mode.
  * \note   This function enables the clock for the CLB1 module by setting the CLB1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the CLB1 module to operate in sleep mode.
  */
static inline void RCC_enableClb1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB1EN_M);
}

/**
  * \brief  Disable the CLB1 clock in sleep mode.
  * \note   This function disables the clock for the CLB1 module by clearing the CLB1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the CLB1 module from operating in sleep mode.
  */
static inline void RCC_disableClb1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_CLB1EN_M);
}

/**
  * \brief  Enable the TIM2 clock in sleep mode.
  * \note   This function enables the clock for the TIM2 module by setting the TIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the TIM2 module to operate in sleep mode.
  */
static inline void RCC_enableTim2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_TIM2EN_M);
}

/**
  * \brief  Disable the TIM2 clock in sleep mode.
  * \note   This function disables the clock for the TIM2 module by clearing the TIM2 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the TIM2 module from operating in sleep mode.
  */
static inline void RCC_disableTim2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_TIM2EN_M);
}

/**
  * \brief  Enable the TIM1 clock in sleep mode.
  * \note   This function enables the clock for the TIM1 module by setting the TIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Setting this bit allows the TIM1 module to operate in sleep mode.
  */
static inline void RCC_enableTim1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_TIM1EN_M);
}

/**
  * \brief  Disable the TIM1 clock in sleep mode.
  * \note   This function disables the clock for the TIM1 module by clearing the TIM1 bit in the
  *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
  *         Clearing this bit stops the TIM1 module from operating in sleep mode.
  */
static inline void RCC_disableTim1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_PCLKLPEN6_TIM1EN_M);
}

/**
  * \brief  Enable the ADCAGG2 clock in sleep mode.
  * \note   This function enables the clock for the ADCAGG2 module by setting the ADCAGG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCAGG2 module to operate in sleep mode.
  */
static inline void RCC_enableAdcAgg2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCAGG2EN_M);
}

/**
  * \brief  Disable the ADCAGG2 clock in sleep mode.
  * \note   This function disables the clock for the ADCAGG2 module by clearing the ADCAGG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCAGG2 module from operating in sleep mode.
  */
static inline void RCC_disableAdcAgg2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCAGG2EN_M);
}

/**
  * \brief  Enable the ADCAGG1 clock in sleep mode.
  * \note   This function enables the clock for the ADCAGG1 module by setting the ADCAGG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCAGG1 module to operate in sleep mode.
  */
static inline void RCC_enableAdcAgg1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCAGG1EN_M);
}

/**
  * \brief  Disable the ADCAGG1 clock in sleep mode.
  * \note   This function disables the clock for the ADCAGG1 module by clearing the ADCAGG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCAGG1 module from operating in sleep mode.
  */
static inline void RCC_disableAdcAgg1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCAGG1EN_M);
}

/**
  * \brief  Enable the ADCCHK8 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK8 module by setting the ADCCHK8 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK8 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk8ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK8EN_M);
}

/**
  * \brief  Disable the ADCCHK8 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK8 module by clearing the ADCCHK8 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK8 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk8ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK8EN_M);
}

/**
  * \brief  Enable the ADCCHK7 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK7 module by setting the ADCCHK7 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK7 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk7ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK7EN_M);
}

/**
  * \brief  Disable the ADCCHK7 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK7 module by clearing the ADCCHK7 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK7 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk7ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK7EN_M);
}

/**
  * \brief  Enable the ADCCHK6 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK6 module by setting the ADCCHK6 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK6 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK6EN_M);
}

/**
  * \brief  Disable the ADCCHK6 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK6 module by clearing the ADCCHK6 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK6 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK6EN_M);
}

/**
  * \brief  Enable the ADCCHK5 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK5 module by setting the ADCCHK5 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK5 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK5EN_M);
}

/**
  * \brief  Disable the ADCCHK5 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK5 module by clearing the ADCCHK5 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK5 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK5EN_M);
}

/**
  * \brief  Enable the ADCCHK4 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK4 module by setting the ADCCHK4 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK4 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK4EN_M);
}

/**
  * \brief  Disable the ADCCHK4 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK4 module by clearing the ADCCHK4 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK4 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK4EN_M);
}

/**
  * \brief  Enable the ADCCHK3 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK3 module by setting the ADCCHK3 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK3 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK3EN_M);
}

/**
  * \brief  Disable the ADCCHK3 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK3 module by clearing the ADCCHK3 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK3 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK3EN_M);
}

/**
  * \brief  Enable the ADCCHK2 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK2 module by setting the ADCCHK2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK2 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK2EN_M);
}

/**
  * \brief  Disable the ADCCHK2 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK2 module by clearing the ADCCHK2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK2 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK2EN_M);
}

/**
  * \brief  Enable the ADCCHK1 clock in sleep mode.
  * \note   This function enables the clock for the ADCCHK1 module by setting the ADCCHK1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the ADCCHK1 module to operate in sleep mode.
  */
static inline void RCC_enableAdcChk1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK1EN_M);
}

/**
  * \brief  Disable the ADCCHK1 clock in sleep mode.
  * \note   This function disables the clock for the ADCCHK1 module by clearing the ADCCHK1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the ADCCHK1 module from operating in sleep mode.
  */
static inline void RCC_disableAdcChk1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_ADCCHK1EN_M);
}

/**
  * \brief  Enable the AWK clock in sleep mode.
  * \note   This function enables the clock for the AWK module by setting the AWK bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the AWK module to operate in sleep mode.
  */
static inline void RCC_enableAwkClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_AWKEN_M);
}

/**
  * \brief  Disable the AWK clock in sleep mode.
  * \note   This function disables the clock for the AWK module by clearing the AWK bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the AWK module from operating in sleep mode.
  */
static inline void RCC_disableAwkClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_AWKEN_M);
}

/**
  * \brief  Enable the LPTIM clock in sleep mode.
  * \note   This function enables the clock for the LPTIM module by setting the LPTIM bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the LPTIM module to operate in sleep mode.
  */
static inline void RCC_enableLptimClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_LPTIMEN_M);
}

/**
  * \brief  Disable the LPTIM clock in sleep mode.
  * \note   This function disables the clock for the LPTIM module by clearing the LPTIM bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the LPTIM module from operating in sleep mode.
  */
static inline void RCC_disableLptimClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_LPTIMEN_M);
}

/**
  * \brief  Enable the IWDG2 clock in sleep mode.
  * \note   This function enables the clock for the IWDG2 module by setting the IWDG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the IWDG2 module to operate in sleep mode.
  */
static inline void RCC_enableIwdg2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_IWDG2EN_M);
}

/**
  * \brief  Disable the IWDG2 clock in sleep mode.
  * \note   This function disables the clock for the IWDG2 module by clearing the IWDG2 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the IWDG2 module from operating in sleep mode.
  */
static inline void RCC_disableIwdg2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_IWDG2EN_M);
}

/**
  * \brief  Enable the CPUxIWDG1 clock in sleep mode.
  * \note   This function enables the clock for the CPUxIWDG1 module by setting the CPUxIWDG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the CPUxIWDG1 module to operate in sleep mode.
  */
static inline void RCC_enableCpuxIwdg1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_CPUXIWDG1EN_M);
}

/**
  * \brief  Disable the CPUxIWDG1 clock in sleep mode.
  * \note   This function disables the clock for the CPUxIWDG1 module by clearing the CPUxIWDG1 bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the CPUxIWDG1 module from operating in sleep mode.
  */
static inline void RCC_disableCpuxIwdg1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_CPUXIWDG1EN_M);
}

/**
  * \brief  Enable the PWR clock in sleep mode.
  * \note   This function enables the clock for the PWR module by setting the PWR bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Setting this bit allows the PWR module to operate in sleep mode.
  */
static inline void RCC_enablePwrClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_PWREN_M);
}

/**
  * \brief  Disable the PWR clock in sleep mode.
  * \note   This function disables the clock for the PWR module by clearing the PWR bit in the
  *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
  *         Clearing this bit stops the PWR module from operating in sleep mode.
  */
static inline void RCC_disablePwrClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_PCLKLPEN8_PWREN_M);
}

/**
  * \brief  Select the HXTL AWK Clock Division Factor
  * \note   This function selects the division factor for the HXTL AWK clock by modifying
  *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
  * \param  hxtlAwkDiv  Specifies the division factor for the HXTL AWK clock.
  *                      This parameter can be any value of @ref RCC_HXTLAWKDIVSELECTION
  */
static inline void RCC_selectHxtlAwkDiv (RCC_HxtlAwkDivSelection hxtlAwkDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_CFGR2_HXTLAWKDIV_M, (hxtlAwkDiv << RCC_CFGR2_HXTLAWKDIV_S));
}

/**
  * \brief  Get the Division Factor for HXTLAWK Clock
  * \note   This function retrieves the division factor for the HXTLAWK clock by reading
  *         the HXTLAWKDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
  * \return The division factor for the HXTLAWK clock.
  *         This value corresponds to one of the definitions in @ref RCC_HXTLAWKDIVSELECTION
  */
static inline RCC_HxtlAwkDivSelection RCC_getHxtlAwkDiv (void)
{
    return (RCC_HxtlAwkDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_HXTLAWKDIV_M) >> RCC_CFGR2_HXTLAWKDIV_S);
}

/**
  * \brief  Enable the EPWMCLKDIV.
  * \note   This function enables the clock for the PWR module by setting the EPWMCLKDIV bit in the
  *         RCC APB Clock Enable Register 8 (RCC->CFGR2).
  *         Setting this bit allows the EPWM module to Enable the Clock frequency division.
  */
static inline void RCC_enableEpwmClkDiv (void)
{
    SET_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_EPWMCLKDIV_M);
}

/**
  * \brief  Disable the EPWMCLKDIV.
  * \note   This function Disables the clock for the PWR module by setting the EPWMCLKDIV bit in the
  *         RCC APB Clock Disable Register 8 (RCC->CFGR2).
  *         Setting this bit allows the EPWM module to Disable the Clock frequency division.
  */
static inline void RCC_DisableEpwmClkDiv (void)
{
    CLEAR_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_EPWMCLKDIV_M);
}

/**
  * \brief  Select the EMIF Clock Division Factor
  * \note   This function selects the division factor for the EMIF clock by modifying
  *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
  * \param  EmifClockDiv  Specifies the division factor for the EMIF clock.
  *                         This parameter can be any value of @ref RCC_EMIFCLOCKDIVSELECTION
  */
static inline void RCC_selectEmifClockDiv (RCC_EmifClockDivSelection EmifClockDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_CFGR2_EMIFDIV_M, (EmifClockDiv << RCC_CFGR2_EMIFDIV_S));
}

/**
  * \brief  Get the Division Factor for EMIF Clock
  * \note   This function retrieves the division factor for the EMIF clock by reading
  *         the EMIFDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
  * \return The division factor for the EMIF clock.
  *         This value corresponds to one of the definitions in @ref RCC_EMIFCLOCKDIVSELECTION
  */
static inline RCC_EmifClockDivSelection RCC_getEmifClockDiv (void)
{
    return (RCC_EmifClockDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_EMIFDIV_M) >> RCC_CFGR2_EMIFDIV_S);
}

/**
  * \brief  Select the Trace Clock Division Factor
  * \note   This function selects the division factor for the trace clock by modifying
  *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
  * \param  traceClockDiv  Specifies the division factor for the trace clock.
  *                         This parameter can be any value of @ref RCC_TRACECLOCKDIVSELECTION
  */
static inline void RCC_selectTraceClockDiv (RCC_TraceClockDivSelection traceClockDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_CFGR2_TRACEDIV_M, (traceClockDiv << RCC_CFGR2_TRACEDIV_S));
}

/**
  * \brief  Get the Division Factor for Trace Clock
  * \note   This function retrieves the division factor for the Trace clock by reading
  *         the TRACEDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
  * \return The division factor for the Trace clock.
  *         This value corresponds to one of the definitions in @ref RCC_TRACECLOCKDIVSELECTION
  */
static inline RCC_TraceClockDivSelection RCC_getTraceClockDiv (void)
{
    return (RCC_TraceClockDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_TRACEDIV_M) >> RCC_CFGR2_TRACEDIV_S);
}

/**
  * \brief  Select the Flash Clock Division Factor
  * \note   This function selects the division factor for the flash clock by modifying
  *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
  * \param  flashClockDiv  Specifies the division factor for the flash clock.
  *                         This parameter can be any value of @ref RCC_FLASHCLOCKDIVSELECTION
  */
static inline void RCC_selectFlashClockDiv (RCC_FlashClockDivSelection flashClockDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_CFGR2_FLASHDIV_M, flashClockDiv);
}

/**
  * \brief  Get the Division Factor for Flash Clock
  * \note   This function retrieves the division factor for the Flash clock by reading
  *         the FLASHDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
  * \return The division factor for the Flash clock.
  *         This value corresponds to one of the definitions in @ref RCC_FLASHCLOCKDIVSELECTION
  */
static inline RCC_FlashClockDivSelection RCC_getFlashClockDiv (void)
{
    return (RCC_FlashClockDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_CFGR2_FLASHDIV_M));
}

/**
  * \brief  Select the PLL Loop Filter Cap Configuration
  * \note   This function configures the PLL loop filter cap by modifying the appropriate bits in the PLLCR4 register.
  *         It applies a key value for security purposes.
  * \param  pllloopFilterCapSel    Specifies the debug control configuration.
  *                                 This parameter can be any value of @ref RCC_PLLLOOPFILTERCAPSELECTION
  */
static inline void RCC_selectPllLoopFilterCap (RCC_PllLoopFilterCapSelection pllloopFilterCapSel)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_PLLCR4_FLTCAP_M, 
               ((pllloopFilterCapSel << RCC_PLLCR4_FLTCAP_S) | RCC_PLLCR4_KEY));
}

/**
  * \brief  Select the PLL Charge Pump Current Configuration
  * \note   This function configures the PLL charge pump current by modifying the appropriate bits in the PLLCR4 register.
  *         It applies a key value for security purposes.
  * \param  pllChargePumpCurrentSel    Specifies the charge pump current configuration.
  *                                     This parameter can be any value of @ref RCC_PLLCHARGEPUMPCURRENTSELECTION
  */
static inline void RCC_selectPllChargePumpCurrent (RCC_PllChargePumpCurrentSelection pllChargePumpCurrentSel)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_PLLCR4_ICPSEL_M, 
               ((pllChargePumpCurrentSel << RCC_PLLCR4_ICPSEL_S) | RCC_PLLCR4_KEY));
}

/**
  * \brief  Select the PLL Loop Filter Resistor Configuration
  * \note   This function configures the PLL loop filter resistor by modifying the appropriate bits in the PLLCR4 register.
  *         It applies a key value for security purposes.
  * \param  pllLoopFilterResSel    Specifies the loop filter resistor configuration.
  *                                 This parameter can be any value of @ref RCC_PLLLOOPFILTERRESSELECTION
  */
static inline void RCC_selectPllLoopFilterRes (RCC_PllLoopFilterResSelection pllLoopFilterResSel)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_PLLCR4_FLTRES_M, 
              ((pllLoopFilterResSel << RCC_PLLCR4_FLTRES_S) | RCC_PLLCR4_KEY));
}

/**
  * \brief  Select the PLL VCO Frequency Range Configuration
  * \note   This function configures the PLL VCO (Voltage Controlled Oscillator) frequency range by modifying 
  *         the appropriate bits in the PLLCR4 register. It applies a key value for security purposes.
  * \param  pllVcoFrequencySel    Specifies the PLL VCO frequency range configuration.
  *                                This parameter can be any value of @ref RCC_PLLVCOFREQUENCYSELECTION
  */
static inline void RCC_selectPllVcoRange (RCC_PllVcoFrequencySelection pllVcoFrequencySel)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_PLLCR4_VCORNG_M, (pllVcoFrequencySel | RCC_PLLCR4_KEY));
}

/**
  * \brief  Configure the MIRC1 Trim Value
  * \note   This function configures the trim value for the MIRC1 (Internal High-Speed RC Oscillator)
  *         by modifying the appropriate bits in the MIRC1CR register (RCC->MIRC1CR).
  *         It applies a key value for security purposes.
  * \param  mirc1TrimValue    Specifies the trim value for the MIRC1.
  *                            This parameter can be any value in the range 0 to 0x1FF.
  */
static inline void RCC_configMirc1Trim (uint16_t mirc1TrimValue)
{
    WRITE_REG(RCC->MIRC1CR.WORDVAL, (mirc1TrimValue | RCC_MIRC1CR_KEY));
}

/**
  * \brief  Configure the MIRC2 Trim Value
  * \note   This function configures the trim value for the MIRC2 (Internal High-Speed RC Oscillator)
  *         by modifying the appropriate bits in the MIRC2CR register (RCC->MIRC2CR).
  *         It applies a key value for security purposes.
  * \param  mirc2TrimValue    Specifies the trim value for the MIRC2.
  *                            This parameter can be any value in the range 0 to 0x1FF.
  */
static inline void RCC_configMirc2Trim (uint16_t mirc2TrimValue)
{
    WRITE_REG(RCC->MIRC2CR.WORDVAL, (mirc2TrimValue | RCC_MIRC2CR_KEY));
}

/**
  * \brief  Enable the HXTL Filter
  * \note   This function enables the HXTL (High-Speed External Crystal Oscillator) filter
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_enableHxtlFilter (void)
{
    SET_BIT(RCC->HXTLCR.WORDVAL, (RCC_HXTLCR_FLTEN_M | RCC_HXTLCR_KEY));
}

/**
  * \brief  Disable the HXTL Filter
  * \note   This function disables the HXTL (High-Speed External Crystal Oscillator) filter
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_disableHxtlFilter (void)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLCR_FLTEN_M, RCC_HXTLCR_KEY);
}

/**
  * \brief  Select the HXTL Feedback Resistance Setting
  * \note   This function selects the Feedback Resistance setting for the HXTL (High-Speed External Crystal Oscillator)
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  * \param  hxtlFeedbackResSel    Specifies the feedback resistance setting for the HXTL.
  *                                This parameter can be any value of @ref RCC_HXTLFEEDBACKRESSELECTION
  */
static inline void RCC_selectHxtlFeedbackRes (RCC_HxtlFeedbackResSelection hxtlFeedbackResSel)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLCR_RFSEL_M, 
               ((hxtlFeedbackResSel << RCC_HXTLCR_RFSEL_S) | RCC_HXTLCR_KEY));
}

/**
  * \brief  Enable the HXTL Feedback Resistance
  * \note   This function enables the Feedback for the HXTL (High-Speed External Crystal Oscillator)
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_enableHxtlFeedbackRes (void)
{
    SET_BIT(RCC->HXTLCR.WORDVAL, (RCC_HXTLCR_RFEN_M | RCC_HXTLCR_KEY));
}

/**
  * \brief  Disable the HXTL Feedback Resistance
  * \note   This function disables the RF for the HXTL (High-Speed External Crystal Oscillator)
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_disableHxtlFeedbackRes (void)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLCR_RFEN_M, RCC_HXTLCR_KEY);
}

/**
  * \brief  Select the HXTL Startup Time
  * \note   This function selects the startup time for the HXTL (High-Speed External Crystal Oscillator)
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  * \param  hxtlStartupSel    Specifies the startup time setting for the HXTL.
  *                            This parameter can be any value of @ref RCC_HXTLSTARTUPSELECTION
  */
static inline void RCC_selectHxtlStartupTime (RCC_HxtlStartupSelection hxtlStartupSel)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLCR_STARTUP_M, 
               ((hxtlStartupSel << RCC_HXTLCR_STARTUP_S) | RCC_HXTLCR_KEY));
}

/**
  * \brief  Select the HXTL Driver Setting
  * \note   This function selects the driver setting for the HXTL (High-Speed External Crystal Oscillator)
  *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
  *         It applies a key value for security purposes.
  * \param  hxtlDriverSel    Specifies the driver setting for the HXTL.
  *                           This parameter can be any value of @ref RCC_HXTLMFSELECTION
  */
static inline void RCC_selectHxtlDriver (RCC_HxtlDriverSelection hxtlDriverSel)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLCR_MODE_M, (hxtlDriverSel | RCC_HXTLCR_KEY));
}

/**
  * \brief  Select the MIRC Cycle detection Setting
  * \note   This function selects the cycle setting between MIRC1 and MIRC2
  *         by modifying the appropriate bits in the MCDCR register (RCC->MCDCR).
  *         It applies a key value for security purposes.
  * \param  mcdMircCycleSel    Specifies the cycle setting between MIRC1 and MIRC2.
  *                             This parameter can be any value of @ref RCC_MCDMIRCCYCLESELECTION
  */
static inline void RCC_selectMcdMircCycle (RCC_McdMircCycleSelection mcdMircCycleSel)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDPRD_M, 
               ((mcdMircCycleSel << RCC_MCDCR_MCDPRD_S) | RCC_MCDCR_KEY));
}

/**
  * \brief  Enable MCD Interrupt
  * \note   This function enables the interrupt for the Main Clock Domain (MCD)
  *         by setting the appropriate bit in the MCDCR register (RCC->MCDCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_enableMcdInt (void)
{
    SET_BIT(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDIE_M | RCC_MCDCR_KEY);
}

/**
  * \brief  Disable MCD Interrupt
  * \note   This function disables the interrupt for the Main Clock Domain (MCD)
  *         by clearing the appropriate bit in the MCDCR register (RCC->MCDCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_disableMcdInt (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDIE_M, RCC_MCDCR_KEY);
}

/**
  * \brief  Clear MCD Interrupt Flag
  * \note   This function clears the interrupt flag for the Main Clock Domain (MCD)
  *         by setting the appropriate bit in the MCDCR register (RCC->MCDCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_clearMcdIntFlag (void)
{
    SET_BIT(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDCLR_M | RCC_MCDCR_KEY);
}

/**
  * \brief  Read the MCD Interrupt Flag.
  * \note   This function checks the MCD interrupt flag bit in the MCDCR register (RCC->MCDCR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the MCD Interrupt Flag.
  *         - 0: The MCD Interrupt Flag is not set.
  *         - 1: The MCD Interrupt Flag is set.
  */
static inline uint32_t RCC_readMcdIntFlag (void)
{
    return READ_BIT(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDFLG_M) ? 1UL : 0UL;
}

/**
 * \brief  Select the MCD Interrupt.
 * \note   This function selects the MCD interrupt source in the MCDCR register (RCC->MCDCR).
 * \param  McdIntSel  Specifies the stabilization time setting for the HXTL.
 *                            This parameter can be any value of @ref RCC_MCDINTSELECTION
 */
static inline void RCC_selectMcdIntSource (RCC_McdIntSelection McdIntSel)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDINTSEL_M, 
              (((uint32_t)McdIntSel << RCC_MCDCR_MCDINTSEL_S) | RCC_MCDCR_KEY));
}

/**
  * \brief  Enable Miss Clock Detect (MCD)
  * \note   This function enables the Miss Clock Detect (MCD)
  *         by setting the appropriate bit in the MCDCR register (RCC->MCDCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_enableMcd (void)
{
    SET_BIT(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDEN_M | RCC_MCDCR_KEY);
}

/**
  * \brief  Disable Miss Clock Detect (MCD)
  * \note   This function disables the Miss Clock Detect (MCD)
  *         by clearing the appropriate bit in the MCDCR register (RCC->MCDCR).
  *         It applies a key value for security purposes.
  */
static inline void RCC_disableMcd (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDCR_MCDEN_M, RCC_MCDCR_KEY);
}

/**
  * \brief  Reset the CPU
  * \note   This function resets the CPU by writing the appropriate value to the RSTCR register (RCC->RSTCR).
  *         It applies the CPU reset bit (RCC_CPURST) to trigger the reset.
  */
static inline void RCC_rstCpu (void)
{
    WRITE_REG(RCC->RSTCR.WORDVAL, RCC_CPURST_VALUE);
}

/**
  * \brief  Reset the MCU
  * \note   This function resets the entire microcontroller (MCU) by writing the appropriate value to the RSTCR register (RCC->RSTCR).
  *         It applies the system reset bit (RCC_SIMXRS) to trigger the reset.
  */
static inline void RCC_rstMcu (void)
{
    WRITE_REG(RCC->RSTCR.WORDVAL, RCC_SIMXRS_VALUE);
}

/**
  * \brief  Clear Reset Flags
  * \note   This function clears the reset flags by setting the appropriate bit in the RSTSR register (RCC->RSTSR).
  *         It applies the remove reset flag mask (RCC_RMVF_M) to clear the flags.
  */
static inline void RCC_clearResetFlags (void)
{
    SET_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_RMVF_M);
}

/**
  * \brief  Read the CPU2 SYSRESETREQ Reset Flag Status.
  * \note   This function checks the CPU2SOFT bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU2SOFT Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu2SysResetReqRstFlag (void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU2SOFT_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU2 LOCKUP Reset Flag Status.
  * \note   This function checks the CPU2LOCKUP bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU2LOCKUP Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu2LockUprstRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU2LOCKUP_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU2 IWDG1 Reset Flag Status.
  * \note   This function checks the RMVST bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU2IWDG1 Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu2Iwdg1RstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU2IWDG1_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU2 IWDG1 Reset Flag Status.
  * \note   This function checks the CPU2IWDG1 bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU2IWDG1 Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu2WwdgRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU2WWDG_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU2 NMIWDG Reset Flag Status.
  * \note   This function checks the CPU2NMIWDG bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU2NMIWDG Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu2NmiwdgRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU2NMIWDG_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the SMPU Reset Flag Status.
  * \note   This function checks the SMPU bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the SMPU Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readSmpuRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_SMPUF_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the Standby Reset Flag Status.
  * \note   This function checks the SBYDBG bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the SBYDBG Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readStandbyRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_SBYDBG_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the Low Power Reset Flag Status.
  * \note   This function checks the LPWR bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the LPWR Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readLowPowerRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_LPWR_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the IWDG2 Reset Flag Status.
  * \note   This function checks the IWDG2 bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the IWDG2 Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readIwdg2RstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_IWDG2F_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU1 NMIWDG Reset Flag Status.
  * \note   This function checks the CPU1NMIWDG bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU1NMIWDG Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu1NmiWdtRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU1NMIWDG_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU1 Software Reset Flag Status.
  * \note   This function checks the CPU1SOFT bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU1SOFT Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu1SoftRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU1SOFT_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU Reset Flag Status.
  * \note   This function checks the CPU bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpuRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the PLL Loss of Lock Reset Flag Status.
  * \note   This function checks the PLLLOSE bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the PLLLOSE Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readPllLoseRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_PLLLOSE_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU1 LOCKUP Reset Flag Status.
  * \note   This function checks the CPU1LOCKUP bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU1LOCKUP Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu1LockupRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU1LOCKUP_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CLKFAIL Reset Flag Status.
  * \note   This function checks the CLKFAIL bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CLKFAIL Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readClockFailRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CLKFAIL_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the LVD Reset Flag Status.
  * \note   This function checks the LVD bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the LVD Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readLvdRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_LVD_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU1 IWDG1 Reset Flag Status.
  * \note   This function checks the CPU1IWDG1 bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU1IWDG1 Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu1Iwdg1RstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU1IWDG1_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the CPU1 WWDG Reset Flag Status.
  * \note   This function checks the CPU1WWDG bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the CPU1WWDG Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readCpu1WwdgRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_CPU1WWDG_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the SIMXRS Reset Flag Status.
  * \note   This function checks the SIMXRS bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the SIMXRS Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readSimxRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_SIMXRS_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the External Pin Reset Flag Status.
  * \note   This function checks the XRSN bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the External Pin Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readExPinRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_XRSN_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the Power-On or Brown-Out Reset Flag Status.
  * \note   This function checks the PORBOR bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the Power-On or Brown-Out Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readPorBorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_PORBOR_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the VDD Power-On Reset Flag Status.
  * \note   This function checks the VDDPOR bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the VDD Power-On Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readVddPorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_VDDPOR_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the VDD I/O Brown-Out Reset Flag Status.
  * \note   This function checks the VDDIOBOR bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the VDD I/O Brown-Out Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readVddIoBorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_VDDIOBOR_M) ? 1UL : 0UL;
}

/**
  * \brief  Read the VDD I/O Power-On Reset Flag Status.
  * \note   This function checks the VDDIOPOR bit in the RCC Reset Status Register (RCC->RSTSR)
  *         and returns a boolean value indicating whether the flag is set.
  * \return Returns the status of the VDD I/O Power-On Reset Flag.
  *          - 0: The reset flag is not being cleared.
  *          - 1: The reset flag is being cleared.
  */
static inline uint32_t RCC_readVddIoPorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RSTSR_VDDIOPOR_M) ? 1UL : 0UL;
}

/**
  * \brief  Unlock the RCC Register Access.
  * \note   This function unlocks access to certain RCC registers by writing a specific unlock key
  *         to the UNLOCK register (RCC->UNLOCK). This is necessary before modifying protected RCC registers.
  */
static inline void RCC_unlockRccRegister(void)
{
    WRITE_REG(RCC->UNLOCK.WORDVAL, RCC_UNLOCK);
}

/**
  * \brief  Lock the RCC Register Access.
  * \note   This function locks access to certain RCC registers by writing a specific lock key
  *         to the UNLOCK register (RCC->UNLOCK). This prevents accidental modification of protected RCC registers.
  */
static inline void RCC_lockRccRegister(void)
{
    WRITE_REG(RCC->UNLOCK.WORDVAL, RCC_LOCK);
}

/**
  * \brief  Get the status of a specified RCC interrupt flag.
  * \note   This function reads and returns the status of the specified interrupt flag based on the provided interrupt source.
  * \return Returns the status of the specified interrupt flag.
  *          - RCC_IFR_OSCCLKSTOP_M: Bit 31 set, Oscillator Clock Stop Interrupt Flag is set.
  *          - RCC_IFR_PLLLOSE_M:    Bit 29 set, indicating that the PLL Loss of Lock Interrupt Flag is set.
  *          - RCC_IFR_PLLLOCK_M:    Bit 25 set, indicating that the PLL Lock Detect Timeout Interrupt Flag is set.
  *          - RCC_IFR_HXTLFAIL_M:   Bit 20 set, indicating that the High-speed External Crystal Oscillator Failure Interrupt Flag is set.
  *          - RCC_IFR_HXTLRDY_M:    Bit 17 set, indicating that the High-speed External Crystal Oscillator Ready Interrupt Flag is set.
  *          - RCC_IFR_LIRCRDY_M:    Bit 15 set, indicating that the Low Internal Reference Clock Ready Interrupt Flag is set.
  *          - RCC_IFR_MIRC1RDY_M:   Bit 9 set, indicating that the Main Internal RC Oscillator 1 Ready Interrupt Flag is set.
  *          - RCC_IFR_MIRC2RDY_M:   Bit 1 set, indicating that the Main Internal RC Oscillator 2 Ready Interrupt Flag is set.
  */
static inline uint32_t RCC_getIntFlagStatus (void)
{
    return (RCC->IFR.WORDVAL);
}

/**
  * \brief  Get the status of a specified reset flag.
  * \note   This function retrieves the status of a specific reset flag within the RCC register.
  * \param  rstFlags    The reset flags to be checked. this parameter can be any combination of the following values.
  *                      - RCC_RSTSR_RMVFST_M:     Bit 30 set, Indicates that in the REMOVE RESET FLAG action.
  *                      - RCC_RSTSR_CPU2SOFT_M:   Bit 28 set, Said CPU2 Cotrex-M7 CPU software reset.
  *                      - RCC_RSTSR_CPU2LOCKUP_M: Bit 27 set, Said CPU2 Cotrex-M7 CPU Lockup reset.
  *                      - RCC_RSTSR_CPU2IWDG1_M:  Bit 26 set, Indicates that CPU2 IWDG1 is reset.
  *                      - RCC_RSTSR_CPU2WWDG_M:   Bit 25 set, Indicates that the CPU2 WWDG has been reset.
  *                      - RCC_RSTSR_CPU2NMIWDG_M: Bit 24 set, Indicates that CPU2 NMIWDTRST has been reset.
  *                      - RCC_RSTSR_SMPU_M:       Bit 20 set, indicating that the System Memory Protection Unit (SMPU) reset has occurred
  *                      - RCC_RSTSR_SBYDBG_M:     Bit 17 set, indicating that the Standby Debug Reset has occurred
  *                      - RCC_RSTSR_LPWR_M:       Bit 16 set, indicating that the Low-Power Reset has occurred
  *                      - RCC_RSTSR_IWDG2_M:      Bit 15 set, indicating that the Independent Watchdog 2 Reset has occurred
  *                      - RCC_RSTSR_CPU1NMIWDG_M: Bit 14 set, indicating that the Non-Maskable Interrupt Watchdog Reset has occurred
  *                      - RCC_RSTSR_CPU1SOFT_M:   Bit 13 set, indicating that the Software Reset has occurred
  *                      - RCC_RSTSR_CPU_M:        Bit 12 set, indicating that the CPU Reset has occurred
  *                      - RCC_RSTSR_PLLLOSE_M:    Bit 11 set, indicating that the Low-power Oscillator Loss Reset has occurred
  *                      - RCC_RSTSR_CPU1LOCKUP_M: Bit 10 set, indicating that the Lockup Reset has occurred
  *                      - RCC_RSTSR_CLKFAIL_M:    Bit 9 set, indicating that the Clock Management Unit Loss of Clock has occurred
  *                      - RCC_RSTSR_LVD_M:        Bit 8 set, indicating that the Low Voltage Detect Reset has occurred
  *                      - RCC_RSTSR_CPU1IWDG1_M:  Bit 7 set, indicating that the Independent Watchdog 1 Reset has occurred
  *                      - RCC_RSTSR_CPU1WWDG_M:   Bit 6 set, indicating that the Window Watchdog Reset has occurred
  *                      - RCC_RSTSR_SIMXRS_M:     Bit 5 set, indicating that the System Interface Module Reset has occurred
  *                      - RCC_RSTSR_XRSM_M:       Bit 4 set, indicating that the External Reset has occurred
  *                      - RCC_RSTSR_PORBOR_M:     Bit 3 set, indicating that the Power-On/Power-Off/Brownout Reset has occurred
  *                      - RCC_RSTSR_VDDPOR_M:     Bit 2 set, indicating that the VDD Power-On/Power-Off Reset has occurred
  *                      - RCC_RSTSR_VDDIOBOR_M:   Bit 1 set, indicating that the VDDIO Power-On/Brownout Reset has occurred
  *                      - RCC_RSTSR_VDDIOPOR_M:   Bit 0 set, indicating that the VDDIO Power-On Reset has occurred
  * \return Returns the status of the specified reset flag.
  */
static inline uint32_t RCC_getRstFlagsStatus (uint32_t rstFlags)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, rstFlags);
}

/**
  * \brief  Get the status of a specified reset flag.(Both CPU1 and CPU2 can read.)
  * \note   This function retrieves the status of a specific reset flag within the CPU1'RCC register.
  * \param  rstFlags    The reset flags to be checked. this parameter can be any combination of the following values.
  *                      - RCC_CPU1RSTSR_RMVFST_M:     Bit 30 set, Indicates that in the REMOVE RESET FLAG action.
  *                      - RCC_CPU1RSTSR_CPU2SOFT_M:   Bit 28 set, Said CPU2 Cotrex-M7 CPU software reset.
  *                      - RCC_CPU1RSTSR_CPU2LOCKUP_M: Bit 27 set, Said CPU2 Cotrex-M7 CPU Lockup reset.
  *                      - RCC_CPU1RSTSR_CPU2IWDG1_M:  Bit 26 set, Indicates that CPU2 IWDG1 is reset.
  *                      - RCC_CPU1RSTSR_CPU2WWDG_M:   Bit 25 set, Indicates that the CPU2 WWDG has been reset.
  *                      - RCC_CPU1RSTSR_CPU2NMIWDG_M: Bit 24 set, Indicates that CPU2 NMIWDTRST has been reset.
  *                      - RCC_CPU1RSTSR_SMPU_M:       Bit 20 set, indicating that the System Memory Protection Unit (SMPU) reset has occurred
  *                      - RCC_CPU1RSTSR_SBYDBG_M:     Bit 17 set, indicating that the Standby Debug Reset has occurred
  *                      - RCC_CPU1RSTSR_LPWR_M:       Bit 16 set, indicating that the Low-Power Reset has occurred
  *                      - RCC_CPU1RSTSR_IWDG2_M:      Bit 15 set, indicating that the Independent Watchdog 2 Reset has occurred
  *                      - RCC_CPU1RSTSR_CPU1NMIWDG_M: Bit 14 set, indicating that the Non-Maskable Interrupt Watchdog Reset has occurred
  *                      - RCC_CPU1RSTSR_CPU1SOFT_M:   Bit 13 set, indicating that the Software Reset has occurred
  *                      - RCC_CPU1RSTSR_CPU_M:        Bit 12 set, indicating that the CPU Reset has occurred
  *                      - RCC_CPU1RSTSR_PLLLOSE_M:    Bit 11 set, indicating that the Low-power Oscillator Loss Reset has occurred
  *                      - RCC_CPU1RSTSR_CPU1LOCKUP_M: Bit 10 set, indicating that the Lockup Reset has occurred
  *                      - RCC_CPU1RSTSR_CLKFAIL_M:    Bit 9 set, indicating that the Clock Management Unit Loss of Clock has occurred
  *                      - RCC_CPU1RSTSR_LVD_M:        Bit 8 set, indicating that the Low Voltage Detect Reset has occurred
  *                      - RCC_CPU1RSTSR_CPU1IWDG1_M:  Bit 7 set, indicating that the Independent Watchdog 1 Reset has occurred
  *                      - RCC_CPU1RSTSR_CPU1WWDG_M:   Bit 6 set, indicating that the Window Watchdog Reset has occurred
  *                      - RCC_CPU1RSTSR_SIMXRS_M:     Bit 5 set, indicating that the System Interface Module Reset has occurred
  *                      - RCC_CPU1RSTSR_XRSM_M:       Bit 4 set, indicating that the External Reset has occurred
  *                      - RCC_CPU1RSTSR_PORBOR_M:     Bit 3 set, indicating that the Power-On/Power-Off/Brownout Reset has occurred
  *                      - RCC_CPU1RSTSR_VDDPOR_M:     Bit 2 set, indicating that the VDD Power-On/Power-Off Reset has occurred
  *                      - RCC_CPU1RSTSR_VDDIOBOR_M:   Bit 1 set, indicating that the VDDIO Power-On/Brownout Reset has occurred
  *                      - RCC_CPU1RSTSR_VDDIOPOR_M:   Bit 0 set, indicating that the VDDIO Power-On Reset has occurred
  * \return Returns the status of the specified reset flag.
  */
static inline uint32_t RCC_getCpu1RstFlagsStatus (uint32_t rstFlags)
{
    return (RCC->CPU1RSTSR.WORDVAL, rstFlags);
}

/**
  * \brief  Get the status of a specified reset flag.(Both CPU1 and CPU2 can read.)
  * \note   This function retrieves the status of a specific reset flag within the CPU2'RCC register.
  * \param  rstFlags    The reset flags to be checked. this parameter can be any combination of the following values.
  *                      - RCC_CPU2RSTSR_RMVFST_M:     Bit 30 set, Indicates that in the REMOVE RESET FLAG action.
  *                      - RCC_CPU2RSTSR_CPU2SOFT_M:   Bit 28 set, Said CPU2 Cotrex-M7 CPU software reset.
  *                      - RCC_CPU2RSTSR_CPU2LOCKUP_M: Bit 27 set, Said CPU2 Cotrex-M7 CPU Lockup reset.
  *                      - RCC_CPU2RSTSR_CPU2IWDG1_M:  Bit 26 set, Indicates that CPU2 IWDG1 is reset.
  *                      - RCC_CPU2RSTSR_CPU2WWDG_M:   Bit 25 set, Indicates that the CPU2 WWDG has been reset.
  *                      - RCC_CPU2RSTSR_CPU2NMIWDG_M: Bit 24 set, Indicates that CPU2 NMIWDTRST has been reset.
  *                      - RCC_CPU2RSTSR_SMPU_M:       Bit 20 set, indicating that the System Memory Protection Unit (SMPU) reset has occurred
  *                      - RCC_CPU2RSTSR_SBYDBG_M:     Bit 17 set, indicating that the Standby Debug Reset has occurred
  *                      - RCC_CPU2RSTSR_LPWR_M:       Bit 16 set, indicating that the Low-Power Reset has occurred
  *                      - RCC_CPU2RSTSR_IWDG2_M:      Bit 15 set, indicating that the Independent Watchdog 2 Reset has occurred
  *                      - RCC_CPU2RSTSR_CPU1NMIWDG:_M Bit 14 set, indicating that the Non-Maskable Interrupt Watchdog Reset has occurred
  *                      - RCC_CPU2RSTSR_CPU1SOFT_M:   Bit 13 set, indicating that the Software Reset has occurred
  *                      - RCC_CPU2RSTSR_CPU_M:        Bit 12 set, indicating that the CPU Reset has occurred
  *                      - RCC_CPU2RSTSR_PLLLOSE_M:    Bit 11 set, indicating that the Low-power Oscillator Loss Reset has occurred
  *                      - RCC_CPU2RSTSR_CPU1LOCKUP_M: Bit 10 set, indicating that the Lockup Reset has occurred
  *                      - RCC_CPU2RSTSR_CLKFAIL_M:    Bit 9 set, indicating that the Clock Management Unit Loss of Clock has occurred
  *                      - RCC_CPU2RSTSR_LVD_M:        Bit 8 set, indicating that the Low Voltage Detect Reset has occurred
  *                      - RCC_CPU2RSTSR_CPU1IWDG1_M:  Bit 7 set, indicating that the Independent Watchdog 1 Reset has occurred
  *                      - RCC_CPU2RSTSR_CPU1WWDG_M:   Bit 6 set, indicating that the Window Watchdog Reset has occurred
  *                      - RCC_CPU2RSTSR_SIMXRS_M:     Bit 5 set, indicating that the System Interface Module Reset has occurred
  *                      - RCC_CPU2RSTSR_XRSM_M:       Bit 4 set, indicating that the External Reset has occurred
  *                      - RCC_CPU2RSTSR_PORBOR_M:     Bit 3 set, indicating that the Power-On/Power-Off/Brownout Reset has occurred
  *                      - RCC_CPU2RSTSR_VDDPOR_M:     Bit 2 set, indicating that the VDD Power-On/Power-Off Reset has occurred
  *                      - RCC_CPU2RSTSR_VDDIOBOR_M:   Bit 1 set, indicating that the VDDIO Power-On/Brownout Reset has occurred
  *                      - RCC_CPU2RSTSR_VDDIOPOR_M:   Bit 0 set, indicating that the VDDIO Power-On Reset has occurred
  * \return Returns the status of the specified reset flag.
  */
static inline uint32_t RCC_getCpu2RstFlagsStatus (uint32_t rstFlags)
{
    return (RCC->CPU2RSTSR.WORDVAL, rstFlags);
}

/**
  * \brief  Get the System Clock Frequency.
  * \note   This function determines the current system clock frequency based on the clock source
  *         and PLL configuration. It reads the software clock switch status and calculates the
  *         frequency accordingly.
  * \return Returns the system clock frequency in Hz.
  *          - HXTL_FREQ: If the system clock source is HXTL.
  *          - MIRC1_FREQ: If the system clock source is MIRC1.
  *          - MIRC2_FREQ: If the system clock source is MIRC2.
  *          - Calculated frequency: If the system clock source is PLL,
  *            based on PLLM, PLLN, PLLP, and PLL source.
  */
extern uint32_t RCC_getSysClockFrequency (void);

/**
  * \brief  Get the HCLK Clock Source Frequency.
  * \note   This function determines the current HCLK clock Source frequency
  * \return Returns the HCLK Source clock frequency in Hz.
  */
extern uint32_t RCC_getCpuclkFrequency (void);

/**
  * \brief  Get the HCLK (AHB) Clock Frequency.
  * \note   This function determines the current HCLK (AHB) clock frequency based on the system clock frequency
  *         and the AHB prescaler. It reads the system clock frequency and divides it by the AHB prescaler value.
  * \return Returns the HCLK (AHB) clock frequency in Hz.
  */
extern uint32_t RCC_getHclkFrequency (void);

/**
  * \brief  Get the PCLK1 (APB1,3,6) Clock Frequency.
  * \note   This function determines the current PCLK1 (APB1,3,6) clock frequency based on the HCLK (AHB) clock frequency
  *         and the APB1 prescaler. It reads the HCLK frequency and divides it by the APB1 prescaler value.
  * \return Returns the PCLK1 (APB1,3,6) clock frequency in Hz.
  */
extern uint32_t RCC_getPclk1Frequency (void);

/**
  * \brief  Get the PCLK2 (APB2,4) Clock Frequency.
  * \note   This function determines the current PCLK2,4 (APB2,4) clock frequency based on the HCLK (AHB)
  *         clock frequency and the APB2,4 prescaler. It reads the HCLK frequency and divides it
  *         by the APB2,4 prescaler value.
  * \return Returns the PCLK2,4 (APB2,4) clock frequency in Hz.
  */
extern uint32_t RCC_getPclk2Frequency (void);

/**
  * \brief  Get the PCLK5 (APB5) Clock Frequency.
  * \note   This function determines the current PCLK5 (APB5) clock frequency based on the HCLK (AHB) clock frequency
  *         and the APB5 prescaler. It reads the HCLK frequency and divides it by the APB5 prescaler value.
  * \return Returns the PCLK5 (APB5) clock frequency in Hz.
  */
extern uint32_t RCC_getPclk5Frequency (void);

/**
  * \brief  Get the EPWM Clock Frequency.
  * \note   This function determines the current EPWM clock frequency based on the HCLK Source clock frequency
  *         and the EPWMCLKDIV prescaler. It reads the HCLK Source frequency and divides it by the HCLK Source prescaler value.
  * \return Returns the EPWM clock frequency in Hz.
  */
extern uint32_t RCC_getEpwmFrequency (void);

/**
  * \brief  Get the Trace Clock Frequency.
  * \note   This function determines the current Trace clock frequency based on the HCLK (AHB) clock frequency
  *         and the Trace prescaler. It reads the HCLK frequency and divides it by the Trace prescaler value.
  * \return Returns the Trace clock frequency in Hz.
  */
extern uint32_t RCC_getTraceClockFrequency (void);

/**
  * \brief  Get the Flash Clock Frequency.
  * \note   This function determines the current Flash clock frequency based on the HCLK (AHB) clock frequency
  *         and the Flash prescaler. It reads the HCLK frequency and divides it by the Flash prescaler value.
  * \return Returns the Flash clock frequency in Hz.
  */
extern uint32_t RCC_getFlashClockFrequency (void);

/**
  * \brief  Configures the system clock source and related clock dividers.
  * \note   Before switching the clock, ensure that the clock source is enabled and ready.
  * \param  sysClockConfig    Specifies the system clock source.
  *                            This parameter can be any value of @ref RCC_SYSCLKSRC
  * \return Returns 0 if the clock configuration is successful, otherwise returns 1.
  */
extern uint32_t RCC_setClock (RCC_SysclkSrc sysClockConfig);

/**
  * \brief  Read the Software Clock Switch Status.
  * \note   This function reads the SWSTA bit in the RCC Configuration Register (RCC->CFGR)
  *         and returns its value after shifting it right by 4 bits.
  * \return Returns the software clock switch status.
  *          - 0: RCC_SYSCLKSTATUS_MIRC2
  *          - 1: RCC_SYSCLKSTATUS_HXTL
  *          - 2: RCC_SYSCLKSTATUS_PLL
  *          - 3: RCC_SYSCLKSTATUS_MIRC1
  */
extern RCC_SysclkStatus RCC_getClockSource (void);

/**
  * \brief  Configures the clock division settings for the Microcontroller Clock Output (MCO).
  * \param  config    Configuration value for clock division settings.
  *                    This parameter can be value of @ref CLOCKDIVCONFIG
  */
extern void RCC_configClockDiv (uint32_t config , uint32_t config2);

/**
  * \brief  Configures the Microcontroller Clock Output 1 (MCO1) settings.
  *
  * \param  mcoSource      Specifies the source for the MCO output.
  *                         This parameter can be any value of @ref RCC_MCOSOURCESEL
  * \param  mcoDiv         Specifies the divider for the MCO output.
  *                         This parameter can be any value of @ref RCC_MCODIVSEL
  * \param  mcoStatus      Specifies whether to enable or disable the MCO output.
  *                         This parameter can be any value of @ref RCC_FUNON
  */
extern void RCC_configMco1 (RCC_McoSourceSel mcoSource, RCC_McoDivSel mcoDiv, RCC_FunOn mcoEnable);

/**
  * \brief  Configures the Microcontroller Clock Output 2 (MCO2) settings.
  *
  * \param  mcoSource      Specifies the source for the MCO output.
  *                         This parameter can be any value of @ref RCC_MCOSOURCESEL
  * \param  mcoDiv         Specifies the divider for the MCO output.
  *                         This parameter can be any value of @ref RCC_MCODIVSEL
  * \param  mcoStatus      Specifies whether to enable or disable the MCO output.
  *                         This parameter can be any value of @ref RCC_FUNON
  */
extern void RCC_configMco2 (RCC_McoSourceSel mcoSource, RCC_McoDivSel mcoDiv, RCC_FunOn mcoEnable);

/**
  * \brief  Set the RCC interrupt enable.
  * 
  * \param  intSource  Specifies the interrupt source to configure.
  *                     This parameter can be any combination of values from @ref RCC_IERMASKS
  *                       RCC_IER_MIRC2RDY_M
  *                       RCC_IER_MIRC1RDY_M
  *                       RCC_IER_LIRCRDY_M
  *                       RCC_IER_HXTLFAULT_M
  *                       RCC_IER_HXTLRDY_M
  *                       RCC_IER_HXTLFAIL_M
  *                       RCC_IER_PLLLOCK_M
  *                       RCC_IER_PLLLOSE_M
  *                       RCC_IER_OSCCLKFAULT_M
  *                       RCC_IER_OSCCLKSTOP_M
  */
extern void RCC_setInterruptEnable (uint32_t intSource);

/**
  * \brief  Clear the RCC interrupt enable.
  * 
  * \param  intSource  Specifies the interrupt source to configure.
  *                     This parameter can be any combination of values from @ref RCC_IERMASKS
  *                       RCC_IER_MIRC2RDY_M
  *                       RCC_IER_MIRC1RDY_M
  *                       RCC_IER_LIRCRDY_M
  *                       RCC_IER_HXTLFAULT_M
  *                       RCC_IER_HXTLRDY_M
  *                       RCC_IER_HXTLFAIL_M
  *                       RCC_IER_PLLLOCK_M
  *                       RCC_IER_PLLLOSE_M
  *                       RCC_IER_OSCCLKFAULT_M
  *                       RCC_IER_OSCCLKSTOP_M
  */
extern void RCC_clearInterruptEnable (uint32_t intSource);

/**
  * \brief  Clear the specified RCC interrupt flag.
  * \note   This function clears the specified interrupt flag based on the provided interrupt source.
  * 
  * \param  intSource    Specifies the interrupt source whose flag is to be cleared.
  *                       This parameter can be any combination of values from @ref RCC_INTSOURCESELECTION
  *                         RCC_CLR_MIRC2RDY_M
  *                         RCC_CLR_MIRC1RDY_M
  *                         RCC_CLR_LIRCRDY_M
  *                         RCC_CLR_HXTLRDY_M
  *                         RCC_CLR_HXTLFAIL_M
  *                         RCC_CLR_PLLLOCK_M
  *                         RCC_CLR_PLLLOSE_M
  *                         RCC_CLR_OSCCLKSTOP_M
  */
extern void RCC_clearInterruptFlag (uint32_t intSource);

/**
  * \brief  Enables the MIRC2 oscillator and waits for it to be ready.
  * \note   This function enables the MIRC2 oscillator and waits for it to become ready.
  * 
  * \return Returns 0 if the MIRC2 oscillator is successfully enabled and ready, otherwise returns 1.
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern uint32_t RCC_enableMirc2Oscillator (void);

/**
  * \brief  Enables the MIRC1 oscillator and waits for it to be ready.
  * \note   This function enables the MIRC1 oscillator and waits for it to become ready.
  * 
  * \return Returns 0 if the MIRC1 oscillator is successfully enabled and ready, otherwise returns 1.
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern uint32_t RCC_enableMirc1Oscillator (void);

/**
  * \brief  Enables the LIRC oscillator and waits for it to be ready.
  * \note   This function enables the LIRC oscillator and waits for it to become ready.
  * 
  * \return Returns 0 if the LIRC oscillator is successfully enabled and ready, otherwise returns 1.
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern uint32_t RCC_enableLircOscillator (void);

/**
  * \brief  Disables the MIRC2 oscillator and waits for it to be disabled.
  * \note   This function disables the MIRC2 oscillator and waits until it is fully disabled.
  * 
  * \return Returns 0 if the MIRC2 oscillator is successfully disabled, otherwise returns 1.
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern uint32_t RCC_disableMirc2Oscillator (void);

/**
  * \brief  Disables the MIRC1 oscillator and waits for it to be disabled.
  * \note   This function disables the MIRC1 oscillator and waits until it is fully disabled.
  * 
  * \return Returns 0 if the MIRC1 oscillator is successfully disabled, otherwise returns 1.
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern uint32_t RCC_disableMirc1Oscillator (void);

/**
  * \brief  Disables the LIRC oscillator and waits for it to be disabled.
  * \note   This function disables the LIRC oscillator and waits until it is fully disabled.
  * 
  * \return Returns 0 if the LIRC oscillator is successfully disabled, otherwise returns 1.
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern uint32_t RCC_disableLircOscillator (void);

/**
  * \brief  Configure the PLL with the specified settings.
  * \note   This function configures the PLL based on the provided configuration parameters.
  * \param  pllConfig      Specifies the PLL configuration settings.
  *                         This parameter can include values from @ref PLLCONFIG
  * \param  pllExtConfig   Specifies the PLL configuration settings.
  *                         This parameter can include values from @ref PLLEXTCONFIG
  * \param  pllStatus      Specifies whether to enable or disable the PLL.
  *                         This parameter can be any value of @ref RCC_FUNON
  * \return Returns 0 if the pll configuration is successful, otherwise returns 1.
  */
extern uint32_t RCC_configPll (uint32_t pllConfig, uint32_t pllExtConfig, RCC_FunOn pllStatus);

/**
  * \brief  Configure the High-Speed External Crystal Oscillator (HXTL) settings.
  * \note   This function configures the HXTL based on the provided configuration parameters.
  *         It ensures that the system clock is not using HXTL before disabling it and re-enabling it with new settings.
  * \param  config        Specifies the configuration settings for the HXTL.
  *                        This parameter is a combination of values from @ref HXTLCONFIG
  * \param  hxtlBypass    Specifies whether to enable or disable the HXTL bypass mode.
  *                        This parameter can be one of the values from @ref RCC_HXTLBYPASSSEL
  * \param  hxtlSts       Specifies whether to enable or disable the HXTL.
  *                        This parameter can be any value of @ref RCC_FUNON
  * \return Returns 0 if the hxtl configuration is successful, otherwise returns 1.
  */
extern uint32_t RCC_configHxtl (uint32_t config, RCC_HxtlBypassSel hxtlBypass, RCC_FunOn hxtlSts);

/**
  * \brief  Reset the specified AHB1 peripheral(s).
  * \note   This function resets one or more AHB1 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB1 peripheral reset request.
  * 
  * \param  peripheral    Specifies the AHB1 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_AHBRST1MASKS
  */
extern void RCC_resetAhb1Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified AHB2 peripheral(s).
  * \note   This function resets one or more AHB2 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB2 peripheral reset request.
  * 
  * \param  peripheral    Specifies the AHB2 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_AHBRST2MASKS
  */
extern void RCC_resetAhb2Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified APB1 peripheral(s).
  * \note   This function resets one or more APB1 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB1 peripheral reset request.
  * 
  * \param  peripheral    Specifies the APB1 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_APBRST1MASKS
  */
extern void RCC_resetApb1Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified APB2 peripheral(s).
  * \note   This function resets one or more APB2 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB2 peripheral reset request.
  * 
  * \param  peripheral    Specifies the APB2 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_APBRST2MASKS
  */
extern void RCC_resetApb2Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified APB3 peripheral(s).
  * \note   This function resets one or more APB3 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB3 peripheral reset request.
  * 
  * \param  peripheral    Specifies the APB3 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_APBRST3MASKS
  */
extern void RCC_resetApb3Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified APB5 peripheral(s).
  * \note   This function resets one or more APB5 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
  * 
  * \param  peripheral    Specifies the APB5 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_APBRST5MASKS
  */
extern void RCC_resetApb5Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified APB6 peripheral(s).
  * \note   This function resets one or more APB6 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
  * 
  * \param  peripheral    Specifies the APB6 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_APBRST6MASKS
  */
extern void RCC_resetApb6Peripheral (uint32_t peripheral);

/**
  * \brief  Reset the specified APB8 peripheral(s).
  * \note   This function resets one or more APB5 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
  * 
  * \param  peripheral    Specifies the APB8 peripheral(s) to be reset.
  *                        This parameter is a combination of values from @ref RCC_APBRST8MASKS
  */
extern void RCC_resetApb8Peripheral (uint32_t peripheral);

/**
  * \brief  Enable the specified AHB1 peripheral(s) clock.
  * \note   This function enables the clock for one or more AHB1 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_HCLKEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableAhb1PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified AHB2 peripheral(s) clock.
  * \note   This function enables the clock for one or more AHB2 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_HCLKEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableAhb2PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified APB1 peripheral(s) clock.
  * \note   This function enables the clock for one or more APB1 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the APB1 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb1PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified APB2 peripheral(s) clock.
  * \note   This function enables the clock for one or more APB2 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the APB2 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb2PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified APB3 peripheral(s) clock.
  * \note   This function enables the clock for one or more APB3 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the APB3 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN3MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb3PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified APB5 peripheral(s) clock.
  * \note   This function enables the clock for one or more APB5 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the APB5 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN5MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb5PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified APB6 peripheral(s) clock.
  * \note   This function enables the clock for one or more APB6 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the APB6 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN6MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb6PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified APB8 peripheral(s) clock.
  * \note   This function enables the clock for one or more APB8 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock enable request.
  * 
  * \param  peripheral    Specifies the APB8 peripheral(s) clock to be enabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN8MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb8PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified AHB1 peripheral(s) clock.
  * \note   This function disables the clock for one or more AHB1 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_HCLKEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableAhb1PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified AHB2 peripheral(s) clock.
  * \note   This function disables the clock for one or more AHB2 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_HCLKEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableAhb2PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified APB1 peripheral(s) clock.
  * \note   This function disables the clock for one or more APB1 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the APB1 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb1PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified APB2 peripheral(s) clock.
  * \note   This function disables the clock for one or more APB2 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the APB2 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb2PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified APB3 peripheral(s) clock.
  * \note   This function disables the clock for one or more APB3 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the APB3 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN3MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb3PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified APB5 peripheral(s) clock.
  * \note   This function disables the clock for one or more APB5 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the APB5 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN5MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb5PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified APB6 peripheral(s) clock.
  * \note   This function disables the clock for one or more APB6 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the APB6 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN6MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb6PeripheralClock (uint32_t peripheral);

/**
  * \brief  Disable the specified APB8 peripheral(s) clock.
  * \note   This function disables the clock for one or more APB8 peripherals based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock disable request.
  * 
  * \param  peripheral    Specifies the APB8 peripheral(s) clock to be disabled.
  *                        This parameter is a combination of values from @ref RCC_PCLKEN8MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb8PeripheralClock (uint32_t peripheral);

/**
  * \brief  Enable the specified AHB1 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more AHB1 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_HCLKLPEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableAhb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified AHB2 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more AHB2 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_HCLKLPEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableAhb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified APB1 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more APB1 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB1 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified APB2 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more APB2 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB2 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified APB3 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more APB3 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB3 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN3MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb3PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified APB5 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more APB5 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB5 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN5MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb5PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified APB6 peripheral(s) clock in sleep mode.
  * \note   This function enables the clock for one or more APB6 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB6 peripheral(s) clock to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN6MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb6PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Enable the specified APB8 peripheral(s) in sleep mode.
  * \note   This function enables one or more APB8 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB8 peripheral enable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB8 peripheral(s) to be enabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN8MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_enableApb8PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified AHB1 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more AHB1 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_HCLKLPEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableAhb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified AHB2 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more AHB2 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_HCLKLPEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableAhb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified APB1 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more APB1 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB1 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN1MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified APB2 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more APB2 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB2 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN2MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified APB3 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more APB3 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB3 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN3MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb3PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified APB5 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more APB5 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB5 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN5MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb5PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified APB6 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more APB6 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB6 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN6MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb6PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Disable the specified APB8 peripheral(s) clock in sleep mode.
  * \note   This function disables the clock for one or more APB8 peripherals in sleep mode based on the provided bitmask.
  *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock disable request in sleep mode.
  * 
  * \param  peripheral    Specifies the APB8 peripheral(s) clock to be disabled in sleep mode.
  *                        This parameter is a combination of values from @ref RCC_PCLKLPEN8MASKS
  * 
  * \attention  This function needs to be unlocked first by \b RCC_unlockRccRegister()
  */
extern void RCC_disableApb8PeripheralClockInSleepMode (uint32_t peripheral);

/**
  * \brief  Configure the MIRC2 Oscillator Stop Detection.
  * \note   This function configures the MIRC2 oscillator stop detection based on the provided status.
  * \param  config    Specifies the configuration settings for the MIRC2.
  *                    This parameter is a combination of values from @ref RCC_MIRC1MIRC2CYCSELECTION.
  * \param  mcdSts    Specifies the enable or disable status of the MCD (Main Clock Divider).
  *                    This parameter can be any value of @ref RCC_FUNON
  */
extern void RCC_configMcd (RCC_McdMircCycleSelection config, RCC_FunOn mcdSts);

/**
  * \brief  Clear the RCC reset flag.
  * \note   This function clears the chip reset flag in the RCC register.
  *         It first unlocks the RCC register, clears the reset flag, and then locks the RCC register
  *         to prevent accidental changes.
  */
extern void RCC_clearRccFlag (void);


#ifdef __cplusplus
}
#endif


#endif /* __RCC_H__ */
