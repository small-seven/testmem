#include "includes.h"
#include "common.h"
#include "crypto/crypto.h"
#include "asn1.h"
#include "x509v3.h"
void x509_certificate_free(struct x509_certificate *cert)
{
	if (cert == NULL)
		return;
	if (cert->next) {
		wpa_printf(MSG_DEBUG, "X509: x509_certificate_free: cer=%p "
			   "was still on a list (next=%p)\n",
			   cert, cert->next);
	}
	x509_free_name(&cert->issuer);
	x509_free_name(&cert->subject);
	os_free(cert->public_key);
	os_free(cert->sign_value);
	os_free(cert->subject_dn);
	os_free(cert);
}
void x509_certificate_chain_free(struct x509_certificate *cert)
{
	struct x509_certificate *next;

	while (cert) {
		next = cert->next;
		cert->next = NULL;
		x509_certificate_free(cert);
		cert = next;
	}
}
