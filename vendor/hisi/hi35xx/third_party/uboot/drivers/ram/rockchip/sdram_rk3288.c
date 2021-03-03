#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <ram.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3288.h>
#include <asm/arch-rockchip/ddr_rk3288.h>
#include <asm/arch-rockchip/grf_rk3288.h>
#include <asm/arch-rockchip/pmu_rk3288.h>
#include <asm/arch-rockchip/sdram.h>
#include <asm/arch-rockchip/sdram_rk3288.h>
#include <linux/err.h>
#include <power/regulator.h>
#include <power/rk8xx_pmic.h>
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#define TEST_PATTEN	0x5aa5f00f
#define DQS_GATE_TRAINING_ERROR_RANK0	(1 << 4)
#define DQS_GATE_TRAINING_ERROR_RANK1	(2 << 4)
#if defined(CONFIG_TPL_BUILD) || \
# ifdef CONFIG_ROCKCHIP_FAST_SPL
# endif
# ifdef CONFIG_ROCKCHIP_FAST_SPL
# endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#ifdef CONFIG_ROCKCHIP_FAST_SPL
#endif
#endif
#endif /* CONFIG_SPL_BUILD */
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if defined(CONFIG_TPL_BUILD) || \
#endif
#if defined(CONFIG_TPL_BUILD) || \
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#else
#endif
#if defined(CONFIG_TPL_BUILD) || \
#endif
#if defined(CONFIG_TPL_BUILD) || \
#endif
