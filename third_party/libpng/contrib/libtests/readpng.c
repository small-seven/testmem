#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#        ifdef PNG_READ_INTERLACING_SUPPORTED
#        else /* !READ_INTERLACING */
#        endif /* !READ_INTERLACING */
#           ifndef PNG_READ_INTERLACING_SUPPORTED
#           endif /* READ_INTERLACING */
