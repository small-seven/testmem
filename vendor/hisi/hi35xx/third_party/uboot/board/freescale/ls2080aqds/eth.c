#include <common.h>
#include <env.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/fsl_serdes.h>
#include <hwconfig.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <fm_eth.h>
#include <i2c.h>
#include <miiphy.h>
#include <fsl-mc/fsl_mc.h>
#include <fsl-mc/ldpaa_wriop.h>
#include "../common/qixis.h"
#include "ls2080aqds_qixis.h"
#define MC_BOOT_ENV_VAR "mcinitcmd"
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#define EMI_NONE	0xFF
#define EMI1_SLOT1	0
#define EMI1_SLOT2	1
#define EMI1_SLOT3	2
#define EMI1_SLOT4	3
#define EMI1_SLOT5	4
#define EMI1_SLOT6	5
#define EMI2		6
#define SFP_TX		0
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_RESET_PHY_R)
#endif /* CONFIG_RESET_PHY_R */
