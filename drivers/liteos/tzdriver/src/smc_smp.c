#include "smc.h"
#include <securec.h>
#include <linux/sched.h>
#include "agent.h"
#include "cmdmonitor.h"
#include "tc_ns_client.h"
#include "tc_ns_log.h"
#include "teek_client_constants.h"
#include "teek_ns_client.h"
#include "tzdriver_compat.h"
#ifdef SECURITY_AUTH_ENHANCE
#include "security_auth_enhance.h"
#endif
#define SECS_SUSPEND_STATUS      0xA5A5
#define PREEMPT_COUNT            10000
#define HZ_COUNT                 10
#define IDLED_COUNT              100
#define MAX_EMPTY_RUNS           100
#define TZ_CPU_ZERO    0
#define TZ_CPU_ONE     1
#define TZ_CPU_FOUR    4
#define TZ_CPU_FIVE    5
#define TZ_CPU_SIX     6
#define TZ_CPU_SEVEN   7
#define LOW_BYTE    0xF
typedef struct {
    int *nIdled;
    uint64_t *ret;
    uint64_t *exitReason;
    uint64_t *ta;
    uint64_t *target;
} WoPmParams;
#ifdef SECURITY_AUTH_ENHANCE
#define MAX_SMC_CMD 18
#else
#define MAX_SMC_CMD 23
#endif
typedef uint32_t SmcBufLockT;

typedef struct __attribute__((__packed__)) TcNsSmcQueue {
    /* set when CA send cmdIn, clear after cmdOut return */
    DECLARE_BITMAP(inBitmap, MAX_SMC_CMD);
    /* set when gtask get cmdIn, clear after cmdOut return */
    DECLARE_BITMAP(doingBitmap, MAX_SMC_CMD);
    /* set when gtask get cmdOut, clear after cmdOut return */
    DECLARE_BITMAP(outBitmap, MAX_SMC_CMD);
    SmcBufLockT smcLock;
    uint32_t lastIn;
    TcNsSmcCmd in[MAX_SMC_CMD];
    uint32_t lastOut;
    TcNsSmcCmd out[MAX_SMC_CMD];
} TcNsSmcQueue;
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#define SHADOW_EXIT_RUN             0x1234dead
typedef struct SmcCmdRet {
    uint64_t exit;
    uint64_t ta;
    uint64_t target;
} SmcCmdRetT;
#define CPU0_ONLY_MASK 0x0001
#if CONFIG_CPU_AFF_NR
#endif
#if CONFIG_CPU_AFF_NR
#endif
#if CONFIG_CPU_AFF_NR
#endif
#if CONFIG_CPU_AFF_NR
#endif
#ifndef CONFIG_PREEMPT
#endif
#if CONFIG_CPU_AFF_NR
#endif
#if (CONFIG_CPU_AFF_NR != 0)
#endif
#if (CONFIG_CPU_AFF_NR != 0)
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef CONFIG_TEELOG
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#define SYM_NAME_LEN_MAX 16
#define SYM_NAME_LEN_1 7
#define SYM_NAME_LEN_2 4
#define CRASH_REG_NUM  3
#define LOW_FOUR_BITE  4
typedef union {
    uint64_t crashReg[CRASH_REG_NUM];
    struct {
        uint8_t haltReason : LOW_FOUR_BITE;
        uint8_t app : LOW_FOUR_BITE;
        char symName[SYM_NAME_LEN_1];
        uint16_t off;
        uint16_t size;
        uint32_t far;
        uint32_t fault;
        union {
            char symNameAppend[SYM_NAME_LEN_2];
            uint32_t elr;
        };
#ifdef CONFIG_TEELOG
#endif
#define GOTO_RESLEEP 1
#define GOTO_RETRY_WITH_CMD 2
#define GOTO_RETRY 3
#define GOTO_CLEAN 4
#if CONFIG_CPU_AFF_NR
#endif
#ifdef SECURITY_AUTH_ENHANCE
#define ALIGN_BIT  0x3
#ifdef CONFIG_ARM64
#else
#endif
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
