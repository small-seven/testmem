#include <common.h>
#include <env.h>
#include <image.h>
#include <fdt_support.h>
#include <asm/addrspace.h>
#include <asm/io.h>
#define	LINUX_MAX_ENVS		256
#define	LINUX_MAX_ARGS		256
#if CONFIG_IS_ENABLED(MIPS_BOOT_FDT) && CONFIG_IS_ENABLED(OF_LIBFDT)
#else
#endif
#if CONFIG_IS_ENABLED(MIPS_BOOT_FDT) && CONFIG_IS_ENABLED(OF_LIBFDT)
#endif
	typedef void __noreturn (*kernel_entry_t)(int, ulong, ulong, ulong);
	kernel_entry_t kernel = (kernel_entry_t) images->ep;
	ulong linux_extra = 0;

	debug("## Transferring control to Linux (at address %p) ...\n", kernel);

	bootstage_mark(BOOTSTAGE_ID_RUN_OS);

	if (CONFIG_IS_ENABLED(MALTA))
		linux_extra = gd->ram_size;

#if CONFIG_IS_ENABLED(BOOTSTAGE_FDT)
	bootstage_fdt_add_report();
#endif
#if CONFIG_IS_ENABLED(BOOTSTAGE_REPORT)
	bootstage_report();
#endif

	if (images->ft_len)
		kernel(-2, (ulong)images->ft_addr, 0, 0);
	else
		kernel(linux_argc, (ulong)linux_argv, (ulong)linux_env,
			linux_extra);
}
