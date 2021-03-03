#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#ifdef CONFIG_TI_SECURE_DEVICE
#ifndef TI_OMAP5_SECURE_BOOT_RESV_SRAM_SZ
#define TI_OMAP5_SECURE_BOOT_RESV_SRAM_SZ (0)
#endif
#ifndef CONFIG_SECURE_RUNTIME_RESV_SRAM_SZ
#define CONFIG_SECURE_RUNTIME_RESV_SRAM_SZ (0)
#endif
#if (CONFIG_TI_SECURE_EMIF_TOTAL_REGION_SIZE != 0)
#else
#endif
#endif
