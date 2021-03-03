#include <common.h>
#include <div64.h>
#include <env.h>
#include <spi.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <asm/io.h>
#include "../drivers/ddr/marvell/axp/ddr3_init.h"
#define ETHADDR_MAX		4
#define SYNO_SN_TAG		"SN="
#define SYNO_CHKSUM_TAG		"CHK="
