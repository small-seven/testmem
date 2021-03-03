#include "curl_setup.h"
#ifdef HAVE_GSSAPI
#include "curl_gssapi.h"
#include "sendf.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef GSS_C_DELEG_POLICY_FLAG
#else
#endif
#define GSS_LOG_BUFFER_LEN 1024
#endif /* HAVE_GSSAPI */
