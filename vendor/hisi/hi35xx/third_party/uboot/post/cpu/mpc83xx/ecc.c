#include <common.h>
#include <cpu_func.h>
#include <irq_func.h>
#include <mpc83xx.h>
#include <watchdog.h>
#include <asm/io.h>
#include <post.h>
#if CONFIG_POST & CONFIG_SYS_POST_ECC
#ifdef CONFIG_DDR_32BIT
#error "Add ECC POST support for CONFIG_DDR_32BIT here!"
#else
#endif /* !CONFIG_DDR_32BIT */
#endif
