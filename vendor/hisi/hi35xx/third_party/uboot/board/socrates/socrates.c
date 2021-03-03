#include <common.h>
#include <env.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/immap_85xx.h>
#include <ioports.h>
#include <flash.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <i2c.h>
#include <mb862xx.h>
#include <video_fb.h>
#include "upm_table.h"
#ifdef CONFIG_PCI
#endif
#if defined(CONFIG_PCI) || defined(CONFIG_DM_PCI)
#else
#endif
#if defined(CONFIG_DM_PCI)
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_R
#endif /* CONFIG_BOARD_EARLY_INIT_R */
#ifdef CONFIG_OF_BOARD_SETUP
#if defined(CONFIG_VIDEO_MB862xx)
#endif
#endif /* CONFIG_OF_BOARD_SETUP */
#if defined(CONFIG_OF_SEPARATE)
#endif
