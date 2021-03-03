#include "test_ip4.h"
#include "lwip/ip4.h"
#include "lwip/inet_chksum.h"
#include "lwip/stats.h"
#include "lwip/prot/ip.h"
#include "lwip/prot/ip4.h"
#include "lwip/tcpip.h"
#if !LWIP_IPV4 || !IP_REASSEMBLY || !MIB2_STATS || !IPFRAG_STATS
#error "This tests needs LWIP_IPV4, IP_REASSEMBLY; MIB2- and IPFRAG-statistics enabled"
#endif
