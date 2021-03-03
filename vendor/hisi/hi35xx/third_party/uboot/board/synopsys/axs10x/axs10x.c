#include <common.h>
#include <cpu_func.h>
#include <dwmmc.h>
#include <malloc.h>
#include <asm/arcregs.h>
#include "axs10x.h"
#define AXS_MB_CREG	0xE0011000
#ifdef CONFIG_ISA_ARCV2
#define RESET_VECTOR_ADDR	0x0
#define AXC003_CREG_CPU_START	0xF0001400
#define BITS_START	0
#define BITS_START_MODE	4
#define BITS_CORE_SEL	9
#define BITS_START_CORE1	1
#define ARCVER_HS38_3_0	0x53
#endif
