#ifndef __UBOOT__
#include <linux/uaccess.h>
#else
#include <div64.h>
#include <ubi_uboot.h>
#endif
#include <linux/err.h>
#include <linux/math64.h>
#include "ubi.h"
#ifndef __UBOOT__
#else
#endif
