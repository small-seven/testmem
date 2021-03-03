#include <sys/cdefs.h>
#ifdef _KERNEL
#include <sys/param.h>
#include <sys/systm.h>
#else /* !_KERNEL */
#include <sys/param.h>
#include <sys/types.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"
#endif /* _KERNEL */
#include <crypto/rijndael/rijndael-api-fst.h>
#include <crypto/sha2/sha256.h>
#include <dev/random/hash.h>
