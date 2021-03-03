#include <limits.h>
#include <stdio.h>
#include "libavutil/common.h"
#include "libavutil/channel_layout.h"
#include "libavutil/error.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/rational.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
typedef struct TestContext {
    const AVClass *class;
    int num;
    int toggle;
    char *string;
    int flags;
    AVRational rational;
    AVRational video_rate;
    int w, h;
    enum AVPixelFormat pix_fmt;
    enum AVSampleFormat sample_fmt;
    int64_t duration;
    uint8_t color[4];
    int64_t channel_layout;
    void *binary;
    int binary_size;
    void *binary1;
    int binary_size1;
    void *binary2;
    int binary_size2;
    int64_t num64;
    float flt;
    double dbl;
    char *escape;
    int bool1;
    int bool2;
    int bool3;
} TestContext;
#define OFFSET(x) offsetof(TestContext, x)
#define TEST_FLAG_COOL 01
#define TEST_FLAG_LAME 02
#define TEST_FLAG_MU   04
