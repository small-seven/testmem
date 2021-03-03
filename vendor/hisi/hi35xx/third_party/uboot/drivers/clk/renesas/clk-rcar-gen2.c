#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <dt-bindings/clock/renesas-cpg-mssr.h>
#include "renesas-cpg-mssr.h"
#include "rcar-gen2-cpg.h"
#define CPG_RST_MODEMR		0x0060
#define CPG_PLL0CR		0x00d8
#define CPG_SDCKCR		0x0074
int gen2_clk_remove(struct udevice *dev)
{
	struct gen2_clk_priv *priv = dev_get_priv(dev);

	return renesas_clk_remove(priv->base, priv->info);
}
