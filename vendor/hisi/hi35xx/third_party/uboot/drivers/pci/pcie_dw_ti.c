#include <common.h>
#include <dm.h>
#include <pci.h>
#include <generic-phy.h>
#include <power-domain.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#define PCIE_VENDORID_MASK	GENMASK(15, 0)
#define PCIE_DEVICEID_SHIFT	16
#define PCIE_CONFIG_BAR0		0x10
#define PCIE_LINK_STATUS_REG		0x80
#define PCIE_LINK_STATUS_SPEED_OFF	16
#define PCIE_LINK_STATUS_SPEED_MASK	(0xf << PCIE_LINK_STATUS_SPEED_OFF)
#define PCIE_LINK_STATUS_WIDTH_OFF	20
#define PCIE_LINK_STATUS_WIDTH_MASK	(0xf << PCIE_LINK_STATUS_WIDTH_OFF)
#define PCIE_LINK_CAPABILITY		0x7c
#define PCIE_LINK_CTL_2			0xa0
#define TARGET_LINK_SPEED_MASK		0xf
#define LINK_SPEED_GEN_1		0x1
#define LINK_SPEED_GEN_2		0x2
#define LINK_SPEED_GEN_3		0x3
#define PCIE_MISC_CONTROL_1_OFF		0x8bc
#define PCIE_DBI_RO_WR_EN		BIT(0)
#define PLR_OFFSET			0x700
#define PCIE_PORT_DEBUG0		(PLR_OFFSET + 0x28)
#define PORT_LOGIC_LTSSM_STATE_MASK	0x1f
#define PORT_LOGIC_LTSSM_STATE_L0	0x11
#define PCIE_LINK_WIDTH_SPEED_CONTROL	0x80c
#define PORT_LOGIC_SPEED_CHANGE		(0x1 << 17)
#define PCIE_LINK_UP_TIMEOUT_MS		100
#define PCIE_ATU_UNR_REGION_CTRL1	0x00
#define PCIE_ATU_UNR_REGION_CTRL2	0x04
#define PCIE_ATU_UNR_LOWER_BASE		0x08
#define PCIE_ATU_UNR_UPPER_BASE		0x0c
#define PCIE_ATU_UNR_LIMIT		0x10
#define PCIE_ATU_UNR_LOWER_TARGET	0x14
#define PCIE_ATU_UNR_UPPER_TARGET	0x18
#define PCIE_ATU_REGION_INDEX1		(0x1 << 0)
#define PCIE_ATU_REGION_INDEX0		(0x0 << 0)
#define PCIE_ATU_TYPE_MEM		(0x0 << 0)
#define PCIE_ATU_TYPE_IO		(0x2 << 0)
#define PCIE_ATU_TYPE_CFG0		(0x4 << 0)
#define PCIE_ATU_TYPE_CFG1		(0x5 << 0)
#define PCIE_ATU_ENABLE			(0x1 << 31)
#define PCIE_ATU_BAR_MODE_ENABLE	(0x1 << 30)
#define PCIE_ATU_BUS(x)			(((x) & 0xff) << 24)
#define PCIE_ATU_DEV(x)			(((x) & 0x1f) << 19)
#define PCIE_ATU_FUNC(x)		(((x) & 0x7) << 16)
#define PCIE_GET_ATU_OUTB_UNR_REG_OFFSET(region)	((region) << 9)
#define PCIE_CMD_STATUS			0x04
#define LTSSM_EN_VAL			BIT(0)
#define LINK_WAIT_MAX_IATU_RETRIES	5
#define LINK_WAIT_IATU			10000
#define AM654_PCIE_DEV_TYPE_MASK	0x3
#define EP				0x0
#define LEG_EP				0x1
#define RC				0x2
