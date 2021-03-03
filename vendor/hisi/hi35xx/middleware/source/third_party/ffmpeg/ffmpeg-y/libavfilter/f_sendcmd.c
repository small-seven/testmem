#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/file.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#include "video.h"
#define COMMAND_FLAG_ENTER 1
#define COMMAND_FLAG_LEAVE 2
typedef struct Command {
    int flags;
    char *target, *command, *arg;
    int index;
} Command;
typedef struct Interval {
    int64_t start_ts;          ///< start timestamp expressed as microseconds units
    int64_t end_ts;            ///< end   timestamp expressed as microseconds units
    int index;                 ///< unique index for these interval commands
    Command *commands;
    int   nb_commands;
    int enabled;               ///< current time detected inside this interval
} Interval;
typedef struct SendCmdContext {
    const AVClass *class;
    Interval *intervals;
    int   nb_intervals;

    char *commands_filename;
    char *commands_str;
} SendCmdContext;
#define OFFSET(x) offsetof(SendCmdContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#define SPACES " \f\t\n\r"
#define COMMAND_DELIMS " \f\t\n\r,;"
#define DELIMS " \f\t\n\r,;"
#define WITHIN_INTERVAL(ts, start_ts, end_ts) ((ts) >= (start_ts) && (ts) < (end_ts))
#if CONFIG_SENDCMD_FILTER
#define sendcmd_options options
#endif
#if CONFIG_ASENDCMD_FILTER
#define asendcmd_options options
#endif
