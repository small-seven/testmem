#include <stdio.h>
#include <string.h>
#include <openssl/asn1.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include "testutil.h"
#include "internal/nelem.h"
#define TODAY_GEN    { sizeof(TODAY_GEN_STR)-1, V_ASN1_GENERALIZEDTIME, TODAY_GEN_STR, 0 }
#define TOMORROW_GEN { sizeof(TOMORROW_GEN_STR)-1, V_ASN1_GENERALIZEDTIME, TOMORROW_GEN_STR, 0 }
#define TODAY_UTC    { sizeof(TODAY_UTC_STR)-1, V_ASN1_UTCTIME, TODAY_UTC_STR, 0 }
#define TOMORROW_UTC { sizeof(TOMORROW_UTC_STR)-1, V_ASN1_UTCTIME, TOMORROW_UTC_STR, 0 }
#ifndef __hpux
#endif
