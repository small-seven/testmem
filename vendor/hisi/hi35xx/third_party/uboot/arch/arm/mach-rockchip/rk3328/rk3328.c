#include <common.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/grf_rk3328.h>
#include <asm/arch-rockchip/uart.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#define CRU_BASE		0xFF440000
#define GRF_BASE		0xFF100000
#define UART2_BASE		0xFF130000
#define FW_DDR_CON_REG		0xFF7C0040
#ifdef CONFIG_SPL_BUILD
#endif
