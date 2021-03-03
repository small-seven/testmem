#include <common.h>
#include <command.h>
#include <linux/compat.h>
#include <rtc.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#define DCAMR_UNSET	0xFFFFFFFF	/* doomsday - 1 sec */
#define DCR_TCE		(1 << 3)	/* Time Counter Enable */
#define DSR_WBF		(1 << 10)	/* Write Busy Flag */
#define DSR_WNF		(1 << 9)	/* Write Next Flag */
#define DSR_WCF		(1 << 8)	/* Write Complete Flag */
#define DSR_WEF		(1 << 7)	/* Write Error Flag */
#define DSR_CAF		(1 << 4)	/* Clock Alarm Flag */
#define DSR_NVF		(1 << 1)	/* Non-Valid Flag */
#define DSR_SVF		(1 << 0)	/* Security Violation Flag */
#define DIER_WNIE	(1 << 9)	/* Write Next Interrupt Enable */
#define DIER_WCIE	(1 << 8)	/* Write Complete Interrupt Enable */
#define DIER_WEIE	(1 << 7)	/* Write Error Interrupt Enable */
#define DIER_CAIE	(1 << 4)	/* Clock Alarm Interrupt Enable */
#define DI_WRITE_WAIT(val, reg)						\
