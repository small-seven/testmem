#include <common.h>
#include <clk.h>
#include <dm.h>
#include <mach/pic32.h>
#include <mach/ddr.h>
#include <dt-bindings/clock/microchip,clock.h>
#define PRECON          0x00
#define ECC_MASK	0x03
#define ECC_SHIFT	4
#define CLK_MHZ(x)	((x) / 1000000)
#ifdef CONFIG_DISPLAY_BOARDINFO
#endif
#ifdef CONFIG_CMD_CLK
#endif
