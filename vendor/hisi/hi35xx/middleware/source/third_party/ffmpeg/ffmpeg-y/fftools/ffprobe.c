#include "config.h"
#include "libavutil/ffversion.h"
#include <string.h>
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/display.h"
#include "libavutil/hash.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/spherical.h"
#include "libavutil/stereo3d.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/libm.h"
#include "libavutil/parseutils.h"
#include "libavutil/timecode.h"
#include "libavutil/timestamp.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libpostproc/postprocess.h"
#include "cmdutils.h"
#include "libavutil/thread.h"
#if !HAVE_THREADS
#  ifdef pthread_mutex_lock
#    undef pthread_mutex_lock
#  endif
#  define pthread_mutex_lock(a) do{}while(0)
#  ifdef pthread_mutex_unlock
#    undef pthread_mutex_unlock
#  endif
#  define pthread_mutex_unlock(a) do{}while(0)
#endif
typedef struct InputStream {
    AVStream *st;

    AVCodecContext *dec_ctx;
} InputStream;
typedef struct InputFile {
    AVFormatContext *fmt_ctx;

    InputStream *streams;
    int       nb_streams;
} InputFile;
typedef struct ReadInterval {
    int id;             ///< identifier
    int64_t start, end; ///< start, end in second/AV_TIME_BASE units
    int has_start, has_end;
    int start_is_offset, end_is_offset;
    int duration_frames;
} ReadInterval;
#define SECTION_MAX_NB_CHILDREN 10
#define SECTION_FLAG_IS_WRAPPER      1 ///< the section only contains other sections, but has no data at its own level
#define SECTION_FLAG_IS_ARRAY        2 ///< the section contains an array of elements of the same type
#define SECTION_FLAG_HAS_VARIABLE_FIELDS 4 ///< the section may contain a variable number of fields with variable keys.
typedef enum {
    SECTION_ID_NONE = -1,
    SECTION_ID_CHAPTER,
    SECTION_ID_CHAPTER_TAGS,
    SECTION_ID_CHAPTERS,
    SECTION_ID_ERROR,
    SECTION_ID_FORMAT,
    SECTION_ID_FORMAT_TAGS,
    SECTION_ID_FRAME,
    SECTION_ID_FRAMES,
    SECTION_ID_FRAME_TAGS,
    SECTION_ID_FRAME_SIDE_DATA_LIST,
    SECTION_ID_FRAME_SIDE_DATA,
    SECTION_ID_FRAME_SIDE_DATA_TIMECODE_LIST,
    SECTION_ID_FRAME_SIDE_DATA_TIMECODE,
    SECTION_ID_FRAME_LOG,
    SECTION_ID_FRAME_LOGS,
    SECTION_ID_LIBRARY_VERSION,
    SECTION_ID_LIBRARY_VERSIONS,
    SECTION_ID_PACKET,
    SECTION_ID_PACKET_TAGS,
    SECTION_ID_PACKETS,
    SECTION_ID_PACKETS_AND_FRAMES,
    SECTION_ID_PACKET_SIDE_DATA_LIST,
    SECTION_ID_PACKET_SIDE_DATA,
    SECTION_ID_PIXEL_FORMAT,
    SECTION_ID_PIXEL_FORMAT_FLAGS,
    SECTION_ID_PIXEL_FORMAT_COMPONENT,
    SECTION_ID_PIXEL_FORMAT_COMPONENTS,
    SECTION_ID_PIXEL_FORMATS,
    SECTION_ID_PROGRAM_STREAM_DISPOSITION,
    SECTION_ID_PROGRAM_STREAM_TAGS,
    SECTION_ID_PROGRAM,
    SECTION_ID_PROGRAM_STREAMS,
    SECTION_ID_PROGRAM_STREAM,
    SECTION_ID_PROGRAM_TAGS,
    SECTION_ID_PROGRAM_VERSION,
    SECTION_ID_PROGRAMS,
    SECTION_ID_ROOT,
    SECTION_ID_STREAM,
    SECTION_ID_STREAM_DISPOSITION,
    SECTION_ID_STREAMS,
    SECTION_ID_STREAM_TAGS,
    SECTION_ID_STREAM_SIDE_DATA_LIST,
    SECTION_ID_STREAM_SIDE_DATA,
    SECTION_ID_SUBTITLE,
} SectionID;
#if HAVE_THREADS
#endif
typedef struct LogBuffer {
    char *context_name;
    int log_level;
    char *log_message;
    AVClassCategory category;
    char *parent_name;
    AVClassCategory parent_category;
}LogBuffer;
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
typedef struct WriterContext WriterContext;

#define WRITER_FLAG_DISPLAY_OPTIONAL_FIELDS 1
#define WRITER_FLAG_PUT_PACKETS_AND_FRAMES_IN_SAME_CHAPTER 2

typedef enum {
    WRITER_STRING_VALIDATION_FAIL,
    WRITER_STRING_VALIDATION_REPLACE,
    WRITER_STRING_VALIDATION_IGNORE,
    WRITER_STRING_VALIDATION_NB
} StringValidation;
typedef struct Writer {
    const AVClass *priv_class;      ///< private class of the writer, if any
    int priv_size;                  ///< private size for the writer context
    const char *name;

    int  (*init)  (WriterContext *wctx);
    void (*uninit)(WriterContext *wctx);

    void (*print_section_header)(WriterContext *wctx);
    void (*print_section_footer)(WriterContext *wctx);
    void (*print_integer)       (WriterContext *wctx, const char *, long long int);
    void (*print_rational)      (WriterContext *wctx, AVRational *q, char *sep);
    void (*print_string)        (WriterContext *wctx, const char *, const char *);
    int flags;                  ///< a combination or WRITER_FLAG_*
} Writer;
#define SECTION_MAX_NB_LEVELS 10
#define OFFSET(x) offsetof(WriterContext, x)
#define PRINT_STRING_OPT      1
#define PRINT_STRING_VALIDATE 2
#define MAX_REGISTERED_WRITERS_NB 64
#define DEFINE_WRITER_CLASS(name)                   \
typedef struct DefaultContext {
    const AVClass *class;
    int nokey;
    int noprint_wrappers;
    int nested_section[SECTION_MAX_NB_LEVELS];
} DefaultContext;
#undef OFFSET
#define OFFSET(x) offsetof(DefaultContext, x)
typedef struct CompactContext {
    const AVClass *class;
    char *item_sep_str;
    char item_sep;
    int nokey;
    int print_section;
    char *escape_mode_str;
    const char * (*escape_str)(AVBPrint *dst, const char *src, const char sep, void *log_ctx);
    int nested_section[SECTION_MAX_NB_LEVELS];
    int has_nested_elems[SECTION_MAX_NB_LEVELS];
    int terminate_line[SECTION_MAX_NB_LEVELS];
} CompactContext;
#undef OFFSET
#define OFFSET(x) offsetof(CompactContext, x)
#undef OFFSET
#define OFFSET(x) offsetof(CompactContext, x)
typedef struct FlatContext {
    const AVClass *class;
    const char *sep_str;
    char sep;
    int hierarchical;
} FlatContext;
#undef OFFSET
#define OFFSET(x) offsetof(FlatContext, x)
typedef struct INIContext {
    const AVClass *class;
    int hierarchical;
} INIContext;
#undef OFFSET
#define OFFSET(x) offsetof(INIContext, x)
typedef struct JSONContext {
    const AVClass *class;
    int indent_level;
    int compact;
    const char *item_sep, *item_start_end;
} JSONContext;
#undef OFFSET
#define OFFSET(x) offsetof(JSONContext, x)
#define JSON_INDENT() printf("%*c", json->indent_level * 4, ' ')
typedef struct XMLContext {
    const AVClass *class;
    int within_tag;
    int indent_level;
    int fully_qualified;
    int xsd_strict;
} XMLContext;
#undef OFFSET
#define OFFSET(x) offsetof(XMLContext, x)
#define CHECK_COMPLIANCE(opt, opt_name)                                 \
#define XML_INDENT() printf("%*c", xml->indent_level * 4, ' ')
#define print_fmt(k, f, ...) do {              \
#define print_int(k, v)         writer_print_integer(w, k, v)
#define print_q(k, v, s)        writer_print_rational(w, k, v, s)
#define print_str(k, v)         writer_print_string(w, k, v, 0)
#define print_str_opt(k, v)     writer_print_string(w, k, v, PRINT_STRING_OPT)
#define print_str_validate(k, v) writer_print_string(w, k, v, PRINT_STRING_VALIDATE)
#define print_time(k, v, tb)    writer_print_time(w, k, v, tb, 0)
#define print_ts(k, v)          writer_print_ts(w, k, v, 0)
#define print_duration_time(k, v, tb) writer_print_time(w, k, v, tb, 1)
#define print_duration_ts(k, v)       writer_print_ts(w, k, v, 1)
#define print_val(k, v, u) do {                                     \
#define print_section_header(s) writer_print_section_header(w, s)
#define print_section_footer(s) writer_print_section_footer(w, s)
#define REALLOCZ_ARRAY_STREAM(ptr, cur_n, new_n)                        \
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_LAVF_AVCTX
#endif
#define PRINT_DISPOSITION(flagname, name) do {                                \
#if FF_API_LAVF_AVCTX
#endif
#define CHECK_END if (ret < 0) goto end
#define SHOW_LIB_VERSION(libname, LIBNAME)                              \
#define PRINT_PIX_FMT_FLAG(flagname, name)                                \
#if FF_API_PSEUDOPAL
#endif
#define DEFINE_OPT_SHOW_SECTION(section, target_section_id)             \
#if HAVE_THREADS
#endif
#define SET_DO_SHOW(id, varname) do {                                   \
#if HAVE_THREADS
#endif
#if CONFIG_AVDEVICE
#endif
