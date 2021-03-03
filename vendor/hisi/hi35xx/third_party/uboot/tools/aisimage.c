#include "imagetool.h"
#include "aisimage.h"
#include <image.h>
#define IS_FNC_EXEC(c)	(cmd_table[c].AIS_cmd == AIS_CMD_FNLOAD)
#define WORD_ALIGN0	4
#define WORD_ALIGN(len) (((len)+WORD_ALIGN0-1) & ~(WORD_ALIGN0-1))
#define MAX_CMD_BUFFER	4096
