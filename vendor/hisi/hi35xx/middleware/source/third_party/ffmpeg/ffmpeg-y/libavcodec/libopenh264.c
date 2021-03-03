#include <string.h>
#include <wels/codec_api.h>
#include <wels/codec_ver.h>
#include "libavutil/log.h"
#include "libopenh264.h"
#if !defined(_WIN32) || !defined(__GNUC__) || !ARCH_X86_32 || AV_GCC_VERSION_AT_LEAST(4, 7)
#endif
