#include <common.h>
#include <bloblist.h>
#include <console.h>
#include <cpu.h>
#include <cpu_func.h>
#include <dm.h>
#include <env.h>
#include <env_internal.h>
#include <fdtdec.h>
#include <fs.h>
#include <i2c.h>
#include <init.h>
#include <initcall.h>
#include <lcd.h>
#include <malloc.h>
#include <mapmem.h>
#include <os.h>
#include <post.h>
#include <relocate.h>
#include <serial.h>
#ifdef CONFIG_SPL
#include <spl.h>
#endif
#include <status_led.h>
#include <sysreset.h>
#include <timer.h>
#include <trace.h>
#include <video.h>
#include <watchdog.h>
#ifdef CONFIG_MACH_TYPE
#include <asm/mach-types.h>
#endif
#if defined(CONFIG_MP) && defined(CONFIG_PPC)
#include <asm/mp.h>
#endif
#include <asm/io.h>
#include <asm/sections.h>
#include <dm/root.h>
#include <linux/errno.h>
#ifdef XTRN_DECLARE_GLOBAL_DATA_PTR
#undef	XTRN_DECLARE_GLOBAL_DATA_PTR
#define XTRN_DECLARE_GLOBAL_DATA_PTR	/* empty = allocate here */
#else
#endif
#if defined(CONFIG_WATCHDOG) || defined(CONFIG_HW_WATCHDOG)
# if defined(CONFIG_HW_WATCHDOG) && \
# endif
#endif /* CONFIG_WATCHDOG */
#ifndef CONFIG_MINI_BOOT
#if !defined(CONFIG_SANDBOX) && !defined(CONFIG_EFI_APP)
#ifdef CONFIG_SYS_TEXT_BASE
#else
#endif
#endif
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_SYSRESET
#endif
#if defined(CONFIG_DISPLAY_CPUINFO) && CONFIG_IS_ENABLED(CPU)
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_NR_DRAM_BANKS
#ifdef DEBUG
#endif
#else
#endif
#if defined(CONFIG_NR_DRAM_BANKS) && defined(CONFIG_SYS_SDRAM_BASE)
#endif
#if defined(CONFIG_SYS_I2C)
#ifdef CONFIG_SYS_I2C
#else
#endif
#endif
#if defined(CONFIG_VID)
#endif
#if defined(__ARM__) || defined(__MICROBLAZE__)
#elif defined(CONFIG_SANDBOX) || defined(CONFIG_EFI_APP)
#elif defined(CONFIG_NIOS2) || defined(CONFIG_XTENSA)
#elif defined(CONFIG_NDS32) || defined(CONFIG_SH) || defined(CONFIG_RISCV)
#elif defined(CONFIG_SYS_MONITOR_BASE)
#endif
#if CONFIG_IS_ENABLED(HANDOFF)
#endif
#ifdef CONFIG_SYS_SDRAM_BASE
#endif
#if defined(CONFIG_SYS_MEM_TOP_HIDE)
#endif
#ifdef CONFIG_SYS_SDRAM_BASE
#endif
#if defined(CONFIG_MP) && (defined(CONFIG_MPC86xx) || defined(CONFIG_E500))
#endif
#ifdef CONFIG_PRAM
#endif /* CONFIG_PRAM */
#ifdef CONFIG_ARM
#if !(CONFIG_IS_ENABLED(SYS_ICACHE_OFF) && CONFIG_IS_ENABLED(SYS_DCACHE_OFF))
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#endif
#endif
#endif
#ifdef CONFIG_DM_VIDEO
#elif defined(CONFIG_LCD)
#  ifdef CONFIG_FB_ADDR
#  else
#  endif /* CONFIG_FB_ADDR */
#endif
#ifdef CONFIG_TRACE
#endif
#ifdef CONFIG_SYS_NONCACHED_MEMORY
#endif
static int reserve_malloc(void)
{
	gd->start_addr_sp = gd->start_addr_sp - TOTAL_MALLOC_LEN;
	debug("Reserving %dk for malloc() at: %08lx\n",
	      TOTAL_MALLOC_LEN >> 10, gd->start_addr_sp);
#ifdef CONFIG_SYS_NONCACHED_MEMORY
	reserve_noncached();
#endif

	return 0;
}
#ifdef CONFIG_MACH_TYPE
#endif
#ifndef CONFIG_OF_EMBED
#endif
#ifdef CONFIG_BOOTSTAGE
#endif
#ifdef CONFIG_BLOBLIST
#endif
#if defined(CONFIG_M68K) || defined(CONFIG_MIPS) || defined(CONFIG_PPC) || \
#ifdef CONFIG_SYS_SRAM_BASE
#endif
#if defined(CONFIG_E500) || defined(CONFIG_MPC86xx)
#endif
#if defined(CONFIG_M68K)
#endif
#if defined(CONFIG_MPC83xx)
#endif
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_M68K)
#if defined(CONFIG_CPM2)
#endif /* CONFIG_CPM2 */
#if defined(CONFIG_M68K) && defined(CONFIG_PCI)
#endif
#if defined(CONFIG_EXTRA_CLOCK)
#endif
#endif
#ifdef CONFIG_POST
#endif
#ifndef CONFIG_OF_EMBED
#endif
#ifdef CONFIG_BOOTSTAGE
#endif
#ifdef CONFIG_BLOBLIST
#endif
#ifdef CONFIG_SYS_TEXT_BASE
#ifdef ARM
#elif defined(CONFIG_M68K)
#elif !defined(CONFIG_SANDBOX)
#endif
#endif
#ifndef CONFIG_MINI_BOOT
#endif
#ifdef CONFIG_OF_BOARD_FIXUP
#endif
#if !defined(CONFIG_ARM) && !defined(CONFIG_SANDBOX) && \
#if defined(CONFIG_X86) || defined(CONFIG_ARC)
#else
#endif
#endif
#if defined(CONFIG_CONSOLE_RECORD) && CONFIG_VAL(SYS_MALLOC_F_LEN)
#else
#endif
#if defined(CONFIG_DM) && CONFIG_VAL(SYS_MALLOC_F_LEN)
#endif
#ifdef CONFIG_TIMER_EARLY
#endif
#ifdef CONFIG_OF_CONTROL
#endif
#ifdef CONFIG_TRACE_EARLY
#endif
#ifdef CONFIG_BLOBLIST
#endif
#if defined(CONFIG_HAVE_FSP)
#endif
#if defined(CONFIG_BOARD_EARLY_INIT_F)
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_SYS_FSL_CLK) || defined(CONFIG_M68K)
#endif
#if !defined(CONFIG_M68K)
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#endif
#if defined(CONFIG_BOARD_POSTCLK_INIT)
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#if defined(CONFIG_PPC) || defined(CONFIG_SH) || defined(CONFIG_X86)
#endif
#if defined(CONFIG_SYSRESET)
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#endif
#if defined(CONFIG_DTB_RESELECT)
#endif
#if defined(CONFIG_DISPLAY_BOARDINFO)
#endif
#if defined(CONFIG_MISC_INIT_F)
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#if defined(CONFIG_SYS_I2C)
#endif
#if defined(CONFIG_VID) && !defined(CONFIG_SPL)
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_POST
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#if defined(CONFIG_SYS_DRAM_TEST)
#endif /* CONFIG_SYS_DRAM_TEST */
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_POST
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_PRAM
#endif
#ifdef CONFIG_ARM
#endif
#if defined(CONFIG_M68K) || defined(CONFIG_MIPS) || defined(CONFIG_PPC) || \
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_M68K)
#endif
#ifdef CONFIG_OF_BOARD_FIXUP
#endif
#if defined(CONFIG_X86) || defined(CONFIG_ARC)
#endif
#if defined(CONFIG_XTENSA)
#endif
#if !defined(CONFIG_ARM) && !defined(CONFIG_SANDBOX) && \
#endif
#if !defined(CONFIG_ARM) && !defined(CONFIG_SANDBOX) && \
#endif
#if defined(CONFIG_X86) || defined(CONFIG_ARC)
#if !CONFIG_IS_ENABLED(X86_64)
#endif
#ifdef CONFIG_TIMER
#endif
#endif /* CONFIG_X86 */
