#include <common.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define VERSAL_MEM_MAP_USED	5
#define DRAM_BANKS CONFIG_NR_DRAM_BANKS
#if defined(CONFIG_DEFINE_TCM_OCM_MMAP)
#define TCM_MAP 1
#else
#define TCM_MAP 0
#endif
#define VERSAL_MEM_MAP_MAX (VERSAL_MEM_MAP_USED + DRAM_BANKS + TCM_MAP + 1)
#if defined(CONFIG_DEFINE_TCM_OCM_MMAP)
#endif
#if defined(CONFIG_SYS_MEM_RSVD_FOR_MMU)
#endif
