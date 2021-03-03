#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <net.h>
#include <miiphy.h>
#include <malloc.h>
#include <linux/compiler.h>
#include <asm/arch/emac_defs.h>
#include <asm/io.h>
#include "davinci_emac.h"
#define debug_emac(fmt,args...)	if (emac_dbg) printf(fmt,##args)
#ifdef EMAC_HW_RAM_ADDR
#else
#define BD_TO_HW(x)	(x)
#define HW_TO_BD(x)	(x)
#endif
#ifdef DAVINCI_EMAC_GIG_ENABLE
#define emac_gigabit_enable(phy_addr)	davinci_eth_gigabit_enable(phy_addr)
#else
#define emac_gigabit_enable(phy_addr)	/* no gigabit to enable */
#endif
#if !defined(CONFIG_SYS_EMAC_TI_CLKDIV)
#define CONFIG_SYS_EMAC_TI_CLKDIV	((EMAC_MDIO_BUS_FREQ / \
#endif
#ifndef CONFIG_SYS_DAVINCI_EMAC_PHY_COUNT
#define CONFIG_SYS_DAVINCI_EMAC_PHY_COUNT	3
#endif
#if defined(DAVINCI_EMAC_VERSION2)
#else
#endif
#if defined(CONFIG_DRIVER_TI_EMAC_USE_RMII) && \
#endif
#ifdef DAVINCI_EMAC_GIG_ENABLE
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#if defined(DAVINCI_EMAC_VERSION2)
#else
#endif
#if defined(CONFIG_DRIVER_TI_EMAC_USE_RMII) && \
#endif
#ifdef DAVINCI_EMAC_GIG_ENABLE
#endif
#if defined(CONFIG_SOC_DA8XX) || \
#endif
#if defined(DAVINCI_EMAC_VERSION2)
#else
#endif
#if defined(CONFIG_DRIVER_TI_EMAC_USE_RMII) && \
#endif
#ifdef DAVINCI_EMAC_GIG_ENABLE
#define PHY_CONF_REG	22
#endif
#if defined(CONFIG_TI816X) || (defined(CONFIG_DRIVER_TI_EMAC_USE_RMII) && \
#endif
