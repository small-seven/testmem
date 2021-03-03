#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <mapmem.h>
#include <stdio_dev.h>
#include <video.h>
#include <video_console.h>
#include <dm/lists.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#ifdef CONFIG_SANDBOX
#include <asm/sdl.h>
#endif
#if defined(CONFIG_ARM) && !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#elif defined(CONFIG_VIDEO_SANDBOX_SDL)
#endif
static int video_pre_remove(struct udevice *dev)
{
	struct video_priv *priv = dev_get_uclass_priv(dev);

	free(priv->cmap);

	return 0;
}
