#include <common.h>
#include <env.h>
#include <malloc.h>
#include <command.h>
#include <net.h>
#include <netdev.h>
#include <miiphy.h>
#include <asm/fec.h>
#include <asm/immap.h>
#include <linux/mii.h>
#undef	ET_DEBUG
#undef	MII_DEBUG
#define DBUF_LENGTH		1520
#define TX_BUF_CNT		2
#define PKT_MAXBUF_SIZE		1518
#define PKT_MINBUF_SIZE		64
#define PKT_MAXBLR_SIZE		1520
#define LAST_PKTBUFSRX		PKTBUFSRX - 1
#define BD_ENET_RX_W_E		(BD_ENET_RX_WRAP | BD_ENET_RX_EMPTY)
#define BD_ENET_TX_RDY_LST	(BD_ENET_TX_READY | BD_ENET_TX_LAST)
#ifdef CONFIG_SYS_FEC0_IOBASE
#endif
#ifdef CONFIG_SYS_FEC1_IOBASE
#ifdef CONFIG_SYS_FEC_BUF_USE_SRAM
#else
#endif
#endif
#ifdef CONFIG_MCF5445x
#endif
#ifdef MII_DEBUG
#endif
#ifdef CONFIG_MCF5445x
#endif
#ifdef MII_DEBUG
#endif
#ifndef CONFIG_SYS_FEC_BUF_USE_SRAM
#endif
#ifdef CONFIG_SYS_UNIFY_CACHE
#endif
#ifdef ET_DEBUG
#endif
#ifndef CONFIG_SYS_FEC_BUF_USE_SRAM
#endif
#ifdef CONFIG_SYS_UNIFY_CACHE
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
#ifdef CONFIG_SYS_FEC1_IOBASE
#endif
#ifdef CONFIG_SYS_FEC0_IOBASE
#endif
#ifdef CONFIG_SYS_FEC1_IOBASE
#endif
#ifdef CONFIG_SYS_FEC_BUF_USE_SRAM
#endif
#ifdef CONFIG_SYS_FEC_BUF_USE_SRAM
#else
#endif
#ifdef ET_DEBUG
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
