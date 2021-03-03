#include "eng_local.h"
#include "internal/dso.h"
#include <openssl/crypto.h>
typedef struct st_dynamic_data_ctx dynamic_data_ctx;
/* The implementation for the important control command */
static int dynamic_load(ENGINE *e, dynamic_data_ctx *ctx);

#define DYNAMIC_CMD_SO_PATH             ENGINE_CMD_BASE
#define DYNAMIC_CMD_NO_VCHECK           (ENGINE_CMD_BASE + 1)
#define DYNAMIC_CMD_ID                  (ENGINE_CMD_BASE + 2)
#define DYNAMIC_CMD_LIST_ADD            (ENGINE_CMD_BASE + 3)
#define DYNAMIC_CMD_DIR_LOAD            (ENGINE_CMD_BASE + 4)
#define DYNAMIC_CMD_DIR_ADD             (ENGINE_CMD_BASE + 5)
#define DYNAMIC_CMD_LOAD                (ENGINE_CMD_BASE + 6)

/* The constants used when creating the ENGINE */
static const char *engine_dynamic_id = "dynamic";
static const char *engine_dynamic_name = "Dynamic engine loading support";
static const ENGINE_CMD_DEFN dynamic_cmd_defns[] = {
    {DYNAMIC_CMD_SO_PATH,
     "SO_PATH",
     "Specifies the path to the new ENGINE shared library",
     ENGINE_CMD_FLAG_STRING},
