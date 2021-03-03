#include <common.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <linux/stddef.h>
#include <malloc.h>
#include <memalign.h>
#include <nand.h>
#include <search.h>
#include <errno.h>
#include <u-boot/crc.h>
#if defined(CONFIG_CMD_SAVEENV) && defined(CONFIG_CMD_NAND) && \
#define CMD_SAVEENV
#elif defined(CONFIG_ENV_OFFSET_REDUND) && !defined(CONFIG_SPL_BUILD)
#error CONFIG_ENV_OFFSET_REDUND must have CONFIG_CMD_SAVEENV & CONFIG_CMD_NAND
#endif
#ifndef CONFIG_ENV_RANGE
#define CONFIG_ENV_RANGE	CONFIG_ENV_SIZE
#endif
#if defined(ENV_IS_EMBEDDED)
#elif defined(CONFIG_NAND_ENV_DST)
#endif /* ENV_IS_EMBEDDED */
#if defined(ENV_IS_EMBEDDED) || defined(CONFIG_NAND_ENV_DST)
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#else /* ENV_IS_EMBEDDED || CONFIG_NAND_ENV_DST */
#endif /* ENV_IS_EMBEDDED || CONFIG_NAND_ENV_DST */
#ifdef CMD_SAVEENV
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#endif /* CMD_SAVEENV */
#if defined(CONFIG_SPL_BUILD)
#else
#endif /* #if defined(CONFIG_SPL_BUILD) */
#ifdef CONFIG_ENV_OFFSET_OOB
#endif
#ifdef CONFIG_ENV_OFFSET_REDUND
#if defined(ENV_IS_EMBEDDED)
#else
#endif /* ! ENV_IS_EMBEDDED */
#else /* ! CONFIG_ENV_OFFSET_REDUND */
#if !defined(ENV_IS_EMBEDDED)
#if defined(CONFIG_ENV_OFFSET_OOB)
#endif
#endif /* ! ENV_IS_EMBEDDED */
#endif /* CONFIG_ENV_OFFSET_REDUND */
#if defined(CMD_SAVEENV)
#endif
