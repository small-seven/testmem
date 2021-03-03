#include <stdio.h>
#include <lzo/lzo1x.h>
#include "libavutil/log.h"
#include "libavutil/lzo.h"
#include "libavutil/mem.h"
#define MAXSZ (10*1024*1024)
#define BENCHMARK_LIBLZO_SAFE   0
#define BENCHMARK_LIBLZO_UNSAFE 0
#if BENCHMARK_LIBLZO_SAFE
#elif BENCHMARK_LIBLZO_UNSAFE
#else
#endif
