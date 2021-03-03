#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pkcs12.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_ENGINE, OPT_IN, OPT_OUT,
    OPT_TOPK8, OPT_NOITER, OPT_NOCRYPT,
#ifndef OPENSSL_NO_SCRYPT
    OPT_SCRYPT, OPT_SCRYPT_N, OPT_SCRYPT_R, OPT_SCRYPT_P,
#endif
    OPT_V2, OPT_V1, OPT_V2PRF, OPT_ITER, OPT_PASSIN, OPT_PASSOUT,
    OPT_TRADITIONAL,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
