#define DRV_NAME "sh-pfc"
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <dm/pinctrl.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include "sh_pfc.h"
static int sh_pfc_gpio_disable_free(struct udevice *dev,
				    unsigned pin_selector)
{
	struct sh_pfc_pinctrl_priv *priv = dev_get_priv(dev);
	struct sh_pfc_pinctrl *pmx = &priv->pmx;
	struct sh_pfc *pfc = &priv->pfc;
	struct sh_pfc_pin_config *cfg;
	const struct sh_pfc_pin *pin = NULL;
	int i, idx;

	for (i = 0; i < pfc->info->nr_pins; i++) {
		if (priv->pfc.info->pins[i].pin != pin_selector)
			continue;

		pin = &priv->pfc.info->pins[i];
		break;
	}

	if (!pin)
		return -EINVAL;

	idx = sh_pfc_get_pin_index(pfc, pin->pin);
	cfg = &pmx->configs[idx];

	cfg->type = PINMUX_TYPE_NONE;

	return 0;
}
#if CONFIG_IS_ENABLED(PINCONF)
#endif
#if CONFIG_IS_ENABLED(PINCONF)
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7790
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7791
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7792
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7793
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7794
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7795
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7796
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77965
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77970
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77980
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77990
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77995
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7790
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7791
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7792
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7793
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7794
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7795
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A7796
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77965
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77970
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77980
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77990
#endif
#ifdef CONFIG_PINCTRL_PFC_R8A77995
#endif
