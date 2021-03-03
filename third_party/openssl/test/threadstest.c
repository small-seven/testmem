#if defined(_WIN32)
# include <windows.h>
#endif
#include <openssl/crypto.h>
#include "testutil.h"
#if !defined(OPENSSL_THREADS) || defined(CRYPTO_TDEBUG)
typedef unsigned int thread_t;

static int run_thread(thread_t *t, void (*f)(void))
{
    f();
    return 1;
}
#elif defined(OPENSSL_SYS_WINDOWS)
typedef HANDLE thread_t;

static DWORD WINAPI thread_run(LPVOID arg)
{
    void (*f)(void);

    *(void **) (&f) = arg;

    f();
    return 0;
}
#else
typedef pthread_t thread_t;

static void *thread_run(void *arg)
{
    void (*f)(void);

    *(void **) (&f) = arg;

    f();
    return NULL;
}
#endif
#if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG)
# if !defined(OPENSSL_SYS_WINDOWS)
# endif
#endif
