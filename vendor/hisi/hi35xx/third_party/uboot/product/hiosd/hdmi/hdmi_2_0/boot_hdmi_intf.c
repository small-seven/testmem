#include "boot_hdmi_intf.h"
#include "drv_hdmi_common.h"
#include "hi_hdmi.h"
#include "hdmi_product_define.h"
#include "hi_common_vo.h"
#define HDMI_MULTIPLE_2P0(x)      ((x) *= 2)
#define HDMI_MULTIPLE_1P5(x)      ((x) = ((x) * 3) >> 1)
#define HDMI_MULTIPLE_1P25(x)     ((x) = ((x) * 5) >> 2)
#define HDMI_MULTIPLE_0P5(x)      ((x) >>= 1)
#define HDMI_MAX_HDMI14_TMDS_RATE 340000
#define HDMI_VIC_VIRTUAL_BASE     255U
#define HDMI_VIC_PC_BASE          ((HDMI_VIC_VIRTUAL_BASE) + 0x100)
#define FMT_VIC_800X600           ((HDMI_VIC_PC_BASE) + 9)
#define FMT_VIC_1024X768          ((HDMI_VIC_PC_BASE) + 13)
#define FMT_VIC_1280X1024         ((HDMI_VIC_PC_BASE) + 25)
#define FMT_VIC_1366X768          ((HDMI_VIC_PC_BASE) + 28)
#define FMT_VIC_1920X1200         ((HDMI_VIC_PC_BASE) + 41)
#define HDMI_INVALID_PIXFREQ      0xffffffff
#define MAX_HDMI_HW_PARAM         43
#define MAX_HDMI_FT_PARAM         4
#define SCRAMBLE_INTERVAL         20
#define SCRAMBLE_TIMEOUT          200
#ifndef HI_PLATFORM_H8
#define FMT_4K_50 VO_OUTPUT_3840X2160_50
#define FMT_4K_60 VO_OUTPUT_3840X2160_60
#else
#define FMT_4K_50 HI_VO_OUT_3840x2160_50
#define FMT_4K_60 HI_VO_OUT_3840x2160_60
#endif
typedef struct {
    hi_u32 vic;
    hi_u32 pixl_freq; /* KHz */
    hi_u32 hor_active;
    hi_u32 ver_active;
    hi_u32 field_rate; /* 0.01Hz */
    hi_u32 format;
} hdmi_fmt_param;
#define hdmi_if_failure_return(ret)                                     \
#define VIDMODE_2_COLORSPACE(vid_mode, color_space)             \
#ifndef HI_PLATFORM_H8
#else
#endif
#ifndef HI_PLATFORM_H8
#else
#endif
#if defined(PHY_CRAFT_S28)
#else
#endif
#ifdef HDMI_SCDC_SUPPORT
#endif
#ifdef HDMI_SCDC_SUPPORT
#endif
#ifdef HDMI_SCDC_SUPPORT
#endif
#ifdef PHY_CRAFT_S28
#endif
#ifdef HI_HDMI_SUPPORT_1_4
#endif
#ifdef PHY_CRAFT_S28
#endif
