#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <u-boot/md5.h>
#include <zynq_bootimg.h>
#define ZYNQ_IMAGE_PHDR_OFFSET		0x09C
#define ZYNQ_IMAGE_FSBL_LEN_OFFSET	0x040
#define ZYNQ_PART_HDR_CHKSUM_WORD_COUNT	0x0F
#define ZYNQ_PART_HDR_WORD_COUNT	0x10
#define ZYNQ_MAXIMUM_IMAGE_WORD_LEN	0x40000000
#define MD5_CHECKSUM_SIZE	16
