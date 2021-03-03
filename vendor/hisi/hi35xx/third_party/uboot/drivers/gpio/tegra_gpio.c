#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <errno.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <asm/bitops.h>
#include <asm/arch/tegra.h>
#include <asm/gpio.h>
#include <dm/device-internal.h>
#include <dt-bindings/gpio/gpio.h>
#ifdef CONFIG_SPL_BUILD
#else
#endif
