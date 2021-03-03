#include <common.h>
#include <dm.h>
#include <env_internal.h>
#include <errno.h>
#include <os.h>
#include <serial.h>
#include <stdio_dev.h>
#include <watchdog.h>
#include <dm/lists.h>
#include <dm/device-internal.h>
#include <dm/of_access.h>
#if !CONFIG_VAL(SYS_MALLOC_F_LEN)
#error "Serial is required before relocation - define CONFIG_$(SPL_)SYS_MALLOC_F_LEN to make this work"
#endif
#if CONFIG_IS_ENABLED(SERIAL_PRESENT)
#ifdef CONFIG_SERIAL_SEARCH_ALL
#endif
#ifdef CONFIG_CONS_INDEX
#define INDEX (CONFIG_CONS_INDEX - 1)
#else
#define INDEX 0
#endif
#ifdef CONFIG_SERIAL_SEARCH_ALL
#else
#endif
#undef INDEX
#ifdef CONFIG_REQUIRE_SERIAL_CONSOLE
#endif
#endif /* CONFIG_SERIAL_PRESENT */
#if CONFIG_IS_ENABLED(SERIAL_PRESENT)
#endif
#if CONFIG_IS_ENABLED(SERIAL_RX_BUFFER)
#else /* CONFIG_IS_ENABLED(SERIAL_RX_BUFFER) */
#endif /* CONFIG_IS_ENABLED(SERIAL_RX_BUFFER) */
#if defined(CONFIG_DM_STDIO)
#if CONFIG_IS_ENABLED(SERIAL_PRESENT)
#endif
#endif
#if CONFIG_IS_ENABLED(SERIAL_PRESENT)
#ifdef CONFIG_DM_STDIO
#endif
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#if CONFIG_POST & CONFIG_SYS_POST_UART
#endif
#endif
#ifdef CONFIG_DM_STDIO
#if CONFIG_IS_ENABLED(SERIAL_RX_BUFFER)
#endif
#endif
static int serial_pre_remove(struct udevice *dev)
{
#if CONFIG_IS_ENABLED(SYS_STDIO_DEREGISTER)
	struct serial_dev_priv *upriv = dev_get_uclass_priv(dev);

	if (stdio_deregister_dev(upriv->sdev, true))
		return -EPERM;
#endif

	return 0;
}
#endif
