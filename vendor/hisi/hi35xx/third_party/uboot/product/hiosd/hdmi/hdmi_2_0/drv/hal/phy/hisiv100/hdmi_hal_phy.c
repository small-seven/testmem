#include "hdmi_hal_phy.h"
#include "hdmi_reg_dphy.h"
#include "hdmi_product_define.h"
#include "hdmi_reg_tx.h"
#include "hdmi_hal_intf.h"
#define PHY_LOOP_DIV_CFG_25   0x640000 /* 25 x 4 = 100 = 0x64 */
#define PHY_LOOP_DIV_CFG_22   0x5a0000 /* 22 x 4 = 90  = 0x5a */
#define PHY_FEEDTHRU_EN_MASK  (0x1 << 2)
#define PHY_HWSPEC_I_16       16
#define PHY_HWSPEC_I_28       28
#define PHY_HWSPEC_I_32       32
#define PHY_HWSPEC_I_MAX      43
#define PHY_RATIO_1_10_MASK   0x1f
#define PHY_RATIO_1_40_MASK   0xfffff
#define PHY_TXPLL_TEST_OFF    0
#define PHY_TXPLL_TEST_ON     0x30000
#define PHY_POWER_ON_MASK_CLK 0xe
#define PHY_POWER_ON_MASK_D0  0xd
#define PHY_POWER_ON_MASK_D1  0xb
#define PHY_POWER_ON_MASK_D2  0x7
#define PHY_POWER_OFF         0xf
#define PHY_POWER_ON          0
#define PHY_POWER_LDO_OFF     0x3
#define PHY_OE_OFF            0xf
#define PHY_OE_ON             0
#define PHY_I_CHARGE_PUMP     0x3
#define PHY_PLL_LOOP_DEVIDER  0x20
#define PHY_HWSPEC_I_MASK_4   0x4
#define PHY_HWSPEC_I_MASK_16  0x10
#define PHY_HWSPEC_I_MASK_20  0x14
#define PHY_ADDR_OFFSET       11
#define PHY_FIFO_MASK_OFFSET  10
#define HDMI_HUNDRED          100
#define HDMI_THOUSAND         1000
#define HDMI_HW_PARAM_NUM     4
typedef enum {
    PHY_CLK_RATIO_1_10,
    PHY_CLK_RATIO_1_40
} phy_clk_ratio;
typedef enum {
    INTERPOLATION_MODE_1X,
    INTERPOLATION_MODE_2X,
    INTERPOLATION_MODE_4X,
    INTERPOLATION_MODE_8X,
    INTERPOLATION_MODE_BUTT
} phy_div_mode;
typedef struct {
    phy_rterm_mode term_mode;
    hi_u32         mode_data_clk;
    hi_u32         mode_data_d0;
    hi_u32         mode_data_d1;
    hi_u32         mode_data_d2;
} phy_rterm_mode_data;
typedef struct {
    hi_u32  phy_gc_ldo_pd;
    hi_u32  phy_gc_de_pd;
    hi_bool phy_gc_bist_pd;
    hi_bool phy_gc_txpll_pd;
    hi_bool phy_gc_rxsense_pd;
} phy_power_cfg;
typedef struct {
    hi_u32 clk_min;
    hi_u32 clk_max;
} phy_clk_range;
typedef struct {
    phy_clk_range   phy_tmds_clk_range;
    phy_hw_spec_cfg phy_spec_cfg;
} phy_hwspec;
typedef struct {
    phy_clk_range phy_tmds_clk_range;
    phy_ssc_cfg   ssc_cfg;
} phy_ssc;
typedef struct {
    phy_clk_range   pix_clk_range;
    hdmi_deep_color deep_color;
    hi_u32          pixel_clk_div;
    /* CRG */
    hi_u32          ssc_byp_div;
    hi_u32          tmds_nxdiv;
    /* PHY */
    hi_u32          loop_div;
    phy_clk_ratio   clk_ratio;
    phy_div_mode    phy_div_mode;
} phy_div_cfg;
typedef struct {
    phy_clk_range range;
    phy_hwspec_enhance_cfg cfg;
} phy_hwspec_enhance;
#if defined(CHIP_TYPE_hi3531dv200) || defined(CHIP_TYPE_hi3535av100)
#elif defined(CHIP_TYPE_hi3521dv200)
#endif
#ifndef HDMI_FPGA_SUPPORT
#if defined(CHIP_TYPE_hi3531dv100)
#elif defined(CHIP_TYPE_hi3531dv200)
#elif defined(CHIP_TYPE_hi3535av100)
#elif defined(CHIP_TYPE_hi3521dv200)
#elif (defined(CHIP_TYPE_hi3521dv100)) || (defined(CHIP_TYPE_hi3536cv100))
#elif defined(CHIP_TYPE_hi3536dv100)
#elif defined(CHIP_TYPE_hi3516cv500)
#ifndef PHY_SPEC_DEBUG
#endif
#else
#endif
#if defined(CHIP_TYPE_hi3531dv200) || defined(CHIP_TYPE_hi3535av100)
#elif defined(CHIP_TYPE_hi3521dv200)
#else
#endif
#endif
#ifndef PHY_SPEC_DEBUG
#if defined(CHIP_TYPE_hi3536dv100)
#else
#endif
#ifndef PHY_SPEC_DEBUG
#ifndef PHY_CRAFT_S28
#else
#endif
#endif
#ifndef PHY_SPEC_DEBUG
#endif
#ifndef PHY_CRAFT_S28
#else
#endif
#endif
#ifdef PHY_CRAFT_S28
#endif
#ifndef HDMI_FPGA_SUPPORT
#ifdef PHY_CRAFT_S28
#endif
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifdef PHY_CRAFT_S28
#endif
#ifndef HDMI_FPGA_SUPPORT
#ifndef PHY_SPEC_DEBUG
#ifdef PHY_CRAFT_S28
#else
#endif
#else
#endif
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifdef PHY_CRAFT_S28
#endif
