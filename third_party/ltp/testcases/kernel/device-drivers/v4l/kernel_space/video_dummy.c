#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/videodev2.h>
#include <media/v4l2-ioctl.h>
#include <media/v4l2-dev.h>
#ifdef CONFIG_COMPAT
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 19)
#else
#endif
#endif
