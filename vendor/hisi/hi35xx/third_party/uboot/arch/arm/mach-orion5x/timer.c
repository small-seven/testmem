#include <common.h>
#include <time.h>
#include <asm/io.h>
#define UBOOT_CNTR	0	/* counter to use for uboot timer */
#define CNTMR_CTRL_REG			(&orion5x_tmr_regs->ctrl)
#define CNTMR_RELOAD_REG(tmrnum)	(&orion5x_tmr_regs->tmr[tmrnum].reload)
#define CNTMR_VAL_REG(tmrnum)		(&orion5x_tmr_regs->tmr[tmrnum].val)
#define CTCR_ARM_TIMER_EN_OFFS(cntr)	(cntr * 2)
#define CTCR_ARM_TIMER_EN_MASK(cntr)	(1 << CTCR_ARM_TIMER_EN_OFFS)
#define CTCR_ARM_TIMER_EN(cntr)		(1 << CTCR_ARM_TIMER_EN_OFFS(cntr))
#define CTCR_ARM_TIMER_DIS(cntr)	(0 << CTCR_ARM_TIMER_EN_OFFS(cntr))
#define CTCR_ARM_TIMER_AUTO_OFFS(cntr)	((cntr * 2) + 1)
#define CTCR_ARM_TIMER_AUTO_MASK(cntr)	(1 << 1)
#define CTCR_ARM_TIMER_AUTO_EN(cntr)	(1 << CTCR_ARM_TIMER_AUTO_OFFS(cntr))
#define CTCR_ARM_TIMER_AUTO_DIS(cntr)	(0 << CTCR_ARM_TIMER_AUTO_OFFS(cntr))
#define TRG_ARM_TIMER_REL_OFFS		0
#define TRG_ARM_TIMER_REL_MASK		0xffffffff
#define TVR_ARM_TIMER_OFFS		0
#define TVR_ARM_TIMER_MASK		0xffffffff
#define TVR_ARM_TIMER_MAX		0xffffffff
#define TIMER_LOAD_VAL 			0xffffffff
#define timestamp gd->arch.tbl
#define lastdec gd->arch.lastinc
