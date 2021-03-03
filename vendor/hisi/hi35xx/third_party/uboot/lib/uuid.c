#include <common.h>
#include <env.h>
#include <time.h>
#include <linux/ctype.h>
#include <errno.h>
#include <common.h>
#include <asm/io.h>
#include <part_efi.h>
#include <malloc.h>
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#if defined(CONFIG_RANDOM_UUID) || defined(CONFIG_CMD_UUID)
#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_CMD_UUID)
#endif /* CONFIG_CMD_UUID */
#endif /* CONFIG_RANDOM_UUID || CONFIG_CMD_UUID */
