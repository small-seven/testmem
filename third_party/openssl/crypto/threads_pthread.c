#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && !defined(OPENSSL_SYS_WINDOWS)
# if defined(OPENSSL_SYS_UNIX)
#  include <sys/types.h>
#  include <unistd.h>
#endif
# ifdef PTHREAD_RWLOCK_INITIALIZER
#  define USE_RWLOCK
# endif
# ifdef USE_RWLOCK
# else
# endif
# ifdef USE_RWLOCK
# else
# endif
# ifdef USE_RWLOCK
# else
# endif
# ifdef USE_RWLOCK
# else
# endif
void CRYPTO_THREAD_lock_free(CRYPTO_RWLOCK *lock)
{
    if (lock == NULL)
        return;

# ifdef USE_RWLOCK
    pthread_rwlock_destroy(lock);
# else
    pthread_mutex_destroy(lock);
# endif
    OPENSSL_free(lock);

    return;
}
# if defined(__GNUC__) && defined(__ATOMIC_ACQ_REL)
# endif
# ifdef OPENSSL_SYS_UNIX
# endif
# ifdef OPENSSL_SYS_UNIX
# endif
#endif
