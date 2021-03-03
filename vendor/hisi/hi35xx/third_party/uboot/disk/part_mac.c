#include <common.h>
#include <command.h>
#include <memalign.h>
#include <ide.h>
#include "part_mac.h"
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#ifndef __ldiv_t_defined
typedef struct {
	long int quot;		/* Quotient	*/
	long int rem;		/* Remainder	*/
} ldiv_t;
# define __ldiv_t_defined	1
#endif
#endif
