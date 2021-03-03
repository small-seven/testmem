#include <dm.h>
#include <usb.h>
#include <linux/mii.h>
#include "usb_ether.h"
#include "lan7x.h"
#define LAN75XX_HW_CFG_BIR		BIT(7)
#define LAN75XX_BURST_CAP		0x034
#define LAN75XX_BULK_IN_DLY		0x03C
#define LAN75XX_RFE_CTL			0x060
#define LAN75XX_FCT_RX_CTL		0x090
#define LAN75XX_FCT_TX_CTL		0x094
#define LAN75XX_FCT_RX_FIFO_END		0x098
#define LAN75XX_FCT_TX_FIFO_END		0x09C
#define LAN75XX_FCT_FLOW		0x0A0
#define LAN75XX_ADDR_FILTX		0x300
#define LAN75XX_ADDR_FILTX_FB_VALID	BIT(31)
