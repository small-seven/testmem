#include <common.h>
#include <command.h>
#include <env.h>
#include <malloc.h>
#include "lan91c96.h"
#include <net.h>
#include <linux/compiler.h>
#define POWER_DOWN	0
#define MEMORY_WAIT_TIME 16
#define SMC_DEBUG 0
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
#define DRIVER_NAME "LAN91C96"
#define SMC_ALLOC_MAX_TRY 5
#define SMC_TX_TIMEOUT 30
#define ETH_ZLEN 60
#ifdef  CONFIG_LAN91C96_USE_32_BIT
#define USE_32_BIT  1
#else
#undef USE_32_BIT
#endif
#if SMC_DEBUG > 2
#endif
#if SMC_DEBUG > 2
#endif
#ifdef USE_32_BIT
#else
#endif /* USE_32_BIT */
#ifdef USE_32_BIT
#else
#endif /* USE_32_BIT */
#ifdef USE_32_BIT
#else
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
#if SMC_DEBUG > 2
#if 0
#endif /* 0 */
#endif /* SMC_DEBUG > 2 */
