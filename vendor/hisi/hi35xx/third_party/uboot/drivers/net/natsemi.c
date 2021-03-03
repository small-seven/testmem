#include <common.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <pci.h>
#define EEPROM_SIZE 0xb /*12 16-bit chunks, or 24 bytes*/
#define DSIZE		0x00000FFF
#define CRC_SIZE	4
#define TOUT_LOOP	500000
#define TX_BUF_SIZE	1536
#define RX_BUF_SIZE	1536
#define NUM_RX_DESC	4	/* Number of Rx descriptor registers. */
typedef struct _BufferDesc {
	u32 link;
	vu_long cmdsts;
	u32 bufptr;
	u32 software_use;
} BufferDesc;
#ifdef NATSEMI_DEBUG
#endif
#if 0
#endif
#define bus_to_phys(a)	pci_mem_to_phys((pci_dev_t)dev->priv, a)
#define phys_to_bus(a)	pci_phys_to_mem((pci_dev_t)dev->priv, a)
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#define eeprom_delay(ee_addr)	INL(dev, ee_addr)
#define EE_Write0 (EE_ChipSelect)
#define EE_Write1 (EE_ChipSelect | EE_DataIn)
#if 0
#ifdef NATSEMI_DEBUG
#endif
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
#ifdef NATSEMI_DEBUG
#endif
