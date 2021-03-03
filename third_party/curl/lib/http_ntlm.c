#include "curl_setup.h"
#if !defined(CURL_DISABLE_HTTP) && defined(USE_NTLM)
#define DEBUG_ME 0
#include "urldata.h"
#include "sendf.h"
#include "strcase.h"
#include "http_ntlm.h"
#include "curl_ntlm_core.h"
#include "curl_ntlm_wb.h"
#include "vauth/vauth.h"
#include "url.h"
#if defined(USE_WINDOWS_SSPI)
#include "curl_sspi.h"
#endif
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if DEBUG_ME
# define DEBUG_OUT(x) x
#else
# define DEBUG_OUT(x) Curl_nop_stmt
#endif
#ifdef USE_WINDOWS_SSPI
#ifdef SECPKG_ATTR_ENDPOINT_BINDINGS
#endif
#endif
#if defined(NTLM_WB_ENABLED)
#endif
#endif /* !CURL_DISABLE_HTTP && USE_NTLM */
