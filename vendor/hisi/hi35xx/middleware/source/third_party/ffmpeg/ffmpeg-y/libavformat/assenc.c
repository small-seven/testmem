#include "libavutil/avstring.h"
#include "avformat.h"
#include "internal.h"
#include "libavutil/opt.h"
typedef struct DialogueLine {
    int readorder;
    char *line;
    struct DialogueLine *prev, *next;
} DialogueLine;
typedef struct ASSContext {
    const AVClass *class;
    int expected_readorder;
    DialogueLine *dialogue_cache;
    DialogueLine *last_added_dialogue;
    int cache_size;
    int ssa_mode;
    int ignore_readorder;
    uint8_t *trailer;
    size_t trailer_size;
} ASSContext;
#define OFFSET(x) offsetof(ASSContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
