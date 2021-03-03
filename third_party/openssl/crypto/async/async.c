#undef _FORTIFY_SOURCE
#include "async_local.h"
#include <openssl/err.h>
#include "crypto/cryptlib.h"
#include <string.h>
#define ASYNC_JOB_RUNNING   0
#define ASYNC_JOB_PAUSING   1
#define ASYNC_JOB_PAUSED    2
#define ASYNC_JOB_STOPPING  3
static int async_ctx_free(void)
{
    async_ctx *ctx;

    ctx = async_get_ctx();

    if (!CRYPTO_THREAD_set_local(&ctxkey, NULL))
        return 0;

    OPENSSL_free(ctx);

    return 1;
}
static void async_job_free(ASYNC_JOB *job)
{
    if (job != NULL) {
        OPENSSL_free(job->funcargs);
        async_fibre_free(&job->fibrectx);
        OPENSSL_free(job);
    }
}
