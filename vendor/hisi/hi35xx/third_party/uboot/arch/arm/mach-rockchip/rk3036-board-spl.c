#include <common.h>
#include <debug_uart.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/sdram_rk3036.h>
#define TIMER_LOAD_COUNT_L	0x00
#define TIMER_LOAD_COUNT_H	0x04
#define TIMER_CONTROL_REG	0x10
#define TIMER_EN	0x1
#define	TIMER_FMODE	(0 << 1)
#define	TIMER_RMODE	(1 << 1)
#ifdef CONFIG_DEBUG_UART
#endif
