#include <ctype.h>
#include <libiniparser.h>
#define ASCIILINESZ         (1024)
#define INI_INVALID_KEY     ((char*)-1)
typedef enum _line_status_ {
    LINE_UNPROCESSED,
    LINE_ERROR,
    LINE_EMPTY,
    LINE_COMMENT,
    LINE_SECTION,
    LINE_VALUE
} line_status ;
void iniparser_freedict(dictionary * d)
{
    dictionary_del(d);
}
