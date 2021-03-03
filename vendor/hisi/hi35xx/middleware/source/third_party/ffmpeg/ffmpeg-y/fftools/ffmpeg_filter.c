#include <stdint.h>
#include "ffmpeg.h"
#include "libavfilter/avfilter.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"
#include "libavresample/avresample.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/channel_layout.h"
#include "libavutil/display.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixfmt.h"
#include "libavutil/imgutils.h"
#include "libavutil/samplefmt.h"
#define DEF_CHOOSE_FORMAT(suffix, type, var, supported_list, none, get_name)   \
#define AUTO_INSERT_FILTER(opt_name, filter_name, arg) do {                 \
#define AUTO_INSERT_FILTER_INPUT(opt_name, filter_name, arg) do {                 \
