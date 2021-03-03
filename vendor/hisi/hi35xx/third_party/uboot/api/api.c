#include <config.h>
#include <command.h>
#include <common.h>
#include <env.h>
#include <malloc.h>
#include <env_internal.h>
#include <linux/types.h>
#include <api_public.h>
#include <u-boot/crc.h>
#include "api_private.h"
#define DEBUG
#undef DEBUG
#ifdef DEBUG
#define debugf(fmt, args...) do { printf("%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define debugf(fmt, args...)
#endif
typedef	int (*cfp_t)(va_list argp);

static int calls_no;

/*
 * pseudo signature:
 *
 * int API_getc(int *c)
 */
static int API_getc(va_list ap)
{
	int *c;

	if ((c = (int *)va_arg(ap, uintptr_t)) == NULL)
		return API_EINVAL;

	*c = getc();
	return 0;
}
