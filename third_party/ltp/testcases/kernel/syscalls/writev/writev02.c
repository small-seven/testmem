#include <sys/types.h>
#include <signal.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <memory.h>
#include <errno.h>
#include "test.h"
#include <sys/mman.h>
#define	K_1	8192
#define	NBUFS		2
#define	CHUNK		K_1	/* single chunk */
#define	MAX_IOVEC	2
#define	DATA_FILE	"writev_data_file"
