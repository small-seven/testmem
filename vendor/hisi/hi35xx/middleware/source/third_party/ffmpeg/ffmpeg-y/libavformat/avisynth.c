#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "libavcodec/internal.h"
#include "avformat.h"
#include "internal.h"
#include "config.h"
#define AVSC_NO_DECLSPEC
#ifdef _WIN32
#else
#endif
typedef struct AviSynthLibrary {
    void *library;
#define AVSC_DECLARE_FUNC(name) name ## _func name
    AVSC_DECLARE_FUNC(avs_bit_blt);
    AVSC_DECLARE_FUNC(avs_clip_get_error);
    AVSC_DECLARE_FUNC(avs_create_script_environment);
    AVSC_DECLARE_FUNC(avs_delete_script_environment);
    AVSC_DECLARE_FUNC(avs_get_audio);
    AVSC_DECLARE_FUNC(avs_get_error);
    AVSC_DECLARE_FUNC(avs_get_frame);
    AVSC_DECLARE_FUNC(avs_get_version);
    AVSC_DECLARE_FUNC(avs_get_video_info);
    AVSC_DECLARE_FUNC(avs_invoke);
    AVSC_DECLARE_FUNC(avs_release_clip);
    AVSC_DECLARE_FUNC(avs_release_value);
    AVSC_DECLARE_FUNC(avs_release_video_frame);
    AVSC_DECLARE_FUNC(avs_take_clip);
#ifdef USING_AVISYNTH
    AVSC_DECLARE_FUNC(avs_bits_per_pixel);
    AVSC_DECLARE_FUNC(avs_get_height_p);
    AVSC_DECLARE_FUNC(avs_get_pitch_p);
    AVSC_DECLARE_FUNC(avs_get_read_ptr_p);
    AVSC_DECLARE_FUNC(avs_get_row_size_p);
    AVSC_DECLARE_FUNC(avs_is_planar_rgb);
    AVSC_DECLARE_FUNC(avs_is_planar_rgba);
#endif
#undef AVSC_DECLARE_FUNC
} AviSynthLibrary;
typedef struct AviSynthContext {
    AVS_ScriptEnvironment *env;
    AVS_Clip *clip;
    const AVS_VideoInfo *vi;

    /* avisynth_read_packet_video() iterates over this. */
    int n_planes;
    const int *planes;

    int curr_stream;
    int curr_frame;
    int64_t curr_sample;

    int error;

    /* Linked list pointers. */
    struct AviSynthContext *next;
} AviSynthContext;
#ifdef USING_AVISYNTH
#endif
#define LOAD_AVS_FUNC(name, continue_on_fail)                          \
#ifdef USING_AVISYNTH
#endif
#undef LOAD_AVS_FUNC
static av_cold void avisynth_context_destroy(AviSynthContext *avs)
{
    if (avs_atexit_called)
        return;

    if (avs == avs_ctx_list) {
        avs_ctx_list = avs->next;
    } else {
        AviSynthContext *prev = avs_ctx_list;
        while (prev->next != avs)
            prev = prev->next;
        prev->next = avs->next;
    }

    if (avs->clip) {
        avs_library.avs_release_clip(avs->clip);
        avs->clip = NULL;
    }
    if (avs->env) {
        avs_library.avs_delete_script_environment(avs->env);
        avs->env = NULL;
    }
}
#ifdef USING_AVISYNTH
#endif
#ifdef USING_AVISYNTH
#endif
#ifdef USING_AVISYNTH
#endif
#ifdef USING_AVISYNTH
#else
#endif
#ifdef USING_AVISYNTH
#endif
#ifdef USING_AVISYNTH
#else
#endif
#ifdef USING_AVISYNTH
#else
#endif
#ifdef USING_AVISYNTH
#endif
