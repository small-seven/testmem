#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fdtdec.h>
#include <spi.h>
#include <malloc.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/hardware.h>
#ifdef CONFIG_DM_SPI
#include <asm/arch/at91_spi.h>
#endif
#ifdef CONFIG_DM_GPIO
#include <asm/gpio.h>
#endif
#include "atmel_spi.h"
#ifndef CONFIG_DM_SPI
#ifdef ATMEL_BASE_SPI1
#endif
#ifdef ATMEL_BASE_SPI2
#endif
#ifdef ATMEL_BASE_SPI3
#endif
#else
#define MAX_CS_COUNT	4
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#endif
