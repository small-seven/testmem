#include <common.h>
#include <command.h>
#include <asm/unaligned.h>
#include "part_iso.h"
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#ifdef	ISO_PART_DEBUG
#define	PRINTF(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTF(fmt,args...)
#endif
#undef CHECK_FOR_POWERPC_PLATTFORM
#define CD_SECTSIZE 2048
#ifdef CHECK_FOR_POWERPC_PLATTFORM
#endif
#endif
