#include <stdio.h>      /* fputs(), fprintf(), fwrite(), putc() */
#include <stdlib.h>     /* exit(), malloc(), free() */
#include <fcntl.h>      /* open() */
#include <unistd.h>     /* close(), read(), lseek() */
#include "zlib.h"
#define local static
#define CHUNK 32768         /* must be a power of two and fit in unsigned */
typedef struct {
    char *name;             /* name of file for error messages */
    int fd;                 /* file descriptor */
    unsigned left;          /* bytes remaining at next */
    unsigned char *next;    /* next byte to read */
    unsigned char *buf;     /* allocated buffer of length CHUNK */
} bin;
#define bget(in) (in->left ? 0 : bload(in), \
