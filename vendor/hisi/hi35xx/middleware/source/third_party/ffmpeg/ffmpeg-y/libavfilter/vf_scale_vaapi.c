#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "scale.h"
#include "video.h"
#include "vaapi_vpp.h"
typedef struct ScaleVAAPIContext {
    VAAPIVPPContext vpp_ctx; // must be the first field

    char *output_format_string;

    int   mode;

    char *w_expr;      // width expression string
    char *h_expr;      // height expression string

    char *colour_primaries_string;
    char *colour_transfer_string;
    char *colour_matrix_string;
    int   colour_range;
    char *chroma_location_string;

    enum AVColorPrimaries colour_primaries;
    enum AVColorTransferCharacteristic colour_transfer;
    enum AVColorSpace colour_matrix;
    enum AVChromaLocation chroma_location;
} ScaleVAAPIContext;
#define D(name) case VA_FILTER_SCALING_ ## name: return #name
#undef D
#define STRING_OPTION(var_name, func_name, default_value) do { \
#define OFFSET(x) offsetof(ScaleVAAPIContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM)
