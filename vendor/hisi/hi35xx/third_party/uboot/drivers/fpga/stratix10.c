#include <common.h>
#include <altera.h>
#include <asm/arch/mailbox_s10.h>
#define RECONFIG_STATUS_POLL_RESP_TIMEOUT_MS		60000
#define RECONFIG_STATUS_INTERVAL_DELAY_US		1000000
#define MBOX_CFGSTAT_MAX ARRAY_SIZE(mbox_cfgstat_state)
