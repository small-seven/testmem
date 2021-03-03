#include <common.h>
#include <malloc.h>
#include <asm/cpm_85xx.h>
#include <command.h>
#include <config.h>
#include <net.h>
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#include <miiphy.h>
#endif
#if defined(CONFIG_ETHER_ON_FCC) && defined(CONFIG_CMD_NET)
#ifdef CONFIG_ETHER_ON_FCC1
#endif
#ifdef CONFIG_ETHER_ON_FCC2
#endif
#ifdef CONFIG_ETHER_ON_FCC3
#endif
#define PKT_MAXDMA_SIZE         1520
#define PKT_MAXBUF_SIZE         1518
#define PKT_MINBUF_SIZE         64
#define PKT_MAXBLR_SIZE         1536
#define TOUT_LOOP 1000000
#define TX_BUF_CNT 2
typedef volatile struct rtxbd {
    cbd_t rxbd[PKTBUFSRX];
    cbd_t txbd[TX_BUF_CNT];
} RTXBD;
#ifdef __GNUC__
#else
#error "rtx must be 64-bit aligned"
#endif
#undef ET_DEBUG
#ifdef ET_DEBUG
#endif
#if 0
#endif
#define ea eth_get_ethaddr()
#undef ea
#if defined(ET_DEBUG)
#endif
#if (defined(CONFIG_MII) || defined(CONFIG_CMD_MII)) \
#endif
#endif
