#include <common.h>
#include <command.h>
#include <env.h>
#include <ide.h>
#include "part_amiga.h"
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#undef AMIGA_DEBUG
#ifdef AMIGA_DEBUG
#define PRINTF(fmt, args...) printf(fmt ,##args)
#else
#define PRINTF(fmt, args...)
#endif
#endif
