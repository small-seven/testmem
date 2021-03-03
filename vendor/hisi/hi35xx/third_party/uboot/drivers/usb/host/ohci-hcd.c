#include <common.h>
#include <cpu_func.h>
#include <asm/byteorder.h>
#include <dm.h>
#include <errno.h>
#if defined(CONFIG_PCI_OHCI)
# include <pci.h>
#if !defined(CONFIG_PCI_OHCI_DEVNO)
#define CONFIG_PCI_OHCI_DEVNO	0
#endif
#endif
#include <malloc.h>
#include <memalign.h>
#include <usb.h>
#include "ohci.h"
#ifdef CONFIG_AT91RM9200
#include <asm/arch/hardware.h>	/* needed for AT91_USB_HOST_BASE */
#endif
#if defined(CONFIG_CPU_ARM920T) || \
# define OHCI_USE_NPS		/* force NoPowerSwitching mode */
#endif
#undef OHCI_VERBOSE_DEBUG	/* not always helpful */
#undef DEBUG
#undef SHOW_INFO
#undef OHCI_FILL_TRACE
#define OHCI_CONTROL_INIT \
#if !CONFIG_IS_ENABLED(DM_USB)
#ifdef CONFIG_PCI_OHCI
#endif
#endif
#ifdef CONFIG_PCI_EHCI_DEVNO
#endif
#ifdef DEBUG
#define dbg(format, arg...) printf("DEBUG: " format "\n", ## arg)
#else
#define dbg(format, arg...) do {} while (0)
#endif /* DEBUG */
#define err(format, arg...) printf("ERROR: " format "\n", ## arg)
#ifdef SHOW_INFO
#define info(format, arg...) printf("INFO: " format "\n", ## arg)
#else
#define info(format, arg...) do {} while (0)
#endif
#ifdef CONFIG_SYS_OHCI_BE_CONTROLLER
# define m16_swap(x) cpu_to_be16(x)
# define m32_swap(x) cpu_to_be32(x)
#else
# define m16_swap(x) cpu_to_le16(x)
# define m32_swap(x) cpu_to_le32(x)
#endif /* CONFIG_SYS_OHCI_BE_CONTROLLER */
#define flush_dcache_buffer(addr, size) \
#define invalidate_dcache_buffer(addr, size) \
#define flush_dcache_ed(addr) flush_dcache_buffer(addr, 16)
#define flush_dcache_td(addr) flush_dcache_buffer(addr, 16)
#define flush_dcache_iso_td(addr) flush_dcache_buffer(addr, 32)
#define flush_dcache_hcca(addr) flush_dcache_buffer(addr, 256)
#define invalidate_dcache_ed(addr) invalidate_dcache_buffer(addr, 16)
#define invalidate_dcache_td(addr) invalidate_dcache_buffer(addr, 16)
#define invalidate_dcache_iso_td(addr) invalidate_dcache_buffer(addr, 32)
#define invalidate_dcache_hcca(addr) invalidate_dcache_buffer(addr, 256)
#if CONFIG_IS_ENABLED(DM_USB)
#define ohci_mdelay(x)
#else
#define ohci_mdelay(x) mdelay(x)
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
static inline void ed_free(struct ed *ed)
{
	ed->usb_dev = NULL;
}
#ifdef DEBUG
#ifdef	OHCI_VERBOSE_DEBUG
#endif
#ifdef CONFIG_AT91C_PQFP_UHPBUG
#endif
#endif /* DEBUG */
#ifdef DEBUG
#endif
#ifdef OHCI_FILL_TRACE
#endif
#ifdef OHCI_FILL_TRACE
#endif
#include <usbroothubdes.h>
#define OK(x)			len = (x); break
#ifdef DEBUG
#define WR_RH_STAT(x)		{info("WR:status %#8x", (x)); ohci_writel((x), \
#define WR_RH_PORTSTAT(x)	{info("WR:portstatus[%d] %#8x", wIndex-1, \
#else
#define WR_RH_STAT(x)		ohci_writel((x), &ohci->regs->roothub.status)
#define WR_RH_PORTSTAT(x)	ohci_writel((x), \
#endif
#define RD_RH_STAT		roothub_status(ohci)
#define RD_RH_PORTSTAT		roothub_portstatus(ohci, wIndex-1)
#ifdef CONFIG_AT91C_PQFP_UHPBUG
#endif
#ifdef DEBUG
#else
#endif
#ifdef CONFIG_AT91C_PQFP_UHPBUG
#endif
#ifdef	DEBUG
#else
#endif
#ifdef DEBUG
#else
#endif
#ifdef DEBUG
#else
#endif
#ifdef DEBUG
#else
#endif
#define MAX_INT_QUEUESIZE 8
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#ifdef DEBUG
#else
#endif
#ifdef CONFIG_PCI_EHCI_DEVNO
#endif
#ifdef CONFIG_PCI_EHCI_DEVNO
#endif
#ifdef	OHCI_USE_NPS
#endif	/* OHCI_USE_NPS */
#ifdef	DEBUG
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#ifdef CONFIG_PCI_OHCI
#endif
#ifdef CONFIG_SYS_USB_OHCI_CPU_INIT
#endif
#ifdef CONFIG_SYS_USB_OHCI_BOARD_INIT
#endif
#ifdef CONFIG_PCI_OHCI
#else
#endif
#ifdef CONFIG_SYS_USB_OHCI_BOARD_INIT
#endif
#ifdef CONFIG_SYS_USB_OHCI_CPU_INIT
#endif
#ifdef CONFIG_SYS_USB_OHCI_BOARD_INIT
#endif
#ifdef CONFIG_SYS_USB_OHCI_CPU_INIT
#endif
#ifdef	DEBUG
#else
#endif
#ifdef CONFIG_SYS_USB_OHCI_BOARD_INIT
#endif
#ifdef CONFIG_SYS_USB_OHCI_CPU_INIT
#endif
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
