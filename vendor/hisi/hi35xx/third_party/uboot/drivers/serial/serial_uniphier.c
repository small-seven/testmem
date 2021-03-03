#include <common.h>
#include <dm.h>
#include <linux/bug.h>
#include <linux/io.h>
#include <linux/serial_reg.h>
#include <linux/sizes.h>
#include <linux/errno.h>
#include <serial.h>
#include <fdtdec.h>
#define tx rx			/* Out: Transmit buffer */
#define LCR_SHIFT	8
#define LCR_MASK	(0xff << (LCR_SHIFT))
#define uniphier_serial_port(dev)	\
