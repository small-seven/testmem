#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include <linux/types.h>
#include <dm.h>
#include <fdtdec.h>
#include <i2c.h>
#define I2C_DTRM_STA	(1 << 10)
#define I2C_DTRM_STO	(1 << 9)
#define I2C_DTRM_NACK	(1 << 8)
#define I2C_DTRM_RD	(1 << 0)
#define I2C_DREC_STS	(1 << 12)
#define I2C_DREC_LRB	(1 << 11)
#define I2C_DREC_LAB	(1 << 9)
#define I2C_BRST_FOEN	(1 << 1)
#define I2C_BRST_BRST	(1 << 0)
#define IOBUS_FREQ	100000000
