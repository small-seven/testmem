#include "server_setup.h"
#include "getpart.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "curl_base64.h"
#include "curl_memory.h"
#include "memdebug.h"
#define EAT_SPACE(p) while(*(p) && ISSPACE(*(p))) (p)++
#define EAT_WORD(p)  while(*(p) && !ISSPACE(*(p)) && ('>' != *(p))) (p)++
#ifdef DEBUG_GETPART
#define show(x) printf x
#else
#define show(x) Curl_nop_stmt
#endif
#if defined(_MSC_VER) && defined(_DLL)
#  pragma warning(disable:4232) /* MSVC extension, dllimport identity */
#endif
#if defined(WIN32) && defined(UNICODE)
#endif
#if defined(_MSC_VER) && defined(_DLL)
#  pragma warning(default:4232) /* MSVC extension, dllimport identity */
#endif
# define MAX_TAG_LEN 79
