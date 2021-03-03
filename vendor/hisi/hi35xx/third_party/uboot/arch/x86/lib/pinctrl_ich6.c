#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <pch.h>
#include <pci.h>
#include <asm/cpu.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/pci.h>
#include <dm/pinctrl.h>
#define GPIO_USESEL_OFFSET(x)	(x)
#define GPIO_IOSEL_OFFSET(x)	(x + 4)
#define GPIO_LVL_OFFSET(x)	((x) ? (x) + 8 : 0xc)
#define GPI_INV			0x2c
#define IOPAD_MODE_MASK			0x7
#define IOPAD_PULL_ASSIGN_SHIFT		7
#define IOPAD_PULL_ASSIGN_MASK		(0x3 << IOPAD_PULL_ASSIGN_SHIFT)
#define IOPAD_PULL_STRENGTH_SHIFT	9
#define IOPAD_PULL_STRENGTH_MASK	(0x3 << IOPAD_PULL_STRENGTH_SHIFT)
