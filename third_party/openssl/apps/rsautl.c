#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_RSA
#else
# include "apps.h"
# include "progs.h"
# include <string.h>
# include <openssl/err.h>
# include <openssl/pem.h>
# include <openssl/rsa.h>
# define RSA_SIGN        1
# define RSA_VERIFY      2
# define RSA_ENCRYPT     3
# define RSA_DECRYPT     4
# define KEY_PRIVKEY     1
# define KEY_PUBKEY      2
# define KEY_CERT        3
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ENGINE, OPT_IN, OPT_OUT, OPT_ASN1PARSE, OPT_HEXDUMP,
    OPT_RAW, OPT_OAEP, OPT_SSL, OPT_PKCS, OPT_X931,
    OPT_SIGN, OPT_VERIFY, OPT_REV, OPT_ENCRYPT, OPT_DECRYPT,
    OPT_PUBIN, OPT_CERTIN, OPT_INKEY, OPT_PASSIN, OPT_KEYFORM,
    OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
#endif
