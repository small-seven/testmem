#include <common.h>
#include <clk.h>
#include <cpu.h>
#include <cpu_func.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass.h>
#include <errno.h>
#include <thermal.h>
#include <asm/arch/sci/sci.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch-imx/cpu.h>
#include <asm/armv8/cpu.h>
#include <asm/armv8/mmu.h>
#include <asm/mach-imx/boot_mode.h>
#define BT_PASSOVER_TAG	0x504F
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_ENV_IS_IN_MMC
#endif
#define MEMSTART_ALIGNMENT  SZ_2M /* Align the memory start with 2MB */
#define MAX_PTE_ENTRIES 512
#define MAX_MEM_MAP_REGIONS 16
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#if defined(CONFIG_IMX8QM)
#define FUSE_MAC0_WORD0 452
#define FUSE_MAC0_WORD1 453
#define FUSE_MAC1_WORD0 454
#define FUSE_MAC1_WORD1 455
#elif defined(CONFIG_IMX8QXP)
#define FUSE_MAC0_WORD0 708
#define FUSE_MAC0_WORD1 709
#define FUSE_MAC1_WORD0 710
#define FUSE_MAC1_WORD1 711
#endif
