#define PROGRAM_NAME "jffs2dump"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <asm/types.h>
#include <dirent.h>
#include <mtd/jffs2-user.h>
#include <endian.h>
#include <byteswap.h>
#include <getopt.h>
#include <crc32.h>
#include "summary.h"
#include "common.h"
#define PAD(x) (((x)+3)&~3)
#define cnv_e32(x) ((jint32_t){bswap_32(x.v32)})
#define cnv_e16(x) ((jint16_t){bswap_16(x.v16)})
#define t32_backwards(x) ({ uint32_t __b = (x); (target_endian==__BYTE_ORDER)?bswap_32(__b):__b; })
#define cpu_to_e32(x) ((jint32_t){t32_backwards(x)})
