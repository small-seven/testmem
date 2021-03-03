#include <stdio.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/crypto.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/x509_vfy.h>
#include <openssl/x509v3.h>
#define SMIME_OP        0x10
#define SMIME_IP        0x20
#define SMIME_SIGNERS   0x40
#define SMIME_ENCRYPT   (1 | SMIME_OP)
#define SMIME_DECRYPT   (2 | SMIME_IP)
#define SMIME_SIGN      (3 | SMIME_OP | SMIME_SIGNERS)
#define SMIME_VERIFY    (4 | SMIME_IP)
#define SMIME_PK7OUT    (5 | SMIME_IP | SMIME_OP)
#define SMIME_RESIGN    (6 | SMIME_IP | SMIME_OP | SMIME_SIGNERS)
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ENCRYPT, OPT_DECRYPT, OPT_SIGN, OPT_RESIGN, OPT_VERIFY,
    OPT_PK7OUT, OPT_TEXT, OPT_NOINTERN, OPT_NOVERIFY, OPT_NOCHAIN,
    OPT_NOCERTS, OPT_NOATTR, OPT_NODETACH, OPT_NOSMIMECAP,
    OPT_BINARY, OPT_NOSIGS, OPT_STREAM, OPT_INDEF, OPT_NOINDEF,
    OPT_CRLFEOL, OPT_ENGINE, OPT_PASSIN,
    OPT_TO, OPT_FROM, OPT_SUBJECT, OPT_SIGNER, OPT_RECIP, OPT_MD,
    OPT_CIPHER, OPT_INKEY, OPT_KEYFORM, OPT_CERTFILE, OPT_CAFILE,
    OPT_R_ENUM,
    OPT_V_ENUM,
    OPT_CAPATH, OPT_NOCAFILE, OPT_NOCAPATH, OPT_IN, OPT_INFORM, OPT_OUT,
    OPT_OUTFORM, OPT_CONTENT
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_DES
#else
#endif
