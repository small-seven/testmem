#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <netdev.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <asm/types.h>
#include <fsl_dtsec.h>
#include <asm/arch/soc.h>
#include <asm/arch-fsl-layerscape/config.h>
#include <asm/arch-fsl-layerscape/immap_lsch2.h>
#include <asm/arch/fsl_serdes.h>
#include <net/pfe_eth/pfe_eth.h>
#include <dm/platform_data/pfe_dm_eth.h>
#define DEFAULT_PFE_MDIO_NAME "PFE_MDIO"
#define DEFAULT_PFE_MDIO1_NAME "PFE_MDIO1"
#define MASK_ETH_PHY_RST	0x00000100
