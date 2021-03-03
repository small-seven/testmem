#include <common.h>
#include <asm/io.h>
#include <memalign.h>
#include <nand.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <dm.h>
#include "brcmnand.h"
#define soc_to_priv(_soc) container_of(_soc, struct bcm6368_nand_soc, soc)
#define BCM6368_NAND_INT		0x00
#define  BCM6368_NAND_STATUS_SHIFT	0
#define  BCM6368_NAND_STATUS_MASK	(0xfff << BCM6368_NAND_STATUS_SHIFT)
#define  BCM6368_NAND_ENABLE_SHIFT	16
#define  BCM6368_NAND_ENABLE_MASK	(0xffff << BCM6368_NAND_ENABLE_SHIFT)
