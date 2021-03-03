#include "curl_setup.h"
#if defined(USE_NTLM) && !defined(USE_WINDOWS_SSPI)
#define DEBUG_ME 0
#include "urldata.h"
#include "non-ascii.h"
#include "sendf.h"
#include "curl_base64.h"
#include "curl_ntlm_core.h"
#include "curl_gethostname.h"
#include "curl_multibyte.h"
#include "curl_md5.h"
#include "warnless.h"
#include "rand.h"
#include "vtls/vtls.h"
#if defined(NTLM_NEEDS_NSS_INIT)
#include "vtls/nssg.h" /* for Curl_nss_force_init() */
#endif
#define BUILDING_CURL_NTLM_MSGS_C
#include "vauth/vauth.h"
#include "vauth/ntlm.h"
#include "curl_endian.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define NTLMSSP_SIGNATURE "\x4e\x54\x4c\x4d\x53\x53\x50"
#define SHORTPAIR(x) ((int)((x) & 0xff)), ((int)(((x) >> 8) & 0xff))
#define LONGQUARTET(x) ((int)((x) & 0xff)), ((int)(((x) >> 8) & 0xff)), \
#if DEBUG_ME
# define DEBUG_OUT(x) x
#else
# define DEBUG_OUT(x) Curl_nop_stmt
#endif
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if defined(NTLM_NEEDS_NSS_INIT)
#elif defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if defined(USE_NTRESPONSES) && defined(USE_NTLM2SESSION)
#define NTLM2FLAG NTLMFLAG_NEGOTIATE_NTLM2_KEY
#else
#define NTLM2FLAG 0
#endif
#ifdef USE_NTRESPONSES
#endif
#if defined(USE_NTRESPONSES) && defined(USE_NTLM_V2)
#endif
#if defined(USE_NTRESPONSES) && defined(USE_NTLM2SESSION)
#endif
#ifdef USE_NTRESPONSES
#endif
#ifdef USE_NTRESPONSES
#endif
#ifdef USE_NTRESPONSES
#else
#endif
#ifdef USE_NTRESPONSES
#else
#endif
#ifdef USE_NTRESPONSES
#endif
#endif /* USE_NTLM && !USE_WINDOWS_SSPI */
