#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <pci.h>
#define	PCNET_DEBUG_LEVEL	0	/* 0=off, 1=init, 2=rx/tx */
#define PCNET_DEBUG1(fmt,args...)	\
#define PCNET_DEBUG2(fmt,args...)	\
#if !defined(CONF_PCNET_79C973) && defined(CONF_PCNET_79C975)
#error "Macro for PCnet chip version is not defined!"
#endif
#define PCNET_LOG_TX_BUFFERS	0
#define PCNET_LOG_RX_BUFFERS	2
#define TX_RING_SIZE		(1 << (PCNET_LOG_TX_BUFFERS))
#define TX_RING_LEN_BITS	((PCNET_LOG_TX_BUFFERS) << 12)
#define RX_RING_SIZE		(1 << (PCNET_LOG_RX_BUFFERS))
#define RX_RING_LEN_BITS	((PCNET_LOG_RX_BUFFERS) << 4)
#define PKT_BUF_SZ		1544
typedef struct pcnet_priv {
	struct pcnet_uncached_priv *uc;
	/* Receive Buffer space */
	unsigned char (*rx_buf)[RX_RING_SIZE][PKT_BUF_SZ + 4];
	int cur_rx;
	int cur_tx;
} pcnet_priv_t;
#define PCNET_RDP		0x10
#define PCNET_RAP		0x12
#define PCNET_RESET		0x14
#define PCNET_BDP		0x16
#ifdef PCNET_HAS_PROM
#endif
#ifdef CONFIG_PCNET_79C973
#endif
#ifdef CONFIG_PCNET_79C975
#endif
#ifdef PCNET_HAS_PROM
#endif /* PCNET_HAS_PROM */
