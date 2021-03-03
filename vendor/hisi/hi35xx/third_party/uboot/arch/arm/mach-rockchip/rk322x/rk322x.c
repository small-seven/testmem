#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/grf_rk322x.h>
#include <asm/arch-rockchip/hardware.h>
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#define GRF_BASE	0x11000000
#endif
#ifdef CONFIG_SPL_BUILD
#define SGRF_BASE	0x10150000
#else
#define GRF_BASE	0x11000000
#endif
