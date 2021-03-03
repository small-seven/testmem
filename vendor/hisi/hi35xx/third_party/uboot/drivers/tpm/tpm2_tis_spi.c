#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <log.h>
#include <spi.h>
#include <tpm-v2.h>
#include <linux/errno.h>
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/unaligned/be_byteshift.h>
#include <asm-generic/gpio.h>
#include "tpm_tis.h"
#include "tpm_internal.h"
#define TPM_ACCESS(l)			(0x0000 | ((l) << 12))
#define TPM_INT_ENABLE(l)               (0x0008 | ((l) << 12))
#define TPM_STS(l)			(0x0018 | ((l) << 12))
#define TPM_DATA_FIFO(l)		(0x0024 | ((l) << 12))
#define TPM_DID_VID(l)			(0x0F00 | ((l) << 12))
#define TPM_RID(l)			(0x0F04 | ((l) << 12))
#define MAX_SPI_FRAMESIZE 64
#define TPM_WAIT_STATES 100
static int tpm_tis_spi_remove(struct udevice *dev)
{
	struct tpm_chip *chip = dev_get_priv(dev);

	tpm_tis_spi_release_locality(dev, chip->locality, true);

	return 0;
}
