#include <common.h>
#include <clk.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dm/read.h>
#include <dt-structs.h>
#include <errno.h>
#include <linux/clk-provider.h>
#if CONFIG_IS_ENABLED(OF_CONTROL)
# if CONFIG_IS_ENABLED(OF_PLATDATA)
# else
# endif /* OF_PLATDATA */
#endif /* OF_CONTROL */
int clk_free(struct clk *clk)
{
	const struct clk_ops *ops;

	debug("%s(clk=%p)\n", __func__, clk);
	if (!clk)
		return 0;
	ops = clk_dev_ops(clk->dev);

	if (!ops->free)
		return 0;

	return ops->free(clk);
}
