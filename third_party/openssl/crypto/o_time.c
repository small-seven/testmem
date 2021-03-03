#include <openssl/e_os2.h>
#include <string.h>
#include <openssl/crypto.h>
#if defined(OPENSSL_THREADS) && defined(OPENSSL_SYS_VMS)
#if defined(OPENSSL_SYS_VMS) && __INITIAL_POINTER_SIZE
# pragma pointer_size save
# pragma pointer_size 32
#endif
#if defined OPENSSL_SYS_VMS && __INITIAL_POINTER_SIZE
# pragma pointer_size restore
#endif
#elif defined(OPENSSL_THREADS) && !defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_SYS_MACOSX)
#elif defined (OPENSSL_SYS_WINDOWS) && defined(_MSC_VER) && _MSC_VER >= 1400
#else
#endif
#define SECS_PER_DAY (24 * 60 * 60)
