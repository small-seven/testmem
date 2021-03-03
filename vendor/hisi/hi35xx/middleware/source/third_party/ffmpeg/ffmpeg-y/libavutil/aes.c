#include "common.h"
#include "aes.h"
#include "aes_internal.h"
#include "intreadwrite.h"
#include "timer.h"
#if CONFIG_SMALL
#else
#endif
#if HAVE_BIGENDIAN
#   define ROT(x, s) (((x) >> (s)) | ((x) << (32-(s))))
#else
#   define ROT(x, s) (((x) << (s)) | ((x) >> (32-(s))))
#endif
#if CONFIG_SMALL
#else
#endif
#if !CONFIG_SMALL
#endif
