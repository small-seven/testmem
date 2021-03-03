#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include <dm.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include <asm/arch/rmobile.h>
#include <asm/arch/sh_sdhi.h>
#include <clk.h>
#define DRIVER_NAME "sh-sdhi"
#if defined(__BIG_ENDIAN_BITFIELD)
#else
#endif /* __BIG_ENDIAN_BITFIELD */
#if defined(__BIG_ENDIAN_BITFIELD)
#endif
#ifndef CONFIG_DM_MMC
#ifdef CONFIG_RCAR_GEN3
#else
#endif
#else
#endif
