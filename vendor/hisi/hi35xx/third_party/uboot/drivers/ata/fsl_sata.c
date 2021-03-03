#include <common.h>
#include <command.h>
#include <console.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/fsl_serdes.h>
#include <malloc.h>
#include <libata.h>
#include <fis.h>
#include <sata.h>
#include "fsl_sata.h"
#if CONFIG_IS_ENABLED(BLK)
#include <dm.h>
#include <ahci.h>
#include <blk.h>
#else
#ifndef CONFIG_SYS_SATA1_FLAGS
#endif
#ifndef CONFIG_SYS_SATA2_FLAGS
#endif
#ifdef CONFIG_SATA1
#else
#endif
#ifdef CONFIG_SATA2
#else
#endif
#endif
#if !CONFIG_IS_ENABLED(BLK)
#else
#endif
#ifdef CONFIG_MPC85xx
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
#ifdef CONFIG_LBA48
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
