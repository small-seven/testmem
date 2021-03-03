#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <command.h>
#include <linux/mtd/omap_gpmc.h>
#include <jffs2/load_kernel.h>
#if defined(CONFIG_NOR)
#elif defined(CONFIG_MTD_RAW_NAND) || defined(CONFIG_CMD_NAND)
#elif defined(CONFIG_CMD_ONENAND)
#else
#endif
#if defined(CONFIG_OMAP34XX)
#endif
#if defined(CONFIG_NOR)
#endif
#if defined(CONFIG_MTD_RAW_NAND) || defined(CONFIG_CMD_NAND)
#endif
#if defined(CONFIG_CMD_ONENAND)
#endif
#if defined(CONFIG_NOR)
#endif
#if defined(CONFIG_MTD_RAW_NAND) || defined(CONFIG_CMD_NAND)
#endif
#if defined(CONFIG_CMD_ONENAND)
#endif
