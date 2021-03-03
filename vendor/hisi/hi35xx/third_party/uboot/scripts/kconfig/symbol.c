#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <sys/utsname.h>
#include "lkc.h"
static void dep_stack_remove(void)
{
	check_top = check_top->prev;
	if (check_top)
		check_top->next = NULL;
}
