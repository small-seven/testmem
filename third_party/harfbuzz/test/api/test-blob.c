#include "hb-test.h"
#if defined(HAVE_SYS_MMAN_H) && defined(HAVE_MPROTECT) && defined(HAVE_MMAP)
# define TEST_MMAP 1
#ifdef HAVE_SYS_MMAN_H
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif /* HAVE_UNISTD_H */
#include <sys/mman.h>
#endif /* HAVE_SYS_MMAN_H */
#endif
#ifdef TEST_MMAP
#endif
typedef struct
{
  hb_blob_t *blob;
  int freed;
  char *data;
  unsigned int len;
} fixture_t;
#ifdef TEST_MMAP
#if defined(HAVE_SYSCONF) && defined(_SC_PAGE_SIZE)
#elif defined(HAVE_SYSCONF) && defined(_SC_PAGESIZE)
#elif defined(HAVE_GETPAGESIZE)
#endif
#endif
#include <errno.h>
#ifdef TEST_MMAP
#endif
