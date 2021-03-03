#define _GNU_SOURCE
#include <compiler.h>
#include <env.h>
#include <errno.h>
#include <env_flags.h>
#include <fcntl.h>
#include <libgen.h>
#include <linux/fs.h>
#include <linux/stringify.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <u-boot/crc.h>
#include <unistd.h>
#include <dirent.h>
#ifdef MTD_OLD
# include <stdint.h>
# include <linux/mtd/mtd.h>
#else
# define  __user	/* nothing */
# include <mtd/mtd-user.h>
#endif
#include <mtd/ubi-user.h>
#include "fw_env_private.h"
#include "fw_env.h"
#ifdef CONFIG_FILE
#endif
#define DIV_ROUND_UP(n, d)	(((n) + (d) - 1) / (d))
#define min(x, y) ({				\
#define DEVNAME(i)    envdevices[(i)].devname
#define DEVOFFSET(i)  envdevices[(i)].devoff
#define ENVSIZE(i)    envdevices[(i)].env_size
#define DEVESIZE(i)   envdevices[(i)].erase_size
#define ENVSECTORS(i) envdevices[(i)].env_sectors
#define DEVTYPE(i)    envdevices[(i)].mtd_type
#define IS_UBI(i)     envdevices[(i)].is_ubi
#define CUR_ENVSIZE ENVSIZE(dev_current)
#define ENV_SIZE      usable_envsize
#define DEFAULT_ENV_INSTANCE_STATIC
#include <env_default.h>
#define UBI_DEV_START "/dev/ubi"
#define UBI_SYSFS "/sys/class/ubi"
#define UBI_VOL_NAME_PATT "ubi%d_%d"
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#if defined(CONFIG_FILE)
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#if defined(CONFIG_FILE)
#else
#ifdef DEVICE1_ESIZE
#endif
#ifdef DEVICE1_ENVSECTORS
#endif
#ifdef HAVE_REDUND
#ifdef DEVICE2_ESIZE
#endif
#ifdef DEVICE2_ENVSECTORS
#endif
#endif
#endif
#if defined(CONFIG_FILE)
#endif
