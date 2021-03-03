#include <common.h>
#include <command.h>
#include <env_internal.h>
#include <linux/stddef.h>
#include <malloc.h>
#include <search.h>
#include <errno.h>
#include <onenand_uboot.h>
#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/onenand.h>
#define ONENAND_MAX_ENV_SIZE	CONFIG_ENV_SIZE
#define ONENAND_ENV_SIZE(mtd)	(ONENAND_MAX_ENV_SIZE - ENV_HEADER_SIZE)
#ifdef CONFIG_ENV_ADDR_FLEX
#endif
#ifdef ENV_IS_EMBEDDED
#else
#endif /* ENV_IS_EMBEDDED */
#ifndef ENV_IS_EMBEDDED
# ifdef CONFIG_ENV_ADDR_FLEX
# endif
#endif /* !ENV_IS_EMBEDDED */
#ifdef CONFIG_ENV_ADDR_FLEX
#endif
#ifdef CONFIG_ENV_ADDR_FLEX
#endif
