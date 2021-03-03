#include <stdio.h>
#include <string.h>              /* for memset() */
#include <stdlib.h>
#include <inttypes.h>
#include "libavutil/mem.h"
#include "libswscale/swscale.h"
#include "libswscale/rgb2rgb.h"
#define SIZE    1000
#define srcByte 0x55
#define dstByte 0xBB
#define FUNC(s, d, n) { s, d, #n, n }
