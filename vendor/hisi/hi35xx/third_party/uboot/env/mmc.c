#include <common.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <fdtdec.h>
#include <linux/stddef.h>
#include <malloc.h>
#include <memalign.h>
#include <mmc.h>
#include <part.h>
#include <search.h>
#include <errno.h>
#define __STR(X) #X
#define STR(X) __STR(X)
#if CONFIG_IS_ENABLED(OF_CONTROL)
#if defined(CONFIG_ENV_OFFSET_REDUND)
#endif
#else
#if defined(CONFIG_ENV_OFFSET_REDUND)
#endif
#endif
#ifdef CONFIG_SYS_MMC_ENV_PART
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#ifdef CONFIG_SYS_MMC_ENV_PART
#endif
#if defined(CONFIG_CMD_SAVEENV) && !defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#if defined(CONFIG_CMD_ERASEENV)
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#endif /* CONFIG_CMD_ERASEENV */
#endif /* CONFIG_CMD_SAVEENV && !CONFIG_SPL_BUILD */
#ifdef CONFIG_ENV_OFFSET_REDUND
#if !defined(ENV_IS_EMBEDDED)
#endif
#else /* ! CONFIG_ENV_OFFSET_REDUND */
#if !defined(ENV_IS_EMBEDDED)
#endif
#endif /* CONFIG_ENV_OFFSET_REDUND */
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_CMD_ERASEENV)
#endif
#endif
