#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <i2c.h>
#include <tpm-v1.h>
#include <errno.h>
#include <linux/types.h>
#include <asm/unaligned.h>
#include "tpm_tis.h"
#include "tpm_internal.h"
#define TPM_ACCESS			0x0
#define TPM_STS				0x18
#define TPM_DATA_FIFO			0x24
#define LOCALITY0			0
#define TPM_DUMMY_BYTE			0xAA
#define TPM_ST33ZP24_I2C_SLAVE_ADDR	0x13
#define TPM_WRITE_DIRECTION             0x80
static int st33zp24_i2c_remove(struct udevice *dev)
{
	st33zp24_i2c_release_locality(dev);

	return 0;
}
