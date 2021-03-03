#include <common.h>
#include <command.h>
#include <config.h>
#include <cpu_func.h>
#include <net.h>
#include <malloc.h>
#include <asm/byteorder.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/unaligned.h>
#include <linux/types.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <usb/ci_udc.h>
#include "../host/ehci.h"
#include "ci_udc.h"
#if ARCH_DMA_MINALIGN > 128
#error This driver can not work on systems with caches longer than 128b
#endif
#define ILIST_ALIGN		roundup(ARCH_DMA_MINALIGN, 32)
#define ILIST_ENT_RAW_SZ	sizeof(struct ept_queue_item)
#define ILIST_ENT_SZ		roundup(ILIST_ENT_RAW_SZ, ILIST_ALIGN)
#define ILIST_SZ		(NUM_ENDPOINTS * 2 * ILIST_ENT_SZ)
#define EP_MAX_LENGTH_TRANSFER	0x4000
#ifndef DEBUG
#define DBG(x...) do {} while (0)
#else
#define DBG(x...) printf(x)
#endif
#define SETUP(type, request) (((type) << 8) | (request))
#ifdef CONFIG_CI_UDC_HAS_HOSTPC
#else
#endif
#ifdef CONFIG_CI_UDC_HAS_HOSTPC
#endif
#ifdef CONFIG_CI_UDC_HAS_HOSTPC
#else
#endif
#ifdef CONFIG_CI_UDC_HAS_HOSTPC
#else
#endif
#if !defined(CONFIG_USB_GADGET_DUALSPEED)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
