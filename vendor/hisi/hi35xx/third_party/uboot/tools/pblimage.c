#include "imagetool.h"
#include <image.h>
#include "pblimage.h"
#include "pbl_crc32.h"
#include <u-boot/crc.h>
#define roundup(x, y)		((((x) + ((y) - 1)) / (y)) * (y))
#define PBL_ACS_CONT_CMD	0x81000000
#define PBL_ADDR_24BIT_MASK	0x00ffffff
#define ENDIANNESS ((char)endian_test.l)
