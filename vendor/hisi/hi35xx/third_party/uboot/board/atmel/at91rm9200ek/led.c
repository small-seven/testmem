#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/clk.h>
#include <asm/arch/at91_pio.h>
#include <status_led.h>
#define	GREEN_LED	(1<<0)
#define	YELLOW_LED	(1<<1)
#define	RED_LED		(1<<2)
