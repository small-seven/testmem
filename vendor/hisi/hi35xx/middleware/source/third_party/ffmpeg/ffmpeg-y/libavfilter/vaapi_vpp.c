#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "formats.h"
#include "internal.h"
#include "vaapi_vpp.h"
typedef struct VAAPIColourProperties {
    VAProcColorStandardType va_color_standard;

    enum AVColorPrimaries color_primaries;
    enum AVColorTransferCharacteristic color_trc;
    enum AVColorSpace colorspace;

    uint8_t va_chroma_sample_location;
    uint8_t va_color_range;

    enum AVColorRange color_range;
    enum AVChromaLocation chroma_sample_location;
} VAAPIColourProperties;
#if VA_CHECK_VERSION(1, 1, 0)
#endif
#if VA_CHECK_VERSION(1, 3, 0)
#endif
#if VA_CHECK_VERSION(1, 1, 0)
#else
#endif
#if VA_CHECK_VERSION(1, 1, 0)
#else
#endif
#if VA_CHECK_VERSION(1, 3, 0)
#endif
#if VA_CHECK_VERSION(1, 1, 0)
#if VA_CHECK_VERSION(1, 3, 0)
#endif
#if VA_CHECK_VERSION(1, 3, 0)
#endif
#endif
#if VA_CHECK_VERSION(1, 1, 0)
#endif
