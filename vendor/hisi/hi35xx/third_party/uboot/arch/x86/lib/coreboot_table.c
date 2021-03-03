#include <common.h>
#include <acpi_s3.h>
#include <vbe.h>
#include <asm/coreboot_tables.h>
#include <asm/e820.h>
#ifdef CONFIG_HAVE_ACPI_RESUME
#endif
void *high_table_malloc(size_t bytes)
{
	u32 new_ptr;
	void *ptr;

	new_ptr = gd->arch.high_table_ptr + bytes;
	if (new_ptr >= gd->arch.high_table_limit)
		return NULL;
	ptr = (void *)gd->arch.high_table_ptr;
	gd->arch.high_table_ptr = new_ptr;

	return ptr;
}
