#include <clk.h>
#include <common.h>
#include <dm.h>
#include <generic-phy.h>
#include <reset.h>
#include <asm/io.h>
#include <linux/bitops.h>
#define OFS_U2_PHY_AC0			0x800
#define USBPLL_FBDIV_S			16
#define USBPLL_FBDIV_M			GENMASK(22, 16)
#define BG_TRIM_S			8
#define BG_TRIM_M			GENMASK(11, 8)
#define BG_RBSEL_S			6
#define BG_RBSEL_M			GENMASK(7, 6)
#define BG_RASEL_S			4
#define BG_RASEL_M			GENMASK(5, 4)
#define BGR_DIV_S			2
#define BGR_DIV_M			GENMASK(3, 2)
#define CHP_EN				BIT(1)
#define OFS_U2_PHY_AC1			0x804
#define VRT_VREF_SEL_S			28
#define VRT_VREF_SEL_M			GENMASK(30, 28)
#define TERM_VREF_SEL_S			24
#define TERM_VREF_SEL_M			GENMASK(26, 24)
#define USBPLL_RSVD			BIT(4)
#define USBPLL_ACCEN			BIT(3)
#define USBPLL_LF			BIT(2)
#define OFS_U2_PHY_AC2			0x808
#define OFS_U2_PHY_ACR0			0x810
#define HSTX_SRCAL_EN			BIT(23)
#define HSTX_SRCTRL_S			16
#define HSTX_SRCTRL_M			GENMASK(18, 16)
#define OFS_U2_PHY_ACR3			0x81C
#define HSTX_DBIST_S			28
#define HSTX_DBIST_M			GENMASK(31, 28)
#define HSRX_BIAS_EN_SEL_S		20
#define HSRX_BIAS_EN_SEL_M		GENMASK(21, 20)
#define OFS_U2_PHY_DCR0			0x860
#define PHYD_RESERVE_S			8
#define PHYD_RESERVE_M			GENMASK(23, 8)
#define CDR_FILT_S			0
#define CDR_FILT_M			GENMASK(3, 0)
#define OFS_U2_PHY_DTM0			0x868
#define FORCE_USB_CLKEN			BIT(25)
#define OFS_FM_CR0			0xf00
#define FREQDET_EN			BIT(24)
#define CYCLECNT_S			0
#define CYCLECNT_M			GENMASK(23, 0)
#define OFS_FM_MONR0			0xf0c
#define OFS_FM_MONR1			0xf10
#define FRCK_EN				BIT(8)
#define U2_SR_COEF_7628			32
