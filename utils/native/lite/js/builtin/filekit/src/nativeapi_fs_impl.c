#include "nativeapi_fs_impl.h"
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <securec.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "nativeapi_config.h"
#define BUFFER_SIZE 512
