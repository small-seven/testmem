#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/pixdesc.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "internal.h"
#include "formats.h"
#define KNOWN(l) (!FF_LAYOUT2COUNT(l)) /* for readability */
#define MERGE_REF(ret, a, fmts, type, fail)                                \
#define MERGE_FORMATS(ret, a, b, fmts, nb, type, fail)                          \
#define MAKE_FORMAT_LIST(type, field, count_field)                      \
#define ADD_FORMAT(f, fmt, unref_fn, type, list, nb)        \
#include "all_channel_layouts.inc"
#define FORMATS_REF(f, ref, unref_fn)                                           \
#define FIND_REF_INDEX(ref, idx)            \
#define FORMATS_UNREF(ref, list)                                   \
#define FORMATS_CHANGEREF(oldref, newref)       \
#define SET_COMMON_FORMATS(ctx, fmts, in_fmts, out_fmts, ref_fn, unref_fn, list) \
