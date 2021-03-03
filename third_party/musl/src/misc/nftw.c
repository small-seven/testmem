#include <ftw.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#undef dirfd
#define dirfd(d) (*(int *)d)
