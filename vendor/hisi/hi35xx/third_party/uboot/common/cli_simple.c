#include <common.h>
#include <bootretry.h>
#include <cli.h>
#include <command.h>
#include <console.h>
#include <env.h>
#include <linux/ctype.h>
#define DEBUG_PARSER	0	/* set to 1 to debug */
#define debug_parser(fmt, args...)		\
#ifdef CONFIG_BOOT_RETRY_TIME
# ifdef CONFIG_RESET_TO_RETRY
# else
# endif
#endif
