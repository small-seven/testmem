#include <common.h>
#include <asm/processor.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <asm/arch/rmobile.h>
#if defined(CONFIG_ARCH_RMOBILE_EXTRAM_BOOT)
#if defined(CONFIG_QOS_PRI_MEDIA)
#define is_qos_pri_media()	1
#else
#define is_qos_pri_media()	0
#endif
#if defined(CONFIG_QOS_PRI_NORMAL)
#define is_qos_pri_normal()	1
#else
#define is_qos_pri_normal()	0
#endif
#if defined(CONFIG_QOS_PRI_GFX)
#define is_qos_pri_gfx()	1
#else
#define is_qos_pri_gfx()	0
#endif
#else /* CONFIG_ARCH_RMOBILE_EXTRAM_BOOT */
#endif /* CONFIG_ARCH_RMOBILE_EXTRAM_BOOT */
