#include <common.h>
#include <linux/errno.h>
#include <asm/global_data.h>
#include <linux/string.h>
#include <linux/list.h>
#include <linux/fb.h>
#include <asm/io.h>
#include <asm/mach-imx/video.h>
#include <malloc.h>
#include <video_fb.h>
#include "../videomodes.h"
#include "ipu.h"
#include "mxcfb.h"
#include "ipu_regs.h"
#include "display.h"
#include <panel.h>
#include <dm.h>
#include <video.h>
#if CONFIG_IS_ENABLED(DM_VIDEO)
#else
#endif
#if CONFIG_IS_ENABLED(VIDEO)
#endif
#define BYTES_PER_LONG 4
#define PADDING (BYTES_PER_LONG - (sizeof(struct fb_info) % BYTES_PER_LONG))
#if CONFIG_IS_ENABLED(DM_VIDEO)
#if defined(CONFIG_DISPLAY)
#endif
#if defined(CONFIG_DISPLAY)
#endif
#endif /* CONFIG_DM_VIDEO */
