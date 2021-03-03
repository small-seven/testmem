#include <common.h>
#include <env.h>
#include <malloc.h>
#include <mapmem.h>
#include <lcd.h>
#include <linux/string.h>
#include <linux/ctype.h>
#include <errno.h>
#include <linux/list.h>
#include <splash.h>
#include <asm/io.h>
#include "menu.h"
#include "cli.h"
#include "pxe_utils.h"
#define MAX_TFTP_PATH_LEN 512
#define PXELINUX_DIR "pxelinux.cfg/"
static void label_destroy(struct pxe_label *label)
{
	if (label->name)
		free(label->name);

	if (label->kernel)
		free(label->kernel);

	if (label->config)
		free(label->config);

	if (label->append)
		free(label->append);

	if (label->initrd)
		free(label->initrd);

	if (label->fdt)
		free(label->fdt);

	if (label->fdtdir)
		free(label->fdtdir);

	free(label);
}
#ifdef CONFIG_CMD_NET
#endif
#ifdef CONFIG_CMD_BOOTI
#elif defined(CONFIG_CMD_BOOTZ)
#endif
#define MAX_NEST_LEVEL 16
#ifdef CONFIG_CMD_BMP
#endif
