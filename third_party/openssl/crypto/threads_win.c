#if defined(_WIN32)
# include <windows.h>
#endif
#include <openssl/crypto.h>
#if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && defined(OPENSSL_SYS_WINDOWS)
# if !defined(_WIN32_WCE)
# else
# endif
void CRYPTO_THREAD_lock_free(CRYPTO_RWLOCK *lock)
{
    if (lock == NULL)
        return;

    DeleteCriticalSection(lock);
    OPENSSL_free(lock);

    return;
}
#  define ONCE_UNINITED     0
#  define ONCE_ININIT       1
#  define ONCE_DONE         2
#endif
