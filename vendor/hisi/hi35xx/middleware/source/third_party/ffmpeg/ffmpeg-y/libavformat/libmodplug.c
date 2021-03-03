#define MODPLUG_STATIC
#include <libmodplug/modplug.h>
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
typedef struct ModPlugContext {
    const AVClass *class;
    ModPlugFile *f;
    uint8_t *buf; ///< input file content

    /* options */
    int noise_reduction;
    int reverb_depth;
    int reverb_delay;
    int bass_amount;
    int bass_range;
    int surround_depth;
    int surround_delay;

    int max_size; ///< max file size to allocate

    /* optional video stream */
    double ts_per_packet; ///< used to define the pts/dts using packet_count;
    int packet_count;     ///< total number of audio packets
    int print_textinfo;   ///< bool flag for printing speed, tempo, order, ...
    int video_stream;     ///< 1 if the user want a video stream, otherwise 0
    int w;                ///< video stream width  in char (one char = 8x8px)
    int h;                ///< video stream height in char (one char = 8x8px)
    int video_switch;     ///< 1 if current packet is video, otherwise 0
    int fsize;            ///< constant frame size
    int linesize;         ///< line size in bytes
    char *color_eval;     ///< color eval user input expression
    AVExpr *expr;         ///< parsed color eval expression
} ModPlugContext;
#define FF_MODPLUG_MAX_FILE_SIZE (100 * 1<<20) // 100M
#define FF_MODPLUG_DEF_FILE_SIZE (  5 * 1<<20) //   5M
#define OFFSET(x) offsetof(ModPlugContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define SET_OPT_IF_REQUESTED(libopt, opt, flag) do {        \
#define ADD_META_MULTIPLE_ENTRIES(entry_name, fname) do {                      \
#define AUDIO_PKT_SIZE 512
#define PRINT_INFO(line, name, idvalue) do {                            \
