#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <sdhci.h>
#include <linux/mbus.h>
#define MVSDH_NAME "mv_sdh"
#define SDHCI_WINDOW_CTRL(win)		(0x4080 + ((win) << 4))
#define SDHCI_WINDOW_BASE(win)		(0x4084 + ((win) << 4))
#ifndef CONFIG_DM_MMC
#ifdef CONFIG_MMC_SDHCI_IO_ACCESSORS
#if defined(CONFIG_SHEEVA_88SV331xV5)
#define SD_CE_ATA_2	0xEA
#define  MMC_CARD	0x1000
#define  MMC_WIDTH	0x0100
#else
#define mv_sdhci_writeb	NULL
#endif /* CONFIG_SHEEVA_88SV331xV5 */
#endif /* CONFIG_MMC_SDHCI_IO_ACCESSORS */
#ifdef CONFIG_MMC_SDHCI_IO_ACCESSORS
#endif
#else
#endif /* CONFIG_DM_MMC */
