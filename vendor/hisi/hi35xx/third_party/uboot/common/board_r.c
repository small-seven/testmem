#include <common.h>
#include <api.h>
#include <cpu_func.h>
#include <irq_func.h>
#include <u-boot/crc.h>
#if defined(CONFIG_CMD_BEDBUG)
#include <bedbug/type.h>
#endif
#include <command.h>
#include <console.h>
#include <dm.h>
#include <env.h>
#include <env_internal.h>
#include <fdtdec.h>
#include <ide.h>
#include <initcall.h>
#if defined(CONFIG_CMD_KGDB)
#include <kgdb.h>
#endif
#include <irq_func.h>
#include <malloc.h>
#include <mapmem.h>
#ifdef CONFIG_BITBANGMII
#include <miiphy.h>
#endif
#include <mmc.h>
#include <nand.h>
#include <of_live.h>
#include <onenand_uboot.h>
#include <scsi.h>
#include <serial.h>
#include <status_led.h>
#include <stdio_dev.h>
#include <timer.h>
#include <trace.h>
#include <watchdog.h>
#ifdef CONFIG_ADDR_MAP
#include <asm/mmu.h>
#endif
#include <asm/sections.h>
#include <dm/root.h>
#include <linux/compiler.h>
#include <linux/err.h>
#include <efi_loader.h>
#include <wdt.h>
#if defined(CONFIG_GPIO_HOG)
#include <asm/gpio.h>
#endif
#ifdef CONFIG_CMD_SF
#include <spi_flash.h>
#include <ufs.h>
#endif
#ifndef CONFIG_MINI_BOOT
#endif  /* CONFIG_MINI_BOOT */
#ifdef CONFIG_TRACE
#endif
#ifndef CONFIG_MINI_BOOT
#endif  /* CONFIG_MINI_BOOT */
#ifdef CONFIG_ARM
#endif
#ifdef __ARM__
#elif defined(CONFIG_NDS32) || defined(CONFIG_RISCV)
#elif !defined(CONFIG_SANDBOX) && !defined(CONFIG_NIOS2)
#endif
#if defined(CONFIG_MPC85xx) || defined(CONFIG_MPC86xx)
#endif
#ifdef CONFIG_SYS_RELOC_GD_ENV_ADDR
#endif
#ifdef CONFIG_OF_EMBED
#endif
#ifdef CONFIG_EFI_LOADER
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_M68K) || defined(CONFIG_MIPS)
#if defined(CONFIG_PPC)
#else
#endif
#endif
#ifdef CONFIG_ADDR_MAP
#endif
#ifdef CONFIG_POST
#endif
#if defined(CONFIG_SYS_INIT_RAM_LOCK) && defined(CONFIG_E500)
#endif
#ifdef CONFIG_PCI
#ifndef CONFIG_DM_PCI
#endif
#endif
#ifdef CONFIG_PPC
#endif
static int initr_malloc(void)
{
	ulong malloc_start;

#if CONFIG_VAL(SYS_MALLOC_F_LEN)
	debug("Pre-reloc malloc() used %#lx bytes (%ld KB)\n", gd->malloc_ptr,
	      gd->malloc_ptr / 1024);
#endif
	/* The malloc area is immediately below the monitor copy in DRAM */
	/*
	 * This value MUST match the value of gd->start_addr_sp in board_f.c:
	 * reserve_noncached().
	 */
	malloc_start = gd->relocaddr - TOTAL_MALLOC_LEN;
	mem_malloc_init((ulong)map_sysmem(malloc_start, TOTAL_MALLOC_LEN),
			TOTAL_MALLOC_LEN);
	return 0;
}
#if defined(CONFIG_CONSOLE_RECORD)
#else
#endif
#ifdef CONFIG_SYS_NONCACHED_MEMORY
#endif
#ifdef CONFIG_OF_LIVE
#endif
#ifdef CONFIG_DM
#ifdef CONFIG_TIMER
#endif
#ifdef CONFIG_TIMER_EARLY
#endif
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#if defined(CONFIG_MTD_NOR_FLASH)
#ifdef CONFIG_SYS_FLASH_CHECKSUM
#endif /* CONFIG_SYS_FLASH_CHECKSUM */
#ifdef CONFIG_SYS_FLASH_BASE
#endif
#if defined(CONFIG_SYS_UPDATE_FLASH_SIZE)
#endif
#if defined(CONFIG_OXC) || defined(CONFIG_RMU)
#elif CONFIG_SYS_MONITOR_BASE == CONFIG_SYS_FLASH_BASE
#endif
#endif
#ifdef CONFIG_CMD_SF
#ifndef CONFIG_ENV_SPI_BUS
# define CONFIG_ENV_SPI_BUS 0
#endif
#ifndef CONFIG_ENV_SPI_CS
# define CONFIG_ENV_SPI_CS  0
#endif
#ifndef CONFIG_ENV_SPI_MAX_HZ
# define CONFIG_ENV_SPI_MAX_HZ  1000000
#endif
#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE    SPI_MODE_3
#endif
#endif /* CONFIG_CMD_SF */
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_GENERIC_UFS
#endif
#if defined(CONFIG_CMD_ONENAND)
#endif
#ifdef CONFIG_MMC
#endif
#ifndef CONFIG_MINI_BOOT
#ifdef CONFIG_OF_CONTROL
#elif defined CONFIG_DELAY_ENVIRONMENT
#else
#endif
#ifdef CONFIG_OF_CONTROL
#endif
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_SYS_BOOTPARAMS_LEN
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#if defined(CONFIG_API)
#endif
#ifndef CONFIG_MINI_BOOT
#ifdef CONFIG_ARM
#endif
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_CMD_NET
#ifdef CONFIG_HAS_ETH1
#endif
#ifdef CONFIG_HAS_ETH2
#endif
#ifdef CONFIG_HAS_ETH3
#endif
#ifdef CONFIG_HAS_ETH4
#endif
#ifdef CONFIG_HAS_ETH5
#endif
#endif /* CONFIG_CMD_NET */
#ifdef CONFIG_CMD_KGDB
#endif
#if defined(CONFIG_LED_STATUS)
#if defined(CONFIG_LED_STATUS_BOOT)
#else
#endif
#endif
#if defined(CONFIG_SCSI) && !defined(CONFIG_DM_SCSI)
#endif
#ifdef CONFIG_BITBANGMII
#endif
#ifdef CONFIG_CMD_NET
#if defined(CONFIG_RESET_PHY_R)
#endif
#endif
#ifdef CONFIG_POST
#endif
#if defined(CONFIG_IDE) && !defined(CONFIG_BLK)
#if defined(CONFIG_START_IDE)
#else
#endif
#endif
#if defined(CONFIG_PRAM)
#endif
#ifdef CONFIG_CMD_BEDBUG
#endif
#ifndef CONFIG_HISI_DISABLE_DOWNLOAD
#endif
#ifdef CONFIG_SANDBOX
#endif
#ifdef CONFIG_MINI_BOOT
#endif
#ifdef CONFIG_ARM
#endif
#if defined(CONFIG_SYS_INIT_RAM_LOCK) && defined(CONFIG_E500)
#endif
#ifdef CONFIG_SYS_NONCACHED_MEMORY
#endif
#ifdef CONFIG_OF_LIVE
#endif
#ifdef CONFIG_DM
#endif
#if defined(CONFIG_ARM) || defined(CONFIG_NDS32) || defined(CONFIG_RISCV) || \
#endif
#ifdef CONFIG_CLOCKS
#endif
#ifdef CONFIG_EFI_LOADER
#endif
#if CONFIG_IS_ENABLED(WDT)
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_M68K) || defined(CONFIG_MIPS)
#endif
#ifdef CONFIG_ADDR_MAP
#endif
#if defined(CONFIG_BOARD_EARLY_INIT_R)
#endif
#ifdef CONFIG_POST
#endif
#if defined(CONFIG_PCI) && defined(CONFIG_SYS_EARLY_PCI_INIT)
#endif
#ifdef CONFIG_ARCH_EARLY_INIT_R
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_M68K) || defined(CONFIG_X86)
#endif
#ifdef CONFIG_CMD_SF
#endif 
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_ONENAND
#endif
#ifdef CONFIG_MMC
#endif
#ifdef CONFIG_GENERIC_UFS
#endif
#ifndef CONFIG_MINI_BOOT
#endif 
#ifdef CONFIG_SYS_BOOTPARAMS_LEN
#endif
#ifndef CONFIG_MINI_BOOT
#endif 
#if defined(CONFIG_ID_EEPROM) || defined(CONFIG_SYS_I2C_MAC_OFFSET)
#endif
#if defined(CONFIG_PCI) && !defined(CONFIG_SYS_EARLY_PCI_INIT)
#endif
#ifndef CONFIG_MINI_BOOT
#endif 
#ifdef CONFIG_API
#endif
#ifdef CONFIG_DISPLAY_BOARDINFO_LATE
#endif
#ifdef CONFIG_ARCH_MISC_INIT
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
#ifdef CONFIG_CMD_KGDB
#endif
#ifndef CONFIG_MINI_BOOT
#endif
#ifdef CONFIG_ARM
#ifndef CONFIG_MINI_BOOT
#endif
#endif
#if defined(CONFIG_MICROBLAZE) || defined(CONFIG_M68K)
#endif
#if defined(CONFIG_LED_STATUS)
#endif
#ifdef CONFIG_CMD_NET
#endif
#if defined(CONFIG_GPIO_HOG)
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif
#if defined(CONFIG_SCSI) && !defined(CONFIG_DM_SCSI)
#endif
#ifdef CONFIG_BITBANGMII
#endif
#ifdef CONFIG_CMD_NET
#endif
#ifdef CONFIG_POST
#endif
#if defined(CONFIG_IDE) && !defined(CONFIG_BLK)
#endif
#ifdef CONFIG_LAST_STAGE_INIT
#endif
#ifdef CONFIG_CMD_BEDBUG
#endif
#if defined(CONFIG_PRAM)
#endif
#ifdef CONFIG_MINI_BOOT
#endif
#if CONFIG_IS_ENABLED(X86_64)
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#if !defined(CONFIG_X86) && !defined(CONFIG_ARM) && !defined(CONFIG_ARM64)
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
