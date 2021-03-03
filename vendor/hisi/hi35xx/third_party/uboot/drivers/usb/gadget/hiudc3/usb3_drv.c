#include "usb3.h"
#include "usb3_hw.h"
#include "usb3_drv.h"
#include "sys.h"
#include "onchiprom.h"
#include "common.h"
#include <cpu_func.h>
#include <linux/string.h>
#include <malloc.h>
#include <linux/compat.h>
#include "../../../phy/hibvt/usb_hisi.h"
#define udelay_100us udelay
#define msleep udelay
void usb3_memset(void *buf, uint8_t value, uint32_t size)
{
	uint8_t *pbuf = (uint8_t *)buf;

	while (size--) {
		*pbuf++ = value;
	}
}
void usb3_memcpy(void *dst, void *src, uint32_t size)
{
	uint8_t *pdst = (uint8_t *)dst;
	uint8_t *psrc = (uint8_t *)src;

	if (psrc > pdst) {
		while (size--) {
			*pdst++ = *psrc++;
		}
	} else {
		pdst += size - 1;
		psrc += size - 1;
		while (size--) {
			*pdst-- = *psrc--;
		}
	}
}
#define RAM_WIDTH       8
#define RAM_RX_DEPTH    4096
#define RAM_TX0_DEPTH   1024
#define RAM_TX1_DEPTH   2048
