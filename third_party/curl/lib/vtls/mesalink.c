#include "curl_setup.h"
#ifdef USE_MESALINK
#include <mesalink/options.h>
#include <mesalink/version.h>
#include "urldata.h"
#include "sendf.h"
#include "inet_pton.h"
#include "vtls.h"
#include "parsedate.h"
#include "connect.h" /* for the connect timeout */
#include "select.h"
#include "strcase.h"
#include "x509asn1.h"
#include "curl_printf.h"
#include "mesalink.h"
#include <mesalink/openssl/ssl.h>
#include <mesalink/openssl/err.h>
#include "curl_memory.h"
#include "memdebug.h"
#define MESALINK_MAX_ERROR_SZ 80
#define BACKEND connssl->backend
#ifdef ENABLE_IPV6
#endif
#ifdef MESALINK_HAVE_CIPHER
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef CURLDEBUG
#ifdef ENABLE_IPV6
#endif
#endif
#ifdef MESALINK_HAVE_SESSION
#endif /* MESALINK_HAVE_SESSION */
#ifdef MESALINK_HAVE_SESSION
#endif /* MESALINK_HAVE_SESSION */
#endif
