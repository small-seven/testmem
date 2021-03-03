#include <stdio.h>
#include <limits.h>
#include "internal/cryptlib.h"
#include "internal/numbers.h"
#include <openssl/buffer.h>
#include <openssl/asn1.h>
#include "crypto/asn1.h"
#ifndef NO_OLD_ASN1
# ifndef OPENSSL_NO_STDIO
# endif
#endif
#ifndef OPENSSL_NO_STDIO
#endif
#define HEADER_SIZE   8
#define ASN1_CHUNK_INITIAL_SIZE (16 * 1024)
