#include <common.h>
#include <errno.h>
#include <time.h>
#include <asm/arch/cpu.h>
#include <asm/arch/gpio.h>
#include <asm/arch/prcm.h>
#include <asm/arch/rsb.h>
#ifdef CONFIG_MACH_SUN8I
#elif defined CONFIG_MACH_SUN9I
#else
#error unsupported MACH_SUNXI
#endif
