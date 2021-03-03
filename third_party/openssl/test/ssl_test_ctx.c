#include <string.h>
#include <openssl/e_os2.h>
#include <openssl/crypto.h>
#include "internal/nelem.h"
#include "ssl_test_ctx.h"
#include "testutil.h"
#ifdef OPENSSL_SYS_WINDOWS
# define strcasecmp _stricmp
#endif
#define IMPLEMENT_SSL_TEST_BOOL_OPTION(struct_type, name, field)        \
#define IMPLEMENT_SSL_TEST_STRING_OPTION(struct_type, name, field)      \
#define IMPLEMENT_SSL_TEST_INT_OPTION(struct_type, name, field)        \
typedef struct {
    const char *name;
    int value;
} test_enum;
#ifndef OPENSSL_NO_EC
#endif
typedef struct {
    const char *name;
    int (*parse)(SSL_TEST_CTX *test_ctx, const char *value);
} ssl_test_ctx_option;
typedef struct {
    const char *name;
    int (*parse)(SSL_TEST_CLIENT_CONF *conf, const char *value);
} ssl_test_client_option;
typedef struct {
    const char *name;
    int (*parse)(SSL_TEST_SERVER_CONF *conf, const char *value);
} ssl_test_server_option;
static void ssl_test_extra_conf_free_data(SSL_TEST_EXTRA_CONF *conf)
{
    OPENSSL_free(conf->client.npn_protocols);
    OPENSSL_free(conf->server.npn_protocols);
    OPENSSL_free(conf->server2.npn_protocols);
    OPENSSL_free(conf->client.alpn_protocols);
    OPENSSL_free(conf->server.alpn_protocols);
    OPENSSL_free(conf->server2.alpn_protocols);
    OPENSSL_free(conf->client.reneg_ciphers);
    OPENSSL_free(conf->server.srp_user);
    OPENSSL_free(conf->server.srp_password);
    OPENSSL_free(conf->server2.srp_user);
    OPENSSL_free(conf->server2.srp_password);
    OPENSSL_free(conf->client.srp_user);
    OPENSSL_free(conf->client.srp_password);
    OPENSSL_free(conf->server.session_ticket_app_data);
    OPENSSL_free(conf->server2.session_ticket_app_data);
}
void SSL_TEST_CTX_free(SSL_TEST_CTX *ctx)
{
    ssl_test_ctx_free_extra_data(ctx);
    OPENSSL_free(ctx->expected_npn_protocol);
    OPENSSL_free(ctx->expected_alpn_protocol);
    OPENSSL_free(ctx->expected_session_ticket_app_data);
    sk_X509_NAME_pop_free(ctx->expected_server_ca_names, X509_NAME_free);
    sk_X509_NAME_pop_free(ctx->expected_client_ca_names, X509_NAME_free);
    OPENSSL_free(ctx->expected_cipher);
    OPENSSL_free(ctx);
}
