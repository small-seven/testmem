#include <common.h>
#include <config.h>
#include <fuse.h>
#include <mapmem.h>
#include <image.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/hab.h>
#define ALIGN_SIZE		0x1000
#define MX6DQ_PU_IROM_MMU_EN_VAR	0x009024a8
#define MX6DLS_PU_IROM_MMU_EN_VAR	0x00901dd0
#define MX6SL_PU_IROM_MMU_EN_VAR	0x00901c60
#define IS_HAB_ENABLED_BIT \
#if !defined(CONFIG_SPL_BUILD)
#define MAX_RECORD_BYTES     (8*1024) /* 4 kbytes */
#if CONFIG_IS_ENABLED(LEGACY_IMAGE_FORMAT)
#endif
#if IMAGE_ENABLE_FIT
#endif
#endif /* !defined(CONFIG_SPL_BUILD) */
#ifdef DEBUG
#if  !defined(CONFIG_SPL_BUILD)
#endif
#endif
#if !defined(CONFIG_SPL_BUILD)
#endif
