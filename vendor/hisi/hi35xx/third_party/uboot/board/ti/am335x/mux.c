#include <common.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/hardware.h>
#include <asm/arch/mux.h>
#include <asm/io.h>
#include <i2c.h>
#include "../common/board_detect.h"
#include "board.h"
#ifdef CONFIG_MTD_RAW_NAND
#ifdef CONFIG_SYS_NAND_BUSWIDTH_16BIT
#endif
#elif defined(CONFIG_NOR)
#endif
#if defined(CONFIG_NOR_BOOT)
#endif
#define PROFILE_NONE	0x0
#define PROFILE_0	(1 << 0)
#define PROFILE_1	(1 << 1)
#define PROFILE_2	(1 << 2)
#define PROFILE_3	(1 << 3)
#define PROFILE_4	(1 << 4)
#define PROFILE_5	(1 << 5)
#define PROFILE_6	(1 << 6)
#define PROFILE_7	(1 << 7)
#define PROFILE_MASK	0x7
#define PROFILE_ALL	0xFF
#define I2C_CPLD_ADDR	0x35
#define CFG_REG		0x10
#ifndef CONFIG_DM_I2C
#else
#endif
#if defined(CONFIG_MTD_RAW_NAND)
#elif defined(CONFIG_NOR)
#else
#endif
#ifdef CONFIG_MTD_RAW_NAND
#endif
#if defined(CONFIG_MTD_RAW_NAND) && defined(CONFIG_EMMC_BOOT)
#elif defined(CONFIG_NOR) && defined(CONFIG_EMMC_BOOT)
#else
#endif
