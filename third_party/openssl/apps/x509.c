#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/asn1.h>
#include <openssl/err.h>
#include <openssl/bn.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/objects.h>
#include <openssl/pem.h>
#ifndef OPENSSL_NO_RSA
# include <openssl/rsa.h>
#endif
#ifndef OPENSSL_NO_DSA
# include <openssl/dsa.h>
#endif
#undef POSTFIX
#define POSTFIX ".srl"
#define DEF_DAYS        30
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_KEYFORM, OPT_REQ, OPT_CAFORM,
    OPT_CAKEYFORM, OPT_SIGOPT, OPT_DAYS, OPT_PASSIN, OPT_EXTFILE,
    OPT_EXTENSIONS, OPT_IN, OPT_OUT, OPT_SIGNKEY, OPT_CA,
    OPT_CAKEY, OPT_CASERIAL, OPT_SET_SERIAL, OPT_FORCE_PUBKEY,
    OPT_ADDTRUST, OPT_ADDREJECT, OPT_SETALIAS, OPT_CERTOPT, OPT_NAMEOPT,
    OPT_C, OPT_EMAIL, OPT_OCSP_URI, OPT_SERIAL, OPT_NEXT_SERIAL,
    OPT_MODULUS, OPT_PUBKEY, OPT_X509TOREQ, OPT_TEXT, OPT_HASH,
    OPT_ISSUER_HASH, OPT_SUBJECT, OPT_ISSUER, OPT_FINGERPRINT, OPT_DATES,
    OPT_PURPOSE, OPT_STARTDATE, OPT_ENDDATE, OPT_CHECKEND, OPT_CHECKHOST,
    OPT_CHECKEMAIL, OPT_CHECKIP, OPT_NOOUT, OPT_TRUSTOUT, OPT_CLRTRUST,
    OPT_CLRREJECT, OPT_ALIAS, OPT_CACREATESERIAL, OPT_CLREXT, OPT_OCSPID,
    OPT_SUBJECT_HASH_OLD,
    OPT_ISSUER_HASH_OLD,
    OPT_BADSIG, OPT_MD, OPT_ENGINE, OPT_NOCERT, OPT_PRESERVE_DATES,
    OPT_R_ENUM, OPT_EXT
} OPTION_CHOICE;
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_MD5
#else
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
