#include <common.h>
#include <watchdog.h>
#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include "linux/mtd/flashchip.h"
#include <linux/mtd/onenand.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <malloc.h>
#ifdef CONFIG_MTD_ONENAND_VERIFY_WRITE
#else
#define onenand_verify(...)             (0)
#define onenand_verify_oob(...)         (0)
#endif
#define NOTALIGNED(x)	((x & (this->subpagesize - 1)) != 0)
#ifdef ONENAND_LINUX
#endif
#ifdef ONENAND_DEBUG
#endif
#ifdef ONENAND_DEBUG
#endif
