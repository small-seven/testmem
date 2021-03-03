#include "libavformat/http.h"
#include "libavutil/avstring.h"
#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/dict.h"
#include "libavutil/time.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#include "id3v2.h"
#define INITIAL_BUFFER_SIZE 32768
#define MAX_FIELD_LEN 64
#define MAX_CHARACTERISTICS_LEN 512
#define MPEG_TIME_BASE 90000
#define MPEG_TIME_BASE_Q (AVRational){1, MPEG_TIME_BASE}
typedef struct HLSContext {
    AVClass *class;
    AVFormatContext *ctx;
    int n_variants;
    struct variant **variants;
    int n_playlists;
    struct playlist **playlists;
    int n_renditions;
    struct rendition **renditions;

    int cur_seq_no;
    int live_start_index;
    int first_packet;
    int64_t first_timestamp;
    int64_t cur_timestamp;
    AVIOInterruptCB *interrupt_callback;
    AVDictionary *avio_opts;
    char *allowed_extensions;
    int max_reload;
    int http_persistent;
    int http_multiple;
    AVIOContext *playlist_pb;
} HLSContext;
#if !CONFIG_HTTP_PROTOCOL
#else
#endif
#define OFFSET(x) offsetof(HLSContext, x)
#define FLAGS AV_OPT_FLAG_DECODING_PARAM
