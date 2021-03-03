#include <common.h>
#include <command.h>
#include <env_internal.h>
#include <fdtdec.h>
#include <linux/stddef.h>
#include <malloc.h>
#include <memalign.h>
#include <ufs.h>
#include <part.h>
#include <search.h>
#include <errno.h>
#if !defined(CONFIG_ENV_OFFSET)
#define CONFIG_ENV_OFFSET 0
#endif
#define UFS_BLK_LEN 4096
#if defined(CONFIG_CMD_SAVEENV) && !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_CMD_SAVEENV && !CONFIG_SPL_BUILD */
#if !defined(ENV_IS_EMBEDDED)
#endif
#ifndef CONFIG_SPL_BUILD
#endif
