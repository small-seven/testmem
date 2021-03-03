#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <i2c.h>
#include <tpm-v1.h>
#include <linux/errno.h>
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/unaligned/be_byteshift.h>
#include "tpm_tis.h"
#include "tpm_internal.h"
#define TPM_TIS_I2C_DID_VID_9635 0x000b15d1L
#define TPM_TIS_I2C_DID_VID_9645 0x001a15d1L
#define	TPM_ACCESS(l)			(0x0000 | ((l) << 4))
#define	TPM_STS(l)			(0x0001 | ((l) << 4))
#define	TPM_DATA_FIFO(l)		(0x0005 | ((l) << 4))
#define	TPM_DID_VID(l)			(0x0006 | ((l) << 4))
#ifdef CONFIG_TPM_TIS_I2C_BURST_LIMITATION
#endif /* CONFIG_TPM_TIS_I2C_BURST_LIMITATION */
