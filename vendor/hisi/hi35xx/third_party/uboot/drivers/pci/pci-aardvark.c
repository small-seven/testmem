#include <common.h>
#include <dm.h>
#include <pci.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#include <linux/ioport.h>
#define PCIE_CORE_CMD_STATUS_REG				0x4
#define     PCIE_CORE_CMD_IO_ACCESS_EN				BIT(0)
#define     PCIE_CORE_CMD_MEM_ACCESS_EN				BIT(1)
#define     PCIE_CORE_CMD_MEM_IO_REQ_EN				BIT(2)
#define PCIE_CORE_DEV_CTRL_STATS_REG				0xc8
#define     PCIE_CORE_DEV_CTRL_STATS_RELAX_ORDER_DISABLE	(0 << 4)
#define     PCIE_CORE_DEV_CTRL_STATS_SNOOP_DISABLE		(0 << 11)
#define PCIE_CORE_LINK_CTRL_STAT_REG				0xd0
#define     PCIE_CORE_LINK_TRAINING				BIT(5)
#define PCIE_CORE_ERR_CAPCTL_REG				0x118
#define     PCIE_CORE_ERR_CAPCTL_ECRC_CHK_TX			BIT(5)
#define     PCIE_CORE_ERR_CAPCTL_ECRC_CHK_TX_EN			BIT(6)
#define     PCIE_CORE_ERR_CAPCTL_ECRC_CHECK			BIT(7)
#define     PCIE_CORE_ERR_CAPCTL_ECRC_CHECK_RCV			BIT(8)
#define PIO_BASE_ADDR				0x4000
#define PIO_CTRL				(PIO_BASE_ADDR + 0x0)
#define   PIO_CTRL_TYPE_MASK			GENMASK(3, 0)
#define   PIO_CTRL_ADDR_WIN_DISABLE		BIT(24)
#define PIO_STAT				(PIO_BASE_ADDR + 0x4)
#define   PIO_COMPLETION_STATUS_SHIFT		7
#define   PIO_COMPLETION_STATUS_MASK		GENMASK(9, 7)
#define   PIO_COMPLETION_STATUS_OK		0
#define   PIO_COMPLETION_STATUS_UR		1
#define   PIO_COMPLETION_STATUS_CRS		2
#define   PIO_COMPLETION_STATUS_CA		4
#define   PIO_NON_POSTED_REQ			BIT(10)
#define   PIO_ERR_STATUS			BIT(11)
#define PIO_ADDR_LS				(PIO_BASE_ADDR + 0x8)
#define PIO_ADDR_MS				(PIO_BASE_ADDR + 0xc)
#define PIO_WR_DATA				(PIO_BASE_ADDR + 0x10)
#define PIO_WR_DATA_STRB			(PIO_BASE_ADDR + 0x14)
#define PIO_RD_DATA				(PIO_BASE_ADDR + 0x18)
#define PIO_START				(PIO_BASE_ADDR + 0x1c)
#define PIO_ISR					(PIO_BASE_ADDR + 0x20)
#define CONTROL_BASE_ADDR			0x4800
#define PCIE_CORE_CTRL0_REG			(CONTROL_BASE_ADDR + 0x0)
#define     PCIE_GEN_SEL_MSK			0x3
#define     PCIE_GEN_SEL_SHIFT			0x0
#define     SPEED_GEN_1				0
#define     SPEED_GEN_2				1
#define     SPEED_GEN_3				2
#define     IS_RC_MSK				1
#define     IS_RC_SHIFT				2
#define     LANE_CNT_MSK			0x18
#define     LANE_CNT_SHIFT			0x3
#define     LANE_COUNT_1			(0 << LANE_CNT_SHIFT)
#define     LANE_COUNT_2			(1 << LANE_CNT_SHIFT)
#define     LANE_COUNT_4			(2 << LANE_CNT_SHIFT)
#define     LANE_COUNT_8			(3 << LANE_CNT_SHIFT)
#define     LINK_TRAINING_EN			BIT(6)
#define PCIE_CORE_CTRL2_REG			(CONTROL_BASE_ADDR + 0x8)
#define     PCIE_CORE_CTRL2_RESERVED		0x7
#define     PCIE_CORE_CTRL2_TD_ENABLE		BIT(4)
#define     PCIE_CORE_CTRL2_STRICT_ORDER_ENABLE	BIT(5)
#define     PCIE_CORE_CTRL2_ADDRWIN_MAP_ENABLE	BIT(6)
#define LMI_BASE_ADDR				0x6000
#define CFG_REG					(LMI_BASE_ADDR + 0x0)
#define     LTSSM_SHIFT				24
#define     LTSSM_MASK				0x3f
#define     LTSSM_L0				0x10
#define CTRL_CORE_BASE_ADDR			0x18000
#define CTRL_CONFIG_REG				(CTRL_CORE_BASE_ADDR + 0x0)
#define     CTRL_MODE_SHIFT			0x0
#define     CTRL_MODE_MASK			0x1
#define     PCIE_CORE_MODE_DIRECT		0x0
#define     PCIE_CORE_MODE_COMMAND		0x1
#define PCIE_CONFIG_RD_TYPE0			0x8
#define PCIE_CONFIG_RD_TYPE1			0x9
#define PCIE_CONFIG_WR_TYPE0			0xa
#define PCIE_CONFIG_WR_TYPE1			0xb
#define PCIE_BDF(dev)				(dev << 4)
#define PCIE_CONF_BUS(bus)			(((bus) & 0xff) << 20)
#define PCIE_CONF_DEV(dev)			(((dev) & 0x1f) << 15)
#define PCIE_CONF_FUNC(fun)			(((fun) & 0x7)	<< 12)
#define PCIE_CONF_REG(reg)			((reg) & 0xffc)
#define PCIE_CONF_ADDR(bus, devfn, where)	\
#define MAX_RETRIES				10
#define PIO_WAIT_TIMEOUT			100
#define LINK_WAIT_TIMEOUT			100000
#define CFG_RD_UR_VAL			0xFFFFFFFF
#define CFG_RD_CRS_VAL			0xFFFF0001
#ifdef CONFIG_DM_GPIO
#else
#endif /* CONFIG_DM_GPIO */
