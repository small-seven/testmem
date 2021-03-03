#include <common.h>
#include <debug_uart.h>
#include <dm.h>
#include <ram.h>
#include <spl.h>
#include <version.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/sdram_px30.h>
#define TIMER_LOAD_COUNT0	0x00
#define TIMER_LOAD_COUNT1	0x04
#define TIMER_CUR_VALUE0	0x08
#define TIMER_CUR_VALUE1	0x0c
#define TIMER_CONTROL_REG	0x10
#define TIMER_EN	0x1
#define	TIMER_FMODE	(0 << 1)
#define	TIMER_RMODE	(1 << 1)
#ifdef CONFIG_DEBUG_UART
#endif
