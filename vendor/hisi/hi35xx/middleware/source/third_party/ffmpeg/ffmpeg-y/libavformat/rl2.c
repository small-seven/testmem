#include <stdint.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "avformat.h"
#include "internal.h"
#define EXTRADATA1_SIZE (6 + 256 * 3) ///< video base, clr, palette
#define FORM_TAG MKBETAG('F', 'O', 'R', 'M')
#define RLV2_TAG MKBETAG('R', 'L', 'V', '2')
#define RLV3_TAG MKBETAG('R', 'L', 'V', '3')
typedef struct Rl2DemuxContext {
    unsigned int index_pos[2];   ///< indexes in the sample tables
} Rl2DemuxContext;
