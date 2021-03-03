#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/of_access.h>
#include <pci.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <linux/errno.h>
#include <linux/ioport.h>
#include <linux/mbus.h>
#define SELECT(x, n)			((x >> n) & 1UL)
#define PCIE_DEV_ID_OFF			0x0000
#define PCIE_CMD_OFF			0x0004
#define PCIE_DEV_REV_OFF		0x0008
#define  PCIE_BAR_LO_OFF(n)		(0x0010 + ((n) << 3))
#define  PCIE_BAR_HI_OFF(n)		(0x0014 + ((n) << 3))
#define PCIE_CAPAB_OFF			0x0060
#define PCIE_CTRL_STAT_OFF		0x0068
#define PCIE_HEADER_LOG_4_OFF		0x0128
#define  PCIE_BAR_CTRL_OFF(n)		(0x1804 + (((n) - 1) * 4))
#define  PCIE_WIN04_CTRL_OFF(n)		(0x1820 + ((n) << 4))
#define  PCIE_WIN04_BASE_OFF(n)		(0x1824 + ((n) << 4))
#define  PCIE_WIN04_REMAP_OFF(n)	(0x182c + ((n) << 4))
#define PCIE_WIN5_CTRL_OFF		0x1880
#define PCIE_WIN5_BASE_OFF		0x1884
#define PCIE_WIN5_REMAP_OFF		0x188c
#define PCIE_CONF_ADDR_OFF		0x18f8
#define  PCIE_CONF_ADDR_EN		BIT(31)
#define  PCIE_CONF_REG(r)		((((r) & 0xf00) << 16) | ((r) & 0xfc))
#define  PCIE_CONF_BUS(b)		(((b) & 0xff) << 16)
#define  PCIE_CONF_DEV(d)		(((d) & 0x1f) << 11)
#define  PCIE_CONF_FUNC(f)		(((f) & 0x7) << 8)
#define  PCIE_CONF_ADDR(dev, reg) \
#define PCIE_CONF_DATA_OFF		0x18fc
#define PCIE_MASK_OFF			0x1910
#define  PCIE_MASK_ENABLE_INTS          (0xf << 24)
#define PCIE_CTRL_OFF			0x1a00
#define  PCIE_CTRL_X1_MODE		BIT(0)
#define PCIE_STAT_OFF			0x1a04
#define  PCIE_STAT_BUS                  (0xff << 8)
#define  PCIE_STAT_DEV                  (0x1f << 16)
#define  PCIE_STAT_LINK_DOWN		BIT(0)
#define PCIE_DEBUG_CTRL			0x1a60
#define  PCIE_DEBUG_SOFT_RESET		BIT(20)
#define PCIE_MEM_SIZE	(128 << 20)
#define DT_FLAGS_TO_TYPE(flags)       (((flags) >> 24) & 0x03)
#define    DT_TYPE_IO                 0x1
#define    DT_TYPE_MEM32              0x2
#define DT_CPUADDR_TO_TARGET(cpuaddr) (((cpuaddr) >> 56) & 0xFF)
#define DT_CPUADDR_TO_ATTR(cpuaddr)   (((cpuaddr) >> 48) & 0xFF)
