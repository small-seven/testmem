#include <common.h>
#include <asm/io.h>
#include <memalign.h>
#include <nand.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <dm.h>
#include "brcmnand.h"
#define BCM6838_NAND_INT		0x00
#define  BCM6838_NAND_STATUS_SHIFT	0
#define  BCM6838_NAND_STATUS_MASK	(0xfff << BCM6838_NAND_STATUS_SHIFT)
#define  BCM6838_NAND_ENABLE_SHIFT	16
#define  BCM6838_NAND_ENABLE_MASK	(0xffff << BCM6838_NAND_ENABLE_SHIFT)
