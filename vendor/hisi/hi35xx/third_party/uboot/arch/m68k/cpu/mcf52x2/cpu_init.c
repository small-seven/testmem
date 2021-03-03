#include <common.h>
#include <cpu_func.h>
#include <watchdog.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_CMD_NET)
#include <config.h>
#include <net.h>
#include <asm/fec.h>
#endif
#ifndef CONFIG_M5272
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) \
#else
#warning "Chip Select 0 are not initialized/used"
#endif
#if (defined(CONFIG_SYS_CS1_BASE) && defined(CONFIG_SYS_CS1_MASK) \
#endif
#if (defined(CONFIG_SYS_CS2_BASE) && defined(CONFIG_SYS_CS2_MASK) \
#endif
#if (defined(CONFIG_SYS_CS3_BASE) && defined(CONFIG_SYS_CS3_MASK) \
#endif
#if (defined(CONFIG_SYS_CS4_BASE) && defined(CONFIG_SYS_CS4_MASK) \
#endif
#if (defined(CONFIG_SYS_CS5_BASE) && defined(CONFIG_SYS_CS5_MASK) \
#endif
#if (defined(CONFIG_SYS_CS6_BASE) && defined(CONFIG_SYS_CS6_MASK) \
#endif
#if (defined(CONFIG_SYS_CS7_BASE) && defined(CONFIG_SYS_CS7_MASK) \
#endif
#endif
#if defined(CONFIG_M5208)
#ifndef CONFIG_WATCHDOG
#endif
#ifdef CONFIG_SYS_UART2_PRI_GPIO
#endif
#ifdef CONFIG_SYS_UART2_ALT1_GPIO
#endif
#ifdef CONFIG_SYS_UART2_ALT1_GPIO
#endif
#if defined(CONFIG_CMD_NET)
#endif				/* CONFIG_CMD_NET */
#endif				/* CONFIG_M5208 */
#if defined(CONFIG_M5253)
#ifdef CONFIG_SYS_I2C_FSL
#ifdef CONFIG_SYS_I2C2_OFFSET
#endif
#endif
#endif				/* #if defined(CONFIG_M5253) */
#if defined(CONFIG_M5271)
#ifndef CONFIG_WATCHDOG
#endif
#ifdef CONFIG_SYS_MCF_SYNCR
#else
#endif
#if defined(CONFIG_CMD_NET)
#endif				/* CONFIG_CMD_NET */
#endif				/* CONFIG_M5271 */
#if defined(CONFIG_M5272)
#ifndef CONFIG_MONITOR_IS_IN_RAM
#if (defined(CONFIG_SYS_OR1_PRELIM) && defined(CONFIG_SYS_BR1_PRELIM))
#endif
#if defined(CONFIG_SYS_OR2_PRELIM) && defined(CONFIG_SYS_BR2_PRELIM)
#endif
#if defined(CONFIG_SYS_OR3_PRELIM) && defined(CONFIG_SYS_BR3_PRELIM)
#endif
#if defined(CONFIG_SYS_OR4_PRELIM) && defined(CONFIG_SYS_BR4_PRELIM)
#endif
#if defined(CONFIG_SYS_OR5_PRELIM) && defined(CONFIG_SYS_BR5_PRELIM)
#endif
#if defined(CONFIG_SYS_OR6_PRELIM) && defined(CONFIG_SYS_BR6_PRELIM)
#endif
#if defined(CONFIG_SYS_OR7_PRELIM) && defined(CONFIG_SYS_BR7_PRELIM)
#endif
#endif				/* #ifndef CONFIG_MONITOR_IS_IN_RAM */
#if defined(CONFIG_CMD_NET)
#endif				/* CONFIG_CMD_NET */
#endif				/* #if defined(CONFIG_M5272) */
#if defined(CONFIG_M5275)
#ifndef CONFIG_MONITOR_IS_IN_RAM
#endif				/* #ifndef CONFIG_MONITOR_IS_IN_RAM */
#ifdef CONFIG_SYS_I2C_FSL
#endif
#if defined(CONFIG_CMD_NET)
#endif				/* CONFIG_CMD_NET */
#endif				/* #if defined(CONFIG_M5275) */
#if defined(CONFIG_M5282)
#ifndef CONFIG_WATCHDOG
#endif
#ifndef CONFIG_MONITOR_IS_IN_RAM
#ifdef CONFIG_SYS_PEPAR
#endif
#ifdef	CONFIG_SYS_PFPAR
#endif
#ifdef CONFIG_SYS_PJPAR
#endif
#ifdef CONFIG_SYS_PSDPAR
#endif
#ifdef CONFIG_SYS_PASPAR
#endif
#ifdef CONFIG_SYS_PEHLPAR
#endif
#ifdef CONFIG_SYS_PQSPAR
#endif
#ifdef CONFIG_SYS_PTCPAR
#endif
#if defined(CONFIG_SYS_PORTTC)
#endif
#if defined(CONFIG_SYS_DDRTC)
#endif
#ifdef CONFIG_SYS_PTDPAR
#endif
#ifdef CONFIG_SYS_PUAPAR
#endif
#if defined(CONFIG_SYS_DDRD)
#endif
#ifdef CONFIG_SYS_DDRUA
#endif
#endif				/* CONFIG_MONITOR_IS_IN_RAM */
#if defined(CONFIG_CMD_NET)
#endif			/* CONFIG_CMD_NET */
#endif
#if defined(CONFIG_M5249)
#endif				/* #if defined(CONFIG_M5249) */
