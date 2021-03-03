#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <malloc.h>
#include <asm/omap_common.h>
#include <asm/arch-omap5/sys_proto.h>
#ifdef CONFIG_TI_SECURE_DEVICE
#ifndef TI_OMAP5_SECURE_BOOT_RESV_SRAM_SZ
#define TI_OMAP5_SECURE_BOOT_RESV_SRAM_SZ (0)
#endif
#ifndef CONFIG_SECURE_RUNTIME_RESV_SRAM_SZ
#define CONFIG_SECURE_RUNTIME_RESV_SRAM_SZ (0)
#endif
#if ((TI_OMAP5_SECURE_BOOT_RESV_SRAM_SZ != 0) || \
#else
#endif
#else
#endif /* #ifdef CONFIG_TI_SECURE_DEVICE */
#if defined(CONFIG_TARGET_DRA7XX_EVM) || defined(CONFIG_TARGET_AM57XX_EVM)
#define OPP_DSP_CLK_NUM	3
#define OPP_IVA_CLK_NUM	2
#define OPP_GPU_CLK_NUM	2
#else
#endif /* CONFIG_TARGET_DRA7XX_EVM || CONFIG_TARGET_AM57XX_EVM */
