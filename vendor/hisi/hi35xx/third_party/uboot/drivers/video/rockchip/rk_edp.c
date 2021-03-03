#include <common.h>
#include <clk.h>
#include <display.h>
#include <dm.h>
#include <edid.h>
#include <panel.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/edp_rk3288.h>
#include <asm/arch-rockchip/grf_rk3288.h>
#include <dt-bindings/clock/rk3288-cru.h>
#define MAX_CR_LOOP 5
#define MAX_EQ_LOOP 5
#define DP_LINK_STATUS_SIZE 6
#define DP_VOLTAGE_MAX         DP_TRAIN_VOLTAGE_SWING_1200
#define DP_PRE_EMPHASIS_MAX    DP_TRAIN_PRE_EMPHASIS_9_5
static int rk_edp_remove(struct udevice *dev)
{
	struct rk_edp_priv *priv = dev_get_priv(dev);
	struct rk3288_edp *regs = priv->regs;

	setbits_le32(&regs->video_ctl_1, VIDEO_MUTE);
	clrbits_le32(&regs->video_ctl_1, VIDEO_EN);
	clrbits_le32(&regs->sys_ctl_3, F_HPD | HPD_CTRL);
	setbits_le32(&regs->func_en_1, SW_FUNC_EN_N);

	return 0;
}
