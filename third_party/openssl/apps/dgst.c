#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/hmac.h>
#include <ctype.h>
#undef BUFSIZE
#define BUFSIZE 1024*8
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP, OPT_LIST,
    OPT_C, OPT_R, OPT_OUT, OPT_SIGN, OPT_PASSIN, OPT_VERIFY,
    OPT_PRVERIFY, OPT_SIGNATURE, OPT_KEYFORM, OPT_ENGINE, OPT_ENGINE_IMPL,
    OPT_HEX, OPT_BINARY, OPT_DEBUG, OPT_FIPS_FINGERPRINT,
    OPT_HMAC, OPT_MAC, OPT_SIGOPT, OPT_MACOPT,
    OPT_DIGEST,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
