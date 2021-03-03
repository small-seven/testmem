#include <stdlib.h>
#include <string.h>
#include "libavutil/pixdesc.h"
#include "libavutil/qsort.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "huffyuvdsp.h"
#include "internal.h"
#include "lossless_videodsp.h"
#include "thread.h"
typedef struct Slice {
    uint32_t start;
    uint32_t size;
} Slice;
typedef enum Prediction {
    LEFT = 1,
    GRADIENT,
    MEDIAN,
} Prediction;
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t  len;
    uint32_t code;
} HuffEntry;
typedef struct MagicYUVContext {
    AVFrame          *p;
    int               max;
    int               bps;
    int               slice_height;
    int               nb_slices;
    int               planes;         // number of encoded planes in bitstream
    int               decorrelate;    // postprocessing work
    int               color_matrix;   // video color matrix
    int               flags;
    int               interlaced;     // video is interlaced
    uint8_t          *buf;            // pointer to AVPacket->data
    int               hshift[4];
    int               vshift[4];
    Slice            *slices[4];      // slice bitstream positions for each plane
    unsigned int      slices_size[4]; // slice sizes for each plane
    uint8_t           len[4][4096];   // table of code lengths for each plane
    VLC               vlc[4];         // VLC for each plane
    int (*huff_build)(VLC *vlc, uint8_t *len);
    int (*magy_decode_slice)(AVCodecContext *avctx, void *tdata,
                             int j, int threadnr);
    LLVidDSPContext   llviddsp;
} MagicYUVContext;
#if HAVE_THREADS
#endif
