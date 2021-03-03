#include <common.h>
#include <command.h>
#include <env.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/fsl_serdes.h>
#include <hwconfig.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <phy.h>
#include <fm_eth.h>
#include <i2c.h>
#include <miiphy.h>
#include <fsl-mc/fsl_mc.h>
#include <fsl-mc/ldpaa_wriop.h>
#include "../common/qixis.h"
#include "ls1088a_qixis.h"
#ifdef CONFIG_FSL_MC_ENET
#define SFP_TX		0
#define EMI_NONE	0xFF
#define EMI1_RGMII1	0
#define EMI1_RGMII2	1
#define EMI1_SLOT1	2
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#if defined(CONFIG_RESET_PHY_R)
#endif /* CONFIG_RESET_PHY_R */
