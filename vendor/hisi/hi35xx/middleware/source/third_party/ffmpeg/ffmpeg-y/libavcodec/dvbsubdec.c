#include "avcodec.h"
#include "get_bits.h"
#include "bytestream.h"
#include "internal.h"
#include "libavutil/colorspace.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#define DVBSUB_PAGE_SEGMENT     0x10
#define DVBSUB_REGION_SEGMENT   0x11
#define DVBSUB_CLUT_SEGMENT     0x12
#define DVBSUB_OBJECT_SEGMENT   0x13
#define DVBSUB_DISPLAYDEFINITION_SEGMENT 0x14
#define DVBSUB_DISPLAY_SEGMENT  0x80
#define cm (ff_crop_tab + MAX_NEG_CROP)
#define RGBA(r,g,b,a) (((unsigned)(a) << 24) | ((r) << 16) | ((g) << 8) | (b))
typedef struct DVBSubCLUT {
    int id;
    int version;

    uint32_t clut4[4];
    uint32_t clut16[16];
    uint32_t clut256[256];

    struct DVBSubCLUT *next;
} DVBSubCLUT;
typedef struct DVBSubObjectDisplay {
    int object_id;
    int region_id;

    int x_pos;
    int y_pos;

    int fgcolor;
    int bgcolor;

    struct DVBSubObjectDisplay *region_list_next;
    struct DVBSubObjectDisplay *object_list_next;
} DVBSubObjectDisplay;
typedef struct DVBSubObject {
    int id;
    int version;

    int type;

    DVBSubObjectDisplay *display_list;

    struct DVBSubObject *next;
} DVBSubObject;
typedef struct DVBSubRegionDisplay {
    int region_id;

    int x_pos;
    int y_pos;

    struct DVBSubRegionDisplay *next;
} DVBSubRegionDisplay;
typedef struct DVBSubRegion {
    int id;
    int version;

    int width;
    int height;
    int depth;

    int clut;
    int bgcolor;

    uint8_t computed_clut[4*256];
    int has_computed_clut;

    uint8_t *pbuf;
    int buf_size;
    int dirty;

    DVBSubObjectDisplay *display_list;

    struct DVBSubRegion *next;
} DVBSubRegion;
typedef struct DVBSubDisplayDefinition {
    int version;

    int x;
    int y;
    int width;
    int height;
} DVBSubDisplayDefinition;
typedef struct DVBSubContext {
    AVClass *class;
    int composition_id;
    int ancillary_id;

    int version;
    int time_out;
    int compute_edt; /**< if 1 end display time calculated using pts
                          if 0 (Default) calculated using time out */
    int compute_clut;
    int clut_count2[257][256];
    int substream;
    int64_t prev_start;
    DVBSubRegion *region_list;
    DVBSubCLUT   *clut_list;
    DVBSubObject *object_list;

    DVBSubRegionDisplay *display_list;
    DVBSubDisplayDefinition *display_definition;
} DVBSubContext;
#define V(x,y) rect->data[0][(x) + (y)*stride]
#define L(x,y) list[d[(x) + (y)*stride]]
#if FF_API_AVPICTURE
#endif
#if 0
#endif
#ifdef DEBUG
#endif /* DEBUG */
#ifdef DEBUG
#endif
#define DS AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_SUBTITLE_PARAM
