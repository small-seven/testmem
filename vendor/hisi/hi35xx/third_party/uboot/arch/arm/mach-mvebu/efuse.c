#include <config.h>
#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/efuse.h>
#include <asm/arch/soc.h>
#include <linux/mbus.h>
#if defined(CONFIG_MVEBU_EFUSE_FAKE)
#define DRY_RUN
#else
#undef DRY_RUN
#endif
#define MBUS_EFUSE_BASE 0xF6000000
#define MBUS_EFUSE_SIZE BIT(20)
#define MVEBU_EFUSE_CONTROL (MVEBU_REGISTER(0xE4008))
#ifndef DRY_RUN
#else
#endif
#ifndef DRY_RUN
#endif
#ifndef DRY_RUN
#endif
