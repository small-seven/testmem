#include "utils/includes.h"
#include "utils/common.h"
#include "utils/module_tests.h"
#include "crypto/aes_siv.h"
#include "crypto/aes_wrap.h"
#include "crypto/aes.h"
#include "crypto/ms_funcs.h"
#include "crypto/crypto.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "crypto/sha384.h"
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef EAP_PSK
#endif /* EAP_PSK */
#ifdef EAP_PSK
#endif /* EAP_PSK */
#ifndef CONFIG_BORINGSSL
#endif /* CONFIG_BORINGSSL */
#ifndef CONFIG_BORINGSSL
#endif /* CONFIG_BORINGSSL */
#ifndef CONFIG_BORINGSSL
#endif /* CONFIG_BORINGSSL */
#ifndef CONFIG_BORINGSSL
#endif /* CONFIG_BORINGSSL */
#ifndef CONFIG_FIPS
#else /* CONFIG_FIPS */
#endif /* CONFIG_FIPS */
#ifdef EAP_FAST
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#else /* EAP_FAST */
#endif /* EAP_FAST */
#define NUM_PASSPHRASE_TESTS ARRAY_SIZE(passphrase_tests)
#if 0 /* This takes quite long to derive.. */
#endif
#if 0 /* \0 not currently supported in passphrase parameters.. */
#endif
#define NUM_RFC6070_TESTS ARRAY_SIZE(rfc6070_tests)
#ifdef CONFIG_HMAC_SHA256_KDF
#endif /* CONFIG_HMAC_SHA256_KDF */
#ifdef CONFIG_SHA384
#else /* CONFIG_SHA384 */
#endif /* CONFIG_SHA384 */
#ifndef CONFIG_FIPS
#else /* CONFIG_FIPS */
#endif /* CONFIG_FIPS */
