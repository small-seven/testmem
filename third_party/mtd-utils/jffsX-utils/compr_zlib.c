#define PROGRAM_NAME "compr_zlib"
#include <stdint.h>
#define crc32 __zlib_crc32
#include <zlib.h>
#undef crc32
#include <stdio.h>
#include <asm/types.h>
#include <linux/jffs2.h>
#include "common.h"
#include "compr.h"
#define STREAM_END_SPACE 12
