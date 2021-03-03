#include <unistd.h> /* for POSIX 1003.1 */
#include <errno.h>  /* for EINTR */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <asm/hwcap.h>
