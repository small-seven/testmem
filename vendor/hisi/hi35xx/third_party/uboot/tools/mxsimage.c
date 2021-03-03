#ifdef CONFIG_MXS
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <u-boot/crc.h>
#include <unistd.h>
#include <limits.h>
#include <openssl/evp.h>
#include "imagetool.h"
#include "mxsimage.h"
#include "pbl_crc32.h"
#include <image.h>
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
static void *OPENSSL_zalloc(size_t num)
{
	void *ret = OPENSSL_malloc(num);

	if (ret != NULL)
		memset(ret, 0, num);
	return ret;
}
void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
{
	EVP_MD_CTX_cleanup(ctx);
	OPENSSL_free(ctx);
}
#endif
#define SB_HAB_DCD_WRITE	0xccUL
#define SB_HAB_DCD_CHECK	0xcfUL
#define SB_HAB_DCD_NOOP		0xc0UL
#define SB_HAB_DCD_MASK_BIT	(1 << 3)
#define SB_HAB_DCD_SET_BIT	(1 << 4)
#define	SB_DCD_WRITE	\
#define	SB_DCD_ANDC	\
#define	SB_DCD_ORR	\
#define	SB_DCD_CHK_EQZ	\
#define	SB_DCD_CHK_EQ	\
#define	SB_DCD_CHK_NEQ	\
#define	SB_DCD_CHK_NEZ	\
#define	SB_DCD_NOOP	\
#endif
