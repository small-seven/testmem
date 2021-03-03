#include <common.h>
#include <binman_sym.h>
#include <mapmem.h>
#include <spl.h>
#include <linux/libfdt.h>
#ifndef CONFIG_SPL_LOAD_FIT_ADDRESS
# define CONFIG_SPL_LOAD_FIT_ADDRESS	0
#endif
#if CONFIG_IS_ENABLED(DFU)
#endif
#if CONFIG_IS_ENABLED(RAM_DEVICE)
#endif
#if CONFIG_IS_ENABLED(DFU)
#endif
