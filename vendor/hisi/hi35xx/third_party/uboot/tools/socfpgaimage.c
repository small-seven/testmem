#include "pbl_crc32.h"
#include "imagetool.h"
#include "mkimage.h"
#include <u-boot/crc.h>
#include <image.h>
#define HEADER_OFFSET	0x40
#define VALIDATION_WORD	0x31305341
