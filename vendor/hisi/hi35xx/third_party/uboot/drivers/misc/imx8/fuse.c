#include <common.h>
#include <console.h>
#include <errno.h>
#include <fuse.h>
#include <asm/arch/sci/sci.h>
#include <asm/arch/sys_proto.h>
#define FSL_ECC_WORD_START_1	 0x10
#define FSL_ECC_WORD_END_1	 0x10F
#define FSL_ECC_WORD_START_2	 0x220
#define FSL_ECC_WORD_END_2	 0x31F
#define FSL_QXP_FUSE_GAP_START	 0x110
#define FSL_QXP_FUSE_GAP_END	 0x21F
#define FSL_SIP_OTP_READ             0xc200000A
#define FSL_SIP_OTP_WRITE            0xc200000B
