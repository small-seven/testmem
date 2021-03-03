#ifndef __UBOOT__
#include <linux/crc32.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <asm/div64.h>
#include <u-boot/crc.h>
#else
#include <ubi_uboot.h>
#endif
#include <linux/err.h>
#include "ubi.h"
#ifndef __UBOOT__
#else
#endif
