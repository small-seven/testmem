#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
#include <irq_func.h>
#include <asm/io.h>
#ifdef CONFIG_FSL_LSCH2
#include <asm/arch/immap_lsch2.h>
#elif defined(CONFIG_FSL_LSCH3)
#include <asm/arch/immap_lsch3.h>
#else
#include <asm/immap_85xx.h>
#endif
#include "vid.h"
#if defined(CONFIG_VOL_MONITOR_IR36021_SET) || \
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#define MAX_LOOP_WAIT_NEW_VOL		100
#define MAX_LOOP_WAIT_VOL_STABLE	100
#define NUM_READINGS    4       /* prefer to be power of 2 for efficiency */
#ifdef CONFIG_VOL_MONITOR_INA220
#define WAIT_FOR_ADC	532	/* wait for 532 microseconds for ADC */
#define ADC_MIN_ACCURACY	4
#else
#define WAIT_FOR_ADC	138	/* wait for 138 microseconds for ADC */
#define ADC_MIN_ACCURACY	4
#endif
#ifdef CONFIG_VOL_MONITOR_INA220
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_VOL_MONITOR_IR36021_READ
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_VOL_MONITOR_LTC3882_READ
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_VOL_MONITOR_INA220
#elif defined CONFIG_VOL_MONITOR_IR36021_READ
#elif defined CONFIG_VOL_MONITOR_LTC3882_READ
#else
#endif
#ifdef CONFIG_VOL_MONITOR_IR36021_SET
#ifdef CONFIG_FSL_LSCH2
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_VOL_MONITOR_LTC3882_SET
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_VOL_MONITOR_IR36021_SET
#elif defined CONFIG_VOL_MONITOR_LTC3882_SET
#else
#endif
#ifdef CONFIG_FSL_LSCH3
#if defined(CONFIG_VOL_MONITOR_IR36021_SET) || \
#else
#endif
#ifdef CONFIG_ARCH_LX2160A
#else
#ifdef CONFIG_ARCH_LS1088A
#else
#endif
#endif
#if defined(CONFIG_VOL_MONITOR_IR36021_SET) || \
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_VOL_MONITOR_LTC3882_SET
#else
#endif
#else /* !CONFIG_FSL_LSCH3 */
#if defined(CONFIG_FSL_LSCH2)
#else
#endif
#if defined(CONFIG_VOL_MONITOR_IR36021_SET) || \
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_FSL_LSCH2
#else
#endif
#endif
#if defined(CONFIG_VOL_MONITOR_IR36021_SET) || \
#endif
