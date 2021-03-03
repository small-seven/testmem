#include <common.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <linux/stddef.h>
#include <errno.h>
#include <memalign.h>
#include <sata.h>
#include <search.h>
#if defined(CONFIG_ENV_OFFSET_REDUND)
#error ENV REDUND not supported
#endif
#if !defined(CONFIG_ENV_OFFSET) || !defined(CONFIG_ENV_SIZE)
#error CONFIG_ENV_OFFSET or CONFIG_ENV_SIZE not defined
#endif
#ifdef CONFIG_CMD_SAVEENV
#endif /* CONFIG_CMD_SAVEENV */
