#include <string.h>
#include <ctype.h>
#include <securec.h>
#include "hcs_ast.h"
#include "hcs_file.h"
#include "hcs_log.h"
#include "hcs_mem.h"
#include "hcs_option.h"
#include "hcs_parser.h"
#define TAB_SIZE 4
#define WRITE_BUFFER_LEN 256
#define INCLUDE_PATH_MAX_LEN 128
#define VARIABLE_NAME_LEN 128
#define GEN_CODE_MARGIN_SIZE 100
#define GEN_ARRAY_SEP_SIZE 2
#define HCS_CONFIG_FILE_HEADER "/*\n"                                                      \
#define HCS_CONFIG_INCLUDE_HEADER "#include <stdint.h>\n\n"
#define DEFAULT_PREFIX "HdfConfig"
#define HCS_CONFIG_INCLUDE_FUNC_DECLARATION "const struct %s%sRoot* HdfGet%sModuleConfigRoot(void);\n\n"
#define HCS_CONFIG_FUNC_IMPLEMENT "\nconst struct %s%sRoot* HdfGet%sModuleConfigRoot(void)\n" \
typedef struct HcsSymbol {
    char *name;
    const ParserObject *object;
    uint32_t duplicateCount;
    struct HcsSymbol *left;
    struct HcsSymbol *right;
    struct HcsSymbol *parent;
} HcsSymbol;
typedef struct HcsSymbolTable {
    HcsSymbol *symbols;
    uint32_t size;
} HcsSymbolTable;
static void HcsSymbolTableRelease()
{
    HcsReleaseSymbol(g_hcsSymbolTable->symbols);
    HcsMemFree(g_hcsSymbolTable);
    g_hcsSymbolTable = NULL;
}
#define MAX_CONFIG_TREE_DEPTH 100
#define HCS_HEADER_MACRO_MAX_LEN 150
