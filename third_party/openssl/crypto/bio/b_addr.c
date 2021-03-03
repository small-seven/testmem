#include <assert.h>
#include <string.h>
#include "bio_local.h"
#include <openssl/crypto.h>
#ifndef OPENSSL_NO_SOCK
#include <openssl/err.h>
#include <openssl/buffer.h>
#include "internal/thread_once.h"
void BIO_ADDR_free(BIO_ADDR *ap)
{
    OPENSSL_free(ap);
}
#ifdef AF_INET6
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_INET6
#endif
#ifdef AF_INET6
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_INET6
#endif
#ifdef AI_PASSIVE
# ifdef EAI_SYSTEM
# endif
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_INET6
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_UNIX
#endif
void BIO_ADDRINFO_free(BIO_ADDRINFO *bai)
{
    if (bai == NULL)
        return;

#ifdef AI_PASSIVE
# ifdef AF_UNIX
#  define _cond bai->bai_family != AF_UNIX
# else
#  define _cond 1
# endif
    if (_cond) {
        freeaddrinfo(bai);
        return;
    }
#endif

    /* Free manually when we know that addrinfo_wrap() was used.
     * See further comment above addrinfo_wrap()
     */
    while (bai != NULL) {
        BIO_ADDRINFO *next = bai->bai_next;
        OPENSSL_free(bai->bai_addr);
        OPENSSL_free(bai);
        bai = next;
    }
}
#ifdef AF_UNIX
#endif
#ifdef AF_INET6
#endif
#ifdef AF_UNIX
#endif
#ifdef AF_UNSPEC
#endif
#ifdef AF_UNIX
#endif
#ifdef AI_PASSIVE
# ifdef AI_ADDRCONFIG
#  ifdef AF_UNSPEC
#  endif
# endif
# if defined(AI_ADDRCONFIG) && defined(AI_NUMERICHOST)
# endif
# ifdef EAI_SYSTEM
# endif
# ifdef EAI_MEMORY
# endif
# if defined(AI_ADDRCONFIG) && defined(AI_NUMERICHOST)
# endif
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size save
# pragma pointer_size 32
#endif
#ifdef OPENSSL_SYS_WINDOWS
#else
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size restore
#endif
#ifdef _WIN64
#else
#endif
#ifndef OPENSSL_SYS_WINDOWS
# if defined(OPENSSL_SYS_VXWORKS)
# else
# endif
#else
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size save
# pragma pointer_size 32
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size restore
#endif
#ifndef OPENSSL_SYS_WINDOWS
#else
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size save
# pragma pointer_size 32
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size restore
#endif
#endif /* OPENSSL_NO_SOCK */
