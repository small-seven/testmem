#include <common.h>
#include <command.h>
#include <irq_func.h>
#include <asm/string.h>
#include <asm/regs.h>
typedef void (*handler_t)(struct pt_regs *);

void unhandled_exception(struct pt_regs *regs)
{
	printf("Unhandled Exception: EXCCAUSE = %ld, EXCVADDR = %lx, pc = %lx\n",
	       regs->exccause, regs->excvaddr, regs->pc);
	panic("*** PANIC\n");
}
