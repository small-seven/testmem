#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
typedef void DFL(char *);
DFL *defaultline;

typedef void FILEONLY(char * file);
FILEONLY *internalfunctions;
FILEONLY *externalfunctions;
FILEONLY *symbolsonly;
FILEONLY *findall;

typedef void FILELINE(char * file, char * line);
FILELINE * singlefunctions;
FILELINE * entity_system;
FILELINE * docsection;

#define MAXLINESZ     2048
#define MAXFILES      250
#define KERNELDOCPATH "scripts/"
#define KERNELDOC     "kernel-doc"
#define DOCBOOK       "-docbook"
#define LIST          "-list"
#define FUNCTION      "-function"
#define NOFUNCTION    "-nofunction"
#define NODOCSECTIONS "-no-doc-sections"
#define SHOWNOTFOUND  "-show-not-found"

static char *srctree, *kernsrctree;

static char **all_list = NULL;
static int all_list_len = 0;

static void consume_symbol(const char *sym)
{
	int i;

	for (i = 0; i < all_list_len; i++) {
		if (!all_list[i])
			continue;
		if (strcmp(sym, all_list[i]))
			continue;
		all_list[i] = NULL;
		break;
	}
