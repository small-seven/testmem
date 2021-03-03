#include <common.h>
#include <charset.h>
#include <efi_loader.h>
#include <malloc.h>
#include <mapmem.h>
#include <fs.h>
#define to_fs(x) container_of(x, struct file_system, base)
#define to_fh(x) container_of(x, struct file_handle, base)
