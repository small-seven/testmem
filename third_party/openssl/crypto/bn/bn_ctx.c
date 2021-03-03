#include "internal/cryptlib.h"
#include "bn_local.h"
#define BN_CTX_POOL_SIZE        16
#define BN_CTX_START_FRAMES     32
typedef struct bignum_pool_item {
    /* The bignum values */
    BIGNUM vals[BN_CTX_POOL_SIZE];
    /* Linked-list admin */
    struct bignum_pool_item *prev, *next;
} BN_POOL_ITEM;
typedef struct bignum_pool {
    /* Linked-list admin */
    BN_POOL_ITEM *head, *current, *tail;
    /* Stack depth and allocation size */
    unsigned used, size;
} BN_POOL;
typedef struct bignum_ctx_stack {
    /* Array of indexes into the bignum stack */
    unsigned int *indexes;
    /* Number of stack frames, and the size of the allocated array */
    unsigned int depth, size;
} BN_STACK;
#ifdef BN_CTX_DEBUG
# define CTXDBG_ENTRY(str, ctx)  do { \
# define CTXDBG_EXIT(ctx)        do { \
# define CTXDBG_RET(ctx,ret)
#else
# define CTXDBG_ENTRY(str, ctx)
# define CTXDBG_EXIT(ctx)
# define CTXDBG_RET(ctx,ret)
#endif
void BN_CTX_free(BN_CTX *ctx)
{
    if (ctx == NULL)
        return;
#ifdef BN_CTX_DEBUG
    {
        BN_POOL_ITEM *pool = ctx->pool.head;
        fprintf(stderr, "BN_CTX_free, stack-size=%d, pool-bignums=%d\n",
                ctx->stack.size, ctx->pool.size);
        fprintf(stderr, "dmaxs: ");
        while (pool) {
            unsigned loop = 0;
            while (loop < BN_CTX_POOL_SIZE)
                fprintf(stderr, "%02x ", pool->vals[loop++].dmax);
            pool = pool->next;
        }
        fprintf(stderr, "\n");
    }
#endif
    BN_STACK_finish(&ctx->stack);
    BN_POOL_finish(&ctx->pool);
    OPENSSL_free(ctx);
}
