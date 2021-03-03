#include <common.h>
#include <command.h>
#include <netdev.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#include <malloc.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <miiphy.h>
#include <phy.h>
#include <fsl_dtsec.h>
#include <asm/fsl_serdes.h>
#include "../common/fman.h"
#if defined(CONFIG_FMAN_ENET)
#ifdef CONFIG_TARGET_T1024RDB
#endif
#ifdef CONFIG_TARGET_T1023RDB
#endif
#if defined(CONFIG_TARGET_T1023RDB)
#elif defined(CONFIG_TARGET_T1024RDB)
#endif
#endif /* CONFIG_FMAN_ENET */
#if defined(CONFIG_TARGET_T1024RDB)
#endif
