#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <string.h>
#include <ctype.h>
#define MAX_FONTLEN 256
typedef unsigned short unicode;

static void usage(char *argv0)
{
  fprintf(stderr, "Usage: \n"
         "        %s chartable [hashsize] [hashstep] [maxhashlevel]\n", argv0);
  exit(EX_USAGE);
}
#include <linux/types.h>\n\
