#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <spi.h>
#include <dm.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <linux/delay.h>
#define hold_time_delay() mscc_vcoreiii_nop_delay(3)
