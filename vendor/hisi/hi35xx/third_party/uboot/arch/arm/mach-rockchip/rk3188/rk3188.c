#include <common.h>
#include <dm.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/grf_rk3188.h>
#include <asm/arch-rockchip/hardware.h>
#define GRF_BASE	0x20008000
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_ROCKCHIP_USB_UART
#endif
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SPL_LED
#endif
#endif
