#include <common.h>
#include <dm.h>
#include <pci.h>
#include <asm/io.h>
#define RP_TX_REG0			0x2000
#define RP_TX_CNTRL			0x2004
#define RP_TX_SOP			BIT(0)
#define RP_TX_EOP			BIT(1)
#define RP_RXCPL_STATUS			0x200C
#define RP_RXCPL_SOP			BIT(0)
#define RP_RXCPL_EOP			BIT(1)
#define RP_RXCPL_REG			0x2008
#define P2A_INT_STATUS			0x3060
#define P2A_INT_STS_ALL			0xf
#define P2A_INT_ENABLE			0x3070
#define RP_CAP_OFFSET			0x70
#define TLP_FMTTYPE_CFGRD0		0x04	/* Configuration Read Type 0 */
#define TLP_FMTTYPE_CFGWR0		0x44	/* Configuration Write Type 0 */
#define TLP_FMTTYPE_CFGRD1		0x05	/* Configuration Read Type 1 */
#define TLP_FMTTYPE_CFGWR1		0x45	/* Configuration Write Type 1 */
#define TLP_PAYLOAD_SIZE		0x01
#define TLP_READ_TAG			0x1d
#define TLP_WRITE_TAG			0x10
#define RP_DEVFN			0
#define RP_CFG_ADDR(pcie, reg)						\
#define RP_SECONDARY(pcie)						\
#define TLP_REQ_ID(bus, devfn)		(((bus) << 8) | (devfn))
#define TLP_CFGRD_DW0(pcie, bus)					\
#define TLP_CFGWR_DW0(pcie, bus)					\
#define TLP_CFG_DW1(pcie, tag, be)					\
#define TLP_CFG_DW2(bus, dev, fn, offset)				\
#define TLP_COMP_STATUS(s)		(((s) >> 13) & 7)
#define TLP_BYTE_COUNT(s)		(((s) >> 0) & 0xfff)
#define TLP_HDR_SIZE			3
#define TLP_LOOP			20000
#define DWORD_MASK			3
#define IS_ROOT_PORT(pcie, bdf)				\
#define PCI_EXP_LNKSTA		18	/* Link Status */
#define PCI_EXP_LNKSTA_DLLLA	0x2000	/* Data Link Layer Link Active */
