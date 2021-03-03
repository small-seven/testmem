#include <stdio.h>
#include "zutil.h"
#include "inftrees.h"
#include "inflate.h"
#include "inffast.h"
    typedef struct inffast_ar {
/* 64   32                               x86  x86_64 */
/* ar offset                              register */
/*  0    0 */ void *esp;                /* esp save */
/*  8    4 */ void *ebp;                /* ebp save */
/* 16    8 */ unsigned char FAR *in;    /* esi rsi  local strm->next_in */
/* 24   12 */ unsigned char FAR *last;  /*     r9   while in < last */
/* 32   16 */ unsigned char FAR *out;   /* edi rdi  local strm->next_out */
/* 40   20 */ unsigned char FAR *beg;   /*          inflate()'s init next_out */
/* 48   24 */ unsigned char FAR *end;   /*     r10  while out < end */
/* 56   28 */ unsigned char FAR *window;/*          size of window, wsize!=0 */
/* 64   32 */ code const FAR *lcode;    /* ebp rbp  local strm->lencode */
/* 72   36 */ code const FAR *dcode;    /*     r11  local strm->distcode */
/* 80   40 */ size_t /*unsigned long */hold;       /* edx rdx  local strm->hold */
/* 88   44 */ unsigned bits;            /* ebx rbx  local strm->bits */
/* 92   48 */ unsigned wsize;           /*          window size */
/* 96   52 */ unsigned write;           /*          window write index */
/*100   56 */ unsigned lmask;           /*     r12  mask for lcode */
/*104   60 */ unsigned dmask;           /*     r13  mask for dcode */
/*108   64 */ unsigned len;             /*     r14  match length */
/*112   68 */ unsigned dist;            /*     r15  match distance */
/*116   72 */ unsigned status;          /*          set when state chng*/
    } type_ar;
#ifdef ASMINF
#if (defined( __GNUC__ ) && defined( __amd64__ ) && ! defined( __i386 )) || (defined(_MSC_VER) && defined(_M_AMD64))
#define PAD_AVAIL_IN 6
#define PAD_AVAIL_OUT 258
#else
#define PAD_AVAIL_IN 5
#define PAD_AVAIL_OUT 257
#endif
#endif
