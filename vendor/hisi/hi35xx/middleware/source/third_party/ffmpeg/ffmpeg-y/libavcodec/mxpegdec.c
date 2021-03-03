#include "internal.h"
#include "mjpeg.h"
#include "mjpegdec.h"
typedef struct MXpegDecodeContext {
    MJpegDecodeContext jpg;
    AVFrame *picture[2]; /* pictures array */
    int picture_index; /* index of current picture */
    int got_sof_data; /* true if SOF data successfully parsed */
    int got_mxm_bitmask; /* true if MXM bitmask available */
    uint8_t *mxm_bitmask; /* bitmask buffer */
    unsigned bitmask_size; /* size of bitmask */
    int has_complete_frame; /* true if has complete frame */
    uint8_t *completion_bitmask; /* completion bitmask of macroblocks */
    unsigned mb_width, mb_height; /* size of picture in MB's from MXM header */
} MXpegDecodeContext;
