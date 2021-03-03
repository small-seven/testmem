#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/param.h>
#ifdef _KERNEL
#include <sys/systm.h>
#else
#include <string.h>
#endif
#include <crypto/rijndael/rijndael_local.h>
#include <crypto/rijndael/rijndael-api-fst.h>
#ifndef TRUE
#define TRUE 1
#endif
typedef u_int8_t	BYTE;

int rijndael_makeKey(keyInstance *key, BYTE direction, int keyLen,
	const char *keyMaterial) {
	u_int8_t cipherKey[RIJNDAEL_MAXKB];

	if (key == NULL) {
		return BAD_KEY_INSTANCE;
	}
#if 1 /*STRICT_ALIGN*/
#else
#endif
#if 1 /*STRICT_ALIGN*/
#else
#endif
#if 1 /*STRICT_ALIGN*/
#else  /* !STRICT_ALIGN */
#endif /* ?STRICT_ALIGN */
#if 1 /*STRICT_ALIGN */
#else
#endif
#if 1 /*STRICT_ALIGN*/
#else
#endif
#if 1 /*STRICT_ALIGN */
#else
#endif
