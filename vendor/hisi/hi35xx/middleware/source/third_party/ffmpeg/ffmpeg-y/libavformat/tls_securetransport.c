#include <errno.h>
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#include "tls.h"
#include "libavcodec/internal.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include <Security/Security.h>
#include <Security/SecureTransport.h>
#include <CoreFoundation/CoreFoundation.h>
#define ioErr -36
typedef struct TLSContext {
    const AVClass *class;
    TLSShared tls_shared;
    SSLContextRef ssl_context;
    CFArrayRef ca_array;
    int lastErr;
} TLSContext;
#if !HAVE_SECITEMIMPORT
#else
#endif
#define CHECK_ERROR(func, ...) do {                                     \
