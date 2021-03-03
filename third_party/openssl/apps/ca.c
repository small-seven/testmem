#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <openssl/conf.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/bn.h>
#include <openssl/txt_db.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/objects.h>
#include <openssl/ocsp.h>
#include <openssl/pem.h>
#ifndef W_OK
# ifdef OPENSSL_SYS_VMS
#  include <unistd.h>
# elif !defined(OPENSSL_SYS_VXWORKS) && !defined(OPENSSL_SYS_WINDOWS)
#  include <sys/file.h>
# endif
#endif
#include "apps.h"
#include "progs.h"
#ifndef W_OK
# define F_OK 0
# define W_OK 2
# define R_OK 4
#endif
#ifndef PATH_MAX
# define PATH_MAX 4096
#endif
#define BASE_SECTION            "ca"
#define ENV_DEFAULT_CA          "default_ca"
#define STRING_MASK             "string_mask"
#define UTF8_IN                 "utf8"
#define ENV_NEW_CERTS_DIR       "new_certs_dir"
#define ENV_CERTIFICATE         "certificate"
#define ENV_SERIAL              "serial"
#define ENV_RAND_SERIAL         "rand_serial"
#define ENV_CRLNUMBER           "crlnumber"
#define ENV_PRIVATE_KEY         "private_key"
#define ENV_DEFAULT_DAYS        "default_days"
#define ENV_DEFAULT_STARTDATE   "default_startdate"
#define ENV_DEFAULT_ENDDATE     "default_enddate"
#define ENV_DEFAULT_CRL_DAYS    "default_crl_days"
#define ENV_DEFAULT_CRL_HOURS   "default_crl_hours"
#define ENV_DEFAULT_MD          "default_md"
#define ENV_DEFAULT_EMAIL_DN    "email_in_dn"
#define ENV_PRESERVE            "preserve"
#define ENV_POLICY              "policy"
#define ENV_EXTENSIONS          "x509_extensions"
#define ENV_CRLEXT              "crl_extensions"
#define ENV_MSIE_HACK           "msie_hack"
#define ENV_NAMEOPT             "name_opt"
#define ENV_CERTOPT             "cert_opt"
#define ENV_EXTCOPY             "copy_extensions"
#define ENV_UNIQUE_SUBJECT      "unique_subject"
#define ENV_DATABASE            "database"
typedef enum {
    REV_VALID             = -1, /* Valid (not-revoked) status */
    REV_NONE              = 0, /* No additional information */
    REV_CRL_REASON        = 1, /* Value is CRL reason code */
    REV_HOLD              = 2, /* Value is hold instruction */
    REV_KEY_COMPROMISE    = 3, /* Value is cert key compromise time */
    REV_CA_COMPROMISE     = 4  /* Value is CA key compromise time */
} REVINFO_TYPE;
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ENGINE, OPT_VERBOSE, OPT_CONFIG, OPT_NAME, OPT_SUBJ, OPT_UTF8,
    OPT_CREATE_SERIAL, OPT_MULTIVALUE_RDN, OPT_STARTDATE, OPT_ENDDATE,
    OPT_DAYS, OPT_MD, OPT_POLICY, OPT_KEYFILE, OPT_KEYFORM, OPT_PASSIN,
    OPT_KEY, OPT_CERT, OPT_SELFSIGN, OPT_IN, OPT_OUT, OPT_OUTDIR,
    OPT_SIGOPT, OPT_NOTEXT, OPT_BATCH, OPT_PRESERVEDN, OPT_NOEMAILDN,
    OPT_GENCRL, OPT_MSIE_HACK, OPT_CRLDAYS, OPT_CRLHOURS, OPT_CRLSEC,
    OPT_INFILES, OPT_SS_CERT, OPT_SPKAC, OPT_REVOKE, OPT_VALID,
    OPT_EXTENSIONS, OPT_EXTFILE, OPT_STATUS, OPT_UPDATEDB, OPT_CRLEXTS,
    OPT_RAND_SERIAL,
    OPT_R_ENUM,
    /* Do not change the order here; see related case statements below */
    OPT_CRL_REASON, OPT_CRL_HOLD, OPT_CRL_COMPROMISE, OPT_CRL_CA_COMPROMISE
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_SYS_VMS
#endif
#ifndef OPENSSL_SYS_VMS
#endif
#ifdef X509_V3
#endif
#define NUM_REASONS OSSL_NELEM(crl_reasons)
