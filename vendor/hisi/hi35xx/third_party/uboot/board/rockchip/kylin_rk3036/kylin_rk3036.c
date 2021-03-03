#include <common.h>
#include <dm.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch-rockchip/uart.h>
#include <asm/arch-rockchip/sdram_rk3036.h>
#include <asm/gpio.h>
#define FASTBOOT_KEY_GPIO 93
#define ROCKCHIP_BOOT_MODE_FASTBOOT	0x5242C309
