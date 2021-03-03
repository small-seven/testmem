#include <common.h>
#include <cpu_func.h>
#include <pci.h>
#include <command.h>
#include <asm/byteorder.h>
#include <malloc.h>
#include <asm/io.h>
#include <fis.h>
#include <sata.h>
#include <libata.h>
#include <sata.h>
#if CONFIG_IS_ENABLED(BLK)
#include <dm.h>
#include <blk.h>
#endif
#include "sata_sil.h"
#define virt_to_bus(devno, v)	pci_virt_to_mem(devno, (void *) (v))
#ifdef CONFIG_LBA48
#endif
#if !CONFIG_IS_ENABLED(BLK)
#else
#endif
#if !CONFIG_IS_ENABLED(BLK)
#else
#endif
#if !CONFIG_IS_ENABLED(BLK)
#else
#endif
#if !CONFIG_IS_ENABLED(BLK)
#else
#endif
#if !CONFIG_IS_ENABLED(BLK)
#else
#endif
#if !CONFIG_IS_ENABLED(BLK)
#ifdef CONFIG_LBA48
#endif
#else
#ifdef CONFIG_LBA48
#endif
#endif
#ifdef DEBUG
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
