#include "libavutil/avstring.h"
#include "libavutil/intfloat.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "internal.h"
#include "http.h"
#include "rtmp.h"
#define RTMPT_DEFAULT_PORT 80
#define RTMPTS_DEFAULT_PORT RTMPS_DEFAULT_PORT
typedef struct RTMP_HTTPContext {
    const AVClass *class;
    URLContext   *stream;           ///< HTTP stream
    char         host[256];         ///< hostname of the server
    int          port;              ///< port to connect (default is 80)
    char         client_id[64];     ///< client ID used for all requests except the first one
    int          seq;               ///< sequence ID used for all requests
    uint8_t      *out_data;         ///< output buffer
    int          out_size;          ///< current output buffer size
    int          out_capacity;      ///< current output buffer capacity
    int          initialized;       ///< flag indicating when the http context is initialized
    int          finishing;         ///< flag indicating when the client closes the connection
    int          nb_bytes_read;     ///< number of bytes read since the last request
    int          tls;               ///< use Transport Security Layer (RTMPTS)
} RTMP_HTTPContext;
#define OFFSET(x) offsetof(RTMP_HTTPContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
