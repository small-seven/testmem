#include "avformat.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#include "tls.h"
#define SECURITY_WIN32
#include <windows.h>
#include <security.h>
#include <schnlsp.h>
#define SCHANNEL_INITIAL_BUFFER_SIZE   4096
#define SCHANNEL_FREE_BUFFER_SIZE      1024
#ifndef SECBUFFER_ALERT
#define SECBUFFER_ALERT                17
#endif
typedef struct TLSContext {
    const AVClass *class;
    TLSShared tls_shared;

    CredHandle cred_handle;
    TimeStamp cred_timestamp;

    CtxtHandle ctxt_handle;
    TimeStamp ctxt_timestamp;

    ULONG request_flags;
    ULONG context_flags;

    uint8_t *enc_buf;
    int enc_buf_size;
    int enc_buf_offset;

    uint8_t *dec_buf;
    int dec_buf_size;
    int dec_buf_offset;

    SecPkgContext_StreamSizes sizes;

    int connected;
    int connection_closed;
    int sspi_close_notify;
} TLSContext;
