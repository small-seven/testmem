#include "av1_parse.h"
#include "cbs.h"
#include "cbs_av1.h"
#include "parser.h"
typedef struct AV1ParseContext {
    CodedBitstreamContext *cbc;
    CodedBitstreamFragment temporal_unit;
    int parsed_extradata;
} AV1ParseContext;
