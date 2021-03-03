#include <va/va.h>
#include <va/va_enc_jpeg.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "bytestream.h"
#include "cbs.h"
#include "cbs_jpeg.h"
#include "internal.h"
#include "jpegtables.h"
#include "mjpeg.h"
#include "put_bits.h"
#include "vaapi_encode.h"
typedef struct VAAPIEncodeMJPEGContext {
    VAAPIEncodeContext common;

    // User options.
    int jfif;
    int huffman;

    // Derived settings.
    int quality;
    uint8_t jfif_data[14];

    // Writer structures.
    JPEGRawFrameHeader     frame_header;
    JPEGRawScan            scan;
    JPEGRawApplicationData jfif_header;
    JPEGRawQuantisationTableSpecification quant_tables;
    JPEGRawHuffmanTableSpecification      huffman_tables;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment current_fragment;
} VAAPIEncodeMJPEGContext;
#define OFFSET(x) offsetof(VAAPIEncodeMJPEGContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM)
