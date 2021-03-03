#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <malloc.h>
#define GPIO_PER_BANK			32
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
