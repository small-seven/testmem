#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <compiler.h>
#include <trace.h>
#define MAX_LINE_LEN 500
#define error(fmt, b...) outf(0, fmt, ##b)
#define warn(fmt, b...) outf(1, fmt, ##b)
#define notice(fmt, b...) outf(2, fmt, ##b)
#define info(fmt, b...) outf(3, fmt, ##b)
#define debug(fmt, b...) outf(4, fmt, ##b)
