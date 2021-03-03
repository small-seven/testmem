#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx7-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <common.h>
#include <linux/sizes.h>
#define UART_PAD_CTRL  (PAD_CTL_DSE_3P3V_49OHM | \
