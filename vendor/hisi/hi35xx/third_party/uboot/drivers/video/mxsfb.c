#include <common.h>
#include <dm.h>
#include <env.h>
#include <linux/errno.h>
#include <malloc.h>
#include <video.h>
#include <video_fb.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/dma.h>
#include <asm/io.h>
#include "videomodes.h"
#define	PS2KHZ(ps)	(1000000000UL / (ps))
#define HZ2PS(hz)	(1000000000UL / ((hz) / 1000))
#define BITS_PP		18
#define BYTES_PP	4
#ifndef CONFIG_VIDEO_MXS_MODE_SYSTEM
#endif
#ifdef CONFIG_VIDEO_MXS_MODE_SYSTEM
#endif
#ifndef CONFIG_DM_VIDEO
#else /* ifndef CONFIG_DM_VIDEO */
static int mxs_video_remove(struct udevice *dev)
{
	struct video_uc_platdata *plat = dev_get_uclass_platdata(dev);

	mxs_remove_common(plat->base);

	return 0;
}
#endif /* ifndef CONFIG_DM_VIDEO */
