#include "meson_vpu.h"
#include <efi_loader.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <fdt_support.h>
#include <linux/sizes.h>
#include <asm/arch/mem.h>
#include "meson_registers.h"
#include "simplefb_common.h"
#define MESON_VPU_OVERSCAN SZ_64K
#if defined(CONFIG_VIDEO_DT_SIMPLEFB)
#endif
#if defined(CONFIG_EFI_LOADER)
#endif
#if defined(CONFIG_VIDEO_DT_SIMPLEFB)
#endif
