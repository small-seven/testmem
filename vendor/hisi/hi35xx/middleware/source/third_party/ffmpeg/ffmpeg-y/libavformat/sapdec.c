#include "avformat.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "network.h"
#include "os_support.h"
#include "internal.h"
#include "avio_internal.h"
#include "url.h"
#include "rtpdec.h"
#if HAVE_POLL_H
#include <poll.h>
#endif
#define MIME "application/sdp"
