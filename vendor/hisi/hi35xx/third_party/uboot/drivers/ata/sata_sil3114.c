#include <common.h>
#include <pci.h>
#include <command.h>
#include <config.h>
#include <asm/byteorder.h>
#include <asm/io.h>
#include <ide.h>
#include <sata.h>
#include <libata.h>
#include "sata_sil3114.h"
#define ATA_SECTOR_WORDS (ATA_SECT_SIZE/2)
#ifdef DEBUG
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#endif
#if (CONFIG_SYS_SATA_MAX_DEVICE >= 1)
#elif (CONFIG_SYS_SATA_MAX_DEVICE >= 2)
#elif (CONFIG_SYS_SATA_MAX_DEVICE >= 3)
#endif
