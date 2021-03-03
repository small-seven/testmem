#include "includes.h"
#include <gcrypt.h>
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
	gcry_cipher_hd_t hd = ctx;
	gcry_cipher_close(hd);
}
void aes_decrypt_deinit(void *ctx)
{
	gcry_cipher_hd_t hd = ctx;
	gcry_cipher_close(hd);
}
