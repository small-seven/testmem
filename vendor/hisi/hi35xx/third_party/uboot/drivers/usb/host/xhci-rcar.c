#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fdtdec.h>
#include <usb.h>
#include <wait_bit.h>
#include <usb/xhci.h>
#include "xhci-rcar-r8a779x_usb3_v3.h"
#define RCAR_USB3_DL_CTRL	0x250	/* FW Download Control & Status */
#define RCAR_USB3_FW_DATA0	0x258	/* FW Data0 */
#define RCAR_USB3_DL_CTRL_ENABLE	BIT(0)
#define RCAR_USB3_DL_CTRL_FW_SUCCESS	BIT(4)
#define RCAR_USB3_DL_CTRL_FW_SET_DATA0	BIT(8)
