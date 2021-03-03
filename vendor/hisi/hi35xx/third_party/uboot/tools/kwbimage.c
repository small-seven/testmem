#include "imagetool.h"
#include <limits.h>
#include <image.h>
#include <stdarg.h>
#include <stdint.h>
#include "kwbimage.h"
#ifdef CONFIG_KWB_SECURE
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#elif !defined(LIBRESSL_VERSION_NUMBER)
#endif
#endif
#ifdef CONFIG_KWB_SECURE
#endif
#define ADDR_INVALID ((uint32_t)-1)
#define BINARY_MAX_ARGS 8
#define IMAGE_CFG_ELEMENT_MAX 256
#if defined(CONFIG_KWB_SECURE)
#endif
#if defined(CONFIG_KWB_SECURE)
#endif
#if defined(CONFIG_KWB_SECURE)
#endif
#if defined(CONFIG_SYS_U_BOOT_OFFS)
#endif
#if defined(CONFIG_KWB_SECURE)
#endif
#if defined(CONFIG_KWB_SECURE)
#endif
#if defined(CONFIG_KWB_SECURE)
#endif
#if defined(CONFIG_KWB_SECURE)
#endif
