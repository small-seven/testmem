#include <command.h>
#include <common.h>
#include <asm/arch/ep93xx.h>
#include <asm/io.h>
#include <malloc.h>
#include <miiphy.h>
#include <linux/types.h>
#include "ep93xx_eth.h"
#define GET_PRIV(eth_dev)	((struct ep93xx_priv *)(eth_dev)->priv)
#define GET_REGS(eth_dev)	(GET_PRIV(eth_dev)->regs)
#if defined(EP93XX_MAC_DEBUG)
#else
#define dump_dev(x)
#define dump_rx_descriptor_queue(x)
#define dump_rx_status_queue(x)
#define dump_tx_descriptor_queue(x)
#define dump_tx_status_queue(x)
#endif	/* defined(EP93XX_MAC_DEBUG) */
#if defined(CONFIG_MII)
#endif
#if defined(CONFIG_MII)
#define MII_ADDRESS_MAX			31
#define MII_REGISTER_MAX		31
#if defined(CONFIG_MII_SUPPRESS_PREAMBLE)
#endif	/* defined(CONFIG_MII_SUPPRESS_PREAMBLE) */
#if defined(CONFIG_MII_SUPPRESS_PREAMBLE)
#endif	/* defined(CONFIG_MII_SUPPRESS_PREAMBLE) */
#endif	/* defined(CONFIG_MII) */
