#include <common.h>
#include <asm/arch/sm.h>
#include <linux/kernel.h>
#include <dm.h>
#include <linux/bitfield.h>
#include <regmap.h>
#include <syscon.h>
#define FN_GET_SHARE_MEM_INPUT_BASE	0x82000020
#define FN_GET_SHARE_MEM_OUTPUT_BASE	0x82000021
#define FN_EFUSE_READ			0x82000030
#define FN_EFUSE_WRITE			0x82000031
#define FN_CHIP_ID			0x82000044
#define SM_CHIP_ID_LENGTH	119
#define SM_CHIP_ID_OFFSET	4
#define SM_CHIP_ID_SIZE		12
#define AO_SEC_SD_CFG15		0xfc
#define REBOOT_REASON_MASK	GENMASK(15, 12)
#define MAX_REBOOT_REASONS 14
