#include <common.h>
#include <dm.h>
#include <pci.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#define PCIE_CONFIG_BAR0		0x10
#define PCIE_LINK_STATUS_REG		0x80
#define PCIE_LINK_STATUS_SPEED_OFF	16
#define PCIE_LINK_STATUS_SPEED_MASK	(0xf << PCIE_LINK_STATUS_SPEED_OFF)
#define PCIE_LINK_STATUS_WIDTH_OFF	20
#define PCIE_LINK_STATUS_WIDTH_MASK	(0xf << PCIE_LINK_STATUS_WIDTH_OFF)
#define RESIZABLE_BAR_CAP		0x250
#define RESIZABLE_BAR_CTL0		0x254
#define RESIZABLE_BAR_CTL1		0x258
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
#define PCIE_LINK_CAPABILITY		0x7C
#define PCIE_LINK_CTL_2			0xA0
#define TARGET_LINK_SPEED_MASK		0xF
#define LINK_SPEED_GEN_1		0x1
#define LINK_SPEED_GEN_2		0x2
#define LINK_SPEED_GEN_3		0x3
#define PCIE_GEN3_RELATED		0x890
#define GEN3_EQU_DISABLE		(1 << 16)
#define GEN3_ZRXDC_NON_COMP		(1 << 0)
#define PCIE_GEN3_EQU_CTRL		0x8A8
#define GEN3_EQU_EVAL_2MS_DISABLE	(1 << 5)
#define PCIE_ROOT_COMPLEX_MODE_MASK	(0xF << 4)
#define PCIE_LINK_UP_TIMEOUT_MS		100
#define PCIE_GLOBAL_CONTROL		0x8000
#define PCIE_APP_LTSSM_EN		(1 << 2)
#define PCIE_DEVICE_TYPE_OFFSET		(4)
#define PCIE_DEVICE_TYPE_MASK		(0xF)
#define PCIE_DEVICE_TYPE_EP		(0x0) /* Endpoint */
#define PCIE_DEVICE_TYPE_LEP		(0x1) /* Legacy endpoint */
#define PCIE_DEVICE_TYPE_RC		(0x4) /* Root complex */
#define PCIE_GLOBAL_STATUS		0x8008
#define PCIE_GLB_STS_RDLH_LINK_UP	(1 << 1)
#define PCIE_GLB_STS_PHY_LINK_UP	(1 << 9)
#define PCIE_ARCACHE_TRC		0x8050
#define PCIE_AWCACHE_TRC		0x8054
#define ARCACHE_SHAREABLE_CACHEABLE	0x3511
#define AWCACHE_SHAREABLE_CACHEABLE	0x5311
#define LINK_SPEED_GEN_1                0x1
#define LINK_SPEED_GEN_2                0x2
#define LINK_SPEED_GEN_3                0x3
#ifdef CONFIG_DM_GPIO
#else
#endif /* CONFIG_DM_GPIO */
