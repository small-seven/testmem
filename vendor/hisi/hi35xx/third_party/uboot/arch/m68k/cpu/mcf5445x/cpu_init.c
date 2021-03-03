#include <common.h>
#include <cpu_func.h>
#include <watchdog.h>
#include <asm/immap.h>
#include <asm/processor.h>
#include <asm/rtc.h>
#include <asm/io.h>
#include <linux/compiler.h>
#if defined(CONFIG_CMD_NET)
#include <config.h>
#include <net.h>
#include <asm/fec.h>
#endif
#if !defined(CONFIG_SERIAL_BOOT)
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) && defined(CONFIG_SYS_CS0_CTRL))
#endif
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
#ifdef CONFIG_CF_DSPI
#ifdef CONFIG_MCF5445x
#endif
#ifdef CONFIG_MCF5441x
#endif
#endif
#ifdef CONFIG_MCF5441x
#ifdef CONFIG_SYS_I2C_0
#endif
#ifdef CONFIG_SYS_I2C_2
#endif
#ifdef CONFIG_SYS_I2C_5
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#endif		/* CONFIG_MCF5441x */
#ifdef CONFIG_MCF5445x
#ifdef CONFIG_CF_SPI
#endif
#ifdef CONFIG_SYS_FSL_I2C
#endif
#endif		/* CONFIG_MCF5445x */
#ifdef CONFIG_SYS_CS0_BASE
#endif
#ifdef CONFIG_MCFRTC
#endif
#ifdef CONFIG_MCF5441x
#endif
#ifdef CONFIG_MCF5441x
#endif
#ifdef CONFIG_MCF5445x
#ifdef CONFIG_SYS_UART1_PRI_GPIO
#elif defined(CONFIG_SYS_UART1_ALT1_GPIO)
#endif
#if defined(CONFIG_SYS_UART2_ALT1_GPIO)
#elif defined(CONFIG_SYS_UART2_ALT2_GPIO)
#endif
#endif	/* CONFIG_MCF5445x */
#if defined(CONFIG_CMD_NET)
#ifdef CONFIG_MCF5445x
#ifdef CONFIG_SYS_FEC_NO_SHARED_PHY
#else
#endif
#ifdef CONFIG_SYS_FEC_FULL_MII
#else
#endif
#ifdef CONFIG_SYS_FEC_FULL_MII
#else
#endif
#endif	/* CONFIG_MCF5445x */
#ifdef CONFIG_MCF5441x
#endif
#endif
