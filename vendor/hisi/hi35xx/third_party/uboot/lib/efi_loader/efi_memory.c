#include <common.h>
#include <efi_loader.h>
#include <init.h>
#include <malloc.h>
#include <mapmem.h>
#include <watchdog.h>
#include <linux/list_sort.h>
#include <linux/sizes.h>
#define EFI_ALLOC_POOL_MAGIC 0x1fe67ddf6491caa2
#define EFI_CARVE_NO_OVERLAP		-1
#define EFI_CARVE_LOOP_AGAIN		-2
#define EFI_CARVE_OVERLAPS_NONRAM	-3
#ifdef CONFIG_EFI_LOADER_BOUNCE_BUFFER
#endif
static int efi_mem_cmp(void *priv, struct list_head *a, struct list_head *b)
{
	struct efi_mem_list *mema = list_entry(a, struct efi_mem_list, link);
	struct efi_mem_list *memb = list_entry(b, struct efi_mem_list, link);

	if (mema->desc.physical_start == memb->desc.physical_start)
		return 0;
	else if (mema->desc.physical_start < memb->desc.physical_start)
		return 1;
	else
		return -1;
}
efi_status_t efi_free_pool(void *buffer)
{
	efi_status_t ret;
	struct efi_pool_allocation *alloc;

	if (!buffer)
		return EFI_INVALID_PARAMETER;

	ret = efi_check_allocated((uintptr_t)buffer, true);
	if (ret != EFI_SUCCESS)
		return ret;

	alloc = container_of(buffer, struct efi_pool_allocation, data);

	/* Check that this memory was allocated by efi_allocate_pool() */
	if (((uintptr_t)alloc & EFI_PAGE_MASK) ||
	    alloc->checksum != checksum(alloc)) {
		printf("%s: illegal free 0x%p\n", __func__, buffer);
		return EFI_INVALID_PARAMETER;
	}
	/* Avoid double free */
	alloc->checksum = 0;

	ret = efi_free_pages((uintptr_t)alloc, alloc->num_pages);

	return ret;
}
#if defined(__aarch64__)
#endif
#ifdef CONFIG_EFI_LOADER_BOUNCE_BUFFER
#endif
