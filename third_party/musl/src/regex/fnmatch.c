#include <string.h>
#include <fnmatch.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "locale_impl.h"
#define END 0
#define UNMATCHABLE -2
#define BRACKET -3
#define QUESTION -4
#define STAR -5
