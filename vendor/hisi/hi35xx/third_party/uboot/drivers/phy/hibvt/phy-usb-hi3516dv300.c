#include <asm/arch-hi3516dv300/platform.h>
#include <dm.h>
#include <usb.h>
#include <usb/xhci.h>
#include "phy-hisi-usb.h"
#define USB2_UTMI_PCTRL			(0x1 << 15)
#define USB2_PHY_TEST_SRST_REQ	(0x1 << 14)
#define USB2_UTMI_CKSEL			(0x1 << 13)
#define USB2_UTMI_CKEN			(0x1 << 12)
#define USB2_REF_CKEN			(0x1 << 9)
#define USB2_BUS_CKEN			(0x1 << 8)
#define USB2_VCC_SRST_REQ		(0x1 << 3)
#define USB2_PHY_CKEN			(0x1 << 2)
#define USB2_PHY_PORT_TREQ		(0x1 << 1)
#define USB2_PHY_REQ			(0x1 << 0)
#define REG_GUSB3PIPECTL0		0xc2c0
#define PCS_SSP_SOFT_RESET		(0x1 << 31)
#define PORT_DISABLE_SUSPEND	(0x1 << 17)
#define REG_GCTL				0xc110
#define PORT_CAP_DIR			(0x3 << 12)
#define PORT_SET_HOST			(0x1 << 12)
#define GTXTHRCFG				0xc108
#define	USB2_G_TXTHRCFG			0x23100000
#define GRXTHRCFG				0xc10c
#define	USB2_G_RXTHRCFG			0x23100000
#define USB2_INNO_PHY_BASE_REG	0x10110000
#define	USB2_PHY_CLK_OUTPUT_REG	0x18
#define	USB2_PHY_CLK_OUTPUT_VAL	0x0c
#define	USB2_VBUS_IO_BASE_REG	0x10ff0000
#define	USB2_VBUS_IO_OFFSET		0x40
#define	USB2_VBUS_IO_VAL		0x431
#define	HS_HIGH_HEIGHT_TUNING_OFFSET	0x8
#define HS_HIGH_HEIGHT_TUNING_MASK	(0x7 << 4)
#define HS_HIGH_HEIGHT_TUNING_VAL	(0x5 << 4)
#define PRE_EMPHASIS_TUNING_OFFSET	0x0
#define PRE_EMPHASIS_TUNING_MASK	(0x7 << 0)
#define	PRE_EMPHASIS_TUNING_VAL		(0x7 << 0)
#define PRE_EMPHASIS_STRENGTH_OFFSET	0x14
#define PRE_EMPHASIS_STRENGTH_MASK	(0x7 << 2)
#define PRE_EMPHASIS_STRENGTH_VAL	(0x3 << 2)
#define HS_SLEW_RATE_TUNING_OFFSET	0x74
#define HS_SLEW_RATE_TUNING_MASK	(0x7 << 1)
#define HS_SLEW_RATE_TUNING_VAL		(0x7 << 1)
#define DISCONNECT_TRIGGER_OFFSET	0x10
#define DISCONNECT_TRIGGER_MASK		(0xf << 4)
#define DISCONNECT_TRIGGER_VAL		(0xd << 4)
