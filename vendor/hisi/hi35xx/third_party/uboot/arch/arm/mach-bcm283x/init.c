#include <common.h>
#include <cpu_func.h>
#include <dm/device.h>
#include <fdt_support.h>
#ifdef CONFIG_ARM64
#include <asm/armv8/mmu.h>
static void _rpi_update_mem_map(struct mm_region *pd)
{
	int i;

	for (i = 0; i < 2; i++) {
		mem_map[i].virt = pd[i].virt;
		mem_map[i].phys = pd[i].phys;
		mem_map[i].size = pd[i].size;
		mem_map[i].attrs = pd[i].attrs;
	}
}
static void rpi_update_mem_map(void)
{
	int ret;
	struct mm_region *mm;
	const struct udevice_id *of_match = board_ids;

	while (of_match->compatible) {
		ret = fdt_node_check_compatible(gd->fdt_blob, 0,
						of_match->compatible);
		if (!ret) {
			mm = (struct mm_region *)of_match->data;
			_rpi_update_mem_map(mm);
			break;
		}

		of_match++;
	}
}
#else
#ifdef CONFIG_ARMV7_LPAE
#endif
