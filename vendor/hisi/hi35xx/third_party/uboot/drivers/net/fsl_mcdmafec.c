#include <common.h>
#include <env.h>
#include <malloc.h>
#include <command.h>
#include <config.h>
#include <net.h>
#include <miiphy.h>
#include <linux/mii.h>
#undef	ET_DEBUG
#undef	MII_DEBUG
#define DBUF_LENGTH		1520
#define PKT_MAXBUF_SIZE		1518
#define PKT_MINBUF_SIZE		64
#define PKT_MAXBLR_SIZE		1536
#define LAST_PKTBUFSRX		PKTBUFSRX - 1
#define BD_ENET_RX_W_E		(BD_ENET_RX_WRAP | BD_ENET_RX_EMPTY)
#define BD_ENET_TX_RDY_LST	(BD_ENET_TX_READY | BD_ENET_TX_LAST)
#define FIFO_ERRSTAT		(FIFO_STAT_RXW | FIFO_STAT_UF | FIFO_STAT_OF)
#define BD_ENET_RX_ERR	(BD_ENET_RX_LG | BD_ENET_RX_NO | BD_ENET_RX_CR | \
#include <asm/immap.h>
#include <asm/fsl_mcdmafec.h>
#include "MCD_dma.h"
#ifdef CONFIG_SYS_FEC0_IOBASE
#endif
#ifdef CONFIG_SYS_FEC1_IOBASE
#ifdef CONFIG_SYS_DMA_USE_INTSRAM
#else
#endif
#endif
#ifdef ET_DEBUG
#endif
#ifdef MII_DEBUG
#endif
#ifdef MII_DEBUG
#endif
#ifdef ET_DEBUG
#endif
#ifdef ET_DEBUG
#endif
#if defined(CONFIG_CMD_MII) || defined (CONFIG_MII) || \
#else
#ifndef CONFIG_SYS_DISCOVER_PHY
#endif				/* ifndef CONFIG_SYS_DISCOVER_PHY */
#endif				/* CONFIG_CMD_MII || CONFIG_MII */
#ifdef ET_DEBUG
#endif
#ifdef CONFIG_SYS_DMA_USE_INTSRAM
#endif
#ifdef CONFIG_SYS_DMA_USE_INTSRAM
#else
#endif
#ifdef ET_DEBUG
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
