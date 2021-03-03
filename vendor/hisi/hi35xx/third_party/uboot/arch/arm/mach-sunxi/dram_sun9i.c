#include <common.h>
#include <dm.h>
#include <errno.h>
#include <ram.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/dram.h>
#include <asm/arch/sys_proto.h>
#define DRAM_CLK (CONFIG_DRAM_CLK * 1000000)
#define SCHED_RDWR_IDLE_GAP(n)            ((n & 0xff) << 24)
#define SCHED_GO2CRITICAL_HYSTERESIS(n)   ((n & 0xff) << 16)
#define SCHED_LPR_NUM_ENTRIES(n)          ((n & 0xff) <<  8)
#define SCHED_PAGECLOSE                   (1 << 2)
#define SCHED_PREFER_WRITE                (1 << 1)
#define SCHED_FORCE_LOW_PRI_N             (1 << 0)
#define SCHED_CONFIG		(SCHED_RDWR_IDLE_GAP(0xf) | \
#define PERFHPR0_CONFIG                   0x0000001f
#define PERFHPR1_CONFIG                   0x1f00001f
#define PERFLPR0_CONFIG                   0x000000ff
#define PERFLPR1_CONFIG                   0x0f0000ff
#define PERFWR0_CONFIG                    0x000000ff
#define PERFWR1_CONFIG                    0x0f0001ff
#define PS2CYCLES_FLOOR(n)    ((n * CONFIG_DRAM_CLK) / 1000000)
#define PS2CYCLES_ROUNDUP(n)  ((n * CONFIG_DRAM_CLK + 999999) / 1000000)
#define NS2CYCLES_FLOOR(n)    ((n * CONFIG_DRAM_CLK) / 1000)
#define NS2CYCLES_ROUNDUP(n)  ((n * CONFIG_DRAM_CLK + 999) / 1000)
#define MAX(a, b)             ((a) > (b) ? (a) : (b))
#define MCTL_BL               8
#define WR2PRE           (MCTL_BL/2 + CWL + tWTR)
#define WR2RD            (MCTL_BL/2 + CWL + tWTR)
#define RD2WR            (CL + MCTL_BL/2 + 2 - CWL)
#define MCTL_PHY_TRTW        0
#define MCTL_PHY_TRTODT      0
#define MCTL_DIV2(n)         ((n + 1)/2)
#define MCTL_DIV32(n)        (n/32)
#define MCTL_DIV1024(n)      (n/1024)
