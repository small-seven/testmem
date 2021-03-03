#include "tcp_helper.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/stats.h"
#include "lwip/pbuf.h"
#include "lwip/inet_chksum.h"
#include "lwip/ip_addr.h"
#if !LWIP_STATS || !TCP_STATS || !MEMP_STATS
#error "This tests needs TCP- and MEMP-statistics enabled"
#endif
tcp_remove(struct tcp_pcb* pcb_list)
{
  struct tcp_pcb *pcb = pcb_list;
  struct tcp_pcb *pcb2;

  while(pcb != NULL) {
    pcb2 = pcb;
    pcb = pcb->next;
    tcp_abort(pcb2);
  }
}
tcp_create_segment(ip_addr_t* src_ip, ip_addr_t* dst_ip,
                   u16_t src_port, u16_t dst_port, void* data, size_t data_len,
                   u32_t seqno, u32_t ackno, u8_t headerflags)
{
  return tcp_create_segment_wnd(src_ip, dst_ip, src_port, dst_port, data,
    data_len, seqno, ackno, headerflags, TCP_WND);
}
