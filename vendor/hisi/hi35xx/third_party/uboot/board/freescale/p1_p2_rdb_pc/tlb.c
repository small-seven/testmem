#include <common.h>
#include <asm/mmu.h>
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_VSC7385_ENET
#endif
#endif /* not SPL */
#ifdef CONFIG_SYS_NAND_BASE
#endif
#if defined(CONFIG_SYS_RAMBOOT) || \
#if defined(CONFIG_TARGET_P1020MBG) || defined(CONFIG_TARGET_P1020RDB_PD)
#endif /* TARGET_P1020MBG */
#endif /* RAMBOOT/SPL */
#ifdef CONFIG_SYS_INIT_L2_ADDR
#if CONFIG_SYS_L2_SIZE >= (256 << 10)
#endif
#endif
