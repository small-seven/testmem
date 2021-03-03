#include <common.h>
#include <asm/mmu.h>
#ifdef CPLD_BASE
#endif
#ifdef PIXIS_BASE
#endif
#if defined(CONFIG_SYS_RAMBOOT) && defined(CONFIG_SYS_INIT_L3_ADDR)
#if !defined(CONFIG_NXP_ESBC)
#else
#endif
#elif defined(CONFIG_SRIO_PCIE_BOOT_SLAVE)
#else
#endif
#ifdef CONFIG_SYS_BMAN_MEM_PHYS
#endif
#ifdef CONFIG_SYS_QMAN_MEM_PHYS
#endif
#ifdef CONFIG_SYS_DCSRBAR_PHYS
#endif
#ifdef CONFIG_SYS_NAND_BASE
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_SLAVE
#endif
