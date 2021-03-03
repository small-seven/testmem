#ifndef HWCONFIG_TEST
#include <config.h>
#include <common.h>
#include <env.h>
#include <exports.h>
#include <hwconfig.h>
#include <linux/types.h>
#include <linux/string.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif /* HWCONFIG_TEST */
#ifdef HWCONFIG_TEST
#endif /* HWCONFIG_TEST */
