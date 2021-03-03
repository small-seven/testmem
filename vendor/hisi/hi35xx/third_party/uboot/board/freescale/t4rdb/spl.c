#include <common.h>
#include <console.h>
#include <env_internal.h>
#include <asm/spl.h>
#include <malloc.h>
#include <ns16550.h>
#include <nand.h>
#include <mmc.h>
#include <fsl_esdhc.h>
#include <i2c.h>
#include "t4rdb.h"
#define FSL_CORENET_CCSR_PORSR1_RCW_MASK	0xFF800000
