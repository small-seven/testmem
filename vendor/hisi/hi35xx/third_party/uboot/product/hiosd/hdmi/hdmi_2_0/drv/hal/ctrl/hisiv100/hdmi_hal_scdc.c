#include "hdmi_hal_scdc.h"
#include "boot_hdmi_intf.h"
#include "hdmi_osal.h"
#include "hdmi_product_define.h"
#include "hdmi_hal_phy.h"
#include "hdmi_hal_ddc.h"
#include "hdmi_hal_intf.h"
#include "hdmi_reg_tx.h"
#define SCDC_OE_SCRAMBLE_INTERVAL 5
typedef struct {
    hi_bool src_scramble;
    hi_bool sink_scramble;
    hi_bool tmds_clk_ratio40x;
} scdc_scramble;
#ifndef HDMI_FPGA_SUPPORT
#endif
#ifndef HDMI_FPGA_SUPPORT
#endif
