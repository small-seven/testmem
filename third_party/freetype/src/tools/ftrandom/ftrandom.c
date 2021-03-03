#define _XOPEN_SOURCE 500 /* for `kill', `strdup', `random', and `srandom' */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <time.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H
#define true     1
#define false    0
#define forever  for (;;)
#define GOOD_FONTS_DIR  "/usr/local/share/fonts"
