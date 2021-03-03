#include <common.h>
#include <sh_pfc.h>
#include <asm/arch/sh73a0-gpio.h>
#define CPU_ALL_PORT(fn, pfx, sfx)				\
#if 0
#define EXT_IRQ16L(n) intcs_evt2irq(0x200 + ((n) << 5))
#define EXT_IRQ16H(n) intcs_evt2irq(0x3200 + ((n - 16) << 5))
#else
#define EXT_IRQ16L(n) (n)
#define EXT_IRQ16H(n) (n)
#endif
