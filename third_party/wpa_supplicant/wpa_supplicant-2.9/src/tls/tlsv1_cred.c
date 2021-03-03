#include "includes.h"
#include "common.h"
#include "base64.h"
#include "crypto/crypto.h"
#include "crypto/sha1.h"
#include "pkcs5.h"
#include "pkcs8.h"
#include "x509v3.h"
#include "tlsv1_cred.h"
void tlsv1_cred_free(struct tlsv1_credentials *cred)
{
	if (cred == NULL)
		return;

	x509_certificate_chain_free(cred->trusted_certs);
	x509_certificate_chain_free(cred->cert);
	crypto_private_key_free(cred->key);
	os_free(cred->dh_p);
	os_free(cred->dh_g);
	os_free(cred->ocsp_stapling_response);
	os_free(cred->ocsp_stapling_response_multi);
	os_free(cred);
}
#ifdef PKCS12_FUNCS
#endif /* PKCS12_FUNCS */
#ifdef PKCS12_FUNCS
#endif /* PKCS12_FUNCS */
