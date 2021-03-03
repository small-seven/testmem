#include <stdlib.h>
#include <string.h>
#include "tre.h"
tre_mem_destroy(tre_mem_t mem)
{
  tre_list_t *tmp, *l = mem->blocks;

  while (l != NULL)
    {
      xfree(l->data);
      tmp = l->next;
      xfree(l);
      l = tmp;
    }
  xfree(mem);
}
