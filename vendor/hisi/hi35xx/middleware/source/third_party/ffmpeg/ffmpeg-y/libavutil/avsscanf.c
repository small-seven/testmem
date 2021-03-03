#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#include "config.h"
#include "common.h"
#include "mem.h"
#include "avassert.h"
#include "avstring.h"
#include "bprint.h"
typedef struct FFFILE {
    size_t buf_size;
    unsigned char *buf;
    unsigned char *rpos, *rend;
    unsigned char *shend;
    ptrdiff_t shlim, shcnt;
    void *cookie;
    size_t (*read)(struct FFFILE *, unsigned char *, size_t);
} FFFILE;
#define SIZE_hh -2
#define SIZE_h  -1
#define SIZE_def 0
#define SIZE_l   1
#define SIZE_L   2
#define SIZE_ll  3
#define shcnt(f) ((f)->shcnt + ((f)->rpos - (f)->buf))
#define shlim(f, lim) ffshlim((f), (lim))
#define shgetc(f) (((f)->rpos != (f)->shend) ? *(f)->rpos++ : ffshgetc(f))
#define shunget(f) ((f)->shend ? (void)(f)->rpos-- : (void)0)
#define LD_B1B_DIG 2
#define LD_B1B_MAX 9007199, 254740991
#define KMAX 128
#define MASK (KMAX-1)
