#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct NormalizeContext {
    const AVClass *class;

    // Storage for the corresponding AVOptions
    uint8_t blackpt[4];
    uint8_t whitept[4];
    int smoothing;
    float independence;
    float strength;

    uint8_t co[4];      // Offsets to R,G,B,A bytes respectively in each pixel
    int num_components; // Number of components in the pixel format
    int step;
    int history_len;    // Number of frames to average; based on smoothing factor
    int frame_num;      // Increments on each frame, starting from 0.

    // Per-extremum, per-channel history, for temporal smoothing.
    struct {
        uint8_t *history;       // History entries.
        uint32_t history_sum;   // Sum of history entries.
    } min[3], max[3];           // Min and max for each channel in {R,G,B}.
#define OFFSET(x) offsetof(NormalizeContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
