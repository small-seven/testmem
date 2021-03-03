#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#define HISTOGRAM_SLOTS 12000
#define BUTTER_ORDER        2
#define YULE_ORDER         10
typedef struct ReplayGainFreqInfo {
    int    sample_rate;
    double BYule[YULE_ORDER + 1];
    double AYule[YULE_ORDER + 1];
    double BButter[BUTTER_ORDER + 1];
    double AButter[BUTTER_ORDER + 1];
} ReplayGainFreqInfo;
typedef struct ReplayGainContext {
    uint32_t histogram[HISTOGRAM_SLOTS];
    float peak;
    int yule_hist_i, butter_hist_i;
    const double *yule_coeff_a;
    const double *yule_coeff_b;
    const double *butter_coeff_a;
    const double *butter_coeff_b;
    float yule_hist_a[256];
    float yule_hist_b[256];
    float butter_hist_a[256];
    float butter_hist_b[256];
} ReplayGainContext;
