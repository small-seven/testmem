#include <stdio.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#define IMPLEMENT_ASN1_STRING_FUNCTIONS(sname) \
void sname##_free(sname *x) \
{ \
    ASN1_STRING_free(x); \
}
