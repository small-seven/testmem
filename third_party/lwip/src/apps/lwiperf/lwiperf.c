#include "lwip/apps/lwiperf.h"
#include "lwip/tcp.h"
#include "lwip/sys.h"
#include <string.h>
#if LWIP_TCP && LWIP_CALLBACK_API
#ifndef LWIPERF_TCP_MAX_IDLE_SEC
#define LWIPERF_TCP_MAX_IDLE_SEC    10U
#endif
#if LWIPERF_TCP_MAX_IDLE_SEC > 255
#error LWIPERF_TCP_MAX_IDLE_SEC must fit into an u8_t
#endif
#ifndef LWIPERF_SERVER_IP_TYPE
#define LWIPERF_SERVER_IP_TYPE      IPADDR_TYPE_ANY
#endif
#ifndef LWIPERF_ALLOC
#define LWIPERF_ALLOC(type)         mem_malloc(sizeof(type))
#define LWIPERF_FREE(type, item)    mem_free(item)
#endif
#ifndef LWIPERF_CHECK_RX_DATA
#define LWIPERF_CHECK_RX_DATA       0
#endif
typedef struct _lwiperf_settings {
#define LWIPERF_FLAGS_ANSWER_TEST 0x80000000
#define LWIPERF_FLAGS_ANSWER_NOW  0x00000001
  u32_t flags;
  u32_t num_threads; /* unused for now */
  u32_t remote_port;
  u32_t buffer_len; /* unused for now */
  u32_t win_band; /* TCP window / UDP rate: unused for now */
  u32_t amount; /* pos. value: bytes?; neg. values: time (unit is 10ms: 1/100 second) */
} lwiperf_settings_t;
typedef struct _lwiperf_state_base lwiperf_state_base_t;
struct _lwiperf_state_base {
  /* linked list */
  lwiperf_state_base_t *next;
  /* 1=tcp, 0=udp */
  u8_t tcp;
  /* 1=server, 0=client */
  u8_t server;
  /* master state used to abort sessions (e.g. listener, main client) */
  lwiperf_state_base_t *related_master_state;
};
typedef struct _lwiperf_state_tcp {
  lwiperf_state_base_t base;
  struct tcp_pcb *server_pcb;
  struct tcp_pcb *conn_pcb;
  u32_t time_started;
  lwiperf_report_fn report_fn;
  void *report_arg;
  u8_t poll_count;
  u8_t next_num;
  /* 1=start server when client is closed */
  u8_t client_tradeoff_mode;
  u32_t bytes_transferred;
  lwiperf_settings_t settings;
  u8_t have_settings_buf;
  u8_t specific_remote;
  ip_addr_t remote_addr;
} lwiperf_state_tcp_t;
lwiperf_list_remove(lwiperf_state_base_t *item)
{
  lwiperf_state_base_t *prev = NULL;
  lwiperf_state_base_t *iter;
  for (iter = lwiperf_all_connections; iter != NULL; prev = iter, iter = iter->next) {
    if (iter == item) {
      if (prev == NULL) {
        lwiperf_all_connections = iter->next;
      } else {
        prev->next = iter->next;
      }
      /* @debug: ensure this item is listed only once */
      for (iter = iter->next; iter != NULL; iter = iter->next) {
        LWIP_ASSERT("duplicate entry", iter != item);
      }
      break;
    }
  }
}
#if LWIPERF_CHECK_RX_DATA
#endif
#endif /* LWIP_TCP && LWIP_CALLBACK_API */
