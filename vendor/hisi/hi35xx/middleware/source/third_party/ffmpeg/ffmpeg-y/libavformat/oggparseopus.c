#include <string.h>
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "oggdec.h"
#define OPUS_SEEK_PREROLL_MS 80
#define OPUS_HEAD_SIZE 19
