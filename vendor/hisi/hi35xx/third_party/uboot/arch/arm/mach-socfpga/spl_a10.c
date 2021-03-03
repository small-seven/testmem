#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/pl310.h>
#include <asm/u-boot.h>
#include <asm/utils.h>
#include <image.h>
#include <asm/arch/reset_manager.h>
#include <spl.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/freeze_controller.h>
#include <asm/arch/clock_manager.h>
#include <asm/arch/scan_manager.h>
#include <asm/arch/sdram.h>
#include <asm/arch/scu.h>
#include <asm/arch/misc.h>
#include <asm/arch/nic301.h>
#include <asm/sections.h>
#include <fdtdec.h>
#include <watchdog.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/fpga_manager.h>
#include <mmc.h>
#include <memalign.h>
#define FPGA_BUFSIZ	16 * 1024
#ifdef CONFIG_SPL_MMC_SUPPORT
#if defined(CONFIG_SPL_FS_FAT) || defined(CONFIG_SPL_FS_EXT4)
#else
#endif
#endif
#ifdef CONFIG_HW_WATCHDOG
#endif /* CONFIG_HW_WATCHDOG */
