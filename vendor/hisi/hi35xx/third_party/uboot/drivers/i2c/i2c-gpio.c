#include <common.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <asm/gpio.h>
#define DEFAULT_UDELAY	5
#define RETRIES		0
#define I2C_ACK		0
#define I2C_NOACK	1
