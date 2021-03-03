#include <common.h>
#include <command.h>
#include <asm/io.h>
#define pixis_base (u8 *)PIXIS_BASE
#ifndef CONFIG_SYS_PIXIS_VCFGEN0_ENABLE
#define CONFIG_SYS_PIXIS_VCFGEN0_ENABLE		0x1C
#endif
#ifndef CONFIG_SYS_PIXIS_VBOOT_ENABLE
#define CONFIG_SYS_PIXIS_VBOOT_ENABLE	0x04
#endif
#ifndef CONFIG_SYS_PIXIS_VBOOT_MASK
#define CONFIG_SYS_PIXIS_VBOOT_MASK	(0x40)
#endif
#ifdef CONFIG_PIXIS_SGMII_CMD
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC3
#endif
#ifdef CONFIG_TSEC4
#endif
#endif
#ifdef CONFIG_SYS_LONGHELP
#endif
#ifdef CONFIG_SYS_LONGHELP
#endif
