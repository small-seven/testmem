#include <common.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/hardware.h>
#include <asm/arch/mux.h>
#include <asm/io.h>
#include <i2c.h>
#ifdef CONFIG_MMC
#endif
#ifdef CONFIG_MTD_RAW_NAND
#endif
#ifndef CONFIG_MTD_RAW_NAND
#endif
#ifdef CONFIG_MTD_RAW_NAND
#elif defined(CONFIG_MMC)
#endif
