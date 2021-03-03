#include <common.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/emif4.h>
void mem_init(void)
{
	do_emif4_init();
}
