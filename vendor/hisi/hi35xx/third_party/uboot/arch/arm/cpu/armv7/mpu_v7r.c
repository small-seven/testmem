#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <asm/armv7.h>
#include <asm/system.h>
#include <asm/barriers.h>
#include <linux/compiler.h>
#include <asm/armv7_mpu.h>
#define MPUIR_S_SHIFT		0
#define MPUIR_S_MASK		BIT(MPUIR_S_SHIFT)
#define MPUIR_DREGION_SHIFT	8
#define MPUIR_DREGION_MASK	(0xff << 8)
