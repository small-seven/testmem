#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#ifndef OPENSSL_NO_SOCK
typedef struct bio_accept_st {
    int state;
    int accept_family;
    int bind_mode;     /* Socket mode for BIO_listen */
    int accepted_mode; /* Socket mode for BIO_accept (set on accepted sock) */
    char *param_addr;
    char *param_serv;

    int accept_sock;

    BIO_ADDRINFO *addr_first;
    const BIO_ADDRINFO *addr_iter;
    BIO_ADDR cache_accepting_addr;   /* Useful if we asked for port 0 */
    char *cache_accepting_name, *cache_accepting_serv;
    BIO_ADDR cache_peer_addr;
    char *cache_peer_name, *cache_peer_serv;

    BIO *bio_chain;
} BIO_ACCEPT;
# define ACPT_S_BEFORE                   1
# define ACPT_S_GET_ADDR                 2
# define ACPT_S_CREATE_SOCKET            3
# define ACPT_S_LISTEN                   4
# define ACPT_S_ACCEPT                   5
# define ACPT_S_OK                       6
static void BIO_ACCEPT_free(BIO_ACCEPT *a)
{
    if (a == NULL)
        return;
    OPENSSL_free(a->param_addr);
    OPENSSL_free(a->param_serv);
    BIO_ADDRINFO_free(a->addr_first);
    OPENSSL_free(a->cache_accepting_name);
    OPENSSL_free(a->cache_accepting_serv);
    OPENSSL_free(a->cache_peer_name);
    OPENSSL_free(a->cache_peer_serv);
    BIO_free(a->bio_chain);
    OPENSSL_free(a);
}
static int acpt_free(BIO *a)
{
    BIO_ACCEPT *data;

    if (a == NULL)
        return 0;
    data = (BIO_ACCEPT *)a->ptr;

    if (a->shutdown) {
        acpt_close_socket(a);
        BIO_ACCEPT_free(data);
        a->ptr = NULL;
        a->flags = 0;
        a->init = 0;
    }
    return 1;
}
#ifdef AF_INET6
#endif
#ifdef AF_INET6
#endif
#endif
