#include <common.h>
#include <dm.h>
#include <reset-uclass.h>
#include <linux/io.h>
#include <asm/arch-rockchip/hardware.h>
#include <dm/lists.h>
#define ROCKCHIP_RESET_NUM_IN_REG	16
static int rockchip_reset_free(struct reset_ctl *reset_ctl)
{
	debug("%s(reset_ctl=%p) (dev=%p, id=%lu)\n", __func__, reset_ctl,
	      reset_ctl->dev, reset_ctl->id);

	return 0;
}
