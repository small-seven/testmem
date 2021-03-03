#include <common.h>
#include <mapmem.h>
#include <physmem.h>
#include <linux/compiler.h>
phys_addr_t __weak arch_phys_memset(phys_addr_t s, int c, phys_size_t n)
{
	void *s_ptr = map_sysmem(s, n);

	assert(((phys_addr_t)(uintptr_t)s) == s);
	assert(((phys_addr_t)(uintptr_t)(s + n)) == s + n);

	return (phys_addr_t)(uintptr_t)memset(s_ptr, c, n);
}
