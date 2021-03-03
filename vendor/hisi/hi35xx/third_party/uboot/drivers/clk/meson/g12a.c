#include <common.h>
#include <asm/arch/clock-g12a.h>
#include <asm/io.h>
#include <clk-uclass.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <div64.h>
#include <dt-bindings/clock/g12a-clkc.h>
#include <linux/kernel.h>
#include "clk_meson.h"
#define CLKID_MPEG_SEL				8
#define CLKID_MPEG_DIV				9
#define CLKID_SD_EMMC_A_CLK0_SEL		63
#define CLKID_SD_EMMC_A_CLK0_DIV		64
#define CLKID_SD_EMMC_B_CLK0_SEL		65
#define CLKID_SD_EMMC_B_CLK0_DIV		66
#define CLKID_SD_EMMC_C_CLK0_SEL		67
#define CLKID_SD_EMMC_C_CLK0_DIV		68
#define CLKID_MPLL0_DIV				69
#define CLKID_MPLL1_DIV				70
#define CLKID_MPLL2_DIV				71
#define CLKID_MPLL3_DIV				72
#define CLKID_MPLL_PREDIV			73
#define CLKID_FCLK_DIV2_DIV			75
#define CLKID_FCLK_DIV3_DIV			76
#define CLKID_FCLK_DIV4_DIV			77
#define CLKID_FCLK_DIV5_DIV			78
#define CLKID_FCLK_DIV7_DIV			79
#define CLKID_FCLK_DIV2P5_DIV			100
#define CLKID_FIXED_PLL_DCO			101
#define CLKID_SYS_PLL_DCO			102
#define CLKID_GP0_PLL_DCO			103
#define CLKID_HIFI_PLL_DCO			104
#define CLKID_VPU_0_DIV				111
#define CLKID_VPU_1_DIV				114
#define CLKID_VAPB_0_DIV			118
#define CLKID_VAPB_1_DIV			121
#define CLKID_HDMI_PLL_DCO			125
#define CLKID_HDMI_PLL_OD			126
#define CLKID_HDMI_PLL_OD2			127
#define CLKID_VID_PLL_SEL			130
#define CLKID_VID_PLL_DIV			131
#define CLKID_VCLK_SEL				132
#define CLKID_VCLK2_SEL				133
#define CLKID_VCLK_INPUT			134
#define CLKID_VCLK2_INPUT			135
#define CLKID_VCLK_DIV				136
#define CLKID_VCLK2_DIV				137
#define CLKID_VCLK_DIV2_EN			140
#define CLKID_VCLK_DIV4_EN			141
#define CLKID_VCLK_DIV6_EN			142
#define CLKID_VCLK_DIV12_EN			143
#define CLKID_VCLK2_DIV2_EN			144
#define CLKID_VCLK2_DIV4_EN			145
#define CLKID_VCLK2_DIV6_EN			146
#define CLKID_VCLK2_DIV12_EN			147
#define CLKID_CTS_ENCI_SEL			158
#define CLKID_CTS_ENCP_SEL			159
#define CLKID_CTS_VDAC_SEL			160
#define CLKID_HDMI_TX_SEL			161
#define CLKID_HDMI_SEL				166
#define CLKID_HDMI_DIV				167
#define CLKID_MALI_0_DIV			170
#define CLKID_MALI_1_DIV			173
#define CLKID_XTAL				0x10000000
#define XTAL_RATE 24000000
#define NUM_CLKS 178
