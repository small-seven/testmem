#include <stdio.h>
#include <zlib.h>
#     define u16(x) (header[x] * 256 + header[x+1])
#     define u32(x) (u16(x) * 65536 + u16(x+2))
