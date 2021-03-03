#include "config.h"
#include "libavutil/attributes.h"
#include "huffyuvencdsp.h"
#include "mathops.h"
#define pw_1 (ULONG_MAX / UINT16_MAX)
#if !HAVE_FAST_UNALIGNED
#endif
