#include <common.h>
#include <mmc.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include "mmc_private.h"
#ifdef MMC_SUPPORTS_TUNING
#endif
#if CONFIG_IS_ENABLED(MMC_HS400_ES_SUPPORT)
#endif
#if CONFIG_IS_ENABLED(BLK)
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT) || \
static int mmc_blk_remove(struct udevice *dev)
{
	struct udevice *mmc_dev = dev_get_parent(dev);
	struct mmc_uclass_priv *upriv = dev_get_uclass_priv(mmc_dev);
	struct mmc *mmc = upriv->mmc;

	return mmc_deinit(mmc);
}
#endif
#if CONFIG_IS_ENABLED(MMC_WRITE)
#endif
#if CONFIG_IS_ENABLED(MMC_UHS_SUPPORT) || \
#endif
#endif /* CONFIG_BLK */
