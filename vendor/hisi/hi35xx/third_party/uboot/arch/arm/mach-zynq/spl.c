#include <common.h>
#include <debug_uart.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/spl.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/ps7_init_gpl.h>
#ifdef CONFIG_DEBUG_UART
#endif
#ifdef CONFIG_SPL_BOARD_INIT
#if defined(CONFIG_ARCH_EARLY_INIT_R) && defined(CONFIG_SPL_FPGA_SUPPORT)
#endif
#endif
#ifdef CONFIG_SPL_SPI_SUPPORT
#endif
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
