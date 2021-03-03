#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "zlib.h"
#define local static
#define LGCHUNK 14
#define CHUNK (1U << LGCHUNK)
#define DSIZE 32768U
typedef struct {
    int fd;                     /* file descriptor */
    int size;                   /* 1 << size is bytes in buf */
    unsigned left;              /* bytes available at next */
    unsigned char *buf;         /* buffer */
    z_const unsigned char *next;    /* next byte in buffer */
    char *name;                 /* file name for error messages */
} file;
#define read1(in) (in->left == 0 ? readmore(in) : 0, \
