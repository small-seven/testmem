#include <common.h>
#include <console.h>
#include <env.h>
#include <env_internal.h>
#include <asm/spl.h>
#include <malloc.h>
#include <ns16550.h>
#include <nand.h>
#include <i2c.h>
#include "../common/qixis.h"
#include "b4860qds_qixis.h"
#ifndef CONFIG_SPL_NAND_BOOT
#else
#endif
#ifdef CONFIG_SPL_NAND_BOOT
#endif
