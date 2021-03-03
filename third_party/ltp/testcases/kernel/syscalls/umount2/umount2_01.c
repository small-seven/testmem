#include <errno.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/mount.h"
#define DIR_MODE	(S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#define FILE_MODE	(S_IRWXU | S_IRWXG | S_IRWXO | S_ISUID | S_ISGID)
#define MNTPOINT	"mntpoint"
