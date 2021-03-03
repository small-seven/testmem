#include "includes.h"
#include "common.h"
#include "crypto.h"
#include "aes_i.h"
#ifndef FULL_UNROLL
#endif /* ?FULL_UNROLL */
#define ROUND(i,d,s) \
#ifdef FULL_UNROLL
#else  /* !FULL_UNROLL */
#endif /* ?FULL_UNROLL */
#undef ROUND
void aes_encrypt_deinit(void *ctx)
{
	os_memset(ctx, 0, AES_PRIV_SIZE);
	os_free(ctx);
}
