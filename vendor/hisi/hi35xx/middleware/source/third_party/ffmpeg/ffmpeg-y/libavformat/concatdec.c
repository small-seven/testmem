#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/timestamp.h"
#include "avformat.h"
#include "internal.h"
#include "url.h"
typedef enum ConcatMatchMode {
    MATCH_ONE_TO_ONE,
    MATCH_EXACT_ID,
} ConcatMatchMode;
typedef struct ConcatStream {
    AVBSFContext *bsf;
    int out_stream_index;
} ConcatStream;
typedef struct {
    char *url;
    int64_t start_time;
    int64_t file_start_time;
    int64_t file_inpoint;
    int64_t duration;
    int64_t user_duration;
    int64_t next_dts;
    ConcatStream *streams;
    int64_t inpoint;
    int64_t outpoint;
    AVDictionary *metadata;
    int nb_streams;
} ConcatFile;
typedef struct {
    AVClass *class;
    ConcatFile *files;
    ConcatFile *cur_file;
    unsigned nb_files;
    AVFormatContext *avf;
    int safe;
    int seekable;
    int eof;
    ConcatMatchMode stream_match_mode;
    unsigned auto_convert;
    int segment_time_metadata;
} ConcatContext;
#define FAIL(retcode) do { ret = (retcode); goto fail; } while(0)
#define OFFSET(x) offsetof(ConcatContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
