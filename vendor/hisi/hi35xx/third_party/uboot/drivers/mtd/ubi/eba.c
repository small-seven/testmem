#ifndef __UBOOT__
#include <linux/slab.h>
#include <linux/crc32.h>
#include <u-boot/crc.h>
#else
#include <ubi_uboot.h>
#endif
#include <linux/err.h>
#include "ubi.h"
#define EBA_RESERVED_PEBS 1
#ifndef __UBOOT__
#endif
