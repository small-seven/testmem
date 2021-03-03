#include "e_os.h"
#include "internal/cryptlib.h"
#include "crypto/cryptlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <openssl/crypto.h>
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
# include <execinfo.h>
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
# include "internal/tsan_assist.h"
# define INCREMENT(x) tsan_counter(&(x))
# define FAILTEST() if (shouldfail()) return NULL
#else
# define INCREMENT(x) /* empty */
# define FAILTEST() /* empty */
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
# ifdef _WIN32
#  define random() rand()
# endif
# ifndef _WIN32
#  ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
#  endif
# endif
#endif
void *CRYPTO_malloc(size_t num, const char *file, int line)
{
    void *ret = NULL;

    INCREMENT(malloc_count);
    if (malloc_impl != NULL && malloc_impl != CRYPTO_malloc)
        return malloc_impl(num, file, line);

    if (num == 0)
        return NULL;

    FAILTEST();
    if (allow_customize) {
        /*
         * Disallow customization after the first allocation. We only set this
         * if necessary to avoid a store to the same cache line on every
         * allocation.
         */
        allow_customize = 0;
    }
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
    if (call_malloc_debug) {
        CRYPTO_mem_debug_malloc(NULL, num, 0, file, line);
        ret = malloc(num);
        CRYPTO_mem_debug_malloc(ret, num, 1, file, line);
    } else {
        ret = malloc(num);
    }
#else
    (void)(file); (void)(line);
    ret = malloc(num);
#endif

    return ret;
}
void *CRYPTO_zalloc(size_t num, const char *file, int line)
{
    void *ret = CRYPTO_malloc(num, file, line);

    FAILTEST();
    if (ret != NULL)
        memset(ret, 0, num);
    return ret;
}
void *CRYPTO_realloc(void *str, size_t num, const char *file, int line)
{
    INCREMENT(realloc_count);
    if (realloc_impl != NULL && realloc_impl != &CRYPTO_realloc)
        return realloc_impl(str, num, file, line);

    FAILTEST();
    if (str == NULL)
        return CRYPTO_malloc(num, file, line);

    if (num == 0) {
        CRYPTO_free(str, file, line);
        return NULL;
    }

#ifndef OPENSSL_NO_CRYPTO_MDEBUG
    if (call_malloc_debug) {
        void *ret;
        CRYPTO_mem_debug_realloc(str, NULL, num, 0, file, line);
        ret = realloc(str, num);
        CRYPTO_mem_debug_realloc(str, ret, num, 1, file, line);
        return ret;
    }
#else
    (void)(file); (void)(line);
#endif
    return realloc(str, num);

}
void *CRYPTO_clear_realloc(void *str, size_t old_len, size_t num,
                           const char *file, int line)
{
    void *ret = NULL;

    if (str == NULL)
        return CRYPTO_malloc(num, file, line);

    if (num == 0) {
        CRYPTO_clear_free(str, old_len, file, line);
        return NULL;
    }

    /* Can't shrink the buffer since memcpy below copies |old_len| bytes. */
    if (num < old_len) {
        OPENSSL_cleanse((char*)str + num, old_len - num);
        return str;
    }

    ret = CRYPTO_malloc(num, file, line);
    if (ret != NULL) {
        memcpy(ret, str, old_len);
        CRYPTO_clear_free(str, old_len, file, line);
    }
    return ret;
}
void CRYPTO_free(void *str, const char *file, int line)
{
    INCREMENT(free_count);
    if (free_impl != NULL && free_impl != &CRYPTO_free) {
        free_impl(str, file, line);
        return;
    }

#ifndef OPENSSL_NO_CRYPTO_MDEBUG
    if (call_malloc_debug) {
        CRYPTO_mem_debug_free(str, 0, file, line);
        free(str);
        CRYPTO_mem_debug_free(str, 1, file, line);
    } else {
        free(str);
    }
#else
    free(str);
#endif
}
void CRYPTO_clear_free(void *str, size_t num, const char *file, int line)
{
    if (str == NULL)
        return;
    if (num)
        OPENSSL_cleanse(str, num);
    CRYPTO_free(str, file, line);
}
