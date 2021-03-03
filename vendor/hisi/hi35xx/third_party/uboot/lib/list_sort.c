#ifndef __UBOOT__
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#else
#include <linux/compat.h>
#include <common.h>
#include <malloc.h>
#endif
#include <linux/list.h>
#include <linux/list_sort.h>
#define MAX_LIST_LENGTH_BITS 20
#ifdef CONFIG_TEST_LIST_SORT
#include <linux/random.h>
#define TEST_LIST_LEN (512+128+2) /* not including head */
#define TEST_POISON1 0xDEADBEEF
#define TEST_POISON2 0xA324354C
#endif /* CONFIG_TEST_LIST_SORT */
