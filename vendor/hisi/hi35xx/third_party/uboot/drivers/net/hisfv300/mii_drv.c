#include "hieth.h"
#include "mdio.h"
#include "mii_drv.h"
#include <config.h>
#define PHY_ID_KSZ8051 0x00221550
#define PHY_ID_KSZ8081 0x00221560
#define PHY_ID_MASK    0xFFFFFFF0
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
