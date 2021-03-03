#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/objects.h>
#include <openssl/asn1.h>
#ifndef ASN1_PARSE_MAXDEPTH
#define ASN1_PARSE_MAXDEPTH 128
#endif
