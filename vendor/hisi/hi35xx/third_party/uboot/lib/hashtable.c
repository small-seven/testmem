#include <errno.h>
#include <malloc.h>
#include <sort.h>
#ifdef USE_HOSTCC		/* HOST build */
# include <string.h>
# include <assert.h>
# include <ctype.h>
# ifndef debug
#  ifdef DEBUG
#   define debug(fmt,args...)	printf(fmt ,##args)
#  else
#   define debug(fmt,args...)
#  endif
# endif
#else				/* U-Boot build */
# include <common.h>
# include <linux/string.h>
# include <linux/ctype.h>
#endif
#ifndef	CONFIG_ENV_MIN_ENTRIES	/* minimum number of entries */
#define	CONFIG_ENV_MIN_ENTRIES 64
#endif
#ifndef	CONFIG_ENV_MAX_ENTRIES	/* maximum number of entries */
#define	CONFIG_ENV_MAX_ENTRIES 512
#endif
#define USED_FREE 0
#define USED_DELETED -1
#include <env_callback.h>
#include <env_flags.h>
#include <search.h>
#include <slre.h>
#if !(defined(CONFIG_SPL_BUILD) && !defined(CONFIG_SPL_SAVEENV))
#ifdef CONFIG_REGEX
#endif
#ifdef CONFIG_REGEX
#endif
#ifdef DEBUG
#endif
#endif
