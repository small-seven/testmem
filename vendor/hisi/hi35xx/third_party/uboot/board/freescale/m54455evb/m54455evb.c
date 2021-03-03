#include <common.h>
#include <init.h>
#include <pci.h>
#include <asm/immap.h>
#include <asm/io.h>
#ifdef CONFIG_CF_SBF
#else
#endif
#if defined(CONFIG_IDE)
#include <ata.h>
#define CALC_TIMING(t) (t + period - 1) / period
#endif
#if defined(CONFIG_PCI)
#endif				/* CONFIG_PCI */
#if defined(CONFIG_FLASH_CFI_LEGACY)
#include <flash.h>
#endif				/* CONFIG_SYS_FLASH_CFI */
