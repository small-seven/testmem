#include <sys/types.h>
#include <stdio.h>      /* rename, fopen, fprintf, fclose */
#include <stdlib.h>     /* malloc, free */
#include <string.h>     /* strlen, strrchr, strcpy, strncpy, strcmp */
#include <fcntl.h>      /* open */
#include <unistd.h>     /* lseek, read, write, close, unlink, sleep, */
#include <errno.h>      /* errno */
#include <time.h>       /* time, ctime */
#include <sys/stat.h>   /* stat */
#include <sys/time.h>   /* utimes */
#include "zlib.h"       /* crc32 */
#include "gzlog.h"      /* header for external access */
#define local static
typedef unsigned int uint;
typedef unsigned long ulong;

/* Macro for debugging to deterministically force recovery operations */
#ifdef GZLOG_DEBUG
    #include <setjmp.h>         /* longjmp */
    jmp_buf gzlog_jump;         /* where to go back to */
    int gzlog_bail = 0;         /* which point to bail at (1..8) */
    int gzlog_count = -1;       /* number of times through to wait */
#   define BAIL(n) do { if (n == gzlog_bail && gzlog_count-- == 0) \
                            longjmp(gzlog_jump, gzlog_bail); } while (0)
#else
#   define BAIL(n)
#endif
#define PATIENCE 300
#define MAX_STORE 16
#define TRIGGER 1024
#define DICT 32768U
#define NO_OP 0
#define APPEND_OP 1
#define COMPRESS_OP 2
#define REPLACE_OP 3
#define PULL2(p) ((p)[0]+((uint)((p)[1])<<8))
#define PULL4(p) (PULL2(p)+((ulong)PULL2(p+2)<<16))
#define PULL8(p) (PULL4(p)+((off_t)PULL4(p+4)<<32))
#define PUT2(p,a) do {(p)[0]=a;(p)[1]=(a)>>8;} while(0)
#define PUT4(p,a) do {PUT2(p,a);PUT2(p+2,a>>16);} while(0)
#define PUT8(p,a) do {PUT4(p,a);PUT4(p+4,a>>32);} while(0)
#define LOGID "\106\035\172"    /* should be three non-zero characters */
#define HEAD sizeof(log_gzhead)     /* should be 16 */
#define EXTRA sizeof(log_gzext)     /* should be 35 */
#define BODY sizeof(log_gzbody)
