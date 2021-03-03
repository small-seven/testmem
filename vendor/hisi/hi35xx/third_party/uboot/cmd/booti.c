#include <common.h>
#include <bootm.h>
#include <command.h>
#include <image.h>
#include <irq_func.h>
#include <lmb.h>
#include <mapmem.h>
#include <linux/kernel.h>
#include <linux/sizes.h>
#ifdef CONFIG_RISCV_SMODE
#elif CONFIG_ARM64
#endif
#ifdef CONFIG_SYS_BOOT_RAMDISK_HIGH
#endif
#ifdef CONFIG_SYS_LONGHELP
#if defined(CONFIG_OF_LIBFDT)
#endif
#endif
