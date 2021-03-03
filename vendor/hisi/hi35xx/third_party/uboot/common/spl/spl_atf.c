#include <common.h>
#include <atf_common.h>
#include <cpu_func.h>
#include <errno.h>
#include <spl.h>
typedef void (*atf_entry_t)(struct bl31_params *params, void *plat_params);

static void bl31_entry(uintptr_t bl31_entry, uintptr_t bl32_entry,
		       uintptr_t bl33_entry, uintptr_t fdt_addr)
{
	struct bl31_params *bl31_params;
	atf_entry_t  atf_entry = (atf_entry_t)bl31_entry;

	bl31_params = bl2_plat_get_bl31_params(bl32_entry, bl33_entry,
					       fdt_addr);

	raw_write_daif(SPSR_EXCEPTION_MASK);
	dcache_disable();

	atf_entry((void *)bl31_params, (void *)fdt_addr);
}
