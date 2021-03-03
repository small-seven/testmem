#include <common.h>
#include <cpu_func.h>
#include <errno.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/types.h>
#include <asm/macro.h>
#include <asm/armv8/sec_firmware.h>
#define SEC_FIRMWARE_LOADED	0x1
#define SEC_FIRMWARE_RUNNING	0x2
#define SEC_FIRMWARE_ADDR_MASK	(~0x3)
#ifndef SEC_FIRMWARE_FIT_IMAGE
#define SEC_FIRMWARE_FIT_IMAGE		"firmware"
#endif
#ifndef SEC_FIRMWARE_FIT_CNF_NAME
#define SEC_FIRMWARE_FIT_CNF_NAME	"config-1"
#endif
#ifndef SEC_FIRMWARE_TARGET_EL
#define SEC_FIRMWARE_TARGET_EL		2
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
#else
#error "The CONFIG_SYS_MEM_RESERVE_SECURE must be defined when enabled SEC Firmware support"
#endif
#ifdef CONFIG_SEC_FIRMWARE_ARMV8_PSCI
#endif
#ifdef CONFIG_TFABOOT
#endif
#define SIP_RNG_64 0xC200FF11
#if defined(CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT)
#endif
