#include "lwip/apps/sntp.h"
#include "lwip/opt.h"
#include "lwip/timeouts.h"
#include "lwip/udp.h"
#include "lwip/dns.h"
#include "lwip/ip_addr.h"
#include "lwip/pbuf.h"
#include "lwip/dhcp.h"
#include <string.h>
#include <time.h>
#if LWIP_UDP
#if SNTP_MAX_SERVERS > 1
#define SNTP_SUPPORT_MULTIPLE_SERVERS 1
#else /* NTP_MAX_SERVERS > 1 */
#define SNTP_SUPPORT_MULTIPLE_SERVERS 0
#endif /* NTP_MAX_SERVERS > 1 */
#ifndef SNTP_SUPPRESS_DELAY_CHECK
#if SNTP_UPDATE_DELAY < 15000
#error "SNTPv4 RFC 4330 enforces a minimum update time of 15 seconds (define SNTP_SUPPRESS_DELAY_CHECK to disable this error)!"
#endif
#endif
#define SNTP_DEBUG_TRACE        (SNTP_DEBUG | LWIP_DBG_TRACE)
#define SNTP_DEBUG_STATE        (SNTP_DEBUG | LWIP_DBG_STATE)
#define SNTP_DEBUG_WARN         (SNTP_DEBUG | LWIP_DBG_LEVEL_WARNING)
#define SNTP_DEBUG_WARN_STATE   (SNTP_DEBUG | LWIP_DBG_LEVEL_WARNING | LWIP_DBG_STATE)
#define SNTP_DEBUG_SERIOUS      (SNTP_DEBUG | LWIP_DBG_LEVEL_SERIOUS)
#define SNTP_ERR_KOD                1
#define SNTP_MSG_LEN                48
#define SNTP_OFFSET_LI_VN_MODE      0
#define SNTP_LI_MASK                0xC0
#define SNTP_LI_NO_WARNING          (0x00 << 6)
#define SNTP_LI_LAST_MINUTE_61_SEC  (0x01 << 6)
#define SNTP_LI_LAST_MINUTE_59_SEC  (0x02 << 6)
#define SNTP_LI_ALARM_CONDITION     (0x03 << 6) /* (clock not synchronized) */
#define SNTP_VERSION_MASK           0x38
#define SNTP_VERSION                (4/* NTP Version 4*/<<3)
#define SNTP_MODE_MASK              0x07
#define SNTP_MODE_CLIENT            0x03
#define SNTP_MODE_SERVER            0x04
#define SNTP_MODE_BROADCAST         0x05
#define SNTP_OFFSET_STRATUM         1
#define SNTP_STRATUM_KOD            0x00
#define SNTP_OFFSET_ORIGINATE_TIME  24
#define SNTP_OFFSET_RECEIVE_TIME    32
#define SNTP_OFFSET_TRANSMIT_TIME   40
#define DIFF_SEC_1970_2036          ((u32_t)2085978496L)
#ifndef SNTP_FRAC_TO_US
# if LWIP_HAVE_INT64
#  define SNTP_FRAC_TO_US(f)        ((u32_t)(((u64_t)(f) * 1000000UL) >> 32))
# else
#  define SNTP_FRAC_TO_US(f)        ((u32_t)(f) / 4295)
# endif
#endif /* !SNTP_FRAC_TO_US */
#ifndef SNTP_SET_SYSTEM_TIME_NTP
# ifdef SNTP_SET_SYSTEM_TIME_US
#  define SNTP_SET_SYSTEM_TIME_NTP(s, f) \
# else
#  define SNTP_SET_SYSTEM_TIME_NTP(s, f) \
# endif
#endif /* !SNTP_SET_SYSTEM_TIME_NTP */
#ifndef SNTP_GET_SYSTEM_TIME_NTP
# define SNTP_GET_SYSTEM_TIME_NTP(s, f) do { \
#endif /* !SNTP_GET_SYSTEM_TIME_NTP */
#define SNTP_OFFSET_TIMESTAMPS \
#if SNTP_COMP_ROUNDTRIP
# if !LWIP_HAVE_INT64
#  error "SNTP round-trip delay compensation requires 64-bit arithmetic"
# endif
# define SNTP_SEC_FRAC_TO_S64(s, f) \
# define SNTP_TIMESTAMP_TO_S64(t) \
#endif /* SNTP_COMP_ROUNDTRIP */
#if SNTP_COMP_ROUNDTRIP || SNTP_CHECK_RESPONSE >= 2
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#if SNTP_SERVER_DNS
#endif /* SNTP_SERVER_DNS */
#if SNTP_MONITOR_SERVER_REACHABILITY
#endif /* SNTP_MONITOR_SERVER_REACHABILITY */
#if SNTP_GET_SERVERS_FROM_DHCP
#endif /* SNTP_GET_SERVERS_FROM_DHCP */
#if SNTP_SUPPORT_MULTIPLE_SERVERS
#else /* SNTP_SUPPORT_MULTIPLE_SERVERS */
#define sntp_current_server 0
#endif /* SNTP_SUPPORT_MULTIPLE_SERVERS */
#if SNTP_RETRY_TIMEOUT_EXP
#define SNTP_RESET_RETRY_TIMEOUT() sntp_retry_timeout = SNTP_RETRY_TIMEOUT
#else /* SNTP_RETRY_TIMEOUT_EXP */
#define SNTP_RESET_RETRY_TIMEOUT()
#define sntp_retry_timeout SNTP_RETRY_TIMEOUT
#endif /* SNTP_RETRY_TIMEOUT_EXP */
#if SNTP_CHECK_RESPONSE >= 1
#endif /* SNTP_CHECK_RESPONSE >= 1 */
#if SNTP_CHECK_RESPONSE >= 2
#endif /* SNTP_CHECK_RESPONSE >= 2 */
#if defined(LWIP_DEBUG) && !defined(sntp_format_time)
#endif /* LWIP_DEBUG && !sntp_format_time */
#if SNTP_COMP_ROUNDTRIP
# if SNTP_CHECK_RESPONSE >= 2
# endif
#endif /* SNTP_COMP_ROUNDTRIP */
#if SNTP_CHECK_RESPONSE >= 2 || SNTP_COMP_ROUNDTRIP
# if SNTP_CHECK_RESPONSE >= 2
# endif
#endif /* SNTP_CHECK_RESPONSE >= 2 || SNTP_COMP_ROUNDTRIP */
#if SNTP_RETRY_TIMEOUT_EXP
#endif /* SNTP_RETRY_TIMEOUT_EXP */
#if SNTP_SUPPORT_MULTIPLE_SERVERS
#if SNTP_SERVER_DNS
#endif
#else /* SNTP_SUPPORT_MULTIPLE_SERVERS */
#define sntp_try_next_server    sntp_retry
#endif /* SNTP_SUPPORT_MULTIPLE_SERVERS */
#if SNTP_CHECK_RESPONSE >= 1
#else /* SNTP_CHECK_RESPONSE >= 1 */
#endif /* SNTP_CHECK_RESPONSE >= 1 */
#if SNTP_CHECK_RESPONSE >= 2
#endif /* SNTP_CHECK_RESPONSE >= 2 */
#if SNTP_CHECK_RESPONSE >= 1
#endif /* SNTP_CHECK_RESPONSE >= 1 */
#if SNTP_MONITOR_SERVER_REACHABILITY
#endif /* SNTP_MONITOR_SERVER_REACHABILITY */
#if SNTP_MONITOR_SERVER_REACHABILITY
#endif /* SNTP_MONITOR_SERVER_REACHABILITY */
#if SNTP_CHECK_RESPONSE >= 1
#endif /* SNTP_CHECK_RESPONSE >= 1 */
#if SNTP_SERVER_DNS
#endif /* SNTP_SERVER_DNS */
#if SNTP_SERVER_DNS
#endif /* SNTP_SERVER_DNS */
#ifdef SNTP_SERVER_ADDRESS
#if SNTP_SERVER_DNS
#else
#error SNTP_SERVER_ADDRESS string not supported SNTP_SERVER_DNS==0
#endif
#endif /* SNTP_SERVER_ADDRESS */
#if SNTP_STARTUP_DELAY
#else
#endif
#if SNTP_MONITOR_SERVER_REACHABILITY
#endif /* SNTP_MONITOR_SERVER_REACHABILITY */
#if SNTP_MONITOR_SERVER_REACHABILITY
#endif /* SNTP_MONITOR_SERVER_REACHABILITY */
#if SNTP_GET_SERVERS_FROM_DHCP
#endif /* SNTP_GET_SERVERS_FROM_DHCP */
#if SNTP_SERVER_DNS
#endif
#if LWIP_DHCP && SNTP_GET_SERVERS_FROM_DHCP
#endif /* LWIP_DHCP && SNTP_GET_SERVERS_FROM_DHCP */
#if SNTP_SERVER_DNS
#endif /* SNTP_SERVER_DNS */
#endif /* LWIP_UDP */
