#include <common.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <zynqmp_firmware.h>
#define ZYNQ_SILICON_VER_MASK	0xF000
#define ZYNQ_SILICON_VER_SHIFT	12
#define ZYNQMP_MEM_MAP_USED	4
#if !defined(CONFIG_ZYNQMP_NO_DDR)
#define DRAM_BANKS CONFIG_NR_DRAM_BANKS
#else
#define DRAM_BANKS 0
#endif
#if defined(CONFIG_DEFINE_TCM_OCM_MMAP)
#define TCM_MAP 1
#else
#define TCM_MAP 0
#endif
#define ZYNQMP_MEM_MAP_MAX (ZYNQMP_MEM_MAP_USED + DRAM_BANKS + TCM_MAP + 1)
#if defined(CONFIG_DEFINE_TCM_OCM_MMAP)
#endif
#if !defined(CONFIG_ZYNQMP_NO_DDR)
#endif
#if defined(CONFIG_SYS_MEM_RSVD_FOR_MMU) || defined(CONFIG_DEFINE_TCM_OCM_MMAP)
#endif
#ifdef CONFIG_SYS_MEM_RSVD_FOR_MMU
#endif
#if defined(CONFIG_ZYNQMP_FIRMWARE)
#endif
#if defined(CONFIG_ZYNQMP_FIRMWARE)
#endif
