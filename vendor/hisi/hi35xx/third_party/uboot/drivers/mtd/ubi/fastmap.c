#ifndef __UBOOT__
#include <linux/crc32.h>
#include <u-boot/crc.h>
#else
#include <div64.h>
#include <malloc.h>
#include <ubi_uboot.h>
#endif
#include <linux/compat.h>
#include <linux/math64.h>
#include "ubi.h"
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
