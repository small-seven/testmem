#include "e_os.h"
#include "crypto/cryptlib.h"
#include <openssl/err.h>
#include "crypto/rand.h"
#include "internal/bio.h"
#include <openssl/evp.h>
#include "crypto/evp.h"
#include "internal/conf.h"
#include "crypto/async.h"
#include "crypto/engine.h"
#include "internal/comp.h"
#include "internal/err.h"
#include "crypto/err.h"
#include "crypto/objects.h"
#include <stdlib.h>
#include <assert.h>
#include "internal/thread_once.h"
#include "crypto/dso_conf.h"
#include "internal/dso.h"
#include "crypto/store.h"
typedef struct ossl_init_stop_st OPENSSL_INIT_STOP;
struct ossl_init_stop_st {
    void (*handler)(void);
    OPENSSL_INIT_STOP *next;
};
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#if !defined(OPENSSL_SYS_UEFI) && defined(_WIN32)
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifndef OPENSSL_SYS_UEFI
# ifdef _WIN32
# else
# endif
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#if !defined(OPENSSL_USE_NODELETE) \
# if defined(DSO_WIN32) && !defined(_WIN32_WCE)
#  ifdef OPENSSL_INIT_DEBUG
#  endif
# elif !defined(DSO_NONE)
#  ifdef OPENSSL_INIT_DEBUG
#  endif
# endif
#endif
#if !defined(OPENSSL_NO_ERR) && !defined(OPENSSL_NO_AUTOERRINIT)
# ifdef OPENSSL_INIT_DEBUG
# endif
#endif
#ifndef OPENSSL_NO_AUTOALGINIT
# ifdef OPENSSL_INIT_DEBUG
# endif
#endif
#ifndef OPENSSL_NO_AUTOALGINIT
# ifdef OPENSSL_INIT_DEBUG
# endif
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifndef OPENSSL_NO_ENGINE
# ifdef OPENSSL_INIT_DEBUG
# endif
# ifndef OPENSSL_NO_DEVCRYPTOENG
#  ifdef OPENSSL_INIT_DEBUG
#  endif
# endif
# ifndef OPENSSL_NO_RDRAND
#  ifdef OPENSSL_INIT_DEBUG
#  endif
# endif
# ifdef OPENSSL_INIT_DEBUG
# endif
# ifndef OPENSSL_NO_STATIC_ENGINE
#  if !defined(OPENSSL_NO_HW) && !defined(OPENSSL_NO_HW_PADLOCK)
#   ifdef OPENSSL_INIT_DEBUG
#   endif
#  endif
#  if defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_NO_CAPIENG)
#   ifdef OPENSSL_INIT_DEBUG
#   endif
#  endif
#  if !defined(OPENSSL_NO_AFALGENG)
#   ifdef OPENSSL_INIT_DEBUG
#   endif
#  endif
# endif
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifndef OPENSSL_NO_COMP
#ifdef OPENSSL_INIT_DEBUG
#endif
#endif
# ifdef OPENSSL_INIT_DEBUG
# endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifdef OPENSSL_INIT_DEBUG
#ifndef OPENSSL_NO_ENGINE
#endif
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
# if !defined(OPENSSL_NO_HW) && !defined(OPENSSL_NO_DEVCRYPTOENG)
# endif
# ifndef OPENSSL_NO_RDRAND
# endif
# ifndef OPENSSL_NO_STATIC_ENGINE
#  if !defined(OPENSSL_NO_HW) && !defined(OPENSSL_NO_HW_PADLOCK)
#  endif
#  if defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_NO_CAPIENG)
#  endif
#  if !defined(OPENSSL_NO_AFALGENG)
#  endif
# endif
#endif
#ifndef OPENSSL_NO_COMP
#endif
#if !defined(OPENSSL_USE_NODELETE)\
# if defined(DSO_WIN32) && !defined(_WIN32_WCE)
# elif !defined(DSO_NONE)
#  ifdef OPENSSL_INIT_DEBUG
#  endif
# endif
#endif
#ifdef OPENSSL_SYS_UNIX
#endif
