#include <stdint.h>
#include "libavutil/avutil.h"
#undef FUNC
#undef FSUF
#undef sample
#undef sample_type
#undef OUT
#undef S
#if SAMPLE_SIZE == 32
#   define sample_type  int32_t
#else
#   define sample_type  int16_t
#endif
#if PLANAR
#   define FSUF   AV_JOIN(SAMPLE_SIZE, p)
#   define sample sample_type *
#   define OUT(n) n
#   define S(s, c, i) (s[c][i])
#else
#   define FSUF   SAMPLE_SIZE
#   define sample sample_type
#   define OUT(n) n[0]
#   define S(s, c, i) (*s++)
#endif
#define FUNC(n) AV_JOIN(n ## _, FSUF)
