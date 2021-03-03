#include "adts_header.h"
#include "adts_parser.h"
#include "avcodec.h"
#include "bsf.h"
#include "put_bits.h"
#include "get_bits.h"
#include "mpeg4audio.h"
#include "internal.h"
typedef struct AACBSFContext {
    int first_frame_done;
} AACBSFContext;
