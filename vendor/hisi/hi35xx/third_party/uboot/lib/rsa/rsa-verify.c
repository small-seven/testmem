#ifndef USE_HOSTCC
#include <common.h>
#include <fdtdec.h>
#include <asm/types.h>
#include <asm/byteorder.h>
#include <linux/errno.h>
#include <asm/types.h>
#include <asm/unaligned.h>
#include <dm.h>
#else
#include "fdt_host.h"
#include "mkimage.h"
#include <fdt_support.h>
#endif
#include <u-boot/rsa-mod-exp.h>
#include <u-boot/rsa.h>
#define RSA_DEFAULT_PUBEXP	65537
#ifdef CONFIG_FIT_ENABLE_RSASSA_PSS_SUPPORT
#endif
#if !defined(USE_HOSTCC)
#endif
#if !defined(USE_HOSTCC)
#else
#endif
