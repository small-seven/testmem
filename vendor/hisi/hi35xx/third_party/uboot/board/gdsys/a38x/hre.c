#include <common.h>
#include <malloc.h>
#include <fs.h>
#include <i2c.h>
#include <mmc.h>
#include <tpm-v1.h>
#include <u-boot/crc.h>
#include <u-boot/sha1.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <pca9698.h>
#include "hre.h"
#define IS_PCR_HREG(spec) ((spec) & 0x20)
#define IS_FIX_HREG(spec) (((spec) & 0x38) == 0x08)
#define IS_VAR_HREG(spec) (((spec) & 0x38) == 0x10)
#define HREG_IDX(spec) ((spec) & (IS_PCR_HREG(spec) ? 0x1f : 0x7))
