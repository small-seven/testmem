#include <common.h>
#include <spi.h>
#include <malloc.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <dm.h>
#include <dm/platform_data/spi_davinci.h>
#define SPIGCR0_SPIENA_MASK	0x1
#define SPIGCR0_SPIRST_MASK	0x0
#define SPIGCR1_CLKMOD_MASK	BIT(1)
#define SPIGCR1_MASTER_MASK	BIT(0)
#define SPIGCR1_SPIENA_MASK	BIT(24)
#define SPIPC0_DIFUN_MASK	BIT(11)		/* SIMO */
#define SPIPC0_DOFUN_MASK	BIT(10)		/* SOMI */
#define SPIPC0_CLKFUN_MASK	BIT(9)		/* CLK */
#define SPIPC0_EN0FUN_MASK	BIT(0)
#define SPIFMT_SHIFTDIR_SHIFT	20
#define SPIFMT_POLARITY_SHIFT	17
#define SPIFMT_PHASE_SHIFT	16
#define SPIFMT_PRESCALE_SHIFT	8
#define SPIDAT1_CSHOLD_SHIFT	28
#define SPIDAT1_CSNR_SHIFT	16
#define SPI_C2TDELAY_SHIFT	24
#define SPI_T2CDELAY_SHIFT	16
#define SPIBUF_RXEMPTY_MASK	BIT(31)
#define SPIBUF_TXFULL_MASK	BIT(29)
#define SPIDEF_CSDEF0_MASK	BIT(0)
#ifndef CONFIG_DM_SPI
#define SPI0_BUS		0
#define SPI0_BASE		CONFIG_SYS_SPI_BASE
#ifndef CONFIG_SYS_SPI0
#define SPI0_NUM_CS		1
#else
#define SPI0_NUM_CS		CONFIG_SYS_SPI0_NUM_CS
#endif
#ifdef CONFIG_SYS_SPI1
#define SPI1_BUS		1
#define SPI1_NUM_CS		CONFIG_SYS_SPI1_NUM_CS
#define SPI1_BASE		CONFIG_SYS_SPI1_BASE
#endif
#ifdef CONFIG_SYS_SPI2
#define SPI2_BUS		2
#define SPI2_NUM_CS		CONFIG_SYS_SPI2_NUM_CS
#define SPI2_BASE		CONFIG_SYS_SPI2_BASE
#endif
#endif
#ifndef CONFIG_DM_SPI
#endif
#ifndef CONFIG_DM_SPI
#ifdef CONFIG_SYS_SPI1
#endif
#ifdef CONFIG_SYS_SPI2
#endif
#ifdef CONFIG_SYS_SPI1
#endif
#ifdef CONFIG_SYS_SPI2
#endif
#ifdef CONFIG_SPI_HALF_DUPLEX
#else
#endif
#else
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
