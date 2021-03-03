#include <common.h>
#include <command.h>
#include <dm/device.h>
#include <dm/root.h>
#include <errno.h>
#include <fdt_support.h>
#include <image.h>
#include <u-boot/zlib.h>
#include <asm/bootparam.h>
#include <asm/cpu.h>
#include <asm/byteorder.h>
#include <asm/zimage.h>
#ifdef CONFIG_SYS_COREBOOT
#include <asm/arch/timestamp.h>
#endif
#define COMMAND_LINE_OFFSET 0x9000
#ifdef CONFIG_SYS_COREBOOT
#endif
#if CONFIG_IS_ENABLED(BOOTSTAGE_REPORT)
#endif
#if defined(CONFIG_OF_LIBFDT) && !defined(CONFIG_OF_NO_KERNEL)
#endif
#ifdef CONFIG_OF_LIBFDT
#endif
#if defined(CONFIG_FIT)
#endif
#ifdef CONFIG_SYS_COREBOOT
#endif
#if !CONFIG_IS_ENABLED(X86_64)
#endif
#ifndef CONFIG_EFI_APP
#endif
