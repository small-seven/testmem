#include <common.h>
#include <adc.h>
#include <asm/io.h>
#include <asm/arch/grf_rk3308.h>
#include <asm/arch-rockchip/hardware.h>
#if defined(CONFIG_DEBUG_UART)
#define GRF_BASE	0xff000000
#endif
#define KEY_DOWN_MIN_VAL        0
#define KEY_DOWN_MAX_VAL        30
