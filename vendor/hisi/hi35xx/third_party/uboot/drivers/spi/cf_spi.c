#include <common.h>
#include <dm.h>
#include <dm/platform_data/spi_coldfire.h>
#include <spi.h>
#include <malloc.h>
#include <asm/coldfire/dspi.h>
#include <asm/io.h>
#ifndef CONFIG_SPI_IDLE_VAL
#if defined(CONFIG_SPI_MMC)
#define CONFIG_SPI_IDLE_VAL	0xFFFF
#else
#define CONFIG_SPI_IDLE_VAL	0x0
#endif
#endif
#define SPI_MODE_MOD			0x00200000
#define SPI_MODE_DBLRATE		0x00100000
#define SPI_MODE_XFER_SZ_MASK		0xf0000000
#define SPI_MODE_DLY_PRE_MASK		0x0fc00000
#define SPI_MODE_DLY_SCA_MASK		0x000fff00
#define MCF_FRM_SZ_16BIT		DSPI_CTAR_TRSZ(0xf)
#define MCF_DSPI_SPEED_BESTMATCH	0x7FFFFFFF
#define MCF_DSPI_MAX_CTAR_REGS		8
#define MCF_DSPI_DEFAULT_SCK_FREQ	10000000
#define MCF_DSPI_DEFAULT_MAX_CS		4
#define MCF_DSPI_DEFAULT_MODE		0
#define MCF_DSPI_DEFAULT_CTAR		(DSPI_CTAR_TRSZ(7) | \
#define MCF_CTAR_MODE_MASK		(MCF_FRM_SZ_16BIT | \
#define setup_ctrl(ctrl, cs)	((ctrl & 0xFF000000) | ((1 << cs) << 16))
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
