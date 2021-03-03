#include <common.h>
#include <exports.h>
#include <asm/io.h>
#include <linux/mtd/nand.h>
#include <hifmc_common.h>
#include "../../../hifmc_spi_ids.h"
#include "hinfc_common.h"
#include "hifmc100.h"
#include "hifmc100_spi_general.c"
#define SPI_NAND_ID_TAB_VER     "2.7"
#ifndef CONFIG_SYS_NAND_QUIET_TEST
#endif
