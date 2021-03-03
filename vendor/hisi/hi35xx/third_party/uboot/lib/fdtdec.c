#ifndef USE_HOSTCC
#include <common.h>
#include <boot_fit.h>
#include <dm.h>
#include <dm/of_extra.h>
#include <env.h>
#include <errno.h>
#include <fdtdec.h>
#include <fdt_support.h>
#include <gzip.h>
#include <mapmem.h>
#include <linux/libfdt.h>
#include <serial.h>
#include <asm/sections.h>
#include <linux/ctype.h>
#include <linux/lzo.h>
#define COMPAT(id, name) name
#if CONFIG_IS_ENABLED(OF_TRANSLATE)
#endif
#if CONFIG_IS_ENABLED(PCI) && defined(CONFIG_DM_PCI)
#endif
#define MAX_STR_LEN 20
#ifdef CONFIG_SPL_BUILD
#else
# ifdef DEBUG
# endif
#endif
#if defined(CONFIG_NR_DRAM_BANKS)
#endif
#if CONFIG_IS_ENABLED(MULTI_DTB_FIT)
# if CONFIG_IS_ENABLED(MULTI_DTB_FIT_GZIP) ||\
#  if CONFIG_IS_ENABLED(MULTI_DTB_FIT_USER_DEFINED_AREA)
#  else
#  endif
# else
# endif
#endif
#if defined(CONFIG_OF_BOARD) || defined(CONFIG_OF_SEPARATE)
#ifdef CONFIG_SPL_BUILD
#else
#endif
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
# if CONFIG_IS_ENABLED(MULTI_DTB_FIT)
# endif
# ifdef CONFIG_OF_EMBED
#  ifdef CONFIG_SPL_BUILD
#  else
#  endif
# elif defined(CONFIG_OF_BOARD) || defined(CONFIG_OF_SEPARATE)
# elif defined(CONFIG_OF_HOSTFILE)
# elif defined(CONFIG_OF_PRIOR_STAGE)
# endif
# ifndef CONFIG_SPL_BUILD
# endif
# if CONFIG_IS_ENABLED(MULTI_DTB_FIT)
# endif
#endif
#if CONFIG_IS_ENABLED(MULTI_DTB_FIT)
#endif
#ifdef CONFIG_NR_DRAM_BANKS
#endif /* CONFIG_NR_DRAM_BANKS */
#endif /* !USE_HOSTCC */
