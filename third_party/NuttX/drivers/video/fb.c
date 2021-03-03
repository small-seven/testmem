#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "fb.h"
#include "fs/fs.h"
#include "assert.h"
#include "errno.h"
#include "user_copy.h"
#define gerr PRINT_ERR
#define FB_DEV_MAXNUM   32
#ifndef CONFIG_DISABLE_POLL
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
static ssize_t fb_mmap(FAR struct file *filep, FAR LosVmMapRegion *region)
{
  int ret = -EINVAL;
  struct fb_chardev_s *fb;
  struct fb_vtable_s *vtable;

  fb = (struct fb_chardev_s *)filep->f_inode->i_private;
  if (fb == NULL)
    {
      return -ENODEV;
    }

  vtable = fb->vtable;
  if (vtable == NULL)
    {
      return -EINVAL;
    }

  if (vtable->fb_mmap != NULL)
    {
      ret = vtable->fb_mmap(vtable, region);
    }

  return ret;
}
#ifdef CONFIG_FB_CMAP
#endif
#ifdef CONFIG_FB_HWCURSOR
#endif
#ifdef CONFIG_LCD_UPDATE
#endif
#ifdef CONFIG_FB_SYNC
#endif
#ifdef CONFIG_FB_OVERLAY
#ifdef CONFIG_FB_OVERLAY_BLIT
#endif
#endif /* CONFIG_FB_OVERLAY */
#ifdef CONFIG_FB_OVERLAY
#endif
#ifdef CONFIG_FB_OVERLAY
#endif
