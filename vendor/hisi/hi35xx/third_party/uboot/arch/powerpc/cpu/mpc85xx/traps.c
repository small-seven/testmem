#include <common.h>
#include <command.h>
#include <irq_func.h>
#include <kgdb.h>
#include <asm/processor.h>
#define END_OF_MEM (gd->bd->bi_memstart + get_effective_memsize())
#define ESR_MCI 0x80000000
#define ESR_PIL 0x08000000
#define ESR_PPR 0x04000000
#define ESR_PTR 0x02000000
#define ESR_DST 0x00800000
#define ESR_DIZ 0x00400000
#define ESR_U0F 0x00008000
#if defined(CONFIG_CMD_BEDBUG)
#endif
#if defined(CONFIG_CMD_KGDB)
#endif
#if defined(CONFIG_CMD_KGDB)
#endif
#if defined(CONFIG_CMD_KGDB)
#endif
#if defined(CONFIG_CMD_KGDB)
#endif
#if defined(CONFIG_CMD_KGDB)
#endif
#if defined(CONFIG_CMD_BEDBUG)
#endif
