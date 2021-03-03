#include "hdmi_hal_phy.h"
#include "hdmi_reg_tx.h"
#include "hdmi_reg_dphy.h"
#include "hdmi_reg_crg.h"
#include "hdmi_reg_ctrl.h"
#include "hdmi_osal.h"
#include "drv_hdmi_common.h"
#include "hdmi_product_define.h"
#define APHY_CS_0              0x1
#define APHY_CS_1              0x2
#define APHY_CS_2              0x4
#define APHY_CS_3              0x8
#define APHY_CS_4              0x10
#define APHY_CS_012            0x7
#define APHY_CS_4567           0xf0
#define APHY_CS_8              0x100
#define APHY_CS_9              0x200
#define PHY_CPIS_VAL           0x07
#define PHY_TMDS_OUTEN         0x14
#define TMDS_CLK_100M          100000
#define TMDS_CLK_165M          165000
#define TMDS_CLK_340M          340000
#define TMDS_CLK_600M          600000
#define HW_FCON_DELAY          2
#define HW_WRITE_STB_DELAY     5
#define PHY_POW_BASE_NUM       2
#define PHY_POW_INDEX_NUM      24
#define TMDS_CLK_FREQ_MUITIPLE 5
#define HDMI_THOUSAND          1000
#define MOD_MULTI_COEFFICIENT  10000
#define LEFT_OR_MASK_OFFSET_5  5
typedef enum {
    APHY_OFFSET_0,
    APHY_OFFSET_1,
    APHY_OFFSET_2,
    APHY_OFFSET_3,
    APHY_OFFSET_4,
    APHY_OFFSET_5,
    APHY_OFFSET_6,
    APHY_OFFSET_7,
    APHY_OFFSET_8,
    APHY_OFFSET_9,
    APHY_OFFSET_A,
    APHY_OFFSET_B,
    APHY_OFFSET_C,
    APHY_OFFSET_D,
    APHY_OFFSET_E,
    APHY_OFFSET_F,
    APHY_OFFSET_BUTT
} aphy_offset_addr;
typedef struct {
    hi_u32 clk_min;
    hi_u32 clk_max;
} phy_clk_range;
typedef struct {
    phy_clk_range  phy_tmds_clk_range;
    phy_hw_spec_cfg phy_spec_cfg;
} phy_hwspec;
typedef struct {
    phy_clk_range phy_tmds_clk_range;
    hi_u8 seek_value;
} phy_clk_rang_value;
typedef struct {
    hi_u32 i_ref_cnt;
    hi_u32 i_ref_cnt_len;
    phy_fcon_mode fcon_mode;
} phy_fcon_para;
typedef struct {
    hi_u8 ref_clk_div;
    hi_u8 vp_divnsel;
    hi_u8 cpzs;
    hi_u8 tmds_divnsel;
    hi_u8 vp_mode;
    hi_u8 fcd_step;
    hdmi_phy_tmds_cfg tmds_cfg;
} phy_clk_set;
typedef struct {
    hi_u8  m_val;
    hi_u8  n_val;
    hi_u32 pll_ref_clk;
    hi_u32 mn_value;
} phy_mnx;
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#if defined(HDMI_PRODUCT_HI3559A)
#elif defined(HDMI_PRODUCT_HI3519A)
#endif
#if defined(HDMI_PRODUCT_HI3559A)
#elif defined(HDMI_PRODUCT_HI3519A)
#endif
#if defined(HDMI_PRODUCT_HI3559A)
#elif defined(HDMI_PRODUCT_HI3519A)
#endif
#if defined(HDMI_PRODUCT_HI3559A)
#elif defined(HDMI_PRODUCT_HI3519A)
#endif
#if defined(HDMI_PRODUCT_HI3559A)
#elif defined(HDMI_PRODUCT_HI3519A)
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
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#if defined(HDMI_PRODUCT_HI3559A)
#else
#endif
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
