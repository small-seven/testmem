#include <common.h>
#include <dm.h>
#include <reset-uclass.h>
#include <asm/arch/clock.h>
#include <asm/arch-tegra/clk_rst.h>
static int tegra_car_reset_free(struct reset_ctl *reset_ctl)
{
	debug("%s(reset_ctl=%p) (dev=%p, id=%lu)\n", __func__, reset_ctl,
	      reset_ctl->dev, reset_ctl->id);

	return 0;
}
