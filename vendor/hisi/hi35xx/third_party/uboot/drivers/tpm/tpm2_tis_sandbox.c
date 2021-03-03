#include <common.h>
#include <dm.h>
#include <tpm-v2.h>
#include <asm/state.h>
#include <asm/unaligned.h>
#include <u-boot/crc.h>
#define TPM2_PROPERTIES_OFFSET 0x0000020E
#define SANDBOX_TPM_PCR_NB 1
