#include "includes.h"
#include <tomcrypt.h>
#include "common.h"
#include "crypto.h"
#ifndef mp_init_multi
#define mp_init_multi                ltc_init_multi
#define mp_clear_multi               ltc_deinit_multi
#define mp_unsigned_bin_size(a)      ltc_mp.unsigned_size(a)
#define mp_to_unsigned_bin(a, b)     ltc_mp.unsigned_write(a, b)
#define mp_read_unsigned_bin(a, b, c) ltc_mp.unsigned_read(a, b, c)
#define mp_exptmod(a,b,c,d)          ltc_mp.exptmod(a,b,c,d)
#endif
void aes_encrypt_deinit(void *ctx)
{
	symmetric_key *skey = ctx;
	aes_done(skey);
	os_free(skey);
}
void aes_decrypt_deinit(void *ctx)
{
	symmetric_key *skey = ctx;
	aes_done(skey);
	os_free(skey);
}
void crypto_public_key_free(struct crypto_public_key *key)
{
	if (key) {
		rsa_free(&key->rsa);
		os_free(key);
	}
}
void crypto_private_key_free(struct crypto_private_key *key)
{
	if (key) {
		rsa_free(&key->rsa);
		os_free(key);
	}
}
void crypto_global_deinit(void)
{
}
#ifdef CONFIG_MODEXP
#endif /* CONFIG_MODEXP */
