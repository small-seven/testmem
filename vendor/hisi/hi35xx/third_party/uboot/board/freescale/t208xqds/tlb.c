#include <common.h>
#include <asm/mmu.h>
#if defined(CONFIG_SYS_RAMBOOT) && defined(CONFIG_SYS_INIT_L3_ADDR)
#elif defined(CONFIG_SRIO_PCIE_BOOT_SLAVE)
#else
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_SYS_BMAN_MEM_PHYS
#endif
#ifdef CONFIG_SYS_QMAN_MEM_PHYS
#endif
#endif
#ifdef CONFIG_SYS_DCSRBAR_PHYS
#endif
#ifdef CONFIG_SYS_NAND_BASE
#endif
#ifdef QIXIS_BASE_PHYS
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_SLAVE
#endif
#if defined(CONFIG_RAMBOOT_PBL) && !defined(CONFIG_SPL_BUILD)
#endif
