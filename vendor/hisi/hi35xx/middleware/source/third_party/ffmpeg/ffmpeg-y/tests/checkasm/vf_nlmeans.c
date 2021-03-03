#include "checkasm.h"
#include "libavfilter/vf_nlmeans.h"
#include "libavutil/avassert.h"
#define randomize_buffer(buf, size) do {    \
