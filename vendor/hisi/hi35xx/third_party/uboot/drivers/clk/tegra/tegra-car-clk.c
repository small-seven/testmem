#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <asm/arch/clock.h>
#include <asm/arch-tegra/clk_rst.h>
static int tegra_car_clk_free(struct clk *clk)
{
	debug("%s(clk=%p) (dev=%p, id=%lu)\n", __func__, clk, clk->dev,
	      clk->id);

	return 0;
}
