#define PROC_RMEM_MAX	"/proc/sys/net/core/rmem_max"
#define PROC_WMEM_MAX	"/proc/sys/net/core/wmem_max"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <net/if_arp.h>
#include "ns-mcast.h"
#define NS_COMMON 1
#include "ns-traffic.h"
