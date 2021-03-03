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
#define GPIO_PER_BANK	32
#define GPIO_USESEL_OFFSET(x)	(x)
#define GPIO_IOSEL_OFFSET(x)	(x + 4)
#define GPIO_LVL_OFFSET(x)	(x + 8)
