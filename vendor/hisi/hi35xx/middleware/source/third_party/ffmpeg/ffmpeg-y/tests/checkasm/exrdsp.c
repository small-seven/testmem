#include <string.h>
#include "checkasm.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/exrdsp.h"
#include "libavutil/intreadwrite.h"
#define BUF_SIZE 5120
#define PADDED_BUF_SIZE BUF_SIZE+AV_INPUT_BUFFER_PADDING_SIZE*2
#define randomize_buffers()                 \
