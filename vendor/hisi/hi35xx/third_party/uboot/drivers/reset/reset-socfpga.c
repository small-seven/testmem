#include <common.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/of_access.h>
#include <env.h>
#include <reset-uclass.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/sizes.h>
#define BANK_INCREMENT		4
#define NR_BANKS		8
#if !defined(CONFIG_SPL_BUILD) || CONFIG_IS_ENABLED(ENV_SUPPORT)
#endif
static int socfpga_reset_free(struct reset_ctl *reset_ctl)
{
	debug("%s(reset_ctl=%p) (dev=%p, id=%lu)\n", __func__, reset_ctl,
	      reset_ctl->dev, reset_ctl->id);

	return 0;
}
static int socfpga_reset_remove(struct udevice *dev)
{
	struct socfpga_reset_data *data = dev_get_priv(dev);

	if (socfpga_reset_keep_enabled()) {
		puts("Deasserting all peripheral resets\n");
		writel(0, data->modrst_base + 4);
	}

	return 0;
}
