#include <stdio.h>
#include <stdlib.h>
#include <string.h>		/* for string functions */
#ifdef UNIT_TEST
#include <assert.h>
#endif /* UNIT_TEST */
#include "splitstr.h"
void splitstr_free(const char **p_return)
{
	if (*p_return != NULL)
		free((char *)*p_return);
	if (p_return != NULL)
		free((char **)p_return);
}
#ifdef UNIT_TEST
#endif
