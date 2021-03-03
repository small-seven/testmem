#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define FSBL_FLAGS_ESTATE_SHIFT		0
#define FSBL_FLAGS_ESTATE_MASK		(1 << FSBL_FLAGS_ESTATE_SHIFT)
#define FSBL_FLAGS_ESTATE_A64		0
#define FSBL_FLAGS_ESTATE_A32		1
#define FSBL_FLAGS_ENDIAN_SHIFT		1
#define FSBL_FLAGS_ENDIAN_MASK		(1 << FSBL_FLAGS_ENDIAN_SHIFT)
#define FSBL_FLAGS_ENDIAN_LE		0
#define FSBL_FLAGS_ENDIAN_BE		1
#define FSBL_FLAGS_TZ_SHIFT		2
#define FSBL_FLAGS_TZ_MASK		(1 << FSBL_FLAGS_TZ_SHIFT)
#define FSBL_FLAGS_NON_SECURE		0
#define FSBL_FLAGS_SECURE		1
#define FSBL_FLAGS_EL_SHIFT		3
#define FSBL_FLAGS_EL_MASK		(3 << FSBL_FLAGS_EL_SHIFT)
#define FSBL_FLAGS_EL0			0
#define FSBL_FLAGS_EL1			1
#define FSBL_FLAGS_EL2			2
#define FSBL_FLAGS_EL3			3
#define FSBL_FLAGS_CPU_SHIFT		5
#define FSBL_FLAGS_CPU_MASK		(3 << FSBL_FLAGS_CPU_SHIFT)
#define FSBL_FLAGS_A53_0		0
#define FSBL_FLAGS_A53_1		1
#define FSBL_FLAGS_A53_2		2
#define FSBL_FLAGS_A53_3		3
#define FSBL_MAX_PARTITIONS		8
#ifdef CONFIG_SPL_OS_BOOT
#endif
