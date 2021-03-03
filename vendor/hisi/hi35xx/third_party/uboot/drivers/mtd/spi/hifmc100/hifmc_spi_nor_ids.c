#include <common.h>
#include <asm/io.h>
#include <linux/mtd/mtd.h>
#include "hifmc100.h"
#if defined(CONFIG_TARGET_HI3562V100) || defined(CONFIG_TARGET_HI3566V100)
#define CONFIG_AUTOMOTIVE_GRADE
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#include "hifmc100_spi_general.c"
#include "hifmc100_spi_s25fl256s.c"
#include "hifmc100_spi_w25q256fv.c"
#include "hifmc100_spi_mx25l25635e.c"
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#include "hifmc100_spi_gd25qxxx.c"
#include "hifmc100_spi_micron.c"
#include "hifmc100_spi_xtx.c"
#include "hifmc100_spi_puya.c"
#include "hifmc100_spi_issi.c"
#define SPI_NOR_ID_TBL_VER     "1.0"
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_AUTOMOTIVE_GRADE
#else
#endif
#ifndef CONFIG_CLOSE_SPI_8PIN_4IO
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#else
#endif
#ifdef CONFIG_AUTOMOTIVE_GRADE
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#else
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif /* CONFIG_DTR_MODE_SUPPORT */
