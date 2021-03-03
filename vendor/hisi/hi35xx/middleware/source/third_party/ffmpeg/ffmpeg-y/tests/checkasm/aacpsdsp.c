#include "libavcodec/aacpsdsp.h"
#include "checkasm.h"
#define N 32
#define STRIDE 128
#define BUF_SIZE (N * STRIDE)
#define randomize(buf, len) do {                                \
#define EPS 0.005
