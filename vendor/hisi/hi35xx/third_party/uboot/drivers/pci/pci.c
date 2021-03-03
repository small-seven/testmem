#include <common.h>
#include <init.h>
#include <command.h>
#include <env.h>
#include <errno.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <pci.h>
#define PCI_HOSE_OP(rw, size, type)					\
#define PCI_OP(rw, size, type, error_code)				\
#define PCI_READ_VIA_DWORD_OP(size, type, off_mask)			\
#define PCI_WRITE_VIA_DWORD_OP(size, type, off_mask, val_mask)		\
#ifdef CONFIG_SYS_PCI_64BIT
#else
#endif
#ifdef CONFIG_PCI_SCAN_SHOW
#endif /* CONFIG_PCI_SCAN_SHOW */
#ifndef CONFIG_PCI_PNP
#endif
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#ifdef CONFIG_PCI_FIXUP_DEV
#endif
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#ifdef CONFIG_PCI_PNP
#else
#endif
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#if defined(CONFIG_PCI_BOOTDELAY)
#endif /* CONFIG_PCI_BOOTDELAY */
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#ifdef CONFIG_PCI_PNP
#endif
