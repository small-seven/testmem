#include <openssl/crypto.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include "ssl_local.h"
#ifndef OPENSSL_NO_SRP
# include <openssl/srp.h>
int SSL_CTX_SRP_CTX_free(struct ssl_ctx_st *ctx)
{
    if (ctx == NULL)
        return 0;
    OPENSSL_free(ctx->srp_ctx.login);
    OPENSSL_free(ctx->srp_ctx.info);
    BN_free(ctx->srp_ctx.N);
    BN_free(ctx->srp_ctx.g);
    BN_free(ctx->srp_ctx.s);
    BN_free(ctx->srp_ctx.B);
    BN_free(ctx->srp_ctx.A);
    BN_free(ctx->srp_ctx.a);
    BN_free(ctx->srp_ctx.b);
    BN_free(ctx->srp_ctx.v);
    memset(&ctx->srp_ctx, 0, sizeof(ctx->srp_ctx));
    ctx->srp_ctx.strength = SRP_MINIMAL_N;
    return 1;
}
int SSL_SRP_CTX_free(struct ssl_st *s)
{
    if (s == NULL)
        return 0;
    OPENSSL_free(s->srp_ctx.login);
    OPENSSL_free(s->srp_ctx.info);
    BN_free(s->srp_ctx.N);
    BN_free(s->srp_ctx.g);
    BN_free(s->srp_ctx.s);
    BN_free(s->srp_ctx.B);
    BN_free(s->srp_ctx.A);
    BN_free(s->srp_ctx.a);
    BN_free(s->srp_ctx.b);
    BN_free(s->srp_ctx.v);
    memset(&s->srp_ctx, 0, sizeof(s->srp_ctx));
    s->srp_ctx.strength = SRP_MINIMAL_N;
    return 1;
}
# define tls1_ctx_ctrl ssl3_ctx_ctrl
# define tls1_ctx_callback_ctrl ssl3_ctx_callback_ctrl
#endif
