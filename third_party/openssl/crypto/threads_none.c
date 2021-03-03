#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#if !defined(OPENSSL_THREADS) || defined(CRYPTO_TDEBUG)
# if defined(OPENSSL_SYS_UNIX)
#  include <sys/types.h>
#  include <unistd.h>
# endif
#define OPENSSL_CRYPTO_THREAD_LOCAL_KEY_MAX 256
# if defined(OPENSSL_SYS_UNIX)
# else
# endif
#endif
