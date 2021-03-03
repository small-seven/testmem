#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/gpio.h>
#include <asm/io.h>
#define GPIO_CONFIG_OFF(no)         ((no) * 0x1000)
#define GPIO_IN_OUT_OFF(no)         ((no) * 0x1000 + 0x4)
#define GPIO_OE_DISABLE  (0x0 << 9)
#define GPIO_OE_ENABLE   (0x1 << 9)
#define GPIO_OE_MASK     (0x1 << 9)
#define GPIO_IN          0
#define GPIO_OUT         1
