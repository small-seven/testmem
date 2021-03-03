#include <common.h>
#include <pci.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#include <fdt_support.h>
#endif
#include <asm/mpc8349_pci.h>
#define MAX_BUSES 2
#ifdef CONFIG_83XX_PCI_STREAMING
#endif
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#ifndef CONFIG_PCISLAVE
#endif
#ifdef CONFIG_PCISLAVE
#define PCI_FUNCTION_CONFIG	0x44
#define PCI_FUNCTION_CFG_LOCK	0x20
#endif
#if defined(CONFIG_OF_LIBFDT)
#endif /* CONFIG_OF_LIBFDT */
