#include <common.h>
#include <display.h>
#include <dm.h>
#include <edid.h>
#include <efi_loader.h>
#include <fdtdec.h>
#include <fdt_support.h>
#include <video.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/display2.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include "simplefb_common.h"
#ifdef CONFIG_MACH_SUN50I
#endif
#ifdef CONFIG_MACH_SUN8I_H3
#else
#endif
#ifdef CONFIG_EFI_LOADER
#endif
#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_VIDEO_DT_SIMPLEFB)
#endif /* CONFIG_OF_BOARD_SETUP && CONFIG_VIDEO_DT_SIMPLEFB */
