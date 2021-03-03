#include <common.h>
#include <net.h>
#include <config.h>
#include <dm.h>
#include <console.h>
#include <malloc.h>
#include <asm/io.h>
#include <phy.h>
#include <miiphy.h>
#include <fdtdec.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <asm/io.h>
#define ENET_ADDR_LENGTH	6
#define ETH_FCS_LEN		4 /* Octets in the FCS */
#define XEL_TSR_XMIT_BUSY_MASK		0x00000001UL
#define XEL_TSR_XMIT_IE_MASK		0x00000008UL
#define XEL_TSR_PROGRAM_MASK		0x00000002UL
#define XEL_TSR_PROG_MAC_ADDR	(XEL_TSR_XMIT_BUSY_MASK | XEL_TSR_PROGRAM_MASK)
#define XEL_TPLR_LENGTH_MASK_HI		0x0000FF00UL
#define XEL_TPLR_LENGTH_MASK_LO		0x000000FFUL
#define XEL_RSR_RECV_DONE_MASK		0x00000001UL
#define XEL_RSR_RECV_IE_MASK		0x00000008UL
#define XEL_MDIOADDR_REGADR_MASK  0x0000001F	/* Register Address */
#define XEL_MDIOADDR_PHYADR_MASK  0x000003E0	/* PHY Address */
#define XEL_MDIOADDR_PHYADR_SHIFT 5
#define XEL_MDIOADDR_OP_MASK	  0x00000400	/* RD/WR Operation */
#define XEL_MDIOWR_WRDATA_MASK	  0x0000FFFF	/* Data to be Written */
#define XEL_MDIORD_RDDATA_MASK	  0x0000FFFF	/* Data to be Read */
#define XEL_MDIOCTRL_MDIOSTS_MASK 0x00000001	/* MDIO Status Mask */
#define XEL_MDIOCTRL_MDIOEN_MASK  0x00000008	/* MDIO Enable */
#define PHY_DETECT_REG  1
#define PHY_DETECT_MASK 0x1808
static int emaclite_remove(struct udevice *dev)
{
	struct xemaclite *emaclite = dev_get_priv(dev);

	free(emaclite->phydev);
	mdio_unregister(emaclite->bus);
	mdio_free(emaclite->bus);

	return 0;
}
