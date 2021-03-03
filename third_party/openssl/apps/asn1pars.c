#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/asn1t.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_IN, OPT_OUT, OPT_INDENT, OPT_NOOUT,
    OPT_OID, OPT_OFFSET, OPT_LENGTH, OPT_DUMP, OPT_DLIMIT,
    OPT_STRPARSE, OPT_GENSTR, OPT_GENCONF, OPT_STRICTPEM,
    OPT_ITEM
} OPTION_CHOICE;
