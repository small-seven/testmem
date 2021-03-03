#undef	VERBOSE_DEBUG
#undef	PACKET_TRACE
#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/hardware.h>
#include <mach/at91_matrix.h>
#include <linux/list.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/at91_udc.h>
#include <malloc.h>
#include "at91_udc.h"
#define	DRIVER_VERSION	"3 May 2006"
#define ep0name		ep_names[0]
#define at91_udp_read(udc, reg) \
#define at91_udp_write(udc, reg, val) \
#define	RX_DATA_READY	(AT91_UDP_RX_DATA_BK0 | AT91_UDP_RX_DATA_BK1)
#define	SET_FX	(AT91_UDP_TXPKTRDY)
#define	CLR_FX	(RX_DATA_READY | AT91_UDP_RXSETUP \
#define w_index		le16_to_cpu(pkt.r.wIndex)
#define w_value		le16_to_cpu(pkt.r.wValue)
#define w_length	le16_to_cpu(pkt.r.wLength)
#undef w_value
#undef w_index
#undef w_length
#if defined(CONFIG_AT91SAM9260) || defined(CONFIG_AT91SAM9G20)
#endif
#if defined(CONFIG_AT91SAM9261)
#endif
#if defined(CONFIG_AT91SAM9260) || defined(CONFIG_AT91SAM9G20)
#endif
