#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <usb.h>
#include <asm/io.h>
#include <malloc.h>
#include <memalign.h>
#include <watchdog.h>
#include <linux/compiler.h>
#include "ehci.h"
#ifndef CONFIG_USB_MAX_CONTROLLER_COUNT
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif
#define HCHALT_TIMEOUT (8 * 1000)
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#define ALIGN_END_ADDR(type, ptr, size)			\
#if defined(CONFIG_EHCI_IS_TDI)
#define ehci_is_TDI()	(1)
#else
#define ehci_is_TDI()	(0)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if defined(CONFIG_EHCI_MMIO_BIG_ENDIAN)
#else
#endif
#ifdef CONFIG_USB_EHCI_TXFIFO_THRESH
#endif
#define PKT_ALIGN	512
#if CONFIG_SYS_MALLOC_LEN <= 64 + 128 * 1024
#warning CONFIG_SYS_MALLOC_LEN may be too small for EHCI
#endif
#ifndef CONFIG_USB_EHCI_FARADAY
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#if defined(CONFIG_EHCI_HCD_INIT_AFTER_RESET)
#endif
#ifdef CONFIG_USB_EHCI_FARADAY
#endif
#endif
#define NEXT_QH(qh) (struct QH *)((unsigned long)hc32_to_cpu((qh)->qh_link) & ~0x1f)
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#ifdef CONFIG_PHY
#else
#endif
