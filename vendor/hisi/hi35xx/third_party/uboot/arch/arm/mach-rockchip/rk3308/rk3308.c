#include <common.h>
#include <asm/io.h>
#include <asm/arch/grf_rk3308.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/gpio.h>
#include <debug_uart.h>
#include <asm/armv8/mmu.h>
#define GRF_BASE	0xff000000
#define SGRF_BASE	0xff2b0000
#define GPIO0_A4	4
#if defined(CONFIG_DEBUG_UART)
#endif
#if defined(CONFIG_SPL_BUILD)
#endif
