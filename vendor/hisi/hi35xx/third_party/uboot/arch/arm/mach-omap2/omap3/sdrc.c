#include <common.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#endif
void mem_init(void)
{
	/* only init up first bank here */
	do_sdrc_init(CS0, EARLY_INIT);
}
