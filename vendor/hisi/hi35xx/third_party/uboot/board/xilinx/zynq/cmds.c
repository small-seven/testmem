#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <malloc.h>
#include <u-boot/md5.h>
#include <u-boot/rsa.h>
#include <u-boot/rsa-mod-exp.h>
#include <u-boot/sha256.h>
#include <zynqpl.h>
#include <fpga.h>
#include <zynq_bootimg.h>
#ifdef CONFIG_CMD_ZYNQ_RSA
#define ZYNQ_EFUSE_RSA_ENABLE_MASK	0x400
#define ZYNQ_ATTRIBUTE_PL_IMAGE_MASK		0x20
#define ZYNQ_ATTRIBUTE_CHECKSUM_TYPE_MASK	0x7000
#define ZYNQ_ATTRIBUTE_RSA_PRESENT_MASK		0x8000
#define ZYNQ_ATTRIBUTE_RSA_PART_OWNER_MASK	0x30000
#define ZYNQ_RSA_MODULAR_SIZE			256
#define ZYNQ_RSA_MODULAR_EXT_SIZE		256
#define ZYNQ_RSA_EXPO_SIZE			64
#define ZYNQ_RSA_SPK_SIGNATURE_SIZE		256
#define ZYNQ_RSA_PARTITION_SIGNATURE_SIZE	256
#define ZYNQ_RSA_SIGNATURE_SIZE			0x6C0
#define ZYNQ_RSA_HEADER_SIZE			4
#define ZYNQ_RSA_MAGIC_WORD_SIZE		60
#define ZYNQ_RSA_PART_OWNER_UBOOT		1
#define ZYNQ_RSA_ALIGN_PPK_START		64
#define WORD_LENGTH_SHIFT	2
#endif
#ifdef CONFIG_CMD_ZYNQ_AES
#endif
#ifdef CONFIG_CMD_ZYNQ_RSA
#endif
#ifdef CONFIG_CMD_ZYNQ_AES
#endif
#ifdef CONFIG_SYS_LONGHELP
#ifdef CONFIG_CMD_ZYNQ_RSA
#endif
#ifdef CONFIG_CMD_ZYNQ_AES
#endif
#endif
