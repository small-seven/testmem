#include "includes.h"
#include "common.h"
#include "crypto/md5.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "x509v3.h"
#include "tlsv1_common.h"
#define NUM_TLS_CIPHER_SUITES ARRAY_SIZE(tls_cipher_suites)
#define NUM_TLS_CIPHER_DATA ARRAY_SIZE(tls_ciphers)
#ifdef CONFIG_TLSV12
#endif /* CONFIG_TLSV12 */
#ifdef CONFIG_TLSV12
#endif /* CONFIG_TLSV12 */
void tls_verify_hash_free(struct tls_verify_hash *verify)
{
	crypto_hash_finish(verify->md5_client, NULL, NULL);
	crypto_hash_finish(verify->md5_server, NULL, NULL);
	crypto_hash_finish(verify->md5_cert, NULL, NULL);
	crypto_hash_finish(verify->sha1_client, NULL, NULL);
	crypto_hash_finish(verify->sha1_server, NULL, NULL);
	crypto_hash_finish(verify->sha1_cert, NULL, NULL);
	verify->md5_client = NULL;
	verify->md5_server = NULL;
	verify->md5_cert = NULL;
	verify->sha1_client = NULL;
	verify->sha1_server = NULL;
	verify->sha1_cert = NULL;
#ifdef CONFIG_TLSV12
	crypto_hash_finish(verify->sha256_client, NULL, NULL);
	crypto_hash_finish(verify->sha256_server, NULL, NULL);
	crypto_hash_finish(verify->sha256_cert, NULL, NULL);
	verify->sha256_client = NULL;
	verify->sha256_server = NULL;
	verify->sha256_cert = NULL;
#endif /* CONFIG_TLSV12 */
}
#ifdef CONFIG_TLSV11
#endif /* CONFIG_TLSV11 */
#ifdef CONFIG_TLSV12
#endif /* CONFIG_TLSV12 */
#ifdef CONFIG_TLSV12
#endif /* CONFIG_TLSV12 */
#ifdef CONFIG_TLSV12
#endif /* CONFIG_TLSV12 */
#ifdef CONFIG_TLSV12
#endif /* CONFIG_TLSV12 */
