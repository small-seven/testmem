#include <stdio.h>
#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#include "internal/conf.h"
#include <openssl/x509.h>
#include <openssl/asn1.h>
#include <openssl/engine.h>
#ifdef _WIN32
# define strdup _strdup
#endif
#if OPENSSL_API_COMPAT < 0x10100000L
#endif
#ifdef OPENSSL_INIT_DEBUG
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_SYS_UEFI
#endif
