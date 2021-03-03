#include <common.h>
#include <malloc.h>
#include <net.h>
#include <config.h>
#include <phy.h>
#include <miiphy.h>
#include <asm/io.h>
#include <netdev.h>
#include "bcm-sf2-eth.h"
#if defined(CONFIG_BCM_SF2_ETH_GMAC)
#include "bcm-sf2-eth-gmac.h"
#else
#error "bcm_sf2_eth: NEED to define a MAC!"
#endif
#define BCM_NET_MODULE_DESCRIPTION	"Broadcom Starfighter2 Ethernet driver"
#define BCM_NET_MODULE_VERSION		"0.1"
#define BCM_SF2_ETH_DEV_NAME		"bcm_sf2"
#ifdef CONFIG_BCM_SF2_ETH_GMAC
#else
#error "bcm_sf2_eth: NEED to register a MAC!"
#endif
#ifdef CONFIG_CMD_MII
#endif
