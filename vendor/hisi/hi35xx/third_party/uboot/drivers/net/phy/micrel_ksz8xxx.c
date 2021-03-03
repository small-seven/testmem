#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <micrel.h>
#include <phy.h>
#define MII_KSZPHY_OMSO		0x16
#define KSZPHY_OMSO_FACTORY_TEST BIT(15)
#define KSZPHY_OMSO_B_CAST_OFF	(1 << 9)
#define MII_KSZ8051_PHY_OMSO			0x16
#define MII_KSZ8051_PHY_OMSO_NAND_TREE_ON	(1 << 5)
#if 0
#endif
