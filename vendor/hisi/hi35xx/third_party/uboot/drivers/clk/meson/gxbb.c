#include <common.h>
#include <asm/arch/clock-gx.h>
#include <asm/io.h>
#include <clk-uclass.h>
#include <div64.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <dt-bindings/clock/gxbb-clkc.h>
#include "clk_meson.h"
#define CLKID_MPEG_SEL		  10
#define CLKID_MPEG_DIV		  11
#define CLKID_SAR_ADC_DIV	  99
#define CLKID_MALI_0_DIV	  101
#define CLKID_MALI_1_DIV	  104
#define CLKID_CTS_AMCLK_SEL	  108
#define CLKID_CTS_AMCLK_DIV	  109
#define CLKID_CTS_MCLK_I958_SEL	  111
#define CLKID_CTS_MCLK_I958_DIV	  112
#define CLKID_32K_CLK_SEL	  115
#define CLKID_32K_CLK_DIV	  116
#define CLKID_SD_EMMC_A_CLK0_SEL  117
#define CLKID_SD_EMMC_A_CLK0_DIV  118
#define CLKID_SD_EMMC_B_CLK0_SEL  120
#define CLKID_SD_EMMC_B_CLK0_DIV  121
#define CLKID_SD_EMMC_C_CLK0_SEL  123
#define CLKID_SD_EMMC_C_CLK0_DIV  124
#define CLKID_VPU_0_DIV		  127
#define CLKID_VPU_1_DIV		  130
#define CLKID_VAPB_0_DIV	  134
#define CLKID_VAPB_1_DIV	  137
#define CLKID_HDMI_PLL_PRE_MULT	  141
#define CLKID_MPLL0_DIV		  142
#define CLKID_MPLL1_DIV		  143
#define CLKID_MPLL2_DIV		  144
#define CLKID_MPLL_PREDIV	  145
#define CLKID_FCLK_DIV2_DIV	  146
#define CLKID_FCLK_DIV3_DIV	  147
#define CLKID_FCLK_DIV4_DIV	  148
#define CLKID_FCLK_DIV5_DIV	  149
#define CLKID_FCLK_DIV7_DIV	  150
#define CLKID_VDEC_1_SEL	  151
#define CLKID_VDEC_1_DIV	  152
#define CLKID_VDEC_HEVC_SEL	  154
#define CLKID_VDEC_HEVC_DIV	  155
#define XTAL_RATE 24000000
