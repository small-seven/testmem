#include "avutil.h"
#include "avassert.h"
#include "avstring.h"
#include "channel_layout.h"
#include "common.h"
#include "dict.h"
#include "eval.h"
#include "log.h"
#include "parseutils.h"
#include "pixdesc.h"
#include "mathematics.h"
#include "opt.h"
#include "samplefmt.h"
#include "bprint.h"
#include <float.h>
#define DEFAULT_NUMVAL(opt) ((opt->type == AV_OPT_TYPE_INT64 || \
#define OPT_EVAL_NUMBER(name, opttype, vartype)                         \
#define WHITESPACES " \n\t\r"
void av_opt_free(void *obj)
{
    const AVOption *o = NULL;
    while ((o = av_opt_next(obj, o))) {
        switch (o->type) {
        case AV_OPT_TYPE_STRING:
        case AV_OPT_TYPE_BINARY:
            av_freep((uint8_t *)obj + o->offset);
            break;

        case AV_OPT_TYPE_DICT:
            av_dict_free((AVDictionary **)(((uint8_t *)obj) + o->offset));
            break;

        default:
            break;
        }
    }
}
