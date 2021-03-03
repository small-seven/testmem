#include <common.h>
#include <cli.h>
#include <command.h>
#include <console.h>
#include <env.h>
#include <env_internal.h>
#include <search.h>
#include <errno.h>
#include <malloc.h>
#include <mapmem.h>
#include <u-boot/crc.h>
#include <watchdog.h>
#include <linux/stddef.h>
#include <asm/byteorder.h>
#include <asm/io.h>
#if	defined(CONFIG_ENV_IS_IN_EEPROM)	|| \
#define ENV_IS_IN_DEVICE
#endif
#if	!defined(ENV_IS_IN_DEVICE)		&& \
# error Define one of CONFIG_ENV_IS_IN_{EEPROM|FLASH|MMC|FAT|EXT4|\
#endif
#define	MAX_ENV_SIZE	(1 << 20)	/* 1 MiB */
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_CMD_NVEDIT_EFI)
#endif
#ifdef CONFIG_CMD_GREPENV
#ifdef CONFIG_REGEX
#endif
#endif
#endif /* CONFIG_SPL_BUILD */
#if CONFIG_IS_ENABLED(CMD_NVEDIT_EFI)
#endif
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_CMD_ASKENV)
#endif
#if defined(CONFIG_CMD_ENV_CALLBACK)
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#else
#endif
#endif
#if defined(CONFIG_CMD_ENV_FLAGS)
#endif
#if defined(CONFIG_CMD_EDITENV)
#endif /* CONFIG_CMD_EDITENV */
#endif /* CONFIG_SPL_BUILD */
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_CMD_SAVEENV) && defined(ENV_IS_IN_DEVICE)
#if defined(CONFIG_CMD_ERASEENV)
#endif
#endif
#endif /* CONFIG_SPL_BUILD */
#ifndef CONFIG_SPL_BUILD
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#ifdef CONFIG_CMD_EXPORTENV
#ifdef CONFIG_ENV_ADDR_REDUND
#endif
#endif
#ifdef CONFIG_CMD_IMPORTENV
#endif
#if defined(CONFIG_CMD_NVEDIT_INFO)
#define ENV_INFO_IS_DEFAULT	BIT(0) /* default environment bit mask */
#define ENV_INFO_IS_PERSISTED	BIT(1) /* environment persistence bit mask */
#if defined(CONFIG_CMD_SAVEENV) && !defined(CONFIG_ENV_IS_NOWHERE)
#else
#endif
#endif
#if defined(CONFIG_CMD_ENV_EXISTS)
#endif
#if defined(CONFIG_CMD_ASKENV)
#endif
#ifndef CONFIG_MINI_BOOT
#endif /* CONFIG_MINI_BOOT */
#if defined(CONFIG_CMD_EDITENV)
#endif
#if defined(CONFIG_CMD_ENV_CALLBACK)
#endif
#if defined(CONFIG_CMD_ENV_FLAGS)
#endif
#if defined(CONFIG_CMD_EXPORTENV)
#endif
#if defined(CONFIG_CMD_GREPENV)
#endif
#if defined(CONFIG_CMD_IMPORTENV)
#endif
#if defined(CONFIG_CMD_NVEDIT_INFO)
#endif
#if defined(CONFIG_CMD_RUN)
#endif
#if defined(CONFIG_CMD_SAVEENV) && defined(ENV_IS_IN_DEVICE)
#if defined(CONFIG_CMD_ERASEENV)
#endif
#endif
#if defined(CONFIG_CMD_ENV_EXISTS)
#endif
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
#ifdef CONFIG_SYS_LONGHELP
#if defined(CONFIG_CMD_ASKENV)
#endif
#if defined(CONFIG_CMD_ENV_CALLBACK)
#endif
#if defined(CONFIG_CMD_EDITENV)
#endif
#if defined(CONFIG_CMD_ENV_EXISTS)
#endif
#if defined(CONFIG_CMD_EXPORTENV)
#endif
#if defined(CONFIG_CMD_ENV_FLAGS)
#endif
#if defined(CONFIG_CMD_GREPENV)
#ifdef CONFIG_REGEX
#else
#endif
#endif
#if defined(CONFIG_CMD_IMPORTENV)
#endif
#if defined(CONFIG_CMD_NVEDIT_INFO)
#endif
#if defined(CONFIG_CMD_NVEDIT_EFI)
#endif
#if defined(CONFIG_CMD_RUN)
#endif
#if defined(CONFIG_CMD_SAVEENV) && defined(ENV_IS_IN_DEVICE)
#if defined(CONFIG_CMD_ERASEENV)
#endif
#endif
#if defined(CONFIG_CMD_NVEDIT_EFI)
#endif
#endif
#if defined(CONFIG_CMD_EDITENV)
#endif
#if defined(CONFIG_CMD_NVEDIT_EFI)
#endif
#ifdef CONFIG_CMD_GREPENV
#ifdef CONFIG_REGEX
#else
#endif
#ifdef CONFIG_REGEX
#endif
#endif
#if defined(CONFIG_CMD_NVEDIT_EFI)
#endif
#if defined(CONFIG_CMD_ASKENV)
#endif
#if defined(CONFIG_CMD_RUN)
#endif
#endif /* CONFIG_SPL_BUILD */
