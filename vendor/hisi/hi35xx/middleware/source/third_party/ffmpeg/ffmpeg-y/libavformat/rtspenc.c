#include "avformat.h"
#if HAVE_POLL_H
#include <poll.h>
#endif
#include "network.h"
#include "os_support.h"
#include "rtsp.h"
#include "internal.h"
#include "avio_internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
#include "libavutil/time.h"
#include "url.h"
#define SDP_MAX_SIZE 16384
