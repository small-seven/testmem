#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/pem.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ENGINE, OPT_CAPATH, OPT_CAFILE, OPT_NOCAPATH, OPT_NOCAFILE,
    OPT_UNTRUSTED, OPT_TRUSTED, OPT_CRLFILE, OPT_CRL_DOWNLOAD, OPT_SHOW_CHAIN,
    OPT_V_ENUM, OPT_NAMEOPT,
    OPT_VERBOSE
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
