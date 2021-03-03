#include "includes.h"
#include <nettle/nettle-meta.h>
#include <nettle/des.h>
#undef des_encrypt
#include <nettle/hmac.h>
#include <nettle/aes.h>
#undef aes_encrypt
#undef aes_decrypt
#include <nettle/arcfour.h>
#include <nettle/bignum.h>
#include "common.h"
#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha384.h"
#include "sha512.h"
#include "crypto.h"
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA512
#endif /* CONFIG_SHA512 */
void aes_encrypt_deinit(void *ctx)
{
	struct aes_ctx *actx = ctx;
	bin_clear_free(actx, sizeof(*actx));
}
void aes_decrypt_deinit(void *ctx)
{
	struct aes_ctx *actx = ctx;
	bin_clear_free(actx, sizeof(*actx));
}
