#include <common.h>
#include <config.h>
#include <spl.h>
#include <asm/io.h>
#include <nand.h>
#include <linux/libfdt_env.h>
#include <fdt.h>
#if defined(CONFIG_SPL_NAND_RAW_ONLY)
#else
#ifdef CONFIG_SPL_NAND_SOFTECC
#else
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#ifdef CONFIG_NAND_ENV_DST
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#endif
#ifdef CONFIG_SYS_NAND_U_BOOT_OFFS_REDUND
#if CONFIG_SYS_NAND_U_BOOT_OFFS != CONFIG_SYS_NAND_U_BOOT_OFFS_REDUND
#endif
#endif
#endif
