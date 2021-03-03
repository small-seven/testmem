#include <common.h>
#include <dm.h>
#include <errno.h>
#include <clk-uclass.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include <k3-avs.h>
static int ti_sci_clk_free(struct clk *clk)
{
	debug("%s(clk=%p)\n", __func__, clk);
	return 0;
}
#ifdef CONFIG_K3_AVS0
#endif
