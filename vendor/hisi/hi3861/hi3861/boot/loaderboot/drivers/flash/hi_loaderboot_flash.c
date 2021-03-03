#include "hi_loaderboot_flash.h"
#include <adc_drv.h>
#define HI_FLASH_SUPPORT_REF_VBAT
#define HI_FLASH_VOLTAGE_TH0 280
#define HI_FLASH_VOLTAGE_TH1 310
#define PLL2DBB_192M_MASK    0x3
#define CMU_CLK_SEL_96M      96
#define CMU_CLK_SEL_80M      80
#define CMU_CLK_SEL_48M      48
#ifdef HI_FLASH_SUPPORT_REF_VBAT
typedef struct {
    hi_u8 chip_id[HI_FLASH_CHIP_ID_NUM];
    hi_u8 freq_high : 2;
    hi_u8 freq_midle : 2;
    hi_u8 freq_low : 2;
    hi_u8 voltage : 2;
} flash_vlt_sfc_info;
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#else
#endif
#ifdef HI_BOARD_ASIC
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#endif
#ifdef HI_FLASH_SUPPORT_REF_VBAT
#else
#endif
