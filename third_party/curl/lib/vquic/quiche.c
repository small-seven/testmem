#include "curl_setup.h"
#ifdef USE_QUICHE
#include <quiche.h>
#include <openssl/err.h>
#include "urldata.h"
#include "sendf.h"
#include "strdup.h"
#include "rand.h"
#include "quic.h"
#include "strcase.h"
#include "multiif.h"
#include "connect.h"
#include "strerror.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define DEBUG_HTTP3
#ifdef DEBUG_HTTP3
#define H3BUGF(x) x
#else
#define H3BUGF(x) do { } while(0)
#endif
#define QUIC_MAX_STREAMS (256*1024)
#define QUIC_MAX_DATA (1*1024*1024)
#define QUIC_IDLE_TIMEOUT (60 * 1000) /* milliseconds */
#ifdef DEBUG_QUICHE
#endif
#ifdef DEBUG_QUICHE
#endif
#define AUTHORITY_DST_IDX 3
#if 0 /* This should probably go in more or less like this */
#endif
#define MAX_ACC 60000  /* <64KB to account for some overhead */
#endif
