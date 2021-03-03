#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include <zlib.h>
#define KBND MKTAG('K', 'B', 'N', 'D')
#define FINT MKTAG('F', 'I', 'N', 'T')
#define INIT MKTAG('I', 'N', 'I', 'T')
#define BNDL MKTAG('B', 'N', 'D', 'L')
#define KFRM MKTAG('K', 'F', 'R', 'M')
#define DLTA MKTAG('D', 'L', 'T', 'A')
#define MOUS MKTAG('M', 'O', 'U', 'S')
#define MPOS MKTAG('M', 'P', 'O', 'S')
#define MOVE MKTAG('M', 'O', 'V', 'E')
#define EMPT MKTAG('E', 'M', 'P', 'T')
typedef struct RASCContext {
    AVClass        *class;
    int             skip_cursor;
    GetByteContext  gb;
    uint8_t        *delta;
    int             delta_size;
    uint8_t        *cursor;
    int             cursor_size;
    unsigned        cursor_w;
    unsigned        cursor_h;
    unsigned        cursor_x;
    unsigned        cursor_y;
    int             stride;
    int             bpp;
    z_stream        zstream;
    AVFrame        *frame;
    AVFrame        *frame1;
    AVFrame        *frame2;
} RASCContext;
#define NEXT_LINE                        \
