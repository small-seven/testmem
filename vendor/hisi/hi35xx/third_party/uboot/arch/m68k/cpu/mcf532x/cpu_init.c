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
#ifdef CONFIG_MCF5301x
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) \
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
#ifdef CONFIG_SYS_I2C_FSL
#endif
#ifdef CONFIG_MCFFEC
#endif
#ifdef CONFIG_MCFRTC
#endif
#ifdef CONFIG_MCFFEC
#endif
#ifdef CONFIG_SYS_UART1_ALT1_GPIO
#elif defined(CONFIG_SYS_UART1_ALT2_GPIO)
#endif
#ifdef CONFIG_SYS_UART2_PRI_GPIO
#elif defined(CONFIG_SYS_UART2_ALT1_GPIO)
#elif defined(CONFIG_SYS_UART2_ALT2_GPIO)
#endif
#if defined(CONFIG_CMD_NET)
#endif				/* CONFIG_CMD_NET */
#endif				/* CONFIG_MCF5301x */
#ifdef CONFIG_MCF532x
#ifndef CONFIG_WATCHDOG
#endif
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) \
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
#ifdef CONFIG_SYS_I2C_FSL
#endif
#ifdef CONFIG_SYS_UART2_ALT1_GPIO
#elif defined(CONFIG_SYS_UART2_ALT2_GPIO)
#elif defined(CONFIG_SYS_UART2_ALT3_GPIO)
#endif
#if defined(CONFIG_CMD_NET)
#endif
#endif				/* CONFIG_MCF532x */
