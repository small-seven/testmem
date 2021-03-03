#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
#include "libavutil/colorspace.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#define RGBA(r,g,b,a) (((unsigned)(a) << 24) | ((r) << 16) | ((g) << 8) | (b))
#define MAX_EPOCH_PALETTES 8   // Max 8 allowed per PGS epoch
#define MAX_EPOCH_OBJECTS  64  // Max 64 allowed per PGS epoch
#define MAX_OBJECT_REFS    2   // Max objects per display set
typedef struct PGSSubObjectRef {
    int     id;
    int     window_id;
    uint8_t composition_flag;
    int     x;
    int     y;
    int     crop_x;
    int     crop_y;
    int     crop_w;
    int     crop_h;
} PGSSubObjectRef;
typedef struct PGSSubPresentation {
    int id_number;
    int palette_id;
    int object_count;
    PGSSubObjectRef objects[MAX_OBJECT_REFS];
    int64_t pts;
} PGSSubPresentation;
typedef struct PGSSubObject {
    int          id;
    int          w;
    int          h;
    uint8_t      *rle;
    unsigned int rle_buffer_size, rle_data_len;
    unsigned int rle_remaining_len;
} PGSSubObject;
typedef struct PGSSubObjects {
    int          count;
    PGSSubObject object[MAX_EPOCH_OBJECTS];
} PGSSubObjects;
typedef struct PGSSubPalette {
    int         id;
    uint32_t    clut[256];
} PGSSubPalette;
typedef struct PGSSubPalettes {
    int           count;
    PGSSubPalette palette[MAX_EPOCH_PALETTES];
} PGSSubPalettes;
typedef struct PGSSubContext {
    AVClass *class;
    PGSSubPresentation presentation;
    PGSSubPalettes     palettes;
    PGSSubObjects      objects;
    int forced_subs_only;
} PGSSubContext;
#if FF_API_AVPICTURE
#endif
#define OFFSET(x) offsetof(PGSSubContext, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_DECODING_PARAM
