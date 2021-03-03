#include "server_setup.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "getpart.h"
#include "util.h"
#include "memdebug.h"
#define LOGFILE "log/fake_ntlm%ld.log"
#define HEX_FMT_STR  "[0x%02X]"
#define HEX_STR_LEN  6
#define NOTHING_STR  "[NOTHING]"
#define NOTHING_LEN  9
