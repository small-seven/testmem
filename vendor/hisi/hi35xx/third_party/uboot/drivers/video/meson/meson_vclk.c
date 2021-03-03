#include <edid.h>
#include "meson_vpu.h"
#include <linux/iopoll.h>
#include <linux/math64.h>
#define writel_bits(mask, val, addr) \
#define HHI_VID_PLL_CLK_DIV	0x1a0 /* 0x68 offset in data sheet */
#define VID_PLL_EN		BIT(19)
#define VID_PLL_BYPASS		BIT(18)
#define VID_PLL_PRESET		BIT(15)
#define HHI_VIID_CLK_DIV	0x128 /* 0x4a offset in data sheet */
#define VCLK2_DIV_MASK		0xff
#define VCLK2_DIV_EN		BIT(16)
#define VCLK2_DIV_RESET		BIT(17)
#define CTS_VDAC_SEL_MASK	(0xf << 28)
#define CTS_VDAC_SEL_SHIFT	28
#define HHI_VIID_CLK_CNTL	0x12c /* 0x4b offset in data sheet */
#define VCLK2_EN		BIT(19)
#define VCLK2_SEL_MASK		(0x7 << 16)
#define VCLK2_SEL_SHIFT		16
#define VCLK2_SOFT_RESET	BIT(15)
#define VCLK2_DIV1_EN		BIT(0)
#define HHI_VID_CLK_DIV		0x164 /* 0x59 offset in data sheet */
#define VCLK_DIV_MASK		0xff
#define VCLK_DIV_EN		BIT(16)
#define VCLK_DIV_RESET		BIT(17)
#define CTS_ENCP_SEL_MASK	(0xf << 24)
#define CTS_ENCP_SEL_SHIFT	24
#define CTS_ENCI_SEL_MASK	(0xf << 28)
#define CTS_ENCI_SEL_SHIFT	28
#define HHI_VID_CLK_CNTL	0x17c /* 0x5f offset in data sheet */
#define VCLK_EN			BIT(19)
#define VCLK_SEL_MASK		(0x7 << 16)
#define VCLK_SEL_SHIFT		16
#define VCLK_SOFT_RESET		BIT(15)
#define VCLK_DIV1_EN		BIT(0)
#define VCLK_DIV2_EN		BIT(1)
#define VCLK_DIV4_EN		BIT(2)
#define VCLK_DIV6_EN		BIT(3)
#define VCLK_DIV12_EN		BIT(4)
#define HHI_VID_CLK_CNTL2	0x194 /* 0x65 offset in data sheet */
#define CTS_ENCI_EN		BIT(0)
#define CTS_ENCP_EN		BIT(2)
#define CTS_VDAC_EN		BIT(4)
#define HDMI_TX_PIXEL_EN	BIT(5)
#define HHI_HDMI_CLK_CNTL	0x1cc /* 0x73 offset in data sheet */
#define HDMI_TX_PIXEL_SEL_MASK	(0xf << 16)
#define HDMI_TX_PIXEL_SEL_SHIFT	16
#define CTS_HDMI_SYS_SEL_MASK	(0x7 << 9)
#define CTS_HDMI_SYS_DIV_MASK	(0x7f)
#define CTS_HDMI_SYS_EN		BIT(8)
#define HHI_HDMI_PLL_CNTL	0x320 /* 0xc8 offset in data sheet */
#define HHI_HDMI_PLL_CNTL_EN	BIT(30)
#define HHI_HDMI_PLL_CNTL2	0x324 /* 0xc9 offset in data sheet */
#define HHI_HDMI_PLL_CNTL3	0x328 /* 0xca offset in data sheet */
#define HHI_HDMI_PLL_CNTL4	0x32C /* 0xcb offset in data sheet */
#define HHI_HDMI_PLL_CNTL5	0x330 /* 0xcc offset in data sheet */
#define HHI_HDMI_PLL_CNTL6	0x334 /* 0xcd offset in data sheet */
#define HHI_HDMI_PLL_CNTL7	0x338 /* 0xce offset in data sheet */
#define HDMI_PLL_RESET		BIT(28)
#define HDMI_PLL_RESET_G12A	BIT(29)
#define HDMI_PLL_LOCK		BIT(31)
#define HDMI_PLL_LOCK_G12A	(3 << 30)
#define FREQ_1000_1001(_freq)	DIV_ROUND_CLOSEST(_freq * 1000, 1001)
#define XTAL_FREQ 24000
#define HDMI_FRAC_MAX_GXBB	4096
#define HDMI_FRAC_MAX_GXL	1024
#define HDMI_FRAC_MAX_G12A	131072
