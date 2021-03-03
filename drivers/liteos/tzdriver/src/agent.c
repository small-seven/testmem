#include "agent.h"
#include <securec.h>
#include "cmdmonitor.h"
#include "mailbox_mempool.h"
#include "smc.h"
#include "tc_client_sub_driver.h"
#include "tc_ns_log.h"
#include "teek_client_constants.h"
#include "tzdriver_compat.h"
#define HASH_FILE_MAX_SIZE         (16 * 1024)
#define AGENT_BUFF_SIZE            (4 * 1024)
#define AGENT_MAX                  32
#define MAX_PATH_SIZE              512
#define PAGE_ORDER_RATIO           2
typedef struct TagCaInfo {
    char path[MAX_PATH_SIZE];
    uint32_t uid;
    uint32_t agentId;
} CaInfo;
#ifdef DEF_ENG
#endif
#ifndef CONFIG_TEE_SMP
#endif
#ifdef CONFIG_TEE_SMP
#endif
#ifdef CONFIG_TEE_SMP
#else
#endif
#ifdef CONFIG_TEE_SMP
#endif
#ifdef CONFIG_TEE_SMP
#endif
