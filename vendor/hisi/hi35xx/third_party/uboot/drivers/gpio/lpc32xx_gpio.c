#include <common.h>
#include <asm/io.h>
#include <asm/arch-lpc32xx/cpu.h>
#include <asm/arch-lpc32xx/gpio.h>
#include <asm-generic/gpio.h>
#include <dm.h>
#define LPC32XX_GPIOS 160
#define MAX_GPIO 160
#define GPIO_TO_PORT(gpio) ((gpio / 32) & 7)
#define GPIO_TO_RANK(gpio) (gpio % 32)
#define GPIO_TO_MASK(gpio) (1 << (gpio % 32))
