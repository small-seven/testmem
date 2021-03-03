#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dm/device.h>
#include <generic-phy.h>
#include <phy-sun4i-usb.h>
#include <reset.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/cpu.h>
#define REG_ISCR			0x00
#define REG_PHYCTL_A10			0x04
#define REG_PHYBIST			0x08
#define REG_PHYTUNE			0x0c
#define REG_PHYCTL_A33			0x10
#define REG_PHY_OTGCTL			0x20
#define REG_PMU_UNK1			0x10
#define PHY_PLL_BW			0x03
#define PHY_RES45_CAL_EN		0x0c
#define PHY_TX_AMPLITUDE_TUNE		0x20
#define PHY_TX_SLEWRATE_TUNE		0x22
#define PHY_DISCON_TH_SEL		0x2a
#define PHY_SQUELCH_DETECT		0x3c
#define PHYCTL_DATA			BIT(7)
#define OTGCTL_ROUTE_MUSB		BIT(0)
#define PHY_TX_RATE			BIT(4)
#define PHY_TX_MAGNITUDE		BIT(2)
#define PHY_TX_AMPLITUDE_LEN		5
#define PHY_RES45_CAL_DATA		BIT(0)
#define PHY_RES45_CAL_LEN		1
#define PHY_DISCON_TH_LEN		2
#define SUNXI_AHB_ICHR8_EN		BIT(10)
#define SUNXI_AHB_INCR4_BURST_EN	BIT(9)
#define SUNXI_AHB_INCRX_ALIGN_EN	BIT(8)
#define SUNXI_ULPI_BYPASS_EN		BIT(0)
#define PHY_CTL_VBUSVLDEXT		BIT(5)
#define PHY_CTL_SIDDQ			BIT(3)
#define SUNXI_EHCI_HS_FORCE		BIT(20)
#define SUNXI_HSIC_CONNECT_INT		BIT(16)
#define SUNXI_HSIC			BIT(1)
#define MAX_PHYS			4
