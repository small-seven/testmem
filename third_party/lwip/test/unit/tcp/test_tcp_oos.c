#include "test_tcp_oos.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/stats.h"
#include "tcp_helper.h"
#if !LWIP_STATS || !TCP_STATS || !MEMP_STATS
#error "This tests needs TCP- and MEMP-statistics enabled"
#endif
#if !TCP_QUEUE_OOSEQ
#error "This tests needs TCP_QUEUE_OOSEQ enabled"
#endif
#define CHECK_SEGMENTS_ON_OOSEQ 1
#if CHECK_SEGMENTS_ON_OOSEQ
#define EXPECT_OOSEQ(x) EXPECT(x)
#else
#define EXPECT_OOSEQ(x)
#endif
#if TCP_OOSEQ_MAX_PBUFS && (TCP_OOSEQ_MAX_PBUFS < ((TCP_WND / TCP_MSS) + 1)) && (PBUF_POOL_BUFSIZE >= (TCP_MSS + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN))
#endif
#if !TCP_OOSEQ_MAX_BYTES && !TCP_OOSEQ_MAX_PBUFS
#endif /* !TCP_OOSEQ_MAX_BYTES && !TCP_OOSEQ_MAX_PBUFS */
#if !TCP_OOSEQ_MAX_BYTES && !TCP_OOSEQ_MAX_PBUFS
#endif /* !TCP_OOSEQ_MAX_BYTES && !TCP_OOSEQ_MAX_PBUFS */
#if TCP_OOSEQ_MAX_BYTES && (TCP_OOSEQ_MAX_BYTES < (TCP_WND + 1)) && (PBUF_POOL_BUFSIZE >= (TCP_MSS + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN))
#endif /* TCP_OOSEQ_MAX_BYTES && (TCP_OOSEQ_MAX_BYTES < (TCP_WND + 1)) && (PBUF_POOL_BUFSIZE >= (TCP_MSS + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN)) */
#if TCP_OOSEQ_MAX_PBUFS && (TCP_OOSEQ_MAX_PBUFS < ((TCP_WND / TCP_MSS) + 1)) && (PBUF_POOL_BUFSIZE >= (TCP_MSS + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN))
#endif /* TCP_OOSEQ_MAX_PBUFS && (TCP_OOSEQ_MAX_BYTES < (TCP_WND + 1)) && (PBUF_POOL_BUFSIZE >= (TCP_MSS + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN)) */
#define FIN_TEST(name, num) \
