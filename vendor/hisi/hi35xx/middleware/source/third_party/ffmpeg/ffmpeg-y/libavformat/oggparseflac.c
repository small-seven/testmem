#include <stdlib.h>
#include "libavcodec/get_bits.h"
#include "libavcodec/flac.h"
#include "avformat.h"
#include "internal.h"
#include "oggdec.h"
#define OGG_FLAC_METADATA_TYPE_STREAMINFO 0x7F
