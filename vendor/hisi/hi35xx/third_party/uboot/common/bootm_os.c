#include <common.h>
#include <bootm.h>
#include <cpu_func.h>
#include <env.h>
#include <fdt_support.h>
#include <linux/libfdt.h>
#include <malloc.h>
#include <vxworks.h>
#include <tee/optee.h>
#if defined(CONFIG_BOOTM_NETBSD) || defined(CONFIG_BOOTM_PLAN9)
#endif
#ifdef CONFIG_BOOTM_NETBSD
#if defined(CONFIG_FIT)
#endif
#endif /* CONFIG_BOOTM_NETBSD*/
#ifdef CONFIG_LYNXKDI
#if defined(CONFIG_FIT)
#endif
#endif /* CONFIG_LYNXKDI */
#ifdef CONFIG_BOOTM_RTEMS
#if defined(CONFIG_FIT)
#endif
#endif /* CONFIG_BOOTM_RTEMS */
#if defined(CONFIG_BOOTM_OSE)
#if defined(CONFIG_FIT)
#endif
#endif /* CONFIG_BOOTM_OSE */
#if defined(CONFIG_BOOTM_PLAN9)
#if defined(CONFIG_FIT)
#endif
#endif /* CONFIG_BOOTM_PLAN9 */
#if defined(CONFIG_BOOTM_VXWORKS) && \
#if defined(CONFIG_OF_LIBFDT)
#endif
#if defined(CONFIG_OF_LIBFDT)
#else
#endif
#if defined(CONFIG_FIT)
#endif
#endif
#if defined(CONFIG_CMD_ELF)
#if defined(CONFIG_FIT)
#endif
#endif
#ifdef CONFIG_INTEGRITY
#if defined(CONFIG_FIT)
#endif
#endif
#ifdef CONFIG_BOOTM_OPENRTOS
#endif
#ifdef CONFIG_BOOTM_OPTEE
#endif
#ifdef CONFIG_BOOTM_LINUX
#endif
#ifdef CONFIG_BOOTM_NETBSD
#endif
#ifdef CONFIG_LYNXKDI
#endif
#ifdef CONFIG_BOOTM_RTEMS
#endif
#if defined(CONFIG_BOOTM_OSE)
#endif
#if defined(CONFIG_BOOTM_PLAN9)
#endif
#if defined(CONFIG_BOOTM_VXWORKS) && \
#endif
#if defined(CONFIG_CMD_ELF)
#endif
#ifdef CONFIG_INTEGRITY
#endif
#ifdef CONFIG_BOOTM_OPENRTOS
#endif
#ifdef CONFIG_BOOTM_OPTEE
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
