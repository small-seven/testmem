#include "libavutil/blowfish.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/rc4.h"
#include "libavutil/xtea.h"
#include "internal.h"
#include "rtmp.h"
#include "rtmpdh.h"
#include "rtmpcrypt.h"
#include "url.h"
typedef struct RTMPEContext {
    const AVClass *class;
    URLContext   *stream;            ///< TCP stream
    FF_DH        *dh;                ///< Diffie-Hellman context
    struct AVRC4 key_in;             ///< RC4 key used for decrypt data
    struct AVRC4 key_out;            ///< RC4 key used for encrypt data
    int          handshaked;         ///< flag indicating when the handshake is performed
    int          tunneling;          ///< use a HTTP connection (RTMPTE)
} RTMPEContext;
#define OFFSET(x) offsetof(RTMPEContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
