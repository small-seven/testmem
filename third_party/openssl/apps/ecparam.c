#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_EC
#else
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/bn.h>
# include <openssl/ec.h>
# include <openssl/x509.h>
# include <openssl/pem.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_IN, OPT_OUT, OPT_TEXT, OPT_C,
    OPT_CHECK, OPT_LIST_CURVES, OPT_NO_SEED, OPT_NOOUT, OPT_NAME,
    OPT_CONV_FORM, OPT_PARAM_ENC, OPT_GENKEY, OPT_ENGINE,
    OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
#endif
