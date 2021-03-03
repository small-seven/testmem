#include <string.h>
#include "internal/nelem.h"
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/obj_mac.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include "../crypto/rand/rand_local.h"
#include "../include/crypto/rand.h"
#if defined(_WIN32)
# include <windows.h>
#endif
#if defined(OPENSSL_SYS_UNIX)
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#endif
#include "testutil.h"
#include "drbgtest.h"
typedef struct drbg_selftest_data_st {
    int post;
    int nid;
    unsigned int flags;

    /* KAT data for no PR */
    const unsigned char *entropy;
    size_t entropylen;
    const unsigned char *nonce;
    size_t noncelen;
    const unsigned char *pers;
    size_t perslen;
    const unsigned char *adin;
    size_t adinlen;
    const unsigned char *entropyreseed;
    size_t entropyreseedlen;
    const unsigned char *adinreseed;
    size_t adinreseedlen;
    const unsigned char *adin2;
    size_t adin2len;
    const unsigned char *expected;
    size_t exlen;
    const unsigned char *kat2;
    size_t kat2len;

    /* KAT data for PR */
    const unsigned char *entropy_pr;
    size_t entropylen_pr;
    const unsigned char *nonce_pr;
    size_t noncelen_pr;
    const unsigned char *pers_pr;
    size_t perslen_pr;
    const unsigned char *adin_pr;
    size_t adinlen_pr;
    const unsigned char *entropypr_pr;
    size_t entropyprlen_pr;
    const unsigned char *ading_pr;
    size_t adinglen_pr;
    const unsigned char *entropyg_pr;
    size_t entropyglen_pr;
    const unsigned char *kat_pr;
    size_t katlen_pr;
    const unsigned char *kat2_pr;
    size_t kat2len_pr;
} DRBG_SELFTEST_DATA;
#define make_drbg_test_data(nid, flag, pr, post) {\
#define make_drbg_test_data_use_df(nid, pr, p) \
#define make_drbg_test_data_no_df(nid, pr, p)                      \
typedef struct test_ctx_st {
    const unsigned char *entropy;
    size_t entropylen;
    int entropycnt;
    const unsigned char *nonce;
    size_t noncelen;
    int noncecnt;
} TEST_CTX;
typedef struct hook_ctx_st {
    RAND_DRBG *drbg;
    /*
     * Currently, all DRBGs use the same get_entropy() callback.
     * The tests however, don't assume this and store
     * the original callback for every DRBG separately.
     */
    RAND_DRBG_get_entropy_fn get_entropy;
    /* forces a failure of the get_entropy() call if nonzero */
    int fail;
    /* counts successful reseeds */
    int reseed_count;
} HOOK_CTX;
#if defined(OPENSSL_SYS_UNIX)
#endif
#if defined(OPENSSL_SYS_UNIX)
#endif
#if defined(OPENSSL_THREADS)
# if defined(OPENSSL_SYS_WINDOWS)
typedef HANDLE thread_t;

static DWORD WINAPI thread_run(LPVOID arg)
{
    run_multi_thread_test();
    /*
     * Because we're linking with a static library, we must stop each
     * thread explicitly, or so says OPENSSL_thread_stop(3)
     */
    OPENSSL_thread_stop();
    return 0;
}
# else
typedef pthread_t thread_t;

static void *thread_run(void *arg)
{
    run_multi_thread_test();
    /*
     * Because we're linking with a static library, we must stop each
     * thread explicitly, or so says OPENSSL_thread_stop(3)
     */
    OPENSSL_thread_stop();
    return NULL;
}
# endif
# define THREADS 3
#endif
#ifdef OPENSSL_RAND_SEED_NONE
#endif
#if defined(OPENSSL_THREADS)
#endif
