#include "los_hw_pri.h"
#include "los_tick_pri.h"
#include "los_sys_pri.h"
#include "gic_common.h"
#define STRING_COMB(x, y, z)        x ## y ## z
#ifdef LOSCFG_ARCH_SECURE_MONITOR_MODE
#define TIMER_REG(reg)              STRING_COMB(TIMER_REG_, CNTPS, reg)
#else
#define TIMER_REG(reg)              STRING_COMB(TIMER_REG_, CNTP, reg)
#endif
#define TIMER_REG_CTL               TIMER_REG(_CTL)     /* 32 bits */
#define TIMER_REG_TVAL              TIMER_REG(_TVAL)    /* 32 bits */
#define TIMER_REG_CVAL              TIMER_REG(_CVAL)    /* 64 bits */
#define TIMER_REG_CT                TIMER_REG(CT)       /* 64 bits */
#ifdef __LP64__
#define TIMER_REG_CNTFRQ            cntfrq_el0
#define TIMER_REG_CNTP_CTL          cntp_ctl_el0
#define TIMER_REG_CNTP_TVAL         cntp_tval_el0
#define TIMER_REG_CNTP_CVAL         cntp_cval_el0
#define TIMER_REG_CNTPCT            cntpct_el0
#define TIMER_REG_CNTPS_CTL         cntps_ctl_el1
#define TIMER_REG_CNTPS_TVAL        cntps_tval_el1
#define TIMER_REG_CNTPS_CVAL        cntps_cval_el1
#define TIMER_REG_CNTPSCT           cntpct_el0
#define READ_TIMER_REG32(reg)       AARCH64_SYSREG_READ(reg)
#define READ_TIMER_REG64(reg)       AARCH64_SYSREG_READ(reg)
#define WRITE_TIMER_REG32(reg, val) AARCH64_SYSREG_WRITE(reg, (UINT64)(val))
#define WRITE_TIMER_REG64(reg, val) AARCH64_SYSREG_WRITE(reg, val)
#else /* Aarch32 */
#define TIMER_REG_CNTFRQ            CP15_REG(c14, 0, c0, 0)
#define TIMER_REG_CNTP_CTL          CP15_REG(c14, 0, c2, 1)
#define TIMER_REG_CNTP_TVAL         CP15_REG(c14, 0, c2, 0)
#define TIMER_REG_CNTP_CVAL         CP15_REG64(c14, 2)
#define TIMER_REG_CNTPCT            CP15_REG64(c14, 0)
#define CNTPS CNTP
#define READ_TIMER_REG32(reg)       ARM_SYSREG_READ(reg)
#define READ_TIMER_REG64(reg)       ARM_SYSREG64_READ(reg)
#define WRITE_TIMER_REG32(reg, val) ARM_SYSREG_WRITE(reg, val)
#define WRITE_TIMER_REG64(reg, val) ARM_SYSREG64_WRITE(reg, val)
#endif
#define OS_CYCLE_PER_TICK (g_sysClock / LOSCFG_BASE_CORE_TICK_PER_SECOND)
