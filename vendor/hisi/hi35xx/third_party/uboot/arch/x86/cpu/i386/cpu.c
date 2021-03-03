#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <asm/control_regs.h>
#include <asm/cpu.h>
#include <asm/mp.h>
#include <asm/msr.h>
#include <asm/mtrr.h>
#include <asm/processor-flags.h>
#define GDT_ENTRY(flags, base, limit)			\
#ifdef CONFIG_HAVE_FSP
#endif
#define PAGETABLE_BASE		0x80000
#define PAGETABLE_SIZE		(6 * 4096)
	typedef void (*func_t)(ulong pgtable, ulong setup_base, ulong target);
	uint32_t *pgtable;
	func_t func;
	char *ptr;

	pgtable = (uint32_t *)PAGETABLE_BASE;

	build_pagetable(pgtable);

	extern long call64_stub_size;
	ptr = malloc(call64_stub_size);
	if (!ptr) {
		printf("Failed to allocate the cpu_call64 stub\n");
		return -ENOMEM;
	}
#ifdef CONFIG_SMP
#endif
