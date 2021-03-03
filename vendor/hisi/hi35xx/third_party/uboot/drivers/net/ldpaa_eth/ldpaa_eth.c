#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/types.h>
#include <malloc.h>
#include <net.h>
#include <hwconfig.h>
#include <phy.h>
#include <linux/compat.h>
#include <fsl-mc/fsl_dpmac.h>
#include <fsl-mc/ldpaa_wriop.h>
#include "ldpaa_eth.h"
#ifdef CONFIG_PHYLIB
#endif
#ifdef DEBUG
#define DPNI_STATS_PER_PAGE 6
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_PHYLIB
#endif
static void ldpaa_dpbp_free(void)
{
	ldpaa_dpbp_drain();
	dpbp_disable(dflt_mc_io, MC_CMD_NO_FLAGS, dflt_dpbp->dpbp_handle);
	dpbp_reset(dflt_mc_io, MC_CMD_NO_FLAGS, dflt_dpbp->dpbp_handle);
	dpbp_close(dflt_mc_io, MC_CMD_NO_FLAGS, dflt_dpbp->dpbp_handle);
}
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_PHYLIB
#endif
