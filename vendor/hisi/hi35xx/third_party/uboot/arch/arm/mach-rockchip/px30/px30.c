#include <common.h>
#include <clk.h>
#include <dm.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch-rockchip/grf_px30.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/arch-rockchip/uart.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_px30.h>
#include <dt-bindings/clock/px30-cru.h>
#define PMU_PWRDN_CON			0xff000018
#define PMUGRF_BASE			0xff010000
#define GRF_BASE			0xff140000
#define CRU_BASE			0xff2b0000
#define VIDEO_PHY_BASE			0xff2e0000
#define SERVICE_CORE_ADDR		0xff508000
#define DDR_FW_BASE			0xff534000
#define FW_DDR_CON			0x40
#define QOS_PRIORITY			0x08
#define QOS_PRIORITY_LEVEL(h, l)	((((h) & 3) << 8) | ((l) & 3))
#ifdef CONFIG_SPL_BUILD
#if !defined(CONFIG_DEBUG_UART_BOARD_INIT) || \
#endif
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#if defined(CONFIG_DEBUG_UART_BASE) && \
#endif
#if defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff158000)
#elif defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff168000)
#if (CONFIG_DEBUG_UART_CHANNEL == 1)
#else
#endif /* CONFIG_DEBUG_UART_CHANNEL == 1 */
#elif defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff178000)
#else
#if (CONFIG_DEBUG_UART_CHANNEL == 1)
#else
#endif /* CONFIG_DEBUG_UART_CHANNEL == 1 */
#endif /* CONFIG_DEBUG_UART_BASE && CONFIG_DEBUG_UART_BASE == ... */
#endif /* CONFIG_DEBUG_UART_BOARD_INIT */
