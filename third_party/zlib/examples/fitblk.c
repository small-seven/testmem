#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "zlib.h"
#define local static
#define RAWLEN 4096    /* intermediate uncompressed buffer size */
#define EXCESS 256      /* empirically determined stream overage */
#define MARGIN 8        /* amount to back off for completion */
