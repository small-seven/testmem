#include <common.h>
#include <asm/io.h>
#include <miiphy.h>
#include <wait_bit.h>
#define CONTROL_IDLE		BIT(31)
#define CONTROL_ENABLE		BIT(30)
#define CONTROL_FAULT		BIT(19)
#define CONTROL_FAULT_ENABLE	BIT(18)
#define CONTROL_DIV_MASK	GENMASK(15, 0)
#define USERACCESS_GO		BIT(31)
#define USERACCESS_WRITE	BIT(30)
#define USERACCESS_ACK		BIT(29)
#define USERACCESS_READ		(0)
#define USERACCESS_PHY_REG_SHIFT	(21)
#define USERACCESS_PHY_ADDR_SHIFT	(16)
#define USERACCESS_DATA		GENMASK(15, 0)
#define CPSW_MDIO_DIV_DEF	0xff
#define PHY_REG_MASK		0x1f
#define PHY_ID_MASK		0x1f
#define CPSW_MDIO_TIMEOUT            100 /* msecs */
void cpsw_mdio_free(struct mii_dev *bus)
{
	struct cpsw_mdio *mdio = bus->priv;
	u32 reg;

	/* disable mdio */
	reg = readl(&mdio->regs->control);
	reg &= ~CONTROL_ENABLE;
	writel(reg, &mdio->regs->control);

	mdio_unregister(bus);
	mdio_free(bus);
	free(mdio);
}
