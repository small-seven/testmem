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
#include <asm/arch/gpio.h>
#include <dt-bindings/gpio/x86-gpio.h>
#include <dm/pinctrl.h>
#include <dm/uclass-internal.h>
#define PIRQ_SHIFT	16
#define CONF_MASK	0xffff
