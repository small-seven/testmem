#include <common.h>
#include <console.h>
#include <dm.h>
#include <fdtdec.h>
#include <lcd.h>
#include <os.h>
#include <serial.h>
#include <video.h>
#include <linux/compiler.h>
#include <asm/state.h>
#if CONFIG_IS_ENABLED(OF_CONTROL)
static int sandbox_serial_remove(struct udevice *dev)
{
	struct sandbox_serial_platdata *plat = dev->platdata;

	if (plat->colour != -1)
		output_ansi_reset();

	return 0;
}
#ifndef CONFIG_SPL_BUILD
#endif
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
#ifdef CONFIG_DEBUG_UART_SANDBOX
#include <debug_uart.h>
#endif /* CONFIG_DEBUG_UART_SANDBOX */
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
