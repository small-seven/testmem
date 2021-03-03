#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <dt-bindings/clock/renesas-cpg-mssr.h>
#include "renesas-cpg-mssr.h"
#include "rcar-gen3-cpg.h"
#define CPG_RST_MODEMR		0x0060
#define CPG_PLL0CR		0x00d8
#define CPG_PLL2CR		0x002c
#define CPG_PLL4CR		0x01f4
#define CPG_RPC_PREDIV_MASK	0x3
#define CPG_RPC_PREDIV_OFFSET	3
#define CPG_RPC_POSTDIV_MASK	0x7
#define CPG_RPC_POSTDIV_OFFSET	0
#define CPG_SD_STP_HCK		BIT(9)
#define CPG_SD_STP_CK		BIT(8)
#define CPG_SD_STP_MASK		(CPG_SD_STP_HCK | CPG_SD_STP_CK)
#define CPG_SD_FC_MASK		(0x7 << 2 | 0x3 << 0)
#define CPG_SD_DIV_TABLE_DATA(stp_hck, stp_ck, sd_srcfc, sd_fc, sd_div) \
int gen3_clk_remove(struct udevice *dev)
{
	struct gen3_clk_priv *priv = dev_get_priv(dev);

	return renesas_clk_remove(priv->base, priv->info);
}
