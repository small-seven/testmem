#include <common.h>
#include <cpu_func.h>
#include <mmc.h>
#include <malloc.h>
#define ESDHC_BOOT_IMAGE_SIZE	0x48
#define ESDHC_BOOT_IMAGE_ADDR	0x50
#define MBRDBR_BOOT_SIG_55	0x1fe
#define MBRDBR_BOOT_SIG_AA	0x1ff
#define CONFIG_CFG_DATA_SECTOR	0
#ifndef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
#ifndef CONFIG_FSL_CORENET
#endif
