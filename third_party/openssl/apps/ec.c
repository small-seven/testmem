#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_EC
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/evp.h>
# include <openssl/pem.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_ENGINE, OPT_IN, OPT_OUT,
    OPT_NOOUT, OPT_TEXT, OPT_PARAM_OUT, OPT_PUBIN, OPT_PUBOUT,
    OPT_PASSIN, OPT_PASSOUT, OPT_PARAM_ENC, OPT_CONV_FORM, OPT_CIPHER,
    OPT_NO_PUBLIC, OPT_CHECK
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
#endif
