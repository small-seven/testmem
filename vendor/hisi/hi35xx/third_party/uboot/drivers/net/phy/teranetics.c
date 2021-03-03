#include <common.h>
#include <phy.h>
#ifndef CONFIG_PHYLIB_10G
#error The Teranetics PHY needs 10G support
#endif
#define MDIO_PHYXS_LANE_READY (MDIO_PHYXS_LNSTAT_SYNC0 | \
