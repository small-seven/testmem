#include <common.h>
#include <dm.h>
#include <net.h>
#include <malloc.h>
#include <miiphy.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/types.h>
#include <asm/system.h>
#include <asm/byteorder.h>
#include <asm/arch/cpu.h>
#if defined(CONFIG_KIRKWOOD)
#include <asm/arch/soc.h>
#elif defined(CONFIG_ORION5X)
#include <asm/arch/orion5x.h>
#endif
#include "mvgbe.h"
#ifndef CONFIG_MVGBE_PORTS
# define CONFIG_MVGBE_PORTS {0, 0}
#endif
#define MV_PHY_ADR_REQUEST 0xee
#define MVGBE_SMI_REG (((struct mvgbe_registers *)MVGBE0_BASE)->smi)
#if defined(CONFIG_PHYLIB) || defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#endif
#if (defined(CONFIG_MII) || defined(CONFIG_CMD_MII)) &&  \
#endif
#if (defined(CONFIG_MII) || defined(CONFIG_CMD_MII)) && \
#endif
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_SYS_MII_MODE
#endif
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#endif
#ifndef CONFIG_DM_ETH
#endif
#if defined(CONFIG_PHYLIB) || defined(CONFIG_DM_ETH)
#if defined(CONFIG_DM_ETH)
#else
#endif
#endif /* CONFIG_PHYLIB || CONFIG_DM_ETH */
#if defined(CONFIG_PHYLIB) && !defined(CONFIG_DM_ETH)
#endif
#ifndef CONFIG_DM_ETH
#if defined(MVGBE1_BASE)
#endif
#if defined(CONFIG_PHYLIB)
#elif defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#endif
#ifdef CONFIG_DM_ETH
#endif /* CONFIG_DM_ETH */
