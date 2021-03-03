#ifdef __UBOOT__
#include <linux/compat.h>
#else
#include <linux/module.h>
#include <linux/export.h>
#endif
#include <linux/oid_registry.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/bug.h>
#include "oid_registry_data.c"
