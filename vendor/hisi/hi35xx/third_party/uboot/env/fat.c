#include <common.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <linux/stddef.h>
#include <malloc.h>
#include <memalign.h>
#include <search.h>
#include <errno.h>
#include <fat.h>
#include <mmc.h>
#ifdef CONFIG_SPL_BUILD
# if !defined(CONFIG_TARGET_AM335X_EVM) || defined(CONFIG_SPL_OS_BOOT)
#  define LOADENV
# endif
#else
# define LOADENV
# if defined(CONFIG_CMD_SAVEENV)
#  define CMD_SAVEENV
# endif
#endif
#ifdef CMD_SAVEENV
#endif /* CMD_SAVEENV */
#ifdef LOADENV
#ifdef CONFIG_MMC
#endif
#endif /* LOADENV */
#ifdef LOADENV
#endif
#ifdef CMD_SAVEENV
#endif
