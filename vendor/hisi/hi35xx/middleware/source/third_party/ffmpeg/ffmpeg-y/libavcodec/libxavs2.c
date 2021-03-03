#include "xavs2.h"
#include "mpeg12.h"
#include "libavutil/avstring.h"
#define xavs2_opt_set2(name, format, ...) do{ \
typedef struct XAVS2EContext {
    AVClass *class;

    int lcu_row_threads;
    int initial_qp;
    int qp;
    int max_qp;
    int min_qp;
    int preset_level;
    int log_level;

    void *encoder;
    char *xavs2_opts;

    xavs2_outpacket_t packet;
    xavs2_param_t *param;

    const xavs2_api_t *api;

} XAVS2EContext;
#define OFFSET(x) offsetof(XAVS2EContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
