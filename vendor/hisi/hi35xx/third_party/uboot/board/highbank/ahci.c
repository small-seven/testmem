#include <common.h>
#include <ahci.h>
#include <asm/io.h>
#define CPHY_MAP(dev, addr) ((((dev) & 0x1f) << 7) | (((addr) >> 9) & 0x7f))
#define CPHY_ADDR(base, dev, addr) ((base) | (((addr) & 0x1ff) << 2))
#define CPHY_BASE			0xfff58000
#define CPHY_WIDTH			0x1000
#define CPHY_DTE_XS			5
#define CPHY_MII			31
#define SERDES_CR_CTL			0x80a0
#define SERDES_CR_ADDR			0x80a1
#define SERDES_CR_DATA			0x80a2
#define CR_BUSY				0x0001
#define CR_START			0x0001
#define CR_WR_RDN			0x0002
#define CPHY_TX_INPUT_STS		0x2001
#define CPHY_RX_INPUT_STS		0x2002
#define CPHY_SATA_TX_OVERRIDE_BIT	0x8000
#define CPHY_SATA_RX_OVERRIDE_BIT	0x4000
#define CPHY_TX_INPUT_OVERRIDE		0x2004
#define CPHY_RX_INPUT_OVERRIDE		0x2005
#define SPHY_LANE			0x100
#define SPHY_HALF_RATE			0x0001
#define CPHY_SATA_DPLL_MODE		0x0700
#define CPHY_SATA_DPLL_SHIFT		8
#define CPHY_SATA_TX_ATTEN		0x1c00
#define CPHY_SATA_TX_ATTEN_SHIFT	10
#define HB_SREG_SATA_ATTEN		0xfff3cf24
#define SATA_PORT_BASE			0xffe08000
#define SATA_VERSIONR			0xf8
#define SATA_HB_VERSION			0x3332302a
#define WAIT_MS_LINKUP	4
