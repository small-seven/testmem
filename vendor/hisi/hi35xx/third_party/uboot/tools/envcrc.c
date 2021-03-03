#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <u-boot/crc.h>
#include <unistd.h>
#include <linux/kconfig.h>
#ifndef __ASSEMBLY__
#define	__ASSEMBLY__			/* Dirty trick to get only #defines	*/
#endif
#define	__ASM_STUB_PROCESSOR_H__	/* don't include asm/processor.		*/
#include <config.h>
#undef	__ASSEMBLY__
#if defined(CONFIG_ENV_IS_IN_FLASH)
# ifndef  CONFIG_ENV_ADDR
#  define CONFIG_ENV_ADDR	(CONFIG_SYS_FLASH_BASE + CONFIG_ENV_OFFSET)
# endif
# ifndef  CONFIG_ENV_OFFSET
#  define CONFIG_ENV_OFFSET (CONFIG_ENV_ADDR - CONFIG_SYS_FLASH_BASE)
# endif
# if !defined(CONFIG_ENV_ADDR_REDUND) && defined(CONFIG_ENV_OFFSET_REDUND)
#  define CONFIG_ENV_ADDR_REDUND	(CONFIG_SYS_FLASH_BASE + CONFIG_ENV_OFFSET_REDUND)
# endif
# ifndef  CONFIG_ENV_SIZE
#  define CONFIG_ENV_SIZE	CONFIG_ENV_SECT_SIZE
# endif
# if (CONFIG_ENV_ADDR >= CONFIG_SYS_MONITOR_BASE) && \
#  define ENV_IS_EMBEDDED
# endif
#endif	/* CONFIG_ENV_IS_IN_FLASH */
#if defined(ENV_IS_EMBEDDED) && !defined(CONFIG_BUILD_ENVCRC)
# define CONFIG_BUILD_ENVCRC
#endif
#ifdef CONFIG_SYS_REDUNDAND_ENVIRONMENT
# define ENV_HEADER_SIZE	(sizeof(uint32_t) + 1)
#else
# define ENV_HEADER_SIZE	(sizeof(uint32_t))
#endif
#define ENV_SIZE (CONFIG_ENV_SIZE - ENV_HEADER_SIZE)
#ifdef CONFIG_BUILD_ENVCRC
# include <env_internal.h>
#endif	/* CONFIG_BUILD_ENVCRC */
#ifdef CONFIG_BUILD_ENVCRC
#else
#endif
