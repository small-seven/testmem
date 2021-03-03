#include <common.h>
#include <command.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <version.h>
#include <asm/io.h>
#if defined(CONFIG_HIFMC_SPI_NAND) \
#include <hinfc_common.h>
#endif
#if defined(CONFIG_HIFMC_SPI_NAND) || defined(CONFIG_HIFMC_NAND) || defined(CONFIG_HIFMC_SPI_NOR)
#if defined(CONFIG_HIFMC_SPI_NAND) || defined(CONFIG_HIFMC_NAND)
#ifdef CONFIG_CMD_NAND
#endif
#else
#endif
#endif
#if defined(CONFIG_HIFMC_SPI_NAND) || defined(CONFIG_HIFMC_NAND)
#endif
#ifdef CONFIG_HIFMC_SPI_NOR
#endif
