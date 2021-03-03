#include <lwip/netif.h>
#include <lwip/dhcp.h>
#if (LWIP_CHKSUM_ALGORITHM == 4) /* version #4, asm based */
#include "in_cksum.h"
#endif
