#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <asm/clk.h>
static int sandbox_clk_free(struct clk *clk)
{
	struct sandbox_clk_priv *priv = dev_get_priv(clk->dev);

	if (clk->id >= SANDBOX_CLK_ID_COUNT)
		return -EINVAL;

	priv->requested[clk->id] = false;
	return 0;
}
