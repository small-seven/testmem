#include "avcodec.h"
#include "libavcodec/ass.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include <aribb24/aribb24.h>
#include <aribb24/parser.h>
#include <aribb24/decoder.h>
typedef struct Libaribb24Context {
    AVClass *class;

    arib_instance_t *lib_instance;
    arib_parser_t *parser;
    arib_decoder_t *decoder;

    int read_order;

    char        *aribb24_base_path;
    unsigned int aribb24_skip_ruby;
} Libaribb24Context;
#define RGB_TO_BGR(c) (((c) & 0xff) << 16 | ((c) & 0xff00) | (((c) >> 16) & 0xff))
#define OFFSET(x) offsetof(Libaribb24Context, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_DECODING_PARAM
