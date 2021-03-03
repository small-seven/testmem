#ifndef USE_HOSTCC
#include <common.h>
#include <fdtdec.h>
#include <asm/types.h>
#include <asm/byteorder.h>
#include <linux/errno.h>
#include <asm/types.h>
#include <asm/unaligned.h>
#else
#include "fdt_host.h"
#include "mkimage.h"
#include <fdt_support.h>
#endif
#include <u-boot/rsa.h>
#include <u-boot/rsa-mod-exp.h>
#define UINT64_MULT32(v, multby)  (((uint64_t)(v)) * ((uint32_t)(multby)))
#define get_unaligned_be32(a) fdt32_to_cpu(*(uint32_t *)a)
#define put_unaligned_be32(a, b) (*(uint32_t *)(b) = cpu_to_fdt32(a))
#define RSA_DEFAULT_PUBEXP	65537
#if defined(CONFIG_CMD_ZYNQ_RSA)
#endif
