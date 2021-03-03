#include <unistd.h>
#include "hcs_file.h"
#include "hcs_compiler.h"
#include "hcs_log.h"
#define ARG_COUNT_MIN 2
#define USAGE(option, info) HCS_PRINT("  %-12s%s\n", option, info)
#define HCS_SUPPORT_ARGS "o:ap:bditvVh"
