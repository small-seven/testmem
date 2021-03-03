#include "hdmi_hal_ctrl.h"
#include "hdmi_reg_tx.h"
#include "hdmi_reg_video_path.h"
#include "hdmi_reg_aon.h"
#include "hdmi_reg_ctrl.h"
#include "hdmi_hal_ddc.h"
#include "hdmi_hal_intf.h"
#include "hdmi_reg_crg.h"
#include "hdmi_product_define.h"
#define CTRL_CHANNEL0_Y          0x0
#define CTRL_CHANNEL0_Y422       0x3
#define CTRL_CHANNEL1_CB         0x1
#define CTRL_CHANNEL1_Y422       0x4
#define CTRL_CHANNEL2_CR         0x2
#define CTRL_CHANNEL2_Y422       0x3
#define CTRL_COLORMETRY_OUT_MASK 0xfc
#define CTRL_COLORMETRY_OUT_BIT  0    /* out colormetry offset in reg_csc_mode */
#define CTRL_COLORMETRY_IN_MASK  0xcf
#define CTRL_COLORMETRY_IN_BIT   0x4  /* in colormetry offset in reg_csc_mode */
#define CTRL_COLORMETRY_MASK     0x3
#define CTRL_RGB_OUT_BIT         0x3  /* out color space offset in reg_csc_mode */
#define CTRL_RGB_IN_BIT          0x7  /* in color space offset in reg_csc_mode */
#define CTRL_QUANTIZAION_OUT_BIT 0x2  /* out quantization offset in reg_csc_mode */
#define CTRL_QUANTIZAION_IN_BIT  0x6  /* in quantization offset in reg_csc_mode */
#define CTRL_SYCN_POL_V_BIT      0    /* vsync offset in reg_inver_sync */
#define CTRL_SYCN_POL_H_BIT      1    /* hsync offset in reg_inver_sync */
#define CTRL_SYCN_POL_DE_BIT     0x3  /* DE offset in reg_inver_sync */
#define CTRL_DATA_RESET_DELAY    5
typedef struct {
    hi_bool in_rgb;
    hi_bool out_rgb;
    hi_bool csc_enable;
    hi_bool y422_enable;
    hi_bool y420_enable;
    hi_bool dwsm_hori_enable;
    hi_bool dwsm_vert_enable;
} ctrl_colorspace_en;
#if defined(HDMI_PRODUCT_HI3519A)
#endif
#if defined(HDMI_PRODUCT_HI3519A)
#endif
#if defined(HDMI_PRODUCT_HI3519A)
#endif
