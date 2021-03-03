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
#ifdef CONFIG_M5235
#define out_be_fbcs_reg		out_be16
#else
#define out_be_fbcs_reg		out_be32
#endif
#ifndef CONFIG_WATCHDOG
#endif
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) && defined(CONFIG_SYS_CS0_CTRL))
#endif
#if (defined(CONFIG_SYS_CS1_BASE) && defined(CONFIG_SYS_CS1_MASK) && defined(CONFIG_SYS_CS1_CTRL))
#endif
#if (defined(CONFIG_SYS_CS2_BASE) && defined(CONFIG_SYS_CS2_MASK) && defined(CONFIG_SYS_CS2_CTRL))
#endif
#if (defined(CONFIG_SYS_CS3_BASE) && defined(CONFIG_SYS_CS3_MASK) && defined(CONFIG_SYS_CS3_CTRL))
#endif
#if (defined(CONFIG_SYS_CS4_BASE) && defined(CONFIG_SYS_CS4_MASK) && defined(CONFIG_SYS_CS4_CTRL))
#endif
#if (defined(CONFIG_SYS_CS5_BASE) && defined(CONFIG_SYS_CS5_MASK) && defined(CONFIG_SYS_CS5_CTRL))
#endif
#if (defined(CONFIG_SYS_CS6_BASE) && defined(CONFIG_SYS_CS6_MASK) && defined(CONFIG_SYS_CS6_CTRL))
#endif
#if (defined(CONFIG_SYS_CS7_BASE) && defined(CONFIG_SYS_CS7_MASK) && defined(CONFIG_SYS_CS7_CTRL))
#endif
#ifdef CONFIG_SYS_I2C_FSL
#endif
#ifdef CONFIG_SYS_UART2_PRI_GPIO
#elif defined(CONFIG_SYS_UART2_ALT1_GPIO)
#endif
#if defined(CONFIG_CMD_NET)
#endif
