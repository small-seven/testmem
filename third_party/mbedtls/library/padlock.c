#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PADLOCK_C)
#include "mbedtls/padlock.h"
#include <string.h>
#ifndef asm
#define asm __asm
#endif
#if defined(MBEDTLS_HAVE_X86)
#endif /* MBEDTLS_HAVE_X86 */
#endif /* MBEDTLS_PADLOCK_C */
