#include "libavcodec/options.c"
typedef struct Dummy12Context {
    AVClass  *av_class;
    int      num;
    char*    str;
} Dummy12Context;
typedef struct Dummy3Context {
    void     *fake_av_class;
    int      num;
    char*    str;
} Dummy3Context;
#define OFFSET(x) offsetof(Dummy12Context, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
