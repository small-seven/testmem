#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dt-structs.h>
#include <ram.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3399.h>
#include <asm/arch-rockchip/grf_rk3399.h>
#include <asm/arch-rockchip/pmu_rk3399.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/sdram.h>
#include <asm/arch-rockchip/sdram_rk3399.h>
#include <linux/err.h>
#include <time.h>
#define PRESET_SGRF_HOLD(n)	((0x1 << (6 + 16)) | ((n) << 6))
#define PRESET_GPIO0_HOLD(n)	((0x1 << (7 + 16)) | ((n) << 7))
#define PRESET_GPIO1_HOLD(n)	((0x1 << (8 + 16)) | ((n) << 8))
#define PHY_DRV_ODT_HI_Z	0x0
#define PHY_DRV_ODT_240		0x1
#define PHY_DRV_ODT_120		0x8
#define PHY_DRV_ODT_80		0x9
#define PHY_DRV_ODT_60		0xc
#define PHY_DRV_ODT_48		0xd
#define PHY_DRV_ODT_40		0xe
#define PHY_DRV_ODT_34_3	0xf
#define PHY_BOOSTP_EN		0x1
#define PHY_BOOSTN_EN		0x1
#define PHY_SLEWP_EN		0x1
#define PHY_SLEWN_EN		0x1
#define PHY_RX_CM_INPUT		0x1
#define CS0_MR22_VAL		0
#define CS1_MR22_VAL		3
#define LPDDR3_DS_34		0x1
#define LPDDR3_DS_40		0x2
#define LPDDR3_DS_48		0x3
#define CRU_SFTRST_DDR_CTRL(ch, n)	((0x1 << (8 + 16 + (ch) * 4)) | \
#define CRU_SFTRST_DDR_PHY(ch, n)	((0x1 << (9 + 16 + (ch) * 4)) | \
#if defined(CONFIG_TPL_BUILD) || \
#endif
#if defined(CONFIG_TPL_BUILD) || \
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#else
#endif
#if !defined(CONFIG_RAM_RK3399_LPDDR4)
#else
#include "sdram-rk3399-lpddr4-400.inc"
#include "sdram-rk3399-lpddr4-800.inc"
#endif /* CONFIG_RAM_RK3399_LPDDR4 */
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if !defined(CONFIG_RAM_RK3399_LPDDR4)
#else
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#else
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#else
#endif
#endif
#if defined(CONFIG_TPL_BUILD) || \
#else
#endif
#if defined(CONFIG_TPL_BUILD) || \
#endif
#if defined(CONFIG_TPL_BUILD) || \
#endif
