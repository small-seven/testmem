#include <common.h>
#include <asm/mmu.h>
#ifdef CONFIG_SPL_NAND_BOOT
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_PCI
#endif
#endif
#if defined(CONFIG_SYS_RAMBOOT) || defined(CONFIG_SPL)
#endif
#ifdef CONFIG_SYS_FPGA_BASE
#endif
#ifdef CONFIG_SYS_NAND_BASE_PHYS
#endif
