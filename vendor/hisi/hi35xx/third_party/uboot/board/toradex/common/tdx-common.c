#include <common.h>
#include <env.h>
#include <g_dnl.h>
#include <linux/libfdt.h>
#include "tdx-cfg-block.h"
#include <asm/setup.h>
#include "tdx-common.h"
#define TORADEX_OUI 0x00142dUL
#ifdef CONFIG_TDX_CFG_BLOCK
#ifdef CONFIG_REVISION_TAG
#endif /* CONFIG_TDX_CFG_BLOCK */
#ifdef CONFIG_SERIAL_TAG
#endif /* CONFIG_SERIAL_TAG */
#ifdef CONFIG_TDX_CFG_BLOCK_2ND_ETHADDR
#endif
#ifdef CONFIG_USB_GADGET_DOWNLOAD
#endif
#if defined(CONFIG_OF_LIBFDT)
#endif
#else /* CONFIG_TDX_CFG_BLOCK */
#ifdef CONFIG_REVISION_TAG
#endif /* CONFIG_REVISION_TAG */
#ifdef CONFIG_SERIAL_TAG
#endif /* CONFIG_SERIAL_TAG */
#endif /* CONFIG_TDX_CFG_BLOCK */
