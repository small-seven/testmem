#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <fdtdec.h>
#include <spi.h>
#include <asm/io.h>
#define ALTERA_SPI_STATUS_RRDY_MSK	BIT(7)
#define ALTERA_SPI_CONTROL_SSO_MSK	BIT(10)
#ifndef CONFIG_ALTERA_SPI_IDLE_VAL
#define CONFIG_ALTERA_SPI_IDLE_VAL	0xff
#endif
