#include <stdio.h>
#include <stdlib.h>
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "lcl.h"
#include "thread.h"
#if CONFIG_ZLIB_DECODER
#include <zlib.h>
#endif
typedef struct LclDecContext {
    // Image type
    int imgtype;
    // Compression type
    int compression;
    // Flags
    int flags;
    // Decompressed data size
    unsigned int decomp_size;
    // Decompression buffer
    unsigned char* decomp_buf;
#if CONFIG_ZLIB_DECODER
    z_stream zstream;
#endif
} LclDecContext;
#if CONFIG_ZLIB_DECODER
#endif
#if CONFIG_ZLIB_DECODER
#endif
#if CONFIG_ZLIB_DECODER
#endif
#if CONFIG_ZLIB_DECODER
#endif
#if HAVE_THREADS
#endif
#if CONFIG_ZLIB_DECODER
#endif
#if CONFIG_MSZH_DECODER
#endif
#if CONFIG_ZLIB_DECODER
#endif
