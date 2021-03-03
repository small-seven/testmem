#define pr_fmt(fmt) "tegra-pcie: " fmt
#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <pci.h>
#include <pci_tegra.h>
#include <power-domain.h>
#include <reset.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/ioport.h>
#include <linux/list.h>
#ifndef CONFIG_TEGRA186
#include <asm/arch/clock.h>
#include <asm/arch/powergate.h>
#include <asm/arch-tegra/xusb-padctl.h>
#include <dt-bindings/pinctrl/pinctrl-tegra-xusb.h>
#endif
#define AFI_AXI_BAR0_SZ	0x00
#define AFI_AXI_BAR1_SZ	0x04
#define AFI_AXI_BAR2_SZ	0x08
#define AFI_AXI_BAR3_SZ	0x0c
#define AFI_AXI_BAR4_SZ	0x10
#define AFI_AXI_BAR5_SZ	0x14
#define AFI_AXI_BAR0_START	0x18
#define AFI_AXI_BAR1_START	0x1c
#define AFI_AXI_BAR2_START	0x20
#define AFI_AXI_BAR3_START	0x24
#define AFI_AXI_BAR4_START	0x28
#define AFI_AXI_BAR5_START	0x2c
#define AFI_FPCI_BAR0	0x30
#define AFI_FPCI_BAR1	0x34
#define AFI_FPCI_BAR2	0x38
#define AFI_FPCI_BAR3	0x3c
#define AFI_FPCI_BAR4	0x40
#define AFI_FPCI_BAR5	0x44
#define AFI_CACHE_BAR0_SZ	0x48
#define AFI_CACHE_BAR0_ST	0x4c
#define AFI_CACHE_BAR1_SZ	0x50
#define AFI_CACHE_BAR1_ST	0x54
#define AFI_MSI_BAR_SZ		0x60
#define AFI_MSI_FPCI_BAR_ST	0x64
#define AFI_MSI_AXI_BAR_ST	0x68
#define AFI_CONFIGURATION		0xac
#define  AFI_CONFIGURATION_EN_FPCI	(1 << 0)
#define AFI_FPCI_ERROR_MASKS	0xb0
#define AFI_INTR_MASK		0xb4
#define  AFI_INTR_MASK_INT_MASK	(1 << 0)
#define  AFI_INTR_MASK_MSI_MASK	(1 << 8)
#define AFI_SM_INTR_ENABLE	0xc4
#define  AFI_SM_INTR_INTA_ASSERT	(1 << 0)
#define  AFI_SM_INTR_INTB_ASSERT	(1 << 1)
#define  AFI_SM_INTR_INTC_ASSERT	(1 << 2)
#define  AFI_SM_INTR_INTD_ASSERT	(1 << 3)
#define  AFI_SM_INTR_INTA_DEASSERT	(1 << 4)
#define  AFI_SM_INTR_INTB_DEASSERT	(1 << 5)
#define  AFI_SM_INTR_INTC_DEASSERT	(1 << 6)
#define  AFI_SM_INTR_INTD_DEASSERT	(1 << 7)
#define AFI_AFI_INTR_ENABLE		0xc8
#define  AFI_INTR_EN_INI_SLVERR		(1 << 0)
#define  AFI_INTR_EN_INI_DECERR		(1 << 1)
#define  AFI_INTR_EN_TGT_SLVERR		(1 << 2)
#define  AFI_INTR_EN_TGT_DECERR		(1 << 3)
#define  AFI_INTR_EN_TGT_WRERR		(1 << 4)
#define  AFI_INTR_EN_DFPCI_DECERR	(1 << 5)
#define  AFI_INTR_EN_AXI_DECERR		(1 << 6)
#define  AFI_INTR_EN_FPCI_TIMEOUT	(1 << 7)
#define  AFI_INTR_EN_PRSNT_SENSE	(1 << 8)
#define AFI_PCIE_CONFIG					0x0f8
#define  AFI_PCIE_CONFIG_PCIE_DISABLE(x)		(1 << ((x) + 1))
#define  AFI_PCIE_CONFIG_PCIE_DISABLE_ALL		0xe
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_MASK	(0xf << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_SINGLE	(0x0 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_420	(0x0 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_X2_X1	(0x0 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_DUAL	(0x1 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_222	(0x1 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_X4_X1	(0x1 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_411	(0x2 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_T186_401	(0x0 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_T186_211	(0x1 << 20)
#define  AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_T186_111	(0x2 << 20)
#define AFI_FUSE			0x104
#define  AFI_FUSE_PCIE_T0_GEN2_DIS	(1 << 2)
#define AFI_PEX0_CTRL			0x110
#define AFI_PEX1_CTRL			0x118
#define AFI_PEX2_CTRL			0x128
#define AFI_PEX2_CTRL_T186		0x19c
#define  AFI_PEX_CTRL_RST		(1 << 0)
#define  AFI_PEX_CTRL_CLKREQ_EN		(1 << 1)
#define  AFI_PEX_CTRL_REFCLK_EN		(1 << 3)
#define  AFI_PEX_CTRL_OVERRIDE_EN	(1 << 4)
#define AFI_PLLE_CONTROL		0x160
#define  AFI_PLLE_CONTROL_BYPASS_PADS2PLLE_CONTROL (1 << 9)
#define  AFI_PLLE_CONTROL_PADS2PLLE_CONTROL_EN (1 << 1)
#define AFI_PEXBIAS_CTRL_0		0x168
#define PADS_CTL_SEL		0x0000009C
#define PADS_CTL		0x000000A0
#define  PADS_CTL_IDDQ_1L	(1 <<  0)
#define  PADS_CTL_TX_DATA_EN_1L	(1 <<  6)
#define  PADS_CTL_RX_DATA_EN_1L	(1 << 10)
#define PADS_PLL_CTL_TEGRA20			0x000000B8
#define PADS_PLL_CTL_TEGRA30			0x000000B4
#define  PADS_PLL_CTL_RST_B4SM			(0x1 <<  1)
#define  PADS_PLL_CTL_LOCKDET			(0x1 <<  8)
#define  PADS_PLL_CTL_REFCLK_MASK		(0x3 << 16)
#define  PADS_PLL_CTL_REFCLK_INTERNAL_CML	(0x0 << 16)
#define  PADS_PLL_CTL_REFCLK_INTERNAL_CMOS	(0x1 << 16)
#define  PADS_PLL_CTL_REFCLK_EXTERNAL		(0x2 << 16)
#define  PADS_PLL_CTL_TXCLKREF_MASK		(0x1 << 20)
#define  PADS_PLL_CTL_TXCLKREF_DIV10		(0x0 << 20)
#define  PADS_PLL_CTL_TXCLKREF_DIV5		(0x1 << 20)
#define  PADS_PLL_CTL_TXCLKREF_BUF_EN		(0x1 << 22)
#define PADS_REFCLK_CFG0			0x000000C8
#define PADS_REFCLK_CFG1			0x000000CC
#define PADS_REFCLK_CFG_TERM_SHIFT		2  /* 6:2 */
#define PADS_REFCLK_CFG_E_TERM_SHIFT		7
#define PADS_REFCLK_CFG_PREDI_SHIFT		8  /* 11:8 */
#define PADS_REFCLK_CFG_DRVI_SHIFT		12 /* 15:12 */
#define RP_VEND_XP	0x00000F00
#define  RP_VEND_XP_DL_UP	(1 << 30)
#define RP_VEND_CTL2				0x00000FA8
#define  RP_VEND_CTL2_PCA_ENABLE		(1 << 7)
#define RP_PRIV_MISC	0x00000FE0
#define  RP_PRIV_MISC_PRSNT_MAP_EP_PRSNT (0xE << 0)
#define  RP_PRIV_MISC_PRSNT_MAP_EP_ABSNT (0xF << 0)
#define RP_LINK_CONTROL_STATUS			0x00000090
#define  RP_LINK_CONTROL_STATUS_DL_LINK_ACTIVE	0x20000000
#define  RP_LINK_CONTROL_STATUS_LINKSTAT_MASK	0x3fff0000
#ifdef CONFIG_TEGRA186
#else
#endif
#ifndef CONFIG_TEGRA186
#endif
#ifdef CONFIG_TEGRA20
#endif
#ifdef CONFIG_TEGRA20
#endif
#ifndef CONFIG_TEGRA186
#endif
#ifdef CONFIG_TEGRA186
#else
#endif
#ifdef CONFIG_TEGRA186
#else
#endif
#ifndef CONFIG_TEGRA186
#endif
#ifdef CONFIG_TEGRA186
#else
#endif
static void tegra_pcie_port_free(struct tegra_pcie_port *port)
{
	list_del(&port->list);
	free(port);
}
#ifdef CONFIG_TEGRA186
#endif
