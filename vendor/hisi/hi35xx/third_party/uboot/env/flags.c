#include <env.h>
#include <linux/string.h>
#include <linux/ctype.h>
#ifdef USE_HOSTCC /* Eliminate "ANSI does not permit..." warnings */
#include <stdint.h>
#include <stdio.h>
#include "fw_env_private.h"
#include "fw_env.h"
#include <env_attr.h>
#include <env_flags.h>
#define env_get fw_getenv
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#else
#include <common.h>
#include <env_internal.h>
#endif
#ifdef CONFIG_CMD_NET
#define ENV_FLAGS_NET_VARTYPE_REPS "im"
#else
#define ENV_FLAGS_NET_VARTYPE_REPS ""
#endif
#ifdef CONFIG_CMD_ENV_FLAGS
#ifdef CONFIG_CMD_NET
#endif
#endif /* CONFIG_CMD_ENV_FLAGS */
#ifdef CONFIG_CMD_NET
#endif
#ifdef CONFIG_CMD_NET
#endif
#ifdef CONFIG_CMD_NET
#endif
#ifdef USE_HOSTCC /* Functions only used from tools/env */
#else /* !USE_HOSTCC - Functions only used from lib/hashtable.c */
#ifndef CONFIG_ENV_ACCESS_IGNORE_FORCE
#endif
#endif
