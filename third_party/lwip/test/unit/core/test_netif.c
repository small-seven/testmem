#include "test_netif.h"
#include "lwip/netif.h"
#include "lwip/stats.h"
#include "lwip/etharp.h"
#include "netif/ethernet.h"
#if !LWIP_NETIF_EXT_STATUS_CALLBACK
#error "This tests needs LWIP_NETIF_EXT_STATUS_CALLBACK enabled"
#endif
#define MAX_NSC_REASON_IDX 10
