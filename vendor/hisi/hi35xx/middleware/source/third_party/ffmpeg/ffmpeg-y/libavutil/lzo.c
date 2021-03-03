#include <string.h>
#include "avutil.h"
#include "avassert.h"
#include "common.h"
#include "intreadwrite.h"
#include "lzo.h"
#define OUTBUF_PADDED 1
#define INBUF_PADDED 1
typedef struct LZOContext {
    const uint8_t *in, *in_end;
    uint8_t *out_start, *out, *out_end;
    int error;
} LZOContext;
#ifdef INBUF_PADDED
#define GETB(c) (*(c).in++)
#else
#define GETB(c) get_byte(&(c))
#endif
#if defined(INBUF_PADDED) && defined(OUTBUF_PADDED)
#endif
