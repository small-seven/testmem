#include "netif/bridgeif.h"
#include "lwip/sys.h"
#include "lwip/mem.h"
#include "lwip/timeouts.h"
#include <string.h>
#define BRIDGEIF_AGE_TIMER_MS 1000
#define BR_FDB_TIMEOUT_SEC  (60*5) /* 5 minutes FDB timeout */
typedef struct bridgeif_dfdb_entry_s {
  u8_t used;
  u8_t port;
  u32_t ts;
  struct eth_addr addr;
} bridgeif_dfdb_entry_t;
typedef struct bridgeif_dfdb_s {
  u16_t max_fdb_entries;
  bridgeif_dfdb_entry_t *fdb;
} bridgeif_dfdb_t;
