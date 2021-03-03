#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_NOOUT, OPT_PUBKEY, OPT_VERIFY, OPT_IN, OPT_OUT,
    OPT_ENGINE, OPT_KEY, OPT_CHALLENGE, OPT_PASSIN, OPT_SPKAC,
    OPT_SPKSECT, OPT_KEYFORM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
