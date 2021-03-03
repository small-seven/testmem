#include "includes.h"
#include <linux/if_alg.h>
#include "common.h"
#include "crypto.h"
#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha384.h"
#include "aes.h"
#ifndef SOL_ALG
#define SOL_ALG 279
#endif /* SOL_ALG */
void aes_encrypt_deinit(void *ctx)
{
	linux_af_alg_skcipher_deinit(ctx);
}
void aes_decrypt_deinit(void *ctx)
{
	linux_af_alg_skcipher_deinit(ctx);
}
void crypto_global_deinit(void)
{
}
