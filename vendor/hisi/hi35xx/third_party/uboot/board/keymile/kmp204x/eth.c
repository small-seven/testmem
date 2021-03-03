#include <common.h>
#include <netdev.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <phy.h>
#ifdef CONFIG_FMAN_ENET
#endif
#if defined(CONFIG_PHYLIB) && defined(CONFIG_PHY_MARVELL)
#define mv88E1118_PAGE_REG	22
#endif
