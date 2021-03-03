#include "includes.h"
#include "common.h"
#include "crypto.h"
#include "tls/rsa.h"
#include "tls/pkcs1.h"
#include "tls/pkcs8.h"
void crypto_public_key_free(struct crypto_public_key *key)
{
	crypto_rsa_free((struct crypto_rsa_key *) key);
}
void crypto_private_key_free(struct crypto_private_key *key)
{
	crypto_rsa_free((struct crypto_rsa_key *) key);
}
