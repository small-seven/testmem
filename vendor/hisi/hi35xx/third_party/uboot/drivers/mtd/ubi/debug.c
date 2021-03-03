#include <hexdump.h>
#include <ubi_uboot.h>
#include "ubi.h"
#ifndef __UBOOT__
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#endif
#ifndef __UBOOT__
#else
#endif
