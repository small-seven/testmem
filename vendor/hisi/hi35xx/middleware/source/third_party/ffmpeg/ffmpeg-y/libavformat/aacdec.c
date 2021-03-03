#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "id3v1.h"
#include "id3v2.h"
#include "apetag.h"
#define ADTS_HEADER_SIZE 7
