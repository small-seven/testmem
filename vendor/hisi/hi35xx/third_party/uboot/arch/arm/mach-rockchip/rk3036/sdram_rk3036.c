#include <common.h>
#include <asm/io.h>
#include <asm/types.h>
#include <asm/arch-rockchip/cru_rk3036.h>
#include <asm/arch-rockchip/grf_rk3036.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/sdram_rk3036.h>
#include <asm/arch-rockchip/uart.h>
#define CRU_BASE	0x20000000
#define GRF_BASE	0x20008000
#define DDR_PHY_BASE	0x2000a000
#define DDR_PCTL_BASE	0x20004000
#define CPU_AXI_BUS_BASE	0x10128000
#define	MSCH4_MAINDDR3		(1 << 7)
#define PHY_DRV_ODT_SET(n)	((n << 4) | n)
#define DDR3_DLL_RESET		(1 << 8)
