#include "curl_setup.h"
#if !defined(CURL_DISABLE_SMB) && defined(USE_NTLM) &&  \
#if !defined(USE_WINDOWS_SSPI) || defined(USE_WIN32_CRYPTO)
#define BUILDING_CURL_SMB_C
#ifdef HAVE_PROCESS_H
#include <process.h>
#ifdef CURL_WINDOWS_APP
#define getpid GetCurrentProcessId
#elif !defined(MSDOS)
#define getpid _getpid
#endif
#endif
#include "smb.h"
#include "urldata.h"
#include "sendf.h"
#include "multiif.h"
#include "connect.h"
#include "progress.h"
#include "transfer.h"
#include "vtls/vtls.h"
#include "curl_ntlm_core.h"
#include "escape.h"
#include "curl_endian.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef USE_SSL
#endif
#define MAX_PAYLOAD_SIZE  0x8000
#define MAX_MESSAGE_SIZE  (MAX_PAYLOAD_SIZE + 0x1000)
#define CLIENTNAME        "curl"
#define SERVICENAME       "?????"
#define MSGCAT(str)                             \
#define MSGCATNULL(str)                         \
#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || \
#else
#  define smb_swap16(x) (x)
#  define smb_swap32(x) (x)
#  define smb_swap64(x) (x)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef USE_NTRESPONSES
#else
#endif
#ifdef USE_SSL
#endif
#if SIZEOF_TIME_T < SIZEOF_CURL_OFF_T
#endif
#endif /* !USE_WINDOWS_SSPI || USE_WIN32_CRYPTO */
#endif /* CURL_DISABLE_SMB && USE_NTLM && CURL_SIZEOF_CURL_OFF_T > 4 */
