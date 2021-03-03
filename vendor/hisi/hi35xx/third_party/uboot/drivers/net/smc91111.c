#include <common.h>
#include <command.h>
#include <config.h>
#include <malloc.h>
#include "smc91111.h"
#include <net.h>
#define POWER_DOWN	0
#define NO_AUTOPROBE
#define SMC_DEBUG 0
#if SMC_DEBUG > 1
#endif
#ifndef CONFIG_SMC_AUTONEG_TIMEOUT
#define CONFIG_SMC_AUTONEG_TIMEOUT 10
#endif
#define MEMORY_WAIT_TIME 16
#if (SMC_DEBUG > 2 )
#define PRINTK3(args...) printf(args)
#else
#define PRINTK3(args...)
#endif
#if SMC_DEBUG > 1
#define PRINTK2(args...) printf(args)
#else
#define PRINTK2(args...)
#endif
#ifdef SMC_DEBUG
#define PRINTK(args...) printf(args)
#else
#define PRINTK(args...)
#endif
#define LAN91C111_MEMORY_MULTIPLIER	(1024*2)
#ifndef CONFIG_SMC91111_BASE
#error "SMC91111 Base address must be passed to initialization funciton"
#endif
#define SMC_DEV_NAME "SMC91111"
#define SMC_PHY_ADDR 0x0000
#define SMC_ALLOC_MAX_TRY 5
#define SMC_TX_TIMEOUT 30
#define SMC_PHY_CLOCK_DELAY 1000
#define ETH_ZLEN 60
#ifdef	CONFIG_SMC_USE_32_BIT
#define USE_32_BIT  1
#else
#undef USE_32_BIT
#endif
#ifdef SHARED_RESOURCES
#else
# define swap_to(x)
#endif
#ifndef CONFIG_SMC91111_EXT_PHY
#endif /* !CONFIG_SMC91111_EXT_PHY */
#ifdef CONFIG_SMC_USE_IOFUNCS
#endif  /* CONFIG_SMC_USE_IOFUNCS */
#if SMC_DEBUG > 2
#endif
#define tx_done(dev) 1
#if defined(CONFIG_SMC91111_EXT_PHY)
#else
#endif
#if SMC_DEBUG > 2
#endif
#ifdef USE_32_BIT
#else
#endif
#ifdef USE_32_BIT
#else
#endif /* USE_32_BIT */
#ifdef USE_32_BIT
#else
#endif
#ifndef CONFIG_SMC91111_EXT_PHY
#endif
#ifdef USE_32_BIT
#endif
#ifdef USE_32_BIT
#else
#endif
#ifdef USE_32_BIT
#else
#endif /* USE_32_BIT */
#if	SMC_DEBUG > 2
#endif
#if 0
#endif /* 0 */
#if (SMC_DEBUG > 2 )
#endif
#ifndef CONFIG_SMC91111_EXT_PHY
#if (SMC_DEBUG > 2 )
#endif
#if (SMC_DEBUG > 2 )
#endif
#endif /* !CONFIG_SMC91111_EXT_PHY */
#ifndef CONFIG_SMC91111_EXT_PHY
#endif /* !CONFIG_SMC91111_EXT_PHY */
#if SMC_DEBUG > 2
#if SMC_DEBUG > 3
#endif
#endif
