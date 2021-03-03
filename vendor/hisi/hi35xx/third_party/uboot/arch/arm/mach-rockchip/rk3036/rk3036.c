#include <asm/io.h>
#include <asm/arch-rockchip/grf_rk3036.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/sdram_rk3036.h>
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#define GRF_BASE	0x20008000
#endif
#if !CONFIG_IS_ENABLED(RAM)
#endif
