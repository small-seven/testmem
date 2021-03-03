#include "mailbox_mempool.h"
#include <securec.h>
#include "smc.h"
#include "tc_ns_log.h"
#include "teek_client_constants.h"
#include "tzdriver_compat.h"
#define MAILBOX_PAGE_MAX (MAILBOX_POOL_SIZE >> PAGE_SHIFT)
#define MAILBOX_ORDER_MAX GET_ORDER(MAILBOX_POOL_SIZE)
#ifdef DEF_ENG
#define MB_SHOW_LINE 64
#define BITS_OF_BYTE  8
#endif
#ifdef DEF_ENG
#define MB_WRITE_SIZE 64
#define DBG_READ_BUFSIZE 16
#endif
#define TC_NS_CLIENT_MEILBOX_OPT_NAME "/dev/tz_mailbox_opt"
#define TC_NS_CLIENT_MEILBOX_STATE_NAME "/dev/tz_mailbox_state"
#ifdef DEF_ENG
#endif
