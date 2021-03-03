#include <common.h>
#include <dm.h>
#include <dm/platform_data/pfe_dm_eth.h>
#include <net.h>
#include <net/pfe_eth/pfe_eth.h>
#if defined(CONFIG_PHYLIB)
#define MDIO_TIMEOUT    5000
#endif
