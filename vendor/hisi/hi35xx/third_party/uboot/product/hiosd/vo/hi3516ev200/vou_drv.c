#include "vou_drv.h"
#include "hi_type.h"
#include "vou_reg.h"
#include "vou_def.h"
#include "vou_hal.h"
#include "vou_coef_org.h"
#define VO_DEV_MAX_NUM   1
#define VO_LAYER_MAX_NUM 1
#define VO_SD_VTTH_WATERLINE 100
#define VO_HD_VTTH_WATERLINE 240
#define VO_BACKGROUD_BLACK   0x8080
#define VO_BACKGROUD_GREEN   0x804D3A42
#define VO_BACKGROUD_WHITE   0x3fffffff
#define VO_BACKGROUD_DEFAULT VO_BACKGROUD_WHITE
#define max2(x, y)       ((x) > (y) ? (x) : (y))
#define min2(x, y)       ((x) < (y) ? (x) : (y))
#define clip_min(x, min) (((x) >= (min)) ? (x) : (min))
typedef enum {
    VO_INTMSK_NONE = 0,
    VO_INTMSK_DHD0_VTTHD1 = 0x1,
    VO_INTMSK_DHD0_VTTHD2 = 0x2,
    VO_INTMSK_DHD0_VTTHD3 = 0x4,
    VO_INTMSK_DHD0_UFINT = 0x8,

    VO_INTMSK_DHD1_VTTHD1 = 0x10,
    VO_INTMSK_DHD1_VTTHD2 = 0x20,
    VO_INTMSK_DHD1_VTTHD3 = 0x40,
    VO_INTMSK_DHD1_UFINT = 0x80,

    VO_INTMSK_DSD_VTTHD1 = 0x100,
    VO_INTMSK_DSD_VTTHD2 = 0x200,
    VO_INTMSK_DSD_VTTHD3 = 0x400,
    VO_INTMSK_DSD_UFINT = 0x800,

    VO_INTMSK_B0_ERR = 0x1000,
    VO_INTMSK_B1_ERR = 0x2000,
    VO_INTMSK_B2_ERR = 0x4000,

    VO_INTMSK_WBC_DHDOVER = 0x8000,

    VO_INTREPORT_ALL = 0xffffffff
} vo_int_mask;
typedef struct {
    hi_bool enable;
    hi_u32 bk_grd;
    vo_intf_type intf_type;
    vo_intf_sync out_sync;
    hal_disp_pixel_format pixel_fmt;
} hal_dev_config;
typedef struct {
    hi_u32 bk_grd;
} hal_layer_config;
typedef struct {
    hi_s32 luma;
    hi_s32 cont;
    hi_s32 hue;
    hi_s32 satu;
} hal_csc_value;
typedef struct {
    hi_u32 base_phys;
    hi_void *base_virt;
    hi_u32 hor;
    hi_u32 ver422;
    hi_u32 ver420;
    hi_u32 lut;
    hi_u32 gam;
    hi_u32 acc;
} hal_coef_addr;
