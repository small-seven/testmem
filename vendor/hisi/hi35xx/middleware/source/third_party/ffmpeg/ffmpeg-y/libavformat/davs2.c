#include "avformat.h"
#include "rawdec.h"
#include "libavcodec/internal.h"
#include "libavutil/intreadwrite.h"
#define ISSQH(x)  ((x) == 0xB0 )
#define ISEND(x)  ((x) == 0xB1 )
#define ISPIC(x)  ((x) == 0xB3 || (x) == 0xB6)
#define ISUNIT(x) ( ISSQH(x) || ISEND(x) || (x) == 0xB2 || ISPIC(x) || (x) == 0xB5 || (x) == 0xB7 )
#define ISAVS2(x) ((x) == 0x20 || (x) == 0x22 || (x) == 0x30 || (x) == 0x32 )
