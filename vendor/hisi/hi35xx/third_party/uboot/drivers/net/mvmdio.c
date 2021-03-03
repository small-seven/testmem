#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <miiphy.h>
#include <phy.h>
#include <asm/io.h>
#include <wait_bit.h>
#define MVMDIO_SMI_DATA_SHIFT		0
#define MVMDIO_SMI_PHY_ADDR_SHIFT	16
#define MVMDIO_SMI_PHY_REG_SHIFT	21
#define MVMDIO_SMI_READ_OPERATION	BIT(26)
#define MVMDIO_SMI_WRITE_OPERATION	0
#define MVMDIO_SMI_READ_VALID		BIT(27)
#define MVMDIO_SMI_BUSY			BIT(28)
#define MVMDIO_XSMI_MGNT_REG		0x0
#define MVMDIO_XSMI_PHYADDR_SHIFT	16
#define MVMDIO_XSMI_DEVADDR_SHIFT	21
#define MVMDIO_XSMI_WRITE_OPERATION	(0x5 << 26)
#define MVMDIO_XSMI_READ_OPERATION	(0x7 << 26)
#define MVMDIO_XSMI_READ_VALID		BIT(29)
#define MVMDIO_XSMI_BUSY		BIT(30)
#define MVMDIO_XSMI_ADDR_REG		0x8
