#include "config.h"
#ifdef HAVE_NUMA_V2
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <ctype.h>
#include <errno.h>
#include <numa.h>
#include <numaif.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "memtoy.h"
#include "test.h"
#define CMD_SUCCESS 0
#define CMD_ERROR   1
#ifndef __NR_migrate_pages
#define __NR_migrate_pages 0
#endif
#ifndef MPOL_MF_WAIT
#define MPOL_MF_WAIT    (1<<2)	/* Wait for existing pages to migrate */
#endif
#define KILO_SHIFT 10
#if 0
#endif
#if 1				// for testing
#endif
#if 0
#endif
typedef int (*cmd_func_t) (char *);

struct command {
	char *cmd_name;
	cmd_func_t cmd_func;	/* */
	char *cmd_help;

} cmd_table[] = {
#if 0				/* template for new commands */
#endif
#define CMDBUFSZ 256
#endif
