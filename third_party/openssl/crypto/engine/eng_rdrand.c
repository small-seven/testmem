#include <openssl/opensslconf.h>
#include <stdio.h>
#include <string.h>
#include "crypto/engine.h"
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/crypto.h>
#if (defined(__i386)   || defined(__i386__)   || defined(_M_IX86) || \
#else
#endif
