#include <common.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <micrel.h>
#include <phy.h>
#define MII_KSZ90xx_PHY_CTL		0x1f
#define MIIM_KSZ90xx_PHYCTL_1000	(1 << 6)
#define MIIM_KSZ90xx_PHYCTL_100		(1 << 5)
#define MIIM_KSZ90xx_PHYCTL_10		(1 << 4)
#define MIIM_KSZ90xx_PHYCTL_DUPLEX	(1 << 3)
#define MII_KSZ9021_EXTENDED_CTRL	0x0b
#define MII_KSZ9021_EXTENDED_DATAW	0x0c
#define MII_KSZ9021_EXTENDED_DATAR	0x0d
#define CTRL1000_PREFER_MASTER		(1 << 10)
#define CTRL1000_CONFIG_MASTER		(1 << 11)
#define CTRL1000_MANUAL_CONFIG		(1 << 12)
#define KSZ9021_PS_TO_REG		120
#define MII_KSZ9031_MMD_ACCES_CTRL	0x0d
#define MII_KSZ9031_MMD_REG_DATA	0x0e
#define KSZ9031_PS_TO_REG		60
#ifdef CONFIG_DM_ETH
#else /* !CONFIG_DM_ETH */
#endif
