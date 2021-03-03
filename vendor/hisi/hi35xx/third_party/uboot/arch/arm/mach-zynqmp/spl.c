#include <common.h>
#include <debug_uart.h>
#include <init.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/spl.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_DEBUG_UART
#endif
#ifndef MODE_RESET
# define MODE_RESET	PS_MODE1
#endif
#ifdef CONFIG_SPL_BOARD_INIT
#endif
#if defined(CONFIG_SPL_ZYNQMP_ALT_BOOTMODE_ENABLED)
#endif
#ifdef CONFIG_SPL_MMC_SUPPORT
#ifdef CONFIG_SPL_ZYNQMP_TWO_SDHCI
#endif
#endif
#ifdef CONFIG_SPL_DFU
#endif
#ifdef CONFIG_SPL_SATA_SUPPORT
#endif
#ifdef CONFIG_SPL_SPI_SUPPORT
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
