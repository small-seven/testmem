#include <common.h>
#include <dm.h>
#include <errno.h>
#include <led.h>
#include <asm/io.h>
#include <dm/lists.h>
#define LEDS_MAX		32
#define LEDS_WAIT		100
#define LED_MODE_REG		0x0
#define LED_MODE_OFF		0
#define LED_MODE_ON		1
#define LED_MODE_MASK		1
#define LED_CTRL_REG		0x4
#define LED_CTRL_CLK_MASK	0x3
#define LED_CTRL_CLK_1		0
#define LED_CTRL_CLK_2		1
#define LED_CTRL_CLK_4		2
#define LED_CTRL_CLK_8		3
#define LED_CTRL_POL_SHIFT	2
#define LED_CTRL_POL_MASK	(1 << LED_CTRL_POL_SHIFT)
#define LED_CTRL_BUSY_SHIFT	3
#define LED_CTRL_BUSY_MASK	(1 << LED_CTRL_BUSY_SHIFT)
