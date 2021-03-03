#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_SRP
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <openssl/conf.h>
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/txt_db.h>
# include <openssl/buffer.h>
# include <openssl/srp.h>
# include "apps.h"
# include "progs.h"
# define BASE_SECTION    "srp"
# define CONFIG_FILE "openssl.cnf"
# define ENV_DATABASE            "srpvfile"
# define ENV_DEFAULT_SRP         "default_srp"
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_VERBOSE, OPT_CONFIG, OPT_NAME, OPT_SRPVFILE, OPT_ADD,
    OPT_DELETE, OPT_MODIFY, OPT_LIST, OPT_GN, OPT_USERINFO,
    OPT_PASSIN, OPT_PASSOUT, OPT_ENGINE, OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
#endif
