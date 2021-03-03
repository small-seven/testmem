#include <stdint.h>
#include "libavutil/imgutils.h"
#include "bytestream.h"
#include "avcodec.h"
#include "internal.h"
#include "mathops.h"
typedef enum {
    MASK_NONE,
    MASK_HAS_MASK,
    MASK_HAS_TRANSPARENT_COLOR,
    MASK_LASSO
} mask_type;
typedef struct IffContext {
    AVFrame *frame;
    int planesize;
    uint8_t * planebuf;
    uint8_t * ham_buf;      ///< temporary buffer for planar to chunky conversation
    uint32_t *ham_palbuf;   ///< HAM decode table
    uint32_t *mask_buf;     ///< temporary buffer for palette indices
    uint32_t *mask_palbuf;  ///< masking palette table
    unsigned  compression;  ///< delta compression method used
    unsigned  is_short;     ///< short compression method used
    unsigned  is_interlaced;///< video is interlaced
    unsigned  is_brush;     ///< video is in ANBR format
    unsigned  bpp;          ///< bits per plane to decode (differs from bits_per_coded_sample if HAM)
    unsigned  ham;          ///< 0 if non-HAM or number of hold bits (6 for bpp > 6, 4 otherwise)
    unsigned  flags;        ///< 1 for EHB, 0 is no extra half darkening
    unsigned  transparency; ///< TODO: transparency color index in palette
    unsigned  masking;      ///< TODO: masking method used
    int init; // 1 if buffer and palette data already initialized, 0 otherwise
    int16_t   tvdc[16];     ///< TVDC lookup table
    GetByteContext gb;
    uint8_t *video[2];
    unsigned video_size;
    uint32_t *pal;
} IffContext;
#define LUT8_PART(plane, v)                             \
#define LUT8(plane) {                           \
#define LUT32(plane) {                                    \
#define DECODE_HAM_PLANE32(x)       \
#define DECODE_RGBX_COMMON(type) \
#define GETNIBBLE ((i & 1) ?  (src[i>>1] & 0xF) : (src[i>>1] >> 4))
#if CONFIG_IFF_ILBM_DECODER
#endif
