#include <common.h>
#include <clk.h>
#include <dm.h>
#include <ram.h>
#include <asm/io.h>
#include <power-domain.h>
#include <dm.h>
#include <asm/arch/sys_proto.h>
#include <power/regulator.h>
#include "k3-am654-ddrss.h"
#define LDELAY 10000
#define DDRSS_DDRPHY_RANKIDR_RANK0	0
#define ddrss_ctl_writel(off, val) ddrss_writel(ddrss->ddrss_ctl_cfg, off, val)
#define ddrss_ctl_readl(off) ddrss_readl(ddrss->ddrss_ctl_cfg, off)
#define ddrss_phy_writel(off, val)					\
#define ddrss_phy_readl(off)						\
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
