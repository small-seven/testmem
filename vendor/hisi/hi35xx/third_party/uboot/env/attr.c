#ifdef USE_HOSTCC /* Eliminate "ANSI does not permit..." warnings */
#include <stdint.h>
#include <stdio.h>
#include <linux/linux_string.h>
#else
#include <common.h>
#include <slre.h>
#endif
#include <env_attr.h>
#include <errno.h>
#include <linux/string.h>
#include <malloc.h>
#if defined(CONFIG_REGEX)
#else
#endif
