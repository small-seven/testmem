#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <spi.h>
#include <tpm-v1.h>
#include <errno.h>
#include <linux/types.h>
#include <asm/unaligned.h>
#include <linux/compat.h>
#include "tpm_tis.h"
#include "tpm_internal.h"
#define TPM_ACCESS			0x0
#define TPM_STS				0x18
#define TPM_DATA_FIFO			0x24
#define LOCALITY0			0
#define TPM_DATA_FIFO				0x24
#define TPM_INTF_CAPABILITY			0x14
#define TPM_DUMMY_BYTE				0x00
#define TPM_WRITE_DIRECTION			0x80
#define MAX_SPI_LATENCY				15
#define LOCALITY0				0
#define ST33ZP24_OK					0x5A
#define ST33ZP24_UNDEFINED_ERR				0x80
#define ST33ZP24_BADLOCALITY				0x81
#define ST33ZP24_TISREGISTER_UKNOWN			0x82
#define ST33ZP24_LOCALITY_NOT_ACTIVATED			0x83
#define ST33ZP24_HASH_END_BEFORE_HASH_START		0x84
#define ST33ZP24_BAD_COMMAND_ORDER			0x85
#define ST33ZP24_INCORECT_RECEIVED_LENGTH		0x86
#define ST33ZP24_TPM_FIFO_OVERFLOW			0x89
#define ST33ZP24_UNEXPECTED_READ_FIFO			0x8A
#define ST33ZP24_UNEXPECTED_WRITE_FIFO			0x8B
#define ST33ZP24_CMDRDY_SET_WHEN_PROCESSING_HASH_END	0x90
#define ST33ZP24_DUMMY_BYTES				0x00
#define ST33ZP24_SPI_BUFFER_SIZE (TPM_BUFSIZE + (TPM_BUFSIZE / 2) +\
static int st33zp24_spi_remove(struct udevice *dev)
{
	st33zp24_spi_release_locality(dev);

	return 0;
}
