#include "ebur128.h"
#include <float.h>
#include <limits.h>
#include <math.h>               /* You may have to define _USE_MATH_DEFINES if you use MSVC */
#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "libavutil/thread.h"
#define CHECK_ERROR(condition, errorcode, goto_point)                          \
#define ALMOST_ZERO 0.000001
#define RELATIVE_GATE         (-10.0)
#define RELATIVE_GATE_FACTOR  pow(10.0, RELATIVE_GATE / 10.0)
#define MINUS_20DB            pow(10.0, -20.0 / 10.0)
void ff_ebur128_destroy(FFEBUR128State ** st)
{
    av_free((*st)->d->block_energy_histogram);
    av_free((*st)->d->short_term_block_energy_histogram);
    av_free((*st)->d->audio_data);
    av_free((*st)->d->channel_map);
    av_free((*st)->d->sample_peak);
    av_free((*st)->d->data_ptrs);
    av_free((*st)->d);
    av_free(*st);
    *st = NULL;
}
#define EBUR128_FILTER(type, scaling_factor)                                       \
#define FF_EBUR128_ADD_FRAMES_PLANAR(type)                                             \
#define FF_EBUR128_ADD_FRAMES(type)                                            \
