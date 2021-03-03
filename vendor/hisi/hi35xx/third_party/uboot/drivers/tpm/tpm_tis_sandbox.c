#include <common.h>
#include <dm.h>
#include <tpm-v1.h>
#include <asm/state.h>
#include <asm/unaligned.h>
#include <u-boot/crc.h>
#define FIRMWARE_NV_INDEX		0x1007
#define KERNEL_NV_INDEX			0x1008
#define BACKUP_NV_INDEX                 0x1009
#define FWMP_NV_INDEX                   0x100a
#define REC_HASH_NV_INDEX               0x100b
#define REC_HASH_NV_SIZE                VB2_SHA256_DIGEST_SIZE
#define NV_DATA_PUBLIC_PERMISSIONS_OFFSET	60
#define ROLLBACK_SPACE_KERNEL_VERSION	2
#define ROLLBACK_SPACE_KERNEL_UID	0x4752574C  /* 'GRWL' */
#define TPM_REQUEST_HEADER_LENGTH	10
#define TPM_RESPONSE_HEADER_LENGTH	10
#define NV_DATA_SIZE		0x20
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
