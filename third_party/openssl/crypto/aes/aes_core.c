#include <assert.h>
#include <stdlib.h>
#include <openssl/crypto.h>
#include <openssl/aes.h>
#include "aes_local.h"
#ifndef AES_ASM
#ifndef FULL_UNROLL
#endif /* ?FULL_UNROLL */
#ifdef FULL_UNROLL
#else  /* !FULL_UNROLL */
#endif /* ?FULL_UNROLL */
#ifndef FULL_UNROLL
#endif /* ?FULL_UNROLL */
#ifdef FULL_UNROLL
#else  /* !FULL_UNROLL */
#endif /* ?FULL_UNROLL */
#else /* AES_ASM */
#if defined(ROTATE)
#else
#endif
#endif /* AES_ASM */
