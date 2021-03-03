#define LOG_CATEGORY UCLASS_SPI
#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <spi_flash.h>
#include <os.h>
#include <linux/errno.h>
#include <asm/spi.h>
#include <asm/state.h>
#include <dm/device-internal.h>
#ifndef CONFIG_SPI_IDLE_VAL
# define CONFIG_SPI_IDLE_VAL 0xFF
#endif
