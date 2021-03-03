#include <common.h>
#include <init.h>
#include <asm/arch/boot.h>
#include <env.h>
#include <linux/libfdt.h>
#include <linux/err.h>
#include <asm/arch/mem.h>
#include <asm/arch/sm.h>
#include <asm/armv8/mmu.h>
#include <asm/unaligned.h>
#include <efi_loader.h>
#include <u-boot/crc.h>
#if CONFIG_IS_ENABLED(FASTBOOT)
#include <asm/psci.h>
#include <fastboot.h>
#endif
#if CONFIG_IS_ENABLED(FASTBOOT)
#else
#endif
