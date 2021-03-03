#include <common.h>
#include <debug_uart.h>
#include <dm.h>
#include <ram.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_px30.h>
#include <asm/arch-rockchip/grf_px30.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/sdram.h>
#include <asm/arch-rockchip/sdram_px30.h>
#ifdef CONFIG_TPL_BUILD
#endif
#ifdef CONFIG_TPL_BUILD
#define PMUGRF_BASE_ADDR		0xFF010000
#define CRU_BASE_ADDR			0xFF2B0000
#define GRF_BASE_ADDR			0xFF140000
#define DDRC_BASE_ADDR			0xFF600000
#define DDR_PHY_BASE_ADDR		0xFF2A0000
#define SERVER_MSCH0_BASE_ADDR		0xFF530000
#define DDR_GRF_BASE_ADDR		0xff630000
#include	"sdram-px30-ddr3-detect-333.inc"
#include	"sdram-px30-ddr_skew.inc"
#define MIN(a, b)	(((a) > (b)) ? (b) : (a))
#define MAX(a, b)	(((a) > (b)) ? (a) : (b))
#else
#endif /* CONFIG_TPL_BUILD */
