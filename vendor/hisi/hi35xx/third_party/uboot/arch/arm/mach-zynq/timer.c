#include <clk.h>
#include <common.h>
#include <div64.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/clk.h>
#define SCUTIMER_CONTROL_PRESCALER_MASK	0x0000FF00 /* Prescaler */
#define SCUTIMER_CONTROL_PRESCALER_SHIFT	8
#define SCUTIMER_CONTROL_AUTO_RELOAD_MASK	0x00000002 /* Auto-reload */
#define SCUTIMER_CONTROL_ENABLE_MASK		0x00000001 /* Timer enable */
#define TIMER_LOAD_VAL 0xFFFFFFFF
#define TIMER_PRESCALE 255
