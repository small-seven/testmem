#include <common.h>
#include <dm.h>
#include <clk.h>
#include <reset.h>
#include <timer.h>
#include <asm/io.h>
#include <asm/arch/timer.h>
#define DW_APB_LOAD_VAL		0x0
#define DW_APB_CURR_VAL		0x4
#define DW_APB_CTRL		0x8
static int dw_apb_timer_remove(struct udevice *dev)
{
	struct dw_apb_timer_priv *priv = dev_get_priv(dev);

	return reset_release_bulk(&priv->resets);
}
