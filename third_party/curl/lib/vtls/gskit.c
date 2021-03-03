#include "curl_setup.h"
#ifdef USE_GSKIT
#include <gskssl.h>
#include <qsoasync.h>
#undef HAVE_SOCKETPAIR /* because the native one isn't good enough */
#include "socketpair.h"
#ifndef GSK_SSL_EXTN_SERVERNAME_REQUEST
#define GSK_SSL_EXTN_SERVERNAME_REQUEST         230
#endif
#ifndef GSK_TLSV10_CIPHER_SPECS
#define GSK_TLSV10_CIPHER_SPECS                 236
#endif
#ifndef GSK_TLSV11_CIPHER_SPECS
#define GSK_TLSV11_CIPHER_SPECS                 237
#endif
#ifndef GSK_TLSV12_CIPHER_SPECS
#define GSK_TLSV12_CIPHER_SPECS                 238
#endif
#ifndef GSK_PROTOCOL_TLSV11
#define GSK_PROTOCOL_TLSV11                     437
#endif
#ifndef GSK_PROTOCOL_TLSV12
#define GSK_PROTOCOL_TLSV12                     438
#endif
#ifndef GSK_FALSE
#define GSK_FALSE                               0
#endif
#ifndef GSK_TRUE
#define GSK_TRUE                                1
#endif
#include <limits.h>
#include <curl/curl.h>
#include "urldata.h"
#include "sendf.h"
#include "gskit.h"
#include "vtls.h"
#include "connect.h" /* for the connect timeout */
#include "select.h"
#include "strcase.h"
#include "x509asn1.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define SOS_READ        0x01
#define SOS_WRITE       0x02
#define CURL_GSKPROTO_SSLV2     0
#define CURL_GSKPROTO_SSLV2_MASK        (1 << CURL_GSKPROTO_SSLV2)
#define CURL_GSKPROTO_SSLV3     1
#define CURL_GSKPROTO_SSLV3_MASK        (1 << CURL_GSKPROTO_SSLV3)
#define CURL_GSKPROTO_TLSV10    2
#define CURL_GSKPROTO_TLSV10_MASK        (1 << CURL_GSKPROTO_TLSV10)
#define CURL_GSKPROTO_TLSV11    3
#define CURL_GSKPROTO_TLSV11_MASK        (1 << CURL_GSKPROTO_TLSV11)
#define CURL_GSKPROTO_TLSV12    4
#define CURL_GSKPROTO_TLSV12_MASK        (1 << CURL_GSKPROTO_TLSV12)
#define CURL_GSKPROTO_LAST      5
#define BACKEND connssl->backend
typedef struct {
  const char *name;            /* Cipher name. */
  const char *gsktoken;        /* Corresponding token for GSKit String. */
  unsigned int versions;       /* SSL version flags. */
}  gskit_cipher;
#ifndef CURL_DISABLE_FTP
#endif
#endif /* USE_GSKIT */
