#include <common.h>
#include <ahci.h>
#include <cpu_func.h>
#include <dm.h>
#include <dwc_ahsata.h>
#include <fis.h>
#include <libata.h>
#include <malloc.h>
#include <memalign.h>
#include <sata.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/sata.h>
#include <linux/bitops.h>
#include <linux/ctype.h>
#include <linux/errno.h>
#include "dwc_ahsata_priv.h"
#define MAX_DATA_BYTES_PER_SG  (4 * 1024 * 1024)
#define MAX_BYTES_PER_TRANS (AHCI_MAX_SG * MAX_DATA_BYTES_PER_SG)
#define writel_with_flush(a, b)	do { writel(a, b); readl(b); } while (0)
#ifdef CONFIG_PHYS_64BIT
#endif
#define AHCI_GET_CMD_SLOT(c) ((c) ? ffs(c) : 0)
#if !CONFIG_IS_ENABLED(AHCI)
#if defined(CONFIG_MX6)
#endif
#endif /* CONFIG_IS_ENABLED(AHCI) */
#if CONFIG_IS_ENABLED(AHCI)
#if defined(CONFIG_MX6)
#endif
#if CONFIG_IS_ENABLED(DWC_AHSATA_AHCI)
#endif
#endif
