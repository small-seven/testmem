#include <env.h>
#include <errno.h>
#include <common.h>
#include <malloc.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/composite.h>
#include <dfu.h>
#include <g_dnl.h>
#include "f_dfu.h"
typedef int (*dfu_state_fn) (struct f_dfu *,
			     const struct usb_ctrlrequest *,
			     struct usb_gadget *,
			     struct usb_request *);

static inline struct f_dfu *func_to_dfu(struct usb_function *f)
{
	return container_of(f, struct f_dfu, usb_function);
}
