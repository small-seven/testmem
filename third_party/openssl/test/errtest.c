#include <openssl/opensslconf.h>
#include <openssl/err.h>
#include "testutil.h"
#if defined(OPENSSL_SYS_WINDOWS)
# include <windows.h>
#else
# include <errno.h>
#endif
#if defined(OPENSSL_SYS_WINDOWS)
#else
#endif
