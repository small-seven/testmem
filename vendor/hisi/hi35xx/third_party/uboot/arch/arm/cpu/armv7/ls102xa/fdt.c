#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/arch/clock.h>
#include <linux/ctype.h>
#ifdef CONFIG_FSL_ESDHC
#include <fsl_esdhc.h>
#endif
#include <tsec.h>
#include <asm/arch/immap_ls102xa.h>
#include <fsl_sec.h>
#include <dm.h>
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#if CONFIG_SYS_FSL_SEC_COMPAT >= 4
#endif
#ifdef CONFIG_SYS_NS16550
#endif
#if defined(CONFIG_DEEP_SLEEP) && defined(CONFIG_SD_BOOT)
#define UBOOT_HEAD_LEN	0x1000
#endif
#if defined(CONFIG_FSL_ESDHC)
#endif
#if defined(CONFIG_QSPI_BOOT) || defined(CONFIG_SD_BOOT_QSPI)
#else
#endif
