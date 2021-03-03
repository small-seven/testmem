#include <common.h>
#include <div64.h>
#include <config.h>
#include "nand.h"
#include "yaffscfg.h"
#include "yaffsfs.h"
#include "yaffs_packedtags2.h"
#include "yaffs_mtdif.h"
#include "yaffs_mtdif2.h"
#if 0
#include <errno.h>
#else
#include "malloc.h"
#endif
void *yaffsfs_malloc(size_t x)
{
	return malloc(x);
}
void yaffsfs_free(void *x)
{
	free(x);
}
void *yaffs_malloc(size_t size)
{
	return malloc(size);
}
void yaffs_free(void *ptr)
{
	free(ptr);
}
