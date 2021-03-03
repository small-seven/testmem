#include <common.h>
#include <dm.h>
#include <clk.h>
#include <asm/clk.h>
int sandbox_clk_test_free(struct udevice *dev)
{
	struct sandbox_clk_test *sbct = dev_get_priv(dev);
	int i, ret;

	devm_clk_put(dev, sbct->clkps[SANDBOX_CLK_TEST_ID_DEVM1]);
	for (i = 0; i < SANDBOX_CLK_TEST_NON_DEVM_COUNT; i++) {
		ret = clk_free(&sbct->clks[i]);
		if (ret)
			return ret;
	}

	return 0;
}
