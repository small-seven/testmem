#include <common.h>
#include <command.h>
#include <errno.h>
#include <malloc.h>
#include <qfw.h>
#include <asm/io.h>
#ifdef CONFIG_GENERATE_ACPI_TABLE
#include <asm/tables.h>
#endif
#include <linux/list.h>
#ifdef CONFIG_GENERATE_ACPI_TABLE
static int bios_linker_allocate(struct bios_linker_entry *entry, ulong *addr)
{
	uint32_t size, align;
	struct fw_file *file;
	unsigned long aligned_addr;

	align = le32_to_cpu(entry->alloc.align);
	/* align must be power of 2 */
	if (align & (align - 1)) {
		printf("error: wrong alignment %u\n", align);
		return -EINVAL;
	}

	file = qemu_fwcfg_find_file(entry->alloc.file);
	if (!file) {
		printf("error: can't find file %s\n", entry->alloc.file);
		return -ENOENT;
	}

	size = be32_to_cpu(file->cfg.size);

	/*
	 * ZONE_HIGH means we need to allocate from high memory, since
	 * malloc space is already at the end of RAM, so we directly use it.
	 * If allocation zone is ZONE_FSEG, then we use the 'addr' passed
	 * in which is low memory
	 */
	if (entry->alloc.zone == BIOS_LINKER_LOADER_ALLOC_ZONE_HIGH) {
		aligned_addr = (unsigned long)memalign(align, size);
		if (!aligned_addr) {
			printf("error: allocating resource\n");
			return -ENOMEM;
		}
	} else if (entry->alloc.zone == BIOS_LINKER_LOADER_ALLOC_ZONE_FSEG) {
		aligned_addr = ALIGN(*addr, align);
	} else {
		printf("error: invalid allocation zone\n");
		return -EINVAL;
	}

	debug("bios_linker_allocate: allocate file %s, size %u, zone %d, align %u, addr 0x%lx\n",
	      file->cfg.name, size, entry->alloc.zone, align, aligned_addr);

	qemu_fwcfg_read_entry(be16_to_cpu(file->cfg.select),
			      size, (void *)aligned_addr);
	file->addr = aligned_addr;

	/* adjust address for low memory allocation */
	if (entry->alloc.zone == BIOS_LINKER_LOADER_ALLOC_ZONE_FSEG)
		*addr = (aligned_addr + size);

	return 0;
}
#endif
