#include <stdio.h>
#include "bio_local.h"
#define DUMP_WIDTH      16
#define DUMP_WIDTH_LESS_INDENT(i) (DUMP_WIDTH - ((i - (i > 6 ? 6 : i) + 3) / 4))
#define SPACE(buf, pos, n)   (sizeof(buf) - (pos) > (n))
#ifndef CHARSET_EBCDIC
#else
#endif
#ifndef OPENSSL_NO_STDIO
#endif
