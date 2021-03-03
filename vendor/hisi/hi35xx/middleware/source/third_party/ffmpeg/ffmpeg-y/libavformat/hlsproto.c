#include "libavutil/avstring.h"
#include "libavutil/time.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "url.h"
#include "version.h"
typedef struct HLSContext {
    char playlisturl[MAX_URL_SIZE];
    int64_t target_duration;
    int start_seq_no;
    int finished;
    int n_segments;
    struct segment **segments;
    int n_variants;
    struct variant **variants;
    int cur_seq_no;
    URLContext *seg_hd;
    int64_t last_load_time;
} HLSContext;
