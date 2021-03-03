#include "../core/ipv4/etharp.c"  /* for arp_table */
#define icmp6_hdr netinet_icmp6_hdr
#include <netinet/icmp6.h>
#undef icmp6_hdr
#include "api_shell_fix.h"
#include "lwip/opt.h"
#if LWIP_ENABLE_LOS_SHELL_CMD
#include "lwip/api.h"
#include "lwip/tcpip.h"
#include "lwip/netif.h"
#include "lwip/netdb.h"
#include "lwip/stats.h"
#include "lwip/err.h"
#include "lwip/inet.h"
#include "netif/etharp.h"
#include "lwip/ip_addr.h"
#include "lwip/ip6_addr.h"
#include "lwip/icmp.h"
#include "lwip/priv/nd6_priv.h"
#include "lwip/sockets.h"
#include "lwip/inet_chksum.h"
#include "lwip/raw.h"
#include "los_config.h"
#include <string.h>
#include "limits.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <poll.h>
#include "api_shell.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "lwip/udp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/dhcp.h"
#include "lwip/netifapi.h"
#include "los_strnlen_user.h"
#include "linux/kernel.h"
#ifdef LOSCFG_SHELL
#include "shcmd.h"
#include "shell.h"
#endif
#define netif_find netifapi_netif_find_by_name
#if LWIP_ARP
#endif
#if LWIP_IPV6
#define LWIP_MAX_PING6_ARG_COUNT              64
#define LWIP_PING6_STANDARD_PKT_SIZE          56
#define LWIP_PING6_STARTING_SEQ_NUM           0x2255
#define LWIP_PING6_OUT_OF_ORDER_MAGNITUDE     1
#define LWIP_PING6_COUNT_ARG           1
#define LWIP_PING6_SOURCE_ADDRESS_ARG  2
#define LWIP_PING6_INTERFACE_ARG       4
#define LWIP_PING6_HOSTNAME_ARG        8
#define LWIP_PING6_DEFAULT_SOCKET      16
#endif
#ifndef LWIP_TESTBED
#endif
#ifndef LWIP_TESTBED
#endif
#ifndef LWIP_TESTBED
#endif
#ifndef LWIP_TESTBED
#endif
#ifndef LWIP_TESTBED
#endif
#if LWIP_DNS
#ifndef LWIP_TESTBED
#endif
#endif /* LWIP_DNS */
#ifdef LWIP_DEBUG_INFO
#endif /* LWIP_DEBUG_INFO */
#if LWIP_IPV6
typedef struct ping6_args {
    u8_t args_found;
    u8_t interface_index;
    u8_t host_index;
    u8_t pad;
    u32_t pingcount;
    ip6_addr_t src_addr;
    ip6_addr_t dst_addr;
} ping6_args_t;
typedef struct ping6_stats {
    u32_t flag;
    u32_t min_rtt;
    u32_t max_rtt;
    float avg_rtt;
} ping6_stats_t;
#endif /* LWIP_IPV6 */
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#define IFCONFIG_OPTION_SET_IP          (1)
#define IFCONFIG_OPTION_SET_NETMASK     (1 << 1)
#define IFCONFIG_OPTION_SET_GW          (1 << 2)
#define IFCONFIG_OPTION_SET_HW          (1 << 3)
#define IFCONFIG_OPTION_SET_UP          (1 << 4)
#define IFCONFIG_OPTION_SET_DOWN        (1 << 5)
#define IFCONFIG_OPTION_SET_MTU         (1 << 6)
#define IFCONFIG_OPTION_DEL_IP          (1 << 7)
#define NETSTAT_ENTRY_SIZE 120
#define MAX_NETSTAT_ENTRY (NETSTAT_ENTRY_SIZE * (MEMP_NUM_TCP_PCB + MEMP_NUM_UDP_PCB + MEMP_NUM_TCP_PCB_LISTEN + 1))
#define PRINT_BUF_LEN   1024
#define MAX_MACADDR_STRING_LENGTH    18 /* including NULL */
#define CONVERT_STRING_TO_HEX(_src, _dest)    \
#define ERR_IFCONFIG_STRING_PUT(ret, str)     do                                             \
#define LWIP_MSECS_TO_SECS(time_in_msecs) (time_in_msecs / 1000)
#ifndef LWIP_TESTBED
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if MIB2_STATS
#endif
#ifndef LWIP_TESTBED
#endif
#ifndef LWIP_TESTBED
#endif
#if LWIP_DHCP
#endif
#if LWIP_DHCP
#endif
#if LWIP_DHCP
#endif
#if LWIP_STATS
#endif
#if LWIP_ARP
#if LWIP_ENABLE_IP_CONFLICT_SIGNAL
#endif /* LWIP_ENABLE_IP_CONFLICT_SIGNAL */
#endif /* LWIP_ARP */
#if LWIP_IPV6
#endif
#if LWIP_STATS
#if IP6_STATS
#endif
#endif /* LWIP_STATS */
#if LWIP_ARP
#if LWIP_ENABLE_IP_CONFLICT_SIGNAL
#endif /* LWIP_ENABLE_IP_CONFLICT_SIGNAL */
#endif /* LWIP_ARP */
#if LWIP_ARP
#else
#endif /* LWIP_ARP */
#if LWIP_ARP && LWIP_ENABLE_IP_CONFLICT_SIGNAL
#endif /* LWIP_ARP && LWIP_ENABLE_IP_CONFLICT_SIGNAL */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_ARP && LWIP_ENABLE_IP_CONFLICT_SIGNAL
#endif /* LWIP_ARP && LWIP_ENABLE_IP_CONFLICT_SIGNAL */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_ARP && LWIP_ENABLE_IP_CONFLICT_SIGNAL
#endif /* LWIP_ARP && LWIP_ENABLE_IP_CONFLICT_SIGNAL */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#ifdef LOSCFG_SHELL
#endif /* LOSCFG_SHELL */
#define ARP_OPTION_ADD      1
#define ARP_OPTION_DEL      2
#define ARP_OPTION_SHOW     3
#ifndef LWIP_TESTBED
#endif
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#else
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#if ETHARP_SUPPORT_STATIC_ENTRIES
#else
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#ifndef LWIP_TESTBED
#endif
#if LWIP_IPV4
#if ETHARP_SUPPORT_STATIC_ENTRIES
#else
#endif /* ETHARP_SUPPORT_STATIC_ENTRIES */
#endif
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#if LWIP_DNS
#ifndef LWIP_TESTBED
#endif
#endif
#if LWIP_EXT_POLL_SUPPORT
#define PING_ZERO_DATA_LEN 8
#if LWIP_DNS
#else /* LWIP_DNS */
#endif /* LWIP_DNS */
#ifdef LOSCFG_SHELL
#endif /* LOSCFG_SHELL */
#else /* LWIP_EXT_POLL_SUPPORT*/
#if LWIP_DNS
#else /* LWIP_DNS */
#endif /* LWIP_DNS */
#ifdef LOSCFG_SHELL
#endif /* LOSCFG_SHELL */
#endif /* LWIP_EXT_POLL_SUPPORT*/
#if LWIP_IPV6
#if LWIP_DNS
#else
#endif /* LWIP_DNS */
LWIP_STATIC int create_ping6_socket(u8_t type, const void *param)
{
    int sfd;
    int ret;
    struct sockaddr_in6 stHostAddr6;
    struct icmp6_filter icmp6_sock_filter;

    sfd = lwip_socket(PF_INET6, SOCK_RAW, IPPROTO_ICMPV6);
    if (sfd == -1) {
        PRINTK("ping6 : Failed, socket creation failed\n");
        return -1;
    }

    if (param != NULL) {
        if (type == LWIP_PING6_SOURCE_ADDRESS_ARG) {
            /* Binding socket to the provided source address */
            (void)memset_s(&stHostAddr6, sizeof(stHostAddr6), 0, sizeof(stHostAddr6));
            stHostAddr6.sin6_family = AF_INET6;
            inet6_addr_from_ip6addr(&stHostAddr6.sin6_addr, (ip6_addr_t *)param);
            stHostAddr6.sin6_port = htons(IPPROTO_ICMPV6);
            stHostAddr6.sin6_scope_id = 0;

            ret = lwip_bind(sfd, (struct sockaddr *)&stHostAddr6, sizeof(stHostAddr6));
            if (ret == -1) {
                (void)lwip_close(sfd);
                PRINTK("ping6 : bind icmp socket: cannot assign requested address\n");
                return ret;
            }
        } else if (type == LWIP_PING6_INTERFACE_ARG) {
            /* Binding socket to the provided netif */
            ret = lwip_setsockopt(sfd, SOL_SOCKET, SO_BINDTODEVICE, (char *)(param), strlen((char *)(param)));
            if (ret == -1) {
                (void)lwip_close(sfd);
                PRINTK("ping6: unknown iface %s\n", (char *)(param));
                return ret;
            }
        }
    }

    /* Setting socket filter since we are interested only in ECHO REPLY and ERROR messages */
    ICMP6_FILTER_SETBLOCKALL (&icmp6_sock_filter);
    ICMP6_FILTER_SETPASS (ICMP6_TYPE_EREP, &icmp6_sock_filter);
    ICMP6_FILTER_SETPASS (ICMP6_TYPE_DUR, &icmp6_sock_filter);
    ICMP6_FILTER_SETPASS (ICMP6_TYPE_PTB, &icmp6_sock_filter);
    ICMP6_FILTER_SETPASS (ICMP6_TYPE_TE, &icmp6_sock_filter);

    ret = lwip_setsockopt(sfd, IPPROTO_ICMPV6, ICMP6_FILTER, &icmp6_sock_filter, sizeof(struct icmp6_filter));
    if (ret == -1) {
        (void)lwip_close(sfd);
        PRINTK("ping6 : setsockopt: Invalid Argument\n");
        return -1;
    }

    return sfd;
}
#if LWIP_DNS
#endif
#if LWIP_DNS
#else
#endif /* LWIP_DNS */
#if LWIP_DNS
#else
#endif /* LWIP_DNS */
#if LWIP_DNS
#endif /* LWIP_DNS */
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif /* LWIP_IPV6 */
#if  LWIP_SNTP
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif /* LWIP_SNTP*/
#ifdef LOSCFG_NET_LWIP_SACK_TFTP
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
#endif
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif /* LOSCFG_NET_LWIP_SACK_TFTP */
#if LWIP_DNS
#if LWIP_IPV6
#if LWIP_IPV4 && LWIP_IPV6
#endif
#endif
#if LWIP_IPV4
#if LWIP_IPV4 && LWIP_IPV6
#endif
#endif
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif /* LWIP_DNS */
#if LWIP_IPV6
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#if LWIP_UDPLITE
#else
#endif
#endif
#if LWIP_SO_RCVBUF
#endif
#if LWIP_SO_RCVBUF
#if LWIP_IPV6
#endif
#endif
#if LWIP_IPV6
#if LWIP_ND6_QUEUEING
#endif
#if LWIP_ND6_QUEUEING
#else
#endif
#endif
#if LWIP_IPV4
#if ARP_QUEUEING
#endif
#if ARP_QUEUEING
#else
#endif
#endif
#if LWIP_SO_RCVBUF
#if PF_PKT_SUPPORT
#endif
#endif
#if PF_PKT_SUPPORT
#endif
#if LWIP_TCP
#endif
#if LWIP_UDP
#if LWIP_IPV6
#else
#endif
#endif
#if LWIP_RAW
#if PF_PKT_SUPPORT
#endif
#endif
#ifdef LOSCFG_SHELL
#endif /* LOSCFG_SHELL */
#define NETIF_NAME_LEN 10
#ifdef LOSCFG_SHELL
#endif /* LOSCFG_SHELL */
#ifdef LWIP_DEBUG_TCPSERVER
#define MAX_SIZE 1024
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif /* LWIP_DEBUG_TCPSERVER */
#ifdef LWIP_DEBUG_UDPSERVER
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif /* LWIP_DEBUG_UDPSERVER */
#ifdef LWIP_DEBUG_INFO
#endif /* LWIP_DEBUG_INFO */
#if defined(LOSCFG_SHELL_CMD_DEBUG) && defined(LWIP_DEBUG_INFO)
#endif /* LOSCFG_SHELL_CMD_DEBUG && LWIP_DEBUG_INFO */
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif
#ifdef LWIP_TESTBED
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif
#endif //LWIP_ENABLE_LOS_SHELL_CMD
