#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include "mmc_private.h"
#if CONFIG_IS_ENABLED(MMC_TINY)
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#else
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#endif
#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
#endif
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
#else
#endif
#if CONFIG_IS_ENABLED(MMC_TINY)
void mmc_destroy(struct mmc *mmc)
{
}
#else
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
void mmc_destroy(struct mmc *mmc)
{
	/* only freeing memory for now */
	free(mmc);
}
#endif
