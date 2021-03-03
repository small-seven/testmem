#define xxxHASH    EVP_sha1()
#include <openssl/opensslconf.h>
#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include "dsa_local.h"
