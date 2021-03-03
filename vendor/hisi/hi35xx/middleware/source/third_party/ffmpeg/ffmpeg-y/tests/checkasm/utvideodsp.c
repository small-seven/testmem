#include <string.h>
#include "checkasm.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/utvideodsp.h"
#include "libavutil/intreadwrite.h"
#define WIDTH 240
#define HEIGHT 120
#define WIDTH_PADDED (WIDTH + 16) /* padded to 32 */
#define BUFFER_SIZE (WIDTH_PADDED * HEIGHT)
#define randomize_plane(buf, type)          \
#define cmp_plane(buf0, buf1, s)                    \
#define CHECK_RESTORE(type)\
