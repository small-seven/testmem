#include <common.h>
#include <cpu_func.h>
#include <vsprintf.h>
#include <asm/arch/clock.h>
#include <asm/io.h>
#include <asm/arch/immap_ls102xa.h>
#include <asm/cache.h>
#include <asm/system.h>
#include <tsec.h>
#include <netdev.h>
#include <fsl_esdhc.h>
#include <config.h>
#include <fsl_wdog.h>
#include "fsl_epu.h"
#define DCSR_RCPM2_BLOCK_OFFSET	0x223000
#define DCSR_RCPM2_CPMFSMCR0	0x400
#define DCSR_RCPM2_CPMFSMSR0	0x404
#define DCSR_RCPM2_CPMFSMCR1	0x414
#define DCSR_RCPM2_CPMFSMSR1	0x418
#define CPMFSMSR_FSM_STATE_MASK	0x7f
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#define PMD_TYPE_TABLE		0x3
#define PMD_TYPE_SECT		0x1
#define PMD_ATTRINDX(t)		((t) << 2)
#define PMD_SECT_AF		(1 << 10)
#define BLOCK_SIZE_L1		(1UL << 30)
#define BLOCK_SIZE_L2		(1UL << 21)
#define TTBCR_EAE		(1 << 31)
#define TTBCR_T0SZ(x)		((x) << 0)
#define TTBCR_T1SZ(x)		((x) << 16)
#define TTBCR_USING_TTBR0	(TTBCR_T0SZ(0) | TTBCR_T1SZ(0))
#define TTBCR_IRGN0_NC		(0 << 8)
#define TTBCR_IRGN0_WBWA	(1 << 8)
#define TTBCR_IRGN0_WT		(2 << 8)
#define TTBCR_IRGN0_WBNWA	(3 << 8)
#define TTBCR_IRGN0_MASK	(3 << 8)
#define TTBCR_ORGN0_NC		(0 << 10)
#define TTBCR_ORGN0_WBWA	(1 << 10)
#define TTBCR_ORGN0_WT		(2 << 10)
#define TTBCR_ORGN0_WBNWA	(3 << 10)
#define TTBCR_ORGN0_MASK	(3 << 10)
#define TTBCR_SHARED_NON	(0 << 12)
#define TTBCR_SHARED_OUTER	(2 << 12)
#define TTBCR_SHARED_INNER	(3 << 12)
#define TTBCR_EPD0		(0 << 7)
#define TTBCR			(TTBCR_SHARED_NON | \
#define MT_MAIR0		0xeeaa4400
#define MT_MAIR1		0xff000004
#define MT_STRONLY_ORDER	0
#define MT_NORMAL_NC		1
#define MT_DEVICE_MEM		4
#define MT_NORMAL		7
#endif /* #if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) */
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#ifdef CONFIG_FSL_ESDHC
#endif
#if defined(CONFIG_TSEC_ENET) && !defined(CONFIG_DM_ETH)
#endif
#ifdef CONFIG_ARMV7_NONSEC
#endif
