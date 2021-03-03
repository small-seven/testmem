#include "tool_setup.h"
#include "tool_cfgable.h"
#include "tool_main.h"
#include "memdebug.h" /* keep this as LAST include */
void config_free(struct OperationConfig *config)
{
  struct OperationConfig *last = config;

  /* Free each of the structures in reverse order */
  while(last) {
    struct OperationConfig *prev = last->prev;

    free_config_fields(last);
    free(last);

    last = prev;
  }
}
