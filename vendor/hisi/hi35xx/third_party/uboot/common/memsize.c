#include <common.h>
#ifdef __PPC__
# include <asm/io.h>	/* for sync() */
#else
# define sync()		/* nothing */
#endif
#ifndef CONFIG_VERY_BIG_RAM
#else
#endif
