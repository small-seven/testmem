#include <stdint.h>
#include <stdio.h>
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavcodec/get_bits.h"
#include "libavcodec/golomb.h"
#include "libavcodec/put_bits.h"
#define COUNT 8191
#define SIZE (COUNT * 4)
#define EXTEND(i) ((i) << 3 | (i) & 7)
#define EXTEND_L(i) ((i) << 4 | (i) & 15)
