#include <common.h>
#include <command.h>
#include <env.h>
#include <env_internal.h>
#include <linux/stddef.h>
#include <malloc.h>
#include <search.h>
#include <errno.h>
#include <u-boot/crc.h>
#ifndef CONFIG_SPL_BUILD
# if defined(CONFIG_CMD_SAVEENV) && defined(CONFIG_CMD_FLASH)
#  define CMD_SAVEENV
# elif defined(CONFIG_ENV_ADDR_REDUND)
#  error CONFIG_ENV_ADDR_REDUND must have CONFIG_CMD_SAVEENV & CONFIG_CMD_FLASH
# endif
#endif
#if (!defined(CONFIG_MICROBLAZE) && !defined(CONFIG_ARCH_ZYNQ) && \
#define LOADENV
#endif
#if !defined(CONFIG_TARGET_X600) || !defined(CONFIG_SPL_BUILD)
#define INITENV
#endif
#if defined(CONFIG_ENV_ADDR_REDUND) && defined(CMD_SAVEENV) || \
#ifdef ENV_IS_EMBEDDED
#else /* ! ENV_IS_EMBEDDED */
#endif /* ENV_IS_EMBEDDED */
#endif
#ifdef CONFIG_ENV_ADDR_REDUND
#endif /* CONFIG_ENV_ADDR_REDUND */
#ifdef CONFIG_ENV_ADDR_REDUND
#ifdef INITENV
#endif
#ifdef CMD_SAVEENV
#if CONFIG_ENV_SECT_SIZE > CONFIG_ENV_SIZE
#endif
#if CONFIG_ENV_SECT_SIZE > CONFIG_ENV_SIZE
#endif
#if CONFIG_ENV_SECT_SIZE > CONFIG_ENV_SIZE
#endif
#endif /* CMD_SAVEENV */
#else /* ! CONFIG_ENV_ADDR_REDUND */
#ifdef INITENV
#endif
#ifdef CMD_SAVEENV
#if CONFIG_ENV_SECT_SIZE > CONFIG_ENV_SIZE
#endif	/* CONFIG_ENV_SECT_SIZE */
#if CONFIG_ENV_SECT_SIZE > CONFIG_ENV_SIZE
#endif
#endif /* CMD_SAVEENV */
#endif /* CONFIG_ENV_ADDR_REDUND */
#ifdef LOADENV
#ifdef CONFIG_ENV_ADDR_REDUND
#endif /* CONFIG_ENV_ADDR_REDUND */
#endif /* LOADENV */
#ifdef LOADENV
#endif
#ifdef CMD_SAVEENV
#endif
#ifdef INITENV
#endif
