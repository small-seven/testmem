#include <bouncebuf.h>
#include <common.h>
#include <cpu_func.h>
#include <errno.h>
#include <malloc.h>
#include <memalign.h>
#include <mmc.h>
#include <dwmmc.h>
#include <wait_bit.h>
#include <power/regulator.h>
#define PAGE_SIZE 4096
#ifdef CONFIG_DM_MMC
#else
#endif
#ifdef CONFIG_DM_MMC
#else
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#ifdef CONFIG_DM_MMC
#else
#endif
#ifndef CONFIG_DM_MMC
#endif
#ifdef CONFIG_BLK
#else
#endif
