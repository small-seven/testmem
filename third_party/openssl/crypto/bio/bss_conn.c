#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#ifndef OPENSSL_NO_SOCK
typedef struct bio_connect_st {
    int state;
    int connect_family;
    char *param_hostname;
    char *param_service;
    int connect_mode;

    BIO_ADDRINFO *addr_first;
    const BIO_ADDRINFO *addr_iter;
    /*
     * int socket; this will be kept in bio->num so that it is compatible
     * with the bss_sock bio
     */
    /*
     * called when the connection is initially made callback(BIO,state,ret);
     * The callback should return 'ret'.  state is for compatibility with the
     * ssl info_callback
     */
    BIO_info_cb *info_callback;
} BIO_CONNECT;
#define BIO_CONN_S_BEFORE                1
#define BIO_CONN_S_GET_ADDR              2
#define BIO_CONN_S_CREATE_SOCKET         3
#define BIO_CONN_S_CONNECT               4
#define BIO_CONN_S_OK                    5
#define BIO_CONN_S_BLOCKED_CONNECT       6
#define BIO_CONN_S_CONNECT_ERROR         7
#ifdef AF_INET6
#endif
void BIO_CONNECT_free(BIO_CONNECT *a)
{
    if (a == NULL)
        return;
    OPENSSL_free(a->param_hostname);
    OPENSSL_free(a->param_service);
    BIO_ADDRINFO_free(a->addr_first);
    OPENSSL_free(a);
}
static int conn_free(BIO *a)
{
    BIO_CONNECT *data;

    if (a == NULL)
        return 0;
    data = (BIO_CONNECT *)a->ptr;

    if (a->shutdown) {
        conn_close_socket(a);
        BIO_CONNECT_free(data);
        a->ptr = NULL;
        a->flags = 0;
        a->init = 0;
    }
    return 1;
}
# ifdef AF_INET6
# endif
#endif
