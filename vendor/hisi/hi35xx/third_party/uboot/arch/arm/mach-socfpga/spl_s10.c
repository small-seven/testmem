#include <asm/io.h>
#include <asm/u-boot.h>
#include <asm/utils.h>
#include <common.h>
#include <debug_uart.h>
#include <image.h>
#include <spl.h>
#include <asm/arch/clock_manager.h>
#include <asm/arch/firewall_s10.h>
#include <asm/arch/mailbox_s10.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/system_manager.h>
#include <watchdog.h>
#include <dm/uclass.h>
#ifdef CONFIG_SPL_MMC_SUPPORT
#if defined(CONFIG_SPL_FS_FAT) || defined(CONFIG_SPL_FS_EXT4)
#else
#endif
#endif
#ifdef CONFIG_HW_WATCHDOG
#endif
#ifdef CONFIG_DEBUG_UART
#endif
#if CONFIG_IS_ENABLED(ALTERA_SDRAM)
#endif
#ifdef CONFIG_CADENCE_QSPI
#endif
