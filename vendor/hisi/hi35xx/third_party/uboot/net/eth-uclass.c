#include <common.h>
#include <dm.h>
#include <env.h>
#include <net.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <net/pcap.h>
#include "eth_internal.h"
#if defined(CONFIG_CMD_PCAP)
#endif
#if IS_ENABLED(CONFIG_OF_CONTROL)
#else
#endif
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
#ifdef CONFIG_NET_RANDOM_ETHADDR
#else
#endif
static int eth_pre_remove(struct udevice *dev)
{
	struct eth_pdata *pdata = dev->platdata;

	eth_get_ops(dev)->stop(dev);

	/* clear the MAC address */
	memset(pdata->enetaddr, 0, ARP_HLEN);

	return 0;
}
