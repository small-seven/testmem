#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include "str_drm.h"
#include <linux/config.h>
#include "tdrm.h"
#include "drmP.h"
#define DRIVER_AUTHOR		"Kai Zhao"
#define DRIVER_DESC		"drm test mode"
#define DRIVER_DATE		"20030903"
#define DRIVER_CARD_LIST DRM(idlist)
#define DRIVER_FOPS						\
#include "drm_auth.h"
#include "drm_bufs.h"
#include "drm_context.h"
#include "drm_dma.h"
#include "drm_drawable.h"
#include "drm_drv.h"
#ifndef MODULE
#endif
#include "drm_fops.h"
#include "drm_init.h"
#include "drm_ioctl.h"
#include "drm_lock.h"
#include "drm_memory.h"
#include "drm_proc.h"
#include "drm_vm.h"
#include "drm_stub.h"
#include "drm_agpsupport.h"
