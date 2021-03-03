#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct BenchContext {
    const AVClass *class;
    int action;
    int64_t max, min;
    int64_t sum;
    int n;
} BenchContext;
#define OFFSET(x) offsetof(BenchContext, x)
#define DEFINE_OPTIONS(filt_name, FLAGS)                                                                                \
#define START_TIME_KEY "lavfi.bench.start_time"
#define T2F(v) ((v) / 1000000.)
#if CONFIG_BENCH_FILTER
#endif /* CONFIG_BENCH_FILTER */
#if CONFIG_ABENCH_FILTER
#endif /* CONFIG_ABENCH_FILTER */
