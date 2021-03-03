#include <asm/arch-hi3556av100/platform.h>
#include <dm.h>
#include <usb.h>
#include <usb/xhci.h>
#include "phy-hisi-usb.h"
#define USB2_PHY0_CKEN		(0x1 << 5)
#define USB2_PHY1_CKEN		(0x1 << 4)
#define USB2_PHY0_PORT_TREQ	(0x1 << 3)
#define USB2_PHY1_PORT_TREQ	(0x1 << 2)
#define USB2_PHY0_REQ		(0x1 << 1)
#define USB2_PHY1_REQ		(0x1 << 0)
#define COMBPHY0_REF_CKEN	(0x1 << 8)
#define COMBPHY_SRST_REQ	(0x1 << 0)
#define USB3_PCLK_OCC_SEL	(0x1 << 30)
#define USB3_UTMI_CKSEL		(0x1 << 29)
#define USB3_VCC_SRST_REQ	(0x1 << 16)
#define USB2_UTMI_CKSEL		(0x1 << 13)
#define USB2_VCC_SRST_REQ	(0x1 << 0)
#define USB_PORT0			0x38
#define U3_PORT_DISABLE		(0x1 << 3)
#define GTXTHRCFG			0xc108
#define GRXTHRCFG			0xc10c
#define REG_GCTL			0xc110
#define PORT_CAP_DIR		(0x3 << 12)
#define DEFAULT_HOST_MOD	(0x1 << 12)
#define PERI_USB3_GTXTHRCFG	0x2310000
#define REG_GUSB3PIPECTL0	0xc2c0
#define PCS_SSP_SOFT_RESET	(0x1 << 31)
#define SUSPEND_USB3_SS_PHY	(0x1 << 17)
#define USB3_TX_MARGIN		(0x7 << 3)
#define USB3_TX_MARGIN_VAL	(0x2 << 3)
#define USB2_PHY0				0x24
#define USB2_PHY0_TXVREFTUNE	(0xf << 4)
#define USB2_PHY0_VREF_VAL		(0x5 << 4)
#define USB2_PHY0_TXPRE			(0x3 << 12)
#define USB2_PHY0_PRE_VAL		(0x1 << 12)
#define USB2_PHY1				0x30
#define USB2_PHY1_TXVREFTUNE	(0xf << 4)
#define USB2_PHY1_VREF_VAL		(0x5 << 4)
#define USB2_PHY1_TXPRE			(0x3 << 12)
#define USB2_PHY1_PRE_VAL		(0x1 << 12)
#define USB3_DEF_CRG		0x1f010000
#define USB3_DEF_CFG_MASK	0xffff0000
#define USB2_DEF_CRG		0x00001301
#define USB2_DEF_CFG_MASK	0x0000ffff
#define PCIE_USB3_MASK		(0x3 << 12)
#define get_combphy_mode(p)	(((p) & PCIE_USB3_MASK) >> 12)
#define USB3				0x1
#define PCIE_X1				0x0
