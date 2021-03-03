#include <common.h>
#include <rtc.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#define HOUR_SHIFT 8
#define HOUR_MASK  0x1f
#define MIN_SHIFT  0
#define MIN_MASK   0x3f
