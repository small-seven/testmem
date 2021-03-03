#include <common.h>
#include <config.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <dm/root.h>
#include <asm/system.h>
#include <asm/io.h>
#include <asm/arch-armada8k/soc-info.h>
#include "pinctrl-mvebu.h"
#define AP_EMMC_PHY_CTRL_REG		0x100
#define CP_EMMC_PHY_CTRL_REG		0x424
#define EMMC_PHY_CTRL_SDPHY_EN		BIT(0)
#define AP806_EMMC_CLK_PIN_ID		0
#define AP806_EMMC_CLK_FUNC		0x1
#define CP110_EMMC_CLK_PIN_ID		56
#define CP110_EMMC_CLK_FUNC		0xe
