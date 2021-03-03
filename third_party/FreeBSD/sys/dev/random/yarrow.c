#include <sys/cdefs.h>
#include <sys/param.h>
#ifdef _KERNEL
#include <sys/malloc.h>
#include <sys/mutex.h>
#include <sys/systm.h>
#include <crypto/rijndael/rijndael-api-fst.h>
#include <crypto/sha2/sha256.h>
#include <dev/random/hash.h>
#include <dev/random/randomdev.h>
#include <dev/random/random_harvestq.h>
#include <dev/random/uint128.h>
#include <dev/random/yarrow.h>
#else /* !_KERNEL */
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mutex.h>
#include "unit_test.h"
#include <crypto/rijndael/rijndael-api-fst.h>
#include <crypto/sha2/sha256.h>
#include <dev/random/hash.h>
#include <dev/random/randomdev.h>
#include <dev/random/uint128.h>
#include <dev/random/yarrow.h>
#endif /* _KERNEL */
#define RANDOM_ITERATE_NUMBER   16
#define	RANDOM_YARROW_TIMEBIN	16	/* max value for Pt/t */
#define	RANDOM_YARROW_FAST	0
#define	RANDOM_YARROW_SLOW	1
#define	RANDOM_YARROW_NPOOLS	2
#ifndef __LITEOS__
#endif
#ifdef _KERNEL
#endif /* _KERNEL */
#ifdef _KERNEL
#endif
#ifdef _KERNEL
#endif /* _KERNEL */
random_yarrow_deinit_alg(void *unused __unused)
{

	RANDOM_RESEED_DEINIT_LOCK();
	explicit_bzero(&yarrow_state, sizeof(yarrow_state));
#ifdef _KERNEL
	sysctl_ctx_free(&random_clist);
#endif
}
#ifndef __LITEOS__
#endif
#ifdef RANDOM_RWFILE_WRITE_IS_OK
#endif
#if defined(LOSCFG_HW_RANDOM_ENABLE)
#endif
#if defined(LOSCFG_HW_RANDOM_ENABLE) || defined(LOSCFG_DRIVERS_RANDOM)
#endif
#if defined(LOSCFG_HW_RANDOM_ENABLE)
#elif defined(LOSCFG_DRIVERS_RANDOM)
#endif
