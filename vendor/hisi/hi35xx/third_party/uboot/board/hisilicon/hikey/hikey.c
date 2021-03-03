#include <common.h>
#include <dm.h>
#include <dm/platform_data/serial_pl01x.h>
#include <errno.h>
#include <malloc.h>
#include <netdev.h>
#include <asm/io.h>
#include <usb.h>
#include <power/hi6553_pmic.h>
#include <asm-generic/gpio.h>
#include <asm/arch/dwmmc.h>
#include <asm/arch/gpio.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/hi6220.h>
#include <asm/armv8/mmu.h>
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#if CONFIG_CONS_INDEX == 1
#elif CONFIG_CONS_INDEX == 4
#else
#error "Unsupported console index value."
#endif
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
#define STAT_EN_OFF 0x2
#define STAT_DIS_OFF 0x1
#define EYE_PATTERN	0x70533483
#ifdef CONFIG_MMC
#ifdef CONFIG_MMC_DW
#endif
#endif
