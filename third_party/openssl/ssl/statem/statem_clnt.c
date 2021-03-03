#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "../ssl_local.h"
#include "statem_local.h"
#include <openssl/buffer.h>
#include <openssl/rand.h>
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/dh.h>
#include <openssl/bn.h>
#include <openssl/engine.h>
#include <internal/cryptlib.h>
#if DTLS_MAX_VERSION != DTLS1_2_VERSION
# error TODO(DTLS1.3): Restore digest for PHA before adding message.
#endif
#if defined(OPENSSL_NO_NEXTPROTONEG)
#else
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifdef OPENSSL_NO_COMP
#else
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if !defined(OPENSSL_NO_NEXTPROTONEG)
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_COMP
#endif
#ifdef OPENSSL_NO_COMP
#else
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
#endif
#ifndef OPENSSL_NO_PSK
#else
#endif
#ifndef OPENSSL_NO_SRP
#else
#endif
#ifndef OPENSSL_NO_DH
#else
#endif
#ifndef OPENSSL_NO_EC
#else
#endif
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
#endif
#ifdef SSL_DEBUG
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#else
#endif
#ifndef OPENSSL_NO_RSA
#else
#endif
#ifndef OPENSSL_NO_DH
#else
#endif
#ifndef OPENSSL_NO_EC
#else
#endif
#ifndef OPENSSL_NO_GOST
#else
#endif
#ifndef OPENSSL_NO_SRP
#else
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifdef OPENSSL_MAX_TLS1_2_CIPHER_LENGTH
# if OPENSSL_MAX_TLS1_2_CIPHER_LENGTH < 6
#  error Max cipher length too short
# endif
#endif
