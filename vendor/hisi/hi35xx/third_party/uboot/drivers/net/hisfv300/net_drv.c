#define HIETH_SFV300
#include "hieth.h"
#include "mac.h"
#include "ctrl.h"
#include "glb.h"
#include "sys.h"
#include "mii_drv.h"
#include <config.h>
#include <miiphy.h>
#include <net.h>
#include <cpu_func.h>
#define MAC_LEN 6
#ifdef HIETH_RX_QUEUE_MULTI_DESC
#endif
#ifdef HIETH_RX_QUEUE_MULTI_DESC
#endif
#ifdef CONFIG_NET_RANDOM_ETHADDR
#endif
#ifdef HIETH_RX_QUEUE_MULTI_DESC
#endif
static int hieth_dev_remove(struct hieth_netdev_local *ld)
{
#ifdef HIETH_RX_QUEUE_MULTI_DESC
	hieth_destroy_hw_desc_queue(ld);
#endif

	return 0;
}
#if defined(INNER_PHY)
#if defined(INNER_PHY_ADDR_U)
#endif
#if defined(INNER_PHY_ADDR_D)
#endif
#endif
#if defined(CONFIG_HI3536DV100)
#endif
#ifdef INNER_PHY
#endif
#ifdef HIETH_RX_QUEUE_MULTI_DESC
#else
#endif
#define ETH_FCS_LEN 4 /* Octets in the FCS */
