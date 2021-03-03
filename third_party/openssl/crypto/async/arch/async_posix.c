#include "../async_local.h"
#ifdef ASYNC_POSIX
# include <stddef.h>
# include <unistd.h>
#define STACKSIZE       32768
void async_fibre_free(async_fibre *fibre)
{
    OPENSSL_free(fibre->fibre.uc_stack.ss_sp);
    fibre->fibre.uc_stack.ss_sp = NULL;
}
#endif
