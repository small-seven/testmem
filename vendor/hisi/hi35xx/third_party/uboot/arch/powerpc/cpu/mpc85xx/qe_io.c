#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/immap_85xx.h>
#if defined(CONFIG_QE) && !defined(CONFIG_U_QE)
#define	NUM_OF_PINS	32
#endif /* CONFIG_QE */
