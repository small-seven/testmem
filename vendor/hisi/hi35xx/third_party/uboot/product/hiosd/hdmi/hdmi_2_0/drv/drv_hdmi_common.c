#include "drv_hdmi_common.h"
#include "drv_hdmi_infoframe.h"
#include "hdmi_product_define.h"
#include "boot_hdmi_intf.h"
#define CHECK_MAX_VALUE(out, in, max)    out = (hi_u32)(((in) > (max)) ? (max) : (in))
