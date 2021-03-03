#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32)
# include <windows.h>
#endif
#include <openssl/e_os2.h>
#include <openssl/async.h>
#include <openssl/ssl.h>
#ifndef OPENSSL_NO_SOCK
#if defined(OPENSSL_SYS_VMS_DECC) && !defined(__U_INT)
# define __U_INT
typedef unsigned int u_int;
#endif

#include <openssl/bn.h>
#include "apps.h"
#include "progs.h"
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/ocsp.h>
#ifndef OPENSSL_NO_DH
# include <openssl/dh.h>
#endif
#ifndef OPENSSL_NO_RSA
# include <openssl/rsa.h>
#endif
#ifndef OPENSSL_NO_SRP
# include <openssl/srp.h>
#endif
#include "s_apps.h"
#include "timeouts.h"
#ifdef CHARSET_EBCDIC
#include <openssl/ebcdic.h>
#endif
#include "internal/sockets.h"

static int not_resumable_sess_cb(SSL *s, int is_forward_secure);
static int sv_body(int s, int stype, int prot, unsigned char *context);
static int www_body(int s, int stype, int prot, unsigned char *context);
static int rev_body(int s, int stype, int prot, unsigned char *context);
static void close_accept_socket(void);
static int init_ssl_connection(SSL *s);
static void print_stats(BIO *bp, SSL_CTX *ctx);
static int generate_session_id(SSL *ssl, unsigned char *id,
                               unsigned int *id_len);
static void init_session_cache_ctx(SSL_CTX *sctx);
static void free_sessions(void);
#ifndef OPENSSL_NO_DH
static DH *load_dh_param(const char *dhfile);
#endif
static void print_connection_info(SSL *con);

static const int bufsize = 16 * 1024;
static int accept_socket = -1;

#define TEST_CERT       "server.pem"
#define TEST_CERT2      "server2.pem"

static int s_nbio = 0;
static int s_nbio_test = 0;
static int s_crlf = 0;
static SSL_CTX *ctx = NULL;
static SSL_CTX *ctx2 = NULL;
static int www = 0;

static BIO *bio_s_out = NULL;
static BIO *bio_s_msg = NULL;
static int s_debug = 0;
static int s_tlsextdebug = 0;
static int s_msg = 0;
static int s_quiet = 0;
static int s_ign_eof = 0;
static int s_brief = 0;

static char *keymatexportlabel = NULL;
static int keymatexportlen = 20;

static int async = 0;

static const char *session_id_prefix = NULL;

#ifndef OPENSSL_NO_DTLS
static int enable_timeouts = 0;
static long socket_mtu;
#endif

/*
 * We define this but make it always be 0 in no-dtls builds to simplify the
 * code.
 */
static int dtlslisten = 0;
static int stateless = 0;

static int early_data = 0;
static SSL_SESSION *psksess = NULL;

static char *psk_identity = "Client_identity";
char *psk_key = NULL;           /* by default PSK is not used */

#ifndef OPENSSL_NO_PSK
static unsigned int psk_server_cb(SSL *ssl, const char *identity,
                                  unsigned char *psk,
                                  unsigned int max_psk_len)
{
    long key_len = 0;
    unsigned char *key;

    if (s_debug)
        BIO_printf(bio_s_out, "psk_server_cb\n");
    if (identity == NULL) {
        BIO_printf(bio_err, "Error: client did not send PSK identity\n");
        goto out_err;
    }
#endif
#ifndef OPENSSL_NO_SRP
typedef struct srpsrvparm_st {
    char *login;
    SRP_VBASE *vb;
    SRP_user_pwd *user;
} srpsrvparm;
#endif
#ifdef CHARSET_EBCDIC
# define BIO_TYPE_EBCDIC_FILTER  (18|0x0200)
typedef struct {
    size_t alloced;
    char buff[1];
} EBCDIC_OUTBUFF;
static int ebcdic_free(BIO *a)
{
    EBCDIC_OUTBUFF *wbuf;

    if (a == NULL)
        return 0;
    wbuf = BIO_get_data(a);
    OPENSSL_free(wbuf);
    BIO_set_data(a, NULL);
    BIO_set_init(a, 0);

    return 1;
}
#endif
typedef struct tlsextctx_st {
    char *servername;
    BIO *biodebug;
    int extension_error;
} tlsextctx;
typedef struct tlsextstatusctx_st {
    int timeout;
    /* File to load OCSP Response from (or NULL if no file) */
    char *respin;
    /* Default responder to use */
    char *host, *path, *port;
    int use_ssl;
    int verbose;
} tlsextstatusctx;
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
typedef struct tlsextnextprotoctx_st {
    unsigned char *data;
    size_t len;
} tlsextnextprotoctx;
#endif                         /* ndef OPENSSL_NO_NEXTPROTONEG */
typedef struct tlsextalpnctx_st {
    unsigned char *data;
    size_t len;
} tlsextalpnctx;
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP, OPT_ENGINE,
    OPT_4, OPT_6, OPT_ACCEPT, OPT_PORT, OPT_UNIX, OPT_UNLINK, OPT_NACCEPT,
    OPT_VERIFY, OPT_NAMEOPT, OPT_UPPER_V_VERIFY, OPT_CONTEXT, OPT_CERT, OPT_CRL,
    OPT_CRL_DOWNLOAD, OPT_SERVERINFO, OPT_CERTFORM, OPT_KEY, OPT_KEYFORM,
    OPT_PASS, OPT_CERT_CHAIN, OPT_DHPARAM, OPT_DCERTFORM, OPT_DCERT,
    OPT_DKEYFORM, OPT_DPASS, OPT_DKEY, OPT_DCERT_CHAIN, OPT_NOCERT,
    OPT_CAPATH, OPT_NOCAPATH, OPT_CHAINCAPATH, OPT_VERIFYCAPATH, OPT_NO_CACHE,
    OPT_EXT_CACHE, OPT_CRLFORM, OPT_VERIFY_RET_ERROR, OPT_VERIFY_QUIET,
    OPT_BUILD_CHAIN, OPT_CAFILE, OPT_NOCAFILE, OPT_CHAINCAFILE,
    OPT_VERIFYCAFILE, OPT_NBIO, OPT_NBIO_TEST, OPT_IGN_EOF, OPT_NO_IGN_EOF,
    OPT_DEBUG, OPT_TLSEXTDEBUG, OPT_STATUS, OPT_STATUS_VERBOSE,
    OPT_STATUS_TIMEOUT, OPT_STATUS_URL, OPT_STATUS_FILE, OPT_MSG, OPT_MSGFILE,
    OPT_TRACE, OPT_SECURITY_DEBUG, OPT_SECURITY_DEBUG_VERBOSE, OPT_STATE,
    OPT_CRLF, OPT_QUIET, OPT_BRIEF, OPT_NO_DHE,
    OPT_NO_RESUME_EPHEMERAL, OPT_PSK_IDENTITY, OPT_PSK_HINT, OPT_PSK,
    OPT_PSK_SESS, OPT_SRPVFILE, OPT_SRPUSERSEED, OPT_REV, OPT_WWW,
    OPT_UPPER_WWW, OPT_HTTP, OPT_ASYNC, OPT_SSL_CONFIG,
    OPT_MAX_SEND_FRAG, OPT_SPLIT_SEND_FRAG, OPT_MAX_PIPELINES, OPT_READ_BUF,
    OPT_SSL3, OPT_TLS1_3, OPT_TLS1_2, OPT_TLS1_1, OPT_TLS1, OPT_DTLS, OPT_DTLS1,
    OPT_DTLS1_2, OPT_SCTP, OPT_TIMEOUT, OPT_MTU, OPT_LISTEN, OPT_STATELESS,
    OPT_ID_PREFIX, OPT_SERVERNAME, OPT_SERVERNAME_FATAL,
    OPT_CERT2, OPT_KEY2, OPT_NEXTPROTONEG, OPT_ALPN,
    OPT_SRTP_PROFILES, OPT_KEYMATEXPORT, OPT_KEYMATEXPORTLEN,
    OPT_KEYLOG_FILE, OPT_MAX_EARLY, OPT_RECV_MAX_EARLY, OPT_EARLY_DATA,
    OPT_S_NUM_TICKETS, OPT_ANTI_REPLAY, OPT_NO_ANTI_REPLAY, OPT_SCTP_LABEL_BUG,
    OPT_R_ENUM,
    OPT_S_ENUM,
    OPT_V_ENUM,
    OPT_X_ENUM
} OPTION_CHOICE;
#ifdef AF_UNIX
#endif
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
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
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#define IS_PROT_FLAG(o) \
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_INET6
#ifdef AF_UNIX
#endif
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS
#endif
# ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_DTLS
#endif
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#if !defined(OPENSSL_NO_RSA) || !defined(OPENSSL_NO_DSA) || !defined(OPENSSL_NO_EC)
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifdef AF_UNIX
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifdef CHARSET_EBCDIC
#endif
#if !(defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_MSDOS))
#endif
#ifndef OPENSSL_NO_DTLS
# ifndef OPENSSL_NO_SCTP
# else
# endif
#endif
#ifndef OPENSSL_NO_DTLS
# ifndef OPENSSL_NO_SCTP
# endif
# ifndef OPENSSL_NO_SCTP
# endif
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#if !defined(OPENSSL_SYS_WINDOWS) && !defined(OPENSSL_SYS_MSDOS)
#endif
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_MSDOS)
#else
#endif
#ifndef OPENSSL_NO_HEARTBEATS
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef RENEG
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef CERT_CB_TEST_RETRY
#endif
#ifndef OPENSSL_NO_SRP
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_EC
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifdef RENEG
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_SRP
#endif
#if !defined(OPENSSL_SYS_MSDOS)
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifdef RENEG
#endif
#ifdef RENEG
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifndef OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SRP
#endif
#if !defined(OPENSSL_SYS_MSDOS)
#endif
#define MAX_SESSION_ID_ATTEMPTS 10
typedef struct simple_ssl_session_st {
    unsigned char *id;
    unsigned int idlen;
    unsigned char *der;
    int derlen;
    struct simple_ssl_session_st *next;
} simple_ssl_session;
#endif                          /* OPENSSL_NO_SOCK */
