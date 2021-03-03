#include <common.h>
#include <adc.h>
#include <asm/io.h>
#include <asm/arch-rockchip/boot_mode.h>
#if (CONFIG_ROCKCHIP_BOOT_MODE_REG == 0)
#else
#define KEY_DOWN_MIN_VAL	0
#define KEY_DOWN_MAX_VAL	30
#endif
