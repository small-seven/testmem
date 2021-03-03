#include <linux/kconfig.h>
#ifndef __ASSEMBLY__
#define	__ASSEMBLY__			/* Dirty trick to get only #defines */
#endif
#define	__ASM_STUB_PROCESSOR_H__	/* don't include asm/processor. */
#include <config.h>
#undef	__ASSEMBLY__
#include <env_internal.h>
#include <linux/stringify.h>
#if defined(__APPLE__)
#  define SYM_CHAR "_"
#else /* No leading character on symbols */
#  define SYM_CHAR
#endif
#if defined(ENV_IS_EMBEDDED) || defined(CONFIG_BUILD_ENVCRC)
#if defined(USE_HOSTCC) /* Native for 'tools/envcrc' */
#  define __UBOOT_ENV_SECTION__(name)	/*XXX DO_NOT_DEL_THIS_COMMENT*/
#else /* Environment is embedded in U-Boot's .text section */
#  define __UBOOT_ENV_SECTION__(name)	__attribute__ ((section(".text."#name)))
#endif
#if defined(__bfin__)
# define GEN_SET_VALUE(name, value)	\
#else
# define GEN_SET_VALUE(name, value)	\
#endif
#define GEN_SYMNAME(str)	SYM_CHAR #str
#define GEN_VALUE(str)		#str
#define GEN_ABS(name, value)			\
#if !defined(ENV_CRC)
#  define ENV_CRC	(~0)
#endif
#define DEFAULT_ENV_INSTANCE_EMBEDDED
#include <env_default.h>
#ifdef CONFIG_ENV_ADDR_REDUND
#endif	/* CONFIG_ENV_ADDR_REDUND */
#endif /* ENV_IS_EMBEDDED */
