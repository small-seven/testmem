#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zlib.h"
#define local static
#define SPAN 1048576L       /* desired distance between access points */
#define WINSIZE 32768U      /* sliding window size */
#define CHUNK 16384         /* file input buffer size */
