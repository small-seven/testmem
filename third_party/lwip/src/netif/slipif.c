#include "netif/slipif.h"
#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/pbuf.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "lwip/sys.h"
#include "lwip/sio.h"
#define SLIP_END     0xC0 /* 0300: start and end of every packet */
#define SLIP_ESC     0xDB /* 0333: escape start (one byte escaped data follows) */
#define SLIP_ESC_END 0xDC /* 0334: following escape: original byte is 0xC0 (END) */
#define SLIP_ESC_ESC 0xDD /* 0335: following escape: original byte is 0xDB (ESC) */
#ifndef SLIP_MAX_SIZE
#define SLIP_MAX_SIZE 1500
#endif
#ifndef SLIP_SIO_SPEED
#define SLIP_SIO_SPEED(sio_fd) 0
#endif
#if SLIP_RX_FROM_ISR
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if SLIP_USE_RX_THREAD
#endif /* SLIP_USE_RX_THREAD */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if SLIP_RX_FROM_ISR
#endif
#if SLIP_USE_RX_THREAD
#endif /* SLIP_USE_RX_THREAD */
#if SLIP_RX_FROM_ISR
#if SLIP_RX_QUEUE
#else /* SLIP_RX_QUEUE */
#endif /* SLIP_RX_QUEUE */
#if SLIP_RX_QUEUE
#else /* SLIP_RX_QUEUE */
#endif /* SLIP_RX_QUEUE */
#endif /* SLIP_RX_FROM_ISR */
