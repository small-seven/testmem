#include <string.h>
#include <openssl/bio.h>
#include <openssl/x509_vfy.h>
#include <openssl/ssl.h>
#ifndef OPENSSL_NO_SRP
#include <openssl/srp.h>
#endif
#include "../ssl/ssl_local.h"
#include "internal/sockets.h"
#include "internal/nelem.h"
#include "handshake_helper.h"
#include "testutil.h"
#if !defined(OPENSSL_NO_SCTP) && !defined(OPENSSL_NO_SOCK)
#include <netinet/sctp.h>
#endif
void HANDSHAKE_RESULT_free(HANDSHAKE_RESULT *result)
{
    if (result == NULL)
        return;
    OPENSSL_free(result->client_npn_negotiated);
    OPENSSL_free(result->server_npn_negotiated);
    OPENSSL_free(result->client_alpn_negotiated);
    OPENSSL_free(result->server_alpn_negotiated);
    OPENSSL_free(result->result_session_ticket_app_data);
    sk_X509_NAME_pop_free(result->server_ca_names, X509_NAME_free);
    sk_X509_NAME_pop_free(result->client_ca_names, X509_NAME_free);
    OPENSSL_free(result->cipher);
    OPENSSL_free(result);
}
typedef struct handshake_ex_data_st {
    int alert_sent;
    int num_fatal_alerts_sent;
    int alert_received;
    int session_ticket_do_not_call;
    ssl_servername_t servername;
} HANDSHAKE_EX_DATA;
typedef struct ctx_data_st {
    unsigned char *npn_protocols;
    size_t npn_protocols_len;
    unsigned char *alpn_protocols;
    size_t alpn_protocols_len;
    char *srp_user;
    char *srp_password;
    char *session_ticket_app_data;
} CTX_DATA;
static void ctx_data_free_data(CTX_DATA *ctx_data)
{
    OPENSSL_free(ctx_data->npn_protocols);
    ctx_data->npn_protocols = NULL;
    OPENSSL_free(ctx_data->alpn_protocols);
    ctx_data->alpn_protocols = NULL;
    OPENSSL_free(ctx_data->srp_user);
    ctx_data->srp_user = NULL;
    OPENSSL_free(ctx_data->srp_password);
    ctx_data->srp_password = NULL;
    OPENSSL_free(ctx_data->session_ticket_app_data);
    ctx_data->session_ticket_app_data = NULL;
}
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRP
#endif  /* !OPENSSL_NO_SRP */
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#if !defined(OPENSSL_NO_CT) && !defined(OPENSSL_NO_EC)
#endif
#ifndef OPENSSL_NO_SRP
#endif  /* !OPENSSL_NO_SRP */
typedef enum {
    PEER_SUCCESS,
    PEER_RETRY,
    PEER_ERROR,
    PEER_WAITING,
    PEER_TEST_FAILURE
} peer_status_t;
typedef struct peer_st {
    SSL *ssl;
    /* Buffer lengths are int to match the SSL read/write API. */
    unsigned char *write_buf;
    int write_buf_len;
    unsigned char *read_buf;
    int read_buf_len;
    int bytes_to_write;
    int bytes_to_read;
    peer_status_t status;
} PEER;
static void peer_free_data(PEER *peer)
{
    SSL_free(peer->ssl);
    OPENSSL_free(peer->write_buf);
    OPENSSL_free(peer->read_buf);
}
typedef enum {
    HANDSHAKE,
    RENEG_APPLICATION_DATA,
    RENEG_SETUP,
    RENEG_HANDSHAKE,
    APPLICATION_DATA,
    SHUTDOWN,
    CONNECTION_DONE
} connect_phase_t;
typedef enum {
    /* Both parties succeeded. */
    HANDSHAKE_SUCCESS,
    /* Client errored. */
    CLIENT_ERROR,
    /* Server errored. */
    SERVER_ERROR,
    /* Peers are in inconsistent state. */
    INTERNAL_ERROR,
    /* One or both peers not done. */
    HANDSHAKE_RETRY
} handshake_status_t;
#ifndef OPENSSL_NO_EC
#endif
#if !defined(OPENSSL_NO_SCTP) && !defined(OPENSSL_NO_SOCK)
#endif
#if !defined(OPENSSL_NO_SCTP) && !defined(OPENSSL_NO_SOCK)
#endif
#if !defined(OPENSSL_NO_SCTP) && !defined(OPENSSL_NO_SOCK)
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
