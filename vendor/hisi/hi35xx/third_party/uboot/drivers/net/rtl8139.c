#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <pci.h>
#define RTL_TIMEOUT	100000
#define TX_FIFO_THRESH 256	/* In bytes, rounded down to 32 byte units. */
#define RX_FIFO_THRESH	4	/* Rx buffer level before first PCI xfer.  */
#define RX_DMA_BURST	4	/* Maximum PCI burst, '4' is 256 bytes */
#define TX_DMA_BURST	4	/* Calculate as 16<<val. */
#define NUM_TX_DESC	4	/* Number of Tx descriptor registers. */
#define TX_BUF_SIZE	ETH_FRAME_LEN	/* FCS is added by the chip */
#define RX_BUF_LEN_IDX 0	/* 0, 1, 2 is allowed - 8,16,32K rx buffer */
#define RX_BUF_LEN (8192 << RX_BUF_LEN_IDX)
#define DEBUG_TX	0	/* set to 1 to enable debug code */
#define DEBUG_RX	0	/* set to 1 to enable debug code */
#define bus_to_phys(a)	pci_mem_to_phys((pci_dev_t)dev->priv, a)
#define phys_to_bus(a)	pci_phys_to_mem((pci_dev_t)dev->priv, a)
#define EE_SHIFT_CLK	0x04	/* EEPROM shift clock. */
#define EE_CS		0x08	/* EEPROM chip select. */
#define EE_DATA_WRITE	0x02	/* EEPROM chip data in. */
#define EE_WRITE_0	0x00
#define EE_WRITE_1	0x02
#define EE_DATA_READ	0x01	/* EEPROM chip data out. */
#define EE_ENB		(0x80 | EE_CS)
#define eeprom_delay()	inl(ee_addr)
#define EE_WRITE_CMD	(5)
#define EE_READ_CMD	(6)
#define EE_ERASE_CMD	(7)
