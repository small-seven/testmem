#include <string.h>
#include "tu_local.h"
static int tap_free(BIO *b)
{
    if (b == NULL)
        return 0;
    BIO_set_data(b, NULL);
    BIO_set_init(b, 0);
    return 1;
}
