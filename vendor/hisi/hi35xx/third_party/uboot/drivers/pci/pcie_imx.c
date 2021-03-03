#include <common.h>
#include <init.h>
#include <pci.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/crm_regs.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm.h>
#include <linux/sizes.h>
#include <errno.h>
#include <asm/arch/sys_proto.h>
#define PCI_ACCESS_READ  0
#define PCI_ACCESS_WRITE 1
#ifdef CONFIG_MX6SX
#define MX6_DBI_ADDR	0x08ffc000
#define MX6_IO_ADDR	0x08000000
#define MX6_MEM_ADDR	0x08100000
#define MX6_ROOT_ADDR	0x08f00000
#else
#define MX6_DBI_ADDR	0x01ffc000
#define MX6_IO_ADDR	0x01000000
#define MX6_MEM_ADDR	0x01100000
#define MX6_ROOT_ADDR	0x01f00000
#endif
#define MX6_DBI_SIZE	0x4000
#define MX6_IO_SIZE	0x100000
#define MX6_MEM_SIZE	0xe00000
#define MX6_ROOT_SIZE	0xfc000
#define PL_OFFSET 0x700
#define PCIE_PL_PFLR (PL_OFFSET + 0x08)
#define PCIE_PL_PFLR_LINK_STATE_MASK		(0x3f << 16)
#define PCIE_PL_PFLR_FORCE_LINK			(1 << 15)
#define PCIE_PHY_DEBUG_R0 (PL_OFFSET + 0x28)
#define PCIE_PHY_DEBUG_R1 (PL_OFFSET + 0x2c)
#define PCIE_PHY_DEBUG_R1_LINK_UP		(1 << 4)
#define PCIE_PHY_DEBUG_R1_LINK_IN_TRAINING	(1 << 29)
#define PCIE_PHY_CTRL (PL_OFFSET + 0x114)
#define PCIE_PHY_CTRL_DATA_LOC 0
#define PCIE_PHY_CTRL_CAP_ADR_LOC 16
#define PCIE_PHY_CTRL_CAP_DAT_LOC 17
#define PCIE_PHY_CTRL_WR_LOC 18
#define PCIE_PHY_CTRL_RD_LOC 19
#define PCIE_PHY_STAT (PL_OFFSET + 0x110)
#define PCIE_PHY_STAT_DATA_LOC 0
#define PCIE_PHY_STAT_ACK_LOC 16
#define PCIE_PHY_RX_ASIC_OUT 0x100D
#define PHY_RX_OVRD_IN_LO 0x1005
#define PHY_RX_OVRD_IN_LO_RX_DATA_EN (1 << 5)
#define PHY_RX_OVRD_IN_LO_RX_PLL_EN (1 << 3)
#define PCIE_PHY_PUP_REQ		(1 << 7)
#define PCIE_ATU_VIEWPORT		0x900
#define PCIE_ATU_REGION_INBOUND		(0x1 << 31)
#define PCIE_ATU_REGION_OUTBOUND	(0x0 << 31)
#define PCIE_ATU_REGION_INDEX1		(0x1 << 0)
#define PCIE_ATU_REGION_INDEX0		(0x0 << 0)
#define PCIE_ATU_CR1			0x904
#define PCIE_ATU_TYPE_MEM		(0x0 << 0)
#define PCIE_ATU_TYPE_IO		(0x2 << 0)
#define PCIE_ATU_TYPE_CFG0		(0x4 << 0)
#define PCIE_ATU_TYPE_CFG1		(0x5 << 0)
#define PCIE_ATU_CR2			0x908
#define PCIE_ATU_ENABLE			(0x1 << 31)
#define PCIE_ATU_BAR_MODE_ENABLE	(0x1 << 30)
#define PCIE_ATU_LOWER_BASE		0x90C
#define PCIE_ATU_UPPER_BASE		0x910
#define PCIE_ATU_LIMIT			0x914
#define PCIE_ATU_LOWER_TARGET		0x918
#define PCIE_ATU_BUS(x)			(((x) & 0xff) << 24)
#define PCIE_ATU_DEV(x)			(((x) & 0x1f) << 19)
#define PCIE_ATU_FUNC(x)		(((x) & 0x7) << 16)
#define PCIE_ATU_UPPER_TARGET		0x91C
#if defined(CONFIG_MX6SX)
#else
#endif
#ifdef CONFIG_MX6SX
#endif
#ifdef CONFIG_PCIE_IMX_POWER_GPIO
#endif
#ifdef CONFIG_PCIE_IMX_PERST_GPIO
#else
#endif
#if defined(CONFIG_MX6SX)
#else
#endif
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#if !CONFIG_IS_ENABLED(DM_PCI)
void imx_pcie_remove(void)
{
	imx6_pcie_assert_core_reset(priv, true);
}
#else
static int imx_pcie_dm_remove(struct udevice *dev)
{
	struct imx_pcie_priv *priv = dev_get_priv(dev);

	imx6_pcie_assert_core_reset(priv, true);

	return 0;
}
#endif
