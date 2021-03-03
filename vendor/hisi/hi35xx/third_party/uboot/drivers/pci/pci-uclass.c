#include <common.h>
#include <dm.h>
#include <errno.h>
#include <pci.h>
#include <asm/io.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#if defined(CONFIG_X86) && defined(CONFIG_HAVE_FSP)
#include <asm/fsp/fsp_support.h>
#endif
#include "pci_internal.h"
#ifdef CONFIG_NR_DRAM_BANKS
#else
#ifdef CONFIG_SYS_SDRAM_BASE
#endif
#endif
#if CONFIG_IS_ENABLED(PCI_PNP)
#endif
#if defined(CONFIG_X86) && defined(CONFIG_HAVE_FSP)
#endif
