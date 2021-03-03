#include <common.h>
#include <clk.h>
#include <dm.h>
#include <linux/err.h>
#include <malloc.h>
#include <miiphy.h>
#include <net.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#define EMAC_TX_AB_M		(0x1 << 0)
#define EMAC_TX_TM		(0x1 << 1)
#define EMAC_TX_SETUP		(0)
#define EMAC_RX_DRQ_MODE	(0x1 << 1)
#define EMAC_RX_TM		(0x1 << 2)
#define EMAC_RX_PA		(0x1 << 4)
#define EMAC_RX_PCF		(0x1 << 5)
#define EMAC_RX_PCRCE		(0x1 << 6)
#define EMAC_RX_PLE		(0x1 << 7)
#define EMAC_RX_POR		(0x1 << 8)
#define EMAC_RX_UCAD		(0x1 << 16)
#define EMAC_RX_DAF		(0x1 << 17)
#define EMAC_RX_MCO		(0x1 << 20)
#define EMAC_RX_MHF		(0x1 << 21)
#define EMAC_RX_BCO		(0x1 << 22)
#define EMAC_RX_SAF		(0x1 << 24)
#define EMAC_RX_SAIF		(0x1 << 25)
#define EMAC_RX_SETUP		(EMAC_RX_POR | EMAC_RX_UCAD | EMAC_RX_DAF | \
#define EMAC_MAC_CTL0_RFC	(0x1 << 2)
#define EMAC_MAC_CTL0_TFC	(0x1 << 3)
#define EMAC_MAC_CTL0_SETUP	(EMAC_MAC_CTL0_RFC | EMAC_MAC_CTL0_TFC)
#define EMAC_MAC_CTL1_FLC	(0x1 << 1)
#define EMAC_MAC_CTL1_HF	(0x1 << 2)
#define EMAC_MAC_CTL1_DCRC	(0x1 << 3)
#define EMAC_MAC_CTL1_CRC	(0x1 << 4)
#define EMAC_MAC_CTL1_PC	(0x1 << 5)
#define EMAC_MAC_CTL1_VC	(0x1 << 6)
#define EMAC_MAC_CTL1_ADP	(0x1 << 7)
#define EMAC_MAC_CTL1_PRE	(0x1 << 8)
#define EMAC_MAC_CTL1_LPE	(0x1 << 9)
#define EMAC_MAC_CTL1_NB	(0x1 << 12)
#define EMAC_MAC_CTL1_BNB	(0x1 << 13)
#define EMAC_MAC_CTL1_ED	(0x1 << 14)
#define EMAC_MAC_CTL1_SETUP	(EMAC_MAC_CTL1_FLC | EMAC_MAC_CTL1_CRC | \
#define EMAC_MAC_IPGT		0x15
#define EMAC_MAC_NBTB_IPG1	0xc
#define EMAC_MAC_NBTB_IPG2	0x12
#define EMAC_MAC_CW		0x37
#define EMAC_MAC_RM		0xf
#define EMAC_MAC_MFL		0x0600
#define EMAC_CRCERR		(0x1 << 4)
#define EMAC_LENERR		(0x3 << 5)
#define EMAC_RX_BUFSIZE		2000
#ifdef CONFIG_DM_ETH
#endif
#ifdef CONFIG_PHY_ADDR
#endif
