#include <common.h>
#include <env.h>
#include <errno.h>
#include <spl.h>
#include <net.h>
#include <linux/libfdt.h>
#if defined(CONFIG_SPL_ETH_SUPPORT) || defined(CONFIG_SPL_USB_ETHER)
#endif
#ifdef CONFIG_SPL_ETH_SUPPORT
#ifdef CONFIG_SPL_ETH_DEVICE
#endif
#endif
#ifdef CONFIG_SPL_USB_ETHER
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif
#endif
