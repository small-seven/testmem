#include <asm/arch-hi3516ev200/platform.h>
#include <dm.h>
#include <usb.h>
#include <usb/xhci.h>
#include "phy-hisi-usb.h"
#define USB2_CTRL				0x140
#define USB2_CRG_DEFAULT_VAL	0x3b2f
#define USB2_UTMI_CKEN			(0x1 << 12)
#define USB2_PHY_APB_CKEN		(0x1 << 11)
#define USB2_REF_CKEN			(0x1 << 9)
#define USB2_BUS_CKEN			(0x1 << 8)
#define USB2_PHY_PLL_CKEN		(0x1 << 4)
#define USB2_PHY_XTAL_CKEN		(0x1 << 2)
#define USB2_FREECLK_CKSEL		(0x1 << 13)
#define USB2_PHY_APB_RST		(0x1 << 10)
#define USB2_VCC_SRST_REQ		(0x1 << 3)
#define USB2_PHY_REQ			(0x1 << 0)
#define USB2_PHY_PORT_TREQ		(0x1 << 1)
#define GTXTHRCFG				0xc108
#define GRXTHRCFG				0xc10c
#define REG_GCTL				0xc110
#define REG_GUSB3PIPECTL0		0xc2c0
#define PCS_SSP_SOFT_RESET		(0x1 << 31)
#define PORT_CAP_DIR			(0x3 << 12)
#define PORT_SET_HOST			(0x1 << 12)
#define PORT_DISABLE_SUSPEND	(0x1 << 17)
#define USB2_G_TXTHRCFG			0x23100000
#define USB2_G_RXTHRCFG			0x23100000
#define USB2_PHY_BASE_REG		0x100D0000
#define RG_PLL_EN_MASK			0x0003
#define RG_PLL_EN_VAL			0x0003
#define PHY_PLL_OFFSET			0x0014
#define USB_VBUS_IO_CONFIG_REG	0x100c007C
#define USB_VBUS_IO_CONFIG_VAL	0x0531
#define USB_PWREN_CONFIG_REG	0x100c0080
#define USB_PWREN_CONFIG_VAL	0x1
#define HIXVP_PHY_ANA_CFG_0_OFFSET			0x00
#define HIXVP_PHY_PRE_DRIVE_MASK			(0xf << 24)
#define HIXVP_PHY_PRE_DRIVE_VAL				(0x4 << 24)
#define HIXVP_PHY_ANA_CFG_2_OFFSET			0x08
#define HIXVP_PHY_TX_TEST_BIT				(0x1 << 20)
#define HIXVP_PHY_DISCONNECT_REFERENCE_MASK	(0x7 << 16)
#define HIXVP_PHY_DISCONNECT_REFERENCE_VAL	(0x2 << 16)
#define HIXVP_PHY_ANA_CFG_4_OFFSET			0x10
#define HIXVP_PHY_TX_REFERENCE_MASK			(0x7 << 4)
#define HIXVP_PHY_TX_REFERENCE_VAL			(0x5 << 4)
#define HIXVP_PHY_SQUELCH_REFERENCE_MASK	(0x7 << 0)
#define HIXVP_PHY_SQUELCH_REFERENCE_VAL		(0x5 << 0)
#define USB_TRIM_BASE_REG					0x12028004
#define USB_TRIM_VAL_MASK					0x001F
#define USB_TRIM_VAL_MIN					0x0009
#define USB_TRIM_VAL_MAX					0x001D
#define USB2_TRIM_OFFSET					0x0008
#define USB2_TRIM_MASK						0x1f00
#define usb2_trim_val(a)					(((a) << 8) & USB2_TRIM_MASK)
#define USB2_TRIM_DEFAULT_VAL				0x000e
#define USB_SVB_BASE_REG					0x12020158
#define USB_SVB_OFFSET						0x00
#define USB_SVB_MASK						(0x0f << 24)
#define USB_SVB_PREDEV_5_MIN				0x2bc
#define USB_SVB_PREDEV_5_MAX_4_MIN			0x32a
#define USB_SVB_PREDEV_4_MAX_3_MIN			0x398
#define USB_SVB_PREDEV_3_MAX_2_MIN			0x3ca
#define USB_SVB_PREDEV_2_MAX				0x44c
#define USB_SVB_PREDEV_5_PHY_VAL			(0x05 << 24)
#define USB_SVB_PREDEV_4_PHY_VAL			(0x04 << 24)
#define USB_SVB_PREDEV_3_PHY_VAL			(0x03 << 24)
#define USB_SVB_PREDEV_2_PHY_VAL			(0x02 << 24)
