#include <common.h>
#include <command.h>
#include <env.h>
#include <net.h>
#include <phy.h>
#include <linux/errno.h>
#include <net/pcap.h>
#include "eth_internal.h"
#ifdef CONFIG_API
#endif
#ifdef CONFIG_NET_RANDOM_ETHADDR
#else
#endif
#if defined(CONFIG_CMD_PCAP)
#endif
#ifdef CONFIG_API
#endif /* CONFIG_API */
