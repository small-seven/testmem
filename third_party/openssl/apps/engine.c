#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_ENGINE
#else
# include "apps.h"
# include "progs.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <openssl/err.h>
# include <openssl/engine.h>
# include <openssl/ssl.h>
# include <openssl/store.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_C, OPT_T, OPT_TT, OPT_PRE, OPT_POST,
    OPT_V = 100, OPT_VV, OPT_VVV, OPT_VVVV
} OPTION_CHOICE;
#endif
