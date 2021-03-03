#ifndef USE_HOSTCC
#include <common.h>
#include <fdtdec.h>
#include <asm/byteorder.h>
#include <linux/errno.h>
#include <asm/unaligned.h>
#include <hash.h>
#else
#include "fdt_host.h"
#endif
#include <u-boot/rsa.h>
