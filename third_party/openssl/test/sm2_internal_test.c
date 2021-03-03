#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include "testutil.h"
#ifndef OPENSSL_NO_SM2
# include "crypto/sm2.h"
#endif
#ifdef OPENSSL_NO_SM2
#else
#endif
