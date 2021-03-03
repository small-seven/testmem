#include <common.h>
#include <asm/io.h>
#include <memalign.h>
#include <nand.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <dm.h>
#include "brcmnand.h"
#define BCM63158_NAND_INT		0x00
#define BCM63158_NAND_STATUS_SHIFT	0
#define BCM63158_NAND_STATUS_MASK	(0xfff << BCM63158_NAND_STATUS_SHIFT)
#define BCM63158_NAND_INT_EN		0x04
#define BCM63158_NAND_ENABLE_SHIFT	0
#define BCM63158_NAND_ENABLE_MASK	(0xffff << BCM63158_NAND_ENABLE_SHIFT)
