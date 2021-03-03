#include <cpu_func.h>
#include <asm/arch/hardware.h>
#include <asm/cache.h>
#include <asm/emif.h>
#include <common.h>
#include <command.h>
#ifdef CONFIG_ARCH_KEYSTONE
#include <asm/arch/ddr3.h>
#define DDR_MIN_ADDR		CONFIG_SYS_SDRAM_BASE
#define STACKSIZE		(512 << 10)     /* 512 KiB */
#define DDR_REMAP_ADDR		0x80000000
#define ECC_START_ADDR1		((DDR_MIN_ADDR - DDR_REMAP_ADDR) >> 17)
#define ECC_END_ADDR1		(((gd->start_addr_sp - DDR_REMAP_ADDR - \
#endif
#define DDR_TEST_BURST_SIZE	1024
#ifdef CONFIG_ARCH_KEYSTONE
#else
#endif
#ifdef CONFIG_ARCH_KEYSTONE
#else
#endif
