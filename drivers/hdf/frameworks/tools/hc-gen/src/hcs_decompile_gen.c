#include <string.h>
#include <securec.h>
#include "hcs_file.h"
#include "hcs_ast.h"
#include "hcs_mem.h"
#include "hcs_log.h"
#define WRITE_BUFFER_LEN 256
#define HCS_TAB_SIZE 4
#define HCS_DECOMPILE_FILE_HEADER           \
