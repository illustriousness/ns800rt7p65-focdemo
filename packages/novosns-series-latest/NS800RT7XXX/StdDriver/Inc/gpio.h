/**
  * @file       gpio.h
  * @author     yangjun
  * @brief      Header file for NS800RT7xxx gpio module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __GPIO_H__
#define __GPIO_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT7xxx_TI_gpio.h"
#include "NS800RT7xxx_TI_xint.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup GPIO_EXPORTED_TYPES GPIO Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'GPIO' module.
  */

/** @defgroup GPIO_PINNUM GPIO Pin Number with one group(GPIOA/B/C/D/E/F/G/H)
  * @{
  * @brief  Macro definitions about GPIO pins.
  */
typedef enum {
    GPIO_PIN_0 = 0U,    /*!< GPIO pin 0 */
    GPIO_PIN_1,         /*!< GPIO pin 1 */
    GPIO_PIN_2,         /*!< GPIO pin 2 */
    GPIO_PIN_3,         /*!< GPIO pin 3 */
    GPIO_PIN_4,         /*!< GPIO pin 4 */
    GPIO_PIN_5,         /*!< GPIO pin 5 */
    GPIO_PIN_6,         /*!< GPIO pin 6 */
    GPIO_PIN_7,         /*!< GPIO pin 7 */
    GPIO_PIN_8,         /*!< GPIO pin 8 */
    GPIO_PIN_9,         /*!< GPIO pin 9 */
    GPIO_PIN_10,        /*!< GPIO pin 10 */
    GPIO_PIN_11,        /*!< GPIO pin 11 */
    GPIO_PIN_12,        /*!< GPIO pin 12 */
    GPIO_PIN_13,        /*!< GPIO pin 13 */
    GPIO_PIN_14,        /*!< GPIO pin 14 */
    GPIO_PIN_15,        /*!< GPIO pin 15 */
    GPIO_PIN_16,        /*!< GPIO pin 16 */
    GPIO_PIN_17,        /*!< GPIO pin 17 */
    GPIO_PIN_18,        /*!< GPIO pin 18 */
    GPIO_PIN_19,        /*!< GPIO pin 19 */
    GPIO_PIN_20,        /*!< GPIO pin 20 */
    GPIO_PIN_21,        /*!< GPIO pin 21 */
    GPIO_PIN_22,        /*!< GPIO pin 22 */
    GPIO_PIN_23,        /*!< GPIO pin 23 */
    GPIO_PIN_24,        /*!< GPIO pin 24 */
    GPIO_PIN_25,        /*!< GPIO pin 25 */
    GPIO_PIN_26,        /*!< GPIO pin 26 */
    GPIO_PIN_27,        /*!< GPIO pin 27 */
    GPIO_PIN_28,        /*!< GPIO pin 28 */
    GPIO_PIN_29,        /*!< GPIO pin 29 */
    GPIO_PIN_30,        /*!< GPIO pin 30 */
    GPIO_PIN_31,        /*!< GPIO pin 31 */
} GPIO_PinNum;

/**
  * @}
  */

/** @defgroup GPIO_ALTFUNC GPIO Pin Alternate Function
  * @{
  * @brief  Macro definitions about GPIO alternate functions.
  */
typedef enum {
    ALT0_FUNCTION = 0U,    /*!< GPIO alternate function 0 */
    ALT1_FUNCTION,         /*!< GPIO alternate function 1 */
    ALT2_FUNCTION,         /*!< GPIO alternate function 2 */
    ALT3_FUNCTION,         /*!< GPIO alternate function 3 */
    ALT4_FUNCTION,         /*!< GPIO alternate function 4 */
    ALT5_FUNCTION,         /*!< GPIO alternate function 5 */
    ALT6_FUNCTION,         /*!< GPIO alternate function 6 */
    ALT7_FUNCTION,         /*!< GPIO alternate function 7 */
    ALT8_FUNCTION,         /*!< GPIO alternate function 8 */
    ALT9_FUNCTION,         /*!< GPIO alternate function 9 */
    ALT10_FUNCTION,        /*!< GPIO alternate function 10 */
    ALT11_FUNCTION,        /*!< GPIO alternate function 11 */
    ALT12_FUNCTION,        /*!< GPIO alternate function 12 */
    ALT13_FUNCTION,        /*!< GPIO alternate function 13 */
    ALT14_FUNCTION,        /*!< GPIO alternate function 14 */
    ALT15_FUNCTION         /*!< GPIO alternate function 15 */
} GPIO_AltFunc;

/**
  * @}
  */

/** @defgroup GPIO_SMPCLK GPIO Pin Input Sampling Period Selection
  * @{
  * @brief  Macro definitions about GPIO input sampling period.
  */
typedef enum {
    GPIO_SMP_SYSCLK_DIV_1 = 0U,    /*!< Pin Sampling is in SYSCLK/1 */
    GPIO_SMP_SYSCLK_DIV_2,         /*!< Pin Sampling is in SYSCLK/2 */
    GPIO_SMP_SYSCLK_DIV_4,         /*!< Pin Sampling is in SYSCLK/4 */
    GPIO_SMP_SYSCLK_DIV_6,         /*!< Pin Sampling is in SYSCLK/6 */
    GPIO_SMP_SYSCLK_DIV_8,         /*!< Pin Sampling is in SYSCLK/8 */
    GPIO_SMP_SYSCLK_DIV_10,        /*!< Pin Sampling is in SYSCLK/10 */
    GPIO_SMP_SYSCLK_DIV_12,        /*!< Pin Sampling is in SYSCLK/12 */
    GPIO_SMP_SYSCLK_DIV_14,        /*!< Pin Sampling is in SYSCLK/14 */
    GPIO_SMP_SYSCLK_DIV_16,        /*!< Pin Sampling is in SYSCLK/16 */
    GPIO_SMP_SYSCLK_DIV_18,        /*!< Pin Sampling is in SYSCLK/18 */
    GPIO_SMP_SYSCLK_DIV_20,        /*!< Pin Sampling is in SYSCLK/20 */
    GPIO_SMP_SYSCLK_DIV_22,        /*!< Pin Sampling is in SYSCLK/22 */
    GPIO_SMP_SYSCLK_DIV_24,        /*!< Pin Sampling is in SYSCLK/24 */
    GPIO_SMP_SYSCLK_DIV_26,        /*!< Pin Sampling is in SYSCLK/26 */
    GPIO_SMP_SYSCLK_DIV_28,        /*!< Pin Sampling is in SYSCLK/28 */
    GPIO_SMP_SYSCLK_DIV_30,        /*!< Pin Sampling is in SYSCLK/30 */
    GPIO_SMP_SYSCLK_DIV_32,        /*!< Pin Sampling is in SYSCLK/32 */
    GPIO_SMP_SYSCLK_DIV_34,        /*!< Pin Sampling is in SYSCLK/34 */
    GPIO_SMP_SYSCLK_DIV_36,        /*!< Pin Sampling is in SYSCLK/36 */
    GPIO_SMP_SYSCLK_DIV_38,        /*!< Pin Sampling is in SYSCLK/38 */
    GPIO_SMP_SYSCLK_DIV_40,        /*!< Pin Sampling is in SYSCLK/40 */
    GPIO_SMP_SYSCLK_DIV_42,        /*!< Pin Sampling is in SYSCLK/42 */
    GPIO_SMP_SYSCLK_DIV_44,        /*!< Pin Sampling is in SYSCLK/44 */
    GPIO_SMP_SYSCLK_DIV_46,        /*!< Pin Sampling is in SYSCLK/46 */
    GPIO_SMP_SYSCLK_DIV_48,        /*!< Pin Sampling is in SYSCLK/48 */
    GPIO_SMP_SYSCLK_DIV_50,        /*!< Pin Sampling is in SYSCLK/50 */
    GPIO_SMP_SYSCLK_DIV_52,        /*!< Pin Sampling is in SYSCLK/52 */
    GPIO_SMP_SYSCLK_DIV_54,        /*!< Pin Sampling is in SYSCLK/54 */
    GPIO_SMP_SYSCLK_DIV_56,        /*!< Pin Sampling is in SYSCLK/56 */
    GPIO_SMP_SYSCLK_DIV_58,        /*!< Pin Sampling is in SYSCLK/58 */
    GPIO_SMP_SYSCLK_DIV_60,        /*!< Pin Sampling is in SYSCLK/60 */
    GPIO_SMP_SYSCLK_DIV_62,        /*!< Pin Sampling is in SYSCLK/62 */
    GPIO_SMP_SYSCLK_DIV_64,        /*!< Pin Sampling is in SYSCLK/64 */
    GPIO_SMP_SYSCLK_DIV_66,        /*!< Pin Sampling is in SYSCLK/66 */
    GPIO_SMP_SYSCLK_DIV_68,        /*!< Pin Sampling is in SYSCLK/68 */
    GPIO_SMP_SYSCLK_DIV_70,        /*!< Pin Sampling is in SYSCLK/70 */
    GPIO_SMP_SYSCLK_DIV_72,        /*!< Pin Sampling is in SYSCLK/72 */
    GPIO_SMP_SYSCLK_DIV_74,        /*!< Pin Sampling is in SYSCLK/74 */
    GPIO_SMP_SYSCLK_DIV_76,        /*!< Pin Sampling is in SYSCLK/76 */
    GPIO_SMP_SYSCLK_DIV_78,        /*!< Pin Sampling is in SYSCLK/78 */
    GPIO_SMP_SYSCLK_DIV_80,        /*!< Pin Sampling is in SYSCLK/80 */
    GPIO_SMP_SYSCLK_DIV_82,        /*!< Pin Sampling is in SYSCLK/82 */
    GPIO_SMP_SYSCLK_DIV_84,        /*!< Pin Sampling is in SYSCLK/84 */
    GPIO_SMP_SYSCLK_DIV_86,        /*!< Pin Sampling is in SYSCLK/86 */
    GPIO_SMP_SYSCLK_DIV_88,        /*!< Pin Sampling is in SYSCLK/88 */
    GPIO_SMP_SYSCLK_DIV_90,        /*!< Pin Sampling is in SYSCLK/90 */
    GPIO_SMP_SYSCLK_DIV_92,        /*!< Pin Sampling is in SYSCLK/92 */
    GPIO_SMP_SYSCLK_DIV_94,        /*!< Pin Sampling is in SYSCLK/94 */
    GPIO_SMP_SYSCLK_DIV_96,        /*!< Pin Sampling is in SYSCLK/96 */
    GPIO_SMP_SYSCLK_DIV_98,        /*!< Pin Sampling is in SYSCLK/98 */
    GPIO_SMP_SYSCLK_DIV_100,       /*!< Pin Sampling is in SYSCLK/100 */
    GPIO_SMP_SYSCLK_DIV_102,       /*!< Pin Sampling is in SYSCLK/102 */
    GPIO_SMP_SYSCLK_DIV_104,       /*!< Pin Sampling is in SYSCLK/104 */
    GPIO_SMP_SYSCLK_DIV_106,       /*!< Pin Sampling is in SYSCLK/106 */
    GPIO_SMP_SYSCLK_DIV_108,       /*!< Pin Sampling is in SYSCLK/108 */
    GPIO_SMP_SYSCLK_DIV_110,       /*!< Pin Sampling is in SYSCLK/110 */
    GPIO_SMP_SYSCLK_DIV_112,       /*!< Pin Sampling is in SYSCLK/112 */
    GPIO_SMP_SYSCLK_DIV_114,       /*!< Pin Sampling is in SYSCLK/114 */
    GPIO_SMP_SYSCLK_DIV_116,       /*!< Pin Sampling is in SYSCLK/116 */
    GPIO_SMP_SYSCLK_DIV_118,       /*!< Pin Sampling is in SYSCLK/118 */
    GPIO_SMP_SYSCLK_DIV_120,       /*!< Pin Sampling is in SYSCLK/120 */
    GPIO_SMP_SYSCLK_DIV_122,       /*!< Pin Sampling is in SYSCLK/122 */
    GPIO_SMP_SYSCLK_DIV_124,       /*!< Pin Sampling is in SYSCLK/124 */
    GPIO_SMP_SYSCLK_DIV_126,       /*!< Pin Sampling is in SYSCLK/126 */
    GPIO_SMP_SYSCLK_DIV_128,       /*!< Pin Sampling is in SYSCLK/128 */
    GPIO_SMP_SYSCLK_DIV_130,       /*!< Pin Sampling is in SYSCLK/130 */
    GPIO_SMP_SYSCLK_DIV_132,       /*!< Pin Sampling is in SYSCLK/132 */
    GPIO_SMP_SYSCLK_DIV_134,       /*!< Pin Sampling is in SYSCLK/134 */
    GPIO_SMP_SYSCLK_DIV_136,       /*!< Pin Sampling is in SYSCLK/136 */
    GPIO_SMP_SYSCLK_DIV_138,       /*!< Pin Sampling is in SYSCLK/138 */
    GPIO_SMP_SYSCLK_DIV_140,       /*!< Pin Sampling is in SYSCLK/140 */
    GPIO_SMP_SYSCLK_DIV_142,       /*!< Pin Sampling is in SYSCLK/142 */
    GPIO_SMP_SYSCLK_DIV_144,       /*!< Pin Sampling is in SYSCLK/144 */
    GPIO_SMP_SYSCLK_DIV_146,       /*!< Pin Sampling is in SYSCLK/146 */
    GPIO_SMP_SYSCLK_DIV_148,       /*!< Pin Sampling is in SYSCLK/148 */
    GPIO_SMP_SYSCLK_DIV_150,       /*!< Pin Sampling is in SYSCLK/150 */
    GPIO_SMP_SYSCLK_DIV_152,       /*!< Pin Sampling is in SYSCLK/152 */
    GPIO_SMP_SYSCLK_DIV_154,       /*!< Pin Sampling is in SYSCLK/154 */
    GPIO_SMP_SYSCLK_DIV_156,       /*!< Pin Sampling is in SYSCLK/156 */
    GPIO_SMP_SYSCLK_DIV_158,       /*!< Pin Sampling is in SYSCLK/158 */
    GPIO_SMP_SYSCLK_DIV_160,       /*!< Pin Sampling is in SYSCLK/160 */
    GPIO_SMP_SYSCLK_DIV_162,       /*!< Pin Sampling is in SYSCLK/162 */
    GPIO_SMP_SYSCLK_DIV_164,       /*!< Pin Sampling is in SYSCLK/164 */
    GPIO_SMP_SYSCLK_DIV_166,       /*!< Pin Sampling is in SYSCLK/166 */
    GPIO_SMP_SYSCLK_DIV_168,       /*!< Pin Sampling is in SYSCLK/168 */
    GPIO_SMP_SYSCLK_DIV_170,       /*!< Pin Sampling is in SYSCLK/170 */
    GPIO_SMP_SYSCLK_DIV_172,       /*!< Pin Sampling is in SYSCLK/172 */
    GPIO_SMP_SYSCLK_DIV_174,       /*!< Pin Sampling is in SYSCLK/174 */
    GPIO_SMP_SYSCLK_DIV_176,       /*!< Pin Sampling is in SYSCLK/176 */
    GPIO_SMP_SYSCLK_DIV_178,       /*!< Pin Sampling is in SYSCLK/178 */
    GPIO_SMP_SYSCLK_DIV_180,       /*!< Pin Sampling is in SYSCLK/180 */
    GPIO_SMP_SYSCLK_DIV_182,       /*!< Pin Sampling is in SYSCLK/182 */
    GPIO_SMP_SYSCLK_DIV_184,       /*!< Pin Sampling is in SYSCLK/184 */
    GPIO_SMP_SYSCLK_DIV_186,       /*!< Pin Sampling is in SYSCLK/186 */
    GPIO_SMP_SYSCLK_DIV_188,       /*!< Pin Sampling is in SYSCLK/188 */
    GPIO_SMP_SYSCLK_DIV_190,       /*!< Pin Sampling is in SYSCLK/190 */
    GPIO_SMP_SYSCLK_DIV_192,       /*!< Pin Sampling is in SYSCLK/192 */
    GPIO_SMP_SYSCLK_DIV_194,       /*!< Pin Sampling is in SYSCLK/194 */
    GPIO_SMP_SYSCLK_DIV_196,       /*!< Pin Sampling is in SYSCLK/196 */
    GPIO_SMP_SYSCLK_DIV_198,       /*!< Pin Sampling is in SYSCLK/198 */
    GPIO_SMP_SYSCLK_DIV_200,       /*!< Pin Sampling is in SYSCLK/200 */
    GPIO_SMP_SYSCLK_DIV_202,       /*!< Pin Sampling is in SYSCLK/202 */
    GPIO_SMP_SYSCLK_DIV_204,       /*!< Pin Sampling is in SYSCLK/204 */
    GPIO_SMP_SYSCLK_DIV_206,       /*!< Pin Sampling is in SYSCLK/206 */
    GPIO_SMP_SYSCLK_DIV_208,       /*!< Pin Sampling is in SYSCLK/208 */
    GPIO_SMP_SYSCLK_DIV_210,       /*!< Pin Sampling is in SYSCLK/210 */
    GPIO_SMP_SYSCLK_DIV_212,       /*!< Pin Sampling is in SYSCLK/212 */
    GPIO_SMP_SYSCLK_DIV_214,       /*!< Pin Sampling is in SYSCLK/214 */
    GPIO_SMP_SYSCLK_DIV_216,       /*!< Pin Sampling is in SYSCLK/216 */
    GPIO_SMP_SYSCLK_DIV_218,       /*!< Pin Sampling is in SYSCLK/218 */
    GPIO_SMP_SYSCLK_DIV_220,       /*!< Pin Sampling is in SYSCLK/220 */
    GPIO_SMP_SYSCLK_DIV_222,       /*!< Pin Sampling is in SYSCLK/222 */
    GPIO_SMP_SYSCLK_DIV_224,       /*!< Pin Sampling is in SYSCLK/224 */
    GPIO_SMP_SYSCLK_DIV_226,       /*!< Pin Sampling is in SYSCLK/226 */
    GPIO_SMP_SYSCLK_DIV_228,       /*!< Pin Sampling is in SYSCLK/228 */
    GPIO_SMP_SYSCLK_DIV_230,       /*!< Pin Sampling is in SYSCLK/230 */
    GPIO_SMP_SYSCLK_DIV_232,       /*!< Pin Sampling is in SYSCLK/232 */
    GPIO_SMP_SYSCLK_DIV_234,       /*!< Pin Sampling is in SYSCLK/234 */
    GPIO_SMP_SYSCLK_DIV_236,       /*!< Pin Sampling is in SYSCLK/236 */
    GPIO_SMP_SYSCLK_DIV_238,       /*!< Pin Sampling is in SYSCLK/238 */
    GPIO_SMP_SYSCLK_DIV_240,       /*!< Pin Sampling is in SYSCLK/240 */
    GPIO_SMP_SYSCLK_DIV_242,       /*!< Pin Sampling is in SYSCLK/242 */
    GPIO_SMP_SYSCLK_DIV_244,       /*!< Pin Sampling is in SYSCLK/244 */
    GPIO_SMP_SYSCLK_DIV_246,       /*!< Pin Sampling is in SYSCLK/246 */
    GPIO_SMP_SYSCLK_DIV_248,       /*!< Pin Sampling is in SYSCLK/248 */
    GPIO_SMP_SYSCLK_DIV_250,       /*!< Pin Sampling is in SYSCLK/250 */
    GPIO_SMP_SYSCLK_DIV_252,       /*!< Pin Sampling is in SYSCLK/252 */
    GPIO_SMP_SYSCLK_DIV_254,       /*!< Pin Sampling is in SYSCLK/254 */
    GPIO_SMP_SYSCLK_DIV_256,       /*!< Pin Sampling is in SYSCLK/256 */
    GPIO_SMP_SYSCLK_DIV_258,       /*!< Pin Sampling is in SYSCLK/258 */
    GPIO_SMP_SYSCLK_DIV_260,       /*!< Pin Sampling is in SYSCLK/260 */
    GPIO_SMP_SYSCLK_DIV_262,       /*!< Pin Sampling is in SYSCLK/262 */
    GPIO_SMP_SYSCLK_DIV_264,       /*!< Pin Sampling is in SYSCLK/264 */
    GPIO_SMP_SYSCLK_DIV_266,       /*!< Pin Sampling is in SYSCLK/266 */
    GPIO_SMP_SYSCLK_DIV_268,       /*!< Pin Sampling is in SYSCLK/268 */
    GPIO_SMP_SYSCLK_DIV_270,       /*!< Pin Sampling is in SYSCLK/270 */
    GPIO_SMP_SYSCLK_DIV_272,       /*!< Pin Sampling is in SYSCLK/272 */
    GPIO_SMP_SYSCLK_DIV_274,       /*!< Pin Sampling is in SYSCLK/274 */
    GPIO_SMP_SYSCLK_DIV_276,       /*!< Pin Sampling is in SYSCLK/276 */
    GPIO_SMP_SYSCLK_DIV_278,       /*!< Pin Sampling is in SYSCLK/278 */
    GPIO_SMP_SYSCLK_DIV_280,       /*!< Pin Sampling is in SYSCLK/280 */
    GPIO_SMP_SYSCLK_DIV_282,       /*!< Pin Sampling is in SYSCLK/282 */
    GPIO_SMP_SYSCLK_DIV_284,       /*!< Pin Sampling is in SYSCLK/284 */
    GPIO_SMP_SYSCLK_DIV_286,       /*!< Pin Sampling is in SYSCLK/286 */
    GPIO_SMP_SYSCLK_DIV_288,       /*!< Pin Sampling is in SYSCLK/288 */
    GPIO_SMP_SYSCLK_DIV_290,       /*!< Pin Sampling is in SYSCLK/290 */
    GPIO_SMP_SYSCLK_DIV_292,       /*!< Pin Sampling is in SYSCLK/292 */
    GPIO_SMP_SYSCLK_DIV_294,       /*!< Pin Sampling is in SYSCLK/294 */
    GPIO_SMP_SYSCLK_DIV_296,       /*!< Pin Sampling is in SYSCLK/296 */
    GPIO_SMP_SYSCLK_DIV_298,       /*!< Pin Sampling is in SYSCLK/298 */
    GPIO_SMP_SYSCLK_DIV_300,       /*!< Pin Sampling is in SYSCLK/300 */
    GPIO_SMP_SYSCLK_DIV_302,       /*!< Pin Sampling is in SYSCLK/302 */
    GPIO_SMP_SYSCLK_DIV_304,       /*!< Pin Sampling is in SYSCLK/304 */
    GPIO_SMP_SYSCLK_DIV_306,       /*!< Pin Sampling is in SYSCLK/306 */
    GPIO_SMP_SYSCLK_DIV_308,       /*!< Pin Sampling is in SYSCLK/308 */
    GPIO_SMP_SYSCLK_DIV_310,       /*!< Pin Sampling is in SYSCLK/310 */
    GPIO_SMP_SYSCLK_DIV_312,       /*!< Pin Sampling is in SYSCLK/312 */
    GPIO_SMP_SYSCLK_DIV_314,       /*!< Pin Sampling is in SYSCLK/314 */
    GPIO_SMP_SYSCLK_DIV_316,       /*!< Pin Sampling is in SYSCLK/316 */
    GPIO_SMP_SYSCLK_DIV_318,       /*!< Pin Sampling is in SYSCLK/318 */
    GPIO_SMP_SYSCLK_DIV_320,       /*!< Pin Sampling is in SYSCLK/320 */
    GPIO_SMP_SYSCLK_DIV_322,       /*!< Pin Sampling is in SYSCLK/322 */
    GPIO_SMP_SYSCLK_DIV_324,       /*!< Pin Sampling is in SYSCLK/324 */
    GPIO_SMP_SYSCLK_DIV_326,       /*!< Pin Sampling is in SYSCLK/326 */
    GPIO_SMP_SYSCLK_DIV_328,       /*!< Pin Sampling is in SYSCLK/328 */
    GPIO_SMP_SYSCLK_DIV_330,       /*!< Pin Sampling is in SYSCLK/330 */
    GPIO_SMP_SYSCLK_DIV_332,       /*!< Pin Sampling is in SYSCLK/332 */
    GPIO_SMP_SYSCLK_DIV_334,       /*!< Pin Sampling is in SYSCLK/334 */
    GPIO_SMP_SYSCLK_DIV_336,       /*!< Pin Sampling is in SYSCLK/336 */
    GPIO_SMP_SYSCLK_DIV_338,       /*!< Pin Sampling is in SYSCLK/338 */
    GPIO_SMP_SYSCLK_DIV_340,       /*!< Pin Sampling is in SYSCLK/340 */
    GPIO_SMP_SYSCLK_DIV_342,       /*!< Pin Sampling is in SYSCLK/342 */
    GPIO_SMP_SYSCLK_DIV_344,       /*!< Pin Sampling is in SYSCLK/344 */
    GPIO_SMP_SYSCLK_DIV_346,       /*!< Pin Sampling is in SYSCLK/346 */
    GPIO_SMP_SYSCLK_DIV_348,       /*!< Pin Sampling is in SYSCLK/348 */
    GPIO_SMP_SYSCLK_DIV_350,       /*!< Pin Sampling is in SYSCLK/350 */
    GPIO_SMP_SYSCLK_DIV_352,       /*!< Pin Sampling is in SYSCLK/352 */
    GPIO_SMP_SYSCLK_DIV_354,       /*!< Pin Sampling is in SYSCLK/354 */
    GPIO_SMP_SYSCLK_DIV_356,       /*!< Pin Sampling is in SYSCLK/356 */
    GPIO_SMP_SYSCLK_DIV_358,       /*!< Pin Sampling is in SYSCLK/358 */
    GPIO_SMP_SYSCLK_DIV_360,       /*!< Pin Sampling is in SYSCLK/360 */
    GPIO_SMP_SYSCLK_DIV_362,       /*!< Pin Sampling is in SYSCLK/362 */
    GPIO_SMP_SYSCLK_DIV_364,       /*!< Pin Sampling is in SYSCLK/364 */
    GPIO_SMP_SYSCLK_DIV_366,       /*!< Pin Sampling is in SYSCLK/366 */
    GPIO_SMP_SYSCLK_DIV_368,       /*!< Pin Sampling is in SYSCLK/368 */
    GPIO_SMP_SYSCLK_DIV_370,       /*!< Pin Sampling is in SYSCLK/370 */
    GPIO_SMP_SYSCLK_DIV_372,       /*!< Pin Sampling is in SYSCLK/372 */
    GPIO_SMP_SYSCLK_DIV_374,       /*!< Pin Sampling is in SYSCLK/374 */
    GPIO_SMP_SYSCLK_DIV_376,       /*!< Pin Sampling is in SYSCLK/376 */
    GPIO_SMP_SYSCLK_DIV_378,       /*!< Pin Sampling is in SYSCLK/378 */
    GPIO_SMP_SYSCLK_DIV_380,       /*!< Pin Sampling is in SYSCLK/380 */
    GPIO_SMP_SYSCLK_DIV_382,       /*!< Pin Sampling is in SYSCLK/382 */
    GPIO_SMP_SYSCLK_DIV_384,       /*!< Pin Sampling is in SYSCLK/384 */
    GPIO_SMP_SYSCLK_DIV_386,       /*!< Pin Sampling is in SYSCLK/386 */
    GPIO_SMP_SYSCLK_DIV_388,       /*!< Pin Sampling is in SYSCLK/388 */
    GPIO_SMP_SYSCLK_DIV_390,       /*!< Pin Sampling is in SYSCLK/390 */
    GPIO_SMP_SYSCLK_DIV_392,       /*!< Pin Sampling is in SYSCLK/392 */
    GPIO_SMP_SYSCLK_DIV_394,       /*!< Pin Sampling is in SYSCLK/394 */
    GPIO_SMP_SYSCLK_DIV_396,       /*!< Pin Sampling is in SYSCLK/396 */
    GPIO_SMP_SYSCLK_DIV_398,       /*!< Pin Sampling is in SYSCLK/398 */
    GPIO_SMP_SYSCLK_DIV_400,       /*!< Pin Sampling is in SYSCLK/400 */
    GPIO_SMP_SYSCLK_DIV_402,       /*!< Pin Sampling is in SYSCLK/402 */
    GPIO_SMP_SYSCLK_DIV_404,       /*!< Pin Sampling is in SYSCLK/404 */
    GPIO_SMP_SYSCLK_DIV_406,       /*!< Pin Sampling is in SYSCLK/406 */
    GPIO_SMP_SYSCLK_DIV_408,       /*!< Pin Sampling is in SYSCLK/408 */
    GPIO_SMP_SYSCLK_DIV_410,       /*!< Pin Sampling is in SYSCLK/410 */
    GPIO_SMP_SYSCLK_DIV_412,       /*!< Pin Sampling is in SYSCLK/412 */
    GPIO_SMP_SYSCLK_DIV_414,       /*!< Pin Sampling is in SYSCLK/414 */
    GPIO_SMP_SYSCLK_DIV_416,       /*!< Pin Sampling is in SYSCLK/416 */
    GPIO_SMP_SYSCLK_DIV_418,       /*!< Pin Sampling is in SYSCLK/418 */
    GPIO_SMP_SYSCLK_DIV_420,       /*!< Pin Sampling is in SYSCLK/420 */
    GPIO_SMP_SYSCLK_DIV_422,       /*!< Pin Sampling is in SYSCLK/422 */
    GPIO_SMP_SYSCLK_DIV_424,       /*!< Pin Sampling is in SYSCLK/424 */
    GPIO_SMP_SYSCLK_DIV_426,       /*!< Pin Sampling is in SYSCLK/426 */
    GPIO_SMP_SYSCLK_DIV_428,       /*!< Pin Sampling is in SYSCLK/428 */
    GPIO_SMP_SYSCLK_DIV_430,       /*!< Pin Sampling is in SYSCLK/430 */
    GPIO_SMP_SYSCLK_DIV_432,       /*!< Pin Sampling is in SYSCLK/432 */
    GPIO_SMP_SYSCLK_DIV_434,       /*!< Pin Sampling is in SYSCLK/434 */
    GPIO_SMP_SYSCLK_DIV_436,       /*!< Pin Sampling is in SYSCLK/436 */
    GPIO_SMP_SYSCLK_DIV_438,       /*!< Pin Sampling is in SYSCLK/438 */
    GPIO_SMP_SYSCLK_DIV_440,       /*!< Pin Sampling is in SYSCLK/440 */
    GPIO_SMP_SYSCLK_DIV_442,       /*!< Pin Sampling is in SYSCLK/442 */
    GPIO_SMP_SYSCLK_DIV_444,       /*!< Pin Sampling is in SYSCLK/444 */
    GPIO_SMP_SYSCLK_DIV_446,       /*!< Pin Sampling is in SYSCLK/446 */
    GPIO_SMP_SYSCLK_DIV_448,       /*!< Pin Sampling is in SYSCLK/448 */
    GPIO_SMP_SYSCLK_DIV_450,       /*!< Pin Sampling is in SYSCLK/450 */
    GPIO_SMP_SYSCLK_DIV_452,       /*!< Pin Sampling is in SYSCLK/452 */
    GPIO_SMP_SYSCLK_DIV_454,       /*!< Pin Sampling is in SYSCLK/454 */
    GPIO_SMP_SYSCLK_DIV_456,       /*!< Pin Sampling is in SYSCLK/456 */
    GPIO_SMP_SYSCLK_DIV_458,       /*!< Pin Sampling is in SYSCLK/458 */
    GPIO_SMP_SYSCLK_DIV_460,       /*!< Pin Sampling is in SYSCLK/460 */
    GPIO_SMP_SYSCLK_DIV_462,       /*!< Pin Sampling is in SYSCLK/462 */
    GPIO_SMP_SYSCLK_DIV_464,       /*!< Pin Sampling is in SYSCLK/464 */
    GPIO_SMP_SYSCLK_DIV_466,       /*!< Pin Sampling is in SYSCLK/466 */
    GPIO_SMP_SYSCLK_DIV_468,       /*!< Pin Sampling is in SYSCLK/468 */
    GPIO_SMP_SYSCLK_DIV_470,       /*!< Pin Sampling is in SYSCLK/470 */
    GPIO_SMP_SYSCLK_DIV_472,       /*!< Pin Sampling is in SYSCLK/472 */
    GPIO_SMP_SYSCLK_DIV_474,       /*!< Pin Sampling is in SYSCLK/474 */
    GPIO_SMP_SYSCLK_DIV_476,       /*!< Pin Sampling is in SYSCLK/476 */
    GPIO_SMP_SYSCLK_DIV_478,       /*!< Pin Sampling is in SYSCLK/478 */
    GPIO_SMP_SYSCLK_DIV_480,       /*!< Pin Sampling is in SYSCLK/480 */
    GPIO_SMP_SYSCLK_DIV_482,       /*!< Pin Sampling is in SYSCLK/482 */
    GPIO_SMP_SYSCLK_DIV_484,       /*!< Pin Sampling is in SYSCLK/484 */
    GPIO_SMP_SYSCLK_DIV_486,       /*!< Pin Sampling is in SYSCLK/486 */
    GPIO_SMP_SYSCLK_DIV_488,       /*!< Pin Sampling is in SYSCLK/488 */
    GPIO_SMP_SYSCLK_DIV_490,       /*!< Pin Sampling is in SYSCLK/490 */
    GPIO_SMP_SYSCLK_DIV_492,       /*!< Pin Sampling is in SYSCLK/492 */
    GPIO_SMP_SYSCLK_DIV_494,       /*!< Pin Sampling is in SYSCLK/494 */
    GPIO_SMP_SYSCLK_DIV_496,       /*!< Pin Sampling is in SYSCLK/496 */
    GPIO_SMP_SYSCLK_DIV_498,       /*!< Pin Sampling is in SYSCLK/498 */
    GPIO_SMP_SYSCLK_DIV_500,       /*!< Pin Sampling is in SYSCLK/500 */
    GPIO_SMP_SYSCLK_DIV_502,       /*!< Pin Sampling is in SYSCLK/502 */
    GPIO_SMP_SYSCLK_DIV_504,       /*!< Pin Sampling is in SYSCLK/504 */
    GPIO_SMP_SYSCLK_DIV_506,       /*!< Pin Sampling is in SYSCLK/506 */
    GPIO_SMP_SYSCLK_DIV_508,       /*!< Pin Sampling is in SYSCLK/508 */
    GPIO_SMP_SYSCLK_DIV_510        /*!< Pin Sampling is in SYSCLK/510 */
} GPIO_SmpClk;

/**
  * @}
  */

/** @defgroup GPIO_DIRECTION GPIO Pin Input/Output Direction
  * @{
  * @brief  Macro definitions about GPIO Input/Output Direction.
  */
typedef enum {
    GPIO_DIR_MODE_IN = 0U,    /*!< direction mode is input */
    GPIO_DIR_MODE_OUT         /*!< direction mode is output */
} GPIO_Direction;

/**
  * @}
  */

/** @defgroup GPIO_QUALIFICATIONMODE GPIO Pin Input Sampling Mode Selection
  * @{
  * @brief  Macro definitions about GPIO input sampling mode.
  */
typedef enum {
    GPIO_QUAL_SYNC = 0U,    /*!< Synchronization mode is 1 sample */
    GPIO_QUAL_3SAMPLE,      /*!< Synchronization mode is 3 sample */
    GPIO_QUAL_6SAMPLE,      /*!< Synchronization mode is 6 sample */
    GPIO_QUAL_ASYNC         /*!< Asynchronization mode */
} GPIO_QualificationMode;

/**
  * @}
  */

/** @defgroup GPIO_ANALOGMODE GPIO Pin Analog Mode Enable/Disable
  * @{
  * @brief  Macro definitions about GPIO analog mode enable/disable.
  */
typedef enum {
    GPIO_ANALOG_DISABLED = 0U,    /*!< Pin is in digital mode */
    GPIO_ANALOG_ENABLED           /*!< Pin is in analog mode */
} GPIO_AnalogMode;

/**
  * @}
  */

/** @defgroup GPIO_CORESELECT GPIO Pin CPU1/2 Selection
  * @{
  * @brief  Macro definitions about GPIO pin CPU1/2 selection.
  */
typedef enum {
    GPIO_CORE_CPU1 = 0U,    /*!< CPU1 selected as controller core */
    GPIO_CORE_CPU2          /*!< CPU2 selected as controller core */
} GPIO_CoreSelect;

/**
  * @}
  */

/** @defgroup GPIO_DRVLEV GPIO Pin Output Drive Strength Level
  * @{
  * @brief  Macro definitions about GPIO output drive strength.
  */
typedef enum {
    GPIO_DRV_LOW = 0U,    /*!< output drive strength level is low */
    GPIO_DRV_MIDDLE,      /*!< output drive strength level is middle */
    GPIO_DRV_HIGH,        /*!< output drive strength level is high */
    GPIO_DRV_MAX          /*!< output drive strength level is max */
} GPIO_DrvLev;

/**
  * @}
  */

/** @defgroup GPIO_EXTERNALINTNUM GPIO External Interrupt Number(= XINTn TI)
  * @{
  * @brief  Macro definitions about GPIO external interrupt number.
  */
typedef enum {
    GPIO_INT_XINT1 = 0U,    /*!< External Interrupt 1(= XINT1 TI) */
    GPIO_INT_XINT2,         /*!< External Interrupt 2(= XINT2 TI) */
    GPIO_INT_XINT3,         /*!< External Interrupt 3(= XINT3 TI) */
    GPIO_INT_XINT4,         /*!< External Interrupt 4(= XINT4 TI) */
    GPIO_INT_XINT5          /*!< External Interrupt 5(= XINT5 TI) */
} GPIO_ExternalIntNum;

/**
  * @}
  */

/** @defgroup GPIO_INTTYPE GPIO Interrupt Type
  * @{
  * @brief  Macro definitions about GPIO interrupt type.
  */
typedef enum {
    GPIO_INT_TYPE_FALLING_EDGE = 0x0U,    /*!< Interrupt on falling edge */
    GPIO_INT_TYPE_RISING_EDGE  = 0x4U,    /*!< Interrupt on rising edge */
    GPIO_INT_TYPE_BOTH_EDGES   = 0xCU     /*!< Interrupt on both edges */
} GPIO_IntType;

/**
  * @}
  */

/** @defgroup GPIO_PINMASK GPIO Pin Mask
  * @{
  * @brief  Macro definitions about GPIO pin mask definition.
  * @note   Multiple pins can be set together.
  */
#define GPIO_PIN_BIT_0     (0x1UL << GPIO_PIN_0)     /*!< GPIO pins bit 0 */
#define GPIO_PIN_BIT_1     (0x1UL << GPIO_PIN_1)     /*!< GPIO pins bit 1 */
#define GPIO_PIN_BIT_2     (0x1UL << GPIO_PIN_2)     /*!< GPIO pins bit 2 */
#define GPIO_PIN_BIT_3     (0x1UL << GPIO_PIN_3)     /*!< GPIO pins bit 3 */
#define GPIO_PIN_BIT_4     (0x1UL << GPIO_PIN_4)     /*!< GPIO pins bit 4 */
#define GPIO_PIN_BIT_5     (0x1UL << GPIO_PIN_5)     /*!< GPIO pins bit 5 */
#define GPIO_PIN_BIT_6     (0x1UL << GPIO_PIN_6)     /*!< GPIO pins bit 6 */
#define GPIO_PIN_BIT_7     (0x1UL << GPIO_PIN_7)     /*!< GPIO pins bit 7 */
#define GPIO_PIN_BIT_8     (0x1UL << GPIO_PIN_8)     /*!< GPIO pins bit 8 */
#define GPIO_PIN_BIT_9     (0x1UL << GPIO_PIN_9)     /*!< GPIO pins bit 9 */
#define GPIO_PIN_BIT_10    (0x1UL << GPIO_PIN_10)    /*!< GPIO pins bit 10 */
#define GPIO_PIN_BIT_11    (0x1UL << GPIO_PIN_11)    /*!< GPIO pins bit 11 */
#define GPIO_PIN_BIT_12    (0x1UL << GPIO_PIN_12)    /*!< GPIO pins bit 12 */
#define GPIO_PIN_BIT_13    (0x1UL << GPIO_PIN_13)    /*!< GPIO pins bit 13 */
#define GPIO_PIN_BIT_14    (0x1UL << GPIO_PIN_14)    /*!< GPIO pins bit 14 */
#define GPIO_PIN_BIT_15    (0x1UL << GPIO_PIN_15)    /*!< GPIO pins bit 15 */
#define GPIO_PIN_BIT_16    (0x1UL << GPIO_PIN_16)    /*!< GPIO pins bit 16 */
#define GPIO_PIN_BIT_17    (0x1UL << GPIO_PIN_17)    /*!< GPIO pins bit 17 */
#define GPIO_PIN_BIT_18    (0x1UL << GPIO_PIN_18)    /*!< GPIO pins bit 18 */
#define GPIO_PIN_BIT_19    (0x1UL << GPIO_PIN_19)    /*!< GPIO pins bit 19 */
#define GPIO_PIN_BIT_20    (0x1UL << GPIO_PIN_20)    /*!< GPIO pins bit 20 */
#define GPIO_PIN_BIT_21    (0x1UL << GPIO_PIN_21)    /*!< GPIO pins bit 21 */
#define GPIO_PIN_BIT_22    (0x1UL << GPIO_PIN_22)    /*!< GPIO pins bit 22 */
#define GPIO_PIN_BIT_23    (0x1UL << GPIO_PIN_23)    /*!< GPIO pins bit 23 */
#define GPIO_PIN_BIT_24    (0x1UL << GPIO_PIN_24)    /*!< GPIO pins bit 24 */
#define GPIO_PIN_BIT_25    (0x1UL << GPIO_PIN_25)    /*!< GPIO pins bit 25 */
#define GPIO_PIN_BIT_26    (0x1UL << GPIO_PIN_26)    /*!< GPIO pins bit 26 */
#define GPIO_PIN_BIT_27    (0x1UL << GPIO_PIN_27)    /*!< GPIO pins bit 27 */
#define GPIO_PIN_BIT_28    (0x1UL << GPIO_PIN_28)    /*!< GPIO pins bit 28 */
#define GPIO_PIN_BIT_29    (0x1UL << GPIO_PIN_29)    /*!< GPIO pins bit 29 */
#define GPIO_PIN_BIT_30    (0x1UL << GPIO_PIN_30)    /*!< GPIO pins bit 30 */
#define GPIO_PIN_BIT_31    (0x1UL << GPIO_PIN_31)    /*!< GPIO pins bit 31 */

/**
  * @}
  */

/** @defgroup GPIO_PADCONFIG GPIO Pad Configuration
  * @{
  * @brief  Macro definitions about GPIO pad configuration definition.
  */
#define GPIO_PIN_TYPE_STD         (0x00000000UL)    /*!< Push-pull output or floating input */
#define GPIO_PIN_TYPE_PULLUP      (0x00000001UL)    /*!< Pull-up enable for input(Pull-up mode first, when pull-up and pull-down all enabled) */
#define GPIO_PIN_TYPE_INVERT      (0x00000002UL)    /*!< Invert polarity on input */
#define GPIO_PIN_TYPE_OD          (0x00000004UL)    /*!< Open-drain on output */
#define GPIO_PIN_TYPE_PULLDOWN    (0x00000008UL)    /*!< Pull-down enable for input(GPIOH no this function) */

/**
  * @}
  */

/** @defgroup GPIO_XINTOFFSET GPIO XINT address offset
  * @{
  * @brief  Macro definitions about GPIO XINT address offset definition.
  */
#define GPIO_EXTI_XINT_BASE_OFFSET    (0x00000018UL)    /*!< XINT base address offset */
#define GPIO_EXTI_XINT_CNTR_OFFSET    (0x0000002CUL)    /*!< XINT counter address offset */
#define GPIO_EXTI_XINT_PR_OFFSET      (0x00000038UL)    /*!< XINT pending address offset */

/**
  * @}
  */

/** @defgroup GPIO_XINTFUNCBIT GPIO XINT function bits
  * @{
  * @brief  Macro definitions about GPIO XINT function bits definition.
  */
#define GPIO_EXTI_XINT_DMAEN    (0x00000020UL)    /*!< XINT DMA request enable/disable bit */
#define GPIO_EXTI_XINT_POLA     (0x0000000CUL)    /*!< XINT polarity select bit */
#define GPIO_EXTI_XINT_SWIER    (0x00000002UL)    /*!< XINT software interrupt enable bit */
#define GPIO_EXTI_XINT_EN       (0x00000001UL)    /*!< XINT enable bit */

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
  * \brief  Enable GPIO digital mode
  * \note   If this digital mode can be used to one pin, the analog mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_enableDigtalModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->AMSEL.WORDVAL, pinMask);
}

/**
  * \brief  Enable GPIO analog mode
  * \note   If this analog mode can be used to one pin, the digital mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_enableAnalogModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->AMSEL.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO input floating Mode
  * \note   If this floating mode can be used to one pin, the pull-up/pull-down mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setInFloatModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->PE.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO input pull-up Mode
  * \note   If this pull-up mode can be used to one pin, the pull-down/floating mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setInPullupModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->PS.WORDVAL, pinMask);
    SET_BIT(port->PE.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO input pull-down Mode
  * \note   If this pull-down mode can be used to one pin, the pull-up/floating mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setInPullDownModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->PS.WORDVAL, pinMask);
    SET_BIT(port->PE.WORDVAL, pinMask);
}

/**
  * \brief  Disable GPIO input polarity invert function
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_disableInPolaInvertPortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->INV.WORDVAL, pinMask);
}

/**
  * \brief  Enable GPIO input polarity invert function
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_enableInPolaInvertPortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->INV.WORDVAL, pinMask);
}

/**
  * \brief  Set GPIO input schmidt trigger mode
  * \note   If this trigger mode can be used to one pin, the buffer trigger mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setInSchmidtModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->IS.WORDVAL, pinMask);
}

/**
  * \brief  Set GPIO input buffer trigger mode
  * \note   If this trigger mode can be used to one pin, the schmidt trigger mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setInBufferModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->IS.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO input mode
  * \note   If this input mode can be used to one pin, the output mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setInModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->DIR.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO output mode
  * \note   If this output mode can be used to one pin, the input mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setOutModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->DIR.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO output push-pull mode
  * \note   If this mode can be used to one pin, the open-drain mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setOutPPModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->ODR.WORDVAL, pinMask);
}

/**
  * \brief  Sets GPIO output open-drain mode
  * \note   If this mode can be used to one pin, the push-pull mode is disabled automatically.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setOutODModePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->ODR.WORDVAL, pinMask);
}

/**
  * \brief  Disable GPIO output waveform improvement
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_disableOutWaveImproPortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->DT.WORDVAL, pinMask);
}

/**
  * \brief  Enable GPIO output waveform improvement
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_enableOutWaveImproPortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->DT.WORDVAL, pinMask);
}

/**
  * \brief  Reads the data on the specified port.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \return Returns the value in the data register for the specified pin
  *                - 0: Pin output value is low
  *                - 1: Pin output value is high
  */
static inline uint32_t GPIO_readPin (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    return READ_BIT(port->DAT.WORDVAL, (0x1UL << pin))? 1UL : 0UL;
}

/**
  * \brief  Reads the data register value for specified pin.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \return Returns the value in the data register for the specified pin(user set)
  *                - 0: Pin output value is low
  *                - 1: Pin output value is high
  */
static inline uint32_t GPIO_readPinDataRegister (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    return READ_BIT(port->DATR.WORDVAL, (0x1UL << pin))? 1UL : 0UL;
}

/**
  * \brief  Writes a value to the specified pin.
  * \param  port    GPIO port address
  *                  - GPIOA: GPIO A port
  *                  - GPIOB: GPIO B port
  *                  - GPIOC: GPIO C port
  *                  - GPIOD: GPIO D port
  *                  - GPIOE: GPIO E port
  *                  - GPIOF: GPIO F port
  *                  - GPIOG: GPIO G port
  *                  - GPIOH: GPIO H port
  * \param  pin     GPIO pin number
  *                  This parameter can be any value of @ref GPIO_PINNUM
  * \param  outVal  Pin output value to write to the pin
  *                  - 0: Pin output value is low
  *                  - 1: Pin output value is high
  */
static inline void GPIO_writePin (GPIO_TypeDef *port, GPIO_PinNum pin, uint32_t outVal)
{
    if (outVal == 0UL)
    {
        WRITE_REG(port->CLR.WORDVAL, (0x1UL << pin));
    }
    else
    {
        WRITE_REG(port->SET.WORDVAL, (0x1UL << pin));
    }
}

/**
  * \brief  Sets the specified pin.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  */
static inline void GPIO_setPin (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    WRITE_REG(port->SET.WORDVAL, (0x1UL << pin));
}

/**
  * \brief  Clears the specified pin.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  */
static inline void GPIO_clearPin (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    WRITE_REG(port->CLR.WORDVAL, (0x1UL << pin));
}

/**
  * \brief  Toggles the specified pin.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  */
static inline void GPIO_togglePin (GPIO_TypeDef *port, GPIO_PinNum pin)
{
    WRITE_REG(port->TOGGLE.WORDVAL, (0x1UL << pin));
}

/**
  * \brief  Reads the data on the specified port.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \return Returns the value available on pin for the specified port
  *                Bit 0 represents GPIO port pin 0, bit 1 represents GPIO port
  *                pin 1, and so on.
  */
static inline uint32_t GPIO_readPortData (GPIO_TypeDef *port)
{
    return READ_REG(port->DAT.WORDVAL);
}

/**
  * \brief  Reads the data written in GPIO Data Register.
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \return Returns the value in the data register for the specified port(user set)
  *                Bit 0 represents GPIO port pin 0, bit 1 represents GPIO port
  *                pin 1, and so on.
  */
static inline uint32_t GPIO_readPortDataRegister (GPIO_TypeDef *port)
{
    return READ_REG(port->DATR.WORDVAL);
}

/**
  * \brief  Sets all of the specified pins on the specified port.
  * \param  port    GPIO port address
  *                  - GPIOA: GPIO A port
  *                  - GPIOB: GPIO B port
  *                  - GPIOC: GPIO C port
  *                  - GPIOD: GPIO D port
  *                  - GPIOE: GPIO E port
  *                  - GPIOF: GPIO F port
  *                  - GPIOG: GPIO G port
  *                  - GPIOH: GPIO H port
  * \param  outVal  A bit-packed value, where each bit represents a bit on a GPIO port.
  *                  Bit 0 represents GPIO port pin 0, bit 1 represents GPIO port
  *                  pin 1, and so on.
  */
static inline void GPIO_writePortData (GPIO_TypeDef *port, uint32_t outVal)
{
    WRITE_REG(port->DAT.WORDVAL, outVal);
}

/**
  * \brief  Sets all of the specified pins on the specified port.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_setPortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    WRITE_REG(port->SET.WORDVAL, pinMask);
}

/**
  * \brief  Clears all of the specified pins on the specified port.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_clearPortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    WRITE_REG(port->CLR.WORDVAL, pinMask);
}

/**
  * \brief  Toggles all of the specified pins on the specified port.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_togglePortPins (GPIO_TypeDef *port, uint32_t pinMask)
{
    WRITE_REG(port->TOGGLE.WORDVAL, pinMask);
}

/**
  * \brief  Locks the configuration of the specified pins on the specified port.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_lockPortConfig (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->LOCK.WORDVAL, pinMask);
}

/**
  * \brief  Unlocks the configuration of the specified pins on the specified port.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_unlockPortConfig (GPIO_TypeDef *port, uint32_t pinMask)
{
    CLEAR_BIT(port->LOCK.WORDVAL, pinMask);
}

/**
  * \brief  Commits the lock configuration of the specified pins on the specified port.
  * \note   Multiple pins can be set together.
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pinMask  GPIO pin mask
  *                   This parameter can be any value of @ref GPIO_PINMASK
  */
static inline void GPIO_commitPortConfig (GPIO_TypeDef *port, uint32_t pinMask)
{
    SET_BIT(port->CR.WORDVAL, pinMask);
}

/**
  * \brief  Sets the interrupt type of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  * \param  intType    GPIO interrupt type
  *                     This parameter can be any value of @ref GPIO_INTTYPE
  */
static inline void GPIO_setInterruptType (GPIO_ExternalIntNum extIntNum, GPIO_IntType intType)
{
    MODIFY_REG(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_POLA, intType);
}

/**
  * \brief  Gets the interrupt type of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  * \return Returns one of the flags described for GPIO_setInterruptType()
  */
static inline GPIO_IntType GPIO_getInterruptType (GPIO_ExternalIntNum extIntNum)
{
    return (GPIO_IntType)(READ_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_POLA));
}

/**
  * \brief  Enables the interrupt of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
static inline void GPIO_enableInterrupt (GPIO_ExternalIntNum extIntNum)
{
    SET_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_EN);
}

/**
  * \brief  Disables the interrupt of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
static inline void GPIO_disableInterrupt (GPIO_ExternalIntNum extIntNum)
{
    CLEAR_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_EN);
}

/**
  * \brief  Triggers the software interrupt of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
static inline void GPIO_triggerSoftwareInterrupt (GPIO_ExternalIntNum extIntNum)
{
    SET_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_SWIER);
}

/**
  * \brief  Enables the DMA request of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
static inline void GPIO_enableInterruptDMA (GPIO_ExternalIntNum extIntNum)
{
    SET_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_DMAEN);
}

/**
  * \brief  Disables the DMA request of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
static inline void GPIO_disableInterruptDMA (GPIO_ExternalIntNum extIntNum)
{
    CLEAR_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_BASE_OFFSET + (extIntNum << 2)), GPIO_EXTI_XINT_DMAEN);
}

/**
  * \brief  Gets the interrupt counter of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  * \return Returns the interrupt counter value
  */
static inline uint32_t GPIO_getInterruptCounter (GPIO_ExternalIntNum extIntNum)
{
    return READ_REG(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_CNTR_OFFSET + (extIntNum << 2)));
}

/**
  * \brief  Gets the interrupt flag of the specified pin
  * \param  extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  * \return Returns one of the interrupt flags
  */
static inline uint32_t GPIO_getInterruptFlag (GPIO_ExternalIntNum extIntNum)
{
    return READ_BIT(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_PR_OFFSET), (0x1UL << extIntNum));
}

/**
  * \brief  Clears the interrupt flag of the specified pin
  * \param extIntNum  GPIO external interrupt number
  *                     This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
static inline void GPIO_clearInterruptFlag (GPIO_ExternalIntNum extIntNum)
{
    WRITE_REG(TYPE32(EXTI_BASE + GPIO_EXTI_XINT_PR_OFFSET), (0x1UL << extIntNum));
}


/**
  * \brief  Sets the direction and mode of the specified pin
  * \param  port   GPIO port address
  *                 - GPIOA: GPIO A port
  *                 - GPIOB: GPIO B port
  *                 - GPIOC: GPIO C port
  *                 - GPIOD: GPIO D port
  *                 - GPIOE: GPIO E port
  *                 - GPIOF: GPIO F port
  *                 - GPIOG: GPIO G port
  *                 - GPIOH: GPIO H port
  * \param  pin    GPIO pin number
  *                 This parameter can be any value of @ref GPIO_PINNUM
  * \param  pinIO  GPIO pin direction mode
  *                 This parameter can be any value of @ref GPIO_DIRECTION
  */
extern void GPIO_setDirectionMode (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_Direction pinIO);

/**
  * \brief  Gets the direction mode of one pin
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \return Returns one of the enumerated data types described for GPIO_setDirectionMode()
  *                - GPIO_DIR_MODE_IN
  *                - GPIO_DIR_MODE_OUT
  */
extern GPIO_Direction GPIO_getDirectionMode (GPIO_TypeDef *port, GPIO_PinNum pin);

/**
  * \brief  Sets the pad configuration for the specified pin
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pin      GPIO pin number
  *                   This parameter can be any value of @ref GPIO_PINNUM
  * \param  pinType  GPIO pin type
  *                   This parameter can be any value of @ref GPIO_PADCONFIG
  */
extern void GPIO_setPadConfig (GPIO_TypeDef *port, GPIO_PinNum pin, uint32_t pinType);

/**
  * \brief  Gets the pad configuration for the specified pin
  * \note   Multiple pin-type can be return together
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \return Returns a bit field of the values
  *                This parameter can be any value of @ref GPIO_PADCONFIG
  */
extern uint32_t GPIO_getPadConfig (GPIO_TypeDef *port, GPIO_PinNum pin);

/**
  * \brief  Sets the qualification mode for the specified pin
  * \param  port           GPIO port address
  *                         - GPIOA: GPIO A port
  *                         - GPIOB: GPIO B port
  *                         - GPIOC: GPIO C port
  *                         - GPIOD: GPIO D port
  *                         - GPIOE: GPIO E port
  *                         - GPIOF: GPIO F port
  *                         - GPIOG: GPIO G port
  *                         - GPIOH: GPIO H port
  * \param  pin            GPIO pin number
  *                         This parameter can be any value of @ref GPIO_PINNUM
  * \param  qualification  GPIO qualification mode
  *                         This parameter can be any value of @ref GPIO_SMPMODE
  */
extern void GPIO_setQualificationMode (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_QualificationMode qualification);

/**
  * \brief  Gets the qualification type for the specified pin
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \return Returns the qualification mode in the form of one of the values
  */
extern GPIO_QualificationMode GPIO_getQualificationMode (GPIO_TypeDef *port, GPIO_PinNum pin);

/**
  * \brief  Sets the qualification mode for the specified pin
  * \param  port     GPIO port address
  *                   - GPIOA: GPIO A port
  *                   - GPIOB: GPIO B port
  *                   - GPIOC: GPIO C port
  *                   - GPIOD: GPIO D port
  *                   - GPIOE: GPIO E port
  *                   - GPIOF: GPIO F port
  *                   - GPIOG: GPIO G port
  *                   - GPIOH: GPIO H port
  * \param  pin      GPIO pin number
  *                   This parameter can be any value of @ref GPIO_PINNUM
  * \param  divider  GPIO sampling divider
  *                   This parameter can be any value of @ref GPIO_SMPCLK
  */
extern void GPIO_setQualificationPeriod (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_SmpClk divider);

/**
  * \brief  Selects the controller core of a specified pin
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOC: GPIO D port
  *                - GPIOC: GPIO E port
  *                - GPIOC: GPIO F port
  *                - GPIOC: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \param  core  GPIO is the core controller of the specified pin
  *                This parameter can be any value of @ref GPIO_CORESELECT
  */
extern void GPIO_setControllerCore (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_CoreSelect core);

/**
  * \brief  Sets the drive strength for the specified pin
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \param  lev   GPIO output drive strength
  *                This parameter can be any value of @ref GPIO_DRVLEV
  */
extern void GPIO_setDriveLevel (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_DrvLev lev);

/**
  * \brief  Gets the drive strength for the specified pin
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  */
extern GPIO_DrvLev GPIO_getDriveLevel (GPIO_TypeDef *port, GPIO_PinNum pin);

/**
  * \brief  Sets the qualification mode for the specified pin
  * \param  port  GPIO port address
  *                - GPIOA: GPIO A port
  *                - GPIOB: GPIO B port
  *                - GPIOC: GPIO C port
  *                - GPIOD: GPIO D port
  *                - GPIOE: GPIO E port
  *                - GPIOF: GPIO F port
  *                - GPIOG: GPIO G port
  *                - GPIOH: GPIO H port
  * \param  pin   GPIO pin number
  *                This parameter can be any value of @ref GPIO_PINNUM
  * \param  mode  GPIO analog mode
  *                This parameter can be any value of @ref GPIO_ANALOGMODE
  */
extern void GPIO_setAnalogMode (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_AnalogMode mode);

/**
  * \brief  Configures the alternate function of one GPIO pin
  * \param  port       GPIO port address
  *                     - GPIOA: GPIO A port
  *                     - GPIOB: GPIO B port
  *                     - GPIOC: GPIO C port
  *                     - GPIOD: GPIO D port
  *                     - GPIOE: GPIO E port
  *                     - GPIOF: GPIO F port
  *                     - GPIOG: GPIO G port
  *                     - GPIOH: GPIO H port
  * \param  pin        GPIO pin number
  *                     This parameter can be any value of @ref GPIO_PINNUM
  * \param  pinConfig  GPIO alternate function
  *                     This parameter can be any value of @ref GPIO_ALTFUNC
  */
extern void GPIO_setPinConfig (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_AltFunc pinConfig);

/**
  * \brief  Sets the external interrupt pin
  * \param  port      GPIO port address
  *                    - GPIOA: GPIO A port
  *                    - GPIOB: GPIO B port
  *                    - GPIOC: GPIO C port
  *                    - GPIOD: GPIO D port
  *                    - GPIOE: GPIO E port
  *                    - GPIOF: GPIO F port
  *                    - GPIOG: GPIO G port
  *                    - GPIOH: GPIO H port
  * \param pin        GPIO pin number
  *                    This parameter can be any value of @ref GPIO_PINNUM
  * \param extIntNum  GPIO external interrupt number
  *                    This parameter can be any value of @ref GPIO_EXTERNALINTNUM
  */
extern void GPIO_setInterruptPin (GPIO_TypeDef *port, GPIO_PinNum pin, GPIO_ExternalIntNum extIntNum);


#ifdef __cplusplus
}
#endif


#endif /* __GPIO_H__ */
