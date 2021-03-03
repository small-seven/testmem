#include <string.h>
#include "internal/nelem.h"
#include "internal/cryptlib.h"
#include "../ssl_local.h"
#include "statem_local.h"
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_SRTP
#endif
typedef struct extensions_definition_st {
    /* The defined type for the extension */
    unsigned int type;
    /*
     * The context that this extension applies to, e.g. what messages and
     * protocol versions
     */
    unsigned int context;
    /*
     * Initialise extension before parsing. Always called for relevant contexts
     * even if extension not present
     */
    int (*init)(SSL *s, unsigned int context);
    /* Parse extension sent from client to server */
    int (*parse_ctos)(SSL *s, PACKET *pkt, unsigned int context, X509 *x,
                      size_t chainidx);
    /* Parse extension send from server to client */
    int (*parse_stoc)(SSL *s, PACKET *pkt, unsigned int context, X509 *x,
                      size_t chainidx);
    /* Construct extension sent from server to client */
    EXT_RETURN (*construct_stoc)(SSL *s, WPACKET *pkt, unsigned int context,
                                 X509 *x, size_t chainidx);
    /* Construct extension sent from client to server */
    EXT_RETURN (*construct_ctos)(SSL *s, WPACKET *pkt, unsigned int context,
                                 X509 *x, size_t chainidx);
    /*
     * Finalise extension after parsing. Always called where an extensions was
     * initialised even if the extension was not present. |sent| is set to 1 if
     * the extension was seen, or 0 otherwise.
     */
    int (*final)(SSL *s, unsigned int context, int sent);
} EXTENSION_DEFINITION;
#define INVALID_EXTENSION { 0x10000, 0, NULL, NULL, NULL, NULL, NULL, NULL }
#ifndef OPENSSL_NO_SRP
#else
#endif
#ifndef OPENSSL_NO_EC
#else
#endif
#ifndef OPENSSL_NO_OCSP
#else
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#else
#endif
#ifndef OPENSSL_NO_SRTP
#else
#endif
#ifndef OPENSSL_NO_CT
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifdef CHARSET_EBCDIC
#else
#endif
