#define USE_OPENSSL /* or USE_GNUTLS accordingly */
#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>
#define NUMT 4
#ifdef USE_OPENSSL
#include <openssl/crypto.h>
#endif
#ifdef USE_GNUTLS
#include <gcrypt.h>
#include <errno.h>
#define kill_locks()
#endif
