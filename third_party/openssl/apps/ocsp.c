#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_OCSP
#else
# ifdef OPENSSL_SYS_VMS
#  define _XOPEN_SOURCE_EXTENDED/* So fd_set and friends get properly defined
# endif
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>
# include "apps.h"
# include "progs.h"
# include "internal/sockets.h"
# include <openssl/e_os2.h>
# include <openssl/crypto.h>
# include <openssl/err.h>
# include <openssl/ssl.h>
# include <openssl/evp.h>
# include <openssl/bn.h>
# include <openssl/x509v3.h>
# include <openssl/rand.h>
#ifndef HAVE_FORK
# if defined(OPENSSL_SYS_VMS) || defined(OPENSSL_SYS_WINDOWS)
#  define HAVE_FORK 0
# else
#  define HAVE_FORK 1
# endif
#endif
#if HAVE_FORK
# undef NO_FORK
#else
# define NO_FORK
#endif
# if !defined(NO_FORK) && !defined(OPENSSL_NO_SOCK) \
#  define OCSP_DAEMON
#  include <sys/types.h>
#  include <sys/wait.h>
#  include <syslog.h>
#  include <signal.h>
#  define MAXERRLEN 1000 /* limit error text sent to syslog to 1000 bytes */
# else
#  undef LOG_INFO
#  undef LOG_WARNING
#  undef LOG_ERR
#  define LOG_INFO      0
#  define LOG_WARNING   1
#  define LOG_ERR       2
# endif
# if defined(OPENSSL_SYS_VXWORKS)
# endif
# define MAX_VALIDITY_PERIOD    (5 * 60)
# ifdef OCSP_DAEMON
# endif
# ifndef OPENSSL_NO_SOCK
# endif
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_OUTFILE, OPT_TIMEOUT, OPT_URL, OPT_HOST, OPT_PORT,
    OPT_IGNORE_ERR, OPT_NOVERIFY, OPT_NONCE, OPT_NO_NONCE,
    OPT_RESP_NO_CERTS, OPT_RESP_KEY_ID, OPT_NO_CERTS,
    OPT_NO_SIGNATURE_VERIFY, OPT_NO_CERT_VERIFY, OPT_NO_CHAIN,
    OPT_NO_CERT_CHECKS, OPT_NO_EXPLICIT, OPT_TRUST_OTHER,
    OPT_NO_INTERN, OPT_BADSIG, OPT_TEXT, OPT_REQ_TEXT, OPT_RESP_TEXT,
    OPT_REQIN, OPT_RESPIN, OPT_SIGNER, OPT_VAFILE, OPT_SIGN_OTHER,
    OPT_VERIFY_OTHER, OPT_CAFILE, OPT_CAPATH, OPT_NOCAFILE, OPT_NOCAPATH,
    OPT_VALIDITY_PERIOD, OPT_STATUS_AGE, OPT_SIGNKEY, OPT_REQOUT,
    OPT_RESPOUT, OPT_PATH, OPT_ISSUER, OPT_CERT, OPT_SERIAL,
    OPT_INDEX, OPT_CA, OPT_NMIN, OPT_REQUEST, OPT_NDAYS, OPT_RSIGNER,
    OPT_RKEY, OPT_ROTHER, OPT_RMD, OPT_RSIGOPT, OPT_HEADER,
    OPT_V_ENUM,
    OPT_MD,
    OPT_MULTI
} OPTION_CHOICE;
# ifdef OCSP_DAEMON
# endif
#ifndef OPENSSL_NO_SOCK
#endif
# ifdef OCSP_DAEMON
# endif
# ifdef OCSP_DAEMON
#endif
# ifdef OCSP_DAEMON
# endif
# ifndef OPENSSL_NO_SOCK
# else
# endif
# ifdef OCSP_DAEMON
# endif
# ifdef OCSP_DAEMON
#ifdef WCOREDUMP
#endif
# endif
# ifdef OPENSSL_NO_SOCK
# else
# endif
# ifndef OPENSSL_NO_SOCK
# endif
# ifdef OCSP_DAEMON
# endif
# ifdef OPENSSL_NO_SOCK
# else
#  ifdef OCSP_DAEMON
#  endif
#  ifdef OCSP_DAEMON
#  endif
#  ifdef OCSP_DAEMON
#  endif
# endif
# ifndef OPENSSL_NO_SOCK
# endif
#endif
