#include <common.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <errno.h>
#include <malloc.h>
#include <memalign.h>
#include <search.h>
#include <ubi_uboot.h>
#undef crc32
#define _QUOTE(x) #x
#define QUOTE(x) _QUOTE(x)
#if (CONFIG_ENV_UBI_VID_OFFSET == 0)
#else
#endif
#ifdef CONFIG_CMD_SAVEENV
#ifdef CONFIG_SYS_REDUNDAND_ENVIRONMENT
#else /* ! CONFIG_SYS_REDUNDAND_ENVIRONMENT */
#endif /* CONFIG_SYS_REDUNDAND_ENVIRONMENT */
#endif /* CONFIG_CMD_SAVEENV */
#ifdef CONFIG_SYS_REDUNDAND_ENVIRONMENT
#else /* ! CONFIG_SYS_REDUNDAND_ENVIRONMENT */
#endif /* CONFIG_SYS_REDUNDAND_ENVIRONMENT */
