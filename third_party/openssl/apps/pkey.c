#include <stdio.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/evp.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_PASSIN, OPT_PASSOUT, OPT_ENGINE,
    OPT_IN, OPT_OUT, OPT_PUBIN, OPT_PUBOUT, OPT_TEXT_PUB,
    OPT_TEXT, OPT_NOOUT, OPT_MD, OPT_TRADITIONAL, OPT_CHECK, OPT_PUB_CHECK
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
