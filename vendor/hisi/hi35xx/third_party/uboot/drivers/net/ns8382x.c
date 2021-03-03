#include <common.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <pci.h>
#define DSIZE     0x00000FFF
#define CRC_SIZE  4
#define TOUT_LOOP   500000
#define TX_BUF_SIZE    1536
#define RX_BUF_SIZE    1536
#define NUM_RX_DESC    4	/* Number of Rx descriptor registers. */
#define SpeedStatus_Polarity ( GigSpeed | HundSpeed | FullDuplex)
typedef struct _BufferDesc {
	u32 link;
	u32 bufptr;
	vu_long cmdsts;
	u32 extsts;		/*not used here */
} BufferDesc;
#define bus_to_phys(a)	pci_mem_to_phys((pci_dev_t)dev->priv, a)
#define phys_to_bus(a)	pci_phys_to_mem((pci_dev_t)dev->priv, a)
#define mdio_delay(mdio_addr) INL(dev, mdio_addr)
#define MDIO_EnbIn  (0)
#define MDIO_WRITE0 (MDIO_EnbOutput)
#define MDIO_WRITE1 (MDIO_Data | MDIO_EnbOutput)
