#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_init.h"
#if defined(MV88F78X60)
#include "ddr3_axp_vars.h"
#elif defined(MV88F67XX)
#include "ddr3_a370_vars.h"
#elif defined(MV88F672X)
#include "ddr3_a375_vars.h"
#endif
#ifdef STATIC_TRAINING
#endif
#ifdef DUNIT_STATIC
#endif
#if defined(DUNIT_STATIC) || defined(STATIC_TRAINING)
#endif
#if defined(MV88F672X)
#endif
#ifdef DUNIT_STATIC
#endif
#ifdef DUNIT_SPD
#endif
#ifndef MV88F67XX
#if defined(MV88F672X)
#else
#endif
#endif
#if !defined(STATIC_TRAINING)
#if defined(MV88F672X)
#endif
#if defined(MV88F672X)
#else
#endif
#if defined(MV88F672X)
#else
#endif
#if defined(MV88F672X)
#else
#endif
#endif /*  !defined(STATIC_TRAINING) */
#if defined(MV88F672X)
#else
#endif
#ifdef CONFIG_SPD_EEPROM
#endif
#if !defined(MV88F672X)
#endif
#if defined(MV88F672X)
#else
#endif
#if defined(ECC_SUPPORT)
#else
#endif
#if defined(ECC_SUPPORT) && defined(AUTO_DETECTION_SUPPORT)
#endif
#if defined(ECC_SUPPORT) && defined(AUTO_DETECTION_SUPPORT)
#endif
#ifdef DQS_CLK_ALIGNED
#endif
#ifdef DUNIT_STATIC
#ifdef ECC_SUPPORT
#endif
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#if defined(AUTO_DETECTION_SUPPORT)
#endif
#if defined(MV88F672X)
#endif
#endif
#ifdef DUNIT_SPD
#endif
#if defined(MV88F672X)
#else
#endif
#if !defined(MV88F67XX)
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60)
#endif /* end defined(MV88F78X60) */
#endif /* end !defined(MV88F67XX) */
#ifdef STATIC_TRAINING
#if defined(MV88F78X60)
#endif
#else
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#endif
#if !defined(STATIC_TRAINING)
#endif
#if !defined(MV88F67XX)
#if defined(MV88F78X60)
#endif /* end defined(MV88F78X60) */
#endif /* end !defined(MV88F67XX) */
#ifdef STATIC_TRAINING
#else
#endif
#if defined(MV88F672X)
#else
#if defined(MV88F78X60)
#elif defined(MV88F67XX)
#endif
#endif
#if defined(MV88F672X)
#else
#if defined(MV88F78X60)
#endif
#endif
#ifdef STATIC_TRAINING
#endif
#if defined(DB_78X60_PCAC)
#elif defined(DB_78X60_AMC)
#elif defined(DB_88F6710_PCAC)
#elif defined(RD_88F6710)
#elif defined(MV88F672X)
#else
#endif
#ifdef DUNIT_STATIC
#endif
#ifdef AUTO_DETECTION_SUPPORT
#ifdef DB_88F6710
#else
#endif
#endif
#if defined(DB_88F78X60_REV2)
#ifdef AUTO_DETECTION_SUPPORT
#endif
#endif
#if !defined(MV88F672X)
#if defined(MV_INCLUDE_CLK_PWR_CNTRL)
#endif
#if defined(MV_INCLUDE_CLK_PWR_CNTRL)
#endif
#endif
#if defined(MV88F672X)
#endif
