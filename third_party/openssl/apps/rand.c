#include "apps.h"
#include "progs.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/rand.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_OUT, OPT_ENGINE, OPT_BASE64, OPT_HEX,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
