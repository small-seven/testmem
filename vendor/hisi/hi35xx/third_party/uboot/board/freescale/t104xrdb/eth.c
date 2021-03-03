#include <common.h>
#include <netdev.h>
#include <asm/fsl_serdes.h>
#include <asm/immap_85xx.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <fsl_dtsec.h>
#include <vsc9953.h>
#include "../common/fman.h"
#ifdef CONFIG_FMAN_ENET
#ifdef CONFIG_VSC9953
#endif
#if defined(CONFIG_TARGET_T1040RDB) || defined(CONFIG_TARGET_T1040D4RDB)
#endif
#ifdef CONFIG_TARGET_T1042RDB
#endif
#ifdef CONFIG_TARGET_T1042D4RDB
#endif
#ifdef CONFIG_VSC9953
#endif
#endif
