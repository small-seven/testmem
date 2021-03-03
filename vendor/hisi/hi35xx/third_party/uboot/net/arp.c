#include <common.h>
#include "arp.h"
#ifndef	CONFIG_ARP_TIMEOUT
# define ARP_TIMEOUT		5000UL
#else
# define ARP_TIMEOUT		CONFIG_ARP_TIMEOUT
#endif
#ifndef	CONFIG_NET_RETRY_COUNT
# define ARP_TIMEOUT_COUNT	5	/* # of timeouts before giving up  */
#else
# define ARP_TIMEOUT_COUNT	CONFIG_NET_RETRY_COUNT
#endif
#ifdef CONFIG_CMD_LINK_LOCAL
#endif
#ifdef CONFIG_KEEP_SERVERADDR
#endif
