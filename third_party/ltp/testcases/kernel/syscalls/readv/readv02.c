#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <memory.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#define	K_1	1024
#define	M_1	K_1 * K_1
#define	G_1	M_1 * K_1
#define	NBUFS		4
#define	CHUNK		64
#define	MAX_IOVEC	16
#define DATA_FILE	"readv_data_file"
