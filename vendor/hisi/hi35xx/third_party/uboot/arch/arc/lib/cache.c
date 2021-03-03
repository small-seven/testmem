#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <linux/compiler.h>
#include <linux/kernel.h>
#include <linux/log2.h>
#include <asm/arcregs.h>
#include <asm/arc-bcr.h>
#include <asm/cache.h>
#define IC_CTRL_CACHE_DISABLE	BIT(0)
#define DC_CTRL_CACHE_DISABLE	BIT(0)
#define DC_CTRL_INV_MODE_FLUSH	BIT(6)
#define DC_CTRL_FLUSH_STATUS	BIT(8)
#define OP_INV			BIT(0)
#define OP_FLUSH		BIT(1)
#define OP_FLUSH_N_INV		(OP_FLUSH | OP_INV)
#define SLC_CTRL_DIS		0x001
#define SLC_CTRL_IM		0x040
#define SLC_CTRL_BUSY		0x100
#define SLC_CTRL_RGN_OP_INV	0x200
#define CACHE_LINE_MASK		(~(gd->arch.l1_line_sz - 1))
#define inlined_cachefunc	 inline __attribute__((always_inline))
#if (CONFIG_ARC_MMU_VER >= 4)
#endif /* (CONFIG_ARC_MMU_VER >= 4) */
#ifdef CONFIG_ISA_ARCV2
#endif /* CONFIG_ISA_ARCV2 */
#ifdef CONFIG_ISA_ARCV2
#endif /* CONFIG_ISA_ARCV2 */
#if (CONFIG_ARC_MMU_VER == 3)
#endif
