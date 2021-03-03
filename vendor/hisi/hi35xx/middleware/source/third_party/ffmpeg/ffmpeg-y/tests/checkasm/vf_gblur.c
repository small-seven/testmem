#include <string.h>
#include "checkasm.h"
#include "libavfilter/gblur.h"
#define WIDTH 256
#define HEIGHT 256
#define PIXELS (WIDTH * HEIGHT)
#define BUF_SIZE (PIXELS * 4)
#define randomize_buffers(buf, size)             \
