#include <common.h>
#include <dm.h>
#include <errno.h>
#include <timer.h>
#include <linux/io.h>
#define REG32_TMR(x)	(*(u32 *)	((plat->regs) + (x>>2)))
#define ID_REV		0x0
#define CFG		0x10
#define INT_EN		0x14
#define CH_INT_EN(c , i)	((1<<i)<<(4*c))
#define INT_STA		0x18
#define CH_INT_STA(c , i)	((1<<i)<<(4*c))
#define CH_EN		0x1C
#define CH_TMR_EN(c , t)	((1<<t)<<(4*c))
#define CH_CTL(n)	(0x20+0x10*n)
#define APB_CLK		(1<<3)
#define TMR_32		1
#define TMR_16		2
#define TMR_8		3
#define PWM		4
#define CH_REL(n)	(0x24+0x10*n)
#define CH_CNT(n)	(0x28+0x10*n)
