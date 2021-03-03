#include "includes.h"
#include "common.h"
#include "asn1.h"
#include "bignum.h"
#include "rsa.h"
void crypto_rsa_free(struct crypto_rsa_key *key)
{
	if (key) {
		bignum_deinit(key->n);
		bignum_deinit(key->e);
		bignum_deinit(key->d);
		bignum_deinit(key->p);
		bignum_deinit(key->q);
		bignum_deinit(key->dmp1);
		bignum_deinit(key->dmq1);
		bignum_deinit(key->iqmp);
		os_free(key);
	}
}
