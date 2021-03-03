#include "e_os.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <openssl/e_os2.h>
#ifndef OPENSSL_NO_SOCK
#if defined(OPENSSL_SYS_VMS_DECC) && !defined(__U_INT)
# define __U_INT
typedef unsigned int u_int;
#endif

#include "apps.h"
#include "progs.h"
#include <openssl/x509.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/ocsp.h>
#include <openssl/bn.h>
#include <openssl/async.h>
#ifndef OPENSSL_NO_SRP
# include <openssl/srp.h>
#endif
#ifndef OPENSSL_NO_CT
# include <openssl/ct.h>
#endif
#include "s_apps.h"
#include "timeouts.h"
#include "internal/sockets.h"

#if defined(__has_feature)
# if __has_feature(memory_sanitizer)
#  include <sanitizer/msan_interface.h>
# endif
#endif

#undef BUFSIZZ
#define BUFSIZZ 1024*8
#define S_CLIENT_IRC_READ_TIMEOUT 8

static char *prog;
static int c_debug = 0;
static int c_showcerts = 0;
static char *keymatexportlabel = NULL;
static int keymatexportlen = 20;
static BIO *bio_c_out = NULL;
static int c_quiet = 0;
static char *sess_out = NULL;
static SSL_SESSION *psksess = NULL;

static void print_stuff(BIO *berr, SSL *con, int full);
#ifndef OPENSSL_NO_OCSP
static int ocsp_resp_cb(SSL *s, void *arg);
#endif
static int ldap_ExtendedResponse_parse(const char *buf, long rem);
static int is_dNS_name(const char *host);

static int saved_errno;

static void save_errno(void)
{
    saved_errno = errno;
    errno = 0;
}
#ifndef OPENSSL_NO_PSK
#endif
typedef struct tlsextctx_st {
    BIO *biodebug;
    int ack;
} tlsextctx;
#ifndef OPENSSL_NO_SRP
typedef struct srp_arg_st {
    char *srppassin;
    char *srplogin;
    int msg;                    /* copy from c_msg */
    int debug;                  /* copy from c_debug */
    int amp;                    /* allow more groups */
    int strength;               /* minimal size for N */
} SRP_ARG;
# define SRP_NUMBER_ITERATIONS_FOR_PRIME 64
# define PWD_STRLEN 1024
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
typedef struct tlsextnextprotoctx_st {
    unsigned char *data;
    size_t len;
    int status;
} tlsextnextprotoctx;
#endif                         /* ndef OPENSSL_NO_NEXTPROTONEG */
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_4, OPT_6, OPT_HOST, OPT_PORT, OPT_CONNECT, OPT_BIND, OPT_UNIX,
    OPT_XMPPHOST, OPT_VERIFY, OPT_NAMEOPT,
    OPT_CERT, OPT_CRL, OPT_CRL_DOWNLOAD, OPT_SESS_OUT, OPT_SESS_IN,
    OPT_CERTFORM, OPT_CRLFORM, OPT_VERIFY_RET_ERROR, OPT_VERIFY_QUIET,
    OPT_BRIEF, OPT_PREXIT, OPT_CRLF, OPT_QUIET, OPT_NBIO,
    OPT_SSL_CLIENT_ENGINE, OPT_IGN_EOF, OPT_NO_IGN_EOF,
    OPT_DEBUG, OPT_TLSEXTDEBUG, OPT_STATUS, OPT_WDEBUG,
    OPT_MSG, OPT_MSGFILE, OPT_ENGINE, OPT_TRACE, OPT_SECURITY_DEBUG,
    OPT_SECURITY_DEBUG_VERBOSE, OPT_SHOWCERTS, OPT_NBIO_TEST, OPT_STATE,
    OPT_PSK_IDENTITY, OPT_PSK, OPT_PSK_SESS,
#ifndef OPENSSL_NO_SRP
    OPT_SRPUSER, OPT_SRPPASS, OPT_SRP_STRENGTH, OPT_SRP_LATEUSER,
    OPT_SRP_MOREGROUPS,
#endif
    OPT_SSL3, OPT_SSL_CONFIG,
    OPT_TLS1_3, OPT_TLS1_2, OPT_TLS1_1, OPT_TLS1, OPT_DTLS, OPT_DTLS1,
    OPT_DTLS1_2, OPT_SCTP, OPT_TIMEOUT, OPT_MTU, OPT_KEYFORM, OPT_PASS,
    OPT_CERT_CHAIN, OPT_CAPATH, OPT_NOCAPATH, OPT_CHAINCAPATH, OPT_VERIFYCAPATH,
    OPT_KEY, OPT_RECONNECT, OPT_BUILD_CHAIN, OPT_CAFILE, OPT_NOCAFILE,
    OPT_CHAINCAFILE, OPT_VERIFYCAFILE, OPT_NEXTPROTONEG, OPT_ALPN,
    OPT_SERVERINFO, OPT_STARTTLS, OPT_SERVERNAME, OPT_NOSERVERNAME, OPT_ASYNC,
    OPT_USE_SRTP, OPT_KEYMATEXPORT, OPT_KEYMATEXPORTLEN, OPT_PROTOHOST,
    OPT_MAXFRAGLEN, OPT_MAX_SEND_FRAG, OPT_SPLIT_SEND_FRAG, OPT_MAX_PIPELINES,
    OPT_READ_BUF, OPT_KEYLOG_FILE, OPT_EARLY_DATA, OPT_REQCAFILE,
    OPT_V_ENUM,
    OPT_X_ENUM,
    OPT_S_ENUM,
    OPT_FALLBACKSCSV, OPT_NOCMDS, OPT_PROXY, OPT_DANE_TLSA_DOMAIN,
#ifndef OPENSSL_NO_CT
    OPT_CT, OPT_NOCT, OPT_CTLOG_FILE,
#endif
    OPT_DANE_TLSA_RRDATA, OPT_DANE_EE_NO_NAME,
    OPT_ENABLE_PHA,
    OPT_SCTP_LABEL_BUG,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifdef AF_UNIX
#endif
#ifdef AF_INET6
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_SSL3
#endif
#ifndef OPENSSL_NO_TLS1
#endif
#ifndef OPENSSL_NO_TLS1_1
#endif
#ifndef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS1
#endif
#ifndef OPENSSL_NO_DTLS1_2
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifdef WATT32
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_CT
#endif
typedef enum PROTOCOL_choice {
    PROTO_OFF,
    PROTO_SMTP,
    PROTO_POP3,
    PROTO_IMAP,
    PROTO_FTP,
    PROTO_TELNET,
    PROTO_XMPP,
    PROTO_XMPP_SERVER,
    PROTO_CONNECT,
    PROTO_IRC,
    PROTO_MYSQL,
    PROTO_POSTGRES,
    PROTO_LMTP,
    PROTO_NNTP,
    PROTO_SIEVE,
    PROTO_LDAP
} PROTOCOL_CHOICE;
#define IS_INET_FLAG(o) \
#define IS_UNIX_FLAG(o) (o == OPT_UNIX)
#define IS_PROT_FLAG(o) \
#if !defined(OPENSSL_SYS_WINDOWS) && !defined(OPENSSL_SYS_MSDOS)
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_MSDOS)
#endif
#define MAX_SI_TYPES 100
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if defined(__has_feature)
# if __has_feature(memory_sanitizer)
# endif
#endif
#ifdef AF_INET6
#endif
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifdef WATT32
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS1
#endif
#ifndef OPENSSL_NO_DTLS1_2
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_CT
#endif
# ifndef OPENSSL_NO_SRP
# endif
#ifndef OPENSSL_NO_DTLS
#ifndef OPENSSL_NO_SCTP
#endif
#endif /* OPENSSL_NO_DTLS */
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#if !defined(OPENSSL_SYS_WINDOWS) && !defined(OPENSSL_SYS_MSDOS)
#if !defined(OPENSSL_SYS_VMS)
#endif
#else
#endif
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_MSDOS)
#else
#endif
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_MSDOS) || defined(OPENSSL_SYS_VMS)
#else
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef RENEG
#endif
#if defined(OPENSSL_SYS_MSDOS)
#else
#endif
#if !defined(OPENSSL_SYS_WINDOWS) && !defined(OPENSSL_SYS_MSDOS)
#endif
#ifndef OPENSSL_NO_HEARTBEATS
#endif
#ifdef CHARSET_EBCDIC
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifdef SSL_DEBUG
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_SRTP
#endif
# ifndef OPENSSL_NO_OCSP
# endif
#endif                          /* OPENSSL_NO_SOCK */
