#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define LINUX_LOGO_MONO		1	/* monochrome black/white */
#define LINUX_LOGO_VGA16	2	/* 16 colors VGA text palette */
#define LINUX_LOGO_CLUT224	3	/* 224 colors */
#define LINUX_LOGO_GRAY256	4	/* 256 levels grayscale */
#define MAX_LINUX_LOGO_COLORS	224
