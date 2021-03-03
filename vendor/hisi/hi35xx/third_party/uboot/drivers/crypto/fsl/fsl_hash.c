#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <memalign.h>
#include "jobdesc.h"
#include "desc.h"
#include "jr.h"
#include "fsl_hash.h"
#include <hw_sha.h>
#include <linux/errno.h>
#define CRYPTO_MAX_ALG_NAME	80
#define SHA1_DIGEST_SIZE        20
#define SHA256_DIGEST_SIZE      32
#ifdef CONFIG_PHYS_64BIT
#else
#endif
