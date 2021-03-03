#include <linux/errno.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#include <linux/sizes.h>
#include <linux/types.h>
#include <dm.h>
#include <i2c.h>
#include <fdtdec.h>
#define I2C_CR_MST	(1 << 3)	/* master mode */
#define I2C_CR_STA	(1 << 2)	/* start condition */
#define I2C_CR_STO	(1 << 1)	/* stop condition */
#define I2C_CR_NACK	(1 << 0)	/* not ACK */
#define dtrx		dttx		/* receive FIFO (read-only) */
#define I2C_DTTX_CMD	(1 << 8)	/* send command (slave addr) */
#define I2C_DTTX_RD	(1 << 0)	/* read */
#define I2C_INT_TE	(1 << 9)	/* TX FIFO empty */
#define I2C_INT_RB	(1 << 4)	/* received specified bytes */
#define I2C_INT_NA	(1 << 2)	/* no answer */
#define I2C_INT_AL	(1 << 1)	/* arbitration lost */
#define I2C_SR_DB	(1 << 12)	/* device busy */
#define I2C_SR_BB	(1 << 8)	/* bus busy */
#define I2C_SR_RFF	(1 << 3)	/* Rx FIFO full */
#define I2C_SR_RNE	(1 << 2)	/* Rx FIFO not empty */
#define I2C_SR_TNF	(1 << 1)	/* Tx FIFO not full */
#define I2C_SR_TFE	(1 << 0)	/* Tx FIFO empty */
#define I2C_RST_TBRST	(1 << 2)	/* clear Tx FIFO */
#define I2C_RST_RBRST	(1 << 1)	/* clear Rx FIFO */
#define I2C_RST_RST	(1 << 0)	/* forcible bus reset */
#define I2C_BRST_FOEN	(1 << 1)	/* normal operation */
#define I2C_BRST_RSCLO	(1 << 0)	/* release SCL low fixing */
#define FIOCLK	50000000
