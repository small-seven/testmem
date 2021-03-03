#include <common.h>
#include <asm/io.h>
#include <memalign.h>
#include <nand.h>
#include <asm/arch/clock.h>
#include <asm/arch/funcmux.h>
#include <asm/arch-tegra/clk_rst.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <fdtdec.h>
#include <bouncebuf.h>
#include <dm.h>
#include "tegra_nand.h"
#define NAND_CMD_TIMEOUT_MS		10
#define SKIPPED_SPARE_BYTES		4
#define TAG_ECC_BYTES			4
