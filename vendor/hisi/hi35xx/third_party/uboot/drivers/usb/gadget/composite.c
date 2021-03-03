#undef DEBUG
#include <linux/bitops.h>
#include <linux/usb/composite.h>
#define USB_BUFSIZ	4096
typedef struct { __le16 val; } __packed __le16_packed;

static struct usb_composite_driver *composite;

static inline void le16_add_cpu_packed(__le16_packed *var, u16 val)
{
	var->val = cpu_to_le16(le16_to_cpu(var->val) + val);
}
