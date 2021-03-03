#include <common.h>
#include <display.h>
#include <dm.h>
#include <edid.h>
#include <asm/io.h>
#include <dw_hdmi.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <power/regulator.h>
#include <clk.h>
#include <linux/delay.h>
#include <reset.h>
#include <media_bus_format.h>
#include "meson_dw_hdmi.h"
#include "meson_vpu.h"
#define HDMITX_TOP_ADDR_REG	0x0
#define HDMITX_TOP_DATA_REG	0x4
#define HDMITX_TOP_CTRL_REG	0x8
#define HDMITX_TOP_G12A_OFFSET	0x8000
#define HDMITX_DWC_ADDR_REG	0x10
#define HDMITX_DWC_DATA_REG	0x14
#define HDMITX_DWC_CTRL_REG	0x18
#define HHI_MEM_PD_REG0		0x100 /* 0x40 */
#define HHI_HDMI_CLK_CNTL	0x1cc /* 0x73 */
#define HHI_HDMI_PHY_CNTL0	0x3a0 /* 0xe8 */
#define HHI_HDMI_PHY_CNTL1	0x3a4 /* 0xe9 */
#define HHI_HDMI_PHY_CNTL2	0x3a8 /* 0xea */
#define HHI_HDMI_PHY_CNTL3	0x3ac /* 0xeb */
#define HHI_HDMI_PHY_CNTL4	0x3b0 /* 0xec */
#define HHI_HDMI_PHY_CNTL5	0x3b4 /* 0xed */
#if defined DEBUG
#endif
#if defined DEBUG
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
