#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "libavutil/imgutils.h"
#include "indeo4data.h"
#include "internal.h"
#include "ivi.h"
#include "ivi_dsp.h"
#define IVI4_PIC_SIZE_ESC   7
