#include <common.h>
#include <display.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <video.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/grf_rk3288.h>
#include <asm/arch-rockchip/hardware.h>
#include "rk_vop.h"
static int rk_vop_remove(struct udevice *dev)
{
	struct rk_vop_priv *priv = dev_get_priv(dev);
        struct rk3288_vop *regs = priv->regs;

	setbits_le32(&regs->sys_ctrl, V_STANDBY_EN(1));

	/* wait frame complete (60Hz) to enter standby */
	mdelay(17);

	return 0;
}
