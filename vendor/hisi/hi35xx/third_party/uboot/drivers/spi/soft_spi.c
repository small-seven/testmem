#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <spi.h>
#include <asm/gpio.h>
#define SPI_MASTER_NO_RX        BIT(0)
#define SPI_MASTER_NO_TX        BIT(1)
