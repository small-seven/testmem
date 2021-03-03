#include "lwip/opt.h"
#if LWIP_IPV4 && LWIP_ICMP /* don't build if not configured for use in lwipopts.h */
#include "lwip/icmp.h"
#include "lwip/inet_chksum.h"
#include "lwip/ip.h"
#include "lwip/def.h"
#include "lwip/stats.h"
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#ifndef LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN
#define LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN 1
#endif /* LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN */
#define ICMP_DEST_UNREACH_DATASIZE 8
#ifdef LWIP_DEBUG
#endif /* LWIP_DEBUG */
#ifdef LWIP_DEBUG
#endif /* LWIP_DEBUG */
#if LWIP_MULTICAST_PING
#else /* LWIP_MULTICAST_PING */
#endif /* LWIP_MULTICAST_PING */
#if LWIP_BROADCAST_PING
#else /* LWIP_BROADCAST_PING */
#endif /* LWIP_BROADCAST_PING */
#if CHECKSUM_CHECK_ICMP
#endif
#if LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN
#endif /* LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN */
#if CHECKSUM_GEN_ICMP
#if LWIP_CHECKSUM_CTRL_PER_NETIF
#endif /* LWIP_CHECKSUM_CTRL_PER_NETIF */
#else /* CHECKSUM_GEN_ICMP */
#endif /* CHECKSUM_GEN_ICMP */
#if CHECKSUM_GEN_IP
#endif /* CHECKSUM_GEN_IP */
#if LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN || !LWIP_MULTICAST_PING || !LWIP_BROADCAST_PING
#endif /* LWIP_ICMP_ECHO_CHECK_INPUT_PBUF_LEN || !LWIP_MULTICAST_PING || !LWIP_BROADCAST_PING */
#if IP_FORWARD || IP_REASSEMBLY
#endif /* IP_FORWARD || IP_REASSEMBLY */
#ifdef LWIP_HOOK_IP4_ROUTE_SRC
#else
#endif
#if CHECKSUM_GEN_ICMP
#endif
#endif /* LWIP_IPV4 && LWIP_ICMP */
