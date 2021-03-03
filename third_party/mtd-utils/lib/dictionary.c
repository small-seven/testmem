#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXVALSZ	1024
#define DICTMINSZ	128
#define DICT_INVALID_KEY    ((char*)-1)
#ifdef TESTDIC
#define NVALS 20000
#endif
