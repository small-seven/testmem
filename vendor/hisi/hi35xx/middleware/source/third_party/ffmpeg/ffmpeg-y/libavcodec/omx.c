#include "config.h"
#if CONFIG_OMX_RPI
#define OMX_SKIP64BIT
#endif
#include <dlfcn.h>
#include <OMX_Core.h>
#include <OMX_Component.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "h264.h"
#include "internal.h"
#ifdef OMX_SKIP64BIT
#else
#define to_omx_ticks(x) (x)
#define from_omx_ticks(x) (x)
#endif
#define INIT_STRUCT(x) do {                                               \
#define CHECK(x) do {                                                     \
typedef struct OMXContext {
    void *lib;
    void *lib2;
    OMX_ERRORTYPE (*ptr_Init)(void);
    OMX_ERRORTYPE (*ptr_Deinit)(void);
    OMX_ERRORTYPE (*ptr_ComponentNameEnum)(OMX_STRING, OMX_U32, OMX_U32);
    OMX_ERRORTYPE (*ptr_GetHandle)(OMX_HANDLETYPE*, OMX_STRING, OMX_PTR, OMX_CALLBACKTYPE*);
    OMX_ERRORTYPE (*ptr_FreeHandle)(OMX_HANDLETYPE);
    OMX_ERRORTYPE (*ptr_GetComponentsOfRole)(OMX_STRING, OMX_U32*, OMX_U8**);
    OMX_ERRORTYPE (*ptr_GetRolesOfComponent)(OMX_STRING, OMX_U32*, OMX_U8**);
    void (*host_init)(void);
} OMXContext;
#if CONFIG_OMX_RPI
#else
#endif
typedef struct OMXCodecContext {
    const AVClass *class;
    char *libname;
    char *libprefix;
    OMXContext *omx_context;

    AVCodecContext *avctx;

    char component_name[OMX_MAX_STRINGNAME_SIZE];
    OMX_VERSIONTYPE version;
    OMX_HANDLETYPE handle;
    int in_port, out_port;
    OMX_COLOR_FORMATTYPE color_format;
    int stride, plane_size;

    int num_in_buffers, num_out_buffers;
    OMX_BUFFERHEADERTYPE **in_buffer_headers;
    OMX_BUFFERHEADERTYPE **out_buffer_headers;
    int num_free_in_buffers;
    OMX_BUFFERHEADERTYPE **free_in_buffers;
    int num_done_out_buffers;
    OMX_BUFFERHEADERTYPE **done_out_buffers;
    pthread_mutex_t input_mutex;
    pthread_cond_t input_cond;
    pthread_mutex_t output_mutex;
    pthread_cond_t output_cond;

    pthread_mutex_t state_mutex;
    pthread_cond_t state_cond;
    OMX_STATETYPE state;
    OMX_ERRORTYPE error;

    int mutex_cond_inited;

    int eos_sent, got_eos;

    uint8_t *output_buf;
    int output_buf_size;

    int input_zerocopy;
    int profile;
} OMXCodecContext;
    // This uses casts in the printfs, since OMX_U32 actually is a typedef for
    // unsigned long in official header versions (but there are also modified
    // versions where it is something else).
    switch (event) {
    case OMX_EventError:
        pthread_mutex_lock(&s->state_mutex);
        av_log(s->avctx, AV_LOG_ERROR, "OMX error %"PRIx32"\n", (uint32_t) data1);
        s->error = data1;
        pthread_cond_broadcast(&s->state_cond);
        pthread_mutex_unlock(&s->state_mutex);
        break;
    case OMX_EventCmdComplete:
        if (data1 == OMX_CommandStateSet) {
            pthread_mutex_lock(&s->state_mutex);
            s->state = data2;
            av_log(s->avctx, AV_LOG_VERBOSE, "OMX state changed to %"PRIu32"\n", (uint32_t) data2);
            pthread_cond_broadcast(&s->state_cond);
            pthread_mutex_unlock(&s->state_mutex);
        } else if (data1 == OMX_CommandPortDisable) {
#if CONFIG_OMX_RPI
#endif
#if CONFIG_OMX_RPI
#endif
#define OFFSET(x) offsetof(OMXCodecContext, x)
#define VDE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#define VE  AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
