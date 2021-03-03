#include "libavutil/log.h"
#include "swresample_internal.h"
#include <soxr.h>
#if !defined SOXR_VERSION /* Deprecated @ March 2013: */
#else
#endif
