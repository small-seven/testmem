#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/armv8/mmu.h>
#define MVEBU_RFU_BASE			(MVEBU_REGISTER(0x6f0000))
#define RFU_GLOBAL_SW_RST		(MVEBU_RFU_BASE + 0x84)
#define RFU_SW_RESET_OFFSET		0
#define SAR0_REG			(MVEBU_REGISTER(0x2400200))
#define BOOT_MODE_MASK			0x3f
#define BOOT_MODE_OFFSET		4
#define ARMADA_7K8K_COMMON_REGIONS_START	2
