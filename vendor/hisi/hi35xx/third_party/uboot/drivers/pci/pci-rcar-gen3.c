#include <common.h>
#include <asm/io.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <pci.h>
#include <wait_bit.h>
#define PCIECAR			0x000010
#define PCIECCTLR		0x000018
#define  CONFIG_SEND_ENABLE	BIT(31)
#define  TYPE0			(0 << 8)
#define  TYPE1			BIT(8)
#define PCIECDR			0x000020
#define PCIEMSR			0x000028
#define PCIEINTXR		0x000400
#define PCIEPHYSR		0x0007f0
#define  PHYRDY			BIT(0)
#define PCIEMSITXR		0x000840
#define PCIETCTLR		0x02000
#define  CFINIT			1
#define PCIETSTR		0x02004
#define  DATA_LINK_ACTIVE	1
#define PCIEERRFR		0x02020
#define  UNSUPPORTED_REQUEST	BIT(4)
#define PCIEMSIFR		0x02044
#define PCIEMSIALR		0x02048
#define  MSIFE			1
#define PCIEMSIAUR		0x0204c
#define PCIEMSIIER		0x02050
#define PCIEPRAR(x)		(0x02080 + ((x) * 0x4))
#define PCIELAR(x)		(0x02200 + ((x) * 0x20))
#define PCIELAMR(x)		(0x02208 + ((x) * 0x20))
#define  LAM_PREFETCH		BIT(3)
#define  LAM_64BIT		BIT(2)
#define  LAR_ENABLE		BIT(1)
#define PCIEPALR(x)		(0x03400 + ((x) * 0x20))
#define PCIEPAUR(x)		(0x03404 + ((x) * 0x20))
#define PCIEPAMR(x)		(0x03408 + ((x) * 0x20))
#define PCIEPTCTLR(x)		(0x0340c + ((x) * 0x20))
#define  PAR_ENABLE		BIT(31)
#define  IO_SPACE		BIT(8)
#define PCICONF(x)		(0x010000 + ((x) * 0x4))
#define PMCAP(x)		(0x010040 + ((x) * 0x4))
#define EXPCAP(x)		(0x010070 + ((x) * 0x4))
#define VCCAP(x)		(0x010100 + ((x) * 0x4))
#define IDSETR1			0x011004
#define TLCTLR			0x011048
#define MACSR			0x011054
#define  SPCHGFIN		BIT(4)
#define  SPCHGFAIL		BIT(6)
#define  SPCHGSUC		BIT(7)
#define  LINK_SPEED		(0xf << 16)
#define  LINK_SPEED_2_5GTS	(1 << 16)
#define  LINK_SPEED_5_0GTS	(2 << 16)
#define MACCTLR			0x011058
#define  SPEED_CHANGE		BIT(24)
#define  SCRAMBLE_DISABLE	BIT(27)
#define MACS2R			0x011078
#define MACCGSPSETR		0x011084
#define  SPCNGRSN		BIT(31)
#define H1_PCIEPHYADRR		0x04000c
#define  WRITE_CMD		BIT(16)
#define  PHY_ACK		BIT(24)
#define  RATE_POS		12
#define  LANE_POS		8
#define  ADR_POS		0
#define H1_PCIEPHYDOUTR		0x040014
#define GEN2_PCIEPHYADDR	0x780
#define GEN2_PCIEPHYDATA	0x784
#define GEN2_PCIEPHYCTRL	0x78c
#define INT_PCI_MSI_NR		32
#define RCONF(x)		(PCICONF(0) + (x))
#define RPMCAP(x)		(PMCAP(0) + (x))
#define REXPCAP(x)		(EXPCAP(0) + (x))
#define RVCCAP(x)		(VCCAP(0) + (x))
#define PCIE_CONF_BUS(b)	(((b) & 0xff) << 24)
#define PCIE_CONF_DEV(d)	(((d) & 0x1f) << 19)
#define PCIE_CONF_FUNC(f)	(((f) & 0x7) << 16)
#define RCAR_PCI_MAX_RESOURCES	4
#define MAX_NR_INBOUND_MAPS	6
#define PCI_EXP_FLAGS		2		/* Capabilities register */
#define PCI_EXP_FLAGS_TYPE	0x00f0		/* Device/Port type */
#define PCI_EXP_TYPE_ROOT_PORT	0x4		/* Root Port */
#define PCI_EXP_LNKCAP		12		/* Link Capabilities */
#define PCI_EXP_LNKCAP_DLLLARC	0x00100000	/* Data Link Layer Link Active Reporting Capable */
#define PCI_EXP_SLTCAP		20		/* Slot Capabilities */
#define PCI_EXP_SLTCAP_PSN	0xfff80000	/* Physical Slot Number */
