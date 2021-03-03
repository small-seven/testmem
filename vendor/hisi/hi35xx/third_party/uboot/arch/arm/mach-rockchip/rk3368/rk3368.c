#include <common.h>
#include <syscon.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3368.h>
#include <asm/arch-rockchip/grf_rk3368.h>
#include <asm/arch-rockchip/hardware.h>
#define IMEM_BASE                  0xFF8C0000
#define MCU_SRAM_BASE			(IMEM_BASE + 1024 * 4)
#define MCU_SRAM_BASE_BIT31_BIT28	((MCU_SRAM_BASE & GENMASK(31, 28)) >> 28)
#define MCU_SRAM_BASE_BIT27_BIT12	((MCU_SRAM_BASE & GENMASK(27, 12)) >> 12)
#define MCU_EXSRAM_BASE    (0)
#define MCU_EXSRAM_BASE_BIT31_BIT28       ((MCU_EXSRAM_BASE & GENMASK(31, 28)) >> 28)
#define MCU_EXSRAM_BASE_BIT27_BIT12       ((MCU_EXSRAM_BASE & GENMASK(27, 12)) >> 12)
#define MCU_EXPERI_BASE    (0)
#define MCU_EXPERI_BASE_BIT31_BIT28       ((MCU_EXPERI_BASE & GENMASK(31, 28)) >> 28)
#define MCU_EXPERI_BASE_BIT27_BIT12       ((MCU_EXPERI_BASE & GENMASK(27, 12)) >> 12)
#ifdef CONFIG_ARCH_EARLY_INIT_R
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#if defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff180000)
#elif defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff1c0000)
#elif defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff690000)
#endif
#endif
