#include <common.h>
#include <command.h>
#include <env.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <asm/global_data.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <mapmem.h>
#include <asm/io.h>
#define MAX_LEVEL	32		/* how deeply nested we will go */
#define SCRATCHPAD	1024		/* bytes of scratchpad memory */
#define CMD_FDT_MAX_DUMP 64
#ifdef CONFIG_OF_CONTROL
#endif
#ifdef CONFIG_OF_SYSTEM_SETUP
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_SOC_KEYSTONE
#endif
#endif
#if defined(CONFIG_FIT_SIGNATURE)
#endif
#ifdef CONFIG_OF_LIBFDT_OVERLAY
#endif
#ifdef CONFIG_SYS_LONGHELP
#ifdef CONFIG_OF_LIBFDT_OVERLAY
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#endif
#ifdef CONFIG_OF_SYSTEM_SETUP
#endif
#if defined(CONFIG_FIT_SIGNATURE)
#endif
#endif
