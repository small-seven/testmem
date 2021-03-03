#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <net.h>
#include <hwconfig.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <miiphy.h>
#include <phy.h>
#include <fsl_dtsec.h>
#include <fsl_tgec.h>
#include <fsl_memac.h>
#include "fm.h"
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII) && !defined(BITBANGMII)
#define TBIANA_SETTINGS (TBIANA_ASYMMETRIC_PAUSE | TBIANA_SYMMETRIC_PAUSE | \
#define TBIANA_SGMII_ACK 0x4001
#define TBICR_SETTINGS (TBICR_ANEG_ENABLE | TBICR_RESTART_ANEG | \
#ifdef CONFIG_SYS_FMAN_V3
#else
#endif
#ifndef CONFIG_SYS_FMAN_V3
#endif
#ifdef CONFIG_PHYLIB
#endif
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_PHYLIB
#else
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_SYS_FMAN_V3
#ifndef CONFIG_FSL_FM_10GEC_REGULAR_NOTATION
#endif
#else
#endif
#ifdef CONFIG_SYS_FMAN_V3
#else
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_PHYLIB
#endif
