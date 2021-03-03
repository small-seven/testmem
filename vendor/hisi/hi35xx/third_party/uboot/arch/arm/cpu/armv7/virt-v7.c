#include <common.h>
#include <cpu_func.h>
#include <asm/armv7.h>
#include <asm/gic.h>
#include <asm/io.h>
#include <asm/secure.h>
#ifdef CONFIG_ARM_GIC_BASE_ADDRESS
#else
#endif
#ifdef CONFIG_ARMV7_SECURE_BASE
#endif
#ifndef CONFIG_ARMV7_PSCI
#endif
