#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fsl_lpuart.h>
#include <watchdog.h>
#include <asm/io.h>
#include <serial.h>
#include <linux/compiler.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#define US1_TDRE	(1 << 7)
#define US1_RDRF	(1 << 5)
#define US1_OR		(1 << 3)
#define UC2_TE		(1 << 3)
#define UC2_RE		(1 << 2)
#define CFIFO_TXFLUSH	(1 << 7)
#define CFIFO_RXFLUSH	(1 << 6)
#define SFIFO_RXOF	(1 << 2)
#define SFIFO_RXUF	(1 << 0)
#define STAT_LBKDIF	(1 << 31)
#define STAT_RXEDGIF	(1 << 30)
#define STAT_TDRE	(1 << 23)
#define STAT_RDRF	(1 << 21)
#define STAT_IDLE	(1 << 20)
#define STAT_OR		(1 << 19)
#define STAT_NF		(1 << 18)
#define STAT_FE		(1 << 17)
#define STAT_PF		(1 << 16)
#define STAT_MA1F	(1 << 15)
#define STAT_MA2F	(1 << 14)
#define STAT_FLAGS	(STAT_LBKDIF | STAT_RXEDGIF | STAT_IDLE | STAT_OR | \
#define CTRL_TE		(1 << 19)
#define CTRL_RE		(1 << 18)
#define FIFO_RXFLUSH		BIT(14)
#define FIFO_TXFLUSH		BIT(15)
#define FIFO_TXSIZE_MASK	0x70
#define FIFO_TXSIZE_OFF	4
#define FIFO_RXSIZE_MASK	0x7
#define FIFO_RXSIZE_OFF	0
#define FIFO_TXFE		0x80
#ifdef CONFIG_ARCH_IMX8
#define FIFO_RXFE		0x08
#else
#define FIFO_RXFE		0x40
#endif
#define WATER_TXWATER_OFF	0
#define WATER_RXWATER_OFF	16
#define LPUART_FLAG_REGMAP_32BIT_REG	BIT(0)
#define LPUART_FLAG_REGMAP_ENDIAN_BIG	BIT(1)
#ifndef CONFIG_SYS_CLK_FREQ
#define CONFIG_SYS_CLK_FREQ	0
#endif
#if CONFIG_IS_ENABLED(CLK)
#else
#endif
