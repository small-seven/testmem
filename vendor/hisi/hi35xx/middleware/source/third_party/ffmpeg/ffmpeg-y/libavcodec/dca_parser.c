#include "dca.h"
#include "dca_core.h"
#include "dca_exss.h"
#include "dca_lbr.h"
#include "dca_syncwords.h"
#include "get_bits.h"
#include "parser.h"
typedef struct DCAParseContext {
    ParseContext pc;
    uint32_t lastmarker;
    int size;
    int framesize;
    unsigned int startpos;
    DCAExssParser exss;
    unsigned int sr_code;
} DCAParseContext;
#define IS_CORE_MARKER(state) \
#define IS_EXSS_MARKER(state)   ((state & 0xFFFFFFFF) == DCA_SYNCWORD_SUBSTREAM)
#define IS_MARKER(state)        (IS_CORE_MARKER(state) || IS_EXSS_MARKER(state))
#define CORE_MARKER(state)      ((state >> 16) & 0xFFFFFFFF)
#define EXSS_MARKER(state)      (state & 0xFFFFFFFF)
#define STATE_LE(state)     (((state & 0xFF00FF00) >> 8) | ((state & 0x00FF00FF) << 8))
#define STATE_14(state)     (((state & 0x3FFF0000) >> 8) | ((state & 0x00003FFF) >> 6))
#define CORE_FRAMESIZE(state)   (((state >> 4) & 0x3FFF) + 1)
#define EXSS_FRAMESIZE(state)   ((state & 0x2000000000) ? \
