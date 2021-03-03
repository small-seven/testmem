#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
#include "CuTest.h"
#include "dictionary.h"
#include "iniparser.c"
#define GOOD_INI_PATH "ressources/good_ini"
#define BAD_INI_PATH "ressources/bad_ini"
