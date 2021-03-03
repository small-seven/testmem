#include <common.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <pci.h>
#include <miiphy.h>
#undef DEBUG
#define ULI_VENDOR_ID		0x10B9
#define ULI5261_DEVICE_ID	0x5261
#define ULI5263_DEVICE_ID	0x5263
#define PCI_ULI5261_ID		(ULI5261_DEVICE_ID << 16 | ULI_VENDOR_ID)
#define PCI_ULI5263_ID		(ULI5263_DEVICE_ID << 16 | ULI_VENDOR_ID)
#define ULI526X_IO_SIZE	0x100
#define TX_DESC_CNT	0x10		/* Allocated Tx descriptors */
#define RX_DESC_CNT	PKTBUFSRX	/* Allocated Rx descriptors */
#define TX_FREE_DESC_CNT	(TX_DESC_CNT - 2) /* Max TX packet count */
#define TX_WAKE_DESC_CNT	(TX_DESC_CNT - 3) /* TX wakeup count */
#define DESC_ALL_CNT		(TX_DESC_CNT + RX_DESC_CNT)
#define TX_BUF_ALLOC		0x300
#define RX_ALLOC_SIZE		PKTSIZE
#define ULI526X_RESET		1
#define CR0_DEFAULT		0
#define CR6_DEFAULT		0x22200000
#define CR7_DEFAULT		0x180c1
#define CR15_DEFAULT		0x06		/* TxJabber RxWatchdog */
#define TDES0_ERR_MASK		0x4302		/* TXJT, LC, EC, FUE */
#define MAX_PACKET_SIZE		1514
#define ULI5261_MAX_MULTICAST	14
#define RX_COPY_SIZE		100
#define MAX_CHECK_PACKET	0x8000
#define ULI526X_10MHF		0
#define ULI526X_100MHF		1
#define ULI526X_10MFD		4
#define ULI526X_100MFD		5
#define ULI526X_AUTO		8
#define ULI526X_TXTH_72		0x400000	/* TX TH 72 byte */
#define ULI526X_TXTH_96		0x404000	/* TX TH 96 byte */
#define ULI526X_TXTH_128	0x0000		/* TX TH 128 byte */
#define ULI526X_TXTH_256	0x4000		/* TX TH 256 byte */
#define ULI526X_TXTH_512	0x8000		/* TX TH 512 byte */
#define ULI526X_TXTH_1K		0xC000		/* TX TH 1K  byte */
#define CR9_SROM_READ		0x4800
#define CR9_SRCS		0x1
#define CR9_SRCLK		0x2
#define CR9_CRDOUT		0x8
#define SROM_DATA_0		0x0
#define SROM_DATA_1		0x4
#define PHY_DATA_1		0x20000
#define PHY_DATA_0		0x00000
#define MDCLKH			0x10000
#define PHY_POWER_DOWN	0x800
#define SROM_V41_CODE		0x14
#define SROM_CLK_WRITE(data, ioaddr) do {			\
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef TX_DEBUG
#endif
#ifdef TX_DEBUG
#endif
#ifdef RX_DEBUG
#endif
#ifdef RX_DEBUG
#endif
#ifdef RX_DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
