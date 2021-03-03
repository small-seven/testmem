#include <common.h>
#include <netdev.h>
#include <asm/arch/fsl_serdes.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <malloc.h>
#include "../common/sgmii_riser.h"
#include "../common/qixis.h"
#define EMI1_MASK       0x1f
#define EMI1_RGMII0     1
#define EMI1_RGMII1     2
#define EMI1_RGMII2     3
#define EMI1_SGMII1     0x1c
#define EMI1_SGMII2     0x1d
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC3
#endif
#ifdef CONFIG_FSL_SGMII_RISER
#endif
