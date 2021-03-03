#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "dirac.h"
#include "golomb.h"
#include "internal.h"
#include "mpeg12data.h"
#if CONFIG_DIRAC_PARSE
typedef struct dirac_source_params {
    unsigned width;
    unsigned height;
    uint8_t chroma_format;          ///< 0: 444  1: 422  2: 420

    uint8_t interlaced;
    uint8_t top_field_first;

    uint8_t frame_rate_index;       ///< index into dirac_frame_rate[]
    uint8_t aspect_ratio_index;     ///< index into dirac_aspect_ratio[]

    uint16_t clean_width;
    uint16_t clean_height;
    uint16_t clean_left_offset;
    uint16_t clean_right_offset;

    uint8_t pixel_range_index;      ///< index into dirac_pixel_range_presets[]
    uint8_t color_spec_index;       ///< index into dirac_color_spec_presets[]
} dirac_source_params;
#else
#endif
