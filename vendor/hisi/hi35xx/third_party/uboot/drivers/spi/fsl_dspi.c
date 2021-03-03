#include <common.h>
#include <dm.h>
#include <errno.h>
#include <common.h>
#include <spi.h>
#include <malloc.h>
#include <asm/io.h>
#include <fdtdec.h>
#ifndef CONFIG_M68K
#include <asm/arch/clock.h>
#endif
#include <fsl_dspi.h>
#define DSPI_FLAG_REGMAP_ENDIAN_BIG	BIT(0)
#define DSPI_IDLE_VAL			0x0
#define FSL_DSPI_MAX_CHIPSELECT		6
#define FSL_DSPI_DEFAULT_SCK_FREQ	10000000
#define DSPI_TXRX_WAIT_TIMEOUT		1000000
#define DSPI_CTAR_DEFAULT_VALUE		(DSPI_CTAR_TRSZ(7) | \
#define DSPI_CTAR_SET_MODE_MASK		(DSPI_CTAR_TRSZ(15) | \
#ifndef CONFIG_DM_SPI
#endif
#ifndef CONFIG_DM_SPI
#ifdef CONFIG_SYS_FSL_DSPI_BE
#endif
#ifdef CONFIG_M68K
#else
#endif
#ifdef CONFIG_SYS_DSPI_CTAR0
#endif
#ifdef CONFIG_SYS_DSPI_CTAR1
#endif
#ifdef CONFIG_SYS_DSPI_CTAR2
#endif
#ifdef CONFIG_SYS_DSPI_CTAR3
#endif
#ifdef CONFIG_SYS_DSPI_CTAR4
#endif
#ifdef CONFIG_SYS_DSPI_CTAR5
#endif
#ifdef CONFIG_SYS_DSPI_CTAR6
#endif
#ifdef CONFIG_SYS_DSPI_CTAR7
#endif
#else
#ifdef CONFIG_M68K
#else
#endif
#endif
