#include <common.h>
#include <command.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/cpm_8xx.h>
#include <asm/io.h>
#include <phy.h>
#include <linux/mii.h>
#if defined(CONFIG_SYS_DISCOVER_PHY) || defined(CONFIG_FEC1_PHY) || defined(CONFIG_FEC2_PHY)
#define WANT_MII
#else
#undef WANT_MII
#endif
#if defined(WANT_MII)
#include <miiphy.h>
#if !(defined(CONFIG_MII) || defined(CONFIG_CMD_MII))
#error "CONFIG_MII has to be defined!"
#endif
#endif
#if defined(CONFIG_RMII) && !defined(WANT_MII)
#error RMII support is unusable without a working PHY.
#endif
#ifdef CONFIG_SYS_DISCOVER_PHY
#endif
#if defined(CONFIG_ETHER_ON_FEC1)
#endif
#if defined(CONFIG_ETHER_ON_FEC2)
#endif
#define DBUF_LENGTH  1520
#define TX_BUF_CNT 2
#define TOUT_LOOP 100
#define PKT_MAXBUF_SIZE		1518
#define PKT_MINBUF_SIZE		64
#define PKT_MAXBLR_SIZE		1520
#ifdef __GNUC__
#else
#error txbuf must be aligned.
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#define	FEC_ECNTRL_PINMUX	0x00000004
#define FEC_ECNTRL_ETHER_EN	0x00000002
#define FEC_ECNTRL_RESET	0x00000001
#define FEC_RCNTRL_BC_REJ	0x00000010
#define FEC_RCNTRL_PROM		0x00000008
#define FEC_RCNTRL_MII_MODE	0x00000004
#define FEC_RCNTRL_DRT		0x00000002
#define FEC_RCNTRL_LOOP		0x00000001
#define FEC_TCNTRL_FDEN		0x00000004
#define FEC_TCNTRL_HBC		0x00000002
#define FEC_TCNTRL_GTS		0x00000001
#define	FEC_RESET_DELAY		50
#if defined(CONFIG_RMII)
#endif
#if defined(CONFIG_MPC885) && defined(WANT_MII)
#endif
#if defined(CONFIG_ETHER_ON_FEC1)
#if defined(CONFIG_MPC885) /* MPC87x/88x have got 2 FECs and different pinout */
#if !defined(CONFIG_RMII)
#else
#if !defined(CONFIG_FEC1_PHY_NORXERR)
#endif
#endif /* !CONFIG_RMII */
#else
#if defined(CONFIG_TARGET_MCR3000)
#endif
#endif
#endif	/* CONFIG_ETHER_ON_FEC1 */
#if defined(CONFIG_ETHER_ON_FEC2)
#if defined(CONFIG_MPC885) /* MPC87x/88x have got 2 FECs and different pinout */
#if !defined(CONFIG_RMII)
#else
#if !defined(CONFIG_FEC2_PHY_NORXERR)
#endif
#endif /* CONFIG_RMII */
#endif /* CONFIG_MPC885 */
#endif /* CONFIG_ETHER_ON_FEC2 */
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#define ea dev->enetaddr
#undef ea
#if defined(CONFIG_CMD_CDP)
#else
#endif
#ifdef CONFIG_SYS_DISCOVER_PHY
#else
#endif
#if defined(CONFIG_MII) && defined(CONFIG_RMII)
#endif
#if defined(CONFIG_MII)
#endif
#if defined(CONFIG_SYS_DISCOVER_PHY) || defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#define mk_mii_read(ADDR, REG)	(0x60020000 | ((ADDR << 23) | \
#define mk_mii_write(ADDR, REG, VAL)	(0x50020000 | ((ADDR << 23) | \
#define FEC_ENET_HBERR	((uint)0x80000000)	/* Heartbeat error */
#define FEC_ENET_BABR	((uint)0x40000000)	/* Babbling receiver */
#define FEC_ENET_BABT	((uint)0x20000000)	/* Babbling transmitter */
#define FEC_ENET_GRA	((uint)0x10000000)	/* Graceful stop complete */
#define FEC_ENET_TXF	((uint)0x08000000)	/* Full frame transmitted */
#define FEC_ENET_TXB	((uint)0x04000000)	/* A buffer was transmitted */
#define FEC_ENET_RXF	((uint)0x02000000)	/* Full frame received */
#define FEC_ENET_RXB	((uint)0x01000000)	/* A buffer was received */
#define FEC_ENET_MII	((uint)0x00800000)	/* MII interrupt */
#define FEC_ENET_EBERR	((uint)0x00400000)	/* SDMA bus error */
#endif
#if defined(CONFIG_SYS_DISCOVER_PHY)
#define MAX_PHY_PASSES 11
#endif	/* CONFIG_SYS_DISCOVER_PHY */
#if (defined(CONFIG_MII) || defined(CONFIG_CMD_MII)) && !defined(CONFIG_BITBANGMII)
#endif
