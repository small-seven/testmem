#include <pthread.h>
#include <libvmaf.h>
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
typedef struct LIBVMAFContext {
    const AVClass *class;
    FFFrameSync fs;
    const AVPixFmtDescriptor *desc;
    int width;
    int height;
    double vmaf_score;
    int vmaf_thread_created;
    pthread_t vmaf_thread;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int eof;
    AVFrame *gmain;
    AVFrame *gref;
    int frame_set;
    char *model_path;
    char *log_path;
    char *log_fmt;
    int disable_clip;
    int disable_avx;
    int enable_transform;
    int phone_model;
    int psnr;
    int ssim;
    int ms_ssim;
    char *pool;
    int n_threads;
    int n_subsample;
    int enable_conf_interval;
    int error;
} LIBVMAFContext;
#define OFFSET(x) offsetof(LIBVMAFContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define read_frame_fn(type, bits)                                               \
