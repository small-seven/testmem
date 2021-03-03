#include <errno.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/mount.h"
#include "umount2.h"
#define DIR_MODE	(S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#define MNTPOINT	"mntpoint"
