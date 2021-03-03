#include <config.h>
#include <hexdump.h>
#include <malloc.h>
#include <common.h>
#include <console.h>
#include <g_dnl.h>
#include <linux/err.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <usb_mass_storage.h>
#include <asm/unaligned.h>
#include <linux/bitops.h>
#include <linux/usb/gadget.h>
#include <linux/usb/gadget.h>
#include <linux/usb/composite.h>
#include <linux/bitmap.h>
#include <g_dnl.h>
#define FSG_DRIVER_DESC	"Mass Storage Function"
#define FSG_DRIVER_VERSION	"2012/06/5"
#define FSG_NO_INTR_EP 1
#define FSG_NO_DEVICE_STRINGS    1
#define FSG_NO_OTG               1
#define FSG_NO_INTR_EP           1
#include "storage_common.c"
#define GFP_ATOMIC ((gfp_t) 0)
#define PAGE_CACHE_SHIFT	12
#define PAGE_CACHE_SIZE		(1 << PAGE_CACHE_SHIFT)
#define kthread_create(...)	__builtin_return_address(0)
#define wait_for_completion(...) do {} while (0)
#define IGNORE_BULK_OUT		0
#define fsg_is_set(common) likely(__fsg_is_set(common, __func__, __LINE__))
typedef void (*fsg_routine_t)(struct fsg_dev *);

static int exception_in_progress(struct fsg_common *common)
{
	return common->state > FSG_STATE_IDLE;
}
#define START_TRANSFER_OR(common, ep_name, req, pbusy, state)		\
#define START_TRANSFER(common, ep_name, req, pbusy, state)		\
#if 0
#endif
#if 0
#endif
#if 0
#endif
#undef OR
