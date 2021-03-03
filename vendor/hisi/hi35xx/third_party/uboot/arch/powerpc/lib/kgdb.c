#include <common.h>
#include <command.h>
#include <kgdb.h>
#include <asm/signal.h>
#include <asm/processor.h>
#define PC_REGNUM 64
#define SP_REGNUM 1
#if 0
#endif
#define SPACE_REQUIRED	((32*4)+(32*8)+(6*4))
