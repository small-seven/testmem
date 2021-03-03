#include <common.h>
#include <config.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/pinctrl.h>
#include <dm/root.h>
#include <errno.h>
#include <fdtdec.h>
#include <regmap.h>
#include <asm/gpio.h>
#include <asm/system.h>
#include <asm/io.h>
#define OUTPUT_EN	0x0
#define INPUT_VAL	0x10
#define OUTPUT_VAL	0x18
#define OUTPUT_CTL	0x20
#define SELECTION	0x30
#define IRQ_EN		0x0
#define IRQ_POL		0x08
#define IRQ_STATUS	0x10
#define IRQ_WKUP	0x18
#define NB_FUNCS 3
#define GPIO_PER_REG	32
#define PIN_GRP(_name, _start, _nr, _mask, _func1, _func2)	\
#define PIN_GRP_GPIO(_name, _start, _nr, _mask, _func1)	\
#define PIN_GRP_GPIO_2(_name, _start, _nr, _mask, _val1, _val2, _func1)   \
#define PIN_GRP_GPIO_3(_name, _start, _nr, _mask, _v1, _v2, _v3, _f1, _f2) \
#define PIN_GRP_EXTRA(_name, _start, _nr, _mask, _v1, _v2, _start2, _nr2, \
