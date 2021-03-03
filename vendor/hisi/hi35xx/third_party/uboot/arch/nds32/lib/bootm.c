#include <common.h>
#include <command.h>
#include <env.h>
#include <image.h>
#include <u-boot/zlib.h>
#include <asm/byteorder.h>
#include <asm/bootm.h>
#if defined(CONFIG_SETUP_MEMORY_TAGS) || \
# ifdef CONFIG_SETUP_MEMORY_TAGS
# endif
# ifdef CONFIG_INITRD_TAG
# endif
#endif /* CONFIG_SETUP_MEMORY_TAGS || CONFIG_CMDLINE_TAG || CONFIG_INITRD_TAG */
#ifdef CONFIG_CMDLINE_TAG
#endif
#ifdef CONFIG_OF_LIBFDT
#endif
#if defined(CONFIG_SETUP_MEMORY_TAGS) || \
#ifdef CONFIG_SERIAL_TAG
#endif
#ifdef CONFIG_REVISION_TAG
#endif
#ifdef CONFIG_SETUP_MEMORY_TAGS
#endif
#ifdef CONFIG_CMDLINE_TAG
#endif
#ifdef CONFIG_INITRD_TAG
#endif
#endif
#ifdef CONFIG_USB_DEVICE
#endif
#if defined(CONFIG_SETUP_MEMORY_TAGS) || \
#ifdef CONFIG_SETUP_MEMORY_TAGS
#endif /* CONFIG_SETUP_MEMORY_TAGS */
#ifdef CONFIG_INITRD_TAG
#endif /* CONFIG_INITRD_TAG */
#ifdef CONFIG_SERIAL_TAG
#endif
#ifdef CONFIG_REVISION_TAG
#endif  /* CONFIG_REVISION_TAG */
#endif /* CONFIG_SETUP_MEMORY_TAGS || CONFIG_CMDLINE_TAG || CONFIG_INITRD_TAG */
